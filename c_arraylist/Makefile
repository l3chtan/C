CC=gcc
CFLAGS=-std=c99 -pedantic -Wall -D_XOPEN_SOURCE=500 -D_DEFAULT_SOURCE -g 

all:  al_test

al_test: gen_arraylist.o foo.o
	$(CC) $(CFLAGS) -o al_test gen_arraylist.o foo.o
#
arraylist.o: arraylist.c
	$(CC) $(CFLAGS) -c -o gen_arraylist.o gen_arraylist.c
#
foo.o: foo.c gen_alist.h
	$(CC) $(CFLAGS) -c -o foo.o foo.c
#
clean:
	rm -rf *.o al_test
