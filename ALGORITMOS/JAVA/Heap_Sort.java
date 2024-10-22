import java.io.*;
import java.util.*;

public class Heap_Sort {
    public static void main(String[] args) throws IOException {
        String ruta = "archivo.txt";
        BufferedReader br = new BufferedReader(new FileReader(ruta));
        String[] data = br.readLine().split(" ");
        int[] arr = Arrays.stream(data).mapToInt(Integer::parseInt).toArray();
        br.close();

        long startTime = System.currentTimeMillis();

        heapSort(arr);

        BufferedWriter bw = new BufferedWriter(new FileWriter(ruta));
        for (int num : arr) {
            bw.write(num + " ");
        }
        bw.close();

        long endTime = System.currentTimeMillis();
        System.out.println("Tiempo de ejecución: " + (endTime - startTime) + " ms");
    }

    public static void heapSort(int[] arr) {
        int n = arr.length;

        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }

        for (int i = n - 1; i >= 0; i--) {
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

        if (left < n && arr[left] > arr[largest]) {
            largest = left;
        }

        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }

        if (largest != i) {
            int swap = arr[i];
            arr[i] = arr[largest];
            arr[largest] = swap;
            heapify(arr, n, largest);
        }
    }
}
