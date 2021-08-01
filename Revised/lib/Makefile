#which compiler to use
CC = g++

#Flags
FLAGS = -Wall -g

all: main.o BigInt.o Constructors.o helperFunctions.o print.o
	$(CC) main.o typeConv.o Constructors.o helperFunctions.o -o main
#put print.o in here

main.o: main.cpp
	$(CC) $(FLAGS) -c main.cpp

typeConv.o: typeConv.cpp BigInt.hpp
	$(CC) $(FLAGS) -c typeConv.cpp -lm

Constructors.o: Constructors.cpp BigInt.hpp
	$(CC) $(FLAGS) -c Constructors.cpp -lm

helperFunctions.o: helperFunctions.cpp BigInt.hpp
	$(CC) $(FLAGS) -c helperFunctions.cpp -lm

#g++ -Wall -g main.o typeConv.cpp Constructors.cpp helperFunctions.cpp operators.cpp print.cpp -o main


clean:
	rm *.o main



