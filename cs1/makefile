SRC=../../orbiter/src
DISCRETA_CPP = g++
DISCRETA_CC = gcc
CPPFLAGS = -Wall -I$(SRC)/lib -std=c++14
LIB = $(SRC)/lib/liborbiter.a -lpthread
LFLAGS = -lm -Wl,-rpath -Wl,/usr/local/gcc-8.2.0/lib64
#LFLAGS = -lm -lpthread -Wl,-rpath -Wl,/projects/abetten@colostate.edu/gcc-install-destdir/usr/local/gcc-8.1/lib64

MY_PATH=../../orbiter
#MY_PATH=/scratch/betten/COMPILE/orbiter


# uncomment exactly one of the following two lines.
# uncomment the first if you want to run orbiter through docker.
# uncomment the second if you have an installed copy of orbiter and you want to run it directly 
#ORBITER_PATH=docker run -it --volume ${PWD}:/mnt -w /mnt abetten/orbiter 
ORBITER_PATH=$(MY_PATH)/src/apps/orbiter/


TARGETS=\
		cs1.out 

all: $(TARGETS)


cs1.out:  cs1.o ;
	$(DISCRETA_CPP)  cs1.o $(CPPFLAGS) $(LIB) $(LFLAGS) -o $@


install:
	cp $(TARGETS) ../../../bin



clean:
	- rm *.o *.a *.out *~



F_abcd_sweep_4_27_q7_classify:
	$(ORBITER_PATH)orbiter.out -v 2 \
		-define F -finite_field -q 7 -end \
		-define P -projective_space 3 F -end \
		-with P -do \
		-projective_space_activity \
		-canonical_form_PG \
		-input \
			-file_of_points F_abcd_q7_points.txt \
		-end \
		-classification_prefix F_abcd_q7 \
		-report \
		-end \
		-end
	pdflatex F_abcd_q7_classification.tex
	open F_abcd_q7_classification.pdf
