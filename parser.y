%{
#include "ast.h"
#include "parser.tab.h"

int yydebug = 1;

void yyerror(const char *s);
int yylex();

void add_token(const char* type_name, const char* value_str);
void print_all_tokens();
void free_token_list();
Node* create_node_while(Node* cond, Node* body); 
Node* create_node_for(Node* init, Node* cond, Node* update, Node* body);
Node* create_node_switch(Node* expr, Node* cases);
Node* create_node_case(Node* value, Node* body, int has_break);
Node* create_node_default(Node* body, int has_break);
Node* create_node_break();
Node* create_node_continue();


%}

%union {
    int ival;
    double fval;
    char* str;
    int boolean;
    char* id;
    Node* node;
}

%token CLASS INT DOUBLE BOOLEAN PRINTLN EQUAL
%token <ival> INT_LITERAL
%token <fval> FLOAT_LITERAL
%token <str> STRING_LITERAL
%token <boolean> BOOL_LITERAL
%token <id> ID
%token IGUAL PCOMA LPAR RPAR MAS MENOS MULTI DIVS DIGUAL NIGUAL MAYOR MENOR AND OR NOT
%token IF ELSE WHILE FOR LLLAVE RLLAVE
%token PUBLIC STATIC VOID MAIN STRING_KW  
%token LCORR RCORR
%token PUNTO
%token COMA
%token DOSPUNTOS
%token INCREMENTO
%token MENOR_IGUAL 
%token MAYOR_IGUAL 
%token SWITCH CASE DEFAULT BREAK
%token CONTINUE
%token MOD
%token LENGTH
%token NEW


/* --- DECLARACIÓN DE TIPOS PARA NUEVAS REGLAS --- */
%type <node> programa clase sentencias sentencia bloque if_sentencia
%type <node> expresion print declaracion asignacion println
%type <node> condicion
%type <node> metodo_main
%type <node> cuerpo_clase
%type <node> while_sentencia
%type <node> for_sentencia
%type <node> asignacion_opt
%type <node> condicion_opt
%type <node> expresion_opt
%type <node> asignacion_sin_pcoma
%type <node> declaracion_sin_pcoma
%type <node> array_literal lista_enteros
%type <node> switch_sentencia case_lista case_item
%type <node> sentencias_opt  

%left OR
%left AND
%left DIGUAL NIGUAL
%left MAYOR MENOR
%left MAS MENOS
%left MULTI DIVS MOD
%right INCREMENTO
%right NOT
%right UMINUS

%start programa

%%

programa:
    clase { 
        execute_program($1); 
        //print_all_tokens(); 
        //free_token_list(); 
    }
    ;

clase: 
    PUBLIC CLASS ID LLLAVE cuerpo_clase RLLAVE
    {
        $$ = $5; 
        printf("Clase %s definida\n", $3);
        free($3);
    }
    ;

cuerpo_clase:
    metodo_main { $$ = $1; }
    | sentencias { $$ = create_node_block($1); }
    ;

metodo_main:
    PUBLIC STATIC VOID MAIN LPAR STRING_KW LCORR RCORR ID RPAR LLLAVE sentencias RLLAVE
    {
        $$ = create_node_block($12);
        printf("Método main encontrado - ejecutando...\n");
    }
    ;

sentencias:
    sentencia { $$ = $1; }
    | sentencias sentencia
    {
        Node* current = $1;
        while (current->next) current = current->next;
        current->next = $2;
        $$ = $1;
    }
    ;

bloque:
    LLLAVE RLLAVE { $$ = create_node_block(NULL); }
    | LLLAVE sentencias RLLAVE { $$ = create_node_block($2); }
    ;

sentencia:
    declaracion { $$ = $1; }
    | asignacion { $$ = $1; }
    | println { $$ = $1; }
    | if_sentencia { $$ = $1; }
    | while_sentencia { $$ = $1; }
    | for_sentencia { $$ = $1; }
    | switch_sentencia { $$ = $1; }
    | BREAK PCOMA { $$ = create_node_break(); }
    | CONTINUE PCOMA { $$ = create_node_continue(); }
    ;

