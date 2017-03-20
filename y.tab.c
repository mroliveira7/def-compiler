/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "parser.h"

#define YYDEBUG 1


extern FILE *yyin;
extern FILE *yyout;

int yylex(void);
tipoTree * cria_node(char nonT[20], int n_filhos, ...);
tipoTree * terminalNumber(int token_n);
tipoTree * terminalToken(char id[20], int token_n);
char * consultaToken(int token_n);
void yyerror(char *string);
int printTree(tipoTree *p, int depth);
int printFuncall(tipoTree *p, int depth);


int insereVar(listaVar **p, char *id, int value);
listaVar * consultaVar(listaVar *p, char *id);
int consultaFuncs(listaFuncs *p, char *id);
int insereFunc(listaFuncs **p, char *id);
int assignValues(tipoTree *p);


tipoTree *treeRoot = NULL;
listaVar *vars = NULL;
listaFuncs *funcs = NULL;
int G_NUM = 1;
int G_ACC = 0;


#line 104 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    AND = 258,
    NOT = 259,
    OR = 260,
    WHILE = 261,
    ELSE = 262,
    IF = 263,
    RETURN = 264,
    VOID = 265,
    DEF = 266,
    BREAK = 267,
    CONTINUE = 268,
    INT = 269,
    PLUS = 270,
    TIMES = 271,
    MINUS = 272,
    DIV = 273,
    COMMA = 274,
    SEMICOL = 275,
    ASSIGN = 276,
    EQ = 277,
    NEQ = 278,
    LTEQ = 279,
    GTEQ = 280,
    LT = 281,
    GT = 282,
    CLOSEPAR = 283,
    OPENPAR = 284,
    OPENCOLC = 285,
    CLOSECOLC = 286,
    OPENCH = 287,
    CLOSECH = 288,
    U_MINUS = 289,
    NAME = 290,
    NUMBER = 291
  };
#endif
/* Tokens.  */
#define AND 258
#define NOT 259
#define OR 260
#define WHILE 261
#define ELSE 262
#define IF 263
#define RETURN 264
#define VOID 265
#define DEF 266
#define BREAK 267
#define CONTINUE 268
#define INT 269
#define PLUS 270
#define TIMES 271
#define MINUS 272
#define DIV 273
#define COMMA 274
#define SEMICOL 275
#define ASSIGN 276
#define EQ 277
#define NEQ 278
#define LTEQ 279
#define GTEQ 280
#define LT 281
#define GT 282
#define CLOSEPAR 283
#define OPENPAR 284
#define OPENCOLC 285
#define CLOSECOLC 286
#define OPENCH 287
#define CLOSECH 288
#define U_MINUS 289
#define NAME 290
#define NUMBER 291

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 39 "parser.y" /* yacc.c:355  */

	tipoTree *treePointer;
	int integer;
	char id[20];

#line 222 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 239 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   209

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  55
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  107

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   291

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
      35,    36
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    73,    73,    74,    81,    82,    85,    88,    89,    92,
      95,    96,    99,   100,   103,   106,   107,   110,   111,   114,
     115,   116,   117,   118,   119,   120,   123,   124,   127,   128,
     131,   134,   135,   138,   141,   142,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   165,   166
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "AND", "NOT", "OR", "WHILE", "ELSE",
  "IF", "RETURN", "VOID", "DEF", "BREAK", "CONTINUE", "INT", "PLUS",
  "TIMES", "MINUS", "DIV", "COMMA", "SEMICOL", "ASSIGN", "EQ", "NEQ",
  "LTEQ", "GTEQ", "LT", "GT", "CLOSEPAR", "OPENPAR", "OPENCOLC",
  "CLOSECOLC", "OPENCH", "CLOSECH", "U_MINUS", "NAME", "NUMBER", "$accept",
  "s", "program", "decVar", "compVar", "decFunc", "paramList",
  "rcsParamList", "block", "multVar", "multStmt", "stmt", "compElse",
  "compExpr", "funCall", "compArglist", "arglist", "multExpr", "expr",
  "type", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291
};
# endif

