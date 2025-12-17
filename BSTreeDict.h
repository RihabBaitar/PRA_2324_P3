#ifndef BSTREEDICT_H
#define BSTREEDICT_H

#include <iostream>
#include <stdexcept>
#include "Dict.h"
#include "BSTree.h"
#include "TableEntry.h"

template <typename V>
class BSTreeDict : public Dict<std::string, V> {
private:
    BSTree<TableEntry<std::string, V>>* tree;

public:
    BSTreeDict() { tree = new BSTree<TableEntry<std::string, V>>(); }
    ~BSTreeDict() { delete tree; }

    void insert(const std::string& key, const V& value) override {
        TableEntry<std::string, V> entry(key, value);
        tree->insert(entry);
    }

    V search(const std::string& key) const override {
        TableEntry<std::string, V> temp(key, V());
        TableEntry<std::string, V> result = tree->search(temp);
        return result.getValue();
    }

    V& operator[](const std::string& key) override {
        TableEntry<std::string, V> temp(key, V());

        try {
            TableEntry<std::string, V>& entry = tree->searchRef(temp);
            return entry.getValueRef();
        } catch (std::runtime_error&) {
            insert(key, V());
            TableEntry<std::string, V>& entry = tree->searchRef(temp);
            return entry.getValueRef();
        }
    }

    void remove(const std::string& key) override {
        TableEntry<std::string, V> temp(key, V());
        tree->remove(temp);
    }

    int entries() const {
        return tree->size();
    }

    friend std::ostream& operator<<(std::ostream& out, const BSTreeDict<V>& dict) {
        out << *(dict.tree);
        return out;
    }
};

#endif

