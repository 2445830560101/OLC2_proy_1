#include "ast.h"
#include "parser.tab.h"
#include <stdarg.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


// --- Variables globales ---
TokenInfo* global_token_list = NULL;
TokenInfo* global_token_tail = NULL;

Symbol* global_symbols = NULL;

SymbolTableEntry* symbol_table_head = NULL;
ErrorEntry* error_table_head = NULL;

int should_break = 0;
int should_continue = 0;

// --- Funciones auxiliares de símbolos ---
Symbol* lookup_symbol(const char* name) {
    Symbol* sym = global_symbols;
    while (sym) {
        if (strcmp(sym->name, name) == 0) {
            return sym;
        }
        sym = sym->next;
    }
    return NULL;
}

Symbol* add_symbol(const char* name, int type, const char* scope) {
    Symbol* sym = malloc(sizeof(Symbol));
    sym->name = strdup(name);
    sym->type = type;
    sym->scope = strdup(scope);
    sym->next = global_symbols;
    global_symbols = sym;
    return sym;
}

// --- Creación de nodos ---
Node* create_node_int(int val) {
    Node* n = malloc(sizeof(Node));
    n->type = NODE_INT;
    n->value.type = VAL_INT;
    n->value.ival = val;
    n->var_name = NULL;
    n->op = 0;
    n->left = n->right = n->cond = n->then_block = n->else_block = NULL;
    n->next = NULL;
    return n;
}

Node* create_node_double(double val) {
    Node* n = malloc(sizeof(Node));
    n->type = NODE_DOUBLE;
    n->value.type = VAL_DOUBLE;
    n->value.fval = val;
    n->var_name = NULL;
    n->op = 0;
    n->left = n->right = n->cond = n->then_block = n->else_block = NULL;
    n->next = NULL;
    return n;
}

Node* create_node_id(char* name) {
    Node* n = malloc(sizeof(Node));
    n->type = NODE_ID;
    n->var_name = strdup(name);
    n->op = 0;
    n->left = n->right = n->cond = n->then_block = n->else_block = NULL;
    n->next = NULL;
    return n;
}

Node* create_node_binop(int op, Node* left, Node* right) {
    Node* n = malloc(sizeof(Node));
    n->type = NODE_BINOP;
    n->op = op;
    n->left = left;
    n->right = right;
    n->var_name = NULL;
    n->next = NULL;
    return n;
}

Node* create_node_unary(int op, Node* expr) {
    Node* n = malloc(sizeof(Node));
    n->type = NODE_UNARY;
    n->op = op;
    n->left = expr;
    n->right = NULL;
    n->var_name = NULL;
    n->next = NULL;
    return n;
}

Node* create_node_assign(char* name, Node* expr) {
    Node* n = malloc(sizeof(Node));
    n->type = NODE_ASSIGN;
    n->var_name = strdup(name);
    n->left = expr;
    n->next = NULL;
    return n;
}

Node* create_node_println(Node* expr) {
    Node* n = malloc(sizeof(Node));
    n->type = NODE_PRINTLN;
    n->left = expr;
    n->next = NULL;
    return n;
}

Node* create_node_if(Node* cond, Node* then_block, Node* else_block) {
    Node* n = malloc(sizeof(Node));
    n->type = NODE_IF_ELSE;
    n->cond = cond;
    n->then_block = then_block;
    n->else_block = else_block;
    n->next = NULL;
    return n;
}

Node* create_node_block(Node* stmts) {
    Node* n = malloc(sizeof(Node));
    n->type = NODE_BLOCK;
    n->left = stmts;
    n->next = NULL;
    return n;
}

Node* create_node_decl(char* name, int type) {
    Node* n = malloc(sizeof(Node));
    n->type = NODE_DECL;
    n->var_name = strdup(name);
    n->value.type = VAL_INT;
    n->value.ival = type;
    n->next = NULL;
    return n;
}

Node* create_node_array_decl(char* name) {
    Node* n = malloc(sizeof(Node));
    n->type = NODE_ARRAY_DECL;
    n->var_name = strdup(name);
    n->next = NULL;
    return n;
}

Node* create_node_array_literal(int* values, int size) {
    Node* n = malloc(sizeof(Node));
    n->type = NODE_ARRAY_LITERAL;

    IntArray* arr = malloc(sizeof(IntArray));
    arr->size = size;
    if (size > 0) {
        arr->data = malloc(sizeof(int) * size);
        memcpy(arr->data, values, sizeof(int) * size);
    } else {
        arr->data = NULL;
    }

    n->value.type = VAL_ARRAY;
    n->value.arr = arr;
    n->next = NULL;
    return n;
}

