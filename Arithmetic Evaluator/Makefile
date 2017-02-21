########################################
##
## Makefile
## LINUX compilation 
##
##############################################


CC=g++
C++FLAGS=-g -Wall
INCLUDES=-I.
ALL_OBJ = main.o evaluator.o 
PROG_NAME= TranHw1

%.o : %.cpp
	g++  -c $< -o $@ $(C++FLAGS)

$(PROG_NAME): $(ALL_OBJ)
	$(CC) $(C++FLAG) -o $@ $(ALL_OBJ) $(INCLUDES)

all:
	make $(PROG_NAME)

clean:
	(rm -f *.o;)
