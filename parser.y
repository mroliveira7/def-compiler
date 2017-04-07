%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "parser.h"

#define YYDEBUG 1

int cont_while = 0;
int cont_for = 0;
int cont_if = 0;

extern FILE *yyin;
extern FILE *yyout;

int yylex(void);
tipoTree * cria_node(char nonT[20], int n_filhos, ...);
tipoTree * terminalNumber(int token_n);
tipoTree * terminalToken(char id[20], int token_n);
int geraCode(tipoTree *p, int depth);

void yyerror(char *string);


listaVar * consultaVar(listaVar *p, char *id);

int printTree(tipoTree *p, int depth);
int printFuncall(tipoTree *p, int depth);


tipoTree *treeRoot = NULL;
listaVar *vars = NULL;
listaFuncs *funcs = NULL;
int G_NUM = 1;
int G_ATT = 1;
int G_ACC = 0;
int SALVEI = 0;

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
%token U_MINUS

%token <id> NAME
%token <id> NUMBER

%left OR
%left AND
%left EQ NEQ
%left LT GT LTEQ GTEQ
%left PLUS MINUS
%left TIMES DIV
%right NOT
%right U_MINUS
%left OPENPAR CLOSEPAR

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
         | expr  { $$ = $1; }
         ;

funCall : NAME OPENPAR compArglist CLOSEPAR  { $$ = cria_node("funcall", 4, terminalToken($1, NAME), terminalToken("(", OPENPAR), $3, terminalToken(")", CLOSEPAR)); }
        ;

compArglist : { $$ = NULL; }
            | arglist  { $$ = $1; }
            ;

arglist     : expr multExpr  { $$ = cria_node("arglist", 2, $1, $2); }
            ;

multExpr  : { $$ = NULL; }
          | COMMA expr multExpr  { $$ = cria_node("multExpr", 3, terminalToken(",", COMMA), $2, $3); }
          ;

expr      : NUMBER { $$ = terminalToken($1, NUMBER); }
          | NAME { $$ = terminalToken($1, NAME); }
          | OPENPAR expr CLOSEPAR  { $$ = $2; }
          | funCall  { $$ = cria_node("expr", 1, $1); }
          | expr PLUS expr { $$ = cria_node("expr", 3, $1, terminalToken("+", PLUS), $3); }
          | expr MINUS expr  { $$ = cria_node("expr", 3, $1, terminalToken("-", MINUS), $3); }
          | expr DIV expr { $$ = cria_node("expr", 3, $1, terminalToken("/", DIV), $3); }
          | expr TIMES expr { $$ = cria_node("expr", 3, $1, terminalToken("*", TIMES), $3); }
          | expr OR expr { $$ = cria_node("expr", 3, $1, terminalToken("||", OR), $3); }
          | expr AND expr { $$ = cria_node("expr", 3, $1, terminalToken("&&", AND), $3); }
          | expr LT expr { $$ = cria_node("expr", 3, $1, terminalToken("<", LT), $3); }
          | expr LTEQ expr { $$ = cria_node("expr", 3, $1, terminalToken("<=", LTEQ), $3); }
          | expr GT expr { $$ = cria_node("expr", 3, $1, terminalToken(">", GT), $3); }
          | expr GTEQ expr { $$ = cria_node("expr", 3, $1, terminalToken(">=", GTEQ), $3); }
          | expr NEQ expr { $$ = cria_node("expr", 3, $1, terminalToken("!=", NEQ), $3); }
		  | expr EQ expr { $$ = cria_node("expr", 3, $1, terminalToken("==", EQ), $3); }
          | NOT expr { $$ = cria_node("expr", 2, terminalToken("!", NOT), $2); }
          | MINUS expr %prec U_MINUS { $$ = cria_node("expr", 2, terminalToken("-", MINUS), $2); }
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

int insereVar(listaVar **p, char *id, int value){

	listaVar *aux = malloc(sizeof(struct listaV));
	strcpy(aux->varName, id);
	aux->varValue = value;
	aux->prox = *p;
	*p = aux;
}

listaVar * consultaVar(listaVar *p, char *id){

	listaVar *aux;
	for(aux = p; aux != NULL; aux = aux->prox){
		if( strcmp(aux->varName,id) == 0){
			return aux;
		}
	}
	return NULL;
}

int consultaFuncs(listaFuncs *p, char *id){

	listaFuncs *aux;
	for(aux = p; aux != NULL; aux = aux->prox){
		if( strcmp(aux->fname,id) == 0 ){
			return 1;
		}
	}
	return 0;
}