Node* create_node_array_access(char* array_name, Node* index_expr) {
    Node* n = malloc(sizeof(Node));
    n->type = NODE_ARRAY_ACCESS;
    n->var_name = strdup(array_name);
    n->left = index_expr;
    n->next = NULL;
    return n;
}

Node* create_node_array_assign(char* array_name, Node* index_expr, Node* value_expr) {
    Node* n = malloc(sizeof(Node));
    n->type = NODE_ARRAY_ASSIGN;
    n->var_name = strdup(array_name);
    n->left = index_expr;
    n->right = value_expr;
    n->next = NULL;
    return n;
}

Node* create_node_while(Node* cond, Node* body) {
    Node* n = malloc(sizeof(Node));
    n->type = NODE_WHILE;
    n->cond = cond;
    n->then_block = body;
    n->next = NULL;
    return n;
}

Node* create_node_for(Node* init, Node* cond, Node* update, Node* body) {
    Node* n = malloc(sizeof(Node));
    n->type = NODE_FOR;
    n->left = init;
    n->cond = cond;
    n->right = update;
    n->then_block = body;
    n->next = NULL;
    return n;
}

Node* create_node_switch(Node* expr, Node* cases) {
    Node* n = malloc(sizeof(Node));
    n->type = NODE_SWITCH;
    n->left = expr;
    n->right = cases;
    n->next = NULL;
    return n;
}

Node* create_node_case(Node* value, Node* body, int has_break) {
    Node* n = malloc(sizeof(Node));
    n->type = NODE_CASE;
    n->left = value;
    n->right = body;
    n->value.ival = has_break;
    n->next = NULL;
    return n;
}

Node* create_node_default(Node* body, int has_break) {
    Node* n = malloc(sizeof(Node));
    n->type = NODE_DEFAULT;
    n->left = body;
    n->value.ival = has_break;
    n->next = NULL;
    return n;
}

Node* create_node_break() {
    Node* n = malloc(sizeof(Node));
    n->type = NODE_BREAK;
    n->next = NULL;
    return n;
}

Node* create_node_continue() {
    Node* n = malloc(sizeof(Node));
    n->type = NODE_CONTINUE;
    n->next = NULL;
    return n;
}

Node* create_node_array_length(char* array_name) {
    Node* n = malloc(sizeof(Node));
    n->type = NODE_ARRAY_LENGTH;
    n->var_name = strdup(array_name);
    n->left = n->right = n->cond = n->then_block = n->else_block = NULL;
    n->next = NULL;
    return n;
}


// --- Conversión de valores a string ---
char* value_to_string(NodeValue val) {
    char* buffer = malloc(512);
    switch (val.type) {
        case VAL_INT:
            sprintf(buffer, "%d", val.ival);
            break;
        case VAL_DOUBLE:
            sprintf(buffer, "%.6f", val.fval);
            break;
        case VAL_STRING:
            strcpy(buffer, val.str);
            break;
        case VAL_BOOL:
            strcpy(buffer, val.bval ? "true" : "false");
            break;
        default:
            strcpy(buffer, "null");
    }
    return buffer;
}

