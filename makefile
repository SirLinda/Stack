CXX=g++ -g -std=c++11 -Wall -pedantic -Werror=vla
all: tests

tests: tests.o tests.cpp mystacks.cpp mystacks.h
	$(CXX) tests.o mystacks.cpp
tests.o: tests.cpp
	$(CXX) -c -o tests.o tests.cpp
