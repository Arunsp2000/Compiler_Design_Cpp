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
#line 1 "symbl_tbl.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#define YYSTYPE char *
int yyerror();
extern char *yytext;
extern int yylineno;
int global_scope;
typedef struct symbol_table
{
  int line;
  int scope;
  char name[31];
  char type;
  char *value;
  char *datatype;
}ST;
int table_index = 0;
ST st[10000];


#line 88 "y.tab.c" /* yacc.c:339  */

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
    PRIVATE = 258,
    PUBLIC = 259,
    PROTECTED = 260,
    DO = 261,
    DOUBLE = 262,
    WHILE = 263,
    IF = 264,
    ELSE = 265,
    COUT = 266,
    ENDL = 267,
    BREAK = 268,
    CONTINUE = 269,
    INT = 270,
    FLOAT = 271,
    CHAR = 272,
    VOID = 273,
    INCLUDE = 274,
    TOK_MAIN = 275,
    CLASS = 276,
    NUM = 277,
    ID = 278,
    HEADER = 279,
    STRING = 280,
    lt = 281,
    gt = 282,
    eq = 283,
    lteq = 284,
    gteq = 285,
    eqeq = 286,
    neq = 287,
    pl = 288,
    min = 289,
    mul = 290,
    division = 291,
    incr = 292,
    decr = 293,
    or = 294,
    and = 295,
    not = 296,
    perce = 297,
    USING = 298,
    NAMESPACE = 299,
    STD = 300
  };
#endif
/* Tokens.  */
#define PRIVATE 258
#define PUBLIC 259
#define PROTECTED 260
#define DO 261
#define DOUBLE 262
#define WHILE 263
#define IF 264
#define ELSE 265
#define COUT 266
#define ENDL 267
#define BREAK 268
#define CONTINUE 269
#define INT 270
#define FLOAT 271
#define CHAR 272
#define VOID 273
#define INCLUDE 274
#define TOK_MAIN 275
#define CLASS 276
#define NUM 277
#define ID 278
#define HEADER 279
#define STRING 280
#define lt 281
#define gt 282
#define eq 283
#define lteq 284
#define gteq 285
#define eqeq 286
#define neq 287
#define pl 288
#define min 289
#define mul 290
#define division 291
#define incr 292
#define decr 293
#define or 294
#define and 295
#define not 296
#define perce 297
#define USING 298
#define NAMESPACE 299
#define STD 300

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 229 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  26
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   248

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  92
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  181

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   301

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
      48,    49,     2,     2,    50,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    53,    47,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    51,     2,    52,     2,     2,     2,     2,
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
      45,    46
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    35,    35,    39,    40,    41,    42,    43,    44,    45,
      46,    50,    51,    54,    55,    59,    59,    60,    60,    64,
      65,    69,    73,    74,    75,    76,    81,    82,    83,    88,
      88,    89,    89,    92,    92,    93,    97,    98,    99,   100,
     101,   105,   106,   107,   111,   117,   117,   118,   121,   122,
     123,   127,   131,   132,   133,   134,   135,   139,   140,   141,
     145,   146,   147,   148,   151,   152,   153,   156,   157,   158,
     159,   160,   161,   162,   166,   167,   168,   172,   173,   174,
     175,   179,   180,   184,   185,   186,   187,   195,   196,   203,
     204,   205,   206
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PRIVATE", "PUBLIC", "PROTECTED", "DO",
  "DOUBLE", "WHILE", "IF", "ELSE", "COUT", "ENDL", "BREAK", "CONTINUE",
  "INT", "FLOAT", "CHAR", "VOID", "INCLUDE", "TOK_MAIN", "CLASS", "NUM",
  "ID", "HEADER", "STRING", "lt", "gt", "eq", "lteq", "gteq", "eqeq",
  "neq", "pl", "min", "mul", "division", "incr", "decr", "or", "and",
  "not", "perce", "USING", "NAMESPACE", "STD", "\"\\\"\"", "';'", "'('",
  "')'", "','", "'{'", "'}'", "':'", "$accept", "S", "START", "FUNCTION",
  "FUNC_DECL", "FUNC_DEF", "$@1", "$@2", "PARAMETER_LIST", "CLASS_DEF",
  "CLASS_BODY", "ACCESS_SPECIFIER", "MAIN", "$@3", "$@4", "MAIN_BODY",
  "$@5", "LINES", "LOOP", "COND", "LOOPBODY", "$@6", "STATEMENT", "PRINT",
  "CASCADE", "ASSIGN_EXPR", "ARITH_EXPR", "LOGICAL_EXPR",
  "RELLATIONAL_EXPR", "ADDITIVE", "MULTIPLCIATIVE", "FINAL", "TYPE",
  "unary_arop", "LITERAL", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,    59,    40,    41,
      44,   123,   125,    58
};
# endif

