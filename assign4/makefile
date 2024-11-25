# Define Makefile variables
CC = g++ -std=c++11 -g
# CFLAGS = -Wall -Werror    # Uncomment to use, stricter compiler errors
EXE_FILE = main

all: $(EXE_FILE)

$(EXE_FILE): prog.cpp event.o wumpus.o room.o gold.o pit.o bats.o game.o
	$(CC) $(CFLAGS) prog.cpp event.o wumpus.o room.o gold.o pit.o bats.o game.o -g -o $(EXE_FILE)

event.o: event.cpp event.h
	$(CC) $(CFLAGS) -c event.cpp

wumpus.o: wumpus.cpp wumpus.h
	$(CC) $(CFLAGS) -c wumpus.cpp

room.o: room.cpp room.h
	$(CC) $(CFLAGS) -c room.cpp

gold.o: gold.cpp gold.h
	$(CC) $(CFLAGS) -c gold.cpp

pit.o: pit.cpp pit.h
	$(CC) $(CFLAGS) -c pit.cpp

bats.o: bats.cpp bats.h
	$(CC) $(CFLAGS) -c bats.cpp

game.o: game.cpp game.h
	$(CC) $(CFLAGS) -c game.cpp

