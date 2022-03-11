//
// Created by Miles Friedman on 10/12/21.
//

#ifndef INC_21F_PA02_STV_AND_MILES_ITR_H
#define INC_21F_PA02_STV_AND_MILES_ITR_H
#include "list.h"
#include "AVLTree.h"
#include "DSVector.h"
template<typename T>
class  itr {
public:

virtual bool operator==(const itr<T>& right) = 0;
virtual bool operator!=(const itr<T>&  right) = 0;
virtual T& operator*() const = 0;
virtual itr<T>& operator++() = 0;

};

//template<typename K, typename T>
//class DictItr: public itr<K,T>{
//protected:
//    MSNode<K,T>* current;
//    stack<MSNode<K, T>> theStack;
//public:
//    DictItr(){
//    current = nullptr;
//    }
//    DictItr(MSNode<K, T>* curr){
//        current = curr;
//        while(curr != nullptr){
//            theStack.push(*curr);
//            curr = curr->left;
//        }
//        *current = theStack.top();
//        theStack.pop();
//    }
//T operator*(){
//    assert (current != nullptr);
//    return (*current).data;
//}
//DictItr operator++(){
//    *current = theStack.top();
//    MSNode<K,T>* loc = current;
//    if (!theStack.empty()) {
//
//        theStack.pop();
//        if (loc->right != nullptr) {
//            loc = loc->right;
//            while (loc != nullptr) {
//                theStack.push(*loc);
//                loc = loc->left;
//            }
//        }
//    }else{
//        current = nullptr;
//    }
//    return *this;
//    }
//bool operator==( const DictItr& right){
//    return (*current == (right.current));
//    }
//bool operator!=( const DictItr& right){
//    return (*current != (right.current));
//    }
//};
//
//template<typename K, typename T>
//class ListItr: public itr<K,T>{
//protected:
//    node<T>* current;
//public:
//    ListItr(){
//        current = nullptr;
//    }
//    ListItr(node<T>* node){
//        current = node;
//    }
//    T& operator*(){
//        assert(current != nullptr);
//        return current->data;
//    }
//    ListItr& operator++(){
//        assert(current != nullptr);
//        current = current->next;
//        return *this;
//    }
//    ListItr& operator--(){
//        assert (current != nullptr);
//        current = current->prev;
//        return *this;
//    }
//    bool operator==(const ListItr& right){
//        if(right.current == nullptr){
//            if (current == nullptr){
//                return true;
//            }else{
//                return false;
//            }
//        }
//        if (current == nullptr) return false;
//        return (current->data == right.current->data);
//    }
//    bool operator!=(const ListItr& right){
//        if(right.current == nullptr){
//            if (current == nullptr){
//                return false;
//            }else{
//                return true;
//            }
//        }
//        if (current == nullptr) return true;
//        return (current->data != right.current->data);
//    }
//};
//class VecItr: public itr<K,T>{
//protected:
//    T* current;
//    const DSVector<T>* itr_vec;
//    int itr_index;
//public:
//    VecItr(){
//        current = nullptr;
//    }
//    VecItr(DSVector<int> *vec, int index){
//        itr_index = index;
//        itr_vec = vec;
//    }
//    const T& operator*() const{
//        return itr_vec->operator[](itr_index);
//    }
//    Itr& operator=(const VecItr right){
//        current = right.current;
//        itr_vec = right.itr_vec;
//        itr_index = right.itr_index;
//    }
//    VecItr& operator++(){
//        itr_index++;
//        return *this;
//    }
//    VecItr& operator--(){
//        itr_index--;
//        return *this;
//    }
//    bool operator==(const VecItr& right){
//        return (**this == *right);
//    }
//    bool operator!= (const VecItr& right) {
//        return (**this != *right);
//    }
//};
//



#endif //INC_21F_PA02_STV_AND_MILES_ITR_H
