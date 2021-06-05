/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 30 "plp5.y"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;
#include "comun.h"
#include "TablaSimbolos.h"
#include "TablaTipos.h"

extern int col, fila, findefichero;

extern int yylex();
extern char *yytext;
extern FILE *yyin;


int yyerror(char *s);
void errorSemantico(int nerror,char *lexema,int fila,int columna);
int mietiquetaact = 0;
int nuevaEtiqueta();
TablaSimbolos *tsActual = new TablaSimbolos(NULL); 
TablaTipos *ttActual = new TablaTipos(); 
string tipoMayus(string tipo);
string tipoShake(string  type1,  string type2);
//  int parserTipo(string tipo , char * lexema, int fila, int columna  );
int ctemp = 16000;
int cvar = 0;  
int nuevaTemp(char *lexema, int fila, int columna);
int nuevaVar(unsigned tam ,char *lexema, int fila, int columna);


#line 104 "plp5.tab.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_PLP5_TAB_H_INCLUDED
# define YY_YY_PLP5_TAB_H_INCLUDED
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
    cori = 258,
    cord = 259,
    fortok = 260,
    whiletok = 261,
    coma = 262,
    readtok = 263,
    var = 264,
    arraytok = 265,
    pari = 266,
    pard = 267,
    dosp = 268,
    asig = 269,
    pyc = 270,
    opas = 271,
    opmd = 272,
    fn = 273,
    endfn = 274,
    inttok = 275,
    real = 276,
    let = 277,
    iftok = 278,
    elsetok = 279,
    fi = 280,
    print = 281,
    blq = 282,
    fblq = 283,
    id = 284,
    numint = 285,
    numreal = 286,
    eof = 287
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

#endif /* !YY_YY_PLP5_TAB_H_INCLUDED  */



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
typedef yytype_int8 yy_state_t;

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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
#define YYLAST   90

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  33
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  52
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  94

#define YYUNDEFTOK  2
#define YYMAXUTOK   287


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

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
      25,    26,    27,    28,    29,    30,    31,    32
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    66,    66,    74,    79,    84,    90,    96,   103,   103,
     109,   114,   117,   121,   126,   136,   149,   149,   153,   153,
     157,   166,   166,   166,   175,   189,   192,   196,   196,   196,
     204,   209,   216,   223,   230,   230,   253,   253,   267,   273,
     273,   296,   302,   309,   317,   323,   330,   345,   347,   347,
     345,   354,   362
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "cori", "cord", "fortok", "whiletok",
  "coma", "readtok", "var", "arraytok", "pari", "pard", "dosp", "asig",
  "pyc", "opas", "opmd", "fn", "endfn", "inttok", "real", "let", "iftok",
  "elsetok", "fi", "print", "blq", "fblq", "id", "numint", "numreal",
  "eof", "$accept", "S", "Fun", "Stype", "Type", "Dim", "@1", "Cod", "I",
  "@2", "@3", "$@4", "@5", "Ip", "Blq", "@6", "$@7", "It", "Ifa", "E",
  "@8", "@9", "T", "@10", "F", "Ref", "@11", "@12", "$@13", "LExpr", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287
};
# endif

