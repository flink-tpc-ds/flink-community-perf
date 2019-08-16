/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TOK_INT = 258,
     TOK_LITERAL = 259,
     TOK_PATH = 260,
     TOK_DECIMAL = 261,
     TOK_ID = 262,
     TOK_SQL = 263,
     KW_DEFINE = 264,
     KW_RANDOM = 265,
     KW_UNIFORM = 266,
     KW_RANGE = 267,
     KW_DATE = 268,
     KW_INCLUDE = 269,
     KW_TEXT = 270,
     KW_DIST = 271,
     KW_LIST = 272,
     KW_ROWCOUNT = 273,
     KW_BEGIN = 274,
     KW_END = 275,
     KW_SALES = 276,
     KW_RETURNS = 277,
     KW_DISTMEMBER = 278,
     KW_DISTWEIGHT = 279,
     KW_QUERY = 280,
     KW_STREAM = 281,
     KW_TEMPLATE = 282,
     KW_SEED = 283,
     KW_SCALE = 284,
     KW_SCALE_STEP = 285,
     KW_SET = 286,
     KW_ADD = 287,
     KW_NAMES = 288,
     KW_TYPES = 289,
     KW_WEIGHTS = 290,
     KW_INT = 291,
     KW_VARCHAR = 292,
     KW_DECIMAL = 293,
     KW_LIMIT = 294,
     KW_LIMITA = 295,
     KW_LIMITB = 296,
     KW_LIMITC = 297,
     KW_ULIST = 298,
     WITH = 299,
     UMINUS = 300,
     TCAST = 301
   };
#endif
/* Tokens.  */
#define TOK_INT 258
#define TOK_LITERAL 259
#define TOK_PATH 260
#define TOK_DECIMAL 261
#define TOK_ID 262
#define TOK_SQL 263
#define KW_DEFINE 264
#define KW_RANDOM 265
#define KW_UNIFORM 266
#define KW_RANGE 267
#define KW_DATE 268
#define KW_INCLUDE 269
#define KW_TEXT 270
#define KW_DIST 271
#define KW_LIST 272
#define KW_ROWCOUNT 273
#define KW_BEGIN 274
#define KW_END 275
#define KW_SALES 276
#define KW_RETURNS 277
#define KW_DISTMEMBER 278
#define KW_DISTWEIGHT 279
#define KW_QUERY 280
#define KW_STREAM 281
#define KW_TEMPLATE 282
#define KW_SEED 283
#define KW_SCALE 284
#define KW_SCALE_STEP 285
#define KW_SET 286
#define KW_ADD 287
#define KW_NAMES 288
#define KW_TYPES 289
#define KW_WEIGHTS 290
#define KW_INT 291
#define KW_VARCHAR 292
#define KW_DECIMAL 293
#define KW_LIMIT 294
#define KW_LIMITA 295
#define KW_LIMITB 296
#define KW_LIMITC 297
#define KW_ULIST 298
#define WITH 299
#define UMINUS 300
#define TCAST 301




/* Copy the first part of user declarations.  */
#line 1 "qgen.y"

/* 
 * Legal Notice 
 * 
 * This document and associated source code (the "Work") is a part of a 
 * benchmark specification maintained by the TPC. 
 * 
 * The TPC reserves all right, title, and interest to the Work as provided 
 * under U.S. and international laws, including without limitation all patent 
 * and trademark rights therein. 
 * 
 * No Warranty 
 * 
 * 1.1 TO THE MAXIMUM EXTENT PERMITTED BY APPLICABLE LAW, THE INFORMATION 
 *     CONTAINED HEREIN IS PROVIDED "AS IS" AND WITH ALL FAULTS, AND THE 
 *     AUTHORS AND DEVELOPERS OF THE WORK HEREBY DISCLAIM ALL OTHER 
 *     WARRANTIES AND CONDITIONS, EITHER EXPRESS, IMPLIED OR STATUTORY, 
 *     INCLUDING, BUT NOT LIMITED TO, ANY (IF ANY) IMPLIED WARRANTIES, 
 *     DUTIES OR CONDITIONS OF MERCHANTABILITY, OF FITNESS FOR A PARTICULAR 
 *     PURPOSE, OF ACCURACY OR COMPLETENESS OF RESPONSES, OF RESULTS, OF 
 *     WORKMANLIKE EFFORT, OF LACK OF VIRUSES, AND OF LACK OF NEGLIGENCE. 
 *     ALSO, THERE IS NO WARRANTY OR CONDITION OF TITLE, QUIET ENJOYMENT, 
 *     QUIET POSSESSION, CORRESPONDENCE TO DESCRIPTION OR NON-INFRINGEMENT 
 *     WITH REGARD TO THE WORK. 
 * 1.2 IN NO EVENT WILL ANY AUTHOR OR DEVELOPER OF THE WORK BE LIABLE TO 
 *     ANY OTHER PARTY FOR ANY DAMAGES, INCLUDING BUT NOT LIMITED TO THE 
 *     COST OF PROCURING SUBSTITUTE GOODS OR SERVICES, LOST PROFITS, LOSS 
 *     OF USE, LOSS OF DATA, OR ANY INCIDENTAL, CONSEQUENTIAL, DIRECT, 
 *     INDIRECT, OR SPECIAL DAMAGES WHETHER UNDER CONTRACT, TORT, WARRANTY,
 *     OR OTHERWISE, ARISING IN ANY WAY OUT OF THIS OR ANY OTHER AGREEMENT 
 *     RELATING TO THE WORK, WHETHER OR NOT SUCH AUTHOR OR DEVELOPER HAD 
 *     ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES. 
 * 
 * Contributors:
 * Gradient Systems
 */
