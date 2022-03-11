//
// Created by Steve Ntare on 6/11/2021.
//

#ifndef INC_21SU_PA02_TEMPLATE_DSVECTOR_H
#define INC_21SU_PA02_TEMPLATE_DSVECTOR_H
#include <iostream>
#include <iterator>

using std::cout;
using std::endl;

template <class T>

class DSVector {
private:
    T* ranVec;
    int nextUp;
    int capacity;
    int size;
public:



    class Itr : public std::iterator<std::forward_iterator_tag, T>{
    protected:
        T* current;
        const DSVector<T>* itr_vec;
        int itr_index;
    public:
        Itr(){
            current = nullptr;
        }
        Itr(const DSVector<int> *vec, int index){
            itr_index = index;
            itr_vec = vec;
        }
         T& operator*() const{
            return itr_vec->operator[](itr_index);
        }
        Itr& operator=(const Itr &right){
            current = right.current;
            itr_vec = right.itr_vec;
            itr_index = right.itr_index;

            return *this;
        }
         Itr& operator++(){
            itr_index++;
            return *this;
        }


         bool operator==(const Itr& right){
            if (right.itr_index > right.itr_vec->size) {
                if (itr_index > itr_vec->size) {
                    return true;
                } else {
                    return false;
                }
            }
            return (**this == *right);
        }
         bool operator!=(const Itr& right) {
            if (right.itr_index > right.itr_vec->size) {
                if (itr_index > itr_vec->size) {
                    return false;
                } else {
                    return true;
                }
            }
            return !(**this == *right);
        }


    };


    using iterator = Itr;
class RItr : public std::iterator<std::random_access_iterator_tag, T>{
    protected:
        T* current;
        const DSVector<T>* itr_vec;
        int itr_index;
    public:
        RItr(){
            current = nullptr;
        }
        const DSVector<T>* getVec(){
            return itr_vec;
        }
        void setIndex(int idx){
            itr_index = idx;
        }
        int getIndex(){
            return itr_index;
        }
        RItr(const DSVector<int> *vec, int index){
            itr_index = index;
            itr_vec = vec;
        }
        RItr operator+(int num){
            return RItr(itr_vec, itr_index + num);
        }

        RItr operator+=(int num){
        itr_index += num;
        return *this;
        }
        RItr operator-(int num){
            return RItr(itr_vec, itr_index - num);
        }

    RItr operator-=(int num){
        itr_index -= num;
        return *this;
        }
        T& operator[](int index){
        return itr_vec->operator[](itr_index + index);

        }
        T& operator*() const{
            return itr_vec->operator[](itr_index);
        }
        RItr& operator=(const RItr &right){
            current = right.current;
            itr_vec = right.itr_vec;
            itr_index = right.itr_index;

            return *this;
        }
         RItr& operator++(){
            itr_index++;
            return *this;
        }
        RItr& operator--(){
            itr_index--;
            return *this;
        }
    bool operator>(const RItr& right) const{
            if (itr_index > right.itr_index){
                return true;
            }else{
                return false;

            }
        }
    bool operator>=(const RItr& right)const{
        if (itr_index >= right.itr_index){
            return true;
        }else{
            return false;

        }
    }
        bool operator<(const RItr& right)const{
            if (right.itr_index > itr_index){
                return true;
            }else{
                return false;

            }

    }
    bool operator<=(const RItr& right)const{
        if (right.itr_index >= itr_index){
            return true;
        }else{
            return false;

        }

    }

          bool operator==(const RItr& right)const{
            if (right.itr_index > right.itr_vec->size){
                if (itr_index > itr_vec->size){
                    return true;
                }
                else{
                    return false;
                }
            }
            return (**this == *right);
        }
          bool operator!=(const RItr& right)const{
             if (right.itr_index > right.itr_vec->size){
                 if (itr_index > itr_vec->size){
                     return false;
                 }
                 else{
                     return true;
                 }
             }
             return !(**this == *right);
        }
    };


    using randiterator = RItr;



    DSVector(int initial_capacity = 10);
    DSVector(const DSVector<T>&);
    ~DSVector();

    int getNextUp() const;
    int getSize() const;
    void setNextUp(int);
    void setSize(int);