#define YYPACT_NINF (-37)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-48)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -12,   -10,    29,   -37,    22,   -37,    43,    17,   -37,    19,
      28,    32,    28,    19,    19,   -37,   -11,   -37,   -37,    34,
      19,   -37,    55,   -37,   -37,     5,    42,   -37,   -37,   -37,
      49,    50,     5,    51,    17,    17,   -37,    52,    30,     7,
      65,   -37,   -37,   -37,   -37,    -5,   -37,    19,    27,   -37,
      54,   -37,    40,   -37,    42,   -37,     7,     7,    33,   -37,
     -37,   -37,   -37,     1,    17,   -37,   -37,    45,    58,    19,
      42,   -37,    44,    19,   -37,    53,   -37,    46,    51,    68,
      70,   -37,    51,   -37,   -37,    19,    75,   -37,    17,    51,
     -37,    44,   -37,   -37
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     0,     1,     0,     0,    21,     0,
       0,     0,     0,     0,     0,    27,     0,    12,    13,     0,
       0,    36,    46,    42,    43,     0,    38,    41,    45,    18,
      31,     0,     0,    16,     0,     0,     3,     0,     0,     0,
       0,    34,    20,    39,    19,     0,    15,     0,     0,    17,
      28,    11,     0,    44,    37,    48,     0,     0,     0,     4,
       5,     6,    30,    33,     0,    26,    24,     0,     0,     0,
      35,    40,     0,     0,    14,     0,    29,     0,    52,    49,
      10,     7,    32,    25,    22,     0,     0,     8,     0,    51,
      50,     0,    23,     9
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -37,   -37,   -37,    23,   -37,    -9,   -37,    56,   -23,   -37,
     -37,   -37,   -37,   -37,   -37,   -37,   -37,   -37,   -37,   -13,
     -37,   -37,   -36,   -37,    26,    35,   -37,   -37,   -37,   -37
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,    61,    62,    81,    91,    16,    17,    49,
      44,    19,    88,    66,    18,    34,    67,    46,    74,    25,
      56,    39,    26,    57,    27,    28,    40,    69,    86,    79
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      32,    33,    42,    54,    35,    58,     1,    38,    36,    48,
       8,     9,    51,    10,    11,    59,    60,    41,    20,     4,
      70,    41,     8,     9,    73,    10,    11,    12,    13,     5,
      20,    14,    15,     6,    63,    21,    22,    23,    24,    12,
      13,    75,    53,    14,    15,    29,    41,    31,    22,    23,
      24,    64,    65,    59,    60,     7,    78,    22,   -47,    43,
      82,    30,    45,    37,    47,    92,    52,    41,    55,    35,
      68,    77,    89,    76,    80,    85,    84,    87,    83,    90,
       0,    72,    93,    71,     0,     0,     0,     0,     0,     0,
      50
};

