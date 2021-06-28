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
#line 1 "src/ada.y" /* yacc.c:339  */

    #include<iostream>
    #include<string>
    #include "symbolTable.cpp"
    #include <fstream>
    #define TYPEINT 1
    #define TYPESTRING 2
    #define TYPEREAL 3
    #define TYPEBOOL 4
    #define TYPEPROGRAM 5
    #define TYPEPROCEDURE 6
    #define TYPEFUNCTION 7
    #define TYPEARRAY 8
    #define TYPENONE 60
    using namespace std;
    
    #define Trace(t) if (Opt_P) printf(t)
    int yylex();
    int yyerror(string s);
    int Opt_P = 1;
    int currentType=0;
    int localIndexTemp = 0;
    bool hasDeclared = false;
    node* tempNode = new node;
    string programName ; 
    node* tempNode2 = new node;
    int returnTypeTemp = 0;
    fstream file;
    bool isGlobalDeclaration = true;
   
    // 用來保存LOOKUP後的結果
    node* res;
    SymbolTables s;
    vector<int> row;
    string tempStr;
    string tempStr2;
    string tempStr3;
    int labelCount = 0;
    int ifLabelCount = 0;
    int whileLabelCount = 0;
    int needDecreaseCount = 0;
    int tempExitLabel = 0;
    int forLabelCount = 0;
    int forLowerVal = 0;
    int forHigherVal = 0;
    int returnCount = 0;
    //參數的暫存ARRAY

    vector< vector<int>> argTypeTemp;
    vector< int > ifLabelCountTemp;
    vector< int > whileLabelCountTemp;
    vector< int > forLabelCountTemp;

#line 120 "y.tab.c" /* yacc.c:339  */

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
    COMMA = 258,
    COLON = 259,
    PERIOD = 260,
    SEMICOLON = 261,
    RELATIONAL = 262,
    ASSIGNMENT = 263,
    BEGINTOKEN = 264,
    BOOLEAN = 265,
    BREAK = 266,
    CHARACTER = 267,
    CASE = 268,
    CONTINUE = 269,
    CONSTANT = 270,
    DECLARE = 271,
    DO = 272,
    READ = 273,
    ELSE = 274,
    END = 275,
    EXIT = 276,
    FLOAT = 277,
    FOR = 278,
    IF = 279,
    IN = 280,
    INTEGER = 281,
    LOOP = 282,
    PRINT = 283,
    PRINTLN = 284,
    PROCEDURE = 285,
    PROGRAM = 286,
    RETURN = 287,
    STR = 288,
    THEN = 289,
    WHILE = 290,
    KEYWORD = 291,
    LOGICAL = 292,
    REMAINDER = 293,
    LEFTSQUAREBRACKET = 294,
    RIGHTSQUAREBRACKET = 295,
    LEFTPARENTHESE = 296,
    RIGHTPARENTHESE = 297,
    CHANGELINE = 298,
    SPACE = 299,
    INTEGERCONSTANT = 300,
    STRINGCONSTANT = 301,
    REALCONSTANT = 302,
    BOOLEANCONSTANTS = 303,
    IDENTIFIER = 304,
    OR = 305,
    AND = 306,
    NOT = 307,
    GREATEQUAL = 308,
    LESSEQUAL = 309,
    NOTEQUAL = 310,
    UMINUS = 311
  };
#endif
/* Tokens.  */
#define COMMA 258
#define COLON 259
#define PERIOD 260
#define SEMICOLON 261
#define RELATIONAL 262
#define ASSIGNMENT 263
#define BEGINTOKEN 264
#define BOOLEAN 265
#define BREAK 266
#define CHARACTER 267
#define CASE 268
#define CONTINUE 269
#define CONSTANT 270
#define DECLARE 271
#define DO 272
#define READ 273
#define ELSE 274
#define END 275
#define EXIT 276
#define FLOAT 277
#define FOR 278
#define IF 279
#define IN 280
#define INTEGER 281
#define LOOP 282
#define PRINT 283
#define PRINTLN 284
#define PROCEDURE 285
#define PROGRAM 286
#define RETURN 287
#define STR 288
#define THEN 289
#define WHILE 290
#define KEYWORD 291
#define LOGICAL 292
#define REMAINDER 293
#define LEFTSQUAREBRACKET 294
#define RIGHTSQUAREBRACKET 295
#define LEFTPARENTHESE 296
#define RIGHTPARENTHESE 297
#define CHANGELINE 298
#define SPACE 299
#define INTEGERCONSTANT 300
#define STRINGCONSTANT 301
#define REALCONSTANT 302
#define BOOLEANCONSTANTS 303
#define IDENTIFIER 304
#define OR 305
#define AND 306
#define NOT 307
#define GREATEQUAL 308
#define LESSEQUAL 309
#define NOTEQUAL 310
#define UMINUS 311

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 54 "src/ada.y" /* yacc.c:355  */

    struct{
    string* strVal;
    string* name;
    string* name2;
    int tokenType;
    string* typeStr;
    int intVal;
    float realVal;
    bool isVariable;
    bool boolVal;
    }Token;

#line 286 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 303 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   399

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  69
/* YYNRULES -- Number of rules.  */
#define YYNRULES  129
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  244

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   311

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    63,     2,     2,
       2,     2,    61,    60,     2,    59,     2,    62,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      54,    58,    53,     2,     2,     2,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    55,    56,
      57,    64
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    99,    99,    99,   118,   121,    99,   146,   146,   146,
     148,   148,   148,   150,   150,   150,   153,   152,   192,   191,
     249,   248,   268,   300,   304,   305,   306,   307,   308,   313,
     313,   315,   333,   314,   372,   372,   373,   373,   378,   377,
     386,   386,   387,   403,   421,   436,   453,   459,   469,   472,
     474,   473,   478,   480,   481,   482,   483,   484,   486,   490,
     492,   566,   614,   619,   613,   630,   635,   629,   645,   644,
     654,   659,   664,   678,   716,   753,   790,   827,   847,   867,
     887,   915,   944,   968,   985,  1012,  1037,  1059,  1075,  1083,
    1090,  1104,  1123,  1138,  1145,  1203,  1202,  1272,  1297,  1301,
    1307,  1306,  1314,  1314,  1314,  1314,  1318,  1318,  1318,  1318,
    1321,  1321,  1326,  1339,  1325,  1342,  1341,  1359,  1369,  1377,
    1388,  1368,  1398,  1412,  1432,  1447,  1397,  1580,  1579,  1636
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "COMMA", "COLON", "PERIOD", "SEMICOLON",
  "RELATIONAL", "ASSIGNMENT", "BEGINTOKEN", "BOOLEAN", "BREAK",
  "CHARACTER", "CASE", "CONTINUE", "CONSTANT", "DECLARE", "DO", "READ",
  "ELSE", "END", "EXIT", "FLOAT", "FOR", "IF", "IN", "INTEGER", "LOOP",
  "PRINT", "PRINTLN", "PROCEDURE", "PROGRAM", "RETURN", "STR", "THEN",
  "WHILE", "KEYWORD", "LOGICAL", "REMAINDER", "LEFTSQUAREBRACKET",
  "RIGHTSQUAREBRACKET", "LEFTPARENTHESE", "RIGHTPARENTHESE", "CHANGELINE",
  "SPACE", "INTEGERCONSTANT", "STRINGCONSTANT", "REALCONSTANT",
  "BOOLEANCONSTANTS", "IDENTIFIER", "OR", "AND", "NOT", "'>'", "'<'",
  "GREATEQUAL", "LESSEQUAL", "NOTEQUAL", "'='", "'-'", "'+'", "'*'", "'/'",
  "'%'", "UMINUS", "$accept", "program", "$@1", "$@2", "$@3", "$@4",
  "declare", "$@5", "declarations", "$@6", "declaration",
  "variableDeclaration", "$@7", "constantDeclaration", "$@8",
  "arrayDeclaration", "$@9", "variableDeclarationOptional",
  "typeWithEmpty", "procedures", "procedure", "$@10", "$@11", "argumentss",
  "arguments", "argument", "$@12", "argumentSEMICOLON", "type",
  "returnType", "blockStatements", "statements", "$@13", "statement",
  "print_expression", "simple_statement", "$@14", "$@15", "$@16", "$@17",
  "$@18", "expression", "$@19", "comma_separated_expression", "$@20",
  "block", "$@21", "$@22", "$@23", "procedure_block", "$@24", "$@25",
  "$@26", "block_or_simple", "conditional", "$@27", "$@28",
  "conditional_optional", "$@29", "loop", "$@30", "$@31", "$@32", "$@33",
  "$@34", "$@35", "$@36", "procedure_invocation", "$@37", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,    62,    60,   308,   309,   310,    61,    45,
      43,    42,    47,    37,   311
};
# endif

#define YYPACT_NINF -177

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-177)))

