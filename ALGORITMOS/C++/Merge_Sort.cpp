#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <chrono>

using namespace std;
using namespace std::chrono;

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1);
    vector<int> R(n2);

    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    string ruta = "archivo.txt";
    ifstream archivo(ruta);
    string linea;
    vector<int> arreglo;

    if (archivo.is_open()) {
        getline(archivo, linea);
        stringstream ss(linea);
        int num;
        while (ss >> num) {
            arreglo.push_back(num);
        }
        archivo.close();
    }

    auto start = high_resolution_clock::now();

    mergeSort(arreglo, 0, arreglo.size() - 1);

    ofstream archivo_salida(ruta);
    if (archivo_salida.is_open()) {
        for (int num : arreglo) {
            archivo_salida << num << " ";
        }
        archivo_salida.close();
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Tiempo de ejecución: " << duration.count() << " ms" << endl;

    return 0;
}
