all: 	scanner.l
	lex -l scanner.l
	gcc lex.yy.c -o scanner