int insereFunc(listaFuncs **p, char *id){

	listaFuncs *aux = malloc(sizeof(struct listaF));
	strcpy(aux->fname, id);
	aux->prox = *p;
	*p = aux;
}

int updateVar(listaVar *p, char *id, int newValue){

	listaVar *aux = consultaVar(p, id);
	// printf("foi?\n");
	if (aux != NULL)
		aux->varValue = newValue;
	else
		return -1;
	return 1;
}

void yyerror(char *string){  fprintf(stderr, "%s\n", string);}

int printParams(tipoTree *p){

	int i;
	if (p == NULL)
		return 0;

	if(p->tokenNumber == NAME){
		fprintf(yyout, " [%s]", p->id);
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
		fprintf(yyout, " [%s]", p->id);
		return 1;
	}
	else if(p->num_filhos == 3){

		if(p->filhos[0]->tokenNumber == OPENPAR)
		{
			printExpr(p->filhos[1], depth);
			return 1;
		}
		else{
			fprintf(yyout, "[%s", p->filhos[1]->id);
			printExpr(p->filhos[0], depth);
			printExpr(p->filhos[2], depth);
			fprintf(yyout, "]");
			return 1;
		}
	}
	else if(p->num_filhos == 2){
		fprintf(yyout, "[%s", p->filhos[0]->id);
		printExpr(p->filhos[1], depth);
		fprintf(yyout, "]");
		return 1;
	}
	else if(p->num_filhos == 1)
	{
		printFuncall(p->filhos[0], depth+1);
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

	if((p->nonTerminal != NULL) && strcmp(p->nonTerminal, "expr") == 0){
		printExpr(p, depth);
		return 1;
	}
	else if(p->tokenNumber == NUMBER || p->tokenNumber == NAME){
		fprintf(yyout, " [%s]", p->id);
		return 1;
	}


	for(i = 0; i < p->num_filhos; i++){
		printArglist(p->filhos[i], depth);
	}
	return 0;
}

int printFuncall(tipoTree *p, int depth){

	int i;
	fprintf(yyout, "[funccall [%s] ", p->filhos[0]->id);
	fprintf(yyout, "[arglist");
	printArglist(p->filhos[2], depth);
	fprintf(yyout, "]]");
	return 0;
}

int printMultVar(tipoTree *p, int depth){

	int i;
	if (p == NULL)
		return 0;

	if(p->nonTerminal != NULL && strcmp(p->nonTerminal, "decVar") == 0){

		fprintf(yyout, "[decvar [%s]", p->filhos[1]->id);
		if(p->filhos[2]){
			printExpr(p->filhos[2]->filhos[1], depth);
			fprintf(yyout, "]");
		}
		else
			fprintf(yyout, "]");

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

	if(p->nonTerminal != NULL && strcmp(p->nonTerminal, "stmt") == 0){

		if(p->filhos[0]->tokenNumber == NAME)
		{
			fprintf(yyout, "[assign [%s]", p->filhos[0]->id);
			printExpr(p->filhos[2], depth);
			fprintf(yyout, "]");
			return 1;
		}
		else if (p->filhos[0]->tokenNumber == IF)
		{
			fprintf(yyout, "[if");

			printExpr(p->filhos[2], depth+1);
			printTree(p->filhos[4], depth+1);

			if (p->filhos[5]){
				printTree(p->filhos[5]->filhos[1], depth+2);
			}
			fprintf(yyout, "]");
			return 1;
		}
		else if (p->filhos[0]->tokenNumber == WHILE)
		{
			fprintf(yyout, "[while ");
			printExpr(p->filhos[2], depth+1);
			printTree(p->filhos[4], depth+1);
			fprintf(yyout, "]");
			return 1;
		}
		else if (p->filhos[0]->tokenNumber == RETURN)
		{
			fprintf(yyout, "[return ");
			if(p->filhos[1] != NULL)
				printExpr(p->filhos[1], depth);
			fprintf(yyout, "]");
		}
		else if (p->filhos[0]->tokenNumber == BREAK)
		{
			fprintf(yyout, "[break]");
		}
		else if (p->filhos[0]->tokenNumber == CONTINUE)
		{
			fprintf(yyout, "[continue]");
		}
		else{
			printFuncall(p->filhos[0], depth+1);
		}

	}

	for(i = 0; i < p->num_filhos; i++)
		printMultStmt(p->filhos[i], depth);

	return 0;
}

int printDecFunc(tipoTree *p, int depth){

	int i;
	if(p == NULL)
		return 0;

	fprintf(yyout, "[%s]", p->filhos[2]->id);

	if(p->filhos[4] == NULL){
		fprintf(yyout, "[paramlist]");
	}
	else{
		printTree(p->filhos[4], depth);
	}
	printTree(p->filhos[6],depth);
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
			fprintf(yyout, "[paramlist");
			printParams(p);
			fprintf(yyout, "]");
			return 0;
		}

		//print expr
		if(strcmp(p->nonTerminal, "expr") == 0){
			printExpr(p, depth);
			fprintf(yyout, "]");
			return 0;
		}
		// print Arglist
		if(strcmp(p->nonTerminal, "compArglist") == 0){
			fprintf(yyout, "[arglist ");
			printArglist(p, depth);
			fprintf(yyout, "]");
			return 0;
		}
		// print multVar
		if(strcmp(p->nonTerminal, "multVar") == 0 || strcmp(p->nonTerminal, "decVar") == 0){
			printMultVar(p, depth);
			return 0;
		}
		// print multstmt
		if(strcmp(p->nonTerminal, "multStmt") == 0){
			printMultStmt(p, depth);
			return 0;
		}
		if(strcmp(p->nonTerminal, "block") == 0){

			fprintf(yyout, "[block ");
			printMultVar(p->filhos[1], depth+1);
			printMultStmt(p->filhos[2], depth+1);
			fprintf(yyout, "]");
			return 0;
		}
		if(strcmp(p->nonTerminal, "decFunc") == 0){
			fprintf(yyout, "[decfunc ");
			printDecFunc(p, depth+1);
			fprintf(yyout, "]");
			return 0;
		}

	}

	if(p->num_filhos == 0)
	{
		if (p->tokenNumber == INT || p->tokenNumber == VOID || p->tokenNumber == DEF || p->tokenNumber == OPENPAR || p->tokenNumber == CLOSEPAR || p->tokenNumber == OPENCH || p->tokenNumber == CLOSECH || p->tokenNumber == SEMICOL)
			return 1;

		fprintf(yyout,"fez bosta\n");
		fprintf(yyout, "[%s]", p->id);
		return 1;
	}
	else
	{
		for(i = 0; i < p->num_filhos; i++){
			printTree(p->filhos[i], depth+1);
		}
	}
}