#include "config.h"
#include "porting.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#ifdef WIN32
#include <io.h>
#pragma warning(disable: 4305)
#endif

#include "StringBuffer.h"
#include "expr.h"
#include "grammar_support.h"
#include "keywords.h"
#include "substitution.h"
#include "error_msg.h"
#include "tables.h"
#include "qgen_params.h"
#include "tdefs.h"
#include "query_handler.h"
#include "list.h"
#include "dist.h"
#include "scaling.h"


#define DEBUG0(l, fmt) 				if (l <= verbose) printf(fmt)
#define DEBUG1(l, fmt, arg)			if (l <= verbose) printf(fmt, arg)
#define DEBUG2(l, fmt, arg, arg2)	if (l <= verbose) printf(fmt, arg, arg2)

extern file_ref_t file_stack[];

int yylex(void);

#ifdef WIN32
int yyparse(void);
#endif

/* GLOBAL VARIABLES */
int verbose = 0,
	j,
	nRetCode;
ds_key_t i;
char tmpstr[128];
segment_t *pSegment;
substitution_t *pSub;


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 87 "qgen.y"
{
    int		intval;
    char	*strval;
	expr_t	*exprval;
	list_t  *list;
    }
/* Line 193 of yacc.c.  */
#line 281 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 294 "y.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  27
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   236

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  67
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  98
/* YYNRULES -- Number of states.  */
#define YYNSTATES  202

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   301

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,    54,     2,    47,     2,     2,
      59,    60,    48,    45,    62,    46,    66,    49,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    61,    57,
      55,    58,    56,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    51,     2,    63,    50,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    64,     2,    65,     2,     2,     2,     2,
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
      52,    53
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    12,    14,    16,    18,
      22,    28,    34,    36,    39,    45,    53,    63,    65,    67,
      69,    70,    72,    76,    78,    82,    84,    87,    95,    97,
      99,   101,   103,   107,   109,   113,   119,   125,   127,   131,
     133,   135,   137,   139,   143,   149,   154,   156,   158,   163,
     168,   173,   178,   185,   189,   196,   203,   210,   214,   218,
     222,   226,   228,   230,   234,   238,   240,   242,   244,   246,
     248,   250,   252,   254,   256,   258,   260,   262,   264,   268,
     274,   277,   279,   281,   284,   287,   292,   298,   302,   306,
     310,   314,   318,   322,   326,   327,   330,   333,   336
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      68,     0,    -1,    69,    -1,    70,    -1,    69,    70,    -1,
      71,    -1,    83,    -1,    95,    -1,    72,    -1,    54,    14,
      99,    -1,    54,    14,    55,    99,    56,    -1,    16,     7,
      57,    73,    78,    -1,    74,    -1,    73,    74,    -1,    31,
      35,    58,     3,    57,    -1,    31,    34,    58,    59,    76,
      60,    57,    -1,    31,    33,    58,    59,    77,    61,    77,
      60,    57,    -1,    36,    -1,    37,    -1,    38,    -1,    -1,
      75,    -1,    76,    62,    75,    -1,     7,    -1,    77,    62,
       7,    -1,    79,    -1,    78,    79,    -1,    32,    59,    81,
      61,    82,    60,    57,    -1,     3,    -1,     4,    -1,     6,
      -1,    80,    -1,    81,    62,    80,    -1,     3,    -1,    81,
      62,     3,    -1,     9,     7,    58,    85,    57,    -1,     9,
      39,    58,     3,    57,    -1,    85,    -1,    84,    62,    85,
      -1,     4,    -1,     3,    -1,    86,    -1,    91,    -1,    51,
      92,    63,    -1,    51,     7,     3,    98,    63,    -1,    51,
       7,    98,    63,    -1,    29,    -1,    87,    -1,    89,    59,
      84,    60,    -1,    90,    59,    88,    60,    -1,    15,    59,
      93,    60,    -1,    18,    59,     4,    60,    -1,    18,    59,
       4,    62,     4,    60,    -1,    30,    59,    60,    -1,    43,
      59,    85,    62,     3,    60,    -1,    17,    59,    85,    62,
       3,    60,    -1,    12,    59,    85,    62,     3,    60,    -1,
      85,    45,    85,    -1,    85,    46,    85,    -1,    85,    48,
      85,    -1,    85,    49,    85,    -1,    85,    -1,     7,    -1,
      88,    62,    85,    -1,    88,    62,     7,    -1,    13,    -1,
      10,    -1,    16,    -1,    23,    -1,    24,    -1,    11,    -1,
      21,    -1,    22,    -1,    25,    -1,    27,    -1,    26,    -1,
      28,    -1,    94,    -1,    93,    62,    94,    -1,    64,     4,
      62,     3,    65,    -1,    96,    57,    -1,    97,    -1,     8,
      -1,    96,    97,    -1,    96,     8,    -1,    51,     7,    98,
      63,    -1,    51,     7,     3,    98,    63,    -1,    51,    25,
      63,    -1,    51,    26,    63,    -1,    51,    27,    63,    -1,
      51,    28,    63,    -1,    51,    40,    63,    -1,    51,    41,
      63,    -1,    51,    42,    63,    -1,    -1,    66,    19,    -1,
      66,    20,    -1,    66,     3,    -1,     4,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   159,   159,   167,   168,   181,   182,   183,   184,   192,
     197,   208,   211,   212,   215,   216,   217,   220,   221,   222,
     225,   226,   227,   230,   231,   234,   235,   238,   241,   242,
     243,   246,   247,   250,   251,   258,   264,   276,   281,   288,
     292,   296,   297,   302,   306,   310,   314,   318,   321,   325,
     329,   333,   346,   363,   367,   371,   375,   381,   385,   389,
     393,   398,   403,   408,   413,   420,   421,   424,   425,   426,
     429,   430,   431,   434,   435,   436,   437,   440,   445,   452,
     465,   473,   474,   480,   481,   488,   496,   504,   511,   518,
     525,   532,   539,   546,   555,   556,   557,   558,   566
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOK_INT", "TOK_LITERAL", "TOK_PATH",
  "TOK_DECIMAL", "TOK_ID", "TOK_SQL", "KW_DEFINE", "KW_RANDOM",
  "KW_UNIFORM", "KW_RANGE", "KW_DATE", "KW_INCLUDE", "KW_TEXT", "KW_DIST",
  "KW_LIST", "KW_ROWCOUNT", "KW_BEGIN", "KW_END", "KW_SALES", "KW_RETURNS",
  "KW_DISTMEMBER", "KW_DISTWEIGHT", "KW_QUERY", "KW_STREAM", "KW_TEMPLATE",
  "KW_SEED", "KW_SCALE", "KW_SCALE_STEP", "KW_SET", "KW_ADD", "KW_NAMES",
  "KW_TYPES", "KW_WEIGHTS", "KW_INT", "KW_VARCHAR", "KW_DECIMAL",
  "KW_LIMIT", "KW_LIMITA", "KW_LIMITB", "KW_LIMITC", "KW_ULIST", "WITH",
  "'+'", "'-'", "'%'", "'*'", "'/'", "'^'", "'['", "UMINUS", "TCAST",
  "'#'", "'<'", "'>'", "';'", "'='", "'('", "')'", "':'", "','", "']'",
  "'{'", "'}'", "'.'", "$accept", "workload_spec", "statement_list",
  "statement", "include_statement", "dist_statement", "dist_argument_list",
  "dist_argument", "dist_type", "dist_type_list", "dist_name_list",
  "dist_members_list", "dist_member", "dist_value", "dist_value_list",
  "dist_weight_list", "define_statement", "comma_expr_list", "expr",
  "function_call", "arithmetic_expr", "dist_expr_list", "function_name",
  "dist_function_name", "keyword_expr", "keyword_value",
  "replacement_list", "replacement", "query_statement",
  "query_component_list", "substitution", "opt_substitution_suffix",
  "path", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,    43,    45,    37,    42,    47,
      94,    91,   300,   301,    35,    60,    62,    59,    61,    40,
      41,    58,    44,    93,   123,   125,    46
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    67,    68,    69,    69,    70,    70,    70,    70,    71,
      71,    72,    73,    73,    74,    74,    74,    75,    75,    75,
      76,    76,    76,    77,    77,    78,    78,    79,    80,    80,
      80,    81,    81,    82,    82,    83,    83,    84,    84,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    87,    87,    87,
      87,    88,    88,    88,    88,    89,    89,    90,    90,    90,
      91,    91,    91,    92,    92,    92,    92,    93,    93,    94,
      95,    96,    96,    96,    96,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    98,    98,    98,    98,    99
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     3,
       5,     5,     1,     2,     5,     7,     9,     1,     1,     1,
       0,     1,     3,     1,     3,     1,     2,     7,     1,     1,
       1,     1,     3,     1,     3,     5,     5,     1,     3,     1,
       1,     1,     1,     3,     5,     4,     1,     1,     4,     4,
       4,     4,     6,     3,     6,     6,     6,     3,     3,     3,
       3,     1,     1,     3,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     5,
       2,     1,     1,     2,     2,     4,     5,     3,     3,     3,
       3,     3,     3,     3,     0,     2,     2,     2,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    82,     0,     0,     0,     0,     0,     2,     3,     5,
       8,     6,     7,     0,    81,     0,     0,     0,    94,     0,
       0,     0,     0,     0,     0,     0,     0,     1,     4,    84,
      80,    83,     0,     0,     0,    94,     0,     0,    87,    88,
      89,    90,    91,    92,    93,    98,     0,     9,    40,    39,
      66,    70,     0,    65,     0,    67,     0,     0,    71,    72,
      68,    69,    46,     0,     0,     0,     0,    41,    47,     0,
       0,    42,     0,     0,     0,    12,     0,    97,    95,    96,
      85,     0,     0,     0,     0,     0,     0,     0,    94,    73,
      75,    74,    76,     0,     0,     0,     0,     0,    35,     0,
       0,    36,     0,     0,     0,     0,    13,    11,    25,    86,
      10,     0,     0,     0,    77,     0,     0,    53,     0,    94,
       0,    43,    57,    58,    59,    60,     0,    37,    62,    61,
       0,     0,     0,     0,     0,    26,     0,     0,    50,     0,
       0,    51,     0,     0,     0,    45,    48,     0,    49,     0,
       0,    20,     0,    28,    29,    30,    31,     0,     0,     0,
      78,     0,     0,     0,    44,    38,    64,    63,    23,     0,
      17,    18,    19,    21,     0,    14,     0,     0,    56,     0,
      55,    52,    54,     0,     0,     0,     0,    28,     0,     0,
      32,    79,     0,    24,    15,    22,     0,     0,     0,    28,
      27,    16
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,     7,     8,     9,    10,    74,    75,   173,   174,
     169,   107,   108,   156,   157,   189,    11,   126,    66,    67,
      68,   130,    69,    70,    71,    93,   113,   114,    12,    13,
      14,    37,    47
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -169
static const yytype_int16 yypact[] =
{
     110,  -169,    13,    10,   105,    -6,    34,   110,  -169,  -169,
    -169,  -169,  -169,    -3,  -169,   -11,    -7,    -2,    -1,    16,
      32,    35,    38,    39,    44,    61,     3,  -169,  -169,  -169,
    -169,  -169,    93,   131,    94,    76,    26,    80,  -169,  -169,
    -169,  -169,  -169,  -169,  -169,  -169,   146,  -169,  -169,  -169,
    -169,  -169,    96,  -169,    99,  -169,   107,   124,  -169,  -169,
    -169,  -169,  -169,   130,   132,   113,   123,  -169,  -169,   133,
     134,  -169,   116,   -23,   -10,  -169,   104,  -169,  -169,  -169,
    -169,   118,    93,   135,    93,   174,   136,    93,     1,  -169,
    -169,  -169,  -169,   127,    93,    93,    93,    93,  -169,    93,
      20,  -169,   137,   139,   140,   141,  -169,   162,  -169,  -169,
    -169,   103,   197,    75,  -169,   108,   115,  -169,   114,    76,
     142,  -169,    -9,    -9,  -169,  -169,   119,    11,  -169,    11,
     122,   143,   144,   201,    58,  -169,   203,   145,  -169,   135,
     205,  -169,   206,   208,   149,  -169,  -169,    93,  -169,    70,
     202,    91,   156,  -169,  -169,  -169,  -169,   -36,   154,   212,
    -169,   157,   158,   159,  -169,    11,  -169,    11,  -169,    28,
    -169,  -169,  -169,  -169,   125,  -169,    66,    58,  -169,   151,
    -169,  -169,  -169,   202,   213,   164,    91,   163,   160,   165,
    -169,  -169,   126,  -169,  -169,  -169,    72,   167,   169,   168,
    -169,  -169
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -169,  -169,  -169,   220,  -169,  -169,  -169,   155,    45,  -169,
      47,  -169,   128,  -168,    56,  -169,  -169,  -169,   -81,  -169,
    -169,  -169,  -169,  -169,  -169,  -169,  -169,    95,  -169,  -169,
     223,   -35,   187
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -35
static const yytype_int16 yytable[] =
{
      76,   111,    35,   115,   119,    29,   118,    45,    26,   190,
     102,   103,   104,   122,   123,   124,   125,    17,   127,   129,
      15,    73,   105,    48,    49,   176,   177,   128,   190,    77,
      50,    51,    52,    53,    27,    54,    55,    56,    57,    96,
      97,    58,    59,    60,    61,    78,    79,    32,     4,    62,
      63,    33,    16,   120,    30,    34,    94,    95,    46,    96,
      97,   153,   154,    64,   155,    36,   165,    36,   167,   187,
     154,    65,   155,    48,    49,   199,   154,   166,   155,    38,
      50,    51,    52,    53,   144,    54,    55,    56,    57,   183,
     184,    58,    59,    60,    61,    39,    48,    49,    40,    62,
      63,    41,    42,    50,    51,    52,    53,    43,    54,    55,
      56,    57,    18,    64,    58,    59,    60,    61,     1,     2,
      88,    65,    62,    63,    44,    73,     3,   170,   171,   172,
      19,    20,    21,    22,    72,   138,    64,   139,    89,    90,
      91,    92,    36,    80,    65,    23,    24,    25,    94,    95,
      45,    96,    97,    94,    95,    82,    96,    97,    83,    94,
      95,     4,    96,    97,     5,   136,    84,   109,    94,    95,
     140,    96,    97,   101,   110,   141,   143,   142,   116,   146,
      98,   147,   148,    85,   149,   185,   198,   186,   184,    86,
     121,    87,    99,   100,   105,   131,   117,   132,   133,   112,
     134,   137,   150,   151,   152,   145,   158,   159,   161,   168,
     162,   163,   164,   175,   178,   179,   191,   180,   181,   182,
     193,   194,   196,   -33,   200,   197,   201,    28,   -34,   106,
     192,   195,   188,    81,   160,   135,    31
};

static const yytype_uint8 yycheck[] =
{
      35,    82,     3,    84,     3,     8,    87,     4,    14,   177,
      33,    34,    35,    94,    95,    96,    97,     7,    99,   100,
       7,    31,    32,     3,     4,    61,    62,     7,   196,     3,
      10,    11,    12,    13,     0,    15,    16,    17,    18,    48,
      49,    21,    22,    23,    24,    19,    20,    58,    51,    29,
      30,    58,    39,    88,    57,    57,    45,    46,    55,    48,
      49,     3,     4,    43,     6,    66,   147,    66,   149,     3,
       4,    51,     6,     3,     4,     3,     4,     7,     6,    63,
      10,    11,    12,    13,   119,    15,    16,    17,    18,    61,
      62,    21,    22,    23,    24,    63,     3,     4,    63,    29,
      30,    63,    63,    10,    11,    12,    13,    63,    15,    16,
      17,    18,     7,    43,    21,    22,    23,    24,     8,     9,
       7,    51,    29,    30,    63,    31,    16,    36,    37,    38,
      25,    26,    27,    28,     3,    60,    43,    62,    25,    26,
      27,    28,    66,    63,    51,    40,    41,    42,    45,    46,
       4,    48,    49,    45,    46,    59,    48,    49,    59,    45,
      46,    51,    48,    49,    54,    62,    59,    63,    45,    46,
      62,    48,    49,    57,    56,    60,    62,    62,     4,    60,
      57,    62,    60,    59,    62,    60,    60,    62,    62,    59,
      63,    59,    59,    59,    32,    58,    60,    58,    58,    64,
      59,     4,    59,    59,     3,    63,     3,    62,     3,     7,
       4,     3,    63,    57,    60,     3,    65,    60,    60,    60,
       7,    57,    62,    60,    57,    60,    57,     7,    60,    74,
     183,   186,   176,    46,   139,   107,    13
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,     9,    16,    51,    54,    68,    69,    70,    71,
      72,    83,    95,    96,    97,     7,    39,     7,     7,    25,
      26,    27,    28,    40,    41,    42,    14,     0,    70,     8,
      57,    97,    58,    58,    57,     3,    66,    98,    63,    63,
      63,    63,    63,    63,    63,     4,    55,    99,     3,     4,
      10,    11,    12,    13,    15,    16,    17,    18,    21,    22,
      23,    24,    29,    30,    43,    51,    85,    86,    87,    89,
      90,    91,     3,    31,    73,    74,    98,     3,    19,    20,
      63,    99,    59,    59,    59,    59,    59,    59,     7,    25,
      26,    27,    28,    92,    45,    46,    48,    49,    57,    59,
      59,    57,    33,    34,    35,    32,    74,    78,    79,    63,
      56,    85,    64,    93,    94,    85,     4,    60,    85,     3,
      98,    63,    85,    85,    85,    85,    84,    85,     7,    85,
      88,    58,    58,    58,    59,    79,    62,     4,    60,    62,
      62,    60,    62,    62,    98,    63,    60,    62,    60,    62,
      59,    59,     3,     3,     4,     6,    80,    81,     3,    62,
      94,     3,     4,     3,    63,    85,     7,    85,     7,    77,
      36,    37,    38,    75,    76,    57,    61,    62,    60,     3,
      60,    60,    60,    61,    62,    60,    62,     3,    81,    82,
      80,    65,    77,     7,    57,    75,    62,    60,    60,     3,
      57,    57
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
     `$$ = $1'.

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
#line 160 "qgen.y"
    {
							AddQuerySegment(pCurrentQuery, "\n");
							AddQuerySubstitution(pCurrentQuery, "_END", 0, 0);
							AddQuerySegment(pCurrentQuery, "\n");
						}
    break;

  case 4:
#line 169 "qgen.y"
    {
							if (is_set("DEBUG"))
							{
								if ((yyvsp[(2) - (2)].intval) != KW_DEFINE)
								{
									printf("STATUS: parsed %s statement at line %d\n", 
										((yyvsp[(2) - (2)].intval) == TOK_SQL)?"SQL":KeywordText((yyvsp[(2) - (2)].intval)), pCurrentFile->line_number);
								}
							}
						}
    break;

  case 5:
#line 181 "qgen.y"
    {(yyval.intval) = KW_INCLUDE; }
    break;

  case 6:
#line 182 "qgen.y"
    {(yyval.intval) = KW_DEFINE; }
    break;

  case 7:
#line 183 "qgen.y"
    {(yyval.intval) = TOK_SQL; }
    break;

  case 8:
#line 184 "qgen.y"
    {(yyval.intval) = KW_DIST; }
    break;

  case 9:
#line 193 "qgen.y"
    {
					if (include_file((yyvsp[(3) - (3)].strval), pCurrentQuery) < 0)
						yyerror("File include failed");
					}
    break;

  case 10:
#line 198 "qgen.y"
    {
					yywarn("System include not supported; using relative pathing");
					if (include_file((yyvsp[(4) - (5)].strval), pCurrentQuery) < 0)
						yyerror("File include failed");
					}
    break;

  case 35:
#line 259 "qgen.y"
    {
						defineSubstitution(pCurrentQuery, (yyvsp[(2) - (5)].strval), (yyvsp[(4) - (5)].exprval));
						if (is_set("DEBUG"))
							printf("STATUS: DEFINED %s\n", (yyvsp[(2) - (5)].strval));
						}
    break;

  case 36:
#line 265 "qgen.y"
    {
						pSub = findSubstitution(pCurrentQuery, "_LIMIT", 0);
						sprintf(tmpstr, "%d", (yyvsp[(4) - (5)].intval));
						ResetBuffer(pSub->pAssignment->Value.pBuf);
						AddBuffer(pSub->pAssignment->Value.pBuf, tmpstr);
						if (is_set("DEBUG"))
							printf("STATUS: SET LIMIT\n");
						}
    break;

  case 37:
#line 277 "qgen.y"
    {
						(yyval.list) = makeList(L_FL_TAIL, NULL);
						addList((yyval.list), (yyvsp[(1) - (1)].exprval));
						}
    break;

  case 38:
#line 282 "qgen.y"
    {
						addList((yyvsp[(1) - (3)].list), (yyvsp[(3) - (3)].exprval));
						(yyval.list) = (yyvsp[(1) - (3)].list);
						}
    break;

  case 39:
#line 289 "qgen.y"
    {
						(yyval.exprval) = MakeStringConstant((yyvsp[(1) - (1)].strval));
						}
    break;

  case 40:
#line 293 "qgen.y"
    {
						(yyval.exprval) = MakeIntConstant((yyvsp[(1) - (1)].intval));
						}
    break;

  case 42:
#line 298 "qgen.y"
    {
						(yyval.exprval) = MakeIntConstant((yyvsp[(1) - (1)].intval));
						(yyval.exprval)->nFlags |= EXPR_FL_KEYWORD;
						}
    break;

  case 43:
#line 303 "qgen.y"
    {
						(yyval.exprval) = getKeywordValue((yyvsp[(2) - (3)].intval));
						}
    break;

  case 44:
#line 307 "qgen.y"
    {
						(yyval.exprval) = MakeVariableReference((yyvsp[(2) - (5)].strval), (yyvsp[(3) - (5)].intval));
						}
    break;

  case 45:
#line 311 "qgen.y"
    {
						(yyval.exprval) = MakeVariableReference((yyvsp[(2) - (4)].strval), (yyvsp[(3) - (4)].intval));
						}
    break;

  case 46:
#line 315 "qgen.y"
    {
						(yyval.exprval) = MakeIntConstant(get_int("SCALE"));
						}
    break;

  case 48:
#line 322 "qgen.y"
    {
						(yyval.exprval) = MakeFunctionCall((yyvsp[(1) - (4)].intval), (yyvsp[(3) - (4)].list));
						}
    break;

  case 49:
#line 326 "qgen.y"
    {
						(yyval.exprval) = MakeFunctionCall((yyvsp[(1) - (4)].intval), (yyvsp[(3) - (4)].list));
						}
    break;

  case 50:
#line 330 "qgen.y"
    {
						(yyval.exprval) = MakeFunctionCall(KW_TEXT, (yyvsp[(3) - (4)].list));
						}
    break;

  case 51:
#line 334 "qgen.y"
    {
						i = GetTableNumber((yyvsp[(3) - (4)].strval));
						if (i == -1)
						{
							i = distsize((yyvsp[(3) - (4)].strval));
							if (i == -1)
								ReportError(QERR_BAD_NAME, (yyvsp[(3) - (4)].strval), 1);
						}
						else
							i = getIDCount(i);
						(yyval.exprval) = MakeIntConstant(i);
						}
    break;

  case 52:
#line 347 "qgen.y"
    {
						/* TODO: Need to convert this to DSS_HUGE */
						i = GetTableNumber((yyvsp[(3) - (6)].strval));
						if (i == -1)
						{
							i = distsize((yyvsp[(3) - (6)].strval));
							if (i == -1)
								ReportError(QERR_BAD_NAME, (yyvsp[(3) - (6)].strval), 1);
						}
						j = GetTableNumber((yyvsp[(5) - (6)].strval));
						if (i == -1)
							ReportError(QERR_BAD_NAME, (yyvsp[(5) - (6)].strval), 1);
						i = (int)getIDCount(i);
						j = (int)getIDCount(j);
						(yyval.exprval) = MakeIntConstant((i>j)?j:i);
						}
    break;

  case 53:
#line 364 "qgen.y"
    {
						(yyval.exprval) = MakeIntConstant(getScaleSlot(get_int("SCALE")) + 1);
						}
    break;

  case 54:
#line 368 "qgen.y"
    {
						(yyval.exprval) = MakeListExpr(KW_ULIST, (yyvsp[(3) - (6)].exprval), (yyvsp[(5) - (6)].intval));
						}
    break;

  case 55:
#line 372 "qgen.y"
    {
						(yyval.exprval) = MakeListExpr(KW_LIST, (yyvsp[(3) - (6)].exprval), (yyvsp[(5) - (6)].intval));
						}
    break;

  case 56:
#line 376 "qgen.y"
    {
						(yyval.exprval) = MakeListExpr(KW_RANGE, (yyvsp[(3) - (6)].exprval), (yyvsp[(5) - (6)].intval));
						}
    break;

  case 57:
#line 382 "qgen.y"
    {
						(yyval.exprval) = makeArithmeticExpr(OP_ADD, (yyvsp[(1) - (3)].exprval), (yyvsp[(3) - (3)].exprval));
						}
    break;

  case 58:
#line 386 "qgen.y"
    {
						(yyval.exprval) = makeArithmeticExpr(OP_SUBTRACT, (yyvsp[(1) - (3)].exprval), (yyvsp[(3) - (3)].exprval));
						}
    break;

  case 59:
#line 390 "qgen.y"
    {
						(yyval.exprval) = makeArithmeticExpr(OP_MULTIPLY, (yyvsp[(1) - (3)].exprval), (yyvsp[(3) - (3)].exprval));
						}
    break;

  case 60:
#line 394 "qgen.y"
    {
						(yyval.exprval) = makeArithmeticExpr(OP_DIVIDE, (yyvsp[(1) - (3)].exprval), (yyvsp[(3) - (3)].exprval));
						}
    break;

  case 61:
#line 399 "qgen.y"
    {
						(yyval.list) = makeList(L_FL_TAIL, NULL);
						addList((yyval.list), (yyvsp[(1) - (1)].exprval));
						}
    break;

  case 62:
#line 404 "qgen.y"
    {
						(yyval.list) = makeList(L_FL_TAIL, NULL);
						addList((yyval.list), MakeStringConstant((yyvsp[(1) - (1)].strval)));
						}
    break;

  case 63:
#line 409 "qgen.y"
    {
						addList((yyvsp[(1) - (3)].list), (yyvsp[(3) - (3)].exprval));
						(yyval.list) = (yyvsp[(1) - (3)].list);
						}
    break;

  case 64:
#line 414 "qgen.y"
    {
						addList((yyvsp[(1) - (3)].list), MakeStringConstant((yyvsp[(3) - (3)].strval)));
						(yyval.list) = (yyvsp[(1) - (3)].list);
						}
    break;

  case 65:
#line 420 "qgen.y"
    {(yyval.intval) = KW_DATE;}
    break;

  case 66:
#line 421 "qgen.y"
    {(yyval.intval) = KW_RANDOM;}
    break;

  case 67:
#line 424 "qgen.y"
    {(yyval.intval) = KW_DIST;}
    break;

  case 68:
#line 425 "qgen.y"
    {(yyval.intval) = KW_DISTMEMBER;}
    break;

  case 69:
#line 426 "qgen.y"
    {(yyval.intval) = KW_DISTWEIGHT;}
    break;

  case 70:
#line 429 "qgen.y"
    {(yyval.intval) = KW_UNIFORM;}
    break;

  case 71:
#line 430 "qgen.y"
    {(yyval.intval) = KW_SALES;}
    break;

  case 72:
#line 431 "qgen.y"
    {(yyval.intval) = KW_RETURNS;}
    break;

  case 73:
#line 434 "qgen.y"
    {(yyval.intval) = KW_QUERY;}
    break;

  case 74:
#line 435 "qgen.y"
    {(yyval.intval) = KW_TEMPLATE;}
    break;

  case 75:
#line 436 "qgen.y"
    {(yyval.intval) = KW_STREAM;}
    break;

  case 76:
#line 437 "qgen.y"
    {(yyval.intval) = KW_SEED;}
    break;

  case 77:
#line 441 "qgen.y"
    {
						(yyval.list) = makeList(L_FL_TAIL, NULL);
						addList((yyval.list), (yyvsp[(1) - (1)].exprval));
						}
    break;

  case 78:
#line 446 "qgen.y"
    {
						addList((yyval.list), (yyvsp[(3) - (3)].exprval));
						(yyval.list) = (yyvsp[(1) - (3)].list);
						}
    break;

  case 79:
#line 453 "qgen.y"
    {
						(yyval.exprval) = MakeReplacement((yyvsp[(2) - (5)].strval), (yyvsp[(4) - (5)].intval));
						}
    break;

  case 80:
#line 466 "qgen.y"
    {
							pSegment = getTail(pCurrentQuery->SegmentList);
							pSegment->flags |= QS_EOS;
							}
    break;

  case 82:
#line 475 "qgen.y"
    {
							if ((nRetCode = AddQuerySegment(pCurrentQuery, (yyvsp[(1) - (1)].strval))) != 0)
								yyerror("SQL parse failed");
							}
    break;

  case 84:
#line 482 "qgen.y"
    {
							if ((nRetCode = AddQuerySegment(pCurrentQuery, (yyvsp[(2) - (2)].strval))) != 0)
								yyerror("SQL parse failed");
							}
    break;

  case 85:
#line 489 "qgen.y"
    {
							if ((nRetCode = AddQuerySubstitution(pCurrentQuery, (yyvsp[(2) - (4)].strval), 0, (yyvsp[(3) - (4)].intval))) < 0)
								{
								sprintf(tmpstr, "Substitution match failed on %s", (yyvsp[(2) - (4)].strval));
								yyerror(tmpstr);
								}
						}
    break;

  case 86:
#line 497 "qgen.y"
    {
							if ((nRetCode = AddQuerySubstitution(pCurrentQuery, (yyvsp[(2) - (5)].strval), (yyvsp[(3) - (5)].intval), (yyvsp[(4) - (5)].intval))) < 0)
								{
								sprintf(tmpstr, "Substitution match failed on %s", (yyvsp[(2) - (5)].strval));
								yyerror(tmpstr);
								}
						}
    break;

  case 87:
#line 505 "qgen.y"
    {
							if ((nRetCode = AddQuerySubstitution(pCurrentQuery, "_QUERY", 0, 0)) < 0)
								{
								yyerror("Lookup of predefined constant failed");
								}
						}
    break;

  case 88:
#line 512 "qgen.y"
    {
							if ((nRetCode = AddQuerySubstitution(pCurrentQuery, "_STREAM", 0, 0)) < 0)
								{
								yyerror("Lookup of predefined constant failed");
								}
						}
    break;

  case 89:
#line 519 "qgen.y"
    {
							if ((nRetCode = AddQuerySubstitution(pCurrentQuery, "_TEMPLATE", 0, 0)) < 0)
								{
								yyerror("Lookup of predefined constant failed");
								}
						}
    break;

  case 90:
#line 526 "qgen.y"
    {
							if ((nRetCode = AddQuerySubstitution(pCurrentQuery, "_SEED", 0, 0)) < 0)
								{
								yyerror("Lookup of predefined constant failed");
								}
						}
    break;

  case 91:
#line 533 "qgen.y"
    {
							if ((nRetCode = AddQuerySubstitution(pCurrentQuery, "_LIMITA", 0, 0)) < 0)
								{
								yyerror("Lookup of predefined constant failed");
								}
						}
    break;

  case 92:
#line 540 "qgen.y"
    {
							if ((nRetCode = AddQuerySubstitution(pCurrentQuery, "_LIMITB", 0, 0)) < 0)
								{
								yyerror("Lookup of predefined constant failed");
								}
						}
    break;

  case 93:
#line 547 "qgen.y"
    {
							if ((nRetCode = AddQuerySubstitution(pCurrentQuery, "_LIMITC", 0, 0)) < 0)
								{
								yyerror("Lookup of predefined constant failed");
								}
						}
    break;

  case 94:
#line 555 "qgen.y"
    {(yyval.intval) = 0;}
    break;

  case 95:
#line 556 "qgen.y"
    {(yyval.intval) = 0;}
    break;

  case 96:
#line 557 "qgen.y"
    {(yyval.intval) = 1;}
    break;

  case 97:
#line 558 "qgen.y"
    {(yyval.intval) = (yyvsp[(2) - (2)].intval);}
    break;

  case 98:
#line 566 "qgen.y"
    { (yyval.strval) = (yyvsp[(1) - (1)].strval); }
    break;


/* Line 1267 of yacc.c.  */
#line 2199 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 570 "qgen.y"




