%{
#include "ast.h" 
#include "parser.tab.h"
#include <string.h>
#include <stdlib.h>

//int yylineno =1;
int yycolno =1; 


void add_token(const char* type_name, const char* value_str);

%}

%option noinput nounput
%option yylineno

STRING      \"([^\\\"]|\\.)*\"
ID          [a-zA-Z_][a-zA-Z0-9_]*
NUMBER      [0-9]+
FLOATNUM    [0-9]*"."[0-9]+

%%
"public"    { add_token("PUBLIC", NULL); return PUBLIC; }
"static"    { add_token("STATIC", NULL); return STATIC; }
"void"      { add_token("VOID", NULL); return VOID; }
"main"      { add_token("MAIN", NULL); return MAIN; }
"class"     { add_token("CLASS", NULL); return CLASS; }
"new"        { add_token("NEW", NULL); return NEW; }
"int"       { add_token("INT", NULL); return INT; }
"double"    { add_token("DOUBLE", NULL); return DOUBLE; }
"String"    { add_token("STRING_KW", NULL); return STRING_KW; }
"boolean"   { add_token("BOOLEAN", NULL); return BOOLEAN; }
"true"      { add_token("BOOL_LITERAL", "true"); yylval.boolean = 1; return BOOL_LITERAL; }
"false"     { add_token("BOOL_LITERAL", "false"); yylval.boolean = 0; return BOOL_LITERAL; }

"System.out.println"    { add_token("PRINTLN", NULL); return PRINTLN; }

"if"        { add_token("IF", NULL); return IF; }
"else"      { add_token("ELSE", NULL); return ELSE; }
"while"      { add_token("WHILE", NULL); return WHILE; }
"for"        { add_token("FOR", NULL); return FOR; }
"switch"    { add_token("SWITCH", NULL); return SWITCH; }
"case"      { add_token("CASE", NULL); return CASE; }
"default"   { add_token("DEFAULT", NULL); return DEFAULT; }
"break"     { add_token("BREAK", NULL); return BREAK; }



{ID}        { add_token("ID", yytext); yylval.id = strdup(yytext); return ID; }
{NUMBER}    { char buffer[32]; sprintf(buffer, "%s", yytext); add_token("INT_LITERAL", buffer); yylval.ival = atoi(yytext); return INT_LITERAL; }
{FLOATNUM}  { char buffer[32]; sprintf(buffer, "%s", yytext); add_token("FLOAT_LITERAL", buffer); yylval.fval = atof(yytext); return FLOAT_LITERAL; }
{STRING}    { add_token("STRING_LITERAL", yytext); yylval.str = strdup(yytext); return STRING_LITERAL; }

"=="        { add_token("DIGUAL", NULL); return DIGUAL; }
"="         { add_token("IGUAL", NULL); return IGUAL; }
";"         { add_token("PCOMA", NULL); return PCOMA; }
"."         { add_token("PUNTO", NULL); return PUNTO; }
".length" { add_token("LENGTH", "length"); return LENGTH; } 
","         { add_token("COMA", NULL); return COMA; }
"("         { add_token("LPAR", NULL); return LPAR; }
")"         { add_token("RPAR", NULL); return RPAR; }
"+"         { add_token("MAS", NULL); return MAS; }
"-"         { add_token("MENOS", NULL); return MENOS; }
"*"         { add_token("MULTI", NULL); return MULTI; }
"/"         { add_token("DIVS", NULL); return DIVS; }
"%"         { add_token("MOD", NULL); return MOD; }
"!="        { add_token("NIGUAL", NULL); return NIGUAL; }
">="        { add_token("MAYOR_IGUAL", NULL); return MAYOR_IGUAL; }
"<="        { add_token("MENOR_IGUAL", NULL); return MENOR_IGUAL; }
">"         { add_token("MAYOR", NULL); return MAYOR; }
"<"         { add_token("MENOR", NULL); return MENOR; }
 
 
"&&"        { add_token("AND", NULL); return AND; }
"||"        { add_token("OR", NULL); return OR; }
"!"         { add_token("NOT", NULL); return NOT; }
"["         { add_token("LCORR", NULL); return LCORR; }
"]"         { add_token("RCORR", NULL); return RCORR; }
"++"        { add_token("INCREMENTO", NULL); return INCREMENTO; }
":"         { add_token("DOSPUNTOS", NULL); return DOSPUNTOS; }
"break"     { add_token("BREAK", NULL); return BREAK; }
"continue"  { add_token("CONTINUE", NULL); return CONTINUE; }


"{"         { add_token("LLLAVE", NULL); return LLLAVE; }
"}"         { add_token("RLLAVE", NULL); return RLLAVE; }



"//".*                     { /* mensaje una linea */ }
"/*"([^*]|\*+[^*/])*\*+\/  { /* mensaje multi linea */ }

[ \t]+       { yycolno += strlen(yytext); }
[\r\n]+      { yylineno++; yycolno = 1; }
.            { yycolno++; add_token("DESCONOCIDO", yytext); return yytext[0]; }

%%

int yywrap() {
    return 1;
}