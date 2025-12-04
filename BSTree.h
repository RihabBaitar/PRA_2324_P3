#ifndef BSTREE_H
#define BSTREE_H

#include <ostream>
#include <stdexcept>
#include "BSNode.h"

template <typename T>
class BSTree {
private:
    BSNode<T>* root;
    int nelem;

    BSNode<T>* insert(BSNode<T>* n, T e) {
        if (!n) {
            nelem++;
            return new BSNode<T>(e);
        }
        if (e == n->elem)
            throw std::runtime_error("Duplicated element");
        if (e < n->elem)
            n->left = insert(n->left, e);
        else
            n->right = insert(n->right, e);
        return n;
    }

    BSNode<T>* searchNode(BSNode<T>* n, const T& e) const {
        if (!n)
            throw std::runtime_error("Element not found");
        if (e < n->elem)
            return searchNode(n->left, e);
        else if (e > n->elem)
            return searchNode(n->right, e);
        else
            return n;
    }

    void print_inorder(std::ostream &out, BSNode<T>* n) const {
        if (!n) return;
        print_inorder(out, n->left);
        out << n->elem << " ";
        print_inorder(out, n->right);
    }

    BSNode<T>* remove(BSNode<T>* n, T e) {
        if (!n)
            throw std::runtime_error("Element not found");
        if (e < n->elem)
            n->left = remove(n->left, e);
        else if (e > n->elem)
            n->right = remove(n->right, e);
        else {
            if (n->left && n->right) {
                n->elem = max(n->left);
                n->left = remove_max(n->left);
            } else {
                BSNode<T>* temp = n;
                n = (n->left) ? n->left : n->right;
                delete temp;
                nelem--;
            }
        }
        return n;
    }

    T max(BSNode<T>* n) const {
        if (!n) throw std::runtime_error("Tree is empty");
        while (n->right) n = n->right;
        return n->elem;
    }

    BSNode<T>* remove_max(BSNode<T>* n) {
        if (!n->right) return n->left;
        n->right = remove_max(n->right);
        return n;
    }

    void delete_cascade(BSNode<T>* n) {
        if (!n) return;
        delete_cascade(n->left);
        delete_cascade(n->right);
        delete n;
    }

public:
    BSTree() : root(nullptr), nelem(0) {}
    ~BSTree() { delete_cascade(root); }

    void insert(T e) { root = insert(root, e); }
    T search(T e) const { return searchNode(root, e)->elem; }
    void remove(T e) { root = remove(root, e); }

    T& searchRef(const T& e) { return searchNode(root, e)->elem; }
    const T& searchRef(const T& e) const { return searchNode(root, e)->elem; }

    int size() const { return nelem; }

    T operator[](T e) const { return search(e); }

    friend std::ostream& operator<<(std::ostream &out, const BSTree<T>& bst) {
        bst.print_inorder(out, bst.root);
        return out;
    }
};

#endif
      
