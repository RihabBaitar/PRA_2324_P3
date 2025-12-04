#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include "Dict.h"
#include "TableEntry.h"
#include "ListLinked.h"

template<typename K, typename V>
class HashTable : public Dict<K,V> {
private:
    ListLinked<TableEntry<K,V>>* table;
    int capacity;

    int hash(const K& key) const {
        return key % capacity;
    }

public:
    HashTable(int capacity = 10) : capacity(capacity) {
        table = new ListLinked<TableEntry<K,V>>[capacity];
    }

    ~HashTable() {
        delete[] table;
    }

    void insert(const K& key, const V& value) override {
        int index = hash(key);
        ListLinked<TableEntry<K,V>>& bucket = table[index];

        for (int i = 0; i < bucket.size(); i++) {
            if (bucket.get(i).getKey() == key) {
                TableEntry<K,V> e(key, value);
                bucket.remove(i);
                bucket.add(e);
                return;
            }
        }

        bucket.add(TableEntry<K,V>(key, value));
    }

    V search(const K& key) const override {
        int index = hash(key);
        const ListLinked<TableEntry<K,V>>& bucket = table[index];

        for (int i = 0; i < bucket.size(); i++) {
            TableEntry<K,V> e = bucket.get(i);
            if (e.getKey() == key) return e.getValue();
        }

        throw std::runtime_error("Key not found");
    }

    V& operator[](const K& key) override {
        int index = hash(key);
        ListLinked<TableEntry<K,V>>& bucket = table[index];

        for (int i = 0; i < bucket.size(); i++) {
            TableEntry<K,V>& e = *(new TableEntry<K,V>(bucket.get(i)));
            if (e.getKey() == key) {
                return const_cast<V&>(bucket.get(i).getValue()); 
            }
        }

        insert(key, V());
        return operator[](key);
    }

    void remove(const K& key) override {
        int index = hash(key);
        ListLinked<TableEntry<K,V>>& bucket = table[index];

        for (int i = 0; i < bucket.size(); i++) {
            if (bucket.get(i).getKey() == key) {
                bucket.remove(i);
                return;
            }
        }
    }

    template<typename KK, typename VV>
    friend std::ostream& operator<<(std::ostream& out, const HashTable<KK,VV>& ht);
};

template<typename K, typename V>
std::ostream& operator<<(std::ostream& out, const HashTable<K,V>& ht) {
    for (int i = 0; i < ht.capacity; i++) {
        out << i << ": ";

        const ListLinked<TableEntry<K,V>>& bucket = ht.table[i];
        for (int j = 0; j < bucket.size(); j++) {
            out << bucket.get(j);
            if (j < bucket.size() - 1) out << "; ";
        }

        out << std::endl;
    }
    return out;
}

#endif