// --- Evaluación de expresiones binarias/unarias ---
NodeValue promote_and_compute(NodeValue left, NodeValue right, int op) {
    NodeValue result;
    memset(&result, 0, sizeof(NodeValue));

    if (op == MAS && (left.type == VAL_STRING || right.type == VAL_STRING)) {
        char* left_str = value_to_string(left);
        char* right_str = value_to_string(right);
        char* concat = malloc(strlen(left_str) + strlen(right_str) + 1);
        strcpy(concat, left_str);
        strcat(concat, right_str);
        free(left_str);
        free(right_str);
        result.type = VAL_STRING;
        result.str = concat;
        return result;
    }

    double left_d = (left.type == VAL_DOUBLE) ? left.fval :
                    (left.type == VAL_INT) ? (double)left.ival :
                    (left.type == VAL_BOOL) ? (double)left.bval : 0.0;

    double right_d = (right.type == VAL_DOUBLE) ? right.fval :
                     (right.type == VAL_INT) ? (double)right.ival :
                     (right.type == VAL_BOOL) ? (double)right.bval : 0.0;

    int left_i = (left.type == VAL_INT) ? left.ival :
                 (left.type == VAL_BOOL) ? left.bval :
                 (int)left_d;

    int right_i = (right.type == VAL_INT) ? right.ival :
                  (right.type == VAL_BOOL) ? right.bval :
                  (int)right_d;

    if (op == MAYOR || op == MENOR || op == DIGUAL || op == NIGUAL) {
        int cmp_result;
        if (left.type == VAL_STRING && right.type == VAL_STRING) {
            if (op == DIGUAL) cmp_result = (strcmp(left.str, right.str) == 0);
            else if (op == NIGUAL) cmp_result = (strcmp(left.str, right.str) != 0);
            else cmp_result = 0;
        } else {
            if (op == MAYOR) cmp_result = left_d > right_d;
            else if (op == MENOR) cmp_result = left_d < right_d;
            else if (op == DIGUAL) cmp_result = left_d == right_d;
            else if (op == NIGUAL) cmp_result = left_d != right_d;
        }
        result.type = VAL_BOOL;
        result.bval = cmp_result;
        result.ival = cmp_result;
        return result;
    }

    if (op == AND || op == OR) {
        int left_bool = (left.type == VAL_BOOL) ? left.bval : (left_i != 0);
        int right_bool = (right.type == VAL_BOOL) ? right.bval : (right_i != 0);

        result.bval = (op == AND) ? (left_bool && right_bool) : (left_bool || right_bool);
        result.type = VAL_BOOL;
        result.ival = result.bval;
        return result;
    }

    if (left.type == VAL_DOUBLE || right.type == VAL_DOUBLE) {
        result.type = VAL_DOUBLE;
        switch (op) {
            case MAS: result.fval = left_d + right_d; break;
            case MENOS: result.fval = left_d - right_d; break;
            case MULTI: result.fval = left_d * right_d; break;
            case DIVS: result.fval = right_d != 0 ? left_d / right_d : 0.0; break;
            case MOD: result.fval = fmod(left_d, right_d); break;
            default: result.fval = 0.0; break;
        }
    } else {
        result.type = VAL_INT;
        switch (op) {
            case MAS: result.ival = left_i + right_i; break;
            case MENOS: result.ival = left_i - right_i; break;
            case MULTI: result.ival = left_i * right_i; break;
            case DIVS: result.ival = right_i != 0 ? left_i / right_i : 0; break;
            case MOD: result.ival = right_i != 0 ? left_i % right_i : 0; break;
            default: result.ival = 0; break;
        }
    }

    return result;
}

// --- Evaluación de expresiones ---
NodeValue eval_expr(Node* node) {
    NodeValue val;
    memset(&val, 0, sizeof(NodeValue));

    if (!node) return val;

    switch (node->type) {
        case NODE_INT:
            val.type = VAL_INT;
            val.ival = node->value.ival;
            break;
        case NODE_DOUBLE:
            val.type = VAL_DOUBLE;
            val.fval = node->value.fval;
            break;
        case NODE_ID: {
            Symbol* sym = lookup_symbol(node->var_name);
            if (sym) {
                val = sym->value;
            } else {
                fprintf(stderr, "Error: variable '%s' no declarada\n", node->var_name);
                add_error_to_table("Variable no declarada", "Global", 0, 0);
                val.type = VAL_INT;
                val.ival = 0;
            }
            break;
        }
        case NODE_BINOP: {
            NodeValue left = eval_expr(node->left);
            NodeValue right = eval_expr(node->right);
            val = promote_and_compute(left, right, node->op);
            break;
        }
        case NODE_UNARY: {
            NodeValue operand = eval_expr(node->left);
            if (node->op == NOT) {
                val.type = VAL_BOOL;
                val.bval = !operand.bval;
                val.ival = val.bval;
            } else {
                fprintf(stderr, "Operador unario no soportado: %d\n", node->op);
                add_error_to_table("Operador unario no soportado", "Global", 0, 0);
                val.type = VAL_INT;
                val.ival = 0;
            }
            break;
        }
        case NODE_STRING:
            val.type = VAL_STRING;
            val.str = node->value.str;
            break;
        case NODE_BOOL:
            val.type = VAL_BOOL;
            val.bval = node->value.bval;
            val.ival = node->value.bval;
            break;
        case NODE_ARRAY_LITERAL:
            val = node->value;
            break;
        case NODE_ARRAY_ACCESS: {
            Symbol* sym = lookup_symbol(node->var_name);
            if (!sym || sym->value.type != VAL_ARRAY) {
                fprintf(stderr, "Error: '%s' no es un array o no existe\n", node->var_name);
                add_error_to_table("Array no declarado o tipo incorrecto", "Global", 0, 0);
                val.type = VAL_INT;
                val.ival = 0;
                break;
            }

            NodeValue index_val = eval_expr(node->left);
            if (index_val.type != VAL_INT) {
                fprintf(stderr, "Índice debe ser entero\n");
                add_error_to_table("Índice debe ser entero", "Global", 0, 0);
                val.type = VAL_INT;
                val.ival = 0;
                break;
            }

            int idx = index_val.ival;
            IntArray* arr = sym->value.arr;

            if (idx < 0 || idx >= arr->size) {
                fprintf(stderr, "Índice %d fuera de rango [0, %d)\n", idx, arr->size);
                add_error_to_table("Índice fuera de rango", "Global", 0, 0);
                val.type = VAL_INT;
                val.ival = 0;
            } else {
                val.type = VAL_INT;
                val.ival = arr->data[idx];
            }
            break;
        }

        
        default:
            fprintf(stderr, "Tipo no soportado en eval_expr: %d\n", node->type);
            add_error_to_table("Tipo no soportado en expresión", "Global", 0, 0);
            val.type = VAL_INT;
            val.ival = 0;
            break;
    }
    return val;
}

