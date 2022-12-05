CXX = g++
CXXFLAGS = -Wall -std=c++11 

OBJECTS = wrapper.o bar.o

listwrapper: $(OBJECTS)
	$(CXX) -g $(CXXFLAGS) -o bard wrapper.o bar.o 

bar.o: bar.cpp bard.h
	$(CXX) -g $(CXXFLAGS) -c bar.cpp
	
wrapper.o: wrapper.cpp bard.h 
	$(CXX) -g $(CXXFLAGS) -c wrapper.cpp

clean: 
	rm -f *.o
	rm bard
