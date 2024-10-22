#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <chrono>

using namespace std;
using namespace std::chrono;

void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
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

    heapSort(arreglo);

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
