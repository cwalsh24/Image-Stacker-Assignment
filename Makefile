#
# Makefile for Stacker Assignment
# Group: Code4Days (Isaac Copeland, Connor Walsh)
# Date: 09/19/2022
#

# variables for compiler flags
CC = g++
CFLAGS = -Wall -Wextra -g -c
TARGET = -Wall -Wextra -g -o stacker

# default target
default: stacker

# compilation instructions for components of executable
stacker: stacker.o main.o
	$(CC) $(TARGET) Stacker.o main.o

# compilation instructions for components of object files
Stacker.o: stacker.cpp stacker.h
	$(CC) $(CFLAGS) Stacker.cpp

main.o: main.cpp stacker.h
	$(CC) $(CFLAGS) main.cpp

# make clean instructions
clean:
	$(RM) stacker *~ *.o
