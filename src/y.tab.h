/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 54 "src/ada.y" /* yacc.c:1909  */

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

#line 180 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
