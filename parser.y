%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#define YYDEBUG 1


extern FILE *yyin;
extern FILE *yyout;

int yylex(void);
tipoTree * cria_node(char nonT[20], int n_filhos, ...);
tipoTree * terminalNumber(int token_n);
tipoTree * terminalToken(char id[20], int token_n);
void yyerror(char *string);


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
%token <integer> NUMBER

%left AND
%left OR
%left LT GT LTEQ GTEQ EQ NEQ
%left OPENPAR CLOSEPAR
%left PLUS MINUS
%left TIMES DIV
%right NOT

<type> programa decVar decFunc programa type compVar arglist multExpr compArglist expr paramList block rcsParamList multVar multStmt funcCall compElse compExpr

%start programa

%%
program :
        | decVar
        | decFunc
        ;

decVar  : type NAME compVar SEMICOL
        ;

compVar :
        | ASSIGN expr
        ;

decFunc : DEF type NAME OPENPAR paramList CLOSEPAR block
        ;

paramList : type NAME rcsParamList
          ;

rcsParamList  :
              | COMMA type NAME rcsParamList
              ;

block : OPENCH multVar multStmt CLOSECH
      ;

multVar :
        | decVar multVar
        ;

multStmt :
        | decVar multStmt
        ;

stmt : NAME ASSIGN expr SEMICOL
        | funcCall SEMICOL

        | IF OPENPAR expr CLOSEPAR block compElse
        | WHILE OPENPAR expr CLOSEPAR block
        | RETURN compExpr SEMICOL
        | BREAK SEMICOL
        | CONTINUE SEMICOL
        ;

compElse  :
          | ELSE block
          ;

compExpr :
         | expr
         ;


funCall : NAME OPENPAR compArglist CLOSEPAR
        ;

compArglist :
            | arglist
            ;

arglist     : expr multExpr
            ;

multExpr  :
          | COMMA expr multExpr
          ;

expr      : NUMBER
          | NAME
          | OPENPAR expr CLOSEPAR
          | funcCall
          | expr PLUS expr
          | expr MINUS expr
          | expr DIV expr
          | expr TIMES expr
          | expr OR expr
          | expr AND expr
          | expr LT expr
          | expr LTEQ expr
          | expr GT expr
          | expr GTEQ expr
          | expr NEQ expr
          | NOT expr
          | MINUS expr
          ;

type      : INT
          | VOID
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

void yyerror(char *string){  fprintf(stderr, "%s\n", string); }

int printTree(tipoTree *p){

	if(p == NULL)
		return 0;
	if(p->nonTerminal != NULL)
		fprintf(yyout,"[%s ", p->nonTerminal);
	else
		fprintf(yyout, "[");
	if(p->num_filhos == 0)
	{
		if (p->tokenNumber == NUMBER)
			fprintf(yyout, "%s %d", consultaToken(p->tokenNumber), p->number);
		else
			fprintf(yyout, "%s %s", consultaToken(p->tokenNumber), p->id);
	}
	else
	{
		int i;
		for(i = 0; i < p->num_filhos; i++)
			printTree(p->filhos[i]);
	}
	fprintf(yyout,"]");
}

int main(int argc, char** argv){

	yyin = fopen(argv[1], "r");
	yyout = fopen(argv[2], "w");

	if(!yyin) printf("Arquivo nao pode ser aberto!\n");
	else{
		yyparse();
	}

	fclose(yyin);
	fclose(yyout);

	return 0;
}
