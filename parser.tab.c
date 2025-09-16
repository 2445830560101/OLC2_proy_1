/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

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



#line 94 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_CLASS = 3,                      /* CLASS  */
  YYSYMBOL_INT = 4,                        /* INT  */
  YYSYMBOL_DOUBLE = 5,                     /* DOUBLE  */
  YYSYMBOL_BOOLEAN = 6,                    /* BOOLEAN  */
  YYSYMBOL_PRINTLN = 7,                    /* PRINTLN  */
  YYSYMBOL_EQUAL = 8,                      /* EQUAL  */
  YYSYMBOL_INT_LITERAL = 9,                /* INT_LITERAL  */
  YYSYMBOL_FLOAT_LITERAL = 10,             /* FLOAT_LITERAL  */
  YYSYMBOL_STRING_LITERAL = 11,            /* STRING_LITERAL  */
  YYSYMBOL_BOOL_LITERAL = 12,              /* BOOL_LITERAL  */
  YYSYMBOL_ID = 13,                        /* ID  */
  YYSYMBOL_IGUAL = 14,                     /* IGUAL  */
  YYSYMBOL_PCOMA = 15,                     /* PCOMA  */
  YYSYMBOL_LPAR = 16,                      /* LPAR  */
  YYSYMBOL_RPAR = 17,                      /* RPAR  */
  YYSYMBOL_MAS = 18,                       /* MAS  */
  YYSYMBOL_MENOS = 19,                     /* MENOS  */
  YYSYMBOL_MULTI = 20,                     /* MULTI  */
  YYSYMBOL_DIVS = 21,                      /* DIVS  */
  YYSYMBOL_DIGUAL = 22,                    /* DIGUAL  */
  YYSYMBOL_NIGUAL = 23,                    /* NIGUAL  */
  YYSYMBOL_MAYOR = 24,                     /* MAYOR  */
  YYSYMBOL_MENOR = 25,                     /* MENOR  */
  YYSYMBOL_AND = 26,                       /* AND  */
  YYSYMBOL_OR = 27,                        /* OR  */
  YYSYMBOL_NOT = 28,                       /* NOT  */
  YYSYMBOL_IF = 29,                        /* IF  */
  YYSYMBOL_ELSE = 30,                      /* ELSE  */
  YYSYMBOL_WHILE = 31,                     /* WHILE  */
  YYSYMBOL_FOR = 32,                       /* FOR  */
  YYSYMBOL_LLLAVE = 33,                    /* LLLAVE  */
  YYSYMBOL_RLLAVE = 34,                    /* RLLAVE  */
  YYSYMBOL_PUBLIC = 35,                    /* PUBLIC  */
  YYSYMBOL_STATIC = 36,                    /* STATIC  */
  YYSYMBOL_VOID = 37,                      /* VOID  */
  YYSYMBOL_MAIN = 38,                      /* MAIN  */
  YYSYMBOL_STRING_KW = 39,                 /* STRING_KW  */
  YYSYMBOL_LCORR = 40,                     /* LCORR  */
  YYSYMBOL_RCORR = 41,                     /* RCORR  */
  YYSYMBOL_PUNTO = 42,                     /* PUNTO  */
  YYSYMBOL_COMA = 43,                      /* COMA  */
  YYSYMBOL_DOSPUNTOS = 44,                 /* DOSPUNTOS  */
  YYSYMBOL_INCREMENTO = 45,                /* INCREMENTO  */
  YYSYMBOL_MENOR_IGUAL = 46,               /* MENOR_IGUAL  */
  YYSYMBOL_MAYOR_IGUAL = 47,               /* MAYOR_IGUAL  */
  YYSYMBOL_SWITCH = 48,                    /* SWITCH  */
  YYSYMBOL_CASE = 49,                      /* CASE  */
  YYSYMBOL_DEFAULT = 50,                   /* DEFAULT  */
  YYSYMBOL_BREAK = 51,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 52,                  /* CONTINUE  */
  YYSYMBOL_MOD = 53,                       /* MOD  */
  YYSYMBOL_LENGTH = 54,                    /* LENGTH  */
  YYSYMBOL_NEW = 55,                       /* NEW  */
  YYSYMBOL_UMINUS = 56,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 57,                  /* $accept  */
  YYSYMBOL_programa = 58,                  /* programa  */
  YYSYMBOL_clase = 59,                     /* clase  */
  YYSYMBOL_cuerpo_clase = 60,              /* cuerpo_clase  */
  YYSYMBOL_metodo_main = 61,               /* metodo_main  */
  YYSYMBOL_sentencias = 62,                /* sentencias  */
  YYSYMBOL_bloque = 63,                    /* bloque  */
  YYSYMBOL_sentencia = 64,                 /* sentencia  */
  YYSYMBOL_declaracion_sin_pcoma = 65,     /* declaracion_sin_pcoma  */
  YYSYMBOL_declaracion = 66,               /* declaracion  */
  YYSYMBOL_array_literal = 67,             /* array_literal  */
  YYSYMBOL_lista_enteros = 68,             /* lista_enteros  */
  YYSYMBOL_asignacion = 69,                /* asignacion  */
  YYSYMBOL_asignacion_sin_pcoma = 70,      /* asignacion_sin_pcoma  */
  YYSYMBOL_println = 71,                   /* println  */
  YYSYMBOL_print = 72,                     /* print  */
  YYSYMBOL_if_sentencia = 73,              /* if_sentencia  */
  YYSYMBOL_while_sentencia = 74,           /* while_sentencia  */
  YYSYMBOL_condicion = 75,                 /* condicion  */
  YYSYMBOL_for_sentencia = 76,             /* for_sentencia  */
  YYSYMBOL_asignacion_opt = 77,            /* asignacion_opt  */
  YYSYMBOL_condicion_opt = 78,             /* condicion_opt  */
  YYSYMBOL_expresion_opt = 79,             /* expresion_opt  */
  YYSYMBOL_switch_sentencia = 80,          /* switch_sentencia  */
  YYSYMBOL_case_lista = 81,                /* case_lista  */
  YYSYMBOL_case_item = 82,                 /* case_item  */
  YYSYMBOL_sentencias_opt = 83,            /* sentencias_opt  */
  YYSYMBOL_expresion = 84                  /* expresion  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   575

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  91
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  214

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   311


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    87,    87,    95,   104,   105,   109,   117,   118,   128,
     129,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     145,   150,   158,   166,   177,   178,   183,   191,   196,   204,
     209,   217,   222,   230,   236,   248,   252,   259,   266,   291,
     292,   300,   304,   312,   316,   325,   326,   339,   343,   347,
     354,   361,   365,   372,   373,   374,   378,   379,   383,   384,
     389,   396,   400,   412,   416,   420,   424,   431,   432,   437,
     438,   439,   448,   456,   457,   458,   459,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   478,   479,   485,   493,
     494,   495
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "CLASS", "INT",
  "DOUBLE", "BOOLEAN", "PRINTLN", "EQUAL", "INT_LITERAL", "FLOAT_LITERAL",
  "STRING_LITERAL", "BOOL_LITERAL", "ID", "IGUAL", "PCOMA", "LPAR", "RPAR",
  "MAS", "MENOS", "MULTI", "DIVS", "DIGUAL", "NIGUAL", "MAYOR", "MENOR",
  "AND", "OR", "NOT", "IF", "ELSE", "WHILE", "FOR", "LLLAVE", "RLLAVE",
  "PUBLIC", "STATIC", "VOID", "MAIN", "STRING_KW", "LCORR", "RCORR",
  "PUNTO", "COMA", "DOSPUNTOS", "INCREMENTO", "MENOR_IGUAL", "MAYOR_IGUAL",
  "SWITCH", "CASE", "DEFAULT", "BREAK", "CONTINUE", "MOD", "LENGTH", "NEW",
  "UMINUS", "$accept", "programa", "clase", "cuerpo_clase", "metodo_main",
  "sentencias", "bloque", "sentencia", "declaracion_sin_pcoma",
  "declaracion", "array_literal", "lista_enteros", "asignacion",
  "asignacion_sin_pcoma", "println", "print", "if_sentencia",
  "while_sentencia", "condicion", "for_sentencia", "asignacion_opt",
  "condicion_opt", "expresion_opt", "switch_sentencia", "case_lista",
  "case_item", "sentencias_opt", "expresion", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-110)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-45)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -9,    34,    42,  -110,    31,  -110,    13,    47,    -5,    43,
      46,    45,     3,    56,    61,    68,    58,    74,    86,    92,
      94,    77,  -110,   181,  -110,    98,  -110,  -110,   117,  -110,
    -110,  -110,  -110,  -110,    35,    88,    66,   108,    80,   164,
     164,   164,   164,    18,    97,   110,   164,  -110,  -110,  -110,
    -110,  -110,  -110,   164,  -110,   123,   164,  -110,   164,  -110,
    -110,  -110,   141,  -110,   -20,   164,   127,   164,   143,   467,
    -110,   467,   411,   132,   467,   135,   154,   159,   170,   177,
     180,  -110,  -110,   182,   157,   164,  -110,   326,   216,   125,
     229,   265,   164,  -110,   363,  -110,   122,   184,   195,   164,
     164,   164,   164,   164,   164,   164,   164,   164,   164,   183,
     164,   164,   164,   186,   176,   176,   200,   201,   202,   203,
     164,   205,   278,   185,  -110,   189,  -110,  -110,  -110,   421,
    -110,  -110,  -110,    -6,    -6,   122,   122,   522,   522,    -8,
      -8,   512,   503,   208,   467,   467,   122,   164,    99,   196,
    -110,   164,   164,   164,   164,   204,   467,   188,  -110,   121,
      -2,   210,  -110,   164,   314,  -110,   114,     0,   467,   467,
     467,   467,   164,   190,   164,   213,    51,  -110,  -110,  -110,
     -16,  -110,   375,  -110,  -110,  -110,  -110,   211,   467,   218,
     457,   181,  -110,  -110,  -110,   236,  -110,   176,   233,   181,
     181,   209,  -110,  -110,   244,   214,   249,   234,   251,  -110,
     181,  -110,   150,  -110
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     0,     1,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     4,     5,     7,     0,    11,    12,     0,    13,
      14,    15,    16,    17,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    53,     0,     0,     0,    18,    19,     3,
       8,    24,    39,     0,    25,     0,     0,    27,     0,    31,
      69,    70,    71,    72,    73,     0,     0,     0,     0,    45,
      71,    41,     0,     0,    51,     0,     0,     0,     0,     0,
       0,    55,    54,     0,     0,     0,    29,     0,     0,     0,
       0,     0,     0,    88,     0,    42,    86,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      56,     0,     0,     0,    26,     0,    33,    28,    32,     0,
      84,    43,    46,    74,    75,    76,    77,    80,    81,    78,
      79,    82,    83,     0,    89,    90,    91,     0,     0,    47,
      50,     0,     0,     0,     0,     0,    57,     0,    30,     0,
       0,     0,    87,     0,     0,     9,     0,     0,    20,    21,
      23,    22,    58,     0,     0,     0,     0,    61,    37,    35,
       0,    34,     0,    40,    10,    49,    48,     0,    59,     0,
       0,    67,    60,    62,    36,     0,    85,     0,     0,    67,
      68,    66,    38,    52,     0,    64,     0,     0,     0,    65,
       0,    63,     0,     6
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -110,  -110,  -110,  -110,  -110,    -7,  -109,   -22,   225,  -110,
    -110,  -110,  -110,   227,  -110,   174,   106,  -110,   232,  -110,
    -110,  -110,  -110,  -110,  -110,   101,    79,   -37
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,    21,    22,   200,   149,    24,    25,    26,
     161,   180,    27,    28,    29,    68,    30,    31,    73,    32,
      83,   155,   187,    33,   176,   177,   201,    69
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      23,    50,    71,    72,    74,    74,   150,   178,    34,    87,
      99,   100,   101,   102,   101,   102,    88,    39,   194,    90,
      92,    91,    76,    77,    78,    93,     1,   195,    94,    13,
      96,    79,   179,   148,   109,    35,   109,     4,   110,   111,
     110,   111,     5,    40,     6,   112,     7,   112,   122,    53,
      54,     8,     9,    10,    11,   129,    36,    80,   185,    37,
      12,    38,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,    41,   144,   145,   146,    13,    42,    14,    15,
      56,    57,    16,   156,    43,   192,    17,    45,   203,    60,
      61,    62,    63,    64,    44,    18,    65,    66,    19,    20,
     174,   175,    46,     8,     9,    10,    11,    47,    67,    48,
     164,    49,    12,    51,   168,   169,   170,   171,     8,     9,
      10,    11,    58,    59,    85,    86,   182,    12,    13,    55,
      14,    15,    52,   165,    84,   188,    89,   190,    17,   125,
     126,   166,    95,    13,    50,    14,    15,    18,   184,   114,
      19,    20,   115,    17,     8,     9,    10,    11,   -44,   -44,
      97,    98,    18,    12,   109,    19,    20,   116,   110,   111,
     174,   175,   117,    60,    61,    70,    63,    64,    50,    13,
      65,    14,    15,   118,   213,     8,     9,    10,    11,    17,
      50,    39,    67,   119,    12,   121,   143,   120,    18,   131,
     147,    19,    20,   212,    60,    61,    62,    63,    64,   148,
      13,    65,    14,    15,   151,   152,   153,   154,   159,   172,
      17,   157,   160,    67,   163,   181,   167,   173,   197,    18,
     189,   124,    19,    20,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   127,   202,   204,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   191,   109,   198,
     206,   207,   110,   111,   209,   208,   211,   210,    81,   112,
      82,   109,   132,   186,    75,   110,   111,   193,   205,     0,
     128,     0,   112,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   158,     0,     0,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,     0,   109,     0,     0,
       0,   110,   111,     0,     0,     0,     0,     0,   112,     0,
     109,     0,     0,     0,   110,   111,     0,     0,     0,   183,
       0,   112,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,     0,   123,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,     0,     0,   109,     0,     0,     0,
     110,   111,     0,     0,     0,     0,     0,   112,   109,     0,
       0,     0,   110,   111,     0,     0,     0,     0,     0,   112,
     130,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,     0,   196,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,     0,     0,   109,     0,     0,     0,   110,
     111,     0,     0,     0,     0,     0,   112,   109,     0,     0,
       0,   110,   111,     0,     0,     0,     0,     0,   112,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,     0,
       0,     0,   113,   109,     0,     0,     0,   110,   111,     0,
       0,     0,   162,   109,   112,     0,     0,   110,   111,     0,
       0,     0,     0,     0,   112,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,     0,     0,     0,     0,   109,
       0,   199,     0,   110,   111,     0,     0,     0,     0,   109,
     112,     0,     0,   110,   111,     0,     0,     0,     0,     0,
     112,    99,   100,   101,   102,   103,   104,   105,   106,   107,
      99,   100,   101,   102,   103,   104,   105,   106,     0,     0,
      99,   100,   101,   102,     0,   109,   105,   106,     0,   110,
     111,     0,     0,     0,   109,     0,   112,     0,   110,   111,
       0,     0,     0,     0,   109,   112,     0,     0,   110,   111,
       0,     0,     0,     0,     0,   112
};

static const yytype_int16 yycheck[] =
{
       7,    23,    39,    40,    41,    42,   115,     9,    13,    46,
      18,    19,    20,    21,    20,    21,    53,    14,    34,    56,
      40,    58,     4,     5,     6,    45,    35,    43,    65,    29,
      67,    13,    34,    33,    42,    40,    42,     3,    46,    47,
      46,    47,     0,    40,    13,    53,    33,    53,    85,    14,
      15,     4,     5,     6,     7,    92,    13,    39,   167,    13,
      13,    16,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,    16,   110,   111,   112,    29,    16,    31,    32,
      14,    15,    35,   120,    16,    34,    39,    13,   197,     9,
      10,    11,    12,    13,    36,    48,    16,    17,    51,    52,
      49,    50,    16,     4,     5,     6,     7,    15,    28,    15,
     147,    34,    13,    15,   151,   152,   153,   154,     4,     5,
       6,     7,    14,    15,    14,    15,   163,    13,    29,    41,
      31,    32,    15,    34,    37,   172,    13,   174,    39,    14,
      15,   148,    15,    29,   166,    31,    32,    48,    34,    17,
      51,    52,    17,    39,     4,     5,     6,     7,    17,    18,
      17,    18,    48,    13,    42,    51,    52,    13,    46,    47,
      49,    50,    13,     9,    10,    11,    12,    13,   200,    29,
      16,    31,    32,    13,    34,     4,     5,     6,     7,    39,
     212,    14,    28,    13,    13,    38,    13,    15,    48,    15,
      14,    51,    52,   210,     9,    10,    11,    12,    13,    33,
      29,    16,    31,    32,    14,    14,    14,    14,    33,    15,
      39,    16,    33,    28,    16,    15,    30,    39,    17,    48,
      40,    15,    51,    52,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    15,     9,    13,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    44,    42,    41,
      51,    17,    46,    47,    15,    51,    15,    33,    43,    53,
      43,    42,    98,   167,    42,    46,    47,   176,   199,    -1,
      15,    -1,    53,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    15,    -1,    -1,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    -1,    42,    -1,    -1,
      -1,    46,    47,    -1,    -1,    -1,    -1,    -1,    53,    -1,
      42,    -1,    -1,    -1,    46,    47,    -1,    -1,    -1,    15,
      -1,    53,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    -1,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    -1,    -1,    42,    -1,    -1,    -1,
      46,    47,    -1,    -1,    -1,    -1,    -1,    53,    42,    -1,
      -1,    -1,    46,    47,    -1,    -1,    -1,    -1,    -1,    53,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    -1,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    -1,    -1,    42,    -1,    -1,    -1,    46,
      47,    -1,    -1,    -1,    -1,    -1,    53,    42,    -1,    -1,
      -1,    46,    47,    -1,    -1,    -1,    -1,    -1,    53,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    -1,
      -1,    -1,    41,    42,    -1,    -1,    -1,    46,    47,    -1,
      -1,    -1,    41,    42,    53,    -1,    -1,    46,    47,    -1,
      -1,    -1,    -1,    -1,    53,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    -1,    -1,    -1,    -1,    42,
      -1,    44,    -1,    46,    47,    -1,    -1,    -1,    -1,    42,
      53,    -1,    -1,    46,    47,    -1,    -1,    -1,    -1,    -1,
      53,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      18,    19,    20,    21,    22,    23,    24,    25,    -1,    -1,
      18,    19,    20,    21,    -1,    42,    24,    25,    -1,    46,
      47,    -1,    -1,    -1,    42,    -1,    53,    -1,    46,    47,
      -1,    -1,    -1,    -1,    42,    53,    -1,    -1,    46,    47,
      -1,    -1,    -1,    -1,    -1,    53
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    35,    58,    59,     3,     0,    13,    33,     4,     5,
       6,     7,    13,    29,    31,    32,    35,    39,    48,    51,
      52,    60,    61,    62,    64,    65,    66,    69,    70,    71,
      73,    74,    76,    80,    13,    40,    13,    13,    16,    14,
      40,    16,    16,    16,    36,    13,    16,    15,    15,    34,
      64,    15,    15,    14,    15,    41,    14,    15,    14,    15,
       9,    10,    11,    12,    13,    16,    17,    28,    72,    84,
      11,    84,    84,    75,    84,    75,     4,     5,     6,    13,
      39,    65,    70,    77,    37,    14,    15,    84,    84,    13,
      84,    84,    40,    45,    84,    15,    84,    17,    18,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    42,
      46,    47,    53,    41,    17,    17,    13,    13,    13,    13,
      15,    38,    84,    17,    15,    14,    15,    15,    15,    84,
      17,    15,    72,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    13,    84,    84,    84,    14,    33,    63,
      63,    14,    14,    14,    14,    78,    84,    16,    15,    33,
      33,    67,    41,    16,    84,    34,    62,    30,    84,    84,
      84,    84,    15,    39,    49,    50,    81,    82,     9,    34,
      68,    15,    84,    15,    34,    63,    73,    79,    84,    40,
      84,    44,    34,    82,    34,    43,    17,    17,    41,    44,
      62,    83,     9,    63,    13,    83,    51,    17,    51,    15,
      33,    15,    62,    34
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    57,    58,    59,    60,    60,    61,    62,    62,    63,
      63,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      65,    65,    65,    65,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    67,    67,    68,    68,    69,
      69,    70,    71,    71,    72,    72,    72,    73,    73,    73,
      74,    75,    76,    77,    77,    77,    78,    78,    79,    79,
      80,    81,    81,    82,    82,    82,    82,    83,    83,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     6,     1,     1,    13,     1,     2,     2,
       3,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       4,     4,     4,     4,     2,     3,     5,     3,     5,     3,
       5,     3,     5,     5,     7,     2,     3,     1,     3,     2,
       7,     3,     4,     5,     1,     1,     3,     5,     7,     7,
       5,     1,     9,     0,     1,     1,     0,     1,     0,     1,
       7,     1,     2,     6,     4,     5,     3,     0,     1,     1,
       1,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     6,     2,     4,     2,     3,
       3,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* programa: clase  */
