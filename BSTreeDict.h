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

    // Insertar o actualizar valor
    void insert(const std::string& key, const V& value) override {
        TableEntry<std::string, V> entry(key, value);
        tree->insert(entry);
    }

    // Buscar valor por clave
    V search(const std::string& key) const override {
        TableEntry<std::string, V> temp(key, V());
        TableEntry<std::string, V> result = tree->search(temp);
        return result.getValue();
    }

    // Devuelve referencia para cumplir Dict<K,V>
    V& operator[](const std::string& key) override {
        TableEntry<std::string, V> temp(key, V());

        // Intentamos buscar; si no existe, lo insertamos
        try {
            TableEntry<std::string, V>& entry = tree->searchRef(temp);
            return entry.getValueRef();
        } catch (std::runtime_error&) {
            insert(key, V());
            TableEntry<std::string, V>& entry = tree->searchRef(temp);
            return entry.getValueRef();
        }
    }

    // Eliminar clave
    void remove(const std::string& key) override {
        TableEntry<std::string, V> temp(key, V());
        tree->remove(temp);
    }

    // Número de entradas
    int entries() const {
        return tree->size();
    }

    // Para imprimir
    friend std::ostream& operator<<(std::ostream& out, const BSTreeDict<V>& dict) {
        out << *(dict.tree);
        return out;
    }
};

#endif

