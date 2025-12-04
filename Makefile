CXX = g++
CXXFLAGS = -std=c++11 -Wall -g
INC = .

all: bin/testTableEntry bin/testHashTable bin/testBSTree bin/testBSTreeDict

bin/testTableEntry: testTableEntry.cpp TableEntry.h
	$(CXX) $(CXXFLAGS) -I$(INC) testTableEntry.cpp -o bin/testTableEntry

bin/testHashTable: testHashTable.cpp HashTable.h TableEntry.h Dict.h ListLinked.h
	$(CXX) $(CXXFLAGS) -I$(INC) testHashTable.cpp -o bin/testHashTable

bin/testBSTree: testBSTree.cpp BSTree.h BSNode.h
	$(CXX) $(CXXFLAGS) -I$(INC) testBSTree.cpp -o bin/testBSTree

bin/testBSTreeDict: testBSTreeDict.cpp BSTreeDict.h BSTree.h BSNode.h TableEntry.h Dict.h
	$(CXX) $(CXXFLAGS) -I$(INC) testBSTreeDict.cpp -o bin/testBSTreeDict

clean:
	rm -rf bin/testTableEntry bin/testHashTable bin/testBSTree bin/testBSTreeDict