    DSVector& operator= (const DSVector&);
    T& operator[](const int);
    T& operator[](const int) const;
    void insert(const int, const T&);
    void pop_back();
    void grow(int);
    iterator  begin(){
        DSVector<T>::Itr it(this, 0);
        return it;
    }
    iterator  end() {
        DSVector<T>::Itr it(this, size);
        return it;
    }
    randiterator  beginR(){
        DSVector<T>::RItr it(this, 0);
        return it;
    }
    randiterator  endR() {
        DSVector<T>::RItr it(this, size);
        return it;
    }
    int find(T);
    bool isFound(T);
    //sorts a vector alphabetically
//    void sort();
    //adds values to vector
    void push_back(const T&);
    void push_front(const T&);
    void clear();
    int partition(const DSVector<T>&, int, int );
    void swap(T*, T*);
    void quickSort(const DSVector<T>&, int, int);



};

template<class T>
DSVector<T>::DSVector(int initial_capacity) {
    ranVec = new T[initial_capacity];
    nextUp = 0;
    capacity = initial_capacity;
    size = 0;

}

template<class T>
DSVector<T>::DSVector(const DSVector<T>& vec) {
    ranVec = new T[vec.getSize()];
    nextUp = vec.getNextUp();
    size = vec.getSize();
    capacity = vec.capacity;

    for(int i = 0; i < vec.getSize(); i++){
        ranVec[i] = vec.ranVec[i];
    }
}
template<class T>
DSVector<T>::~DSVector() {
    delete [] ranVec;
}

template<class T>
int DSVector<T>::getNextUp() const {
    return nextUp;
}

template<class T>
int DSVector<T>::getSize() const {
    return size;
}

template<class T>
void DSVector<T>::setNextUp(int v) {
    nextUp = v;
}

template<class T>
void DSVector<T>::setSize(int v) {
    size = v;
}

template<class T>
DSVector<T>& DSVector<T>::operator=(const DSVector<T>& vec) {
    if (this == &vec)
        return *this;

    delete[] ranVec;
    size = vec.getSize();
    nextUp = vec.getNextUp();
    capacity = vec.capacity;
    ranVec = new T [capacity];


    for (int i = 0; i < vec.getSize(); i++)
        ranVec[i] = vec[i];

    return *this;

}

template<class T>
T& DSVector<T>::operator[](const int led) {
    return ranVec[led];
}

template<class T>
T &DSVector<T>::operator[](const int led) const {
    return ranVec[led];
}

template<class T>
void DSVector<T>::insert(const int location, const T& thing) {
    if (capacity == location){
        push_back(thing);
    }else{
        if(size == capacity){
            grow(size*=2);
        }
        for (int i = size; i >= location + 1; i--) {
            ranVec[i] = ranVec[i - 1];
        }
        ranVec[location] = thing;
        size++;
    }
}

template<class T>
void DSVector<T>::pop_back() {
    if(size == 0){
        cout << "Nothing in array!" << endl;

    }
    size--;
}

template<class T>
void DSVector<T>::grow(int newCapacity) {
    T* temp = new T[newCapacity];

    for (int i = 0; i<size; i++)
        temp[i] = ranVec[i];

    delete [] ranVec;
    ranVec = temp;
    capacity = newCapacity;
    ranVec = temp;
}

template<class T>
int DSVector<T>::find(T thing) {
    for (int i = 0; i<capacity; i++){
        if (thing == ranVec[i]){
            return i;
        }
    }
    return -1;
}

template<class T>
bool DSVector<T>::isFound(T thing) {
    for (int i = 0; i<size; i++){
        if(ranVec[i] == thing){
            return true;
        }
    }
    return false;
}


template<class T>
void DSVector<T>::push_back(const T&  thing) {
    if(size == capacity){
        grow(capacity*2);
    }
    ranVec[size] = thing;
    size++;
}

template<class T>
void DSVector<T>::push_front(const T& thing) {
    if(size == capacity){
        grow(capacity+= 15);
    }
    for(int i = size; i > 0; i--){
        ranVec[i] = ranVec[i-1];
    }
    ranVec[0] = thing;
    size++;
}

template<class T>
void DSVector<T>::clear() {
    delete [] ranVec;
    size = 0;
    capacity = 10;
    ranVec = new T[10];
}
template <class T>
void DSVector<T>::swap(T* a, T* b) {
    T temp = *a;
    *a = *b;
    *b = temp;
}

template <class T>
int DSVector<T>::partition(const DSVector<T>& arr, int low, int high) {
    T pivot = arr[high];
    int i = (low - 1);
    for(int j = low; j <= high - 1; j++){
        if (arr[j] <= pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return (i+1);
}
template <class T>
void DSVector<T>::quickSort(const DSVector<T>& arr, int low, int high) {
    if(low<high){
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}






#endif //INC_21SU_PA02_TEMPLATE_DSVECTOR_H
