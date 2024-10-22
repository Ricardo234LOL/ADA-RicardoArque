import java.io.*;
import java.util.*;

public class Quick_Sort {
    public static void main(String[] args) throws IOException {
        String ruta = "archivo.txt";
        BufferedReader br = new BufferedReader(new FileReader(ruta));
        String[] data = br.readLine().split(" ");
        int[] arr = Arrays.stream(data).mapToInt(Integer::parseInt).toArray();
        br.close();

        long startTime = System.currentTimeMillis();

        quickSort(arr, 0, arr.length - 1);

        BufferedWriter bw = new BufferedWriter(new FileWriter(ruta));
        for (int num : arr) {
            bw.write(num + " ");
        }
        bw.close();

        long endTime = System.currentTimeMillis();
        System.out.println("Tiempo de ejecución: " + (endTime - startTime) + " ms");
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
}
