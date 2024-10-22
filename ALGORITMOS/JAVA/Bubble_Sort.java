import java.io.*;
import java.util.*;

public class Bubble_Sort {
    public static void main(String[] args) throws IOException {
        String ruta = "archivo.txt";
        BufferedReader br = new BufferedReader(new FileReader(ruta));
        String[] data = br.readLine().split(" ");
        int[] arr = Arrays.stream(data).mapToInt(Integer::parseInt).toArray();
        br.close();

        long startTime = System.currentTimeMillis();
        
        int n = arr.length;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; n - i - 1 > j; j++) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }

        BufferedWriter bw = new BufferedWriter(new FileWriter(ruta));
        for (int num : arr) {
            bw.write(num + " ");
        }
        bw.close();

        long endTime = System.currentTimeMillis();
        System.out.println("Tiempo de ejecución: " + (endTime - startTime) + " ms");
    }
}
