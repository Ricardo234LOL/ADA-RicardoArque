#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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

    quickSort(arreglo, 0, arreglo.size() - 1);

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
