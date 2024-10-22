#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <chrono>

using namespace std;
using namespace std::chrono;

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

    int n = arreglo.size();
    for (int i = 0; n - i - 1 > i; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arreglo[j] > arreglo[j + 1]) {
                swap(arreglo[j], arreglo[j + 1]);
            }
        }
    }

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

