CC = gcc
OPT = -g -O3
WARN = -Wall
CFLAGS = $(OPT) $(WARN)
OBJECTS = data.o io.o main.o

excer1: $(OBJECTS)
	$(CC) $(CFLAGS) -o excer1 $(OBJECTS)

clean:
	@rm -f *.o core

realclean:
	@rm -f excer1

# file dependencies
data.o: data.c data.h
io.o: io.c io.h
main.o: main.c io.h data.h