declaracion_sin_pcoma:
    INT ID IGUAL expresion { 
        add_symbol_to_table($2, "Variable", "int", "Local", yylineno, yycolno);
        $$ = create_node_decl($2, INT_T); 
        free($2);
    }
    | DOUBLE ID IGUAL expresion { 
        add_symbol_to_table($2, "Variable", "double", "Local", yylineno, yycolno);
        Node* decl = create_node_decl($2, DOUBLE_T);
        Node* assign = create_node_assign($2, $4);
        decl->next = assign;
        $$ = decl;
        free($2);
    }
    | STRING_KW ID IGUAL expresion { 
        add_symbol_to_table($2, "Variable", "String", "Local", yylineno, yycolno);
        Node* decl = create_node_decl($2, STRING_T);
        Node* assign = create_node_assign($2, $4);
        decl->next = assign;
        $$ = decl;
        free($2);
    }
    | BOOLEAN ID IGUAL expresion { 
        add_symbol_to_table($2, "Variable", "boolean", "Local", yylineno, yycolno);
        Node* decl = create_node_decl($2, BOOL_T);
        Node* assign = create_node_assign($2, $4);
        decl->next = assign;
        $$ = decl;
        free($2);
    }
    ;

declaracion:
declaracion_sin_pcoma PCOMA { $$ = $1; }
    |INT ID PCOMA { 
        add_symbol_to_table($2, "Variable", "int", "Global", yylineno, yycolno);
        $$ = create_node_decl($2, INT_T); 
        free($2);
    }
    | INT ID IGUAL expresion PCOMA { 
        add_symbol_to_table($2, "Variable", "int", "Global", yylineno, yycolno);
        Node* decl = create_node_decl($2, INT_T);
        Node* assign = create_node_assign($2, $4);
        decl->next = assign;
        $$ = decl;
        free($2);
    }
    | DOUBLE ID PCOMA { 
        add_symbol_to_table($2, "Variable", "double", "Global", yylineno, yycolno);
        $$ = create_node_decl($2, DOUBLE_T); 
        free($2);
    }
    | DOUBLE ID IGUAL expresion PCOMA { 
        add_symbol_to_table($2, "Variable", "double", "Global", yylineno, yycolno);
        Node* decl = create_node_decl($2, DOUBLE_T);
        Node* assign = create_node_assign($2, $4);
        decl->next = assign;
        $$ = decl;
        free($2);
    }
    | STRING_KW ID PCOMA { 
        add_symbol_to_table($2, "Variable", "String", "Global", yylineno, yycolno);
        $$ = create_node_decl($2, STRING_T); 
        free($2);
    }
    | STRING_KW ID IGUAL expresion PCOMA { 
        add_symbol_to_table($2, "Variable", "String", "Global", yylineno, yycolno);
        Node* decl = create_node_decl($2, STRING_T);
        Node* assign = create_node_assign($2, $4);
        decl->next = assign;
        $$ = decl;
        free($2);
    }
    | BOOLEAN ID PCOMA { 
        add_symbol_to_table($2, "Variable", "boolean", "Global", yylineno, yycolno);
        $$ = create_node_decl($2, BOOL_T); 
        free($2);
    }
    | BOOLEAN ID IGUAL expresion PCOMA { 
        add_symbol_to_table($2, "Variable", "boolean", "Global", yylineno, yycolno);
        Node* decl = create_node_decl($2, BOOL_T);
        Node* assign = create_node_assign($2, $4);
        decl->next = assign;
        $$ = decl;
        free($2);
    }
    | INT LCORR RCORR ID PCOMA
    {
        add_symbol_to_table($4, "Array", "int[]", "Global", yylineno, yycolno);
        $$ = create_node_array_decl($4);
        free($4);
    }
    | INT LCORR RCORR ID IGUAL array_literal PCOMA
    {
        add_symbol_to_table($4, "Array", "int[]", "Global", yylineno, yycolno);
        Node* decl = create_node_array_decl($4);
        Node* assign = create_node_assign($4, $6);
        decl->next = assign;
        $$ = decl;
        free($4);
    }
    ;

