//
// Created by Steve Ntare on 6/21/2021.
//


#ifndef SU21_SRCH_ENG_MILES_AND_STEVE_AVLTREE_H
#define SU21_SRCH_ENG_MILES_AND_STEVE_AVLTREE_H

#include "DSVector.h"
#include <iomanip>
#include <iostream>
#include <functional>
#include <stack>
using namespace std;

//We used the AVL Tree implementation found at the following URL for inspiration:
// http://www.cs.sjsu.edu/~shaverdian/AVLTreesLecture.pdf


template<typename K, typename T>
struct MSNode {
    T data;
    K key;
    MSNode *left;
    MSNode *right;
    int height;
    bool operator==(const MSNode<K, T>* rhs){
        if (this == nullptr && rhs != nullptr){
            return false;
        }
        if (this != nullptr && rhs == nullptr){
            return false;
        }
        if (data == rhs->data && key == rhs->key){
            return true;
        }
        else{
            return false;
        }
    }
    bool operator!=(const MSNode<K, T>* rhs){
        if (this == nullptr && rhs != nullptr){
            return true;
        }
        else if (this != nullptr && rhs == nullptr){
            return true;
        }
        else if (this == nullptr && rhs == nullptr){
            return false;
        }
        if (data == rhs->data && key == rhs->key){
            return false;
        }
        else{
            return true;
        }
    }
    MSNode<K,T> operator=(MSNode<K, T>& rhs){
        data = rhs.data;
        key = rhs.key;
        left = rhs.left;
        right = rhs.right;
    }
    MSNode(){}
    MSNode(T x, K k, MSNode *lst, MSNode *rst, int h = 0) : data(x), key(k), left(lst), right(rst), height(h) {}
};
template<typename K, typename T>
class Dict {
private:
    MSNode<K, T> *root;
    int size= 0;


    void insert(T x, K k, MSNode<K, T> *&t) {


        if (t == nullptr) {
            t = new MSNode<K, T>(x, k, nullptr, nullptr);
        } else if (k < t->key) {
            insert(x, k, t->left);
            if (height(t->left) - height(t->right) == 2) {
                if (k < t->left->key) {
                    singleLeftRotate(t);
                } else {
                    doubleLeftRotate(t);
                }
            }
        } else if (k > t->key) {
            insert(x, k, t->right);
            if (height(t->right) - height(t->left) == 2) {
                if (k > t->right->key) {
                    singleRightRotate(t);
                } else {
                    doubleRightRotate(t);
                }
            }
        }
        t->height = max(height(t->left), height(t->right)) + 1;
    }


    void singleRightRotate(MSNode<K, T> *&k2) {
        MSNode<K, T> *k1 = k2->right;
        k2->right = k1->left;
        k1->left = k2;
        k2->height = max(height(k2->left), height(k2->right)) + 1;
        k2 = k1;
    };

    void singleLeftRotate(MSNode<K, T> *&k2) {
        MSNode<K, T> *k1 = k2->left;
        k2->left = k1->right;
        k1->right = k2;
        k2->height = max(height(k2->left), height(k2->right)) + 1;
        k2 = k1;
    };

    void doubleRightRotate(MSNode<K, T> *&k3) {
        singleLeftRotate(k3->right);
        singleRightRotate(k3);
    };

    void doubleLeftRotate(MSNode<K, T> *&k3) {
        singleRightRotate(k3->left);
        singleLeftRotate(k3);
    };

    static int height(MSNode<K, T> *t) {
        return t == nullptr ? -1 : t->height;
    }

    void printPrivate(MSNode<K, T> *input) {
        if (input == nullptr) {
            return;
        }
        if (input == root) {
            if (input->left == nullptr && input->right == nullptr) {
                cout << input->data << " root " << endl;
            } else if (input->left == nullptr) {
                cout << input->data << " root " << input->right->data << " right" << endl;
            } else if (input->right == nullptr) {
                cout << input->data << " root " << input->left->data << " left" << endl;
            } else {
                cout << input->data << " root " << input->left->data << " left " << input->right->data << " right" << endl;
            }
        } else if (input->left == nullptr && input->right == nullptr) {
            cout << input->data << " leaf " << endl;
        } else if (input->left == nullptr) {
            cout << input->data << " node " << input->right->data << " right" << endl;
        } else if (input->right == nullptr) {
            cout << input->data << " node " << input->left->data << " left" << endl;
        } else {
            cout << input->data << " node " << input->left->data << " left " << input->right->data << " right" << endl;
        }
        printPrivate(input->left);
        printPrivate(input->right);
    }




public:

    Dict() {
        root = nullptr;
    };
    ~Dict(){
        clear();
    }
    void add(T x, K k) {
        insert(x, k, root);
        size++;
    }

     void clear(MSNode<K, T> *input) {
        if (input == nullptr) {
            return;
        }
        clear(input->left);
        clear(input->right);
        delete input;

    }

    void clear() {
        clear(root);
        size = 0;
        root = nullptr;
    }

    void print() {
        printPrivate(root);
    }



    T& operator[](K idx){

        MSNode<K,T>* out = search(idx, root);
        if(out == nullptr){
            cout << "key not found"<< endl;
        }else {
            return out->data;
        }

    }
    MSNode<K,T>* search(K k, MSNode<K,T>*& tree){
        if(tree == nullptr){
            return nullptr;
        }
        else if (k == tree->key){
            return tree;
        }
        else if(k < tree->key){
            return search(k, tree->left);
        }
        else if(tree->key < k){
            return search(k, tree->right);

        }
    }


    int getSize(){return size;}
    class Itr : public std::iterator<std::forward_iterator_tag, MSNode<K,T>>{
    protected:
        MSNode<K,T>* current;
        stack<MSNode<K, T>> theStack;
    public:
        Itr(){
            current = nullptr;
        }
        Itr(MSNode<K, T>* curr){
            current = curr;
//            MSNode<K,T>* loc = curr;
//            while(loc != nullptr){
//
//                theStack.push(*loc);
//
//                loc = loc->left;
//            }
//            *current = theStack.top();
//            theStack.pop();

            while(curr != nullptr){

                theStack.push(*curr);

                curr = curr->left;
            }
            *current = theStack.top();
            theStack.pop();
        }
        T operator*(){
            assert (current != nullptr);
            return (*current).data;
        }
        Itr operator++(){
            if (!theStack.empty()) {
                *current = theStack.top();
                MSNode<K,T>* loc = current;


                    theStack.pop();
                    if (loc->right != nullptr) {
                        loc = loc->right;
                        while (loc != nullptr) {
                            theStack.push(*loc);
                            loc = loc->left;
                        }
                    }
                }else{
                    current = nullptr;
                }

            return *this;
        }
        bool operator==( const Itr& right){
            return (*current == (right.current));
        }
        bool operator!=( const Itr& right){
            return (*current != (right.current));
        }
    };

    Itr begin(){
        return Itr(root);
    }
    Itr end(){
        return Itr();
    }
};





#endif //SU21_SRCH_ENG_MILES_AND_STEVE_AVLTREE_H
