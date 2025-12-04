CXX = g++
CXXFLAGS = -std=c++11 -Wall -g
INC = .

all: bin/testTableEntry bin/testHashTable

bin/testTableEntry: testTableEntry.cpp TableEntry.h
	$(CXX) $(CXXFLAGS) -I$(INC) testTableEntry.cpp -o bin/testTableEntry

bin/testHashTable: testHashTable.cpp HashTable.h TableEntry.h Dict.h ListLinked.h
	$(CXX) $(CXXFLAGS) -I$(INC) testHashTable.cpp -o bin/testHashTable

clean:
	rm -rf bin/testTableEntry bin/testHashTable

