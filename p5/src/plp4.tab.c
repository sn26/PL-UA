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
#line 21 "plp4.y" /* yacc.c:339  */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;
#include "comun.h"
#include "TablaSimbolos.h"


extern int col, fila, findefichero;

extern int yylex();
extern char *yytext;
extern FILE *yyin;


int yyerror(char *s);
const int ERRYADECL=1,ERRNODECL=2,ERRVOID=3,ERRNOSIMPLE=4,ERRNOENTERO=5;
void errorSemantico(int nerror,char *lexema,int fila,int columna);

TablaSimbolos *tsActual = new TablaSimbolos(NULL); 

string tipoMayus(string tipo);
string tipoShake(string  type1,  string type2);
int parserTipo(string tipo , char * lexema, int fila, int columna  );

#line 95 "plp4.tab.c" /* yacc.c:339  */

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
   by #include "plp4.tab.h".  */
#ifndef YY_YY_PLP4_TAB_H_INCLUDED
# define YY_YY_PLP4_TAB_H_INCLUDED
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
    pari = 258,
    pard = 259,
    dosp = 260,
    rettok = 261,
    asig = 262,
    pyc = 263,
    opas = 264,
    opmd = 265,
    fn = 266,
    endfn = 267,
    inttok = 268,
    real = 269,
    let = 270,
    iftok = 271,
    elsetok = 272,
    fi = 273,
    print = 274,
    blq = 275,
    fblq = 276,
    id = 277,
    numint = 278,
    numreal = 279,
    eof = 280
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PLP4_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 172 "plp4.tab.c" /* yacc.c:358  */

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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   49

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  26
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  57
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  87

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   280

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
      25
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    52,    52,    60,    66,    69,    69,    69,    72,    80,
      81,    82,    72,    94,    94,    94,    96,    96,   100,   102,
     103,   105,   106,   109,   109,   110,   110,   110,   110,   112,
     113,   113,   114,   115,   115,   115,   117,   117,   117,   119,
     119,   119,   121,   124,   131,   131,   155,   166,   166,   168,
     170,   174,   179,   186,   192,   195,   199,   203
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "pari", "pard", "dosp", "rettok", "asig",
  "pyc", "opas", "opmd", "fn", "endfn", "inttok", "real", "let", "iftok",
  "elsetok", "fi", "print", "blq", "fblq", "id", "numint", "numreal",
  "eof", "$accept", "S", "Sp", "Spp", "$@1", "$@2", "Fun", "$@3", "@4",
  "@5", "@6", "A", "@7", "$@8", "Arg", "@9", "Rt", "Type", "Cod", "@10",
  "$@11", "$@12", "@13", "I", "@14", "@15", "@16", "Blq", "@17", "$@18",
  "Ip", "@19", "$@20", "It", "@21", "Ifa", "$@22", "E", "T", "F", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280
};
# endif

#define YYPACT_NINF -40

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-40)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       2,    -4,    25,   -40,     2,   -40,   -40,   -40,   -40,     2,
      26,   -40,   -40,   -40,   -40,     9,    24,    27,    29,    14,
     -40,    14,   -40,   -40,   -40,   -40,     2,   -40,   -40,   -40,
       9,   -40,   -40,     8,   -40,   -40,   -40,   -40,    -8,    -8,
      12,     0,     0,   -40,   -40,   -40,   -40,   -40,     0,   -40,
     -40,   -40,    28,    30,   -40,    28,   -40,    10,     5,     0,
      -8,     0,    31,    14,     0,   -40,   -40,    30,   -40,   -40,
      15,   -40,    28,   -12,   -40,    19,   -40,   -40,   -40,   -40,
     -40,    -8,     0,   -40,    28,    20,   -40
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     5,     8,     1,     3,     6,     5,
       0,     7,     4,    13,     9,    18,    20,     0,     0,     0,
      10,     0,    14,    21,    22,    19,     5,    16,    15,    11,
      18,    25,    17,     0,    26,    23,    12,    27,     0,     0,
       0,     0,     0,    36,    24,    29,    28,    30,     0,    57,
      54,    55,    33,    51,    53,    32,    25,    46,     0,     0,
       0,     0,    37,     0,     0,    31,    56,    50,    34,    52,
       0,    43,    44,     0,    38,    49,    39,    42,    35,    47,
      45,     0,     0,    40,    48,     0,    41
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -40,   -40,   -40,    -7,   -40,   -40,    41,   -40,   -40,   -40,
     -40,   -40,   -40,   -40,    16,   -40,   -40,   -20,   -11,   -40,
     -40,   -40,   -40,   -39,   -40,   -40,   -40,   -40,   -40,   -40,
     -40,   -40,   -40,   -40,   -40,   -40,   -40,   -38,   -10,   -14
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     7,     8,    11,     9,    10,    16,    26,
      31,    14,    15,    28,    18,    30,    20,    25,    33,    38,
      34,    37,    39,    44,    57,    60,    73,    45,    56,    70,
      78,    81,    85,    65,    75,    80,    82,    52,    53,    54
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      46,    27,    12,    48,    55,    76,    77,    40,    41,    66,
      58,    42,    43,     1,    59,    63,    35,    64,     5,    29,
      36,    68,    49,    50,    51,     6,    72,    23,    24,    13,
      19,    17,    21,    22,    47,    79,    74,    59,    86,    35,
      61,     4,    83,    71,    84,    62,    32,    69,     0,    67
};

