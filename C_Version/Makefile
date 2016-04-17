# Compiling the Hamming Code Program
CC=gcc
#CFLAGS=-c -Wall

all: hamming_code_exe

hamming_code_exe:
	$(CC) main.c hamming_code.c common.c -o hamming_code_exe

run:
	./hamming_code_exe 10 10110

clean:
	rm hamming_code_exe