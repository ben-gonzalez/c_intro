CPP=/usr/bin/g++
CFLAGS= -g -Wall -I. -std=c++14
LINKFLAGS= -g -Wall

all: demo

demo: List.o main.o Tests.o
	$(CPP) $(LINKFLAGS) -o demo List.o main.o Tests.o -lgtest -lpthread

Tests.o: Tests.cpp List.h
	$(CPP) $(CFLAGS) -c Tests.cpp -o Tests.o

List.o: List.h List.cpp
	$(CPP) $(CFLAGS) -c List.cpp -o List.o

main.o: main.cpp List.h
	$(CPP) $(CFLAGS) -c main.cpp -o main.o

clean:
	rm -f *.o demo
