CC	= gcc -std=c99
DEBUG = -g -Wall
PARA = 
OPT	= -Ofast -ffast-math -funroll-all-loops $(PARA)
CFLAGS	= $(DEBUG) $(OPT)
OBJECTS = pi.o main.o matrix_vector.o
LDFLAGS = $(CFLAGS)

matrix_vec: $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ $(LDLIBS)

clean:
	/bin/rm -f *.o core 

realclean: clean
	/bin/rm -f matrix_vec

pi.o: pi.h pi.c
matrix_vector.o:  matrix_vector.h matrix_vector.c
main.o: pi.h matrix_vector.h main.c
