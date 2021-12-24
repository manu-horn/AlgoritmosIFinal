//
// Created by GryPho on 12/10/2021.
//

#include "otrosAlgoritmos.h"

/* Apareo (Merge) de secuencias ya ordenadas
 Problema: dadas dos secuencias ya ordenadas, unir ambas en una única secuencia ordenada

 Complejidad: si n = |a| + |b|, O(n)
 */

vector<int> merge(vector<int>& a, vector<int>& b){
    vector<int> c(a.size() + b.size(), 0);
    int i = 0, j = 0;

    for (int k = 0; k < c.size(); ++k) {
        if (j < b.size() && (i >= a.size() || a[i] >= b[j])){
            c[k] = b[j];
            j++;
        } else {
            c[k] = a[i];
            i++;
        }
    }

    return c;
}

/* The Welfare Crook
 Problema: Dadas tres secuencias ordenadas, sabemos que hay al menos un elemento que se repite entre ellas (en común)
 Encontrar los índices donde está al menos uno de estos eltos repetidos

 Complejidad: sean n = |a|, m = |b|, l = |c|; O (n + m + l)
 */

void crook(vector<int>& a, vector<int>& b, vector<int>& c, int& i, int& j, int& k){
    i = 0, j = 0, k = 0;

    while((a[i] != b[j]) || (b[j] != c[k])){
        if (a[i] < b[j]){
            i++;
        } else if (b[j] < c[k]){
            j++;
        } else {
            k++;
        }
    }
}

/* String Matching y Contiene (enfoque naïve y enfoque Knuth-Morris-Pratt (KMP))
 Problema: búsqueda de un patrón en un texto. Dado un string t(texto) y un string p(patrón),
 queremos saber si p se encuentra dentro de t

 Complejidades:
 * contiene(naïve): O(|p| * |t|)
 * matches: O(|p|)
 * contiene(KMP): O(|p| + |t|)
 * calcular_pi(auxiliar): O(n) = O(|p|)
 */

bool matches(string& t, int i, string& p){ // auxiliar para 'contiene'
    int k = 0;
    while (k < p.size() && t[i+k] == p[k]){
        k++;
    } // el parámetro i es usado para el ciclo de 'contiene'

    return k == p.size();
}

bool contiene (string& t, string& p){
    int i = 0;
    while (i <= t.size() - p.size() && !matches(t, i, p)) {
        i++;
    }

    return i <= t.size() - p.size();
}

vector<int> calcular_pi(string& p){
    vector<int> pi(p.size());
    int i = 0;

    for (int j = 1; j < p.size(); ++j) {
        while(i > 0 && p[i] != p[j]){
            i = pi[i-1];

            if (p[i] == p[j]) i++;

            pi[j] = i;
        }
    }

    return pi;
}

bool contiene_KMP(string& t, string& p){
    int l = 0, r = 0;
    vector<int> pi = calcular_pi(p);

    while(r < t.size() && r - l < p.size()){
        if (t[r] == p[r-l]){
            r++;
        } else if (l == r){
            r++;
            l++;
        } else {
            l = r - pi[r-l];
        }
    }

    return r-l == p.size();
}

// Algoritmo del final: O(n²) n = |a|

vector<vector<int>> interseccion (vector<vector<int>> a, vector<vector<int>> b){
    int i = 0,j = 0; bool esSub = true;
 
    while(i < a.size()){
        while (j < a.size() && a[i][j] != b[i][j]) j++;
        i++;
    }
    i = 0;
    if (j == a.size()) return {};
    
    int col = 0;
    
    while (i < a.size()){
        while(col <= j){
            esSub &= (a[i][a.size()-1-col] == b[i][a.size()-1-j-col]); 
        }
    }
    
    vector<vector<int>> c = {};
    
    if (esSub){
        for(int fil = 0; fil < a.size(); fil++){
            vector<int> h(0);
            for(int col = 0; col < a.size()-j; col++){
                h.push_back(b[fil][col]);
            }
            c.push_back(h);
        }
    }
    
    return c;
    
}

int main()
{
    vector<vector<int>> a = {
        {1,2,4},
        {3,6,1},
        {1,4,7}
    };
    
    vector<vector<int>> b = {
        {2,4,6},
        {6,1,2},
        {4,7,1}
    };
    
    vector<vector<int>> d = interseccion(a, b);
    
    for(int i = 0; i < d.size(); i++){
        for(int j = 0; j < d[0].size(); j++){
            cout << d[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