int trataVars(tipoTree *p){

	if(p == NULL)
		return 0;
	if(p->num_filhos == 0)
	{
		if ((p->tokenNumber == NAME) && (consultaVar(vars, p->id) == NULL) && !(consultaFuncs(funcs,p->id))){
			insereVar(&vars, p->id, 0);
			fprintf(yyout, "%s: .word 0\n", p->id);
		}
	}
	else
	{
		int i;
		for(i = 0; i < p->num_filhos; i++)
			trataVars(p->filhos[i]);
	}
}

int trataFuncs(tipoTree *p){

	if(p == NULL)
		return 0;

	if(strcmp(p->nonTerminal,"decFunc") == 0){

		if(!consultaFuncs(funcs, p->filhos[2]->id)) {
			insereFunc(&funcs, p->filhos[2]->id);
		}
	}
	else
	{
		int i;
		for(i = 0; i < p->num_filhos; i++)
			trataFuncs(p->filhos[i]);
	}
}

int geraExpr(tipoTree *p, int depth){

	int i, x, y;
	if (p == NULL)
		return 0;

	if(p->num_filhos == 3){
		x = geraExpr(p->filhos[0], depth);
		y = geraExpr(p->filhos[2], depth);
		fprintf(yyout, "lw $t1, 4($sp)\n");
		fprintf(yyout,"addiu $sp, $sp, 4\n");
		fprintf(yyout, "lw $a0, 4($sp)\n");
		fprintf(yyout,"addiu $sp, $sp, 4\n");

		if(p->filhos[1]->tokenNumber == PLUS){
			fprintf(yyout,"add $a0, $a0, $t1\n");
			G_ACC = x + y;
		}
		else if(p->filhos[1]->tokenNumber == MINUS){
			fprintf(yyout,"sub $a0, $a0, $t1\n");
			G_ACC = x - y;
		}
		else if(p->filhos[1]->tokenNumber == TIMES){
			fprintf(yyout,"mult $a0, $t1\n");
			fprintf(yyout,"mflo $a0\n");
			G_ACC = x*y;
		}
		else if(p->filhos[1]->tokenNumber == DIV){
			fprintf(yyout,"div $a0, $t1\n");
			fprintf(yyout,"mflo $a0\n");
			G_ACC =  x/y;
		}
		else if(p->filhos[1]->tokenNumber == EQ)
		{
			fprintf(yyout, "seq $a0, $a0, $t1\n");
		}
		else if(p->filhos[1]->tokenNumber == NEQ)
		{
			fprintf(yyout, "sne $a0, $a0, $t1\n");
		}
		else if(p->filhos[1]->tokenNumber == GTEQ)
		{
			fprintf(yyout, "sge $a0, $a0, $t1\n");
		}
		else if(p->filhos[1]->tokenNumber == GT)
		{
			fprintf(yyout, "sgt $a0, $a0, $t1\n");
		}
		else if(p->filhos[1]->tokenNumber == LTEQ)
		{
			fprintf(yyout, "sle $a0, $a0, $t1\n");
		}
		else if(p->filhos[1]->tokenNumber == LT)
		{
			fprintf(yyout, "slt $a0, $a0, $t1\n");
		}
		else if(p->filhos[1]->tokenNumber == AND)
		{
			fprintf(yyout, "and $a0, $a0, $t1\n");
		}
		else if(p->filhos[1]->tokenNumber == OR)
		{
			fprintf(yyout, "or $a0, $a0, $t1\n");
		}

		fprintf(yyout, "sw $a0, 0($sp)\n");
		fprintf(yyout, "addiu $sp, $sp, -4\n");
		return G_ACC;
	}
	else if(p->num_filhos == 2){

		geraExpr(p->filhos[1], depth);
		fprintf(yyout, "lw $a0, 4($sp)\n");
		fprintf(yyout, "addiu $sp, $sp, 4\n");

		if(p->filhos[0]->tokenNumber == MINUS){
			fprintf(yyout, "li $t1 -1\n");
			fprintf(yyout,"mult $a0, $t1\n");
			fprintf(yyout,"mflo $a0\n");
		}
		else{
			fprintf(yyout, "not $a0, $a0\n");
		}

		return 1;
	}
	else if(p->num_filhos == 1)
	{
		printf("gera code funcall filho\n");
		return 1;
	}
	else if(p->tokenNumber == NUMBER) {
		int intValue = atoi(p->id);
		fprintf(yyout, "li $a0, %d\n", intValue);
		fprintf(yyout, "sw $a0, 0($sp)\n");
		fprintf(yyout,"addiu $sp, $sp, -4\n");
		return intValue;
	}
	else if(p->tokenNumber == NAME) {
		listaVar *aux = consultaVar(vars, p->id);
		if (aux == NULL)
			printf("Erro : var nao encontrada!!!!\n");
		else{
			fprintf(yyout, "lw $a0, %s\n", p->id);
			fprintf(yyout, "sw $a0, 0($sp)\n");
			fprintf(yyout,"addiu $sp, $sp, -4\n");
		}
		return aux->varValue;
	}
	printf("aquiiiii\n");
	for(i = 0; i < p->num_filhos; i++){
		geraExpr(p->filhos[i], depth);
	}
	return 0;
}

