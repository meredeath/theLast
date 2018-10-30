all: meta.o
	gcc meta.o -o test
meta.o: meta.c
	gcc -c meta.c
run: all
	./test