array_literal:
    LLLAVE RLLAVE
    {
        $$ = create_node_array_literal(NULL, 0);
    }
    | LLLAVE lista_enteros RLLAVE
    {
        $$ = $2;
    }
    ;

lista_enteros:
    INT_LITERAL
    {
        int* vals = malloc(sizeof(int));
        vals[0] = $1;
        $$ = create_node_array_literal(vals, 1);
        free(vals);
    }
    | lista_enteros COMA INT_LITERAL
    {
        Node* prev = $1;
        if (prev && prev->type == NODE_ARRAY_LITERAL) {
            IntArray* old_arr = prev->value.arr;
            int new_size = old_arr->size + 1;
            int* new_data = malloc(sizeof(int) * new_size);
            if (old_arr->size > 0) {
                memcpy(new_data, old_arr->data, sizeof(int) * old_arr->size);
            }
            new_data[old_arr->size] = $3;

            if (old_arr->data) free(old_arr->data);
            free(old_arr);

            $$ = create_node_array_literal(new_data, new_size);
            free(new_data);
        } else {
            fprintf(stderr, "Error: lista_enteros mal formada\n");
            $$ = create_node_int(0);
        }
    }
    ;

asignacion:
    asignacion_sin_pcoma PCOMA { $$ = $1; }
    | ID LCORR expresion RCORR IGUAL expresion PCOMA
    {
        $$ = create_node_array_assign($1, $3, $6);
        free($1);
    }
    ;

asignacion_sin_pcoma:
    ID IGUAL expresion { $$ = create_node_assign($1, $3); free($1); }
    ;

println:
    PRINTLN LPAR RPAR PCOMA { 
        // Crear un nodo println con string vacío
        Node* empty_str = malloc(sizeof(Node));
        empty_str->type = NODE_STRING;
        empty_str->value.str = strdup("");
        empty_str->next = NULL;
        $$ = create_node_println(empty_str);
    }
    |PRINTLN LPAR print RPAR PCOMA { $$ = create_node_println($3); }
    ;

print:
    STRING_LITERAL 
    { 
        Node* n = malloc(sizeof(Node));
        n->type = NODE_STRING;
        n->value.str = strdup($1);
        n->next = NULL;
        $$ = n;
        free($1);
    }
    | expresion { $$ = $1; }
    | print MAS print 
    {
        Node* n = malloc(sizeof(Node));
        n->type = NODE_BINOP;
        n->op = MAS;  
        n->left = $1;
        n->right = $3;
        n->next = NULL;
        $$ = n;
    }
    ;

if_sentencia:
    IF LPAR condicion RPAR bloque  %prec IF
    {
        $$ = create_node_if($3, $5, NULL);
    }
    | IF LPAR condicion RPAR bloque ELSE if_sentencia
    {
        $$ = create_node_if($3, $5, $7);
    }
    | IF LPAR condicion RPAR bloque ELSE bloque
    {
        $$ = create_node_if($3, $5, $7);
    }
    ;

while_sentencia:
    WHILE LPAR condicion RPAR bloque
    {
        $$ = create_node_while($3, $5);
    }
    ;

condicion:
    expresion { $$ = $1; }
    ;

for_sentencia:
    FOR LPAR asignacion_opt PCOMA condicion_opt PCOMA expresion_opt RPAR bloque
    {
        $$ = create_node_for($3, $5, $7, $9);
    }
    ;

asignacion_opt:
    /* vacío */ { $$ = NULL; }
    | asignacion_sin_pcoma { $$ = $1; }
    | declaracion_sin_pcoma  { $$ = $1; }
    ;

condicion_opt:
    /* vacío */ { $$ = NULL; }
    | expresion { $$ = $1; }
    ;

expresion_opt:
    /* vacío */ { $$ = NULL; }
    | expresion { $$ = $1; }
    ;


switch_sentencia:
    SWITCH LPAR expresion RPAR LLLAVE case_lista RLLAVE
    {
        $$ = create_node_switch($3, $6);
    }
    ;