#define YYTABLE_NINF -101

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -21,  -177,    19,   -19,  -177,  -177,    33,  -177,  -177,    20,
      40,    67,  -177,  -177,  -177,  -177,  -177,    25,    66,    40,
      12,    69,    20,  -177,  -177,  -177,    43,    80,    44,    47,
      50,    51,   303,  -177,  -177,    52,   187,    -1,    86,    57,
     303,  -177,  -177,  -177,  -177,   -28,   303,   303,   -16,   323,
      97,    55,    73,    58,    68,   303,  -177,  -177,   149,  -177,
      -2,    88,  -177,  -177,  -177,    33,  -177,  -177,  -177,  -177,
    -177,  -177,  -177,   303,    70,   258,   303,  -177,    90,  -177,
    -177,  -177,   303,   303,   303,   303,   303,   303,   303,   303,
     303,   303,   303,   303,   303,  -177,   102,    71,    55,     2,
    -177,  -177,    62,   323,   312,   312,  -177,    79,   303,  -177,
     303,   303,  -177,   150,   187,   148,   323,  -177,  -177,   212,
     303,   336,    90,    37,    37,    37,    37,    37,    37,   -15,
     -15,  -177,  -177,  -177,  -177,  -177,  -177,  -177,  -177,  -177,
    -177,  -177,  -177,   152,  -177,   126,   303,  -177,   323,  -177,
    -177,   323,   111,   236,   303,   139,  -177,   215,   171,   183,
    -177,    65,   151,     2,   172,    33,  -177,   166,    63,   280,
     193,   196,   176,  -177,   198,   162,   163,  -177,   200,  -177,
    -177,   210,  -177,   208,   168,   216,   303,    -3,  -177,  -177,
     202,   220,  -177,  -177,    63,   303,   221,  -177,   211,  -177,
     303,  -177,  -177,   224,   215,   323,  -177,   214,  -177,   125,
    -177,  -177,  -177,  -177,  -177,   232,    63,   217,   222,  -177,
     234,   225,   241,  -177,  -177,   226,  -177,  -177,  -177,   242,
     245,   248,   303,  -177,  -177,  -177,   323,   213,   229,    63,
     237,   231,   253,  -177
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     2,     0,     0,     1,     3,     7,     8,     4,    10,
      30,    28,     9,    11,    14,    13,    15,     0,     0,    30,
       0,    23,    10,    31,     5,    29,    27,    28,    24,    25,
      26,     0,     0,    16,    12,    35,   102,     0,     0,     0,
       0,    90,    91,    93,    92,    94,     0,     0,     0,    22,
       0,    37,    46,     0,     0,     0,    62,    65,     0,   118,
       0,     0,    50,    53,    56,     7,    54,    55,    57,    27,
      24,    25,    26,     0,     0,     0,     0,    95,    79,    87,
      89,    88,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    17,     0,     0,    37,     0,
      32,    68,     0,   112,     0,     0,    71,     0,     0,   129,
       0,     0,   127,     0,   102,     0,    18,    20,    72,     0,
      98,    78,    77,    81,    80,    84,    85,    86,    82,    74,
      73,    75,    76,    83,    38,    34,    36,    45,    42,    43,
      44,    47,   106,     0,   122,     0,     0,    63,    59,    66,
      70,   119,     0,     0,    98,     0,    51,   102,     0,     0,
      97,    99,     0,     0,     0,     7,    69,     0,   102,     0,
       0,     0,     0,    60,     0,     0,     0,   103,   102,    19,
      21,     0,    96,    41,     0,     0,     0,     0,   111,   110,
     117,    72,    64,    67,   102,     0,     0,     6,     0,    48,
      98,    40,    39,     0,   102,   123,   115,     0,   120,     0,
     128,   104,   101,    33,   107,     0,   102,     0,     0,    61,
       0,     0,     0,   116,   113,     0,   105,   108,   124,     0,
       0,     0,     0,   114,   121,   109,   125,     0,     0,   102,
       0,     0,     0,   126
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -177,  -177,  -177,  -177,  -177,  -177,   -64,  -177,   238,  -177,
    -177,  -177,  -177,  -177,  -177,  -177,  -177,  -177,   250,   259,
    -177,  -177,  -177,  -177,   181,  -177,  -177,  -177,   -96,  -177,
    -171,   147,  -177,   -34,   175,  -152,  -177,  -177,  -177,  -177,
    -177,   -32,  -177,  -134,  -177,  -151,  -177,  -177,  -177,  -177,
    -177,  -177,  -177,  -176,  -177,  -177,  -177,  -177,  -177,  -177,
    -177,  -177,  -177,  -177,  -177,  -177,  -177,  -177,  -177
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     6,    10,    36,     8,     9,    12,    22,
      13,    14,    50,    15,   158,    16,   159,    33,    21,    18,
      19,    35,   142,    52,    97,    98,   163,   202,    31,   100,
     177,    61,   114,   178,   147,    63,   104,   170,   105,   171,
     143,   161,   120,   162,   181,    64,    65,   198,   220,   164,
     165,   221,   231,   190,    66,   145,   229,   207,   216,    67,
     108,   172,   218,   167,   215,   232,   237,    68,   154
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      49,   115,    62,   141,   109,   110,   110,   199,    75,    69,
       1,    76,   137,    77,    78,    79,   188,   189,   208,     4,
     175,    70,    26,   103,   138,    71,   107,    27,   139,    80,
       5,    81,    72,   214,    28,   140,   111,   111,    29,   112,
     223,   116,   188,   189,   119,    30,    92,    93,    94,     7,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   240,   188,   189,   212,   183,  -100,    11,
      17,    20,   148,   148,    23,    24,   151,    32,   152,   153,
      62,    53,   -45,   -42,    37,   150,   -43,   188,   189,   -44,
      39,    56,    57,    51,    73,    58,    90,    91,    92,    93,
      94,   185,    74,    95,    96,    99,   134,   101,   113,   102,
     117,   144,   187,   135,   169,    82,    83,   173,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    82,
      83,   219,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,   205,   106,   155,   157,   166,   176,
     168,    82,    83,   209,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    82,    83,   179,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,   180,
      40,   186,   184,   182,    41,    42,    43,    44,    45,   192,
     236,    46,   193,   194,   196,    53,   195,   -52,    47,    48,
      54,    55,   197,   200,   201,    56,    57,   203,    53,    58,
     -49,   206,    59,    54,    55,   204,   -58,   210,    56,    57,
     213,   211,    58,    53,   217,    59,    60,   222,    54,    55,
     226,   224,   225,    56,    57,   227,   228,    58,   233,    60,
      59,   234,   160,   230,   235,   238,   239,   241,   242,   243,
      34,   156,    82,    83,    60,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,   174,    38,    25,   136,
     149,     0,     0,     0,     0,     0,    82,    83,     0,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
     118,     0,     0,     0,     0,     0,     0,     0,    82,    83,
       0,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,   191,     0,     0,     0,     0,     0,     0,     0,
      82,    83,     0,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    40,     0,     0,     0,    41,    42,
      43,    44,    45,   146,     0,    46,     0,    41,    42,    43,
      44,    45,    47,    48,    46,     0,     0,     0,     0,     0,
       0,    47,    48,    82,    83,     0,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    83,     0,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94
};

