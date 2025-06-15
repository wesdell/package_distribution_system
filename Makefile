CC = gcc
CFLAGS = -Wall -Iinclude -lpthread
SRC = src

all: thread process

thread: $(SRC)/thread.c $(SRC)/transactions.c $(SRC)/utils.c
	$(CC) $(CFLAGS) $^ -o thread

process: $(SRC)/process.c $(SRC)/transactions.c $(SRC)/utils.c
	$(CC) $(CFLAGS) $^ -o process

clean:
	rm -f thread process results/*
