//
// Created by Steve Ntare on 10/14/2021.
//

#ifndef INC_21F_PA02_STV_AND_MILES_DATA_H
#define INC_21F_PA02_STV_AND_MILES_DATA_H

#include <set>
#include <ctime>
#include <random>
#include <cmath>
#include <iostream>
#include <fstream>
#include <math.h>
//#include <bits/stdc++.h>
using namespace std;
//template <class T>

class Data {
public:




    void swapms(int *a, int *b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    void printArray(vector<int> in, int n) {
        for (int i = 0; i < in.size(); i++)
            cout << in.at(i) << " ";
        cout << "\n";
    }


    void randomize(vector<int>& in, int n) {

        srand(time(NULL));


        for (int i = n - 1; i > 0; i--) {
            int j = rand() % (i + 1);
            swapms(&in.at(i), &in.at(j));
//            cout << i << " " << j << endl;
        }

    }

    void createData(int size){
        srand(time(nullptr));

        // ascending
        while (data.size() != size + 1) {
            data.insert(rand() % a);
        }
        // copying to sets vector
        std::copy(data.begin(), data.end(), back_inserter(sets[0]));

        // change to descending
        auto it = data.end();

        for (--it; it != data.begin(); --it){
            // copying to sets vector
            sets[1].push_back(*it);
        }

        // change to random
        std::copy(data.begin(), data.end(), back_inserter(randomizeSet));
        randomize(randomizeSet, randomizeSet.size());
        for (int i = 0; i<randomizeSet.size(); i++){
          sets[2].push_back(randomizeSet[i]);
    }
        //20% duplicates
//        int noDuplicatesSize = (int) 0.80 * data.size();
//        int duplicatesSize = data.size() - noDuplicatesSize;
        vector<int> copyData;
         it = data.end();

        for (--it; it != data.begin(); --it){
            // copying to sets vector
            copyData.push_back(*it);
        }
        int noDuplicatesSize = (int) (0.80 * copyData.size());
        int duplicatesSize = copyData.size() - noDuplicatesSize;

        for(int i = 0; i < noDuplicatesSize; i++){
            twentyDuplicates.push_back(copyData[i]);
        }

        for(int i = 0; i < duplicatesSize; i++){

            twentyDuplicates.push_back(copyData[i]);
        }
        randomize(twentyDuplicates, twentyDuplicates.size());
        for(int i = 0; i<twentyDuplicates.size(); i++){
            sets[3].push_back(twentyDuplicates[i]);
        }


        //40% duplicates
        int noDuplicatesSize2 = (int) (0.60 * copyData.size());
        int duplicatesSize2 = copyData.size() - noDuplicatesSize2;


        for(int i = 0; i < noDuplicatesSize2; i++){
            fortyDuplicates.push_back(copyData[i]);
        }

        for(int i = 0; i < duplicatesSize2; i++){
            fortyDuplicates.push_back(copyData[i]);
        }
        for(int i = 0; i<fortyDuplicates.size(); i++){
            sets[4].push_back(fortyDuplicates[i]);
        }

        randomize(fortyDuplicates, fortyDuplicates.size());


//        for (int i = 0; i < sets[4].size(); i++){
//            cout << sets[4].at(i) << endl;
//        }








}
    DSVector<int> getAscending(){
        DSVector<int> temp;
        for(int i = 0; i < sets[0].size(); i++){
            temp.push_back(sets[0].at(i));
        }
        return temp;
    }
    DSVector<int> getDescending(){
        DSVector<int> temp;
        for(int i = 0; i < sets[1].size(); i++){
            temp.push_back(sets[1].at(i));
        }
        return temp;
    }
    DSVector<int> getRandom(){
        DSVector<int> temp;
        for(int i = 0; i < sets[2].size(); i++){
            temp.push_back(sets[2].at(i));
        }
        return temp;
    }
    DSVector<int> get20(){
        DSVector<int> temp;
        for(int i = 0; i < sets[3].size(); i++){
            temp.push_back(sets[3].at(i));
        }
        return temp;
    }
    DSVector<int> get40(){
        DSVector<int> temp;
        for(int i = 0; i < sets[4].size(); i++){
            temp.push_back(sets[4].at(i));
        }
        return temp;
    }
private:
    set<int> data;
    vector<int> randomizeSet;
    vector<int> twentyDuplicates;
    vector<int> fortyDuplicates;
    vector<int> sets [5];
    int a = (int)(pow(10, 32));
    };



#endif //INC_21F_PA02_STV_AND_MILES_DATA_H
