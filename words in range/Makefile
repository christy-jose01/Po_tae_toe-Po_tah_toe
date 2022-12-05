CXX = g++
CXXFLAGS = -Wall -std=c++11

OBJECTS = functions.o wrapper.o

wordrange: $(OBJECTS)
	$(CXX) -g $(CXXFLAGS) -o wordrange $(OBJECTS)

wrapper.o: wrapper.cpp 
	$(CXX) -g $(CXXFLAGS) -c wrapper.cpp

functions.o: functions.cpp functions.h
	$(CXX) -g $(CXXFLAGS) -c functions.cpp

clean:
	rm -f *.o
	rm wordrange
