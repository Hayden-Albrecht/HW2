CC = gcc
CFLAGS = -Wall -Wextra -std=c11

all: coordinator checker

coordinator: coordinator.c
	$(CC) $(CFLAGS) -o coordinator coordinator.c

checker: checker.c
	$(CC) $(CFLAGS) -o checker checker.c

clean:
	rm -f coordinator checker

.PHONY: all clean
