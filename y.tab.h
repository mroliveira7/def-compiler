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
#line 39 "parser.y" /* yacc.c:1909  */

	tipoTree *treePointer;
	int integer;
	char id[20];

#line 132 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
