#ifndef LISTLINKED_H
#define LISTLINKED_H

#include "List.h"
#include "Node.h"
#include <stdexcept>

template <typename T>
class ListLinked : public List<T> {
private:
    Node<T>* head;
    int count;

public:
    ListLinked() : head(nullptr), count(0) {}
    ~ListLinked() {
        Node<T>* current = head;
        while (current) {
            Node<T>* next = current->next;
            delete current;
            current = next;
        }
    }

    void add(const T& item) override {
        Node<T>* newNode = new Node<T>(item);
        if (!head) head = newNode;
        else {
            Node<T>* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
        }
        count++;
    }

    T get(int pos) const override {
        if (pos < 0 || pos >= count) throw std::out_of_range("Index out of range");
        Node<T>* temp = head;
        for (int i = 0; i < pos; i++) temp = temp->next;
        return temp->data;
    }

    T remove(int pos) override {
        if (pos < 0 || pos >= count) throw std::out_of_range("Index out of range");
        Node<T>* temp = head;
        Node<T>* prev = nullptr;
        for (int i = 0; i < pos; i++) {
            prev = temp;
            temp = temp->next;
        }
        T value = temp->data;
        if (prev) prev->next = temp->next;
        else head = temp->next;
        delete temp;
        count--;
        return value;
    }

    int size() const override {
        return count;
    }
};

#endif
