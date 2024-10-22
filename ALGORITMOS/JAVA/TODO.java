import java.io.*;
import java.util.*;

public class TODO {
    public static void main(String[] args) throws IOException {
        String[] files = {
            "File_100.txt", "File_500.txt", "File_1000.txt", "File_2000.txt",
            "File_3000.txt", "File_4000.txt", "File_5000.txt", "File_6000.txt",
            "File_7000.txt", "File_8000.txt", "File_10000.txt", "File_20000.txt",
            "File_30000.txt", "File_40000.txt", "File_50000.txt", "File_60000.txt",
            "File_70000.txt", "File_80000.txt", "File_100000.txt"
        };

        for (String file : files) {
            System.out.println("\n--- Resultados para " + file + " ---");
            int[] arregloOriginal = leerArchivo(file);

            ejecutarAlgoritmo(arregloOriginal.clone(), "Bubble Sort", TODO::bubbleSort);
            ejecutarAlgoritmo(arregloOriginal.clone(), "Selection Sort", TODO::selectionSort);
            ejecutarAlgoritmo(arregloOriginal.clone(), "Insertion Sort", TODO::insertionSort);
            ejecutarAlgoritmo(arregloOriginal.clone(), "Merge Sort", arr -> mergeSort(arr, 0, arr.length - 1));
            ejecutarAlgoritmo(arregloOriginal.clone(), "Quick Sort", arr -> quickSort(arr, 0, arr.length - 1));
            ejecutarAlgoritmo(arregloOriginal.clone(), "Heap Sort", TODO::heapSort);
            ejecutarAlgoritmo(arregloOriginal.clone(), "Counting Sort", TODO::countingSort);

            System.out.println("Finalizado el procesamiento para " + file + "\n");
        }
    }

    public static void ejecutarAlgoritmo(int[] arreglo, String nombre, SortFunction algoritmo) {
        System.out.println("Ejecutando " + nombre + "...");
        long inicio = System.currentTimeMillis();
        algoritmo.sort(arreglo);
        long fin = System.currentTimeMillis();
        System.out.println(nombre + " completado en " + (fin - inicio) + " ms");
    }

    public static int[] leerArchivo(String path) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader(path));
        String[] datos = br.readLine().split(" ");
        br.close();
        return Arrays.stream(datos).mapToInt(Integer::parseInt).toArray();
    }

    @FunctionalInterface
    public interface SortFunction {
        void sort(int[] arr);
    }

    public static void bubbleSort(int[] arr) {
        int n = arr.length;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    public static void selectionSort(int[] arr) {
        int n = arr.length;
        for (int i = 0; i < n - 1; i++) {
            int minIdx = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[minIdx]) {
                    minIdx = j;
                }
            }
            int temp = arr[minIdx];
            arr[minIdx] = arr[i];
            arr[i] = temp;
        }
    }

    public static void insertionSort(int[] arr) {
        int n = arr.length;
        for (int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
    }

    public static void mergeSort(int[] arr, int left, int right) {
        if (left < right) {
            int mid = (left + right) / 2;
            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);
            merge(arr, left, mid, right);
        }
    }

    public static void merge(int[] arr, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;
        int[] L = new int[n1];
        int[] R = new int[n2];

        System.arraycopy(arr, left, L, 0, n1);
        System.arraycopy(arr, mid + 1, R, 0, n2);

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

    public static void quickSort(int[] arr, int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }

    public static int partition(int[] arr, int low, int high) {
        int pivot = arr[high];
        int i = (low - 1);
        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        return i + 1;
    }

    public static void heapSort(int[] arr) {
        int n = arr.length;
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }
        for (int i = n - 1; i > 0; i--) {
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;
            heapify(arr, i, 0);
        }
    }

    public static void heapify(int[] arr, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < n && arr[left] > largest) {
            largest = left;
        }
        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }
        if (largest != i) {
            int temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;
            heapify(arr, n, largest);
        }
    }

    public static void countingSort(int[] arr) {
        int maxVal = Arrays.stream(arr).max().getAsInt();
        int[] count = new int[maxVal + 1];

        for (int num : arr) {
            count[num]++;
        }

        int i = 0;
        for (int num = 0; num <= maxVal; num++) {
            while (count[num] > 0) {
                arr[i++] = num;
                count[num]--;
            }
        }
    }
}