#define YYPACT_NINF -159

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-159)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      99,  -159,    -7,  -159,  -159,    -2,   -17,    -8,    26,    18,
      66,  -159,    99,  -159,  -159,    25,  -159,    29,    69,  -159,
    -159,    81,    71,    39,   115,    54,  -159,  -159,    99,    99,
     -14,    68,    68,   109,   118,   102,    93,  -159,     8,    65,
    -159,  -159,    30,   115,  -159,    87,   160,    95,   139,  -159,
     134,  -159,   117,  -159,  -159,   115,    21,   114,  -159,  -159,
      99,    99,    99,  -159,  -159,  -159,  -159,  -159,   128,   135,
     144,  -159,  -159,  -159,  -159,    87,   121,    30,    30,    30,
      30,    30,    30,    30,    30,    30,    30,    30,    30,    30,
    -159,    99,  -159,   146,   148,   171,  -159,   200,  -159,  -159,
    -159,  -159,    93,   103,  -159,   160,   160,    95,    95,    95,
      95,    95,    95,   139,   139,  -159,  -159,  -159,  -159,  -159,
      68,   151,   152,    10,   147,   175,    22,  -159,   124,  -159,
     157,  -159,  -159,  -159,   182,  -159,    93,    64,  -159,  -159,
      68,    67,  -159,   204,   161,   115,   187,  -159,  -159,  -159,
     172,  -159,   190,  -159,   146,   181,  -159,  -159,   200,   173,
    -159,   183,  -159,   100,  -159,   151,   162,   115,    10,  -159,
     175,   175,  -159,   184,   210,  -159,  -159,   188,    10,  -159,
    -159
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    86,    83,    85,    84,     0,     0,     0,     0,     0,
       0,     2,     0,    12,    11,     0,     6,     0,     0,    31,
      29,     0,     0,     0,     0,     0,     1,     9,     0,     0,
      59,     0,     0,     0,     0,     0,     0,    90,    89,     0,
      87,    88,     0,     0,    57,    60,    64,    67,    74,    77,
       0,    82,     0,     8,     7,     0,     0,    33,    32,    30,
       0,     0,     0,    26,    28,    27,    83,    25,     0,     0,
       0,    61,    92,    91,    89,    63,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      62,     0,    58,    17,     0,     0,    35,     0,     5,     3,
       4,    21,     0,     0,    81,    66,    65,    72,    73,    70,
      69,    68,    71,    75,    76,    79,    78,    80,    10,    14,
       0,    15,    20,     0,     0,     0,    89,    40,     0,    39,
       0,    50,    48,    49,     0,    22,    24,     0,    18,    13,
       0,     0,    45,     0,     0,     0,     0,    51,    34,    37,
       0,    38,    59,    23,     0,     0,    16,    19,     0,     0,
      47,     0,    44,     0,    36,     0,     0,     0,     0,    56,
      53,    55,    46,     0,    41,    52,    54,     0,     0,    43,
      42
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -159,  -159,    -5,  -159,   -35,  -159,  -159,  -159,  -125,  -159,
     -96,  -159,  -159,  -159,  -159,   -29,  -159,    73,  -117,    72,
    -158,  -159,   -89,  -159,   -16,   -93,   -24,   194,    82,   145,
      97,   -46,   -34,   -33,  -159
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    10,    11,    12,    13,    14,   140,   120,    94,    15,
      68,    69,    16,    32,    31,    58,    97,   128,   129,   161,
     143,   158,   144,   131,   147,    17,   133,    45,    46,    47,
      48,    49,    18,    50,    51
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      44,    67,    70,    59,   132,    71,   135,    27,   130,    21,
     174,   149,   155,    19,    55,    23,   157,     1,    20,    76,
     180,   125,    95,    53,    54,    66,     3,     4,     1,    22,
     132,    92,    37,   126,    56,   132,    66,     3,     4,   150,
     153,   115,   116,   117,    39,    40,    41,    40,    41,   149,
      24,    42,    37,    74,    24,    98,    99,   100,    43,    40,
      41,   142,    25,   134,    39,   132,    26,    67,    70,   130,
      93,     1,    28,   132,     1,   132,    29,   150,    43,    66,
       3,     4,    66,     3,     4,   132,   118,    72,    73,   134,
      36,   138,    30,    71,   134,    35,    63,    64,    65,    52,
       1,    67,    70,    95,    33,    34,     1,    95,    66,     3,
       4,   156,   169,   154,     2,     3,     4,     5,     6,    57,
       7,   162,     8,   170,   134,   171,    77,    78,    85,    86,
     123,     1,   134,   124,   134,   125,    60,    37,    38,    66,
       3,     4,     9,   162,   134,    61,    37,   126,    62,    39,
     136,   137,    40,    41,   175,   176,    42,    90,    39,   105,
     106,    40,    41,    43,    91,    42,    96,   103,   123,     1,
     104,   124,    43,   125,    87,    88,   148,    66,     3,     4,
     101,    89,   113,   114,    37,   126,    79,    80,   102,    81,
      82,    83,    84,   119,   122,   145,    39,   121,   139,    40,
      41,   146,   141,    42,   151,   152,   123,     1,   160,   124,
      43,   125,   159,   163,   172,    66,     3,     4,    55,   164,
     178,   167,    37,   126,   107,   108,   109,   110,   111,   112,
     165,   166,   168,   177,    39,   179,    75,    40,    41,   173,
       0,    42,     0,     0,     0,     0,     0,   127,    43
};

