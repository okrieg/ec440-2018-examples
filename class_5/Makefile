# Makefile for tokenizer examples
CFLAGS = -Wall -g -Wno-missing-braces
CC = gcc
SHELLOBJ = myshell.o parse.o
PROGS = forever pch pchwait up myshell

all: $(PROGS)
pch: pch.o
forever: forever.o
pchwait: pchwait.o
up: up.o
myshell: $(SHELLOBJ)

clean: 
	rm -f $(PROGS)  *.o *~
