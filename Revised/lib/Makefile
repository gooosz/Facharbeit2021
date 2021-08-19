#which compiler to use
CC = g++

#Flags
FLAGS = -Wall -g

all: main.o typeConv.o Constructors.o helperFunctions.o operators.o
	$(CC) main.o typeConv.o Constructors.o helperFunctions.o operators.o -o main

main.o: main.cpp
	$(CC) $(FLAGS) -c main.cpp

typeConv.o: typeConv.cpp BigInt.hpp
	$(CC) $(FLAGS) -c typeConv.cpp -lm

Constructors.o: Constructors.cpp BigInt.hpp
	$(CC) $(FLAGS) -c Constructors.cpp -lm

helperFunctions.o: helperFunctions.cpp BigInt.hpp
	$(CC) $(FLAGS) -c helperFunctions.cpp -lm

operators.o: operators.cpp BigInt.hpp
	$(CC) $(FLAGS) -c operators.cpp -lm


#create a library
lib: all
	ar crs bigInt.a typeConv.o Constructors.o helperFunctions.o operators.o

clean:
	rm *.o *.a main