static const yytype_int16 yycheck[] =
{
      24,    36,    36,    32,    97,    38,   102,    12,    97,    26,
     168,   128,   137,    20,    28,    23,   141,     7,    20,    43,
     178,    11,    56,    28,    29,    15,    16,    17,     7,    46,
     123,    55,    22,    23,    48,   128,    15,    16,    17,   128,
     136,    87,    88,    89,    34,    37,    38,    37,    38,   166,
      28,    41,    22,    23,    28,    60,    61,    62,    48,    37,
      38,    51,    44,    97,    34,   158,     0,   102,   102,   158,
      49,     7,    47,   166,     7,   168,    47,   166,    48,    15,
      16,    17,    15,    16,    17,   178,    91,    22,    23,   123,
      51,   120,    23,   126,   128,    24,     3,     4,     5,    45,
       7,   136,   136,   137,    23,    24,     7,   141,    15,    16,
      17,   140,    12,    49,    15,    16,    17,    18,    19,    51,
      21,   145,    23,    23,   158,    25,    39,    40,    33,    34,
       6,     7,   166,     9,   168,    11,    27,    22,    23,    15,
      16,    17,    43,   167,   178,    27,    22,    23,    46,    34,
      47,    48,    37,    38,   170,   171,    41,    23,    34,    77,
      78,    37,    38,    48,    47,    41,    52,    23,     6,     7,
      49,     9,    48,    11,    35,    36,    52,    15,    16,    17,
      52,    42,    85,    86,    22,    23,    26,    27,    53,    29,
      30,    31,    32,    47,    23,    48,    34,    49,    47,    37,
      38,    26,    50,    41,    47,    23,     6,     7,    47,     9,
      48,    11,     8,    26,    52,    15,    16,    17,    28,    47,
      10,    48,    22,    23,    79,    80,    81,    82,    83,    84,
      49,   158,    49,    49,    34,    47,    42,    37,    38,   167,
      -1,    41,    -1,    -1,    -1,    -1,    -1,    47,    48
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,    15,    16,    17,    18,    19,    21,    23,    43,
      55,    56,    57,    58,    59,    63,    66,    79,    86,    20,
      20,    26,    46,    23,    28,    44,     0,    56,    47,    47,
      23,    68,    67,    23,    24,    24,    51,    22,    23,    34,
      37,    38,    41,    48,    80,    81,    82,    83,    84,    85,
      87,    88,    45,    56,    56,    28,    48,    51,    69,    69,
      27,    27,    46,     3,     4,     5,    15,    58,    64,    65,
      86,    87,    22,    23,    23,    81,    80,    39,    40,    26,
      27,    29,    30,    31,    32,    33,    34,    35,    36,    42,
      23,    47,    80,    49,    62,    86,    52,    70,    56,    56,
      56,    52,    53,    23,    49,    82,    82,    83,    83,    83,
      83,    83,    83,    84,    84,    85,    85,    85,    56,    47,
      61,    49,    23,     6,     9,    11,    23,    47,    71,    72,
      76,    77,    79,    80,    86,    64,    47,    48,    69,    47,
      60,    50,    51,    74,    76,    48,    26,    78,    52,    72,
      76,    47,    23,    64,    49,    62,    69,    62,    75,     8,
      47,    73,    80,    26,    47,    49,    71,    48,    49,    12,
      23,    25,    52,    73,    74,    78,    78,    49,    10,    47,
      74
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    54,    55,    56,    56,    56,    56,    56,    56,    56,
      56,    57,    57,    58,    58,    60,    59,    61,    59,    62,
      62,    63,    64,    64,    64,    64,    65,    65,    65,    67,
      66,    68,    66,    70,    69,    69,    71,    71,    71,    71,
      71,    72,    72,    72,    73,    75,    74,    74,    76,    76,
      76,    77,    78,    78,    78,    78,    78,    79,    79,    79,
      80,    80,    80,    80,    81,    81,    81,    82,    82,    82,
      82,    82,    82,    82,    83,    83,    83,    84,    84,    84,
      84,    85,    85,    86,    86,    86,    86,    87,    87,    88,
      88,    88,    88
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     5,     5,     5,     1,     3,     3,     2,
       5,     1,     1,     6,     5,     0,     7,     0,     6,     4,
       2,     5,     3,     4,     3,     1,     1,     1,     1,     0,
       4,     0,     4,     0,     4,     2,     3,     2,     2,     1,
       1,     5,     7,     7,     1,     0,     4,     2,     1,     1,
       1,     2,     4,     3,     4,     3,     3,     3,     4,     2,
       1,     2,     2,     2,     1,     3,     3,     1,     3,     3,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2
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
#line 35 "symbl_tbl.y" /* yacc.c:1646  */
    {printf("Input accepted.\n");}
#line 1450 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 54 "symbl_tbl.y" /* yacc.c:1646  */
    {lookup((yyvsp[-4]),yylineno,'I',NULL,(yyvsp[-5]));}
#line 1456 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 55 "symbl_tbl.y" /* yacc.c:1646  */
    {lookup((yyvsp[-3]),yylineno,'I',NULL,(yyvsp[-4]));}
#line 1462 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 59 "symbl_tbl.y" /* yacc.c:1646  */
    {lookup((yyvsp[-3]),yylineno-1,'I',NULL,(yyvsp[-4]));}
#line 1468 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 60 "symbl_tbl.y" /* yacc.c:1646  */
    {lookup((yyvsp[-2]),yylineno-1,'I',NULL,(yyvsp[-3]));}
#line 1474 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 88 "symbl_tbl.y" /* yacc.c:1646  */
    {lookup((yyvsp[0]),yylineno,'I',NULL,(yyvsp[-1]));}
#line 1480 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 89 "symbl_tbl.y" /* yacc.c:1646  */
    {lookup((yyvsp[0]),yylineno,'I',NULL,(yyvsp[-1]));}
#line 1486 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 92 "symbl_tbl.y" /* yacc.c:1646  */
    {global_scope++;}
#line 1492 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 92 "symbl_tbl.y" /* yacc.c:1646  */
    {global_scope--;}
#line 1498 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 117 "symbl_tbl.y" /* yacc.c:1646  */
    {global_scope++;}
#line 1504 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 117 "symbl_tbl.y" /* yacc.c:1646  */
    {global_scope--;}
#line 1510 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 139 "symbl_tbl.y" /* yacc.c:1646  */
    {search_id((yyvsp[-2]),yylineno);update((yyvsp[-2]),yylineno,(yyvsp[0]));}
#line 1516 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 140 "symbl_tbl.y" /* yacc.c:1646  */
    {lookup((yyvsp[-2]),yylineno,'I',NULL,(yyvsp[-3]));update((yyvsp[-2]),yylineno,(yyvsp[0]));}
#line 1522 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 152 "symbl_tbl.y" /* yacc.c:1646  */
    { strcat((yyval)," "); strcat((yyval),(yyvsp[-1])); strcat((yyval)," ");strcat((yyval),(yyvsp[0]));}
#line 1528 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 153 "symbl_tbl.y" /* yacc.c:1646  */
    { strcat((yyval)," "); strcat((yyval),(yyvsp[-1])); strcat((yyval)," ");strcat((yyval),(yyvsp[0]));}
#line 1534 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 157 "symbl_tbl.y" /* yacc.c:1646  */
    { strcat((yyval)," "); strcat((yyval),(yyvsp[-1])); strcat((yyval)," ");strcat((yyval),(yyvsp[0]));}
#line 1540 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 158 "symbl_tbl.y" /* yacc.c:1646  */
    { strcat((yyval)," "); strcat((yyval),(yyvsp[-1])); strcat((yyval)," ");strcat((yyval),(yyvsp[0]));}
#line 1546 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 159 "symbl_tbl.y" /* yacc.c:1646  */
    { strcat((yyval)," "); strcat((yyval),(yyvsp[-1])); strcat((yyval)," ");strcat((yyval),(yyvsp[0]));}
#line 1552 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 160 "symbl_tbl.y" /* yacc.c:1646  */
    { strcat((yyval)," "); strcat((yyval),(yyvsp[-1])); strcat((yyval)," ");strcat((yyval),(yyvsp[0]));}
#line 1558 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 161 "symbl_tbl.y" /* yacc.c:1646  */
    { strcat((yyval)," "); strcat((yyval),(yyvsp[-1])); strcat((yyval)," ");strcat((yyval),(yyvsp[0]));}
#line 1564 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 162 "symbl_tbl.y" /* yacc.c:1646  */
    { strcat((yyval)," "); strcat((yyval),(yyvsp[-1])); strcat((yyval)," ");strcat((yyval),(yyvsp[0]));}
#line 1570 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 167 "symbl_tbl.y" /* yacc.c:1646  */
    { strcat((yyval)," "); strcat((yyval),(yyvsp[-1])); strcat((yyval)," ");strcat((yyval),(yyvsp[0]));}
#line 1576 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 168 "symbl_tbl.y" /* yacc.c:1646  */
    { strcat((yyval)," "); strcat((yyval),(yyvsp[-1])); strcat((yyval)," ");strcat((yyval),(yyvsp[0]));}
#line 1582 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 173 "symbl_tbl.y" /* yacc.c:1646  */
    { strcat((yyval)," "); strcat((yyval),(yyvsp[-1])); strcat((yyval)," ");strcat((yyval),(yyvsp[0]));}
#line 1588 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 174 "symbl_tbl.y" /* yacc.c:1646  */
    { strcat((yyval)," "); strcat((yyval),(yyvsp[-1])); strcat((yyval)," ");strcat((yyval),(yyvsp[0]));}
#line 1594 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 175 "symbl_tbl.y" /* yacc.c:1646  */
    { strcat((yyval)," "); strcat((yyval),(yyvsp[-1])); strcat((yyval)," ");strcat((yyval),(yyvsp[0]));}
#line 1600 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 203 "symbl_tbl.y" /* yacc.c:1646  */
    {search_id((yyvsp[0]),yylineno);}
#line 1606 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1610 "y.tab.c" /* yacc.c:1646  */
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
#line 210 "symbl_tbl.y" /* yacc.c:1906  */



#include "lex.yy.c"

int yyerror(){
  printf("Error at line at %d\n",yylineno);
}

int main()
{
if(!yyparse())  //yyparse-> 0 if success
  {
  	printf("Parsing Complete\n");
    printf("Number of entries in the symbol table = %d\n\n",table_index);
    printf("-----------------------------------Symbol Table--------------------------------------\n\n");
    printf("S.No\t  Token  \t Line Number \t Category \t DataType \t Value \t  Scope \n");
    
    for (int i = 0;i < table_index;i++)
    {
      char *ty;
      
     if(st[i].type=='I')
      {
        ty="identifier";
        printf("%-4d\t  %-7s\t   %-10d \t %-9s\t  %-7s\t   %-5s   %-7d\n",i+1,st[i].name,st[i].line,ty,st[i].datatype,st[i].value,st[i].scope);
      }
    }
  }
  else
  {
    printf("Parsing failed\n");
  }
}


void lookup(char *token,int line,char type,char *value,char *datatype)
{
  // printf("Token %s\n",token);
  int flag = 0;
  for(int i = 0;i < table_index;i++)
  {
    if(!strcmp(st[i].name,token))
    {
      if(st[i].scope==global_scope)
      {  
        flag = 1;
        printf("Error at line %d : %s is redefined\n",line,token);
        exit(0);
      }
    }
  }
  
  //Insert
  if(flag == 0)
  {
    st[table_index].scope=global_scope;
    strcpy(st[table_index].name,token);
    st[table_index].type=type;
    if(value==NULL)
        st[table_index].value=NULL;
    else
        strcpy(st[table_index].value,value);
        
    if(datatype==NULL)
        st[table_index].datatype=NULL;
    else
        st[table_index].datatype=datatype;
        
    st[table_index].line = line;
    table_index++;
  }
}

void search_id(char *token,int lineno)
{
  int flag = 0;
  for(int i = 0;i < table_index;i++)
  {
    if(!strcmp(st[i].name,token))
    {
      flag = 1;
      return;
    }
  }
  if(flag == 0)
  {
    printf("Error at line %d : %s is not defined\n",lineno,token);
    exit(0);
  }
}

void update(char *token,int lineno,char *value)
{
  int flag = 0;
  // printf("%s\n",value);
  for(int i = 0;i < table_index;i++)
  {
    if(!strcmp(st[i].name,token))
    {
      if(st[i].scope == global_scope)
      {  
        flag = 1;
        st[i].value = (char*)malloc(sizeof(char)*strlen(value));
        //sprintf(st[i].value,"%s",value);
        strcpy(st[i].value,value);
        st[i].line = lineno;
        return;
      }
    }
  }
  for(int k=global_scope-1;k!=-1;k--)
  {
    for(int i = 0;i < table_index;i++)
    {
      if(!strcmp(st[i].name,token))
      {
        if(st[i].scope == k)
        {  
          flag = 1;
          st[i].value = (char*)malloc(sizeof(char)*strlen(value));
          //sprintf(st[i].value,"%s",value);
          strcpy(st[i].value,value);
          st[i].line = lineno;
          return;
        }
      }
    }
  }
  if(flag == 0)
  {
    printf("Error at line %d : %s is not defined\n",lineno,token);
    exit(0);
  }
}

// int get_val(char *token)
// {
//   int flag = 0;
//   for(int i = 0;i < table_index;i++)
//   {
//     if(!strcmp(st[i].name,token))
//     {
//       flag = 1;scope
//       return st[i].value;
//     }
//   }
//   if(flag == 0)
//   {
//     printf("Error at line : %s is not defined\n",token);
//     exit(0);
//   }
// }
