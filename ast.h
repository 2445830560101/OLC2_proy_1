#ifndef AST_H
#define AST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

extern int yylineno;
extern int yycolno;
extern int should_break;
extern int should_continue;



// Tipos de nodo del AST
typedef enum {
    NODE_INT,
    NODE_DOUBLE,
    NODE_STRING,
    NODE_BOOL,
    NODE_ID,
    NODE_BINOP,
    NODE_UNARY,
    NODE_ASSIGN,
    NODE_PRINTLN,
    NODE_IF_ELSE,
    NODE_BLOCK,
    NODE_DECL,
    NODE_ARRAY_DECL,
    NODE_ARRAY_LITERAL,
    NODE_ARRAY_ACCESS,
    NODE_ARRAY_ASSIGN,
    NODE_WHILE,
    NODE_FOR,
    NODE_SWITCH,
    NODE_CASE,
    NODE_DEFAULT,
    NODE_BREAK,
    NODE_CONTINUE,
    NODE_ARRAY_LENGTH
} NodeType;

// Estructura para arrays de enteros
typedef struct {
    int* data;
    int size;
} IntArray;

// Tipos de datos para declaraciones
enum { INT_T, DOUBLE_T, STRING_T, BOOL_T };

// Tipos de valor
typedef enum {
    VAL_INT,
    VAL_DOUBLE,
    VAL_STRING,
    VAL_BOOL,
    VAL_ARRAY
} ValueType;

// Valor genérico con tipo
typedef struct {
    ValueType type;
    union {
        int ival;
        double fval;
        char* str;
        int bval;
        IntArray* arr;
    };
} NodeValue;

// Nodo del AST
typedef struct Node Node;
struct Node {
    NodeType type;
    NodeValue value;
    char* var_name;
    int op;
    Node *left, *right;
    Node *cond, *then_block, *else_block;
    Node *next;
};

// Tabla de símbolos
typedef struct Symbol Symbol;
struct Symbol {
    char* name;
    int type;
    NodeValue value;
    char* scope; 
    Symbol* next;
};

// Estructura para tokens
typedef struct TokenInfo {
    char* type_name;
    char* value_str;
    struct TokenInfo* next;
} TokenInfo;

extern TokenInfo* global_token_list;
extern TokenInfo* global_token_tail;

// Estructura para tabla de símbolos
typedef struct SymbolTableEntry {
    char* id;
    char* tipo_simbolo;
    char* tipo_dato;
    char* ambito;
    int linea;
    int columna;
    struct SymbolTableEntry* next;
} SymbolTableEntry;

// Estructura para tabla de errores
typedef struct ErrorEntry {
    int no;
    char* descripcion;
    char* ambito;
    int linea;
    int columna;
    struct ErrorEntry* next;
} ErrorEntry;

extern Symbol* global_symbols;
extern SymbolTableEntry* symbol_table_head;
extern ErrorEntry* error_table_head;

// Declaraciones de funciones
Symbol* lookup_symbol(const char* name);
Symbol* add_symbol(const char* name, int type, const char* scope);
Node* create_node_int(int val);
Node* create_node_double(double val);
Node* create_node_id(char* name);
Node* create_node_binop(int op, Node* left, Node* right);
Node* create_node_unary(int op, Node* expr);
Node* create_node_assign(char* name, Node* expr);
Node* create_node_println(Node* expr);
Node* create_node_if(Node* cond, Node* then_block, Node* else_block);
Node* create_node_block(Node* stmts);
Node* create_node_decl(char* name, int type);
Node* create_node_array_decl(char* name);
Node* create_node_array_literal(int* values, int size);
Node* create_node_array_access(char* array_name, Node* index_expr);
Node* create_node_array_assign(char* array_name, Node* index_expr, Node* value_expr);
NodeValue eval_expr(Node* node);
int eval_condition(Node* node);
void execute_stmt(Node* node);
void execute_block(Node* block);
void execute_program(Node* program);
void add_token(const char* type_name, const char* value_str);
void print_all_tokens();
void free_token_list();
void add_symbol_to_table(const char* id, const char* tipo_simbolo, const char* tipo_dato, const char* ambito, int linea, int columna);
void add_error_to_table(const char* descripcion, const char* ambito, int linea, int columna);
void print_symbol_table();
void print_error_table();

#endif