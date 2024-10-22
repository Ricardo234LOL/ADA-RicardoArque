#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono;

void bubbleSort(vector<int>& arr);
void selectionSort(vector<int>& arr);
void insertionSort(vector<int>& arr);
void mergeSort(vector<int>& arr, int left, int right);
void merge(vector<int>& arr, int left, int mid, int right);
void quickSort(vector<int>& arr, int low, int high);
int partition(vector<int>& arr, int low, int high);
void heapSort(vector<int>& arr);
void heapify(vector<int>& arr, int n, int i);
void countingSort(vector<int>& arr);
vector<int> leerArchivo(const string& path);

void ejecutarAlgoritmo(vector<int> arr, const string& nombre, void(*algoritmo)(vector<int>&)) {
    cout << "Ejecutando " << nombre << "..." << endl;
    auto inicio = high_resolution_clock::now();
    algoritmo(arr);
    auto fin = high_resolution_clock::now();
    auto duracion = duration_cast<milliseconds>(fin - inicio).count();
    cout << nombre << " completado en " << duracion << " ms" << endl;
}

int main() {
    vector<string> files = {
        "File_100.txt", "File_500.txt", "File_1000.txt", "File_2000.txt",
        "File_3000.txt", "File_4000.txt", "File_5000.txt", "File_6000.txt",
        "File_7000.txt", "File_8000.txt", "File_10000.txt", "File_20000.txt",
        "File_30000.txt", "File_40000.txt", "File_50000.txt", "File_60000.txt",
        "File_70000.txt", "File_80000.txt", "File_100000.txt"
    };

    for (const auto& file : files) {
        cout << "\n--- Resultados para " << file << " ---" << endl;
        vector<int> arregloOriginal = leerArchivo(file);

        ejecutarAlgoritmo(arregloOriginal, "Bubble Sort", bubbleSort);
        ejecutarAlgoritmo(arregloOriginal, "Selection Sort", selectionSort);
        ejecutarAlgoritmo(arregloOriginal, "Insertion Sort", insertionSort);
        ejecutarAlgoritmo(arregloOriginal, "Merge Sort", [](vector<int>& arr) { mergeSort(arr, 0, arr.size() - 1); });
        ejecutarAlgoritmo(arregloOriginal, "Quick Sort", [](vector<int>& arr) { quickSort(arr, 0, arr.size() - 1); });
        ejecutarAlgoritmo(arregloOriginal, "Heap Sort", heapSort);
        ejecutarAlgoritmo(arregloOriginal, "Counting Sort", countingSort);

        cout << "Finalizado el procesamiento para " << file << "\n" << endl;
    }

    return 0;
}

vector<int> leerArchivo(const string& path) {
    ifstream archivo(path);
    string linea;
    vector<int> arr;
    if (archivo.is_open()) {
        getline(archivo, linea);
        stringstream ss(linea);
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        archivo.close();
    }
    return arr;
}

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(arr[minIdx], arr[i]);
    }
}

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
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

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }

    while (j < n2) {
        arr[k++] = R[j++];
    }
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

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

void heapSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

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

void countingSort(vector<int>& arr) {
    int maxVal = *max_element(arr.begin(), arr.end());
    vector<int> count(maxVal + 1, 0);
    for (int num : arr) {
        count[num]++;
    }
    int index = 0;
    for (int i = 0; i <= maxVal; i++) {
        while (count[i]-- > 0) {
            arr[index++] = i;
        }
    }
}
