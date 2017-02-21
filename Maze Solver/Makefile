########################################
##
## Makefile
## LINUX compilation 
##
##############################################


CC=g++
C++FLAGS=-g -Wall
INCLUDES=-I.
ALL_OBJ = tranHW2.o mazeSolver.o 
PROG_NAME= TranHw2

%.o : %.cpp
	g++  -c $< -o $@ $(C++FLAGS)

$(PROG_NAME): $(ALL_OBJ)
	$(CC) $(C++FLAG) -o $@ $(ALL_OBJ) $(INCLUDES)

all:
	make $(PROG_NAME)

clean:
	(rm -f *.o;)
