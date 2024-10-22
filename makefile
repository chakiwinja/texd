CC= gcc

CDEPS= -Ilib -Iinclude -lSDL2

CFLAGS= $(CDEPS) 

DBGFLAGS= -g

SRC = $(wildcard src/*.c)
BIN = texd

run: build
	bin/$(BIN)

build: source
	$(CC) $(CFLAGS) obj/*.o -o bin/$(BIN)

source:
	$(CC) $(CFLAGS) $(SRC) -c
	mv *.o obj/

clean: 
	rm -rf obj/*.o
	rm -rf bin/$(BIN)
