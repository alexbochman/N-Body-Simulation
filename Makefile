
CC = g++
CFLAGS = -c -g -Og -Wall -Werror -ansi -pedantic
LIBS = -lsfml-graphics -lsfml-window -lsfml-system

all: main.o Body.o
	$(CC) main.o Body.o -o NBody $(LIBS)

main.o: main.cpp
	$(CC) $(CFLAGS) -o $@ $< -std=c++14

Body.o: Body.cpp Body.hpp
	$(CC) $(CFLAGS) -o $@ $< -std=c++14

clean:
	rm NBody *.o