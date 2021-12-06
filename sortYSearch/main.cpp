#include <iostream>
#include "sorts.h"
#include "search.h"
using namespace std;

int main() {
    vector<int> v = {0,1,2,3,5,6,7,8};

    int indice = binarySearchRange(v,3,2,4);

    cout << indice;
    return 0;
}