#line 87 "parser.y"
          { 
        execute_program((yyvsp[0].node)); 
        //print_all_tokens(); 
        //free_token_list(); 
    }
#line 1382 "parser.tab.c"
    break;

  case 3: /* clase: PUBLIC CLASS ID LLLAVE cuerpo_clase RLLAVE  */
#line 96 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node); 
        printf("Clase %s definida\n", (yyvsp[-3].id));
        free((yyvsp[-3].id));
    }
#line 1392 "parser.tab.c"
    break;

  case 4: /* cuerpo_clase: metodo_main  */
#line 104 "parser.y"
                { (yyval.node) = (yyvsp[0].node); }
#line 1398 "parser.tab.c"
    break;

  case 5: /* cuerpo_clase: sentencias  */
#line 105 "parser.y"
                 { (yyval.node) = create_node_block((yyvsp[0].node)); }
#line 1404 "parser.tab.c"
    break;

  case 6: /* metodo_main: PUBLIC STATIC VOID MAIN LPAR STRING_KW LCORR RCORR ID RPAR LLLAVE sentencias RLLAVE  */
#line 110 "parser.y"
    {
        (yyval.node) = create_node_block((yyvsp[-1].node));
        printf("Método main encontrado - ejecutando...\n");
    }
#line 1413 "parser.tab.c"
    break;

  case 7: /* sentencias: sentencia  */
