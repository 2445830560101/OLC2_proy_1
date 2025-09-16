CC = gcc
CFLAGS = -Wall -g
GTK_CFLAGS := $(shell pkg-config --cflags gtk+-3.0)
GTK_LIBS := $(shell pkg-config --libs gtk+-3.0)
LIBS = -lfl -lm  # <-- ¡AÑADIDO -lm!

# Archivos generados
PARSER_C = parser.tab.c
PARSER_H = parser.tab.h
LEXER_C = lex.yy.c

# Objetos del parser/lexer
PARSER_OBJS = $(PARSER_C:.c=.o) $(LEXER_C:.c=.o)

# Objetos del intérprete
INTERPRETER_OBJS = ast.o javalang.o

# Objetos de la GUI
GUI_OBJS = main.o

# Objetos completos
ALL_OBJS = $(PARSER_OBJS) $(INTERPRETER_OBJS) $(GUI_OBJS)

# Binarios
TARGET_INTERPRETER = javalang
TARGET_GUI = javlang-ide

.PHONY: all clean

all: $(TARGET_INTERPRETER) $(TARGET_GUI)

# Generar parser y lexer
$(PARSER_C) $(PARSER_H): parser.y
	bison -d parser.y

$(LEXER_C): lexer.l
	flex lexer.l

# Compilar objetos
%.o: %.c
	$(CC) $(CFLAGS) $(GTK_CFLAGS) -c $< -o $@

# Enlazar intérprete (consola)
$(TARGET_INTERPRETER): $(PARSER_OBJS) $(INTERPRETER_OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

# Enlazar GUI
$(TARGET_GUI): $(ALL_OBJS)
	$(CC) $(CFLAGS) $(GTK_CFLAGS) -o $@ $^ $(GTK_LIBS) $(LIBS)


clean:
	rm -f $(TARGET_INTERPRETER) $(TARGET_GUI) *.o $(PARSER_C) $(PARSER_H) $(LEXER_C)