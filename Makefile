#MAKEFILE

all:main

main:main.o linked_op.o
	gcc -o main main.o linked_op.o

linked_op.o:linked_op.c linked_op.h
	gcc -o linked_op.o -c linked_op.c -W -Wall -ansi -pedantic


main.o:main.c linked_op.h
	gcc -o main.o -c main.c -W -Wall -ansi -pedantic


clean:
	rm -rf *.o

mrproper:
	rm -rf main