#line 117 "parser.y"
              { (yyval.node) = (yyvsp[0].node); }
#line 1419 "parser.tab.c"
    break;

  case 8: /* sentencias: sentencias sentencia  */
#line 119 "parser.y"
    {
        Node* current = (yyvsp[-1].node);
        while (current->next) current = current->next;
        current->next = (yyvsp[0].node);
        (yyval.node) = (yyvsp[-1].node);
    }
#line 1430 "parser.tab.c"
    break;

  case 9: /* bloque: LLLAVE RLLAVE  */
#line 128 "parser.y"
                  { (yyval.node) = create_node_block(NULL); }
#line 1436 "parser.tab.c"
    break;

  case 10: /* bloque: LLLAVE sentencias RLLAVE  */
#line 129 "parser.y"
                               { (yyval.node) = create_node_block((yyvsp[-1].node)); }
#line 1442 "parser.tab.c"
    break;

  case 11: /* sentencia: declaracion  */
#line 133 "parser.y"
                { (yyval.node) = (yyvsp[0].node); }
#line 1448 "parser.tab.c"
    break;

  case 12: /* sentencia: asignacion  */
#line 134 "parser.y"
                 { (yyval.node) = (yyvsp[0].node); }
#line 1454 "parser.tab.c"
    break;

  case 13: /* sentencia: println  */
