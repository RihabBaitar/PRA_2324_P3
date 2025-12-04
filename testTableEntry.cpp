#include <iostream>
#include "TableEntry.h"

int main() {
    TableEntry<int, std::string> e1(1, "hola");
    TableEntry<int, std::string> e2(2, "adios");

    std::cout << e1 << std::endl;
    std::cout << e2 << std::endl;

    return 0;
}

