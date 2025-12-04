#ifndef DICT_H
#define DICT_H

template <typename K, typename V>
class Dict {
public:
    virtual ~Dict() {}

    virtual void insert(const K& key, const V& value) = 0;
    virtual V search(const K& key) const = 0;
    virtual V& operator[](const K& key) = 0;
    virtual void remove(const K& key) = 0;
};

#endif