static const yytype_int16 yycheck[] =
{
      32,    65,    36,    99,     6,     8,     8,   178,    40,    10,
      31,    39,    10,    41,    46,    47,   168,   168,   194,     0,
     154,    22,    10,    55,    22,    26,    58,    15,    26,    45,
      49,    47,    33,   204,    22,    33,    39,    39,    26,    41,
     216,    73,   194,   194,    76,    33,    61,    62,    63,    16,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,   239,   216,   216,   200,   163,     3,    49,
      30,     4,   104,   105,    49,     9,   108,     8,   110,   111,
     114,    18,    39,    39,     4,     6,    39,   239,   239,    39,
      39,    28,    29,    41,     8,    32,    59,    60,    61,    62,
      63,   165,    45,     6,    49,    32,     4,    49,    20,    41,
      40,    49,    49,    42,   146,    50,    51,     6,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    50,
      51,     6,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,   186,     6,     6,     9,     6,    20,
      34,    50,    51,   195,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    50,    51,     6,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,     6,
      41,    25,    20,    42,    45,    46,    47,    48,    49,     6,
     232,    52,     6,    27,    42,    18,     8,    20,    59,    60,
      23,    24,    49,     3,     6,    28,    29,    49,    18,    32,
      20,    19,    35,    23,    24,     9,     6,     6,    28,    29,
       6,    20,    32,    18,    20,    35,    49,     5,    23,    24,
       6,    24,    20,    28,    29,    20,     5,    32,     6,    49,
      35,     6,    40,    27,     6,    42,    27,    20,    27,     6,
      22,   114,    50,    51,    49,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    40,    27,    19,    98,
     105,    -1,    -1,    -1,    -1,    -1,    50,    51,    -1,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,
      -1,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      50,    51,    -1,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    41,    -1,    -1,    -1,    45,    46,
      47,    48,    49,    41,    -1,    52,    -1,    45,    46,    47,
      48,    49,    59,    60,    52,    -1,    -1,    -1,    -1,    -1,
      -1,    59,    60,    50,    51,    -1,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    51,    -1,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    31,    66,    67,     0,    49,    68,    16,    71,    72,
      69,    49,    73,    75,    76,    78,    80,    30,    84,    85,
       4,    83,    74,    49,     9,    84,    10,    15,    22,    26,
      33,    93,     8,    82,    73,    86,    70,     4,    83,    39,
      41,    45,    46,    47,    48,    49,    52,    59,    60,   106,
      77,    41,    88,    18,    23,    24,    28,    29,    32,    35,
      49,    96,    98,   100,   110,   111,   119,   124,   132,    10,
      22,    26,    33,     8,    45,   106,    39,    41,   106,   106,
      45,    47,    50,    51,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,     6,    49,    89,    90,    32,
      94,    49,    41,   106,   101,   103,     6,   106,   125,     6,
       8,    39,    41,    20,    97,    71,   106,    40,    42,   106,
     107,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,     4,    42,    89,    10,    22,    26,
      33,    93,    87,   105,    49,   120,    41,    99,   106,    99,
       6,   106,   106,   106,   133,     6,    96,     9,    79,    81,
      40,   106,   108,    91,   114,   115,     6,   128,    34,   106,
     102,   104,   126,     6,    40,   108,    20,    95,    98,     6,
       6,   109,    42,    93,    20,    71,    25,    49,   100,   110,
     118,    42,     6,     6,    27,     8,    42,    49,   112,    95,
       3,     6,    92,    49,     9,   106,    19,   122,   118,   106,
       6,    20,   108,     6,    95,   129,   123,    20,   127,     6,
     113,   116,     5,   118,    24,    20,     6,    20,     5,   121,
      27,   117,   130,     6,     6,     6,   106,   131,    42,    27,
     118,    20,    27,     6
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    65,    67,    68,    69,    70,    66,    71,    72,    71,
      73,    74,    73,    75,    75,    75,    77,    76,    79,    78,
      81,    80,    82,    82,    83,    83,    83,    83,    83,    84,
      84,    86,    87,    85,    88,    88,    89,    89,    91,    90,
      92,    92,    93,    93,    93,    93,    94,    94,    95,    95,
      97,    96,    96,    98,    98,    98,    98,    98,    99,    99,
     100,   100,   101,   102,   100,   103,   104,   100,   105,   100,
     100,   100,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   107,   106,   106,   108,   108,
     109,   108,   111,   112,   113,   110,   115,   116,   117,   114,
     118,   118,   120,   121,   119,   123,   122,   122,   125,   126,
     127,   124,   128,   129,   130,   131,   124,   133,   132,   132
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     0,     0,    14,     0,     0,     3,
       0,     0,     3,     1,     1,     1,     0,     5,     0,     8,
       0,     8,     2,     0,     2,     2,     2,     2,     0,     2,
       0,     0,     0,    10,     3,     0,     2,     0,     0,     5,
       1,     0,     1,     1,     1,     1,     0,     2,     2,     1,
       0,     3,     0,     1,     1,     1,     1,     1,     3,     1,
       4,     7,     0,     0,     5,     0,     0,     5,     0,     4,
       3,     2,     3,     3,     3,     3,     3,     3,     3,     2,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     2,
       1,     1,     1,     1,     1,     0,     5,     4,     0,     1,
       0,     4,     0,     0,     0,     8,     0,     0,     0,     8,
       1,     1,     0,     0,    10,     0,     3,     0,     0,     0,
       0,    10,     0,     0,     0,     0,    18,     0,     6,     2
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
#line 99 "src/ada.y" /* yacc.c:1646  */
    {}
#line 1599 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 99 "src/ada.y" /* yacc.c:1646  */
    {
                            file.open("./"+ *(yyvsp[0].Token).name + ".jasm",ios::out);
                            file << "class " + *(yyvsp[0].Token).name <<"\n";
                            file <<"{\n";
                            programName = *(yyvsp[0].Token).name;
                            // insert program identifer
                            Trace("Read program ID\n"); 
                            
                            tempNode->identifierType = TYPEPROGRAM;
                            tempNode->identifierName = *(yyvsp[0].Token).name;
                            if(s.insert( tempNode) == -1)
                            {
                                yyerror("same idenifier name in a symbolTable\n");
                            }
                            //reset tempNode
                            tempNode = new node;

                            }
#line 1622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 118 "src/ada.y" /* yacc.c:1646  */
    {
                                isGlobalDeclaration = false;
                            }
#line 1630 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 121 "src/ada.y" /* yacc.c:1646  */
    {
                                file << "   method public static void main(java.lang.String[])\n";
                                file << "   max_stack 15\n";
                                file << "   max_locals 15\n";
                                file << "   {\n" ;
                            }
#line 1641 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 127 "src/ada.y" /* yacc.c:1646  */
    { 
                                cout<<"begin: "<<*(yyvsp[0].Token).name<<"\n";
                                cout<<"end: "<<s.start->start->identifierName<<"\n";
                                // check begin name and end name
                                if(*(yyvsp[0].Token).name != *(yyvsp[-11].Token).name){
                                yyerror("program name different\n");

                                }
                                else{  
                                    s.dumpAllTable(); s.popTable();
                                    Trace("Success syntax\n");
                                file << "       return\n";
                                file << "   }\n";
                                file <<"}";

                                    } 
                            }
#line 1663 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 146 "src/ada.y" /* yacc.c:1646  */
    {Trace("detect empty DECLARE\n");}
#line 1669 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 146 "src/ada.y" /* yacc.c:1646  */
    {Trace("detect DECLARE\n");}
#line 1675 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 146 "src/ada.y" /* yacc.c:1646  */
    {}
#line 1681 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 148 "src/ada.y" /* yacc.c:1646  */
    {Trace("detect declaration\n");}
#line 1687 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 148 "src/ada.y" /* yacc.c:1646  */
    {Trace("declarations\n");}
#line 1693 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 150 "src/ada.y" /* yacc.c:1646  */
    { Trace("detect constantDeclaration\n");}
#line 1699 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 150 "src/ada.y" /* yacc.c:1646  */
    {Trace("detect variableDeclaration\n");}
#line 1705 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 150 "src/ada.y" /* yacc.c:1646  */
    {Trace("detect arrayDeclaration\n");}
#line 1711 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 153 "src/ada.y" /* yacc.c:1646  */
    {   // if variable type is NONE then set default INT!
                if(tempNode->identifierType == TYPENONE)
                {
                    tempNode->identifierType = TYPEINT;
                    
                }
                tempNode->id = localIndexTemp++;
                tempNode->identifierName = *(yyvsp[-2].Token).name;
                
                // check only one variable name  in a symbolTable
                if(s.insert( tempNode) == -1)
                {
                    yyerror("same idenifier name in a symbolTable\n");
                }
                /*NEW*/
                if(isGlobalDeclaration){
                    file << "   field static " + printVariableType(tempNode->identifierType) + " " + tempNode->identifierName + tempStr + "\n";
                    tempStr = "";
                    tempStr2 = "";
                }else{
                    if(tempStr2 != ""){
                        // later push
                        // file << tempStr2 <<"\n";
                        file << "       istore " << to_string(tempNode->id)<<"\n";

                    }
                    
                    tempStr = "";
                    tempStr2 = "";
                }
                /*NEW*/
                tempNode = new node;
                
                //reset tempNode
                // insert variable identifer
            }
#line 1752 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 188 "src/ada.y" /* yacc.c:1646  */
    {

}
#line 1760 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 192 "src/ada.y" /* yacc.c:1646  */
    {

                tempNode->identifierName = *(yyvsp[-5].Token).name;
                // set contant value = 1
                tempNode->isConstant = true;
                // check right value and left vale are consistent?
                if(((yyvsp[0].Token).tokenType != tempNode->identifierType) && tempNode->identifierType != TYPENONE)
                {
                    yyerror("declare constant type inconsistent\n");
                }
                // set variavle type
                tempNode->identifierType = (yyvsp[0].Token).tokenType;
                tempNode->id = localIndexTemp++;
                // check only one variable name  in a symbolTable
                if(s.insert( tempNode) == -1)
                {
                    yyerror("same idenifier name in a symbolTable\n");
                }
                /*NEW*/
                if(tempNode->identifierType == TYPEBOOL){
                            if ((yyvsp[0].Token).boolVal){
                                tempNode->intVal = 1;
                            }else{
                                tempNode->intVal = 0;
                            }
                            tempStr = " = " + to_string(tempNode->intVal);
                            tempStr2 = "        sipush " +  to_string(tempNode->intVal);
                }
                else if(tempNode->identifierType != TYPESTRING){
                            tempNode->realVal = int((yyvsp[0].Token).realVal);
                            tempStr = " = " + to_string(int(tempNode->realVal));
                            tempStr2 = "        sipush " +  to_string(int(tempNode->realVal));
                }else{
                            tempNode->strVal = *(yyvsp[0].Token).strVal;
                            tempStr = "";
                            tempStr2 = "";
                }
                if(isGlobalDeclaration){
                    file << "   field static " + printVariableType(tempNode->identifierType) + " " + tempNode->identifierName + tempStr + "\n";
                    tempStr = "";
                    tempStr2 = "";
                }else{
                    // later push
                    // file << tempStr2 <<"\n";
                    file << "       istore " << to_string(tempNode->id)<<"\n";
                    tempStr = "";
                    tempStr2 = "";
                }
                /*NEW*/
                tempNode = new node;
                
            }
#line 1817 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 245 "src/ada.y" /* yacc.c:1646  */
    {
                Trace("constantDeclaration\n");
            }
#line 1825 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 249 "src/ada.y" /* yacc.c:1646  */
    {
                tempNode2->identifierName = *(yyvsp[-5].Token).name;
                tempNode2->identifierType = TYPEARRAY;
                //set array type 
                tempNode2->arrayType = tempNode2->parameterTypes[0];
                // index must >=0
                if((yyvsp[-1].Token).intVal < 0){
                    yyerror("array declration with size < 0\n");
                }
                tempNode2->initArray(tempNode2->arrayType, (yyvsp[-1].Token).intVal);
                // check only one variable name  in a symbolTable
                if(s.insert( tempNode2) == -1)
                {
                    yyerror("same idenifier name in a symbolTable\n");
                }
                tempNode2 = new node;
            }
#line 1847 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 266 "src/ada.y" /* yacc.c:1646  */
    {}
#line 1853 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 269 "src/ada.y" /* yacc.c:1646  */
    {
                        
                        // check type inconsistent
                        if(((yyvsp[0].Token).tokenType != tempNode->identifierType) && tempNode->identifierType != TYPENONE)
                        {
                            yyerror("declare  type inconsistent\n");
                        }
                        tempNode->identifierType = (yyvsp[0].Token).tokenType;
                        /* NEW*/
                        if(tempNode->identifierType == TYPEBOOL){
                            // bool
                            if ((yyvsp[0].Token).boolVal){
                                tempNode->intVal = 1;
                            }else{
                                tempNode->intVal = 0;
                            }
                             
                            tempStr = " = " + to_string(tempNode->intVal);
                            tempStr2 = "        sipush " +  to_string(tempNode->intVal);
                        }
                        else if(tempNode->identifierType != TYPESTRING){
                            tempNode->realVal = int((yyvsp[0].Token).realVal);
                            tempStr = " = " + to_string( int(tempNode->realVal));
                            tempStr2 = "        sipush " +  to_string(int(tempNode->realVal));
                        }else{
                            tempStr = "";
                            tempStr2 = "";
                        }
                        /* NEW */
                        
                    }
#line 1889 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 300 "src/ada.y" /* yacc.c:1646  */
    {
                        tempStr = "";
                        tempStr2 = "";
}
#line 1898 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 304 "src/ada.y" /* yacc.c:1646  */
    {tempNode->identifierType = TYPEREAL; }
#line 1904 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 305 "src/ada.y" /* yacc.c:1646  */
    {tempNode->identifierType = TYPEINT; }
#line 1910 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 306 "src/ada.y" /* yacc.c:1646  */
    {tempNode->identifierType = TYPESTRING; }
#line 1916 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 307 "src/ada.y" /* yacc.c:1646  */
    {tempNode->identifierType = TYPEBOOL; }
#line 1922 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 308 "src/ada.y" /* yacc.c:1646  */
    {tempNode->identifierType = TYPENONE;}
#line 1928 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 313 "src/ada.y" /* yacc.c:1646  */
    {Trace("detect empty procedure\n");}
#line 1934 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 315 "src/ada.y" /* yacc.c:1646  */
    {   
                localIndexTemp = 0;
                tempNode2->identifierType = TYPEPROCEDURE;
                tempNode2->identifierName = *(yyvsp[0].Token).name;
                
                returnCount = 0;
                
                // check only one variable name  in a symbolTable
                if(s.insert( tempNode2) == -1)
                {
                    yyerror("same idenifier name in a symbolTable\n");
                } 
                cout<<"#199 create\n";
                // create new table to store arguments and variables
                s.createNewSymbolTable();

            }
#line 1956 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 333 "src/ada.y" /* yacc.c:1646  */
    {
                /*NEW*/
                file << "   method public static " + printVariableType(tempNode2->parameterTypes[tempNode2->parameterTypes.size() - 1]);
                file << " " << *(yyvsp[-3].Token).name << "(";
                for(int i = 0; i< tempNode2->parameterTypes.size() - 1; i++){
                    if( i == tempNode2->parameterTypes.size() - 2){
                        file << printVariableType(tempNode2->parameterTypes[i]);
                        file << ")\n";
                        
                    }else{
                        file << printVariableType(tempNode2->parameterTypes[i]) << ", ";
                    }
                }
                returnTypeTemp = tempNode2->parameterTypes[tempNode2->parameterTypes.size() - 1];
                if(tempNode2->parameterTypes.size() == 1) file << ")\n";
                file << "   max_stack 15\n";
                file << "   max_locals 15\n";  
                file << "   {\n";
                /* NEW */

                    tempNode2 = new node; 
                    
            }
#line 1984 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 356 "src/ada.y" /* yacc.c:1646  */
    { 
                //check procedure begin name and end name 
                if(*(yyvsp[-8].Token).name != *(yyvsp[-1].Token).name)
                {
                    yyerror("procedure name different\n");                   
                }
                //exit scope
                s.popTable();
                /* NEW */
                if(returnCount == 0){
                    file << "       return\n";
                }
                file << "   }\n";
                /* NEW */
            }
#line 2004 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 373 "src/ada.y" /* yacc.c:1646  */
    {
    Trace("detect 0 formal parameter\n");
}
#line 2012 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 378 "src/ada.y" /* yacc.c:1646  */
    {
                 
                tempNode->identifierName = *(yyvsp[-1].Token).name;
                tempNode->id = localIndexTemp++;
                Trace("SEMICOLON argument\n");
            
            }
#line 2024 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 384 "src/ada.y" /* yacc.c:1646  */
    {}
#line 2030 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 386 "src/ada.y" /* yacc.c:1646  */
    {}
#line 2036 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 388 "src/ada.y" /* yacc.c:1646  */
    {
                tempNode->identifierType = TYPEREAL;
                
                tempNode2->parameterTypes.push_back(TYPEREAL);
                // if tempNode has name  means we are storing arg paramaters 
                if(tempNode->identifierName == "")
                {

                }
                else if(s.insert( tempNode) == -1)
                {
                    yyerror("same idenifier name in a symbolTable\n");
                }
                tempNode = new node;
            }
#line 2056 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 404 "src/ada.y" /* yacc.c:1646  */
    {
                tempNode->identifierType = TYPEINT;
                
                cout<<"there: "<< tempNode->identifierName<<"\n";
                
                tempNode2->parameterTypes.push_back(TYPEINT);
                // if tempNode has name  means we are storing arg paramaters 
                if(tempNode->identifierName == "")
                {

                }
                else if(s.insert( tempNode) == -1)
                {
                    yyerror("same idenifier name in a symbolTable\n");
                }
                tempNode = new node;
            }
#line 2078 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 421 "src/ada.y" /* yacc.c:1646  */
    {
                tempNode->identifierType = TYPESTRING;
                
                tempNode2->parameterTypes.push_back(TYPESTRING);
                // if tempNode has name  means we are storing arg paramaters 
                if(tempNode->identifierName == "")
                {

                }
                else if(s.insert( tempNode) == -1)
                {
                    yyerror("same idenifier name in a symbolTable\n");
                }   
                tempNode = new node;
            }
#line 2098 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 437 "src/ada.y" /* yacc.c:1646  */
    {
                tempNode->identifierType = TYPEBOOL;
                
                tempNode2->parameterTypes.push_back(TYPEBOOL);
                // if tempNode has name  means we are storing arg paramaters 
                if(tempNode->identifierName == "")
                {

                }
                else if(s.insert( tempNode) == -1)
                {
                    yyerror("same idenifier name in a symbolTable\n");
                }
                tempNode = new node;
            }
#line 2118 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 454 "src/ada.y" /* yacc.c:1646  */
    {
                    // if no return means this is a procedure
                    tempNode2->isFunction = false;
                    tempNode2->parameterTypes.push_back(-1);
                }
#line 2128 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 459 "src/ada.y" /* yacc.c:1646  */
    {
                    // if return means this is a function
    tempNode2->isFunction = true;
    tempNode2->identifierType = TYPEFUNCTION;
    Trace("detect RETURN\n");
}
#line 2139 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 470 "src/ada.y" /* yacc.c:1646  */
    {
                    //for block one or more statement
                }
#line 2147 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 474 "src/ada.y" /* yacc.c:1646  */
    { 
                // for program zero or more statement
                Trace("statements\n");
            }
#line 2156 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 477 "src/ada.y" /* yacc.c:1646  */
    {}
#line 2162 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 479 "src/ada.y" /* yacc.c:1646  */
    {}
#line 2168 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 484 "src/ada.y" /* yacc.c:1646  */
    {}
#line 2174 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 487 "src/ada.y" /* yacc.c:1646  */
    { 
                        (yyval.Token).tokenType = (yyvsp[-1].Token).tokenType; 
                    }
#line 2182 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 490 "src/ada.y" /* yacc.c:1646  */
    { (yyval.Token).tokenType = (yyvsp[0].Token).tokenType; }
#line 2188 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 493 "src/ada.y" /* yacc.c:1646  */
    {
                //check variable exist
                res = s.findVariable(*(yyvsp[-3].Token).name);
                if(res == NULL)
                {
                    yyerror("cannot find the IDENTIFIER: " + *(yyvsp[-3].Token).name);
                    
                }
                /*NEW*/
                if (res->isGlobal){
                    file << "        putstatic " << printVariableType(res->identifierType)<<" "<<  programName << "." << res->identifierName<< "\n";
                }else{
                    file << "        istore " << to_string(res->id) << "\n";
                }
                    
                /*NEW*/
                // check type consistent
                if(res->identifierType == TYPESTRING)
                {
                    if( (yyvsp[-1].Token).tokenType == TYPESTRING)
                    {
                       
                    }
                    else
                    {
                        yyerror("type is not consistent\n");
                    }
                }
                else if (res->identifierType == TYPEBOOL)
                {
                    if( (yyvsp[-1].Token).tokenType == TYPEBOOL)
                    {
                       
                    }
                    else
                    {
                        yyerror("type is not consistent\n");
                    }
                }
                else if (res->identifierType == TYPEINT)
                {
                    if((yyvsp[-1].Token).tokenType == TYPEREAL)
                    {
                        Trace("right expression coercion REAL -> INT  \n");
                    }
                    else if((yyvsp[-1].Token).tokenType != TYPEINT)
                    {
                        yyerror("type is not consistent\n");
                    }
                }
                else if (res->identifierType == TYPEREAL)
                {
                    if((yyvsp[-1].Token).tokenType == TYPEINT)
                    {
                        Trace("right expression coercion INT -> REAL  \n");
                    }
                    else if((yyvsp[-1].Token).tokenType != TYPEREAL)
                    {
                        yyerror("type is not consistent\n");
                    }
                }
                else 
                {
                    yyerror("left operand must be int ,string, bool, real!\n");
                }
                //check constant variable
                if(res->isConstant == 1)
                {
                    yyerror("constant cannot reassignment! \n");
                }
                
                Trace("detect assignment\n");
            }
#line 2266 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 567 "src/ada.y" /* yacc.c:1646  */
    {
                    // check index type
                    if((yyvsp[-4].Token).tokenType != TYPEINT)
                    {
                        yyerror("array index must be integer! \n");
                    }
                    // check variable exist
                    res = s.findVariable(*(yyvsp[-6].Token).name);
                    if(res == NULL)
                    {
                        yyerror("cannot find the IDENTIFIER: " + *(yyvsp[-6].Token).name);
                        
                    }
                    if(res->identifierType != TYPEARRAY)
                    {
                        yyerror("identifier is not a array! \n");
                    }
                    // check index type
                    if(res->arrayType == TYPEINT )
                    {
                        if((yyvsp[-1].Token).tokenType == TYPEREAL)
                        {
                            Trace("right expression coercion REAL -> INT  \n");
                        }
                        else if ((yyvsp[-1].Token).tokenType != TYPEINT)
                        {
                            yyerror("type is not consistent\n");
                        }
                    }
                    else if (res->arrayType == TYPEREAL)
                    {
                        if((yyvsp[-1].Token).tokenType == TYPEINT)
                        {
                            Trace("right expression coercion INT -> REAL  \n");
                        }
                        else if ((yyvsp[-1].Token).tokenType != TYPEREAL)
                        {
                            yyerror("type is not consistent\n");
                        }
                    }
                    else if (res->arrayType != (yyvsp[-1].Token).tokenType)
                    {
                        yyerror("type is not consistent\n");
                    }
                    Trace("Array assignment\n");
                }
#line 2317 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 614 "src/ada.y" /* yacc.c:1646  */
    { 
                /*NEW*/
                file << "       getstatic java.io.PrintStream java.lang.System.out\n";
                /*NEW*/ 
            }
#line 2327 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 619 "src/ada.y" /* yacc.c:1646  */
    {
                if((yyvsp[0].Token).tokenType == TYPESTRING){
                    file << "       invokevirtual void java.io.PrintStream.print(java.lang.String)\n";
                }else if((yyvsp[0].Token).tokenType == TYPEBOOL){
                    file << "       invokevirtual void java.io.PrintStream.print(boolean)\n";
                }else if((yyvsp[0].Token).tokenType == TYPEINT){
                    file << "       invokevirtual void java.io.PrintStream.print(int)\n";
                }
                
            }
#line 2342 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 630 "src/ada.y" /* yacc.c:1646  */
    { 
                /*NEW*/
                file << "       getstatic java.io.PrintStream java.lang.System.out\n";
                /*NEW*/ 
            }
#line 2352 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 635 "src/ada.y" /* yacc.c:1646  */
    {
                if((yyvsp[0].Token).tokenType == TYPESTRING){
                    file << "       invokevirtual void java.io.PrintStream.println(java.lang.String)\n";
                }else if((yyvsp[0].Token).tokenType == TYPEINT){
                    file << "       invokevirtual void java.io.PrintStream.println(int)\n";
                }else if((yyvsp[0].Token).tokenType == TYPEBOOL){
                    file << "       invokevirtual void java.io.PrintStream.println(boolean)\n";
                }
            }
#line 2366 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 645 "src/ada.y" /* yacc.c:1646  */
    {
                    res = s.findVariable(*(yyvsp[0].Token).name);
                    s.dumpAllTable();
                    if(res == NULL)
                    {
                        yyerror("cannot find the IDENTIFIER\n");
                    }
                    Trace("READ \n");
                }
#line 2380 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 655 "src/ada.y" /* yacc.c:1646  */
    {
                returnCount++;
                file <<"        ireturn\n";
            }
#line 2389 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 660 "src/ada.y" /* yacc.c:1646  */
    {
                returnCount++;
                file <<"        return\n";
            }
#line 2398 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 665 "src/ada.y" /* yacc.c:1646  */
    {
                            // check expression type
                            if((yyvsp[-1].Token).tokenType != TYPEINT && (yyvsp[-1].Token).tokenType != TYPEREAL && (yyvsp[-1].Token).tokenType != TYPEBOOL)
                            {
                                yyerror("error type when '(expression)' \n");
                            }
                            //pass type
                            (yyval.Token).tokenType = (yyvsp[-1].Token).tokenType;
                            (yyval.Token).realVal = (yyvsp[-1].Token).realVal;
                            (yyval.Token).boolVal = (yyvsp[-1].Token).boolVal;
                            cout<< "calculate val: "<<(yyval.Token).realVal<<"\n";
                            cout<< "calculate bool  val: "<<(yyval.Token).boolVal<<"\n";
                        }
#line 2416 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 679 "src/ada.y" /* yacc.c:1646  */
    {
                            // implication type coercion and type check
                            if((yyvsp[-2].Token).tokenType != TYPEINT && (yyvsp[-2].Token).tokenType != TYPEREAL)
                            {
                                yyerror("error type when '+' \n");
                            }
                            if((yyvsp[0].Token).tokenType != TYPEINT && (yyvsp[0].Token).tokenType != TYPEREAL)
                            {
                                yyerror("error type when '+' \n");
                            }
                            else if((yyvsp[-2].Token).tokenType == TYPEINT && (yyvsp[0].Token).tokenType == TYPEREAL)
                            {
                                Trace("left operand coercion INT -> REAL  \n");
                                (yyval.Token).tokenType = TYPEREAL;
                            }
                            else if((yyvsp[-2].Token).tokenType == TYPEREAL && (yyvsp[0].Token).tokenType == TYPEINT)
                            {
                                Trace("right operand coercion INT -> REAL  \n");
                                (yyval.Token).tokenType = TYPEREAL;
                            }
                            else if ((yyvsp[-2].Token).tokenType == TYPEINT && (yyvsp[0].Token).tokenType == TYPEINT)
                            {
                                (yyval.Token).tokenType = TYPEINT;
                            }
                            else
                            {
                                (yyval.Token).tokenType = TYPEREAL;
                                
                            }
                            Trace("detect '+' \n");
                            (yyval.Token).realVal = (yyvsp[-2].Token).realVal + (yyvsp[0].Token).realVal;
                            /*NEW*/
                            if(!isGlobalDeclaration)
                            file << "       iadd\n";
                            /*NEW*/
                            cout<< "calculate val: "<<(yyval.Token).realVal<<"\n";
                        }
#line 2458 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 717 "src/ada.y" /* yacc.c:1646  */
    {
                            // implication type coercion and type check
                            if((yyvsp[-2].Token).tokenType != TYPEINT && (yyvsp[-2].Token).tokenType != TYPEREAL)
                            {
                                yyerror("error type when '-' \n");
                            }
                            if((yyvsp[0].Token).tokenType != TYPEINT && (yyvsp[0].Token).tokenType != TYPEREAL)
                            {
                                yyerror("error type when '-' \n");
                            }
                            else if((yyvsp[-2].Token).tokenType == TYPEINT && (yyvsp[0].Token).tokenType == TYPEREAL)
                            {
                                Trace("left operand coercion INT -> REAL  \n");
                                (yyval.Token).tokenType = TYPEREAL;
                            }
                            else if((yyvsp[-2].Token).tokenType == TYPEREAL && (yyvsp[0].Token).tokenType == TYPEINT)
                            {
                                Trace("right operand coercion INT -> REAL  \n");
                                (yyval.Token).tokenType = TYPEREAL;
                            }
                            else if ((yyvsp[-2].Token).tokenType == TYPEINT && (yyvsp[0].Token).tokenType == TYPEINT)
                            {
                                (yyval.Token).tokenType = TYPEINT;
                            }
                            else
                            {
                                (yyval.Token).tokenType = TYPEREAL;
                            }
                            Trace("detect '-' \n");
                            (yyval.Token).realVal = (yyvsp[-2].Token).realVal - (yyvsp[0].Token).realVal;
                            /*NEW*/
                            if(!isGlobalDeclaration)
                            file << "       isub\n";
                            /*NEW*/
                            cout<< "calculate val: "<<(yyval.Token).realVal<<"\n";
                        }
#line 2499 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 754 "src/ada.y" /* yacc.c:1646  */
    {
                            // implication type coercion and type check
                            if((yyvsp[-2].Token).tokenType != TYPEINT && (yyvsp[-2].Token).tokenType != TYPEREAL)
                            {
                                yyerror("error type when '*' \n");
                            }
                            if((yyvsp[-2].Token).tokenType != TYPEINT && (yyvsp[0].Token).tokenType != TYPEREAL)
                            {
                                yyerror("error type when '*' \n");
                            }
                            else if((yyvsp[-2].Token).tokenType == TYPEINT && (yyvsp[0].Token).tokenType == TYPEREAL)
                            {
                                Trace("left operand coercion INT -> REAL  \n");
                                (yyval.Token).tokenType = TYPEREAL;
                            }
                            else if((yyvsp[-2].Token).tokenType == TYPEREAL && (yyvsp[0].Token).tokenType == TYPEINT)
                            {
                                Trace("right operand coercion INT -> REAL  \n");
                                (yyval.Token).tokenType = TYPEREAL;
                            }
                            else if ((yyvsp[-2].Token).tokenType == TYPEINT && (yyvsp[0].Token).tokenType == TYPEINT)
                            {
                                (yyval.Token).tokenType = TYPEINT;
                            }
                            else
                            {
                                (yyval.Token).tokenType = TYPEREAL;
                            }
                            Trace("detect '*' \n");
                            (yyval.Token).realVal = (yyvsp[-2].Token).realVal * (yyvsp[0].Token).realVal;
                            /*NEW*/
                            if(!isGlobalDeclaration)
                            file << "       imul\n";
                            /*NEW*/
                            cout<< "calculate val: "<<(yyval.Token).realVal<<"\n";
                        }
#line 2540 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 791 "src/ada.y" /* yacc.c:1646  */
    {
                            // implication type coercion and type check
                            if((yyvsp[-2].Token).tokenType != TYPEINT && (yyvsp[-2].Token).tokenType != TYPEREAL)
                            {
                                yyerror("error type when '/' \n");
                            }
                            if((yyvsp[0].Token).tokenType != TYPEINT && (yyvsp[0].Token).tokenType != TYPEREAL)
                            {
                                yyerror("error type when '/' \n");
                            }
                            else if((yyvsp[-2].Token).tokenType == TYPEINT && (yyvsp[0].Token).tokenType == TYPEREAL)
                            {
                                Trace("left operand coercion INT -> REAL  \n");
                                (yyval.Token).tokenType = TYPEREAL;
                            }
                            else if((yyvsp[-2].Token).tokenType == TYPEREAL && (yyvsp[0].Token).tokenType == TYPEINT)
                            {
                                Trace("right operand coercion INT -> REAL  \n");
                                (yyval.Token).tokenType = TYPEREAL;
                            }
                            else if ((yyvsp[-2].Token).tokenType == TYPEINT && (yyvsp[0].Token).tokenType == TYPEINT)
                            {
                                (yyval.Token).tokenType = TYPEINT;
                            }
                            else
                            {
                                (yyval.Token).tokenType = TYPEREAL;
                            }
                            (yyval.Token).realVal = (yyvsp[-2].Token).realVal / (yyvsp[0].Token).realVal;
                            /*NEW*/
                            if(!isGlobalDeclaration)
                            file << "       idiv\n";
                            /*NEW*/
                            cout<< "calculate val: "<<(yyval.Token).realVal<<"\n";
                            Trace("detect '/' \n");
                        }
#line 2581 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 828 "src/ada.y" /* yacc.c:1646  */
    {
                            // type check
                            if((yyvsp[-2].Token).tokenType != TYPEBOOL)
                            {
                                yyerror("error type when 'and' \n");
                            }
                            if((yyvsp[0].Token).tokenType != TYPEBOOL)
                            {
                                yyerror("error type when 'and' \n");
                            }
                            (yyval.Token).tokenType = TYPEBOOL;
                            (yyval.Token).boolVal = ((yyvsp[-2].Token).boolVal && (yyvsp[0].Token).boolVal);
                            /*NEW*/
                            if(!isGlobalDeclaration)
                            file << "       iand\n";
                            /*NEW*/
                            Trace("detect 'AND' \n");
                            cout<< "calculate AND bool val: "<<(yyval.Token).boolVal<<"\n";
                        }
#line 2605 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 848 "src/ada.y" /* yacc.c:1646  */
    {
                            // type check
                            if((yyvsp[-2].Token).tokenType != TYPEBOOL)
                            {
                                yyerror("error type when 'or' \n");
                            }
                            if((yyvsp[0].Token).tokenType != TYPEBOOL)
                            {
                                yyerror("error type when 'or' \n");
                            }
                            (yyval.Token).tokenType = TYPEBOOL;
                            (yyval.Token).boolVal = ((yyvsp[-2].Token).boolVal || (yyvsp[0].Token).boolVal);
                            /*NEW*/
                            if(!isGlobalDeclaration)
                            file << "       ior\n";
                            /*NEW*/
                            cout<< "calculate OR bool val: "<<(yyval.Token).boolVal<<"\n";
                            Trace("detect 'OR' \n");
                        }
#line 2629 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 868 "src/ada.y" /* yacc.c:1646  */
    {
                            // type check
                            if((yyvsp[0].Token).tokenType != TYPEBOOL)
                            {
                                yyerror("error type when 'not' \n");
                            }
                            (yyval.Token).tokenType = TYPEBOOL;
                            (yyval.Token).boolVal = !((yyvsp[0].Token).boolVal);
                            
                            Trace("detect 'NOT' \n");
                            /*NEW*/
                            if(!isGlobalDeclaration){
                                file << "       sipush 1\n";
                                file << "       ixor\n";
                            }
                                
                            /*NEW*/
                            cout<< "calculate NOT bool val: "<<(yyval.Token).boolVal<<"\n";
                        }
#line 2653 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 888 "src/ada.y" /* yacc.c:1646  */
    {
                            // type check
                            if((yyvsp[-2].Token).tokenType != TYPEINT && (yyvsp[-2].Token).tokenType != TYPEREAL)
                            {
                                yyerror("error type when '<' \n");
                            }
                            if((yyvsp[0].Token).tokenType != TYPEINT && (yyvsp[0].Token).tokenType != TYPEREAL)
                            {
                                yyerror("error type when '<' \n");
                            }
                            (yyval.Token).tokenType = TYPEBOOL;
                            (yyval.Token).boolVal = ((yyvsp[-2].Token).realVal < (yyvsp[0].Token).realVal);
                            /*NEW*/
                            if(!isGlobalDeclaration){
                                file << "       isub\n";
                                file << "       iflt "<< "L" << to_string(labelCount)<< "\n";
                                file << "       iconst_0\n";
                                file << "       goto " << "L" << to_string(labelCount + 1) << "\n";
                                file <<"L" << to_string(labelCount)<<": iconst_1"<< "\n";
                                file << "L" << to_string(labelCount + 1) << ":\n";
                                file << "nop\n";
                                labelCount += 2;
                            }
                            /*NEW*/
                            cout<< "calculate bool val: "<<(yyval.Token).boolVal<<"\n";
                            Trace("detect '<' \n");
                        }
#line 2685 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 916 "src/ada.y" /* yacc.c:1646  */
    {
                            // type check
                            if((yyvsp[-2].Token).tokenType != TYPEINT && (yyvsp[-2].Token).tokenType != TYPEREAL)
                            {
                                yyerror("error type when '>' \n");
                            }
                            
                            if((yyvsp[0].Token).tokenType != TYPEINT && (yyvsp[0].Token).tokenType != TYPEREAL)
                            {
                                yyerror("error type when '>' \n");
                            }
                            (yyval.Token).tokenType = TYPEBOOL;
                            (yyval.Token).boolVal = ((yyvsp[-2].Token).realVal > (yyvsp[0].Token).realVal);
                            /*NEW*/
                            if(!isGlobalDeclaration){
                                file << "       isub\n";
                                file << "       ifgt "<< "L" << to_string(labelCount)<< "\n";
                                file << "       iconst_0\n";
                                file << "       goto " << "L" << to_string(labelCount + 1) << "\n";
                                file <<"L" << to_string(labelCount)<<": iconst_1"<< "\n";
                                file << "L" << to_string(labelCount + 1) << ":\n";
                                file << "nop\n";
                                labelCount += 2;
                            }
                            /*NEW*/
                            cout<< "calculate> bool val: "<<(yyval.Token).boolVal<<"\n";
                            Trace("detect '>' \n");
                        }
#line 2718 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 945 "src/ada.y" /* yacc.c:1646  */
    {
                            // type check
                            if((yyvsp[-2].Token).tokenType != (yyvsp[0].Token).tokenType)
                            {
                                yyerror("error type when '=' \n");
                            }
                            (yyval.Token).tokenType = TYPEBOOL;
                            (yyval.Token).boolVal = ((yyvsp[-2].Token).realVal == (yyvsp[0].Token).realVal);
                            /*NEW*/
                            if(!isGlobalDeclaration){
                                file << "       isub\n";
                                file << "       ifeq "<< "L" << to_string(labelCount)<< "\n";
                                file << "       iconst_0\n";
                                file << "       goto " << "L" << to_string(labelCount + 1) << "\n";
                                file <<"L" << to_string(labelCount)<<": iconst_1"<< "\n";
                                file << "L" << to_string(labelCount + 1) << ":\n";
                                file << "nop\n";
                                labelCount += 2;
                            }
                            /*NEW*/
                            cout<< "calculate= bool val: "<<(yyval.Token).boolVal<<"\n";;
                            Trace("detect '=' \n");
                        }
#line 2746 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 969 "src/ada.y" /* yacc.c:1646  */
    {
                            // type check
                            if((yyvsp[-2].Token).tokenType != (yyvsp[0].Token).tokenType)
                            {
                                yyerror("error type when '%' \n");
                            }
                            (yyval.Token).tokenType = TYPEINT;
                            // $$.realVal = float((int($1.realVal) % int($3.realVal)));
                            /*NEW*/
                            if(!isGlobalDeclaration){
                                file << "       irem\n";
                            }
                            /*NEW*/
                            cout<< "calculate= real val: "<<(yyval.Token).realVal<<"\n";;
                            
                        }
#line 2767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 986 "src/ada.y" /* yacc.c:1646  */
    {
                            // type check
                            if((yyvsp[-2].Token).tokenType != TYPEINT && (yyvsp[-2].Token).tokenType != TYPEREAL)
                            {
                                yyerror("error type when '>=' \n");
                            }
                            
                            if((yyvsp[0].Token).tokenType != TYPEINT && (yyvsp[0].Token).tokenType != TYPEREAL)
                            {
                                yyerror("error type when '>=' \n");
                            }
                            (yyval.Token).tokenType = TYPEBOOL;
                            (yyval.Token).boolVal = ((yyvsp[-2].Token).realVal >= (yyvsp[0].Token).realVal);
                            if(!isGlobalDeclaration){
                                file << "       isub\n";
                                file << "       ifge "<< "L" << to_string(labelCount)<< "\n";
                                file << "       iconst_0\n";
                                file << "       goto " << "L" << to_string(labelCount + 1) << "\n";
                                file <<"L" << to_string(labelCount)<<": iconst_1"<< "\n";
                                file << "L" << to_string(labelCount + 1) << ":\n";
                                file << "nop\n";
                                labelCount += 2;
                            }
                            cout<< "calculate>= bool val: "<<(yyval.Token).boolVal<<"\n";
                            Trace("detect '>=' \n");
                        }
#line 2798 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 1013 "src/ada.y" /* yacc.c:1646  */
    {
                            // type check
                            if((yyvsp[-2].Token).tokenType != TYPEINT && (yyvsp[-2].Token).tokenType != TYPEREAL)
                            {
                                yyerror("error type when '<=' \n");
                            }
                            if((yyvsp[0].Token).tokenType != TYPEINT && (yyvsp[0].Token).tokenType != TYPEREAL)
                            {
                                yyerror("error type when '<=' \n");
                            }
                            (yyval.Token).tokenType = TYPEBOOL;
                            (yyval.Token).boolVal = ((yyvsp[-2].Token).realVal <= (yyvsp[0].Token).realVal);
                            if(!isGlobalDeclaration){
                                file << "       isub\n";
                                file << "       ifle "<< "L" << to_string(labelCount)<< "\n";
                                file << "       iconst_0\n";
                                file << "       goto " << "L" << to_string(labelCount + 1) << "\n";
                                file <<"L" << to_string(labelCount)<<": iconst_1"<< "\n";
                                file << "L" << to_string(labelCount + 1) << ":\n";
                                labelCount += 2;
                            }
                            cout<< "calculate<= bool val: " <<(yyval.Token).boolVal<<"\n";
                            Trace("detect '<=' \n");
                        }
#line 2827 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 1038 "src/ada.y" /* yacc.c:1646  */
    {
                            // type check
                            if((yyvsp[0].Token).tokenType != (yyvsp[-2].Token).tokenType)
                            {
                                yyerror("error type when '/=' \n");
                            }
                            (yyval.Token).tokenType = TYPEBOOL;
                            (yyval.Token).boolVal = ((yyvsp[-2].Token).realVal != (yyvsp[0].Token).realVal);
                            if(!isGlobalDeclaration){
                                file << "       isub\n";
                                file << "       ifne "<< "L" << to_string(labelCount)<< "\n";
                                file << "       iconst_0\n";
                                file << "       goto " << "L" << to_string(labelCount + 1) << "\n";
                                file <<"L" << to_string(labelCount)<<": iconst_1"<< "\n";
                                file << "L" << to_string(labelCount + 1) << ":\n";
                                file << "nop\n";
                                labelCount += 2;
                            }
                            cout<< "calculate /= bool val:"  <<(yyval.Token).boolVal<<"\n";
                            Trace("detect '/=' \n");
                        }
#line 2853 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 1060 "src/ada.y" /* yacc.c:1646  */
    {
                    // type check
                    if((yyvsp[0].Token).tokenType != TYPEINT && (yyvsp[0].Token).tokenType != TYPEREAL)
                            {
                                yyerror("error type when '-' \n");
                            }
                    (yyval.Token).tokenType = (yyvsp[0].Token).tokenType;
                    Trace("detect 'UMINUS ' \n");
                    (yyval.Token).realVal =  -1* (yyvsp[0].Token).realVal;
                    /*NEW*/
                            if(!isGlobalDeclaration)
                            file << "      ineg\n";
                    /*NEW*/
                    cout<< "calculate val: "<<(yyval.Token).realVal<<"\n";
                }
#line 2873 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 1076 "src/ada.y" /* yacc.c:1646  */
    {
                    // type check
                    (yyval.Token).tokenType = TYPEREAL;
                    Trace("+ REAL\n");
                    (yyval.Token).realVal =  (yyvsp[0].Token).realVal;
                    cout<< "calculate val: "<<(yyval.Token).realVal<<"\n";
                }
#line 2885 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 1084 "src/ada.y" /* yacc.c:1646  */
    {
                    // type check
                    (yyval.Token).tokenType = TYPEINT;
                    (yyval.Token).realVal =  (yyvsp[0].Token).realVal;
                    cout<< "calculate val: "<<(yyval.Token).realVal<<"\n";
                }
#line 2896 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 1091 "src/ada.y" /* yacc.c:1646  */
    {
                    
                    (yyval.Token).tokenType = TYPEINT;  
                    (yyval.Token).realVal =  (yyvsp[0].Token).realVal;
                    (yyvsp[0].Token).intVal = (yyvsp[0].Token).realVal;
                    (yyval.Token).isVariable = false;
                    /*New*/
                    if(!isGlobalDeclaration)
                    file <<"        sipush " + to_string((yyvsp[0].Token).intVal) <<"\n";

                    Trace("INT\n");
                    /*New*/
                }
#line 2914 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 1105 "src/ada.y" /* yacc.c:1646  */
    {
                    if(!isGlobalDeclaration){

                        file << "       ldc \"";

                        tempStr3 = *(yyvsp[0].Token).strVal;
                        for (int i = 0; i< tempStr3.size(); i++)
                        {
                           file << tempStr3[i];
                        }
                        file <<"\""<<"\n";
                    }
                    
                    (yyval.Token).tokenType = TYPESTRING;  
                    (yyval.Token).isVariable = false;
                    *(yyval.Token).strVal = *(yyvsp[0].Token).strVal; 
                    Trace("STR\n");
                }
#line 2937 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 1124 "src/ada.y" /* yacc.c:1646  */
    {
                    (yyval.Token).tokenType = TYPEBOOL; 
                    (yyval.Token).boolVal = (yyvsp[0].Token).boolVal;
                    (yyval.Token).isVariable = false;
                    if((yyvsp[0].Token).boolVal){
                        if(!isGlobalDeclaration)
                        file <<"        iconst_1\n";
                    } else
                    {
                        if(!isGlobalDeclaration)
                        file <<"        iconst_0\n";
                    }
                    Trace("BOOL\n");
                }
#line 2956 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 1139 "src/ada.y" /* yacc.c:1646  */
    {
                    (yyval.Token).tokenType = TYPEREAL; 
                    (yyval.Token).realVal =  (yyvsp[0].Token).realVal;  
                    (yyval.Token).isVariable = false;
                    Trace("REALL\n");
                }
#line 2967 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 1146 "src/ada.y" /* yacc.c:1646  */
    {
                    // check variable exist
                    res = s.findVariable(*(yyvsp[0].Token).name);
                    (yyval.Token).isVariable = true;
                    if(isGlobalDeclaration){
                        cout<<"GGGGGGGGGGGGGGGGGGGG";
                        cout<< *(yyvsp[0].Token).name <<res->realVal;
                        (yyval.Token).realVal = res->realVal;
                        (yyval.Token).tokenType = res->identifierType;
                    }
                    else{
                        if(res == NULL)
                        {
                            yyerror("cannot find the IDENTIFIER\n");
                        } 
                        else if(res->identifierType == TYPEPROCEDURE)
                        {
                            yyerror("this is a procedure, not a function!\n");
                        }else if (res->identifierType == TYPEFUNCTION)
                        {
                            // only function could return
                            (yyval.Token).tokenType = res->parameterTypes[res->parameterTypes.size()-1];
                            // if enter this block means the function do not have parameters
                            file << "       invokestatic " << printVariableType(res->parameterTypes.back()) << " " << programName << "." << res->identifierName;
                            file << "()\n";
                            if(res->parameterTypes.size() > 1) 
                            {
                                yyerror("the function has parameters !\n");
                            }
                        } 
                        else
                        {
                            /*New*/
                            if(res->identifierType == TYPESTRING){
                                
                                    file << "       ldc \""; 
                                    for (int i = 0; i< res->strVal.size(); i++)
                                    {
                                    file << res->strVal[i];
                                    }
                                    file  << "\"\n";
                            }else{
                                if(res->isGlobal){
                                    file << "       getstatic int " << programName <<"."<< res->identifierName <<"\n";
                                }else{
                                    file << "       iload " << res->id <<"\n";
                                }
                            }
                            
                            /*New*/
                            (yyval.Token).tokenType = res->identifierType;
                            Trace("ID\n"); 
                        }
                    }
                    
                }
#line 3028 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 1203 "src/ada.y" /* yacc.c:1646  */
    {
                    // create arg scope
                    argTypeTemp.push_back(row);
                }
#line 3037 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 1208 "src/ada.y" /* yacc.c:1646  */
    {
                    res = s.findVariable(*(yyvsp[-4].Token).name);
                    if(res == NULL)
                    {
                        yyerror("cannot find the IDENTIFIER\n");
                    }
                    // compare formal parameter and actual parameter count consistent
                    if(argTypeTemp[argTypeTemp.size()-1].size() != res->parameterTypes.size() - 1 && !( argTypeTemp[argTypeTemp.size()-1].size() == 0 && res->parameterTypes.size()== 0 ) )
                    {
                        cout<< "argTypeTemp: " <<argTypeTemp[argTypeTemp.size()-1].size()<< "\n";
                        cout<< "res->parameterTypes.size() - 1 "<<res->parameterTypes.size() - 1<< "\n";
                        yyerror("parameter count is not consistent\n");
                    }
                     // compare formal parameter and actual parameter type consistent
                    for(int i = 0; i < argTypeTemp[argTypeTemp.size()-1].size(); i++)
                    {
                        
                        cout<<"formal parameter index :"<< i <<" type: " << res->parameterTypes[i]<<" \n";
                        cout<<" actual parameter index :"<< i <<" type: " << argTypeTemp[argTypeTemp.size()-1][i]<<" \n";
                        if( res->parameterTypes[i] != argTypeTemp[argTypeTemp.size()-1][i])
                        {
                            yyerror("parameter type is not consistent\n");
                        }
                        
                    }
                    cout<<'\n';
                    if(res !=NULL)
                    {
                        
                        if(!(res->identifierType == TYPEFUNCTION || res->identifierType == TYPEPROCEDURE))
                        {
                            yyerror("the identifier is not a procedure or a function\n");
                        }
                        // procedure can not be a function
                        if(!res->isFunction)
                        {
                            yyerror("this is a procedure, not a function\n");
                        }
                        cout<<"Function Name: "<< res->identifierName<<"\n";
                        
                    } 
                    else
                    {
                        yyerror("cannot find the function\n");
                    } 
                    /*NEW*/
                    file << "       invokestatic " << printVariableType(res->parameterTypes.back()) << " " << programName << "." << res->identifierName;
                    file << "(";
                    for (int i = 0; i < res->parameterTypes.size() - 1; i++){
                        if(i == 0)
                        file << printVariableType(res->parameterTypes[i]);
                        else
                        file <<", "<< printVariableType(res->parameterTypes[i]);
                    }
                    file << ")\n";

                    /*NEW*/
                    (yyval.Token).tokenType = res->parameterTypes[res->parameterTypes.size() - 1];
                    res = NULL;
                    // exit arg scope
                    argTypeTemp.pop_back();
                    
                    Trace("detect function calls\n");
                }
#line 3106 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 1273 "src/ada.y" /* yacc.c:1646  */
    {
                    res = s.findVariable(*(yyvsp[-3].Token).name);
                    if(res == NULL)
                    {
                        yyerror("cannot find the IDENTIFIER\n");
                    } 
                    if(res->identifierType != TYPEARRAY)
                    {
                        yyerror("this is not a array!\n");
                    }

                    if((yyvsp[-1].Token).tokenType != TYPEINT )
                    {
                        yyerror("array index is not num\n");
                    }
                    else
                    {
                        (yyval.Token).tokenType = res->arrayType;
                        Trace("array ID\n"); 
                    }
                }
#line 3132 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 1298 "src/ada.y" /* yacc.c:1646  */
    {
                                 
                            }
#line 3140 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 1302 "src/ada.y" /* yacc.c:1646  */
    {
                                cout<<"Aname: " <<*(yyvsp[0].Token).name<<"\n";
                                argTypeTemp[argTypeTemp.size()-1].push_back((yyvsp[0].Token).tokenType);
                            }
#line 3149 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 1307 "src/ada.y" /* yacc.c:1646  */
    {
                                cout<<"Bname: " <<*(yyvsp[0].Token).name<<"\n";
                                argTypeTemp[argTypeTemp.size()-1].push_back((yyvsp[0].Token).tokenType);
                            }
#line 3158 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 1310 "src/ada.y" /* yacc.c:1646  */
    {}
#line 3164 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 1314 "src/ada.y" /* yacc.c:1646  */
    {cout<<"#826 create\n";s.createNewSymbolTable(); }
#line 3170 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 1314 "src/ada.y" /* yacc.c:1646  */
    {Trace("BLOCK STATEMENT\n");}
#line 3176 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 1314 "src/ada.y" /* yacc.c:1646  */
    {  s.dumpAllTable(); s.popTable(); }
#line 3182 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 1314 "src/ada.y" /* yacc.c:1646  */
    {
Trace("block\n");
}
#line 3190 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 1318 "src/ada.y" /* yacc.c:1646  */
    { s.dumpAllTable();}
#line 3196 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 1318 "src/ada.y" /* yacc.c:1646  */
    {Trace("BLOCK STATEMENT\n");}
#line 3202 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 1318 "src/ada.y" /* yacc.c:1646  */
    {  s.dumpAllTable();  }
#line 3208 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 1319 "src/ada.y" /* yacc.c:1646  */
    {Trace("procedure_block\n");}
#line 3214 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 1321 "src/ada.y" /* yacc.c:1646  */
    {
    
}
#line 3222 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 1326 "src/ada.y" /* yacc.c:1646  */
    {
                if((yyvsp[0].Token).tokenType != TYPEBOOL)
                {
                    yyerror("IF expression is not boolean expression \n");
                }
                /*NEW*/
                file << "       ifeq IFL" << to_string(ifLabelCount) << "\n";
                ifLabelCountTemp.push_back(ifLabelCount++);
                ifLabelCountTemp.push_back(ifLabelCount++);
                
                /*NEW*/

            }
#line 3240 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 1339 "src/ada.y" /* yacc.c:1646  */
    {}
#line 3246 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 1339 "src/ada.y" /* yacc.c:1646  */
    {}
#line 3252 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 1342 "src/ada.y" /* yacc.c:1646  */
    {
                                /*NEW*/
                                file << "       goto IFL" << to_string(ifLabelCountTemp.back()) << "\n";
                                file << "IFL" << to_string(ifLabelCountTemp[ifLabelCountTemp.size()-2]) << ":\n";
                                file << "nop\n";

                                /*NEW*/
                            }
#line 3265 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 1350 "src/ada.y" /* yacc.c:1646  */
    {
                                /*NEW*/
                                file << "IFL" << to_string(ifLabelCountTemp.back()) << ":\n";
                                file << "nop\n";
                                ifLabelCountTemp.pop_back();
                                ifLabelCountTemp.pop_back();
                                /*NEW*/
                            }
#line 3278 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 1359 "src/ada.y" /* yacc.c:1646  */
    {
                                /*NEW*/
                                file << "IFL" << to_string(ifLabelCountTemp[ifLabelCountTemp.size() - 2]) << ":\n";
                                file << "nop\n";
                                ifLabelCountTemp.pop_back();
                                ifLabelCountTemp.pop_back();
                                /*NEW*/
}
#line 3291 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 1369 "src/ada.y" /* yacc.c:1646  */
    {
                /*NEW*/
                file << "WHL" << to_string(whileLabelCount)<<":\n";
                file << "nop\n";
                whileLabelCountTemp.push_back(whileLabelCount++);

                /*NEW*/
            }
#line 3304 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 1377 "src/ada.y" /* yacc.c:1646  */
    {
                if((yyvsp[0].Token).tokenType != TYPEBOOL)
                {
                    yyerror("WHILE expression is not boolean expression \n");
                }
                /*NEW*/
                file << "       ifeq WHL" << to_string(whileLabelCount)<<"\n";
                whileLabelCountTemp.push_back(whileLabelCount++);
                /*NEW*/
            }
#line 3319 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 1388 "src/ada.y" /* yacc.c:1646  */
    {
                /*NEW*/
                file << "       goto WHL" << to_string(whileLabelCountTemp[whileLabelCountTemp.size() - 2])<<"\n";
                file << "WHL" << to_string(whileLabelCountTemp[whileLabelCountTemp.size() - 1]) << ":\n";
                file << "nop\n";
                whileLabelCountTemp.pop_back();
                whileLabelCountTemp.pop_back();
                /*NEW*/
            }
#line 3333 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 1398 "src/ada.y" /* yacc.c:1646  */
    {
        
        
        // check variavle exist and for variable must be integer!
        res = s.findVariable(*(yyvsp[0].Token).name);
        if(res == NULL)
        {
            yyerror("cannot find the IDENTIFIER\n");
        }else if(res->identifierType != TYPEINT)
        {
            yyerror("for expression must be num!\n");
        }  
        tempNode = new node;
     }
#line 3352 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 1412 "src/ada.y" /* yacc.c:1646  */
    {
        if((yyvsp[0].Token).tokenType != TYPEINT)
        {
            yyerror("for expression must be num!\n");
        }
        forLowerVal = (yyvsp[0].Token).intVal;
       
        forLabelCountTemp.push_back((yyvsp[0].Token).realVal);
        /*New*/
        res = s.findVariable(*(yyvsp[-3].Token).name);
        
        
        if(res->isGlobal){
            file << "       putstatic int " << programName <<"."<< res->identifierName <<"\n";
        }else{         
            file << "       istore " << res->id <<"\n";
        }
        /*New*/
        
    }
#line 3377 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 1432 "src/ada.y" /* yacc.c:1646  */
    {
        /*New*/
        res = s.findVariable(*(yyvsp[-6].Token).name);
        forLabelCountTemp.push_back(forLabelCount);
        //begin
        file << "FORL" << to_string(forLabelCount++)<< ":\n";
        file << "nop\n";

        if(res->isGlobal){
            file << "       getstatic int " << programName <<"."<< res->identifierName <<"\n";
        }else{         
            file << "       iload " << res->id <<"\n";
        }
        /*New*/
    }
#line 3397 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 1447 "src/ada.y" /* yacc.c:1646  */
    {
        if((yyvsp[0].Token).tokenType != TYPEINT)
        {
            yyerror("for expression must be num!\n");
        }
        forLabelCountTemp.push_back((yyvsp[0].Token).intVal);
        
        /*NEW*/
        file << "       isub\n";
        // 20210618
        if((yyvsp[-5].Token).isVariable){
            res = s.findVariable(*(yyvsp[-5].Token).name);
        }else{
            res = NULL;
        }
        
        if (res != NULL){
            if(res->isGlobal){
                file << "       getstatic int " << programName <<"."<< res->identifierName <<"\n";
            }else{         
                file << "       iload " << res->id <<"\n";
            }
            
        }else{
            file << "       sipush " <<(yyvsp[-5].Token).realVal <<"\n";
        }
        if((yyvsp[0].Token).isVariable){
            res = s.findVariable(*(yyvsp[0].Token).name);
        }else{
            res = NULL;
        }
        if (res != NULL){
            if(res->isGlobal){
                file << "       getstatic int " << programName <<"."<< res->identifierName <<"\n";
            }else{         
                file << "       iload " << res->id <<"\n";
            }
            
        }else{
            file << "       sipush " << (yyvsp[0].Token).realVal <<"\n";
        }
        file << "       isub\n";
        file << "       ifle DEC" << to_string(needDecreaseCount) << "\n";
        file << "       ifge FORL" << to_string(forLabelCount) << "\n";
        file << "       goto DEC" << to_string(needDecreaseCount + 1) << "\n";
        file << "DEC" << to_string(needDecreaseCount++)<< ":\nnop\n";
        file << "       ifle FORL" << to_string(forLabelCount) << "\n";
        file << "DEC" << to_string(needDecreaseCount++)<< ":\nnop\n";
        
        
        file << "       iconst_0\n" ;
        file << "       goto FORL" << to_string(forLabelCount + 1) << "\n";
        file << "FORL" << to_string(forLabelCount) << ":\n";
        file << "       iconst_1\n";
        file << "FORL" << to_string(forLabelCount + 1) << ":\n";
        file << "nop\n";
        forLabelCount += 2;
        //exit
        forLabelCountTemp.push_back(forLabelCount);
        file << "       ifeq FORL" << to_string(forLabelCount++) << "\n";


        /*NEW*/
    }
#line 3466 "y.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 1511 "src/ada.y" /* yacc.c:1646  */
    {
        /*NEW*/
        
            res = s.findVariable(*(yyvsp[-15].Token).name);
            if(res->isGlobal){
                file << "       getstatic int " << programName <<"."<< res->identifierName <<"\n";
            }else{         
                file << "       iload " << res->id <<"\n";
            }
            file << "      sipush 1\n";
            
        // 20210618
        if((yyvsp[-12].Token).isVariable){
            res = s.findVariable(*(yyvsp[-12].Token).name);
        }else{
            res = NULL;
        }
        if (res != NULL){
            if(res->isGlobal){
                file << "       getstatic int " << programName <<"."<< res->identifierName <<"\n";
            }else{         
                file << "       iload " << res->id <<"\n";
            }
            
        }else{
            file << "       sipush " << (yyvsp[-12].Token).realVal <<"\n";
        }
        if((yyvsp[-7].Token).isVariable){
            res = s.findVariable(*(yyvsp[-7].Token).name);
        }else{
            res = NULL;
        }
        if (res != NULL){
            if(res->isGlobal){
                file << "       getstatic int " << programName <<"."<< res->identifierName <<"\n";
            }else{         
                file << "       iload " << res->id <<"\n";
            }
            
        }else{
            file << "       sipush " << (yyvsp[-7].Token).realVal <<"\n";
        }
        file << "       isub\n";
        file << "       ifle DEC" << to_string(needDecreaseCount) << "\n";
        file << "       isub\n";
        file << "       goto DEC" << to_string(needDecreaseCount + 1) << "\n";
        file << "DEC" << to_string(needDecreaseCount++)<< ":\nnop\n";
        file << "       iadd\n";
        file << "DEC" << to_string(needDecreaseCount++)<< ":\nnop\n";

        res = s.findVariable(*(yyvsp[-15].Token).name);
        if(res->isGlobal){
            file << "       putstatic int " << programName <<"."<< res->identifierName <<"\n";
        }else{         
            file << "       istore " << res->id <<"\n";
        }
        file << "        goto FORL" << forLabelCountTemp[forLabelCountTemp.size() - 3] << "\n";
        file << "FORL" << forLabelCountTemp[forLabelCountTemp.size() - 1] << ":\n";
        forLabelCountTemp.pop_back();
        forLabelCountTemp.pop_back();
        forLabelCountTemp.pop_back();
        forLabelCountTemp.pop_back();
        file << "nop\n";
        /*NEW*/
        tempNode = new node;
       
     }
#line 3538 "y.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 1580 "src/ada.y" /* yacc.c:1646  */
    {
                    argTypeTemp.push_back(row);
                }
#line 3546 "y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 1583 "src/ada.y" /* yacc.c:1646  */
    {
                    res = s.findVariable(*(yyvsp[-5].Token).name);
                    // compare formal parameter and actual parameter count consistent
                    if(argTypeTemp[argTypeTemp.size()- 1].size() != res->parameterTypes.size() - 1 && !( argTypeTemp[argTypeTemp.size()- 1].size() == 0 && res->parameterTypes.size()== 0 ) )
                    {
                        yyerror("procedure parameter count is not consistent\n");
                    }
                    // compare formal parameter and actual parameter type consistent
                    for(int i = 0; i < argTypeTemp[argTypeTemp.size()- 1].size(); i++)
                    {
                        
                        cout<<"formal parameter index :"<< i <<" type: " << res->parameterTypes[i]<<" \n";
                        cout<<" actual parameter index :"<< i <<" type: " << argTypeTemp[argTypeTemp.size()- 1][i]<<" \n";
                        if( res->parameterTypes[i] != argTypeTemp[argTypeTemp.size()- 1][i])
                        {
                            yyerror("parameter type is not consistent\n");
                        }
                        
                    }
                    cout<<'\n';
                    if(res !=NULL)
                    {
                        
                        if(!(res->identifierType == TYPEFUNCTION || res->identifierType == TYPEPROCEDURE))
                        {
                            yyerror("the identifier is not a procedure or a function\n");
                        }
                        if(res->isFunction)
                        {
                            yyerror("this is a function, not a  procedure\n");
                        }
                        cout<<"Procedure Name: "<< res->identifierName<<"\n";
                        /*NEW*/
                        file << "       invokestatic " << printVariableType(res->parameterTypes.back()) << " " << programName << "." << res->identifierName;
                        file << "(";
                        for (int i = 0; i < res->parameterTypes.size() - 1; i++){
                            if(i == 0)
                            file << printVariableType(res->parameterTypes[i]);
                            else
                            file <<", "<< printVariableType(res->parameterTypes[i]);
                        }
                        file << ")\n";

                    /*NEW*/
                    } 
                    else
                    {
                        yyerror("cannot find the procedure\n");
                    } 
                    res = NULL;
                    argTypeTemp.pop_back();
                    Trace("detect procedure calls\n");
                }
#line 3604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 1637 "src/ada.y" /* yacc.c:1646  */
    {
                        // call procedure with no arg
                        res = s.findVariable(*(yyvsp[-1].Token).name);
                        s.dumpAllTable();
                        if(res == NULL)
                        {
                            yyerror("cannot find the IDENTIFIER\n");
                        }
                        else if (res->isFunction == 1)
                        {
                            yyerror("this is a function, not a  procedure\n");
                        }
                        else if (res->identifierType != TYPEPROCEDURE)
                        {
                            yyerror("this is not a  procedure\n");
                        }
                        /*NEW*/
                        file << "       invokestatic " << printVariableType(res->parameterTypes.back()) << " " << programName << "." << res->identifierName;
                        file << "()\n";
        
    
                        Trace("READ \n");
                        Trace("procedure invocation no parameter");
                    }
#line 3633 "y.tab.c" /* yacc.c:1646  */
    break;


#line 3637 "y.tab.c" /* yacc.c:1646  */
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
#line 1665 "src/ada.y" /* yacc.c:1906  */


int main()
{   
    yyparse();
    file.close();
}

int yyerror(string s)
{
   cout<<"ERROR: "<< s<<"\n";
    exit(-1);
    return 0;
    
}
