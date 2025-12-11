# the make file

CC = gcc
CFLAGS = -Wall -Wextra -std=c11

all: main.out


main.out: main.o functions.o
	$(CC) $(CFLAGS) -o main.out main.o functions.o -lm




main.o: main.c functions.h
	$(CC) $(CFLAGS) -c main.c




functions.o: functions.c functions.h
	$(CC) $(CFLAGS) -c functions.c



clean:
	rm -f *.o main.out