#line 135 "parser.y"
              { (yyval.node) = (yyvsp[0].node); }
#line 1460 "parser.tab.c"
    break;

  case 14: /* sentencia: if_sentencia  */
#line 136 "parser.y"
                   { (yyval.node) = (yyvsp[0].node); }
#line 1466 "parser.tab.c"
    break;

  case 15: /* sentencia: while_sentencia  */
#line 137 "parser.y"
                      { (yyval.node) = (yyvsp[0].node); }
#line 1472 "parser.tab.c"
    break;

  case 16: /* sentencia: for_sentencia  */
#line 138 "parser.y"
                    { (yyval.node) = (yyvsp[0].node); }
#line 1478 "parser.tab.c"
    break;

  case 17: /* sentencia: switch_sentencia  */
#line 139 "parser.y"
                       { (yyval.node) = (yyvsp[0].node); }
#line 1484 "parser.tab.c"
    break;

  case 18: /* sentencia: BREAK PCOMA  */
#line 140 "parser.y"
                  { (yyval.node) = create_node_break(); }
#line 1490 "parser.tab.c"
    break;

  case 19: /* sentencia: CONTINUE PCOMA  */
#line 141 "parser.y"
                     { (yyval.node) = create_node_continue(); }
#line 1496 "parser.tab.c"
    break;

  case 20: /* declaracion_sin_pcoma: INT ID IGUAL expresion  */
