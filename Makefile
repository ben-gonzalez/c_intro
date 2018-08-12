CPP=/usr/bin/g++
CFLAGS= -g -Wall -I. -std=c++14
LINKFLAGS= -g -Wall

all: demo

demo: list.o main.o tests.o
	$(CPP) $(LINKFLAGS) -o demo list.o main.o tests.o -lgtest -lpthread

tests.o: tests.cpp list.h
	$(CPP) $(CFLAGS) -c tests.cpp -o tests.o

list.o: list.h list.cpp
	$(CPP) $(CFLAGS) -c list.cpp -o list.o

main.o: main.cpp list.h
	$(CPP) $(CFLAGS) -c main.cpp -o main.o

clean:
	rm -f *.o demo
