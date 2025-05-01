CC=/usr/bin/gcc
LD=/usr/bin/gcc

all: emulator.o link

emulator.o:
	$(CC) -c src/emulator.c -o bin/emulator.o

link:
	$(LD) bin/emulator.o -o emulator