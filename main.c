#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>


// Declaración externa del intérprete
void run_interpreter();

// Widgets globales
GtkWidget *source_editor;
GtkWidget *output_display;
GtkWidget *token_error_display;

// Estructura para capturar salida
typedef struct {
    char *buffer;
    size_t size;
    size_t capacity;
} OutputBuffer;

OutputBuffer* create_buffer() {
    OutputBuffer *buf = malloc(sizeof(OutputBuffer));
    buf->buffer = malloc(1024);
    buf->buffer[0] = '\0';
    buf->size = 0;
    buf->capacity = 1024;
    return buf;
}

void buffer_append(OutputBuffer *buf, const char *str) {
    size_t len = strlen(str);
    if (buf->size + len + 1 > buf->capacity) {
        buf->capacity *= 2;
        buf->buffer = realloc(buf->buffer, buf->capacity);
    }
    strcpy(buf->buffer + buf->size, str);
    buf->size += len;
}

// Función que ejecuta el intérprete y captura su salida
void capture_output(const char* filename, OutputBuffer *buf) {
    int pipefd[2];
    pid_t pid;

    if (pipe(pipefd) == -1) {
        buffer_append(buf, "Error: no se pudo crear pipe\n");
        return;
    }

    pid = fork();
    if (pid == -1) {
        buffer_append(buf, "Error: fork falló\n");
        close(pipefd[0]);
        close(pipefd[1]);
        return;
    }

    if (pid == 0) {
        // HIJO
        close(pipefd[0]);

        // Redirigir stdin desde archivo
        int fd = open(filename, O_RDONLY);
        if (fd == -1) {
            dprintf(pipefd[1], "Error: open('%s') falló: %s\n", filename, strerror(errno));
            close(pipefd[1]);
            exit(1);
        }
        dup2(fd, STDIN_FILENO);
        close(fd);

        // Redirigir stdout/stderr al pipe
        dup2(pipefd[1], STDOUT_FILENO);
        dup2(pipefd[1], STDERR_FILENO);
        close(pipefd[1]);

        run_interpreter();
        exit(0);
    } else {
        // PADRE
        close(pipefd[1]);
        char buffer[1024];
        ssize_t count;
        while ((count = read(pipefd[0], buffer, sizeof(buffer)-1)) > 0) {
            buffer[count] = '\0';
            buffer_append(buf, buffer);
        }
        close(pipefd[0]);
        wait(NULL);
    }
}

// Callback para botón "Cargar"
void on_load_clicked(GtkWidget *widget, gpointer data) {
    GtkWidget *dialog = gtk_file_chooser_dialog_new(
        "Abrir archivo", GTK_WINDOW(data),
        GTK_FILE_CHOOSER_ACTION_OPEN,
        "_Cancelar", GTK_RESPONSE_CANCEL,
        "_Abrir", GTK_RESPONSE_ACCEPT,
        NULL);

    if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_ACCEPT) {
        char *filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));
        FILE *file = fopen(filename, "r");
        if (file) {
            fseek(file, 0, SEEK_END);
            long fsize = ftell(file);
            fseek(file, 0, SEEK_SET);

            char *string = malloc(fsize + 1);
            fread(string, 1, fsize, file);
            fclose(file);

            string[fsize] = '\0';
            GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(source_editor));
            gtk_text_buffer_set_text(buffer, string, -1);
            free(string);
        } else {
            GtkTextBuffer *err_buf = gtk_text_view_get_buffer(GTK_TEXT_VIEW(token_error_display));
            gtk_text_buffer_set_text(err_buf, "Error: no se pudo abrir el archivo seleccionado.\n", -1);
        }
        g_free(filename);
    }
    gtk_widget_destroy(dialog);
}

// ✅ Callback para botón "Guardar"
void on_save_clicked(GtkWidget *widget, gpointer data) {
    GtkWidget *dialog = gtk_file_chooser_dialog_new(
        "Guardar archivo", GTK_WINDOW(data),
        GTK_FILE_CHOOSER_ACTION_SAVE,
        "_Cancelar", GTK_RESPONSE_CANCEL,
        "_Guardar", GTK_RESPONSE_ACCEPT,
        NULL);

    gtk_file_chooser_set_do_overwrite_confirmation(GTK_FILE_CHOOSER(dialog), TRUE);
    gtk_file_chooser_set_current_name(GTK_FILE_CHOOSER(dialog), "programa.usl");

    if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_ACCEPT) {
        char *filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));

        GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(source_editor));
        GtkTextIter start, end;
        gtk_text_buffer_get_start_iter(buffer, &start);
        gtk_text_buffer_get_end_iter(buffer, &end);
        char *text = gtk_text_buffer_get_text(buffer, &start, &end, FALSE);

        FILE *file = fopen(filename, "w");
        if (file) {
            fwrite(text, 1, strlen(text), file);
            fclose(file);
            GtkTextBuffer *err_buf = gtk_text_view_get_buffer(GTK_TEXT_VIEW(token_error_display));
            char *msg = g_strdup_printf("Archivo guardado: %s\n", filename);
            gtk_text_buffer_set_text(err_buf, msg, -1);
            g_free(msg);
        } else {
            GtkTextBuffer *err_buf = gtk_text_view_get_buffer(GTK_TEXT_VIEW(token_error_display));
            gtk_text_buffer_set_text(err_buf, "Error: no se pudo guardar el archivo.\n", -1);
        }

        g_free(text);
        g_free(filename);
    }
    gtk_widget_destroy(dialog);
}