#define YYPACT_NINF -93

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-93)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      41,   -93,    52,   -93,    28,    41,   -93,   -93,    -1,    18,
     -93,   -93,    29,    27,    25,    43,    52,    25,    25,    25,
      35,   -93,   -93,   153,   -93,    37,    39,   -93,   -93,    54,
      25,    25,    25,    25,    25,    25,    25,    25,    25,    25,
      25,    25,    25,    60,    56,   -93,    58,   -93,   112,    21,
     169,    15,   -93,    15,   -93,   182,   182,    73,    73,    73,
      73,    52,   -93,    52,   -93,   -93,    25,   -93,    52,    -3,
      49,   112,   -93,    64,    65,    25,    89,    90,     6,    67,
      -3,   105,    56,   -93,    25,    25,   106,   153,   -93,   -93,
      25,   -93,   -93,   -93,   -93,    80,    96,   -93,   137,    60,
      60,   -93,   -93,   109,    60,   -93,   -93
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,    55,     0,    54,     0,     2,     4,     5,     0,     0,
       1,     3,     7,     0,     0,     0,    10,     0,     0,     0,
      37,    36,    39,     8,     6,     0,     0,    52,    53,     0,
      31,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    12,    38,     0,    32,    34,    45,
      44,    40,    43,    41,    42,    51,    50,    47,    49,    46,
      48,    15,     9,     0,    11,    30,     0,    33,    15,    17,
       0,    34,    16,     0,     0,    28,     0,     0,     0,     0,
      17,     0,    12,    35,     0,     0,     0,    29,    24,    25,
       0,    14,    18,    20,    13,     0,     0,    23,     0,     0,
       0,    19,    22,    26,     0,    21,    27
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -93,   127,   -93,   -57,   -93,   -93,   -93,    51,   -92,    75,
      61,   -93,   -93,   -93,   -39,   -93,   -93,    74,   -17,    24
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,    15,     7,    25,    64,    62,    69,
      79,    80,   105,    86,    22,    46,    47,    67,    23,     8
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      27,    28,    29,    73,    68,    74,    75,   102,   103,    76,
      77,    68,   106,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,     9,    90,    10,    17,
      81,    34,    78,    36,    12,    30,    33,    34,    35,    36,
      26,    81,    18,    37,    38,    39,    40,    41,    42,    71,
      14,     1,     2,    13,    19,     3,    16,    31,    87,    32,
      20,    21,     1,    24,    30,    43,     3,    95,    96,    33,
      34,    35,    36,    98,    44,    63,    37,    38,    39,    40,
      41,    42,    45,    31,    82,    32,    65,    70,    33,    34,
      35,    36,    61,    84,    85,    33,    34,    35,    36,    31,
      91,    32,    37,    38,    39,    40,    41,    42,    99,    88,
      89,    33,    34,    35,    36,    31,   104,    32,    37,    38,
      39,    40,    41,    42,   100,    93,    97,    33,    34,    35,
      36,    66,    11,    94,    37,    38,    39,    40,    41,    42,
      31,    92,    32,    72,     0,    83,     0,     0,     0,     0,
       0,     0,    33,    34,    35,    36,    31,   101,    32,    37,
      38,    39,    40,    41,    42,     0,     0,     0,    33,    34,
      35,    36,    31,     0,     0,    37,    38,    39,    40,    41,
      42,     0,     0,     0,    33,    34,    35,    36,     0,     0,
       0,    37,    38,    39,    40,    41,    42,    33,    34,    35,
      36,     0,     0,     0,     0,     0,    39,    40,    41,    42
};

