%{
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


tipoTree *treeRoot = NULL;

%}

%union {
	tipoTree *treePointer;
	int integer;
	char id[20];
};

%token AND NOT OR WHILE
%token ELSE IF RETURN VOID
%token DEF BREAK CONTINUE INT
%token PLUS TIMES MINUS DIV
%token COMMA SEMICOL ASSIGN EQ
%token NEQ LTEQ GTEQ LT GT
%token CLOSEPAR OPENPAR OPENCOLC CLOSECOLC
%token OPENCH CLOSECH

%token <id> NAME
%token <id> NUMBER

%left AND
%left OR
%left LT GT LTEQ GTEQ EQ NEQ
%left OPENPAR CLOSEPAR
%left PLUS MINUS
%left TIMES DIV
%right NOT

%type <treePointer> s program decVar decFunc  type compVar arglist multExpr compArglist expr paramList block rcsParamList multVar stmt multStmt funCall compElse compExpr

%start s

%%
s       : {$$ = NULL;}
		| program s {
			if ($1 != NULL){
				$$ = cria_node("program", 2, $1, $2);
				treeRoot = $$;
			}
		};

program : decVar { $$ = $1; }
        | decFunc { $$ = $1; }
        ;

decVar  : type NAME compVar SEMICOL { $$ = cria_node("decVar", 4, $1, terminalToken($2, NAME), $3, terminalToken(";", SEMICOL)); }
        ;

compVar : {$$ = NULL;}
        | ASSIGN expr { $$ = cria_node("compVar", 2, terminalToken("=", ASSIGN), $2); }
        ;

decFunc : DEF type NAME OPENPAR paramList CLOSEPAR block { $$ = cria_node("decFunc" , 7, terminalToken("def", DEF), $2, terminalToken($3, NAME), terminalToken("(", OPENPAR), $5, terminalToken(")", CLOSEPAR), $7); }
        ;

paramList : {$$ = NULL;}
 		  | type NAME rcsParamList { $$ = cria_node("paramList", 3, $1, terminalToken($2, NAME), $3); }
          ;

rcsParamList  : { $$ = NULL; }
              | COMMA type NAME rcsParamList { $$ = cria_node("paramList", 4, terminalToken(",", COMMA), $2, terminalToken($3, NAME), $4); }
              ;

block : OPENCH multVar multStmt CLOSECH { $$ = cria_node("block", 4, terminalToken("{", OPENCH), $2, $3, terminalToken("}", CLOSECH)); }
      ;

multVar : { $$ = NULL; }
        | decVar multVar { $$ = cria_node("multVar", 2, $1, $2); }
        ;

multStmt : { $$ = NULL; }
         | stmt multStmt { $$ = cria_node("multStmt", 2, $1, $2); }
         ;

stmt :    NAME ASSIGN expr SEMICOL { $$ = cria_node("stmt", 4, terminalToken($1, NAME), terminalToken("=", ASSIGN), $3, terminalToken(";", SEMICOL)); }
        | funCall SEMICOL { $$ = cria_node("stmt", 2, $1, terminalToken(";", SEMICOL)); }
        | IF OPENPAR expr CLOSEPAR block compElse { $$ = cria_node("stmt", 6, terminalToken("if", IF), terminalToken("(", OPENPAR), $3, terminalToken(")", CLOSEPAR), $5, $6); }
        | WHILE OPENPAR expr CLOSEPAR block { $$ = cria_node("stmt", 5, terminalToken("while", WHILE), terminalToken("(", OPENPAR), $3, terminalToken(")", CLOSEPAR), $5); }
        | RETURN compExpr SEMICOL  { $$ = cria_node("stmt", 3, terminalToken("return", RETURN), $2, terminalToken(";", SEMICOL)); }
        | BREAK SEMICOL  { $$ = cria_node("stmt", 2, terminalToken("break", BREAK), terminalToken(";", SEMICOL)); }
        | CONTINUE SEMICOL  { $$ = cria_node("stmt", 2, terminalToken("continue", CONTINUE), terminalToken(";", SEMICOL)); }
        ;

compElse  : { $$ = NULL; }
          | ELSE block  { $$ = cria_node("compelse", 2, terminalToken("else", ELSE), $2); }
          ;

