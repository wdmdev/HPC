CC	= gcc -std=c99
DEBUG	= -g -Wall
OPT	= 
CFLAGS	= $(DEBUG) $(OPT)
OBJECTS = pi.o main.o
LDFLAGS = $(CFLAGS)

my_pi: $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ $(LDLIBS)

clean:
	/bin/rm -f *.o core 

realclean: clean
	/bin/rm -f project1

pi.o: pi.c pi.h
main.o: pi.h main.c