static const yytype_int8 yycheck[] =
{
      39,    21,     9,     3,    42,    17,    18,    15,    16,     4,
      48,    19,    20,    11,     9,     5,     8,     7,    22,    26,
      12,    60,    22,    23,    24,     0,    64,    13,    14,     3,
       6,    22,     5,     4,    22,    16,    21,     9,    18,     8,
      10,     0,    81,    63,    82,    56,    30,    61,    -1,    59
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    11,    27,    28,    32,    22,     0,    29,    30,    32,
      33,    31,    29,     3,    37,    38,    34,    22,    40,     6,
      42,     5,     4,    13,    14,    43,    35,    43,    39,    29,
      41,    36,    40,    44,    46,     8,    12,    47,    45,    48,
      15,    16,    19,    20,    49,    53,    49,    22,     3,    22,
      23,    24,    63,    64,    65,    63,    54,    50,    63,     9,
      51,    10,    44,     5,     7,    59,     4,    64,    49,    65,
      55,    43,    63,    52,    21,    60,    17,    18,    56,    16,
      61,    57,    62,    49,    63,    58,    18
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    26,    27,    28,    29,    30,    31,    29,    33,    34,
      35,    36,    32,    38,    39,    37,    41,    40,    40,    42,
      42,    43,    43,    45,    44,    46,    47,    48,    44,    49,
      50,    49,    49,    51,    52,    49,    54,    55,    53,    57,
      58,    56,    56,    59,    60,    59,    59,    62,    61,    61,
      63,    63,    64,    64,    65,    65,    65,    65
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     0,     0,     2,     0,     0,
       0,     0,    11,     0,     0,     5,     0,     5,     0,     2,
       0,     1,     1,     0,     4,     0,     0,     0,     4,     1,
       0,     4,     2,     0,     0,     6,     0,     0,     5,     0,
       0,     5,     1,     2,     0,     4,     0,     0,     3,     0,
       3,     1,     3,     1,     1,     1,     3,     1
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
#line 52 "plp4.y" /* yacc.c:1646  */
    { 
    /* Primero, comprobaremos que después del programa no hay ningún token más*/
    int tk = yylex(); 
    if(tk!= 0) yyerror(""); 
    (yyval).trad = (yyvsp[0]).trad; 
    cout<<(yyval).trad; 
}
#line 1306 "plp4.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 60 "plp4.y" /* yacc.c:1646  */
    {
    (yyval).trad = (yyvsp[-1]).trad + (yyvsp[0]).trad; 
    (yyval).atributos.asig = "";
}
#line 1315 "plp4.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 66 "plp4.y" /* yacc.c:1646  */
    { 
                (yyval).trad = (yyvsp[-1]).trad + (yyvsp[0]).trad; 
                (yyval).atributos.asig = (yyvsp[-2]).atributos.asig; }
#line 1323 "plp4.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 69 "plp4.y" /* yacc.c:1646  */
    {}
#line 1329 "plp4.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 69 "plp4.y" /* yacc.c:1646  */
    {}
#line 1335 "plp4.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 69 "plp4.y" /* yacc.c:1646  */
    {(yyval).trad = ""; }
#line 1341 "plp4.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 72 "plp4.y" /* yacc.c:1646  */
    {  
            struct Simbolo simb1; 
            simb1.nombre = (yyvsp[0]).lexema; 
            simb1.tipo =FUNCIONT; 
            simb1.nomtrad = (yyvsp[-2]).atributos.asig + (yyvsp[0]).lexema;  
            if(!tsActual->newSymb(simb1))errorSemantico(ERRYADECL,(yyvsp[0]).lexema,(yyvsp[0]).fila,(yyvsp[0]).col);
            tsActual= new TablaSimbolos(tsActual); 
            }
#line 1354 "plp4.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 80 "plp4.y" /* yacc.c:1646  */
    {if((yyvsp[-4]).trad== "") { (yyval).trad = "void"; } else{ (yyval).trad = (yyvsp[-4]).trad; }}
#line 1360 "plp4.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 81 "plp4.y" /* yacc.c:1646  */
    {(yyval).atributos.asig = (yyvsp[-6]).atributos.asig + (yyvsp[-4]).lexema + "_"; }
#line 1366 "plp4.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 82 "plp4.y" /* yacc.c:1646  */
    { (yyval).trad = "_" +(yyvsp[-8]).atributos.asig + (yyvsp[-6]).lexema; 
            (yyval).atributos.asig = (yyval).trad;
            (yyval).atributos.tipo = (yyvsp[-2]).trad; }
#line 1374 "plp4.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 85 "plp4.y" /* yacc.c:1646  */
    {
                tsActual = tsActual->getPadre();
                
                (yyval).atributos.asig = (yyvsp[-11]).atributos.asig;
                (yyval).atributos.tipo= (yyvsp[-11]).atributos.tipo;
                (yyval).trad = (yyvsp[-3]).trad + (yyvsp[-5]).trad + " " + (yyvsp[-11]).atributos.asig + (yyvsp[-9]).lexema + " "+ (yyvsp[-7]).trad +  "\n{\n" + (yyvsp[-1]).trad + " }\n " ;
            }
#line 1386 "plp4.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 94 "plp4.y" /* yacc.c:1646  */
    { (yyval).trad = ""; (yyval).atributos.asig = ""; }
#line 1392 "plp4.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 94 "plp4.y" /* yacc.c:1646  */
    {}
#line 1398 "plp4.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 94 "plp4.y" /* yacc.c:1646  */
    { (yyval).trad = "(" + (yyvsp[-2]).trad + ")";  }
#line 1404 "plp4.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 96 "plp4.y" /* yacc.c:1646  */
    {if((yyvsp[-3]).trad==""){(yyval).trad= ",";} else {(yyval).trad = (yyvsp[-3]).trad;} (yyval).atributos.asig = ",";}
#line 1410 "plp4.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 96 "plp4.y" /* yacc.c:1646  */
    {
    struct Simbolo simb1; simb1.nombre = (yyvsp[-4]).lexema; simb1.tipo = parserTipo((yyvsp[-2]).trad , (yyvsp[-4]).lexema , (yyvsp[-4]).fila, (yyvsp[-4]).col ); simb1.nomtrad = (yyvsp[-4]).lexema;  
    if(!tsActual->newSymb(simb1))  errorSemantico(ERRYADECL,(yyvsp[-4]).lexema,(yyvsp[-4]).fila,(yyvsp[-4]).col);
    (yyval).trad = (yyvsp[-5]).trad + (yyvsp[-2]).trad + " " + (yyvsp[-4]).lexema + (yyvsp[0]).trad;     }
#line 1419 "plp4.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 100 "plp4.y" /* yacc.c:1646  */
    {(yyval).trad = "";  }
#line 1425 "plp4.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 102 "plp4.y" /* yacc.c:1646  */
    { (yyval).trad = (yyvsp[0]).trad;}
#line 1431 "plp4.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 103 "plp4.y" /* yacc.c:1646  */
    {if((yyvsp[0]).trad =="" ){(yyval).trad = "void";}else{ (yyval).trad=(yyvsp[0]).trad;}  }
#line 1437 "plp4.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 105 "plp4.y" /* yacc.c:1646  */
    { (yyval).trad = "int"; }
#line 1443 "plp4.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 106 "plp4.y" /* yacc.c:1646  */
    {(yyval).trad = "float";}
#line 1449 "plp4.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 109 "plp4.y" /* yacc.c:1646  */
    {(yyval).trad =(yyvsp[-2]).trad; (yyval).atributos.tipo= (yyvsp[-2]).atributos.tipo;  }
#line 1455 "plp4.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 109 "plp4.y" /* yacc.c:1646  */
    {(yyval).trad = (yyvsp[-3]).trad + (yyvsp[0]).trad;  }
#line 1461 "plp4.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 110 "plp4.y" /* yacc.c:1646  */
    {}
#line 1467 "plp4.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 110 "plp4.y" /* yacc.c:1646  */
    {}
#line 1473 "plp4.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 110 "plp4.y" /* yacc.c:1646  */
    {(yyval).trad = (yyvsp[-2]).trad; (yyval).atributos.tipo= (yyvsp[-2]).atributos.tipo; }
#line 1479 "plp4.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 110 "plp4.y" /* yacc.c:1646  */
    {(yyval).trad = (yyvsp[0]).trad; }
#line 1485 "plp4.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 112 "plp4.y" /* yacc.c:1646  */
    {(yyval).trad = (yyvsp[0]).trad + "\n"; }
#line 1491 "plp4.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 113 "plp4.y" /* yacc.c:1646  */
    {(yyval).trad = (yyvsp[-2]).trad; (yyval).atributos.tipo = (yyvsp[-2]).atributos.tipo;    }
#line 1497 "plp4.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 113 "plp4.y" /* yacc.c:1646  */
    {(yyval).trad = (yyvsp[0]).trad + "\n";  }
#line 1503 "plp4.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 114 "plp4.y" /* yacc.c:1646  */
    {(yyval).trad = "print" + tipoMayus((yyvsp[0]).atributos.tipo) + "(" + (yyvsp[0]).trad + ");\n";   }
#line 1509 "plp4.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 115 "plp4.y" /* yacc.c:1646  */
    { (yyval).trad = "_" + (yyvsp[-2]).trad;   (yyval).atributos.tipo = (yyvsp[-2]).atributos.tipo;   tsActual = new TablaSimbolos(tsActual); }
#line 1515 "plp4.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 115 "plp4.y" /* yacc.c:1646  */
    {tsActual = tsActual->getPadre();  (yyval).trad = "_" + (yyvsp[-4]).trad; (yyval).atributos.tipo = (yyvsp[-4]).atributos.tipo; }
#line 1521 "plp4.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 115 "plp4.y" /* yacc.c:1646  */
    {(yyval).trad = "if(" + (yyvsp[-4]).trad + "){\n" + (yyvsp[-2]).trad + "\n}\n" + (yyvsp[0]).trad;   }
#line 1527 "plp4.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 117 "plp4.y" /* yacc.c:1646  */
    {(yyval).trad = "_" + (yyvsp[-1]).trad; (yyval).atributos.tipo = (yyvsp[-1]).atributos.tipo; tsActual = new TablaSimbolos(tsActual); }
#line 1533 "plp4.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 117 "plp4.y" /* yacc.c:1646  */
    {tsActual = tsActual->getPadre();}
#line 1539 "plp4.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 117 "plp4.y" /* yacc.c:1646  */
    { (yyval).trad = "{\n" + (yyvsp[-2]).trad + "\n}\n"; }
#line 1545 "plp4.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 119 "plp4.y" /* yacc.c:1646  */
    {(yyval).atributos.tipo = (yyvsp[-1]).atributos.tipo; (yyval).trad = (yyvsp[-1]).trad; tsActual = new TablaSimbolos(tsActual);}
#line 1551 "plp4.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 119 "plp4.y" /* yacc.c:1646  */
    {tsActual = tsActual->getPadre(); }
#line 1557 "plp4.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 119 "plp4.y" /* yacc.c:1646  */
    {(yyval).trad = "else{\n" + (yyvsp[-2]).trad + "\n}\n"; }
#line 1563 "plp4.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 121 "plp4.y" /* yacc.c:1646  */
    {(yyval).trad = ""; }
#line 1569 "plp4.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 124 "plp4.y" /* yacc.c:1646  */
    {  struct Simbolo simb1; 
            simb1.nombre = (yyvsp[(-1) - (2)]).lexema; 
            simb1.tipo = parserTipo((yyvsp[0]).trad , (yyvsp[(-1) - (2)]).lexema , (yyvsp[(-1) - (2)]).fila , (yyvsp[(-1) - (2)]).col);  
            simb1.nomtrad = (yyvsp[(-1) - (2)]).lexema + (yyvsp[-2]).trad;  
            if(!tsActual->newSymb(simb1))errorSemantico(ERRYADECL,(yyvsp[(-1) - (2)]).lexema,(yyvsp[(-1) - (2)]).fila,(yyvsp[(-1) - (2)]).col);
            (yyval).trad = (yyvsp[0]).trad + " " + (yyvsp[(-1) - (2)]).lexema + (yyvsp[-2]).trad + "; ";
             }
#line 1581 "plp4.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 131 "plp4.y" /* yacc.c:1646  */
    {(yyval).trad = (yyvsp[(-1) - (2)]).lexema; (yyval).lexema = (yyvsp[(-1) - (2)]).lexema; (yyval).fila = (yyvsp[(-1) - (2)]).fila; (yyval).col = (yyvsp[(-1) - (2)]).col;  }
#line 1587 "plp4.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 131 "plp4.y" /* yacc.c:1646  */
    {
        (yyval).tipo = (yyvsp[-2]).tipo;
        (yyval).atributos.tipo = (yyvsp[-2]).atributos.tipo;
        bool entrado = false;
        if(tsActual->searchSymb((yyvsp[(-1) - (4)]).lexema)!= NULL){
            if(tsActual->searchSymb((yyvsp[(-1) - (4)]).lexema)->tipo == ENTEROT && parserTipo((yyvsp[-2]).atributos.tipo , (yyvsp[(-1) - (4)]).lexema , (yyvsp[(-1) - (4)]).fila , (yyvsp[(-1) - (4)]).col) == REALT ) errorSemantico(ERRNOENTERO,(yyvsp[-3]).lexema,(yyvsp[-3]).fila,(yyvsp[-3]).col);
            (yyval).trad =  (yyvsp[0]).trad +  tsActual->searchSymb((yyvsp[(-1) - (4)]).lexema)->nomtrad + " = " + (yyvsp[-2]).trad + ";" ;
            entrado = true;
        }
        struct Simbolo simb1; 
        simb1.nombre = (yyvsp[(-1) - (4)]).lexema; 
        simb1.tipo = parserTipo((yyvsp[-2]).atributos.tipo , (yyvsp[(-1) - (4)]).lexema , (yyvsp[(-1) - (4)]).fila , (yyvsp[(-1) - (4)]).col);  
        simb1.nomtrad = (yyvsp[(-1) - (4)]).lexema + (yyvsp[-4]).trad; 
        if(entrado == false){
            if( !tsActual->newSymb(simb1) ){    
                if(tsActual->searchSymb((yyvsp[(-1) - (4)]).lexema)->tipo == ENTEROT &&  parserTipo((yyvsp[-2]).atributos.tipo , (yyvsp[(-1) - (4)]).lexema , (yyvsp[(-1) - (4)]).fila , (yyvsp[(-1) - (4)]).col) == REALT ) errorSemantico(ERRNOENTERO,(yyvsp[-3]).lexema,(yyvsp[-3]).fila,(yyvsp[-3]).col);
                (yyval).trad =  (yyvsp[0]).trad +  tsActual->searchSymb((yyvsp[(-1) - (4)]).lexema)->nomtrad + " = " + (yyvsp[-2]).trad + ";" ;  
            }else{      
                if((yyvsp[0]).trad.length() > 1 ) errorSemantico(ERRVOID,(yyvsp[(-1) - (4)]).lexema,(yyvsp[(-1) - (4)]).fila,(yyvsp[(-1) - (4)]).col); 
                (yyval).trad =   (yyvsp[-2]).atributos.tipo + " " + (yyvsp[(-1) - (4)]).lexema + (yyvsp[-4]).trad + "; " +  (yyvsp[(-1) - (4)]).lexema + (yyvsp[-4]).trad  + " = " + (yyvsp[-2]).trad + ";" ;
            }
        }
        
    }
#line 1616 "plp4.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 155 "plp4.y" /* yacc.c:1646  */
    {
        struct Simbolo simb1; 
        simb1.nombre = (yyvsp[(-1) - (0)]).lexema; 
        
        simb1.tipo = parserTipo((yyvsp[0]).atributos.tipo , (yyvsp[(-1) - (0)]).lexema , (yyvsp[(-1) - (0)]).fila , (yyvsp[(-1) - (0)]).col);  
        simb1.nomtrad = (yyvsp[(-1) - (0)]).lexema + (yyvsp[0]).trad;  
        if( !tsActual->newSymb(simb1) )  errorSemantico(ERRYADECL,(yyvsp[(-1) - (0)]).lexema,(yyvsp[(-1) - (0)]).fila,(yyvsp[(-1) - (0)]).col);
        (yyval).tipo = (yyvsp[0]).tipo;
        (yyval).trad = (yyvsp[0]).atributos.tipo + " " + (yyvsp[(-1) - (0)]).lexema + (yyvsp[0]).trad + ";";
    }
#line 1631 "plp4.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 166 "plp4.y" /* yacc.c:1646  */
    {if(tsActual->searchSymb((yyvsp[-1]).trad) == NULL ){
        errorSemantico(ERRVOID,(yyvsp[-1]).lexema,(yyvsp[-1]).fila,(yyvsp[-1]).col); } }
#line 1638 "plp4.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 167 "plp4.y" /* yacc.c:1646  */
    { (yyval).tipo = (yyvsp[0]).tipo; (yyval).trad = "if(" + (yyvsp[0]).trad + ")";  }
#line 1644 "plp4.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 168 "plp4.y" /* yacc.c:1646  */
    {(yyval).trad = ""; }
#line 1650 "plp4.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 170 "plp4.y" /* yacc.c:1646  */
    {  
                (yyval).tipo = parserTipo(tipoShake((yyvsp[-2]).atributos.tipo , (yyvsp[0]).atributos.tipo) , (yyvsp[-2]).lexema , (yyvsp[-2]).col , (yyvsp[-2]).fila);
                (yyval).atributos.tipo = tipoShake((yyvsp[-2]).atributos.tipo , (yyvsp[0]).atributos.tipo); 
                (yyval).trad = (yyvsp[-2]).trad + (yyvsp[-1]).lexema + (yyvsp[0]).trad; }
#line 1659 "plp4.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 174 "plp4.y" /* yacc.c:1646  */
    { 
        (yyval).atributos.tipo = (yyvsp[0]).atributos.tipo; 
        (yyval).tipo = (yyvsp[0]).tipo; 
        (yyval).trad = (yyvsp[0]).trad; }
#line 1668 "plp4.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 179 "plp4.y" /* yacc.c:1646  */
    { 
                (yyval).atributos.tipo =   tipoShake((yyvsp[-2]).atributos.tipo , (yyvsp[-2]).atributos.tipo); 
                (yyval).tipo = parserTipo( tipoShake((yyvsp[-2]).atributos.tipo , (yyvsp[0]).atributos.tipo) , (yyvsp[-2]).lexema , (yyvsp[-2]).col , (yyvsp[-2]).fila);
                
                (yyval).trad = (yyvsp[-2]).trad + " " + (yyvsp[-1]).lexema + " " + (yyvsp[0]).trad; 
                
    }
#line 1680 "plp4.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 186 "plp4.y" /* yacc.c:1646  */
    { 
        (yyval).atributos.tipo = (yyvsp[0]).atributos.tipo;
        (yyval).tipo = (yyvsp[0]).tipo; 
        (yyval).trad = (yyvsp[0]).trad; 
        }
#line 1690 "plp4.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 192 "plp4.y" /* yacc.c:1646  */
    {(yyval).tipo =ENTEROT; 
            (yyval).atributos.tipo = "int";
            (yyval).trad = (yyvsp[0]).lexema; }
#line 1698 "plp4.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 195 "plp4.y" /* yacc.c:1646  */
    {
        (yyval).atributos.tipo = "float";
        (yyval).tipo = REALT; 
        (yyval).trad = (yyvsp[0]).lexema;}
#line 1707 "plp4.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 199 "plp4.y" /* yacc.c:1646  */
    {
        (yyval).tipo = (yyvsp[-2]).tipo; 
        (yyval).atributos.tipo = (yyvsp[-2]).atributos.tipo;
        (yyval).trad = "(" + (yyvsp[-1]).trad + ")"; }
#line 1716 "plp4.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 203 "plp4.y" /* yacc.c:1646  */
    {
        if( tsActual->searchSymb((yyvsp[0]).lexema) == NULL) errorSemantico(ERRNODECL,(yyvsp[0]).lexema,(yyvsp[0]).fila,(yyvsp[0]).col);
        
        if(tsActual->searchSymb((yyvsp[0]).lexema)->tipo != ENTEROT && tsActual->searchSymb((yyvsp[0]).lexema)->tipo != REALT ) errorSemantico(ERRNOSIMPLE,(yyvsp[0]).lexema,(yyvsp[0]).fila,(yyvsp[0]).col);
        (yyval).tipo = tsActual->searchSymb((yyvsp[0]).lexema)->tipo;
        if((yyval).tipo == ENTEROT) (yyval).atributos.tipo = "int";
        if((yyval).tipo == REALT) (yyval).atributos.tipo = "float"; 
        (yyval).trad =  tsActual->searchSymb((yyvsp[0]).lexema)->nomtrad;
    }
#line 1730 "plp4.tab.c" /* yacc.c:1646  */
    break;


#line 1734 "plp4.tab.c" /* yacc.c:1646  */
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
#line 213 "plp4.y" /* yacc.c:1906  */


string tipoMayus(string tipo){
    
    if(tipo == "int") return "Int"; 
    return "Float"; 
}

int parserTipo(string tipo , char * lexema, int fila, int columna  ){
    if (tipo =="int"  ) return ENTEROT; 
    if (tipo == "float"  ) return REALT; 
    
    if(tipo == "void" )errorSemantico(ERRVOID,lexema,fila,columna);
    return -1; 
}

string tipoShake(string type1,  string type2){
    if(type1 == "float" || type2 == "float" ) return "float"; 
    return "int";
}

/// ---------- Errores semánticos ---------------------------------

void errorSemantico(int nerror,char *lexema,int fila,int columna)
{
    fprintf(stderr,"Error semantico (%d,%d): en '%s', ",fila,columna,lexema);
    switch (nerror) {
      case ERRYADECL: fprintf(stderr,"ya existe en este ambito\n");
         break;
      case ERRNODECL: fprintf(stderr,"no ha sido declarado\n");
         break;
      case ERRNOSIMPLE: fprintf(stderr,"debe ser de tipo entero o real\n");
         break;
      case ERRVOID: fprintf(stderr,"debe declararse con tipo entero o real\n");
         break;
      case ERRNOENTERO: fprintf(stderr,"la expresión debe ser de tipo entero\n");
         break;
    }
    exit(-1);
}



/// ---------- Errores léxicos y sintácticos ----------------------
void msgError(int nerror,int fila,int col,const char *s)
{
     switch (nerror) {
         case ERRLEXICO: fprintf(stderr,"Error lexico (%d,%d): caracter '%s' incorrecto\n",fila,col,s);
            break;
         case ERRSINT: fprintf(stderr,"Error sintactico (%d,%d): en '%s'\n",fila,col,s);
            break;
         case ERREOF: fprintf(stderr,"Error sintactico: fin de fichero inesperado\n");
            break;
         case ERRLEXEOF: fprintf(stderr,"Error lexico: fin de fichero inesperado\n");
            break;
     }
        
     exit(1);
}

int yyerror(char *s)
{
    if (findefichero) 
    {
       msgError(ERREOF,-1,-1,"");
    }
    else
    {  
       msgError(ERRSINT,fila,col-strlen(yytext),yytext);
    }
    return 0;
}


int main(int argc,char *argv[])
{
    FILE *fent;

    if (argc==2)
    {
        fent = fopen(argv[1],"rt");
        if (fent)
        {
            yyin = fent;
            yyparse();
            fclose(fent);
        }
        else
            fprintf(stderr,"No puedo abrir el fichero\n");
    }
    else
        fprintf(stderr,"Uso: ejemplo <nombre de fichero>\n");
}