compExpr : {$$ = NULL; }
         | expr  { $$ = cria_node("compexp", 1, $1); }
         ;

funCall : NAME OPENPAR compArglist CLOSEPAR  { $$ = cria_node("funcall", 4, terminalToken($1, NAME), terminalToken("(", OPENPAR), $3, terminalToken(")", CLOSEPAR)); }
        ;

compArglist : { $$ = NULL; }
            | arglist  { $$ = cria_node("compArglist", 1, $1); }
            ;

arglist     : expr multExpr  { $$ = cria_node("arglist", 2, $1, $2); }
            ;

multExpr  : { $$ = NULL; }
          | COMMA expr multExpr  { $$ = cria_node("multExpr", 3, terminalToken(",", COMMA), $2, $3); }
          ;

expr      : NUMBER { $$ = terminalToken($1, NUMBER); }
          | NAME { $$ = terminalToken($1, NAME); }
          | OPENPAR expr CLOSEPAR  { $$ = cria_node("expr", 3, terminalToken("(", OPENPAR), $2, terminalToken(")", CLOSEPAR)); }
          | funCall  { $$ = cria_node("funcall", 1, $1); }
          | expr PLUS expr { $$ = cria_node("expr", 3, $1, terminalToken("+", PLUS), $3); }
          | expr MINUS expr  { $$ = cria_node("expr", 3, $1, terminalToken("-", MINUS), $3); }
          | expr DIV expr { $$ = cria_node("expr", 3, $1, terminalToken("/", DIV), $3); }
          | expr TIMES expr { $$ = cria_node("expr", 3, $1, terminalToken("*", TIMES), $3); }
          | expr OR expr { $$ = cria_node("expr", 3, $1, terminalToken("or", OR), $3); }
          | expr AND expr { $$ = cria_node("expr", 3, $1, terminalToken("and", AND), $3); }
          | expr LT expr { $$ = cria_node("expr", 3, $1, terminalToken("<", LT), $3); }
          | expr LTEQ expr { $$ = cria_node("expr", 3, $1, terminalToken("<=", LTEQ), $3); }
          | expr GT expr { $$ = cria_node("expr", 3, $1, terminalToken(">", GT), $3); }
          | expr GTEQ expr { $$ = cria_node("expr", 3, $1, terminalToken(">=", GTEQ), $3); }
          | expr NEQ expr { $$ = cria_node("expr", 3, $1, terminalToken("<>", NEQ), $3); }
          | NOT expr { $$ = cria_node("expr", 2, terminalToken("!", NOT), $2); }
          | MINUS expr { $$ = cria_node("expr", 2, terminalToken("-", MINUS), $2); }
          ;

type      : INT { $$ = terminalToken("int", INT); }
          | VOID { $$ = terminalToken("void", VOID); }
          ;

%%

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

void yyerror(char *string){  fprintf(stderr, "%s\n", string); 
}

