#include <iostream>
#include "BSTreeDict.h"

int main() {
    BSTreeDict<int> dict;

    std::cout << "dict.entries(): " << dict.entries() << "\n";

    dict.insert("c", 3);
    dict.insert("f", 6);
    dict.insert("a", 1);
    dict.insert("b", 2);
    dict.insert("d", 4);
    dict.insert("e", 5);

    std::cout << dict << "\n";

    std::cout << "dict['a']: " << dict["a"] << "\n";
    std::cout << "dict['d']: " << dict["d"] << "\n";

    dict.remove("c");
    std::cout << "After remove('c'):\n" << dict << "\n";

    try {
        dict.insert("a", 100);
    } catch(std::runtime_error &e) {
        std::cout << "insert('a') => OK! Exception: " << e.what() << "\n";
    }

    try {
        dict.search("j");
    } catch(std::runtime_error &e) {
        std::cout << "search('j') => OK! Exception: " << e.what() << "\n";
    }

    try {
        dict.remove("c");
    } catch(std::runtime_error &e) {
        std::cout << "remove('c') => OK! Exception: " << e.what() << "\n";
    }

    return 0;
}

