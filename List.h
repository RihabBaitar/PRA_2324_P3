#ifndef LIST_H
#define LIST_H

template <typename T>
class List {
public:
    virtual ~List() {}
    virtual void add(const T& item) = 0;
    virtual T get(int pos) const = 0;
    virtual T remove(int pos) = 0;
    virtual int size() const = 0;
};

#endif