int printParams(tipoTree *p){

	int i;
	if (p == NULL)
		return 0;

	if(p->tokenNumber == NAME){
		printf(" [%s]", p->id);
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
		printf(" [%s]", p->id);
		return 1;
	}
	else if(p->num_filhos == 3){
		
		if(p->filhos[0]->tokenNumber == OPENPAR)
		{
			printExpr(p->filhos[1], depth);
			return 1;
		}
		else{
			printf("[%s", p->filhos[1]->id);
			printExpr(p->filhos[0], depth);
			printExpr(p->filhos[2], depth);
			printf("]");
			return 1;
		}
	}
	else if(p->num_filhos == 2){
		printf("[%s", p->filhos[0]->id);
		printExpr(p->filhos[1], depth);
		printf("]\n");
		return 1;
	}
	else if(p->num_filhos == 1)
	{
		printFuncall(p->filhos[0], depth);
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

	if( (p->nonTerminal != NULL) && strcmp(p->nonTerminal, "expr") == 0){
		printExpr(p, depth);
		return 1;
	}

	for(i = 0; i < p->num_filhos; i++){
		printArglist(p->filhos[i], depth);
	}
	return 0;
}

int printFuncall(tipoTree *p, int depth){

	printf("[funcall ");
	printf(" [%s]", p->filhos[0]->id);
	printf(" [arglist ");
	printArglist(p->filhos[2], depth);
	printf("]]");
	return 0;
}

int printMultVar(tipoTree *p, int depth){

	int i;
	if (p == NULL)
		return 0;

	if(p->nonTerminal != NULL && strcmp(p->nonTerminal, "decVar") == 0){

		printf("[decVar [%s]", p->filhos[1]->id);
		if(p->filhos[2]){
			printExpr(p->filhos[2]->filhos[1], depth);
			printf("]]\n");
		}
		else
			printf("]\n");
		
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

// stmt :    NAME ASSIGN expr SEMICOL
//         | funCall SEMICOL
//         | IF OPENPAR expr CLOSEPAR block compElse
//         | WHILE OPENPAR expr CLOSEPAR block
//         | RETURN compExpr SEMICOL 
//         | BREAK SEMICOL
//         | CONTINUE SEMICOL
//         ;

	if(p->nonTerminal != NULL && strcmp(p->nonTerminal, "stmt") == 0){

		if(p->filhos[0]->tokenNumber == NAME){
			printf("[assign [%s]", p->filhos[0]->id);
			printExpr(p->filhos[2], depth);
			printf("]]\n");
			return 1;
		}
		else if (p->filhos[0]->tokenNumber == IF)
		{
			for(i=0; i < depth; i++) printf(" ");
			printf("[if \n");
			
			for(i=0; i < depth+1; i++) printf(" ");
			printf("[ ");
			printExpr(p->filhos[2], depth+1);
			printf("]\n");
			
			printTree(p->filhos[4], depth+1);
			
			if (p->filhos[5]){
				for(i=0; i < depth+1; i++) printf(" ");
				printf("[else \n");
				printTree(p->filhos[5]->filhos[1], depth+1);
				for(i=0; i < depth+1; i++) printf(" ");
				printf("]\n");
			}
			printf("]\n");

			return 1;
		}

	}

	for(i = 0; i < p->num_filhos; i++)
		printMultStmt(p->filhos[i], depth);

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
			for(i=0; i < depth; i++) printf(" ");
			printf("[%s", p->nonTerminal);
			printParams(p);
			printf("]\n");
			return 0;
		}

		//print expr
		if(strcmp(p->nonTerminal, "expr") == 0 || strcmp(p->nonTerminal, "compexp") == 0){
			for(i=0; i < depth; i++) printf(" ");
			printExpr(p, depth);
			printf("]\n");
			return 0;
		}
		// print Arglist
		if(strcmp(p->nonTerminal, "compArglist") == 0){
			for(i=0; i < depth; i++) printf(" ");
			printf("[arglist ");
			printArglist(p, depth);
			printf("]\n");
			return 0;
		}
		// print multVar
		if(strcmp(p->nonTerminal, "multVar") == 0 || strcmp(p->nonTerminal, "decVar") == 0){
			for(i=0; i < depth; i++) printf(" ");
			printMultVar(p, depth);
			return 0;
		}
		// print multstmt
		if(strcmp(p->nonTerminal, "multStmt") == 0){
			for(i=0; i < depth; i++) printf(" ");
			printMultStmt(p, depth);
			return 0;
		}

		for(i=0; i < depth; i++) printf(" ");
		printf("[%s\n", p->nonTerminal);
	}

	if(p->num_filhos == 0)
	{
		if (p->tokenNumber == INT || p->tokenNumber == VOID || p->tokenNumber == DEF || p->tokenNumber == OPENPAR || p->tokenNumber == CLOSEPAR || p->tokenNumber == OPENCH || p->tokenNumber == CLOSECH || p->tokenNumber == SEMICOL)
			return 1;

		for(i=0; i < depth; i++) printf(" ");
		printf("[%s]\n", p->id);
		return 1;
	}
	else
	{
		for(i = 0; i < p->num_filhos; i++){
			printTree(p->filhos[i], depth+1);
		}

		for(i=0; i < depth; i++) printf(" ");
		printf("]\n");
	}
}

int main(int argc, char** argv){

	yyin = fopen(argv[1], "r");
	yyout = fopen(argv[2], "w");

	if(!yyin) printf("Arquivo nao pode ser aberto!\n");
	else{
		yyparse();
	}
	printTree(treeRoot, 0);
	printf("\n");
	fclose(yyin);
	fclose(yyout);

	return 0;
}
