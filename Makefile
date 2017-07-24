CC=clang
CFLAGS=-c -Wall

all: salloc

salloc: slab.o salloc.o
	$(CC) -Wall slab.o salloc.o -o salloc

salloc.o: salloc.c salloc.h
	$(CC) $(CFLAGS) slab.o salloc.c salloc.h

slab.o: slab.c slab.h
	$(CC) -c slab.c slab.h
