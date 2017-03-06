%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "y.tab.h"

int flag_comma = 1;
%}

letter				[a-zA-Z]
number				[0-9]+
id					[a-zA-Z_][a-zA-Z_0-9]*

%%

"//"				simple_comment();

"&&"				{
						// printf("SYM  \"%c%c\"\n", 38, 38);
						return AND;
					}
"!"					{
						// printf("SYM  \"%c\"\n", 33);
						return NOT;
					}
"||"				{
						// printf("SYM  \"%c%c\"\n", 124, 124);
						return OR;
					}
"while"				{
						// printf("KEY  \"while\"\n");
						return WHILE;
					}
"else"				{
						// printf("KEY  \"else\"\n");
						return ELSE;
					}
"if"				{
						// printf("KEY  \"if\"\n");
						return IF;
					}
"return"			{
						// printf("KEY  \"return\"\n");
						return RETURN;
					}
"void"				{
						// printf("KEY  \"void\"\n");
						return VOID;
					}
"def"				{
						// printf("KEY  \"def\"\n");
						return DEF;
					}
"break"				{
						// printf("KEY  \"break\"\n");
						return BREAK;
					}
"continue"			{
						// printf("KEY  \"continue\"\n");
						return CONTINUE;
					}
"int"				{
						// printf("KEY  \"int\"\n");
						return INT;
					}

{id}				{
						// printf("ID   \"%s\"\n", yytext);
						strcpy(yylval.id, yytext);
						return NAME;
					}
{number}			{
						// printf("DEC  \"%s\"\n", yytext);
						strcpy(yylval.id, yytext);
						return NUMBER;
					}
"+"					{
						// printf("SYM  \"%c\"\n", 43);
						return PLUS;
					}
"-"					{
						// printf("SYM  \"%c\"\n", 45);
						return MINUS;
					}
"*"					{
						// printf("SYM  \"%c\"\n", 42);
						return TIMES;
					}
"/"					{
						// printf("SYM  \"%c\"\n", 47);
						return DIV;
					}
","					{
						// printf("SYM  \"%c\"\n", 44);
						return COMMA;
					}
";"					{
						// printf("SYM  \"%c\"\n", 59);
						return SEMICOL;
					}
"="					{
						// printf("SYM  \"%c\"\n", 61);
						return ASSIGN;
					}
"=="				{
						// printf("SYM  \"%c%c\"\n", 61, 61);
						return EQ;
					}
"!="				{
						// printf("SYM  \"%c%c\"\n", 33, 61);
						return NEQ;
					}
"<="				{
						// printf("SYM  \"%c%c\"\n", 60, 61);
						return LTEQ;
					}
">="				{
						// printf("SYM  \"%c%c\"\n", 62,61);
						return GTEQ;
					}
"<"					{
						// printf("SYM  \"%c\"\n", 60);
						return LT;
					}
">"					{
						// printf("SYM  \"%c\"\n", 62);
						return GT;
					}
")"					{
						// printf("SYM  \"%c\"\n", 41);
						return CLOSEPAR;
					}
"("					{
						// printf("SYM  \"%c\"\n", 40);
						return OPENPAR;
					}
"["					{
						// printf("SYM  \"%c\"\n", 91);
						return OPENCOLC;
					}
"]"					{
						// printf("SYM  \"%c\"\n", 93);
						return CLOSECOLC;
					}
"{"					{
						// printf("SYM  \"%c\"\n", 123);
						return OPENCH;
					}
"}"					{
						// printf("SYM  \"%c\"\n", 125);
						return CLOSECH;
					}

\n					yylineno++;
[ \t]+				;
.					{
						print_error();
						// yyerror("CARACTER NAO ESPERADO");
						return 1;
					}
%%

print_error(){
	if(flag_comma == 1){
		fprintf(yyout, "LEXICAL ERROR AT LINE %d: %s\n", yylineno, yytext);
		flag_comma = 0;
	}
	else
		fprintf(yyout, ",\nLEXICAL ERROR AT LINE %d: %s\n", yylineno, yytext);
}

simple_comment(){
	char c;
	while((c = input()) != '\n');
	yylineno++;
}

// int main(){
// 	yyin = fopen(argv[1], "r");
// 	yyout = fopen(argv[2], "w");
//
// 	if(!yyin) printf("Arquivo nao pode ser aberto!\n");
// 	else{
// 		yylex();
// 	}
// 	return 0;
// }

int yywrap(void) {
    return 1;
}
