#Macros
CC = gcc
FLAGS = -Wall -g

#Pattern Rules
%.o: %.c
	$(CC) $(FLAGS) -c $<

all: token

clean: 
	rm -f token *.o

token: main.c token.o
	$(CC) $(FLAGS) $< token.c -o $@

token.o: token.h