// Callback para botón "Ejecutar"
void on_execute_clicked(GtkWidget *widget, gpointer data) {
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(source_editor));
    GtkTextIter start, end;
    gtk_text_buffer_get_start_iter(buffer, &start);
    gtk_text_buffer_get_end_iter(buffer, &end);
    char *text = gtk_text_buffer_get_text(buffer, &start, &end, FALSE);

    if (!text || strlen(text) == 0) {
        GtkTextBuffer *err_buf = gtk_text_view_get_buffer(GTK_TEXT_VIEW(token_error_display));
        gtk_text_buffer_set_text(err_buf, "Error: El editor está vacío. Escribe o carga código primero.\n", -1);
        g_free(text);
        return;
    }

    // crear archivo temporal
    char temp_filename[] = "/tmp/javlang_temp_XXXXXX.usl";
    int fd = mkstemp(temp_filename);

    if (fd == -1) {
        // Fallback: tmpnam
        char *tmp_name = tmpnam(NULL);
        if (!tmp_name) {
            GtkTextBuffer *err_buf = gtk_text_view_get_buffer(GTK_TEXT_VIEW(token_error_display));
            gtk_text_buffer_set_text(err_buf, "Error: No se pudo generar nombre de archivo temporal.\n", -1);
            g_free(text);
            return;
        }
        strcpy(temp_filename, tmp_name);
        strcat(temp_filename, ".usl");

        FILE *f = fopen(temp_filename, "w");
        if (!f) {
            GtkTextBuffer *err_buf = gtk_text_view_get_buffer(GTK_TEXT_VIEW(token_error_display));
            gtk_text_buffer_set_text(err_buf, "Error: No se pudo crear archivo temporal (fallback).\n", -1);
            g_free(text);
            return;
        }
        fwrite(text, 1, strlen(text), f);
        fclose(f);
    } else {
        write(fd, text, strlen(text));
        close(fd);
    }

    GtkTextBuffer *out_buf = gtk_text_view_get_buffer(GTK_TEXT_VIEW(output_display));
    gtk_text_buffer_set_text(out_buf, "", -1);

    GtkTextBuffer *token_buf = gtk_text_view_get_buffer(GTK_TEXT_VIEW(token_error_display));
    gtk_text_buffer_set_text(token_buf, "Ejecutando...\n", -1);

    OutputBuffer *output_buf = create_buffer();
    capture_output(temp_filename, output_buf);

    gtk_text_buffer_set_text(out_buf, output_buf->buffer, -1);
    gtk_text_buffer_set_text(token_buf, output_buf->buffer, -1);

    free(output_buf->buffer);
    free(output_buf);
    unlink(temp_filename);
    g_free(text);
}

// Función principal de GTK
int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "JavaLang IDE");
    gtk_window_set_default_size(GTK_WINDOW(window), 1000, 700);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    GtkWidget *button_box = gtk_button_box_new(GTK_ORIENTATION_HORIZONTAL);
    gtk_box_set_spacing(GTK_BOX(button_box), 10);

    GtkWidget *load_button = gtk_button_new_with_label("Cargar");
    g_signal_connect(load_button, "clicked", G_CALLBACK(on_load_clicked), window);

    GtkWidget *save_button = gtk_button_new_with_label("Guardar");  // ✅ Nuevo botón
    g_signal_connect(save_button, "clicked", G_CALLBACK(on_save_clicked), window);  // ✅ Conectado

    GtkWidget *execute_button = gtk_button_new_with_label("Ejecutar");
    g_signal_connect(execute_button, "clicked", G_CALLBACK(on_execute_clicked), window);

    gtk_container_add(GTK_CONTAINER(button_box), load_button);
    gtk_container_add(GTK_CONTAINER(button_box), save_button);  // ✅ Añadido al layout
    gtk_container_add(GTK_CONTAINER(button_box), execute_button);
    gtk_box_pack_start(GTK_BOX(vbox), button_box, FALSE, FALSE, 0);

    GtkWidget *hpaned = gtk_paned_new(GTK_ORIENTATION_HORIZONTAL);
    gtk_box_pack_start(GTK_BOX(vbox), hpaned, TRUE, TRUE, 0);

    GtkWidget *scrolled_source = gtk_scrolled_window_new(NULL, NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled_source),
                                   GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);

    source_editor = gtk_text_view_new();
    gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(source_editor), GTK_WRAP_WORD);
    gtk_container_add(GTK_CONTAINER(scrolled_source), source_editor);
    gtk_paned_pack1(GTK_PANED(hpaned), scrolled_source, TRUE, FALSE);

    GtkWidget *scrolled_output = gtk_scrolled_window_new(NULL, NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled_output),
                                   GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);

    output_display = gtk_text_view_new();
    gtk_text_view_set_editable(GTK_TEXT_VIEW(output_display), FALSE);
    gtk_text_view_set_cursor_visible(GTK_TEXT_VIEW(output_display), FALSE);
    gtk_container_add(GTK_CONTAINER(scrolled_output), output_display);
    gtk_paned_pack2(GTK_PANED(hpaned), scrolled_output, TRUE, FALSE);

    GtkWidget *scrolled_tokens = gtk_scrolled_window_new(NULL, NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled_tokens),
                                   GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);

    token_error_display = gtk_text_view_new();
    gtk_text_view_set_editable(GTK_TEXT_VIEW(token_error_display), FALSE);
    gtk_text_view_set_cursor_visible(GTK_TEXT_VIEW(token_error_display), FALSE);
    gtk_container_add(GTK_CONTAINER(scrolled_tokens), token_error_display);
    gtk_box_pack_start(GTK_BOX(vbox), scrolled_tokens, TRUE, TRUE, 0);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}