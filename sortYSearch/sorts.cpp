//
// Created by GryPho on 11/18/2021.
//

#include "sorts.h"

// cocktail & cocktailShaker

void cocktailSort(vector<int>& v){
    for (int i = 0; i < v.size()/2; ++i) {
        swap(v[i], v[posMinimoEnRango(v,i,v.size()-1-i)]);
        swap(v[v.size()-1-i], v[posMaximoEnRango(v, i, v.size()-1-i)]);
    }
}

void cocktailShakerSort(vector<int>& v){
    bool ordenada = false;

    for (int i = 0; i < v.size() && !ordenada; ++i) {
        ordenada = true;

        for (int j = i; j < v.size()-1; ++j) {
            if (v[j] >v[j+1]){
                swap(v[j],v[j+1]);
                ordenada = false;
            }
        }

        for (int k = v.size()-1-i; k > 0 && !ordenada ; --k) {
            if (v[k-1]> v[k]){
                swap(v[k], v[k-1]);
                ordenada = false;
            }
        }
    }
}

int posMinimoEnRango(vector<int> v, int low, int high){
    int posMin = low;

    for (int i = low; i <= high; ++i) {
        if(v[i] <= v[posMin]) posMin = i;
    }

    return posMin;
}

int posMaximoEnRango(vector<int> v, int low, int high){
    int posMax = low;

    for (int i = low; i <= high; ++i) {
        if (v[i] >= v[posMax]) posMax = i;
    }

    return posMax;
}


// counting

vector<int> countingSort(vector<int> s){
    vector<int> conteo = contarApariciones(s);
    vector<int> ordenado;

    for (int i = 0; i < conteo.size() ; ++i) {
        for (int j = 0; j < conteo[i]; ++j) {
            ordenado.push_back(i);
        }
    }

    return ordenado;
}

vector<int> contarApariciones (vector<int> s){ // para counting sort
    vector<int> c (s.size()); //acoto: a lo sumo hay s.size() elementos distintos

    for (int i = 0; i < s.size(); ++i) {
        c[s[i]]++;
    }

    return c;
}

// selection

void selectionSort(vector<int>& s){ // posMinimoEnRango está arriba
    for (int i = 0; i < s.size()-1; ++i) {
        int minPos = posMinimoEnRango(s, i, s.size()-1);
        swap(s[i], s[minPos]);
    }
}

// insertion

void insertionSort(vector<int>& s){
    for (int i = 0; i < s.size(); ++i) {
       insert(s, i);
    }
}
void insert(vector<int>& s, int i){
    for (int j = i; j > 0 && s[j] < s[j-1]; --j) {
        swap(s[j], s[j-1]);
    }
}

// bubble

void bubbleSort(vector<int>& s){
    for (int i = 0; i < s.size(); ++i) {
        burbujeo(s,i);
    }
}
void burbujeo(vector<int>& s, int i){
    for (int j = s.size()-1; j > i ; --j) {
        if (s[j] < s[j-1]) swap(s[j], s[j-1]);
    }
}