#line 145 "parser.y"
                           { 
        add_symbol_to_table((yyvsp[-2].id), "Variable", "int", "Local", yylineno, yycolno);
        (yyval.node) = create_node_decl((yyvsp[-2].id), INT_T); 
        free((yyvsp[-2].id));
    }
#line 1506 "parser.tab.c"
    break;

  case 21: /* declaracion_sin_pcoma: DOUBLE ID IGUAL expresion  */
#line 150 "parser.y"
                                { 
        add_symbol_to_table((yyvsp[-2].id), "Variable", "double", "Local", yylineno, yycolno);
        Node* decl = create_node_decl((yyvsp[-2].id), DOUBLE_T);
        Node* assign = create_node_assign((yyvsp[-2].id), (yyvsp[0].node));
        decl->next = assign;
        (yyval.node) = decl;
        free((yyvsp[-2].id));
    }
#line 1519 "parser.tab.c"
    break;

  case 22: /* declaracion_sin_pcoma: STRING_KW ID IGUAL expresion  */
#line 158 "parser.y"
                                   { 
        add_symbol_to_table((yyvsp[-2].id), "Variable", "String", "Local", yylineno, yycolno);
        Node* decl = create_node_decl((yyvsp[-2].id), STRING_T);
        Node* assign = create_node_assign((yyvsp[-2].id), (yyvsp[0].node));
        decl->next = assign;
        (yyval.node) = decl;
        free((yyvsp[-2].id));
    }
#line 1532 "parser.tab.c"
    break;

  case 23: /* declaracion_sin_pcoma: BOOLEAN ID IGUAL expresion  */
#line 166 "parser.y"
                                 { 
        add_symbol_to_table((yyvsp[-2].id), "Variable", "boolean", "Local", yylineno, yycolno);
        Node* decl = create_node_decl((yyvsp[-2].id), BOOL_T);
        Node* assign = create_node_assign((yyvsp[-2].id), (yyvsp[0].node));
        decl->next = assign;
        (yyval.node) = decl;
        free((yyvsp[-2].id));
    }
#line 1545 "parser.tab.c"
    break;

  case 24: /* declaracion: declaracion_sin_pcoma PCOMA  */
#line 177 "parser.y"
                            { (yyval.node) = (yyvsp[-1].node); }
#line 1551 "parser.tab.c"
    break;

  case 25: /* declaracion: INT ID PCOMA  */
#line 178 "parser.y"
                  { 
        add_symbol_to_table((yyvsp[-1].id), "Variable", "int", "Global", yylineno, yycolno);
        (yyval.node) = create_node_decl((yyvsp[-1].id), INT_T); 
        free((yyvsp[-1].id));
    }
#line 1561 "parser.tab.c"
    break;

  case 26: /* declaracion: INT ID IGUAL expresion PCOMA  */
#line 183 "parser.y"
                                   { 
        add_symbol_to_table((yyvsp[-3].id), "Variable", "int", "Global", yylineno, yycolno);
        Node* decl = create_node_decl((yyvsp[-3].id), INT_T);
        Node* assign = create_node_assign((yyvsp[-3].id), (yyvsp[-1].node));
        decl->next = assign;
        (yyval.node) = decl;
        free((yyvsp[-3].id));
    }
#line 1574 "parser.tab.c"
    break;

  case 27: /* declaracion: DOUBLE ID PCOMA  */
#line 191 "parser.y"
                      { 
        add_symbol_to_table((yyvsp[-1].id), "Variable", "double", "Global", yylineno, yycolno);
        (yyval.node) = create_node_decl((yyvsp[-1].id), DOUBLE_T); 
        free((yyvsp[-1].id));
    }
#line 1584 "parser.tab.c"
    break;

  case 28: /* declaracion: DOUBLE ID IGUAL expresion PCOMA  */
#line 196 "parser.y"
                                      { 
        add_symbol_to_table((yyvsp[-3].id), "Variable", "double", "Global", yylineno, yycolno);
        Node* decl = create_node_decl((yyvsp[-3].id), DOUBLE_T);
        Node* assign = create_node_assign((yyvsp[-3].id), (yyvsp[-1].node));
        decl->next = assign;
        (yyval.node) = decl;
        free((yyvsp[-3].id));
    }
#line 1597 "parser.tab.c"
    break;

  case 29: /* declaracion: STRING_KW ID PCOMA  */
#line 204 "parser.y"
                         { 
        add_symbol_to_table((yyvsp[-1].id), "Variable", "String", "Global", yylineno, yycolno);
        (yyval.node) = create_node_decl((yyvsp[-1].id), STRING_T); 
        free((yyvsp[-1].id));
    }
