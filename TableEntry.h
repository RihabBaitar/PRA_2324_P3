#ifndef TABLEENTRY_H
#define TABLEENTRY_H

#include <iostream>

template <typename K, typename V>
class TableEntry {
private:
    K key;
    V value;

public:
    TableEntry() : key(), value() {}
    TableEntry(const K& k, const V& v) : key(k), value(v) {}

    const K& getKey() const { return key; }
    const V& getValue() const { return value; }
    V& getValueRef() { return value; }  
    void setValue(const V& v) { value = v; }

    bool operator==(const TableEntry<K,V>& other) const {
        return key == other.key;
    }

    bool operator<(const TableEntry<K,V>& other) const { return key < other.key; }
    bool operator>(const TableEntry<K,V>& other) const { return key > other.key; }

    friend std::ostream& operator<<(std::ostream& out, const TableEntry<K,V>& e) {
        out << "('" << e.key << "' => " << e.value << ")";
        return out;
    }
};

#endif

