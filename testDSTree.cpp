#include <iostream>
#include "BSTree.h"

int main() {
    BSTree<int> bstree;

    std::cout << "bstree.size(): " << bstree.size() << "\n";
    std::cout << "cout << bstree: " << bstree << "\n";

    int valores[] = {15, 7, 3, 11, 9, 18, 21, 20};
    for(int v : valores) {
        bstree.insert(v);
        std::cout << "Inserted " << v << ", bstree.size(): " << bstree.size() << "\n";
        std::cout << bstree << "\n";
    }

    try {
        bstree.search(0);
    } catch(std::runtime_error &e) {
        std::cout << "search(0) => OK! Exception: " << e.what() << "\n";
    }

    try {
        bstree.insert(9);
    } catch(std::runtime_error &e) {
        std::cout << "insert(9) => OK! Exception: " << e.what() << "\n";
    }

    bstree.remove(9);
    std::cout << "After remove(9), bstree.size(): " << bstree.size() << "\n";
    std::cout << bstree << "\n";

    return 0;
}