int geraMultStmt(tipoTree *p, int depth){

	int i;
	if (p == NULL)
		return 0;

	if(p->nonTerminal != NULL && strcmp(p->nonTerminal, "stmt") == 0){

		if(p->filhos[0]->tokenNumber == NAME)
		{
			geraExpr(p->filhos[2], depth);
			fprintf(yyout, "addiu $sp, $sp, 4\n");
			listaVar *aux;
			int new_value = G_ACC;
			aux = consultaVar(vars, p->filhos[0]->id);
			aux->varValue = new_value;
			fprintf(yyout, "sw $a0, %s\n", p->filhos[0]->id);
			return 1;
		}
		else if (p->filhos[0]->tokenNumber == IF)
		{
			cont_if++;
			geraExpr(p->filhos[2], depth);
			fprintf(yyout, "li $t1, 0\n");
			fprintf(yyout, "beq $a0, $t1, false_bi%d\n",cont_if);
			geraCode(p->filhos[4], depth);
			fprintf(yyout, "j exit_if%d\n", cont_if);
			fprintf(yyout, "false_bi%d:\n", cont_if);
			geraCode(p->filhos[5], depth);
			fprintf(yyout, "exit_if%d:\n", cont_if);
			return 1;
		}
		else if (p->filhos[0]->tokenNumber == WHILE)
		{
			cont_while++;
			fprintf(yyout, "true_bw%d:\n", cont_while);
			geraExpr(p->filhos[2], depth);
			fprintf(yyout, "li $t1, 0\n");
			fprintf(yyout, "beq $a0, $t1, false_bw%d\n", cont_while);
			geraCode(p->filhos[4], depth);
			fprintf(yyout, "j true_bw%d\n", cont_while);
			fprintf(yyout, "false_bw%d:\n", cont_while);
			return 1;
		}
		else if (p->filhos[0]->tokenNumber == RETURN)
		{
			//Se tiver um filho não nulo
			if(p->filhos[1]->nonTerminal != NULL){
				geraCode(p->filhos[1], depth);
		
				// volta o codigo do gerado
				return 1;
			} else{
				// volta para quem chamou
				return 1;
			}
		}
		else if (p->filhos[0]->tokenNumber == BREAK)
		{
			fprintf(yyout, "j false_bw%d\n", cont_while);
			return 1;
		}
		else if (p->filhos[0]->tokenNumber == CONTINUE)
		{
			fprintf(yyout, "j true_bw%d\n", cont_while);
			return 1;
		}
		else{
			if(strcmp(p->filhos[0]->filhos[0]->id, "print") == 0){
				printf("Printa algo\n");
				geraExpr(p->filhos[0]->filhos[2]->filhos[0], depth);
				fprintf(yyout, "li $v0, 1\n");
				fprintf(yyout, "syscall\n");
				fprintf(yyout, "li $v0, 4\n");
				fprintf(yyout, "la $a0, _newline\n");
				fprintf(yyout, "syscall\n");
				return 1;
			}
			if(strcmp(p->filhos[0]->filhos[0]->id, "funcall") == 0){
				
				// GERAR CODIGO FUNCALL AQUI
				printf("gera funCall in stmt\n");
			}
		}
	}
	for(i = 0; i < p->num_filhos; i++)
		geraMultStmt(p->filhos[i], depth);

	return 0;
}

