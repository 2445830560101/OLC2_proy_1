#include "ast.h"
#include "parser.tab.h"
#include <stdio.h>


// Variable global 
int show_tokens = 1;

// Función principal del intérprete 
void run_interpreter() {

    
        // imprimir cabecera
    if (show_tokens) {
        printf("JavaLang Interpreter (con AST y tabla de símbolos)\n");
    }

    // Iniciar el parser
    int result = yyparse();
    
    if (result == 0) {
        // Éxito
        // Imprimir tokens
        print_all_tokens();
        // Imprimir tablas
        print_symbol_table();
        print_error_table();
    } else {
        fprintf(stderr, "Error durante el parseo.\n");
    }
}

// Función main original 
#ifdef STANDALONE_INTERPRETER
int main(int argc, char *argv[]) {
    if (argc > 1) {
        if (freopen(argv[1], "r", stdin) == NULL) {
            fprintf(stderr, "Error: no se pudo abrir el archivo %s\n", argv[1]);
            return 1;
        }
    }
    run_interpreter();
    return 0;
}
#endif