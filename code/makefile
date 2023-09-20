#Macros
CC = gcc
FLAGS = -Wall -g

#Pattern Rules
all: token

clean: 
	rm -f token *.o

token: main.c token.o
	$(CC) $(FLAGS) main.c token.c -o token

token.o: token.h