// --- Evaluación de condiciones ---
int eval_condition(Node* node) {
    NodeValue v = eval_expr(node);
    if (v.type == VAL_BOOL) return v.bval;
    else if (v.type == VAL_INT) return v.ival != 0;
    else if (v.type == VAL_DOUBLE) return v.fval != 0.0;
    else if (v.type == VAL_STRING) return strlen(v.str) > 0;
    return 0;
}

// --- Ejecución de bloques y sentencias ---
void execute_stmt(Node* node);

void execute_block(Node* block) {
    if (!block) return;

    if (block->type == NODE_BLOCK) {
        Node* stmt = block->left;
        while (stmt) {
            execute_stmt(stmt);
            //  break/continue 
            if (should_break || should_continue) {
                break;
            }
            stmt = stmt->next;
        }
    } else {
        execute_stmt(block);
    }
}

void execute_stmt(Node* node) {
    if (!node) return;

    switch (node->type) {
        case NODE_DECL: {
            Symbol* sym = add_symbol(node->var_name, node->value.ival, "Local");
            memset(&sym->value, 0, sizeof(NodeValue));
            sym->value.type = node->value.ival == INT_T ? VAL_INT :
                              node->value.ival == DOUBLE_T ? VAL_DOUBLE :
                              node->value.ival == BOOL_T ? VAL_BOOL : VAL_STRING;
            if (node->value.ival == STRING_T) {
                sym->value.str = strdup("");
            }
            const char* tipo_dato = "int";
            if (node->value.ival == DOUBLE_T) tipo_dato = "double";
            else if (node->value.ival == STRING_T) tipo_dato = "String";
            else if (node->value.ival == BOOL_T) tipo_dato = "boolean";
            add_symbol_to_table(node->var_name, "Variable", tipo_dato, "Local", 0, 0);
            break;
        }
        case NODE_ARRAY_DECL: {
            Symbol* sym = add_symbol(node->var_name, INT_T, "Local");
            sym->value.type = VAL_ARRAY;
            sym->value.arr = NULL;
            add_symbol_to_table(node->var_name, "Array", "int[]", "Local", 0, 0);
            break;
        }
        case NODE_ASSIGN: {
            NodeValue val = eval_expr(node->left);
            Symbol* sym = lookup_symbol(node->var_name);
            if (sym) {
                sym->value = val;
                if (node->left->type == NODE_BOOL) {
                    sym->value.type = VAL_BOOL;
                }
            } else {
                fprintf(stderr, "Error: variable '%s' no declarada\n", node->var_name);
                add_error_to_table("Asignación a variable no declarada", "Global", 0, 0);
            }
            break;
        }
        case NODE_ARRAY_ASSIGN: {
            Symbol* sym = lookup_symbol(node->var_name);
            if (!sym || sym->value.type != VAL_ARRAY) {
                fprintf(stderr, "Error: '%s' no es un array o no existe\n", node->var_name);
                add_error_to_table("Asignación a array no declarado", "Global", 0, 0);
                break;
            }

            NodeValue index_val = eval_expr(node->left);
            NodeValue value_val = eval_expr(node->right);

            if (index_val.type != VAL_INT) {
                fprintf(stderr, "Índice debe ser entero\n");
                add_error_to_table("Índice debe ser entero", "Global", 0, 0);
                break;
            }

            int idx = index_val.ival;
            IntArray* arr = sym->value.arr;

            if (!arr) {
                fprintf(stderr, "Array '%s' no inicializado\n", node->var_name);
                add_error_to_table("Array no inicializado", "Global", 0, 0);
                break;
            }

            if (idx < 0 || idx >= arr->size) {
                fprintf(stderr, "Índice %d fuera de rango [0, %d)\n", idx, arr->size);
                add_error_to_table("Índice fuera de rango", "Global", 0, 0);
                break;
            }

            if (value_val.type != VAL_INT) {
                fprintf(stderr, "Solo se soporta asignación de enteros en arrays por ahora\n");
                add_error_to_table("Tipo de asignación no soportado", "Global", 0, 0);
                break;
            }

            arr->data[idx] = value_val.ival;
            break;
        }
        case NODE_PRINTLN: {
            NodeValue val = eval_expr(node->left);
            switch (val.type) {
                case VAL_STRING: printf("%s\n", val.str); break;
                case VAL_DOUBLE: printf("%.5f\n", val.fval); break;
                case VAL_BOOL: printf("%s\n", val.bval ? "true" : "false"); break;
                case VAL_INT: printf("%d\n", val.ival); break;
                case VAL_ARRAY:
                    if (val.arr) {
                        printf("[");
                        for (int i = 0; i < val.arr->size; i++) {
                            printf("%d", val.arr->data[i]);
                            if (i < val.arr->size - 1) printf(", ");
                        }
                        printf("]\n");
                    } else {
                        printf("null\n");
                    }
                    break;
                default: printf("null\n");
            }
            break;
        }
        case NODE_IF_ELSE: {
            int cond_result = eval_condition(node->cond);
            if (cond_result) {
                execute_block(node->then_block);
            } else if (node->else_block) {
                execute_block(node->else_block);
            }
            break;
        }
        case NODE_WHILE: {
            int local_should_break = 0;
            while (1) {
                if (!eval_condition(node->cond)) break;
                should_continue = 0;
                execute_block(node->then_block);
                if (should_break) {
                    local_should_break = 1;
                    should_break = 0;
                    break;
                }
                if (should_continue) {
                    should_continue = 0;
                    continue;
                }
            }
            if (local_should_break) should_break = 1;
            break;
        }
        case NODE_FOR: {
            int local_should_break = 0;

            // Inicialización
            if (node->left) execute_stmt(node->left);

            while (1) {
                // Condición
                int cond_result = 1;
                if (node->cond) cond_result = eval_condition(node->cond);
                if (!cond_result) break;

                should_continue = 0;
                execute_block(node->then_block);

                if (should_break) {
                    local_should_break = 1;
                    should_break = 0;
                    break;
                }

                // Manejo de continue
                if (should_continue) {
                    should_continue = 0;
                    if (node->right) execute_stmt(node->right);
                    continue;
                }

                // Actualización normal
                if (node->right) execute_stmt(node->right);
            }

            if (local_should_break) should_break = 1;
            break;
        }
        case NODE_SWITCH: {
            NodeValue switch_val = eval_expr(node->left);
            Node* current_case = node->right;
            int matched = 0;
            int local_should_break = 0;

            while (current_case && !local_should_break) {
                if (current_case->type == NODE_CASE) {
                    NodeValue case_val = eval_expr(current_case->left);
                    if (case_val.type == VAL_INT && switch_val.type == VAL_INT && case_val.ival == switch_val.ival) {
                        matched = 1;
                        execute_block(current_case->right);
                        if (current_case->value.ival) local_should_break = 1;
                    }
                } else if (current_case->type == NODE_DEFAULT) {
                    if (!matched) {
                        execute_block(current_case->left);
                        if (current_case->value.ival) local_should_break = 1;
                    }
                }
                if (!local_should_break) current_case = current_case->next;
            }

            if (local_should_break) should_break = 1;
            break;
        }
        case NODE_BREAK:
            should_break = 1;
            break;
        case NODE_CONTINUE:
            should_continue = 1;
            break;
        default:
            fprintf(stderr, "Tipo de sentencia no soportado: %d\n", node->type);
            add_error_to_table("Sentencia no soportada", "Global", 0, 0);
            break;
    }
}