static const yytype_int8 yycheck[] =
{
      17,    18,    19,     6,    61,     8,     9,    99,   100,    12,
      13,    68,   104,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,     2,    21,     0,     4,
      69,    16,    35,    18,    35,    29,    15,    16,    17,    18,
      16,    80,    17,    22,    23,    24,    25,    26,    27,    66,
      21,    10,    11,    35,    29,    14,    29,     3,    75,     5,
      35,    36,    10,    20,    29,    28,    14,    84,    85,    15,
      16,    17,    18,    90,    35,    19,    22,    23,    24,    25,
      26,    27,    28,     3,    35,     5,    28,    63,    15,    16,
      17,    18,    32,    29,    29,    15,    16,    17,    18,     3,
      33,     5,    22,    23,    24,    25,    26,    27,    28,    20,
      20,    15,    16,    17,    18,     3,     7,     5,    22,    23,
      24,    25,    26,    27,    28,    20,    20,    15,    16,    17,
      18,    19,     5,    82,    22,    23,    24,    25,    26,    27,
       3,    80,     5,    68,    -1,    71,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    16,    17,    18,     3,    20,     5,    22,
      23,    24,    25,    26,    27,    -1,    -1,    -1,    15,    16,
      17,    18,     3,    -1,    -1,    22,    23,    24,    25,    26,
      27,    -1,    -1,    -1,    15,    16,    17,    18,    -1,    -1,
      -1,    22,    23,    24,    25,    26,    27,    15,    16,    17,
      18,    -1,    -1,    -1,    -1,    -1,    24,    25,    26,    27
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    10,    11,    14,    38,    39,    40,    42,    56,    56,
       0,    38,    35,    35,    21,    41,    29,     4,    17,    29,
      35,    36,    51,    55,    20,    43,    56,    55,    55,    55,
      29,     3,     5,    15,    16,    17,    18,    22,    23,    24,
      25,    26,    27,    28,    35,    28,    52,    53,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    32,    45,    19,    44,    28,    19,    54,    40,    46,
      56,    55,    46,     6,     8,     9,    12,    13,    35,    47,
      48,    51,    35,    54,    29,    29,    50,    55,    20,    20,
      21,    33,    47,    20,    44,    55,    55,    20,    55,    28,
      28,    20,    45,    45,     7,    49,    45
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    37,    38,    38,    39,    39,    40,    41,    41,    42,
      43,    43,    44,    44,    45,    46,    46,    47,    47,    48,
      48,    48,    48,    48,    48,    48,    49,    49,    50,    50,
      51,    52,    52,    53,    54,    54,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    56,    56
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     4,     0,     2,     7,
       0,     3,     0,     4,     4,     0,     2,     0,     2,     4,
       2,     6,     5,     3,     2,     2,     0,     2,     0,     1,
       4,     0,     1,     2,     0,     3,     1,     1,     3,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 73 "parser.y" /* yacc.c:1646  */
    {(yyval.treePointer) = NULL;}
#line 1405 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 74 "parser.y" /* yacc.c:1646  */
    {
			if ((yyvsp[-1].treePointer) != NULL){
				(yyval.treePointer) = cria_node("program", 2, (yyvsp[-1].treePointer), (yyvsp[0].treePointer));
				treeRoot = (yyval.treePointer);
			}
		}
#line 1416 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 81 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = (yyvsp[0].treePointer); }
#line 1422 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 82 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = (yyvsp[0].treePointer); }
#line 1428 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 85 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = cria_node("decVar", 4, (yyvsp[-3].treePointer), terminalToken((yyvsp[-2].id), NAME), (yyvsp[-1].treePointer), terminalToken(";", SEMICOL)); }
#line 1434 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 88 "parser.y" /* yacc.c:1646  */
    {(yyval.treePointer) = NULL;}
#line 1440 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 89 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = cria_node("compVar", 2, terminalToken("=", ASSIGN), (yyvsp[0].treePointer)); }
#line 1446 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 92 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = cria_node("decFunc" , 7, terminalToken("def", DEF), (yyvsp[-5].treePointer), terminalToken((yyvsp[-4].id), NAME), terminalToken("(", OPENPAR), (yyvsp[-2].treePointer), terminalToken(")", CLOSEPAR), (yyvsp[0].treePointer)); }
#line 1452 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 95 "parser.y" /* yacc.c:1646  */
    {(yyval.treePointer) = NULL;}
#line 1458 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 96 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = cria_node("paramList", 3, (yyvsp[-2].treePointer), terminalToken((yyvsp[-1].id), NAME), (yyvsp[0].treePointer)); }
#line 1464 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 99 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = NULL; }
#line 1470 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 100 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = cria_node("paramList", 4, terminalToken(",", COMMA), (yyvsp[-2].treePointer), terminalToken((yyvsp[-1].id), NAME), (yyvsp[0].treePointer)); }
#line 1476 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 103 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = cria_node("block", 4, terminalToken("{", OPENCH), (yyvsp[-2].treePointer), (yyvsp[-1].treePointer), terminalToken("}", CLOSECH)); }
#line 1482 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 106 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = NULL; }
#line 1488 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 107 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = cria_node("multVar", 2, (yyvsp[-1].treePointer), (yyvsp[0].treePointer)); }
#line 1494 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 110 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = NULL; }
#line 1500 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 111 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = cria_node("multStmt", 2, (yyvsp[-1].treePointer), (yyvsp[0].treePointer)); }
#line 1506 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 114 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = cria_node("stmt", 4, terminalToken((yyvsp[-3].id), NAME), terminalToken("=", ASSIGN), (yyvsp[-1].treePointer), terminalToken(";", SEMICOL)); }
#line 1512 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 115 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = cria_node("stmt", 2, (yyvsp[-1].treePointer), terminalToken(";", SEMICOL)); }
#line 1518 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 116 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = cria_node("stmt", 6, terminalToken("if", IF), terminalToken("(", OPENPAR), (yyvsp[-3].treePointer), terminalToken(")", CLOSEPAR), (yyvsp[-1].treePointer), (yyvsp[0].treePointer)); }
#line 1524 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 117 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = cria_node("stmt", 5, terminalToken("while", WHILE), terminalToken("(", OPENPAR), (yyvsp[-2].treePointer), terminalToken(")", CLOSEPAR), (yyvsp[0].treePointer)); }
#line 1530 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 118 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = cria_node("stmt", 3, terminalToken("return", RETURN), (yyvsp[-1].treePointer), terminalToken(";", SEMICOL)); }
#line 1536 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 119 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = cria_node("stmt", 2, terminalToken("break", BREAK), terminalToken(";", SEMICOL)); }
#line 1542 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 120 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = cria_node("stmt", 2, terminalToken("continue", CONTINUE), terminalToken(";", SEMICOL)); }
#line 1548 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 123 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = NULL; }
#line 1554 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 124 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = cria_node("compelse", 2, terminalToken("else", ELSE), (yyvsp[0].treePointer)); }
#line 1560 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 127 "parser.y" /* yacc.c:1646  */
    {(yyval.treePointer) = NULL; }
#line 1566 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 128 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = (yyvsp[0].treePointer); }
#line 1572 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 131 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = cria_node("funcall", 4, terminalToken((yyvsp[-3].id), NAME), terminalToken("(", OPENPAR), (yyvsp[-1].treePointer), terminalToken(")", CLOSEPAR)); }
#line 1578 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 134 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = NULL; }
#line 1584 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 135 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = (yyvsp[0].treePointer); }
#line 1590 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 138 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = cria_node("arglist", 2, (yyvsp[-1].treePointer), (yyvsp[0].treePointer)); }
#line 1596 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 141 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = NULL; }
#line 1602 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 142 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = cria_node("multExpr", 3, terminalToken(",", COMMA), (yyvsp[-1].treePointer), (yyvsp[0].treePointer)); }
#line 1608 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 145 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = terminalToken((yyvsp[0].id), NUMBER); }
#line 1614 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 146 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = terminalToken((yyvsp[0].id), NAME); }
#line 1620 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 147 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = cria_node("expr", 3, terminalToken("(", OPENPAR), (yyvsp[-1].treePointer), terminalToken(")", CLOSEPAR)); }
#line 1626 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 148 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = cria_node("expr", 1, (yyvsp[0].treePointer)); }
#line 1632 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 149 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = cria_node("expr", 3, (yyvsp[-2].treePointer), terminalToken("+", PLUS), (yyvsp[0].treePointer)); }
#line 1638 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 150 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = cria_node("expr", 3, (yyvsp[-2].treePointer), terminalToken("-", MINUS), (yyvsp[0].treePointer)); }
#line 1644 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 151 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = cria_node("expr", 3, (yyvsp[-2].treePointer), terminalToken("/", DIV), (yyvsp[0].treePointer)); }
#line 1650 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 152 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = cria_node("expr", 3, (yyvsp[-2].treePointer), terminalToken("*", TIMES), (yyvsp[0].treePointer)); }
#line 1656 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 153 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = cria_node("expr", 3, (yyvsp[-2].treePointer), terminalToken("||", OR), (yyvsp[0].treePointer)); }
#line 1662 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 154 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = cria_node("expr", 3, (yyvsp[-2].treePointer), terminalToken("&&", AND), (yyvsp[0].treePointer)); }
#line 1668 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 155 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = cria_node("expr", 3, (yyvsp[-2].treePointer), terminalToken("<", LT), (yyvsp[0].treePointer)); }
#line 1674 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 156 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = cria_node("expr", 3, (yyvsp[-2].treePointer), terminalToken("<=", LTEQ), (yyvsp[0].treePointer)); }
#line 1680 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 157 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = cria_node("expr", 3, (yyvsp[-2].treePointer), terminalToken(">", GT), (yyvsp[0].treePointer)); }
#line 1686 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 158 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = cria_node("expr", 3, (yyvsp[-2].treePointer), terminalToken(">=", GTEQ), (yyvsp[0].treePointer)); }
#line 1692 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 159 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = cria_node("expr", 3, (yyvsp[-2].treePointer), terminalToken("!=", NEQ), (yyvsp[0].treePointer)); }
#line 1698 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 160 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = cria_node("expr", 3, (yyvsp[-2].treePointer), terminalToken("==", EQ), (yyvsp[0].treePointer)); }
#line 1704 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 161 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = cria_node("expr", 2, terminalToken("!", NOT), (yyvsp[0].treePointer)); }
#line 1710 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 162 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = cria_node("expr", 2, terminalToken("-", MINUS), (yyvsp[0].treePointer)); }
#line 1716 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 165 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = terminalToken("int", INT); }
#line 1722 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 166 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = terminalToken("void", VOID); }
#line 1728 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1732 "y.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 169 "parser.y" /* yacc.c:1906  */


tipoTree * cria_node(char nonT[20], int n_filhos, ...){

	va_list params;
	int i = 0;
	tipoTree *aux = malloc(sizeof(struct treeNode));
	aux->nonTerminal = malloc(sizeof(char)*strlen(nonT));
	strcpy(aux->nonTerminal, nonT);
	aux->num_filhos = n_filhos;
	aux->filhos = malloc(n_filhos * sizeof(struct treeNode));

	va_start(params, n_filhos);
	while(i < n_filhos)
	{
		aux->filhos[i] = va_arg(params, tipoTree*);
		i++;
	}

	va_end(params);
	return aux;
}

tipoTree * terminalNumber(int token_n){

	tipoTree *aux = malloc(sizeof(struct treeNode));
	aux->num_filhos = 0;
	aux->tokenNumber = NUMBER;
	aux->number = token_n;
	aux->id = NULL;
	return aux;
}

tipoTree * terminalToken(char id[20], int token_n){

	tipoTree *aux = malloc(sizeof(struct treeNode));
	aux->num_filhos = 0;
	aux->tokenNumber = token_n;
	aux->id = malloc(sizeof(char)*strlen(id));
	strcpy(aux->id, id);
	return aux;
}

void yyerror(char *string){  fprintf(stderr, "%s\n", string);}

int printParams(tipoTree *p){

	int i;
	if (p == NULL)
		return 0;

	if(p->tokenNumber == NAME){
		fprintf(yyout, " [%s]", p->id);
	}

	for(i = 0; i < p->num_filhos; i++){
		printParams(p->filhos[i]);
	}
	return 0;
}

int printExpr(tipoTree *p, int depth){

	int i;
	if (p == NULL)
		return 0;

	if(p->tokenNumber == NUMBER || p->tokenNumber == NAME)
	{
		fprintf(yyout, " [%s]", p->id);
		return 1;
	}
	else if(p->num_filhos == 3){

		if(p->filhos[0]->tokenNumber == OPENPAR)
		{
			printExpr(p->filhos[1], depth);
			return 1;
		}
		else{
			fprintf(yyout, "[%s", p->filhos[1]->id);
			printExpr(p->filhos[0], depth);
			printExpr(p->filhos[2], depth);
			fprintf(yyout, "]");
			return 1;
		}
	}
	else if(p->num_filhos == 2){
		fprintf(yyout, "[%s", p->filhos[0]->id);
		printExpr(p->filhos[1], depth);
		fprintf(yyout, "]");
		return 1;
	}
	else if(p->num_filhos == 1)
	{
		printFuncall(p->filhos[0], depth+1);
		return 1;
	}

	for(i = 0; i < p->num_filhos; i++){
		printExpr(p->filhos[i], depth);
	}
	return 0;
}

int printArglist(tipoTree *p, int depth){

	int i;
	if (p == NULL)
		return 0;

	if((p->nonTerminal != NULL) && strcmp(p->nonTerminal, "expr") == 0){
		printExpr(p, depth);
		return 1;
	}
	else if(p->tokenNumber == NUMBER || p->tokenNumber == NAME){
		fprintf(yyout, " [%s]", p->id);
		return 1;
	}


	for(i = 0; i < p->num_filhos; i++){
		printArglist(p->filhos[i], depth);
	}
	return 0;
}

int printFuncall(tipoTree *p, int depth){

	int i;
	fprintf(yyout, "[funccall [%s] ", p->filhos[0]->id);
	fprintf(yyout, "[arglist");
	printArglist(p->filhos[2], depth);
	fprintf(yyout, "]]");
	return 0;
}

int printMultVar(tipoTree *p, int depth){

	int i;
	if (p == NULL)
		return 0;

	if(p->nonTerminal != NULL && strcmp(p->nonTerminal, "decVar") == 0){

		fprintf(yyout, "[decvar [%s]", p->filhos[1]->id);
		if(p->filhos[2]){
			printExpr(p->filhos[2]->filhos[1], depth);
			fprintf(yyout, "]");
		}
		else
			fprintf(yyout, "]");

		return 1;
	}

	for(i = 0; i < p->num_filhos; i++){
		printMultVar(p->filhos[i], depth);
	}
	return 0;
}

int printMultStmt(tipoTree *p, int depth){

	int i;
	if (p == NULL)
		return 0;

	if(p->nonTerminal != NULL && strcmp(p->nonTerminal, "stmt") == 0){

		if(p->filhos[0]->tokenNumber == NAME)
		{
			fprintf(yyout, "[assign [%s]", p->filhos[0]->id);
			printExpr(p->filhos[2], depth);
			fprintf(yyout, "]");
			return 1;
		}
		else if (p->filhos[0]->tokenNumber == IF)
		{
			fprintf(yyout, "[if");

			printExpr(p->filhos[2], depth+1);
			printTree(p->filhos[4], depth+1);

			if (p->filhos[5]){
				printTree(p->filhos[5]->filhos[1], depth+2);
			}
			fprintf(yyout, "]");
			return 1;
		}
		else if (p->filhos[0]->tokenNumber == WHILE)
		{
			fprintf(yyout, "[while ");
			printExpr(p->filhos[2], depth+1);
			printTree(p->filhos[4], depth+1);
			fprintf(yyout, "]");
			return 1;
		}
		else if (p->filhos[0]->tokenNumber == RETURN)
		{
			fprintf(yyout, "[return ");
			if(p->filhos[1] != NULL)
				printExpr(p->filhos[1], depth);
			fprintf(yyout, "]");
		}
		else if (p->filhos[0]->tokenNumber == BREAK)
		{
			fprintf(yyout, "[break]");
		}
		else if (p->filhos[0]->tokenNumber == CONTINUE)
		{
			fprintf(yyout, "[continue]");
		}
		else{
			printFuncall(p->filhos[0], depth+1);
		}

	}

	for(i = 0; i < p->num_filhos; i++)
		printMultStmt(p->filhos[i], depth);

	return 0;
}

int printDecFunc(tipoTree *p, int depth){

	int i;
	if(p == NULL)
		return 0;

	fprintf(yyout, "[%s]", p->filhos[2]->id);

	if(p->filhos[4] == NULL){
		fprintf(yyout, "[paramlist]");
	}
	else{
		printTree(p->filhos[4], depth);
	}
	printTree(p->filhos[6],depth);
	return 0;
}

int printTree(tipoTree *p, int depth){

	int i;
	if(p == NULL)
		return 0;
	if(p->nonTerminal != NULL){

		//print Paramlist
		if(strcmp(p->nonTerminal, "paramList") == 0)
		{
			fprintf(yyout, "[paramlist");
			printParams(p);
			fprintf(yyout, "]");
			return 0;
		}

		//print expr
		if(strcmp(p->nonTerminal, "expr") == 0){
			printExpr(p, depth);
			fprintf(yyout, "]");
			return 0;
		}
		// print Arglist
		if(strcmp(p->nonTerminal, "compArglist") == 0){
			fprintf(yyout, "[arglist ");
			printArglist(p, depth);
			fprintf(yyout, "]");
			return 0;
		}
		// print multVar
		if(strcmp(p->nonTerminal, "multVar") == 0 || strcmp(p->nonTerminal, "decVar") == 0){
			printMultVar(p, depth);
			return 0;
		}
		// print multstmt
		if(strcmp(p->nonTerminal, "multStmt") == 0){
			printMultStmt(p, depth);
			return 0;
		}
		if(strcmp(p->nonTerminal, "block") == 0){

			fprintf(yyout, "[block ");
			printMultVar(p->filhos[1], depth+1);
			printMultStmt(p->filhos[2], depth+1);
			fprintf(yyout, "]");
			return 0;
		}
		if(strcmp(p->nonTerminal, "decFunc") == 0){
			fprintf(yyout, "[decfunc ");
			printDecFunc(p, depth+1);
			fprintf(yyout, "]");
			return 0;
		}

	}

	if(p->num_filhos == 0)
	{
		if (p->tokenNumber == INT || p->tokenNumber == VOID || p->tokenNumber == DEF || p->tokenNumber == OPENPAR || p->tokenNumber == CLOSEPAR || p->tokenNumber == OPENCH || p->tokenNumber == CLOSECH || p->tokenNumber == SEMICOL)
			return 1;

		fprintf(yyout,"fez bosta\n");
		fprintf(yyout, "[%s]", p->id);
		return 1;
	}
	else
	{
		for(i = 0; i < p->num_filhos; i++){
			printTree(p->filhos[i], depth+1);
		}
	}
}


int insereVar(listaVar **p, char *id, int value){

	listaVar *aux = malloc(sizeof(struct listaV));
	strcpy(aux->varName, id);
	aux->varValue = value;
	aux->prox = *p;
	*p = aux;
}

listaVar * consultaVar(listaVar *p, char *id){

	listaVar *aux;
	for(aux = p; aux != NULL; aux = aux->prox){
		if( strcmp(aux->varName,id) == 0){
			return aux;
		}
	}
	return NULL;
}

int consultaFuncs(listaFuncs *p, char *id){

	listaFuncs *aux;
	for(aux = p; aux != NULL; aux = aux->prox){
		if( strcmp(aux->fname,id) == 0 ){
			return 1;
		}
	}
	return 0;
}

int insereFunc(listaFuncs **p, char *id){

	listaFuncs *aux = malloc(sizeof(struct listaF));
	strcpy(aux->fname, id);
	aux->prox = *p;
	*p = aux;
}

int updateVar(listaVar *p, char *id, int newValue){

	listaVar *aux = consultaVar(p, id);
	// printf("foi?\n");
	if (aux != NULL)
		aux->varValue = newValue;
	else
		return -1;
	return 1;
}


int trataFuncs(tipoTree *p){

	if(p == NULL)
		return 0;

	if( strcmp(p->nonTerminal,"comando") == 0){
		if(p->filhos[0]->id != NULL)
		{
			if( strcmp(p->filhos[0]->id, "function")){
				if(!consultaFuncs(funcs, p->filhos[1]->id))
					insereFunc(&funcs, p->filhos[1]->id);
			}
		}
	}
	else
	{
		int i;
		for(i = 0; i < p->num_filhos; i++)
			trataFuncs(p->filhos[i]);
	}
}

int trataVars(tipoTree *p){

	if(p == NULL)
		return 0;
	if(p->num_filhos == 0)
	{
		if ((p->tokenNumber == NAME) && (consultaVar(vars, p->id) == NULL) && !(consultaFuncs(funcs,p->id))){
			insereVar(&vars, p->id, 0);
			fprintf(yyout, "%s: .word 0\n", p->id);
		}
	}
	else
	{
		int i;
		for(i = 0; i < p->num_filhos; i++)
			trataVars(p->filhos[i]);
	}
}

int main(int argc, char** argv){

	yyin = fopen(argv[1], "r");
	yyout = fopen(argv[2], "w");

	if(!yyin) fprintf(yyout, "Arquivo nao pode ser aberto!\n");
	else{
		yyparse();
	}
	// Incialização do ambiente
	// printTree(treeRoot, 0);
	insereFunc(&funcs, "print");
	trataFuncs(treeRoot);
	printf("chegou\n");

	//Inicializacao MIPS
	fprintf(yyout, "\n.data\n");
	trataVars(treeRoot);
	fprintf(yyout, "\n");
	fprintf(yyout, "_newline: .asciiz \"\\n\"\n");
	fprintf(yyout,".text\n");
	fprintf(yyout,".globl main\n\n");
	fprintf(yyout,"main:\n");

	//Chamar função que gera código aqui


	fprintf(yyout, "li $v0, 4\n");
	fprintf(yyout, "la $a0, _newline\n");
	fprintf(yyout, "syscall\n");

	fprintf(yyout, "\nli $v0, 10\n");
	fprintf(yyout, "syscall");
	fprintf(yyout,"\n");


	fclose(yyin);
	fclose(yyout);

	return 0;
}
