#include <iostream>
#include "HashTable.h"

int main() {
    HashTable<int, std::string> ht(5);

    ht.insert(1, "uno");
    ht.insert(2, "dos");
    ht.insert(6, "seis");

    std::cout << ht;

    std::cout << "search(2) = " << ht.search(2) << std::endl;

    ht.remove(1);
    std::cout << ht;

    return 0;
}