static const yytype_int8 yycheck[] =
{
      13,    14,    25,    39,    15,    10,    18,    20,    19,    32,
       5,     6,    35,     8,     9,    20,    21,    16,    11,    29,
      56,    16,     5,     6,    23,     8,     9,    22,    23,     0,
      11,    26,    27,    11,    47,    16,    29,    30,    31,    22,
      23,    64,    12,    26,    27,    10,    16,    12,    29,    30,
      31,    24,    25,    20,    21,    12,    69,    29,     3,    17,
      73,    29,    13,    29,    14,    88,    14,    16,     3,    15,
      30,    13,    85,    28,    30,     7,    30,     7,    25,     4,
      -1,    58,    91,    57,    -1,    -1,    -1,    -1,    -1,    -1,
      34
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    18,    34,    35,    29,     0,    11,    12,     5,     6,
       8,     9,    22,    23,    26,    27,    40,    41,    47,    44,
      11,    16,    29,    30,    31,    52,    55,    57,    58,    58,
      29,    58,    52,    52,    48,    15,    19,    29,    52,    54,
      59,    16,    41,    17,    43,    13,    50,    14,    41,    42,
      40,    41,    14,    12,    55,     3,    53,    56,    10,    20,
      21,    36,    37,    52,    24,    25,    46,    49,    30,    60,
      55,    57,    36,    23,    51,    41,    28,    13,    52,    62,
      30,    38,    52,    25,    30,     7,    61,     7,    45,    52,
       4,    39,    41,    38
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    33,    34,    35,    36,    36,    37,    37,    39,    38,
      38,    40,    40,    41,    41,    41,    42,    41,    43,    41,
      41,    44,    45,    41,    41,    46,    46,    48,    49,    47,
      50,    50,    51,    51,    53,    52,    54,    52,    52,    56,
      55,    55,    57,    57,    57,    57,    58,    59,    60,    61,
      58,    62,    62
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     6,     1,     1,     1,     3,     0,     4,
       1,     3,     1,     1,     5,     3,     0,     3,     0,     3,
       3,     0,     0,     9,     4,     3,     1,     0,     0,     5,
       2,     0,     2,     0,     0,     4,     0,     3,     1,     0,
       4,     1,     1,     1,     3,     1,     1,     0,     0,     0,
       7,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
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
  case 2:
#line 66 "plp5.y"
       { 
    /* Primero, comprobaremos que después del programa no hay ningún token más*/
    int tk = yylex(); 
    if(tk!= 0) yyerror(""); 
    yyval.trad = yyvsp[0].trad; 
    cout<<yyval.trad; 
}
#line 1427 "plp5.tab.c"
    break;

  case 3:
#line 74 "plp5.y"
                              {
    int etiqact = nuevaEtiqueta(); 
    yyval.trad = "L" + to_string(etiqact) + ":\n"
    + yyvsp[-1].trad; 
}
#line 1437 "plp5.tab.c"
    break;

  case 4:
#line 79 "plp5.y"
              {
        yyval.tipo = ENTERO; 
        yyval.atributos.tipo= "int"; 
        yyval.tam = 1; 
    }
#line 1447 "plp5.tab.c"
    break;

  case 5:
#line 84 "plp5.y"
           {
        yyval.tipo = REAL; 
        yyval.atributos.tipo = "float"; 
        yyval.tam = 1; 
    }
#line 1457 "plp5.tab.c"
    break;

  case 6:
#line 90 "plp5.y"
            {
    yyval.tipo = yyvsp[0].tipo; 
    yyval.atributos.tipo = yyvsp[0].atributos.tipo; 
    yyval.tam = yyvsp[0].tam; 
    
    }
#line 1468 "plp5.tab.c"
    break;

  case 7:
#line 96 "plp5.y"
                         {
        yyval.tam = yyvsp[-1].tam * yyvsp[0].tam; 
        yyval.tipo = ttActual->nuevoTipoArray(yyval.tam , yyvsp[0].tipo);
        
        cout<<yyval.tam<<endl;
    }
#line 1479 "plp5.tab.c"
    break;

  case 8:
#line 103 "plp5.y"
                 {yyval.tipo = yyvsp[(-2) - (2)].tipo; }
#line 1485 "plp5.tab.c"
    break;

  case 9:
#line 103 "plp5.y"
                                            {
        yyval.tam= yyvsp[-3].tam * yyvsp[0].tam;
        yyval.tipo = ttActual->nuevoTipoArray(yyval.tam , yyvsp[0].tipo); 
        
        cout<<yyval.tam<<endl;
    }
#line 1496 "plp5.tab.c"
    break;

  case 10:
#line 109 "plp5.y"
            {
        yyval.tam = yyvsp[-1].tam;
        yyval.tipo = ttActual->nuevoTipoArray(yyval.tam , yyvsp[-1].tipo); 
    }
#line 1505 "plp5.tab.c"
    break;

  case 11:
#line 114 "plp5.y"
               {
    yyval.trad = yyvsp[-2].trad + yyvsp[0].trad;
    }
#line 1513 "plp5.tab.c"
    break;

  case 12:
#line 117 "plp5.y"
        {
        yyval.trad = yyvsp[0].trad;
    }
#line 1521 "plp5.tab.c"
    break;

  case 13:
#line 121 "plp5.y"
       {
    yyval.trad = yyvsp[0].trad; 
    yyval.atributos.tipo = yyvsp[0].atributos.tipo; 
    yyval.tipo = yyvsp[0].tipo;
    }
#line 1531 "plp5.tab.c"
    break;

  case 14:
#line 126 "plp5.y"
                         {
        
        int temp = nuevaTemp(yyvsp[-4].lexema , yyvsp[-4].fila, yyvsp[-4].col); 
        yyval.trad = 
        yyvsp[0].trad +   
        "mov " + to_string(yyvsp[0].dir) + " " + to_string(temp) + "\n" +
        "mov" + to_string(temp) + " " + to_string(yyvsp[-4].dir) + "\n" +  
        yyvsp[0].atributos.etiqueta;
        
    }
#line 1546 "plp5.tab.c"
    break;

  case 15:
#line 136 "plp5.y"
                {
        struct Simbolo simb1; 
        simb1.nombre = yyvsp[-1].lexema;
        simb1.tipo = yyvsp[0].tipo;
        simb1.dir = yyvsp[-1].dir;
        simb1.tam = yyvsp[0].tam;
        if(!tsActual->newSymb(simb1))  errorSemantico(ERR_YADECL,yyvsp[-1].lexema,yyvsp[-1].fila,yyvsp[-1].col);
        yyval.dir = nuevaVar(yyvsp[0].tam , yyvsp[-1].lexema, yyvsp[-1].fila, yyvsp[-1].col); 
        yyval.trad = ""; 
        yyval.tipo = yyvsp[0].tipo; 
        yyval.dir = yyvsp[-1].dir; 
        yyval.tam = yyval.tam;
    }
#line 1564 "plp5.tab.c"
    break;

  case 16:
#line 149 "plp5.y"
              {if(yyvsp[0].tipo == REAL ) yyval.trad = "wri "; 
                if(yyvsp[0].tipo == ENTERO ) yyval.trad = "wrr ";   }
#line 1571 "plp5.tab.c"
    break;

  case 17:
#line 150 "plp5.y"
                                                             {
        yyval.trad = yyvsp[0].trad  + to_string( yyvsp[-1].dir) + " wrl\n";   
    }
#line 1579 "plp5.tab.c"
    break;

  case 18:
#line 153 "plp5.y"
                  {if(yyvsp[0].tipo == ENTERO ) yyval.trad = "rdi "; 
                if(yyvsp[0].tipo == REAL) yyval.trad = "rdr ";  }
#line 1586 "plp5.tab.c"
    break;

  case 19:
#line 154 "plp5.y"
                                                         {
        yyval.trad = yyvsp[0].trad + to_string(yyvsp[-1].dir); 
    }
#line 1594 "plp5.tab.c"
    break;

  case 20:
#line 157 "plp5.y"
                   {
        int etiqact1 = nuevaEtiqueta();
        int etiqact2 = nuevaEtiqueta(); 
        yyval.trad = "L" + to_string(etiqact1)+ ":\n"+
        yyvsp[-1].trad + "mov " + to_string(yyvsp[-1].dir) + " A\n" 
        + "jz " + "L" + to_string(etiqact2) + "\n" + 
        yyvsp[0].trad + "jmp L" + to_string(etiqact1) + "\n" + 
        "L" + to_string(etiqact2) + ":\n";   
    }
#line 1608 "plp5.tab.c"
    break;

  case 21:
#line 166 "plp5.y"
             {tsActual = new TablaSimbolos(tsActual); }
#line 1614 "plp5.tab.c"
    break;

  case 22:
#line 166 "plp5.y"
                                                                                   {
         if(yyvsp[-3].numint > yyvsp[-1].numint) yyval.trad = "subi "; 
        if(yyvsp[-3].numint < yyvsp[-1].numint) yyval.trad = "addi "; }
#line 1622 "plp5.tab.c"
    break;

  case 23:
#line 169 "plp5.y"
          {  
            int etiqact1 = nuevaEtiqueta(); 
            int var1 = nuevaVar(1,yyvsp[-6].lexema , yyvsp[-6].fila , yyvsp[-6].col ); 
            yyval.trad = "L" + to_string(etiqact1) + ":\n mov " + yyvsp[-4].lexema + " " + to_string(var1) + "\n" +  "mov " + to_string(var1) + " A\n" + yyvsp[-1].trad + " #1\n" + "mov A" + to_string(var1) + "\n subi" + " #"+yyvsp[-2].lexema + "\n"+ "jmpz L" + to_string(etiqact1) + "\n"; 
            tsActual = tsActual->padre;
    }
#line 1633 "plp5.tab.c"
    break;

  case 24:
#line 175 "plp5.y"
                   {
        int etiqact1 = nuevaEtiqueta(); 
        int etiqact2 = nuevaEtiqueta();
        yyval.trad = yyvsp[-2].trad + 
        "mov " + to_string(yyvsp[-2].dir) + " A\n" +
         "jz L" + to_string(etiqact1) + "\n" 
         + yyvsp[-1].trad 
         + "jmpL" + to_string(etiqact2) + "\n" +
         + 
         "L" + to_string(etiqact1)+":\n"
         +yyvsp[0].trad +
         "L" + to_string(etiqact2) + ":\n";
}
#line 1651 "plp5.tab.c"
    break;

  case 25:
#line 189 "plp5.y"
                 {
    yyval.trad = yyvsp[-1].trad; 
    }
#line 1659 "plp5.tab.c"
    break;

  case 26:
#line 192 "plp5.y"
         {
        yyval.trad = ""; 
    }
#line 1667 "plp5.tab.c"
    break;

  case 27:
#line 196 "plp5.y"
         {tsActual = new TablaSimbolos(tsActual); }
#line 1673 "plp5.tab.c"
    break;

  case 28:
#line 196 "plp5.y"
                                                        {tsActual = tsActual->getPadre();}
#line 1679 "plp5.tab.c"
    break;

  case 29:
#line 196 "plp5.y"
                                                                                               {
    
    yyval.trad = yyvsp[-3].trad;

    
}
#line 1690 "plp5.tab.c"
    break;

  case 30:
#line 204 "plp5.y"
              {
    yyval.tipo = yyvsp[0].tipo; 
    yyval.trad = ""; 
    yyval.tam  = yyvsp[0].tam; 
    }
#line 1700 "plp5.tab.c"
    break;

  case 31:
#line 209 "plp5.y"
      {
        yyval.trad =""; 
        yyval.tipo = ENTERO;
        yyval.tam = 1;

    }
#line 1711 "plp5.tab.c"
    break;

  case 32:
#line 216 "plp5.y"
            {
    int etiq = nuevaEtiqueta();
    yyval.trad = "mov " + to_string(yyvsp[0].dir) + " A\n" + "jz" + "L" + to_string(etiq) + "\n";
    yyval.dir = yyvsp[0].dir;
    yyval.atributos.etiqueta = "L" + to_string(etiq) + ":\n";

    }
#line 1723 "plp5.tab.c"
    break;

  case 33:
#line 223 "plp5.y"
      {
        yyval.trad ="";
        yyval.atributos.etiqueta = ""; 

    }
#line 1733 "plp5.tab.c"
    break;

  case 34:
#line 230 "plp5.y"
          {if(strcmp(yyvsp[0].lexema, "+") ){yyval.trad = "add"; }
            if(strcmp(yyvsp[0].lexema ,"-")) {yyval.trad == "sub";}}
#line 1740 "plp5.tab.c"
    break;

  case 35:
#line 231 "plp5.y"
                                                              {
    int tmp;
    tmp = nuevaTemp(yyvsp[-3].lexema, yyvsp[-3].fila, yyvsp[-3].col);
    yyval.dir = tmp; 
    if(yyvsp[-3].tipo == ENTERO && yyvsp[0].tipo == ENTERO ){
        yyval.trad = yyvsp[-3].trad + yyvsp[0].trad + "mov " + to_string(yyvsp[-3].dir) + " A" + yyvsp[-1].trad +"i " + to_string(yyvsp[0].dir) + "mov A " + to_string(tmp); 
        yyval.tipo = ENTERO;
        yyval.atributos.tipo = "int"; 
    }
    else if(yyvsp[-3].tipo == REAL && yyvsp[0].tipo == ENTERO){
        int tmpcp; 
        tmpcp = nuevaTemp(yyvsp[-3].lexema, yyvsp[-3].fila, yyvsp[-3].col);
        yyval.trad = yyvsp[-3].trad + yyvsp[0].trad + "mov " + to_string(yyvsp[0].dir) + " A\n"+"itor\n" + "mov A " + to_string(tmpcp) + "\n" 
        + "mov " + to_string(yyvsp[-3].dir) + " A" + "\n" + yyvsp[-1].trad + "r " + to_string(tmpcp) + "\nmov A " + to_string(tmp); 
        yyval.tipo = REAL; 
        yyval.atributos.tipo = "float"; 
    }else if (yyvsp[-3].tipo == REAL && yyvsp[0].tipo == REAL){
        yyval.trad = yyvsp[-3].trad + yyvsp[0].trad + "mov " + to_string(yyvsp[-3].dir) + " A\n" + yyvsp[-1].trad + "r " + to_string(yyvsp[0].dir) + "\nmov A " + to_string(tmp); 
        yyval.tipo = REAL; 
        yyval.atributos.tipo = "float";  
    }
    }
#line 1767 "plp5.tab.c"
    break;

  case 36:
#line 253 "plp5.y"
           {if( strcmp(yyvsp[0].lexema,"+") ){yyval.trad = "add"; }
            if(strcmp( yyvsp[0].lexema ,"-")) {yyval.trad == "sub";}}
#line 1774 "plp5.tab.c"
    break;

  case 37:
#line 254 "plp5.y"
                                                               {

        int tmp = nuevaTemp(yyvsp[-2].lexema, yyvsp[-2].fila, yyvsp[-2].col); 
        if(yyvsp[0].tipo == ENTERO){
            yyval.trad = yyvsp[-1].trad + "i " + to_string(yyvsp[0].dir)+ "mov A "  + to_string(tmp); 
            yyval.tipo = ENTERO; 
            yyval.atributos.tipo == "int";  
        }else if(yyvsp[0].tipo == REAL ){
            yyval.trad = yyvsp[-1].trad + "r " + to_string(yyvsp[0].dir)+ "mov A "  + to_string(tmp);  
            yyval.tipo = REAL; 
            yyval.atributos.tipo = "float"; 
        }
    }
#line 1792 "plp5.tab.c"
    break;

  case 38:
#line 267 "plp5.y"
        {
        yyval.atributos.tipo = yyvsp[0].atributos.tipo; 
        yyval.tipo = yyvsp[0].tipo; 
        yyval.trad = yyvsp[0].trad; 
    }
#line 1802 "plp5.tab.c"
    break;

  case 39:
#line 273 "plp5.y"
          {if(strcmp(yyvsp[0].lexema,"*")){yyval.trad = "mul"; }
           if(strcmp(yyvsp[0].lexema ,"/")){yyval.trad = "div";}}
#line 1809 "plp5.tab.c"
    break;

  case 40:
#line 275 "plp5.y"
            {
        int tmp = nuevaTemp(yyvsp[-3].lexema, yyvsp[-3].fila, yyvsp[-3].col);
        yyval.dir = tmp; 
        if(yyvsp[-3].tipo == ENTERO && yyvsp[0].tipo == ENTERO ){
            yyval.trad = yyvsp[-3].trad + yyvsp[0].trad + "mov " + to_string(yyvsp[-3].dir) + " A" + yyvsp[-1].trad +"i " + to_string(yyvsp[0].dir) + "mov A " + to_string(tmp); 
            yyval.tipo = ENTERO;
            yyval.atributos.tipo = "int"; 
        }
        else if(yyvsp[-3].tipo == REAL && yyvsp[0].tipo == ENTERO){
            
            int tmpcp = nuevaTemp(yyvsp[-3].lexema, yyvsp[-3].fila, yyvsp[-3].col);
            yyval.trad = yyvsp[-3].trad + yyvsp[0].trad + "mov " + to_string(yyvsp[0].dir) + " A\n"+"itor\n" + "mov A " + to_string(tmpcp) + "\n" 
            + "mov " + to_string(yyvsp[-3].dir) + " A" + "\n" + yyvsp[-1].trad + "r " + to_string(tmpcp) + "\nmov A " + to_string(tmp); 
            yyval.tipo = REAL; 
            yyval.atributos.tipo = "float"; 
        }else if (yyvsp[-3].tipo == REAL && yyvsp[0].tipo == REAL){
            yyval.trad = yyvsp[-3].trad + yyvsp[0].trad + "mov " + to_string(yyvsp[-3].dir) + " A\n" + yyvsp[-1].trad + "r " + to_string(yyvsp[0].dir) + "\nmov A " + to_string(tmp); 
            yyval.tipo = REAL; 
            yyval.atributos.tipo = "float";  
        }
    }
#line 1835 "plp5.tab.c"
    break;

  case 41:
#line 296 "plp5.y"
        {
        yyval.tipo = yyvsp[0].tipo;
        yyval.trad = yyvsp[0].trad;
    }
#line 1844 "plp5.tab.c"
    break;

  case 42:
#line 302 "plp5.y"
          {yyval.tipo = ENTERO; 
        yyval.atributos.tipo = "int"; 
        int temp = nuevaTemp(yyvsp[0].lexema , yyvsp[0].fila, yyvsp[0].col); 
        yyval.trad = "mov #" + string(yyvsp[0].lexema) +  to_string(temp) + "\n"; 
        yyval.dir = temp; 
        }
#line 1855 "plp5.tab.c"
    break;

  case 43:
#line 309 "plp5.y"
              {
        yyval.tipo = REAL; 
        yyval.atributos.tipo = "real"; 
        int temp = nuevaTemp(yyvsp[0].lexema , yyvsp[0].fila, yyvsp[0].col); 
        yyval.trad = "mov $" + string(yyvsp[0].lexema) +  to_string(temp) + "\n";
        yyval.dir = temp; 

    }
#line 1868 "plp5.tab.c"
    break;

  case 44:
#line 317 "plp5.y"
                  {
        yyval.tipo = yyvsp[-1].tipo; 
        yyval.atributos.tipo = yyvsp[-1].atributos.tipo; 
        yyval.trad = yyvsp[-1].trad; 
        yyval.dir = yyvsp[-1].dir; 
    }
#line 1879 "plp5.tab.c"
    break;

  case 45:
#line 323 "plp5.y"
          {
        yyval.tipo = yyvsp[0].tipo; 
        yyval.atributos = yyvsp[0].atributos; 
        yyval.trad = yyvsp[0].trad;
        yyval.dir = yyvsp[0].dir; 
    }
#line 1890 "plp5.tab.c"
    break;

  case 46:
#line 330 "plp5.y"
       { 
       
        if( tsActual->searchSymb(yyvsp[0].lexema) == NULL) {
            //cout<<$1.lexema<<endl;
            errorSemantico(ERR_NODECL,yyvsp[0].lexema,yyvsp[0].fila,yyvsp[0].col);
        }
        yyval.tipo = tsActual->searchSymb(yyvsp[0].lexema)->tipo;
        if(yyval.tipo == ENTERO) yyval.atributos.tipo = "int";
        if(yyval.tipo == REAL) yyval.atributos.tipo = "float"; 
        int tmp = nuevaTemp(yyvsp[0].lexema, yyvsp[0].fila, yyvsp[0].col );
        yyval.dir = tmp;
        yyval.trad = "mov " + to_string(tsActual->searchSymb(yyvsp[0].lexema)->dir) + " " + to_string(tmp) + "\n";
        
    }
#line 1909 "plp5.tab.c"
    break;

  case 47:
#line 345 "plp5.y"
         {if(tsActual->searchSymb(yyvsp[0].lexema) == NULL) errorSemantico(ERR_NODECL,yyvsp[0].lexema,yyvsp[0].fila,yyvsp[0].col); 
        if(tsActual->searchSymb(yyvsp[0].lexema)->tipo != ARRAY) errorSemantico(ERR_SOBRAN,yyvsp[0].lexema,yyvsp[0].fila,yyvsp[0].col); 
     }
#line 1917 "plp5.tab.c"
    break;

  case 48:
#line 347 "plp5.y"
            {yyval.tam = ttActual->tipos[yyvsp[-2].tipo].tamano; yyval.tipo == ttActual->tipos[yyvsp[-2].tipo].tipoBase;  yyval.atributos.dbase = yyvsp[-2].dir; int tmp= nuevaTemp(yyvsp[-2].lexema, yyvsp[-2].fila, yyvsp[-2].col); yyval.trad= "mov #0 " + to_string(tmp) + "\n"; yyval.dir= tmp;}
#line 1923 "plp5.tab.c"
    break;

  case 49:
#line 347 "plp5.y"
                                                                                                                                                                                                                                                   {if(yyvsp[-3].tipo != ENTERO ) errorSemantico(ERR_INDICE_ENTERO,yyvsp[-3].lexema,yyvsp[-3].fila,yyvsp[-3].col);}
#line 1929 "plp5.tab.c"
    break;

  case 50:
#line 347 "plp5.y"
                                                                                                                                                                                                                                                                                                                                            {
        int tmp = nuevaTemp(yyvsp[-6].lexema, yyvsp[-6].fila, yyvsp[-6].col); 
        yyval.dir = tmp; 
        yyval.trad = yyvsp[-2].trad + "mov" + to_string(yyvsp[-2].dir) + " A\n" + "muli" + "#" + to_string(yyvsp[-2].tam) + "\naddi #" + to_string(yyvsp[-2].atributos.dbase) + "\n" + "mov @A" + to_string(tmp); 
        yyval.tipo = yyvsp[-2].tipo; 
   }
#line 1940 "plp5.tab.c"
    break;

  case 51:
#line 354 "plp5.y"
                   {
        if(yyvsp[0].tipo != ENTERO ) errorSemantico(ERR_INDICE_ENTERO,yyvsp[0].lexema,yyvsp[0].fila,yyvsp[0].col);
        yyval.tipo = yyvsp[-3].tipo; 
        yyval.atributos.dbase = yyvsp[-3].atributos.dbase; 
        int tmp = nuevaTemp(yyvsp[-2].lexema , yyvsp[-2].fila, yyvsp[-2].col); 
        yyval.dir = tmp;
        yyval.trad = yyvsp[-3].trad + yyvsp[0].trad + "mov " + to_string(yyvsp[-3].dir) + " A\n" + "muli" + "#" + to_string(yyvsp[-3].tam) + "\naddi " + to_string( yyvsp[0].dir)  + "\n" + "mov A " + to_string(tmp); 
    }
#line 1953 "plp5.tab.c"
    break;

  case 52:
#line 362 "plp5.y"
        {
        if(yyvsp[0].tipo != ENTERO ) errorSemantico(ERR_INDICE_ENTERO,yyvsp[0].lexema,yyvsp[0].fila,yyvsp[0].col);
        yyval.trad = yyvsp[0].trad; 
        yyval.tipo = yyvsp[0].tipo; 
        yyval.dir = yyvsp[0].dir; 
    }
#line 1964 "plp5.tab.c"
    break;


#line 1968 "plp5.tab.c"

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 369 "plp5.y"






string tipoMayus(string tipo){
    
    if(tipo == "int") return "Int"; 
    return "Float"; 
}
/*
int parserTipo(string tipo , char * lexema, int fila, int columna  ){
    if (tipo =="int"  ) return ENTERO; 
    if (tipo == "float"  ) return REAL; 
    
    if(tipo == "void" )errorSemantico(ERRVOID,lexema,fila,columna);
    return -1; 
}*/

string tipoShake(string type1,  string type2){
    if(type1 == "float" || type2 == "float" ) return "float"; 
    return "int";
}

///Manejar temporales (16000 - 16383)
int nuevaTemp(char *lexema, int fila, int columna ){
    ctemp +=1; 
    if(ctemp > 16383) errorSemantico(ERR_MAXTEMP, lexema, fila, columna ); 
    return ctemp; 
}
///Manejar variables 
int nuevaVar(unsigned tam , char *lexema, int fila, int columna ){
    cvar +=tam; 
    if(cvar > 16000) errorSemantico(ERR_NOCABE, lexema, fila, columna ); 
    return cvar; 
}
//Manejar etiquetas 
int nuevaEtiqueta(){
    mietiquetaact += 1;
    return mietiquetaact; 
}

/// ---------- Errores semánticos ---------------------------------
void errorSemantico(int nerror,char *s,int fila,int columna)
{
    fprintf(stderr,"Error semantico (%d,%d): ",fila,columna);
    //cout<<ERR_NODECL<<endl;
    //cout<<nerror<<endl;
    switch (nerror) {
        case ERR_YADECL: fprintf(stderr,"variable '%s' ya declarada\n",s);
               // fila,columna de la variable
               break;
        case ERR_NODECL: fprintf(stderr,"variable '%s' no declarada\n",s);
               // fila,columna de la variable
               break;
        case ERR_NOCABE:fprintf(stderr,"la variable '%s' ya no cabe en memoria\n",s);  
               // fila,columna de la variable
               break;

        case ERR_IFWHILE:fprintf(stderr,"la expresion del '%s' debe ser de tipo entero",s);
               // fila,columna del 'if' o 'while'
               break;
             
        case ERR_DIM: fprintf(stderr,"la dimension debe ser mayor que 0\n");
               // fila,columna de la dimension (numint)
               break;
        case ERR_FALTAN: fprintf(stderr,"faltan indices\n");
               // fila,columna del id (si no hay ningún índice) o del último ']'
               break;
        case ERR_SOBRAN: fprintf(stderr,"sobran indices\n");
               // fila,columna del '[' si no es array, o de la ',' que sobra
               break;
        case ERR_INDICE_ENTERO: fprintf(stderr,"el indice de un array debe ser de tipo entero\n");
               // fila,columna del '[' si es el primero, o de la ',' inmediatamente anterior
               break;

        case ERR_ASIG: fprintf(stderr,"tipos incompatibles en la asignacion\n");
               // fila,columna del '='
               break;
        case ERR_MAXTEMP:fprintf(stderr,"no hay espacio para variables temporales\n");
               // fila,columna da igual
               break;
    }
    exit(-1);
}




void msgError(int nerror,int nlin,int ncol,const char *s)
{
     switch (nerror) {
         case ERRLEXICO: fprintf(stderr,"Error lexico (%d,%d): caracter '%s' incorrecto\n",nlin,ncol,s);
            break;
         case ERRSINT: fprintf(stderr,"Error sintactico (%d,%d): en '%s'\n",nlin,ncol,s);
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
