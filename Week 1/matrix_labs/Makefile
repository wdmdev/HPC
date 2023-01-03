LIB_PATH = -L /usr/lib64/atlas -lsatlas
CC = gcc
OPT = -g -O3
WARN = -Wall
CFLAGS = $(OPT) $(WARN) -std=c99 $(LIB_PATH)
OBJECTS = matrix2d.o ex5.o

project: $(OBJECTS)
	$(CC) $(CFLAGS) -o ex5 $(OBJECTS)

clean:
	@rm -f *.o core
