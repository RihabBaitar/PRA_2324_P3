#include <iostream>
#include <stdexcept>
#include "BSTree.h"

int main() {
    BSTree<int> bstree;

    std::cout << "Creating BSTree<int> bstree ..." << std::endl << std::endl;

    std::cout << "bstree.size(): " << bstree.size() << std::endl;
    std::cout << "cout << bstree: " << std::endl << bstree << std::endl;

    int elems[] = {15, 7, 3, 11, 9, 18, 21, 20};

    for (int e : elems) {
        std::cout << "bstree.insert(" << e << ")" << std::endl;
        bstree.insert(e);
        std::cout << "-----------------" << std::endl;
        std::cout << "bstree.size(): " << bstree.size() << std::endl;
        std::cout << "bstree.search(" << e << "): " << bstree.search(e) << std::endl;
        std::cout << "cout << bstree: " << std::endl << bstree << std::endl;
    }

    try {
        bstree.search(0);
    } catch (const std::runtime_error &e) {
        std::cout << "bstree.search(0) => OK! It throwed std::runtime_error: " << e.what() << std::endl;
    }

    try {
        bstree.insert(9);
    } catch (const std::runtime_error &e) {
        std::cout << "bstree.insert(9) => OK! It throwed std::runtime_error: " << e.what() << std::endl;
    }

    try {
        bstree.remove(50);
    } catch (const std::runtime_error &e) {
        std::cout << "bstree.remove(50) => OK! It throwed std::runtime_error: " << e.what() << std::endl;
    }

    int removeElems[] = {9, 11, 7, 15};
    for (int e : removeElems) {
        std::cout << std::endl << "bstree.remove(" << e << ")" << std::endl;
        bstree.remove(e);
        std::cout << "----------------" << std::endl;
        std::cout << "bstree.size(): " << bstree.size() << std::endl;
        std::cout << "cout << bstree: " << std::endl << bstree << std::endl;

        std::cout << std::endl << "bstree.insert(" << e << ")" << std::endl;
        bstree.insert(e);
        std::cout << "----------------" << std::endl;
        std::cout << "bstree.size(): " << bstree.size() << std::endl;
        std::cout << "cout << bstree: " << std::endl << bstree << std::endl;
    }

    return 0;
}

