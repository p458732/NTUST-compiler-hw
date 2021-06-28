##################################################################
#
#	Makefile -- P Parser
#
##################################################################
all: clean mkdir main
mkdir:
	mkdir -p output


main: 
	lex src/ada.l 
	yacc -d src/ada.y
	mv ./y.tab.c ./src/y.tab.c
	mv ./y.tab.h ./src/y.tab.h
	mv ./lex.yy.c ./src/lex.yy.c
	
	g++ -o output/scanner  ./src/lex.yy.c ./src/y.tab.c
 
	
clean: 
	rm -f output/*.*