int geraMultVar(tipoTree *p, int depth){

	int i;
	if (p == NULL)
		return 0;

	if(p->nonTerminal != NULL && strcmp(p->nonTerminal, "decVar") == 0){

		if(p->filhos[2]){
			geraExpr(p->filhos[2]->filhos[1], depth);
			fprintf(yyout, "addiu $sp, $sp, 4\n");
			listaVar *aux;
			int new_value = G_ACC;
			aux = consultaVar(vars, p->filhos[1]->id);
			aux->varValue = new_value;
			fprintf(yyout, "sw $a0, %s\n", p->filhos[1]->id);
			return 1;
		}
		return 1;
	}
	for(i = 0; i < p->num_filhos; i++){
		geraMultVar(p->filhos[i], depth);
	}
	return 0;
}

int geraCode(tipoTree *p, int depth){

	int i;
	if(p == NULL)
		return 0;

	if(p->nonTerminal != NULL){

		printf("%s\n", p->nonTerminal);

		if(strcmp(p->nonTerminal, "expr") == 0){
			printf("jeba\n");
			geraExpr(p, depth);
			return 0;
		}
		if(strcmp(p->nonTerminal, "multStmt") == 0){
			geraMultStmt(p, depth);
			return 0;
		}
		if(strcmp(p->nonTerminal, "multVar") == 0 || strcmp(p->nonTerminal, "decVar") == 0){
			geraMultVar(p, depth);
			return 0;
		}
	}

	for(i = 0; i < p->num_filhos; i++){
			geraCode(p->filhos[i], depth+1);
	}
}

int main(int argc, char** argv){

	yyin = fopen(argv[1], "r");
	yyout = fopen(argv[2], "w");

	if(!yyin) fprintf(yyout, "Arquivo nao pode ser aberto!\n");
	else{
		yyparse();
	}

	//Inicialização de ambiente
	insereFunc(&funcs, "print");
	trataFuncs(treeRoot);

	//Inicializacao MIPS
	fprintf(yyout, "\n.data\n");
	trataVars(treeRoot);
	fprintf(yyout, "\n");
	fprintf(yyout, "_newline: .asciiz \"\\n\"\n");
	fprintf(yyout,".text\n");
	fprintf(yyout,".globl main\n\n");
	fprintf(yyout,"main:\n");

	//printTree(treeRoot, 0);
	
	geraCode(treeRoot, 0);

	//Printa acumulador
	// fprintf(yyout, "li $v0, 1\n");
	// fprintf(yyout, "syscall\n");

	fprintf(yyout, "li $v0, 4\n");
	fprintf(yyout, "la $a0, _newline\n");
	fprintf(yyout, "syscall\n");

	fprintf(yyout, "\nli $v0, 10\n");
	fprintf(yyout, "syscall");
	fprintf(yyout,"\n");

	fclose(yyin);
	fclose(yyout);

	return 0;
}
