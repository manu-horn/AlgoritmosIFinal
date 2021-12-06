//
// Created by GryPho on 11/18/2021.
//

#include <vector>
using namespace std;
#ifndef SORTYSEARCH_SORTS_H
#define SORTYSEARCH_SORTS_H

#endif //SORTYSEARCH_SORTS_H

// selection insertion bubble counting cocktail

void cocktailSort(vector<int>& v);
void cocktailShakerSort(vector<int>& v);
int posMinimoEnRango(vector<int> v, int low, int high);
int posMaximoEnRango(vector<int> v, int low, int high);

vector<int> countingSort(vector<int> s);
vector<int> contarApariciones (vector<int> s); // para counting sort

void selectionSort(vector<int>& s);
int findMinPos(vector<int> s, int low, int high);

void insertionSort(vector<int>& s);
void insert(vector<int>& s, int i);

void bubbleSort(vector<int>& s);
void burbujeo(vector<int>& s, int i);