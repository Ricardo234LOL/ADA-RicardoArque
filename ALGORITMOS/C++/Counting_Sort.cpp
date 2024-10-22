#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <chrono>
#include <algorithm>

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

    int max = *max_element(arreglo.begin(), arreglo.end());
    vector<int> count(max + 1, 0);
    vector<int> output(arreglo.size());

    for (int i = 0; i < arreglo.size(); i++) {
        count[arreglo[i]]++;
    }

    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    for (int i = arreglo.size() - 1; i >= 0; i--) {
        output[count[arreglo[i]] - 1] = arreglo[i];
        count[arreglo[i]]--;
    }

    ofstream archivo_salida(ruta);
    if (archivo_salida.is_open()) {
        for (int num : output) {
            archivo_salida << num << " ";
        }
        archivo_salida.close();
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Tiempo de ejecución: " << duration.count() << " ms" << endl;

    return 0;
}
