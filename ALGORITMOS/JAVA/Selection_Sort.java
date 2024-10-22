import java.io.*;
import java.util.*;

public class Selection_Sort {
    public static void main(String[] args) throws IOException {
        String ruta = "archivo.txt";
        BufferedReader br = new BufferedReader(new FileReader(ruta));
        String[] data = br.readLine().split(" ");
        int[] arr = Arrays.stream(data).mapToInt(Integer::parseInt).toArray();
        br.close();

        long startTime = System.currentTimeMillis();

        selectionSort(arr);

        BufferedWriter bw = new BufferedWriter(new FileWriter(ruta));
        for (int num : arr) {
            bw.write(num + " ");
        }
        bw.close();

        long endTime = System.currentTimeMillis();
        System.out.println("Tiempo de ejecución: " + (endTime - startTime) + " ms");
    }

    public static void selectionSort(int[] arr) {
        int n = arr.length;
        for (int i = 0; i < n - 1; i++) {
            int min_idx = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[min_idx]) {
                    min_idx = j;
                }
            }
            int temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }
    }
}