void execute_program(Node* program) {
    if (!program) return;
    if (program->type == NODE_BLOCK) {
        execute_block(program);
    }
}

// --- Gestión de tokens y tablas ---
void add_token(const char* type_name, const char* value_str) {
    TokenInfo* new_token = malloc(sizeof(TokenInfo));
    new_token->type_name = strdup(type_name);
    new_token->value_str = value_str ? strdup(value_str) : NULL;
    new_token->next = NULL;

    if (!global_token_list) {
        global_token_list = new_token;
        global_token_tail = new_token;
    } else {
        global_token_tail->next = new_token;
        global_token_tail = new_token;
    }
}

void print_all_tokens() {
    fprintf(stderr, "=== LISTA DE TOKENS ===\n");
    TokenInfo* token = global_token_list;
    while (token) {
        if (token->value_str) {
            fprintf(stderr, "TOKEN: %s (%s)\n", token->type_name, token->value_str);
        } else {
            fprintf(stderr, "TOKEN: %s\n", token->type_name);
        }
        token = token->next;
    }
    fprintf(stderr, "=======================\n");
}

void free_token_list() {
    TokenInfo* token = global_token_list;
    while (token) {
        TokenInfo* next = token->next;
        free(token->type_name);
        if (token->value_str) free(token->value_str);
        free(token);
        token = next;
    }
    global_token_list = NULL;
    global_token_tail = NULL;
}

