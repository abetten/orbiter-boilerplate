SRC=../../orbiter/src
DISCRETA_CPP = g++
DISCRETA_CC = gcc
CPPFLAGS = -Wall -I$(SRC)/lib -std=c++14
LIB = $(SRC)/lib/liborbiter.a -lpthread
LFLAGS = -lm -Wl,-rpath -Wl,/usr/local/gcc-8.2.0/lib64
#LFLAGS = -lm -lpthread -Wl,-rpath -Wl,/projects/abetten@colostate.edu/gcc-install-destdir/usr/local/gcc-8.1/lib64



TARGETS=\
		ff1.out 

all: $(TARGETS)


ff1.out:  ff1.o ;
	$(DISCRETA_CPP)  ff1.o $(CPPFLAGS) $(LIB) $(LFLAGS) -o $@


install:
	cp $(TARGETS) ../../../bin



clean:
	- rm *.o *.a *.out *~