#line 1607 "parser.tab.c"
    break;

  case 30: /* declaracion: STRING_KW ID IGUAL expresion PCOMA  */
#line 209 "parser.y"
                                         { 
        add_symbol_to_table((yyvsp[-3].id), "Variable", "String", "Global", yylineno, yycolno);
        Node* decl = create_node_decl((yyvsp[-3].id), STRING_T);
        Node* assign = create_node_assign((yyvsp[-3].id), (yyvsp[-1].node));
        decl->next = assign;
        (yyval.node) = decl;
        free((yyvsp[-3].id));
    }
#line 1620 "parser.tab.c"
    break;

  case 31: /* declaracion: BOOLEAN ID PCOMA  */
#line 217 "parser.y"
                       { 
        add_symbol_to_table((yyvsp[-1].id), "Variable", "boolean", "Global", yylineno, yycolno);
        (yyval.node) = create_node_decl((yyvsp[-1].id), BOOL_T); 
        free((yyvsp[-1].id));
    }
#line 1630 "parser.tab.c"
    break;

  case 32: /* declaracion: BOOLEAN ID IGUAL expresion PCOMA  */
#line 222 "parser.y"
                                       { 
        add_symbol_to_table((yyvsp[-3].id), "Variable", "boolean", "Global", yylineno, yycolno);
        Node* decl = create_node_decl((yyvsp[-3].id), BOOL_T);
        Node* assign = create_node_assign((yyvsp[-3].id), (yyvsp[-1].node));
        decl->next = assign;
        (yyval.node) = decl;
        free((yyvsp[-3].id));
    }
#line 1643 "parser.tab.c"
    break;

  case 33: /* declaracion: INT LCORR RCORR ID PCOMA  */
#line 231 "parser.y"
    {
        add_symbol_to_table((yyvsp[-1].id), "Array", "int[]", "Global", yylineno, yycolno);
        (yyval.node) = create_node_array_decl((yyvsp[-1].id));
        free((yyvsp[-1].id));
    }
#line 1653 "parser.tab.c"
    break;

  case 34: /* declaracion: INT LCORR RCORR ID IGUAL array_literal PCOMA  */
#line 237 "parser.y"
    {
        add_symbol_to_table((yyvsp[-3].id), "Array", "int[]", "Global", yylineno, yycolno);
        Node* decl = create_node_array_decl((yyvsp[-3].id));
        Node* assign = create_node_assign((yyvsp[-3].id), (yyvsp[-1].node));
        decl->next = assign;
        (yyval.node) = decl;
        free((yyvsp[-3].id));
    }
#line 1666 "parser.tab.c"
    break;

  case 35: /* array_literal: LLLAVE RLLAVE  */
#line 249 "parser.y"
    {
        (yyval.node) = create_node_array_literal(NULL, 0);
    }
#line 1674 "parser.tab.c"
    break;

  case 36: /* array_literal: LLLAVE lista_enteros RLLAVE  */
#line 253 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 1682 "parser.tab.c"
    break;

  case 37: /* lista_enteros: INT_LITERAL  */
#line 260 "parser.y"
    {
        int* vals = malloc(sizeof(int));
        vals[0] = (yyvsp[0].ival);
        (yyval.node) = create_node_array_literal(vals, 1);
        free(vals);
    }
#line 1693 "parser.tab.c"
    break;

  case 38: /* lista_enteros: lista_enteros COMA INT_LITERAL  */
#line 267 "parser.y"
    {
        Node* prev = (yyvsp[-2].node);
        if (prev && prev->type == NODE_ARRAY_LITERAL) {
            IntArray* old_arr = prev->value.arr;
            int new_size = old_arr->size + 1;
            int* new_data = malloc(sizeof(int) * new_size);
            if (old_arr->size > 0) {
                memcpy(new_data, old_arr->data, sizeof(int) * old_arr->size);
            }
            new_data[old_arr->size] = (yyvsp[0].ival);

            if (old_arr->data) free(old_arr->data);
            free(old_arr);

            (yyval.node) = create_node_array_literal(new_data, new_size);
            free(new_data);
        } else {
            fprintf(stderr, "Error: lista_enteros mal formada\n");
            (yyval.node) = create_node_int(0);
        }
    }
#line 1719 "parser.tab.c"
    break;

  case 39: /* asignacion: asignacion_sin_pcoma PCOMA  */
#line 291 "parser.y"
                               { (yyval.node) = (yyvsp[-1].node); }
#line 1725 "parser.tab.c"
    break;

  case 40: /* asignacion: ID LCORR expresion RCORR IGUAL expresion PCOMA  */
#line 293 "parser.y"
    {
        (yyval.node) = create_node_array_assign((yyvsp[-6].id), (yyvsp[-4].node), (yyvsp[-1].node));
        free((yyvsp[-6].id));
    }
#line 1734 "parser.tab.c"
    break;

  case 41: /* asignacion_sin_pcoma: ID IGUAL expresion  */
#line 300 "parser.y"
                       { (yyval.node) = create_node_assign((yyvsp[-2].id), (yyvsp[0].node)); free((yyvsp[-2].id)); }
#line 1740 "parser.tab.c"
    break;

  case 42: /* println: PRINTLN LPAR RPAR PCOMA  */
#line 304 "parser.y"
                            { 
        // Crear un nodo println con string vacío
        Node* empty_str = malloc(sizeof(Node));
        empty_str->type = NODE_STRING;
        empty_str->value.str = strdup("");
        empty_str->next = NULL;
        (yyval.node) = create_node_println(empty_str);
    }
#line 1753 "parser.tab.c"
    break;

  case 43: /* println: PRINTLN LPAR print RPAR PCOMA  */
#line 312 "parser.y"
                                   { (yyval.node) = create_node_println((yyvsp[-2].node)); }
#line 1759 "parser.tab.c"
    break;

  case 44: /* print: STRING_LITERAL  */