case_lista:
    case_item { 
        $$ = $1; 
        $1->next = NULL;
    }
    | case_lista case_item { 
        Node* current = $1;
        while (current->next) {
            current = current->next;
        }
        current->next = $2;
        $$ = $1;
    }
    ;


case_item:
    CASE expresion DOSPUNTOS sentencias_opt BREAK PCOMA
    {
        $$ = create_node_case($2, $4, 1); 
    }
    | CASE expresion DOSPUNTOS sentencias_opt
    {
        $$ = create_node_case($2, $4, 0); 
    }
    | DEFAULT DOSPUNTOS sentencias_opt BREAK PCOMA
    {
        $$ = create_node_default($3, 1);
    }
    | DEFAULT DOSPUNTOS sentencias_opt
    {
        $$ = create_node_default($3, 0);
    }
    ;

sentencias_opt:
    /* vacío */ { $$ = create_node_block(NULL); }
    | sentencias { $$ = $1; }
    ;


expresion:
    INT_LITERAL { $$ = create_node_int($1); }
    | FLOAT_LITERAL { $$ = create_node_double($1); }
    | STRING_LITERAL  
    { 
        Node* n = malloc(sizeof(Node));
        n->type = NODE_STRING;
        n->value.str = strdup($1);
        n->next = NULL;
        $$ = n;
        free($1);
    }
    | BOOL_LITERAL  
    {
        Node* n = malloc(sizeof(Node));
        n->type = NODE_BOOL;
        n->value.bval = $1;
        n->next = NULL;
        $$ = n;
    }
    | ID { $$ = create_node_id($1); free($1); }
    | expresion MAS expresion { $$ = create_node_binop(MAS, $1, $3); }
    | expresion MENOS expresion { $$ = create_node_binop(MENOS, $1, $3); }
    | expresion MULTI expresion { $$ = create_node_binop(MULTI, $1, $3); }
    | expresion DIVS expresion { $$ = create_node_binop(DIVS, $1, $3); }
    | expresion MAYOR expresion { $$ = create_node_binop(MAYOR, $1, $3); }
    | expresion MENOR expresion { $$ = create_node_binop(MENOR, $1, $3); }
    | expresion DIGUAL expresion { $$ = create_node_binop(DIGUAL, $1, $3); }
    | expresion NIGUAL expresion { $$ = create_node_binop(NIGUAL, $1, $3); }
    | expresion AND expresion { $$ = create_node_binop(AND, $1, $3); }
    | expresion OR expresion { $$ = create_node_binop(OR, $1, $3); }
    | LPAR expresion RPAR { $$ = $2; }
    | expresion PUNTO ID LPAR expresion RPAR
    {
        if (strcmp($3,"equals")==0){
            $$ = create_node_binop(DIGUAL,$1,$5);
        } else {
            fprintf(stderr,"Metodo no soportado: %s\n",$3);
            $$ = create_node_int(0);
        }
        free($3);
    }
    | NOT expresion %prec UMINUS { $$ = create_node_unary(NOT, $2); }
    | ID LCORR expresion RCORR
    {
        $$ = create_node_array_access($1, $3);
        free($1);
    }
    
    | ID INCREMENTO %prec INCREMENTO 
    {
        Node* id_node = create_node_id($1);
        Node* one_node = create_node_int(1);
        Node* add_node = create_node_binop(MAS, id_node, one_node);
        $$ = create_node_assign($1, add_node);
        free($1);
    }
    | expresion MENOR_IGUAL expresion { $$ = create_node_binop(MENOR_IGUAL, $1, $3); }
    | expresion MAYOR_IGUAL expresion { $$ = create_node_binop(MAYOR_IGUAL, $1, $3); }
    | expresion MOD expresion { $$ = create_node_binop(MOD, $1, $3); }

    ;

%%

void yyerror(const char *s) {
    extern int yychar;
    extern char* yytext;
    fprintf(stderr, "Error en línea %d, columna %d: %s\n", yylineno, yycolno, s);
    fprintf(stderr, "Token actual: %d, texto: '%s'\n", yychar, yytext ? yytext : "NULL");
}