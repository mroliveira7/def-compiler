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
s       : program { 
		if ($1 != NULL){
			$$ = cria_node("programa", 1, $1);
			treeRoot = $$;
		}
		};

program : decVar { $$ = cria_node("program", 1, $1); }
        | decFunc { $$ = cria_node("program", 1, $1); }
        ;

decVar  : type NAME compVar SEMICOL { $$ = cria_node("decVar", 4, $1, terminalToken("name", NAME), $3, terminalToken("semicol", SEMICOL)); }
        ;

compVar : {$$ = NULL;}
        | ASSIGN expr { $$ = cria_node("decVar", 2, terminalToken("assign", ASSIGN), $2); }
        ;

decFunc : DEF type NAME OPENPAR paramList CLOSEPAR block { $$ = cria_node("decFunc" , 7, terminalToken("def", DEF), $2, terminalToken("name", NAME), terminalToken("openpar", OPENPAR), $5, terminalToken("closepar", CLOSEPAR), $7); }
        ;

paramList : type NAME rcsParamList { $$ = cria_node("paramList", 3, $1, terminalToken("name", NAME), $3); }
          ;

rcsParamList  : { $$ = NULL; }
              | COMMA type NAME rcsParamList { $$ = cria_node("paramList", 4, terminalToken("comma", COMMA), $2, terminalToken("name", NAME), $4); }
              ;

block : OPENCH multVar multStmt CLOSECH { $$ = cria_node("block", 4, terminalToken("opench", OPENCH)); }
      ;

multVar : { $$ = NULL; }
        | decVar multVar { $$ = cria_node("multVar", $1, $2); }
        ;

multStmt : { $$ = NULL; }
         | decVar multStmt { $$ = cria_node("multStmt", $1, $2); }
         ;

stmt :    NAME ASSIGN expr SEMICOL { $$ = cria_node("stmt", 4, terminalToken("name", NAME), terminalToken("assign", ASSIGN), $3, terminalToken("semicol", SEMICOL)); }
        | funcCall SEMICOL { $$ = cria_node("stmt", 2, $1, terminalToken("semicol", SEMICOL)); }
        | IF OPENPAR expr CLOSEPAR block compElse { $$ = cria_node("stmt", 6, terminalToken("if", IF), terminalToken("openpar", OPENPAR), $3, terminalToken("closepar", CLOSEPAR), $5, $6); }
        | WHILE OPENPAR expr CLOSEPAR block { $$ = cria_node("stmt", 5, terminalToken("while", WHILE), terminalToken("openpar", OPENPAR), $3, terminalToken("closepar", CLOSEPAR), $5); }
        | RETURN compExpr SEMICOL  { $$ = cria_node("stmt", 3, terminalToken("return", RETURN), $2, terminalToken("semicol", SEMICOL)); }
        | BREAK SEMICOL  { $$ = cria_node("stmt", 2, terminalToken("break", BREAK), terminalToken("semicol", SEMICOL)); }
        | CONTINUE SEMICOL  { $$ = cria_node("stmt", 2, terminalToken("continue", CONTINUE), terminalToken("semicol", SEMICOL)); }
        ;

compElse  : { $$ = NULL; }
          | ELSE block  { $$ = cria_node("compelse", 2, terminalToken("else", ELSE), $2); }
          ;

compExpr : {$$ = NULL; }
         | expr  { $$ = cria_node("compexp", 1, $1); }
         ;

funCall : NAME OPENPAR compArglist CLOSEPAR  { $$ = cria_node("funCall", 4, terminalToken("name", NAME), terminalToken("openpar", OPENPAR), $3, terminalToken("closepar", CLOSEPAR)); }
        ;

compArglist : { $$ = NULL; }
            | arglist  { $$ = cria_node("compArglist", 1, $1); }
            ;

arglist     : expr multExpr  { $$ = cria_node("arglist", 2, $1, $2); }
            ;

multExpr  : { $$ = NULL; }
          | COMMA expr multExpr  { $$ = cria_node("multExpr", 3, terminalToken("comma", COMMA), $2, $3); }
          ;

expr      : NUMBER { $$ = terminalToken("number", NUMBER); }
          | NAME { $$ = terminalToken("name", NAME); }
          | OPENPAR expr CLOSEPAR  { $$ = cria_node("expr", 3, terminalToken("openpar", OPENPAR), $2, terminalToken("closepar", CLOSEPAR)); }
          | funcCall  { $$ = cria_node("expr", $1); }
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
          | expr NEQ expr { $$ = cria_node("expr", 3, $1, terminalToken("!=", NEQ), $3); }
          | NOT expr {}
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
