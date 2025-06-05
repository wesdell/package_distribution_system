# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -pthread
SRC_DIR = src
OBJ_DIR = obj

# Sources
UTILS = $(SRC_DIR)/utils.c $(SRC_DIR)/transactions.c

# Targets
all: process thread

process: $(SRC_DIR)/process.c $(UTILS)
	$(CC) $(CFLAGS) -o process $(SRC_DIR)/process.c $(UTILS)

thread: $(SRC_DIR)/thread.c $(UTILS)
	$(CC) $(CFLAGS) -o thread $(SRC_DIR)/thread.c $(UTILS)

clean:
	rm -f process thread *.o *.out *.log
	rm -f results/*.txt

.PHONY: all clean