#line 317 "parser.y"
    { 
        Node* n = malloc(sizeof(Node));
        n->type = NODE_STRING;
        n->value.str = strdup((yyvsp[0].str));
        n->next = NULL;
        (yyval.node) = n;
        free((yyvsp[0].str));
    }
#line 1772 "parser.tab.c"
    break;

  case 45: /* print: expresion  */
#line 325 "parser.y"
                { (yyval.node) = (yyvsp[0].node); }
#line 1778 "parser.tab.c"
    break;

  case 46: /* print: print MAS print  */
#line 327 "parser.y"
    {
        Node* n = malloc(sizeof(Node));
        n->type = NODE_BINOP;
        n->op = MAS;  
        n->left = (yyvsp[-2].node);
        n->right = (yyvsp[0].node);
        n->next = NULL;
        (yyval.node) = n;
    }
#line 1792 "parser.tab.c"
    break;

  case 47: /* if_sentencia: IF LPAR condicion RPAR bloque  */
#line 340 "parser.y"
    {
        (yyval.node) = create_node_if((yyvsp[-2].node), (yyvsp[0].node), NULL);
    }
#line 1800 "parser.tab.c"
    break;

  case 48: /* if_sentencia: IF LPAR condicion RPAR bloque ELSE if_sentencia  */
