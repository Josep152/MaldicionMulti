#include <iostream>
#include <vector>
#include <math.h>
#include <cstdlib>
#include <time.h>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <fstream>
using namespace std;

#define dim 50

int randomN() { return (rand() % 20); }

float roundoff(float value, unsigned char prec)
{
    float pow_10 = pow(10.0f, (float)prec);
    return round(value * pow_10) / pow_10;
}

float dist(vector<int> A, vector<int> B) {
    int rpta = 0;
    vector<int>::iterator ita = A.begin();
    vector<int>::iterator itb = B.begin();
    for (; ita != A.end(); ++ita, ++itb) {
        rpta += pow(*ita - *itb, 2);
    }
    return pow(rpta, 0.5);
}

void printVect(vector<int> A) {
    for (vector<int>::iterator it = A.begin(); it != A.end(); ++it) {
        cout << *it << ' ';
    }
    cout << endl;
}
void fill(vector<int>& A) {
    A.resize(dim, 0);
    generate(A.begin(), A.end(), randomN);
}
int main() {
    srand(time(NULL));

    map<float, int> counter;

    vector<vector<int>> total(50000);
    vector<vector<int>>::iterator it = total.begin();
    vector<vector<int>>::iterator ithere = total.begin();
    fill(*it);
    ++it;
    for (; it != total.end(); ++it) {
        fill(*it);
        //printVect(*it);
        counter [roundoff(dist(*ithere, *it), 1)]++;
        //cout << dist(*ithere, *it) << endl;
    }
    /*for (auto i : counter) {
        cout << i.first << " : " << i.second << "\n";
    }*/

    ofstream file;
    string nombre = "50Dim50kElem";
    string direccion = "D://Programacion//EDA//multidimensionalidad//";
    direccion.append(nombre);
    direccion.append(".csv");
    file.open(direccion, ios::out);

    for (auto i : counter) {
        file << i.first << "," << i.second << ",\n";
    }
    file.close();   //Se cierra el file
    return 0;
}
