//
// Created by GryPho on 11/18/2021.
//

#include "search.h"
#include <cmath>

// puedo devolver el índice o un bool que me diga si está o no

bool linearSearch(int x, vector<int> s){
    
    int i = 0;
    while(i < s.size() && s[i] != x){
        i++;
    }

    return (i < s.size());
}

int binarySearch(int x, vector<int> v){
    int low = 0, high = v.size()-1;

    while (low < high){
        int mid = (low + high)/2;

        if (v[mid] >= x) high = mid;
        else low = mid + 1;
    }

    if (v[low] == x) return low;
    else return -1;
}

int binarySearchRange (vector<int> v, int x, int from, int to){ // from y to son inclusives

    while (from < to){
        int mid = (from + to)/2;

        if (v[mid] < x) from = mid +1;
        else to = mid;
    }

    if (v[from] == x) return from;
    else return -1;
}

int jumpSearch(int x, vector<int> v){
    int i = 0, salto = sqrt(v.size()), m = 0;

    while (i < v.size() && v[i] < x){
        i += salto;
    }

    if (v[0] == x) return 0;
    else if (i == 0) return -1;
    else if (i < v.size()) m = i+1;
    else m = v.size();

    for (int j = i+1 - salto; j < m; ++j) {
        if (v[j] == x) return j;
    }

    return -1;
}
