CC=gcc
CFLAGS=-Wall -Wextra -pedantic -g

httpparser: parseur.o api.o utils.o main.o
	$(CC) $(CFLAGS) -o httpparser parseur.o api.o utils.o main.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

parseur.o: parseur.c global.h
	$(CC) $(CFLAGS) -c parseur.c

api.o: api.c api.h
	$(CC) $(CFLAGS) -c api.c

utils.o: utils.c utils.h
	$(CC) $(CFLAGS) -c utils.c

clean:
	rm -f *.o main
