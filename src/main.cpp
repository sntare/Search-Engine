#include <iostream>
#include "DSVector.h"
#include "Data.h"
#include "list.h"
#include <chrono>
#include "AVLTree.h"
template<typename T>
void quickSort(typename DSVector<T>::randiterator, typename DSVector<T>::randiterator);
template<typename T>
void insertionSort(typename DSVector<T>::randiterator, typename DSVector<T>::randiterator);
template<typename T>
typename DSVector<T>::randiterator partition(typename DSVector<T>::randiterator low, typename DSVector<T>::randiterator high);
template<typename T>
void heapSort(typename DSVector<T>::randiterator, int );
template<typename T>
void swapy(typename DSVector<T>::randiterator a, typename DSVector<T>::randiterator b);



int main(){
    ofstream output;
    output.open("output.csv");
    //vector<int> sizes {1000};

    vector<int> sizes {1000, 10000, 25000, 50000, 75000, 100000};

for(int i = 0; i < sizes.size(); i++){
    Data date;
    date.createData(sizes[i]);
    //Ascending Sort

    DSVector<int>::randiterator begin = date.getAscending().beginR();
    DSVector<int>::randiterator end = date.getAscending().endR();
    auto start = std::chrono::high_resolution_clock::now();
    insertionSort<int>(begin, end);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = duration_cast<std::chrono::microseconds>(stop - start);
    auto time = duration.count();
    cout << "Ascending Sorted " << sizes[i] << " In " << time << " Microseconds" << endl;
    output << "ascending," << sizes[i] << "," << time << endl;
    for(begin; begin != end; ++begin){
        if (*begin < *(begin - 1))
            cout << "Failure" << endl;
    }
    //Descending Sort
     begin = date.getDescending().beginR();
     end = date.getDescending().endR();
     start = std::chrono::high_resolution_clock::now();
    insertionSort<int>(begin, end);
     stop = std::chrono::high_resolution_clock::now();
     duration = duration_cast<std::chrono::microseconds>(stop - start);
     time = duration.count();
    cout << "Descending Sorted " << sizes[i] << " In " << time << " Microseconds" << endl;
    output << "descending," << sizes[i] << "," << time << endl;
    for(begin; begin != end; ++begin){
        if (*begin < *(begin - 1))
            cout << "Failure" << endl;
    }
    //Random Sort
    begin = date.getRandom().beginR();
    end = date.getRandom().endR();
    start = std::chrono::high_resolution_clock::now();
    insertionSort<int>(begin, end);
    stop = std::chrono::high_resolution_clock::now();
    duration = duration_cast<std::chrono::microseconds>(stop - start);
    time = duration.count();
    cout << "Random Sorted " << sizes[i] << " In " << time << " Microseconds" << endl;
    output << "random," << sizes[i] << "," << time << endl;
    for(begin; begin != end; ++begin){
        if (*begin < *(begin - 1))
            cout << "Failure" << endl;
    }
    //20% Sort
    begin = date.get20().beginR();
    end = date.get20().endR();
    start = std::chrono::high_resolution_clock::now();
    insertionSort<int>(begin, end);
    stop = std::chrono::high_resolution_clock::now();
    duration = duration_cast<std::chrono::microseconds>(stop - start);
    time = duration.count();
    cout << "20% Sorted " << sizes[i] << " In " << time << " Microseconds" << endl;
    output << "20%," << sizes[i] << "," << time << endl;
    for(begin; begin != end; ++begin){
        if (*begin < *(begin - 1))
            cout << "Failure" << endl;
    }
    //40% Sort
    begin = date.get40().beginR();
    end = date.get40().endR();
    start = std::chrono::high_resolution_clock::now();
    insertionSort<int>(begin, end);
    stop = std::chrono::high_resolution_clock::now();
    duration = duration_cast<std::chrono::microseconds>(stop - start);
    time = duration.count();
    cout << "40% Sorted " << sizes[i] << " In " << time << " Microseconds" << endl;
    output << "40%," << sizes[i] << "," << time << endl;
    for(begin; begin != end; ++begin){
        if (*begin < *(begin - 1))
            cout << "Failure" << endl;
    }
}
output.close();


}
template <typename T>
void insertionSort(typename DSVector<T>::randiterator begin, typename DSVector<T>::randiterator end){

    T key;
    typename DSVector<T>::randiterator i = begin;
    typename DSVector<T>::randiterator j;
    for(i + 1; i != end; ++i){
        key = *i;
        j = (i - 1);
        while(j >= begin && *j > key){
            *(j+1) = *j;
            --j;
        }
        *(j+1) = key;
  }

}
template <typename T>

void swapy(typename DSVector<T>::randiterator a, typename DSVector<T>::randiterator b){
    T temp = *a;
    *a = *b;
    *b = temp;
}
template <typename T>
typename DSVector<T>::randiterator partition(typename DSVector<T>::randiterator low, typename DSVector<T>::randiterator high){
    T pivot = *high;
    typename DSVector<T>::randiterator i = (low - 1);
    for(typename DSVector<T>::randiterator j = low; j <= (high - 1); ++j){
        if(*j <= pivot){
            ++i;
            cout << "swapping " << *i << "and" << *j << endl;
            swapy<T>(i, j);
        }
    }
    swapy<T>((++i), high);
    return (++i);
}
template <typename T>
void quickSort(typename DSVector<T>::randiterator low, typename DSVector<T>::randiterator high){
    if (low < high) {
        typename DSVector<T>::randiterator pi = partition<T>(low, high);
        quickSort<T>(low, pi - 1);
        quickSort<T>(pi + 1, high);
    }
}
template <typename T>
void buildMaxHeap(typename DSVector<T>::randiterator it, int n){
    for(typename DSVector<T>::randiterator i(it.getVec(), 1); i.getIndex() < n; ++i){
        int num = (i.getIndex() - 1) / 2;
        typename DSVector<T>::randiterator compare(it.getVec(), num);
        if(*i > *compare){
            typename DSVector<T>::randiterator j = i;
            int num2 = (j.getIndex() - 1) / 2;
            typename DSVector<T>::randiterator compare2(it.getVec(), num2);
            while(*j > *compare2){
                cout << "swapping " << *j << " and " << *compare2 << endl;
                swapy<T>(j, compare2);
                j.setIndex(num2);
            }
        }
    }

}
template <typename T>
void heapSort(typename DSVector<T>::randiterator it, int n){
    buildMaxHeap<T>(it, n);

    for(typename DSVector<T>::randiterator i(it.getVec(), n - 1); i.getIndex() > 0; --i){

        swapy<T>(it, i);


        typename DSVector<T>::randiterator j = i;
        typename DSVector<T>::randiterator index = it;
        do{
            int set = (2 * j.getIndex() + 1);
            index.setIndex(set);



            if(*index < *(index + 1)
            && index.getIndex() < (i.getIndex() - 1)){

                        ++index;
            }
            if(*j < *index
            && index.getIndex() < i.getIndex()){
                swapy<T>(j, index);
            }
            j = index;

        } while (index.getIndex() < i.getIndex());
    }

}