void add_symbol_to_table(const char* id, const char* tipo_simbolo, const char* tipo_dato, const char* ambito, int linea, int columna) {
    SymbolTableEntry* new_entry = malloc(sizeof(SymbolTableEntry));
    new_entry->id = strdup(id);
    new_entry->tipo_simbolo = strdup(tipo_simbolo);
    new_entry->tipo_dato = strdup(tipo_dato);
    new_entry->ambito = strdup(ambito);
    new_entry->linea = linea;
    new_entry->columna = columna;
    new_entry->next = NULL;

    if (!symbol_table_head) {
        symbol_table_head = new_entry;
    } else {
        SymbolTableEntry* current = symbol_table_head;
        while (current->next) {
            current = current->next;
        }
        current->next = new_entry;
    }
}

void add_error_to_table(const char* descripcion, const char* ambito, int linea, int columna) {
    static int error_no = 1;
    ErrorEntry* new_entry = malloc(sizeof(ErrorEntry));
    new_entry->no = error_no++;
    new_entry->descripcion = strdup(descripcion);
    new_entry->ambito = strdup(ambito);
    new_entry->linea = linea;
    new_entry->columna = columna;
    new_entry->next = NULL;

    if (!error_table_head) {
        error_table_head = new_entry;
    } else {
        ErrorEntry* current = error_table_head;
        while (current->next) {
            current = current->next;
        }
        current->next = new_entry;
    }
}

void print_symbol_table() {
    FILE* file = fopen("tabla_simbolos.txt", "w");
    if (!file) {
        fprintf(stderr, "Error: no se pudo crear tabla_simbolos.txt\n");
        return;
    }

    fprintf(file, "| ID | Tipo simbolo | Tipo dato | Ambito | Linea | Columna |\n");
    fprintf(file, "|----|--------------|-----------|--------|-------|---------|\n");

    SymbolTableEntry* entry = symbol_table_head;
    while (entry) {
        fprintf(file, "| %s | %s | %s | %s | %d | %d |\n",
                entry->id,
                entry->tipo_simbolo,
                entry->tipo_dato,
                entry->ambito,
                entry->linea,
                entry->columna);
        entry = entry->next;
    }
    fclose(file);
}

void print_error_table() {
    FILE* file = fopen("tabla_errores.txt", "w");
    if (!file) {
        fprintf(stderr, "Error: no se pudo crear tabla_errores.txt\n");
        return;
    }

    fprintf(file, "| No. | Descripción | Ambito | Linea | Columna |\n");
    fprintf(file, "|-----|-------------|--------|-------|---------|\n");

    ErrorEntry* entry = error_table_head;
    while (entry) {
        fprintf(file, "| %d | %s | %s | %d | %d |\n",
                entry->no,
                entry->descripcion,
                entry->ambito,
                entry->linea,
                entry->columna);
        entry = entry->next;
    }
    fclose(file);
}