#line 344 "parser.y"
    {
        (yyval.node) = create_node_if((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1808 "parser.tab.c"
    break;

  case 49: /* if_sentencia: IF LPAR condicion RPAR bloque ELSE bloque  */
#line 348 "parser.y"
    {
        (yyval.node) = create_node_if((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1816 "parser.tab.c"
    break;

  case 50: /* while_sentencia: WHILE LPAR condicion RPAR bloque  */
#line 355 "parser.y"
    {
        (yyval.node) = create_node_while((yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1824 "parser.tab.c"
    break;

  case 51: /* condicion: expresion  */
#line 361 "parser.y"
              { (yyval.node) = (yyvsp[0].node); }
#line 1830 "parser.tab.c"
    break;

  case 52: /* for_sentencia: FOR LPAR asignacion_opt PCOMA condicion_opt PCOMA expresion_opt RPAR bloque  */
#line 366 "parser.y"
    {
        (yyval.node) = create_node_for((yyvsp[-6].node), (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1838 "parser.tab.c"
    break;

  case 53: /* asignacion_opt: %empty  */
#line 372 "parser.y"
                 { (yyval.node) = NULL; }
#line 1844 "parser.tab.c"
    break;

  case 54: /* asignacion_opt: asignacion_sin_pcoma  */
#line 373 "parser.y"
                           { (yyval.node) = (yyvsp[0].node); }
#line 1850 "parser.tab.c"
    break;

  case 55: /* asignacion_opt: declaracion_sin_pcoma  */
#line 374 "parser.y"
                             { (yyval.node) = (yyvsp[0].node); }
#line 1856 "parser.tab.c"
    break;

  case 56: /* condicion_opt: %empty  */
#line 378 "parser.y"
                 { (yyval.node) = NULL; }
#line 1862 "parser.tab.c"
    break;

  case 57: /* condicion_opt: expresion  */
#line 379 "parser.y"
                { (yyval.node) = (yyvsp[0].node); }
#line 1868 "parser.tab.c"
    break;

  case 58: /* expresion_opt: %empty  */
#line 383 "parser.y"
                 { (yyval.node) = NULL; }
#line 1874 "parser.tab.c"
    break;

  case 59: /* expresion_opt: expresion  */
#line 384 "parser.y"
                { (yyval.node) = (yyvsp[0].node); }
#line 1880 "parser.tab.c"
    break;

  case 60: /* switch_sentencia: SWITCH LPAR expresion RPAR LLLAVE case_lista RLLAVE  */
#line 390 "parser.y"
    {
        (yyval.node) = create_node_switch((yyvsp[-4].node), (yyvsp[-1].node));
    }
#line 1888 "parser.tab.c"
    break;

  case 61: /* case_lista: case_item  */
#line 396 "parser.y"
              { 
        (yyval.node) = (yyvsp[0].node); 
        (yyvsp[0].node)->next = NULL;
    }
#line 1897 "parser.tab.c"
    break;

  case 62: /* case_lista: case_lista case_item  */
#line 400 "parser.y"
                           { 
        Node* current = (yyvsp[-1].node);
        while (current->next) {
            current = current->next;
        }
        current->next = (yyvsp[0].node);
        (yyval.node) = (yyvsp[-1].node);
    }
#line 1910 "parser.tab.c"
    break;

  case 63: /* case_item: CASE expresion DOSPUNTOS sentencias_opt BREAK PCOMA  */
#line 413 "parser.y"
    {
        (yyval.node) = create_node_case((yyvsp[-4].node), (yyvsp[-2].node), 1); // 1 = tiene break
    }
#line 1918 "parser.tab.c"
    break;

  case 64: /* case_item: CASE expresion DOSPUNTOS sentencias_opt  */
#line 417 "parser.y"
    {
        (yyval.node) = create_node_case((yyvsp[-2].node), (yyvsp[0].node), 0); // 0 = no tiene break
    }
#line 1926 "parser.tab.c"
    break;

  case 65: /* case_item: DEFAULT DOSPUNTOS sentencias_opt BREAK PCOMA  */
#line 421 "parser.y"
    {
        (yyval.node) = create_node_default((yyvsp[-2].node), 1);
    }
#line 1934 "parser.tab.c"
    break;

  case 66: /* case_item: DEFAULT DOSPUNTOS sentencias_opt  */
#line 425 "parser.y"
    {
        (yyval.node) = create_node_default((yyvsp[0].node), 0);
    }
#line 1942 "parser.tab.c"
    break;

  case 67: /* sentencias_opt: %empty  */
#line 431 "parser.y"
                 { (yyval.node) = create_node_block(NULL); }
#line 1948 "parser.tab.c"
    break;

  case 68: /* sentencias_opt: sentencias  */
#line 432 "parser.y"
                 { (yyval.node) = (yyvsp[0].node); }
#line 1954 "parser.tab.c"
    break;

  case 69: /* expresion: INT_LITERAL  */
#line 437 "parser.y"
                { (yyval.node) = create_node_int((yyvsp[0].ival)); }
#line 1960 "parser.tab.c"
    break;

  case 70: /* expresion: FLOAT_LITERAL  */
#line 438 "parser.y"
                    { (yyval.node) = create_node_double((yyvsp[0].fval)); }
#line 1966 "parser.tab.c"
    break;

  case 71: /* expresion: STRING_LITERAL  */
#line 440 "parser.y"
    { 
        Node* n = malloc(sizeof(Node));
        n->type = NODE_STRING;
        n->value.str = strdup((yyvsp[0].str));
        n->next = NULL;
        (yyval.node) = n;
        free((yyvsp[0].str));
    }
#line 1979 "parser.tab.c"
    break;

  case 72: /* expresion: BOOL_LITERAL  */
#line 449 "parser.y"
    {
        Node* n = malloc(sizeof(Node));
        n->type = NODE_BOOL;
        n->value.bval = (yyvsp[0].boolean);
        n->next = NULL;
        (yyval.node) = n;
    }
#line 1991 "parser.tab.c"
    break;

  case 73: /* expresion: ID  */
#line 456 "parser.y"
         { (yyval.node) = create_node_id((yyvsp[0].id)); free((yyvsp[0].id)); }
#line 1997 "parser.tab.c"
    break;

  case 74: /* expresion: expresion MAS expresion  */
#line 457 "parser.y"
                              { (yyval.node) = create_node_binop(MAS, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2003 "parser.tab.c"
    break;

  case 75: /* expresion: expresion MENOS expresion  */
#line 458 "parser.y"
                                { (yyval.node) = create_node_binop(MENOS, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2009 "parser.tab.c"
    break;

  case 76: /* expresion: expresion MULTI expresion  */
#line 459 "parser.y"
                                { (yyval.node) = create_node_binop(MULTI, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2015 "parser.tab.c"
    break;

  case 77: /* expresion: expresion DIVS expresion  */
#line 460 "parser.y"
                               { (yyval.node) = create_node_binop(DIVS, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2021 "parser.tab.c"
    break;

  case 78: /* expresion: expresion MAYOR expresion  */
#line 461 "parser.y"
                                { (yyval.node) = create_node_binop(MAYOR, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2027 "parser.tab.c"
    break;

  case 79: /* expresion: expresion MENOR expresion  */
#line 462 "parser.y"
                                { (yyval.node) = create_node_binop(MENOR, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2033 "parser.tab.c"
    break;

  case 80: /* expresion: expresion DIGUAL expresion  */
#line 463 "parser.y"
                                 { (yyval.node) = create_node_binop(DIGUAL, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2039 "parser.tab.c"
    break;

  case 81: /* expresion: expresion NIGUAL expresion  */
#line 464 "parser.y"
                                 { (yyval.node) = create_node_binop(NIGUAL, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2045 "parser.tab.c"
    break;

  case 82: /* expresion: expresion AND expresion  */
#line 465 "parser.y"
                              { (yyval.node) = create_node_binop(AND, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2051 "parser.tab.c"
    break;

  case 83: /* expresion: expresion OR expresion  */
#line 466 "parser.y"
                             { (yyval.node) = create_node_binop(OR, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2057 "parser.tab.c"
    break;

  case 84: /* expresion: LPAR expresion RPAR  */
#line 467 "parser.y"
                          { (yyval.node) = (yyvsp[-1].node); }
#line 2063 "parser.tab.c"
    break;

  case 85: /* expresion: expresion PUNTO ID LPAR expresion RPAR  */
#line 469 "parser.y"
    {
        if (strcmp((yyvsp[-3].id),"equals")==0){
            (yyval.node) = create_node_binop(DIGUAL,(yyvsp[-5].node),(yyvsp[-1].node));
        } else {
            fprintf(stderr,"Metodo no soportado: %s\n",(yyvsp[-3].id));
            (yyval.node) = create_node_int(0);
        }
        free((yyvsp[-3].id));
    }
#line 2077 "parser.tab.c"
    break;

  case 86: /* expresion: NOT expresion  */
#line 478 "parser.y"
                                 { (yyval.node) = create_node_unary(NOT, (yyvsp[0].node)); }
#line 2083 "parser.tab.c"
    break;

  case 87: /* expresion: ID LCORR expresion RCORR  */
#line 480 "parser.y"
    {
        (yyval.node) = create_node_array_access((yyvsp[-3].id), (yyvsp[-1].node));
        free((yyvsp[-3].id));
    }
#line 2092 "parser.tab.c"
    break;

  case 88: /* expresion: ID INCREMENTO  */
#line 486 "parser.y"
    {
        Node* id_node = create_node_id((yyvsp[-1].id));
        Node* one_node = create_node_int(1);
        Node* add_node = create_node_binop(MAS, id_node, one_node);
        (yyval.node) = create_node_assign((yyvsp[-1].id), add_node);
        free((yyvsp[-1].id));
    }
#line 2104 "parser.tab.c"
    break;

  case 89: /* expresion: expresion MENOR_IGUAL expresion  */
#line 493 "parser.y"
                                      { (yyval.node) = create_node_binop(MENOR_IGUAL, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2110 "parser.tab.c"
    break;

  case 90: /* expresion: expresion MAYOR_IGUAL expresion  */
#line 494 "parser.y"
                                      { (yyval.node) = create_node_binop(MAYOR_IGUAL, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2116 "parser.tab.c"
    break;

  case 91: /* expresion: expresion MOD expresion  */
#line 495 "parser.y"
                              { (yyval.node) = create_node_binop(MOD, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2122 "parser.tab.c"
    break;


#line 2126 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 499 "parser.y"


void yyerror(const char *s) {
    extern int yychar;
    extern char* yytext;
    fprintf(stderr, "Error en línea %d, columna %d: %s\n", yylineno, yycolno, s);
    fprintf(stderr, "Token actual: %d, texto: '%s'\n", yychar, yytext ? yytext : "NULL");
}
