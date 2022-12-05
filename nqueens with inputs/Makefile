CXX = g++
CXXFLAGS = -Wall -std=c++11

OBJECTS = list.o wrapper.o queen.o 

nqueens: $(OBJECTS)
	$(CXX) -g $(CFLAGS) -o nqueens $(OBJECTS) 

wrapper.o: wrapper.cpp
	$(CXX) -g $(CFLAGS) -c wrapper.cpp

queen.o: queen.cpp queen.h 
	$(CXX) -g $(CFLAGS) -c queen.cpp

list.o: list.cpp list.h
	$(CXX) -g $(CFLAGS) -c list.cpp

clean:
	rm -f *.o
	rm nqueens
