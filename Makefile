#!make -f

CXX=clang++-9 
CXXFLAGS=-std=c++2a

HEADERS=PhoneticFinder.hpp
OBJECTS=PhoneticFinder.o

run: demo test test1 test2
	./$^

demo: Demo.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o demo

test: TestCounter.o Test.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o test

test1: TestCounter.o Test_ofek.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o test1

test2: TestCounter.o Test_snir.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o test2

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) --compile $< -o $@

clean:
	rm -f *.o demo test test1 test2