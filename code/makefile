#Pattern Rules
all: token

clean: 
	rm -f token *.o

token: main.c token.o
	gcc -Wall -g main.c token.c -o token

token.o: token.h