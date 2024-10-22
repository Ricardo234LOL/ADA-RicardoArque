import java.io.*;
import java.util.*;

public class Counting_Sort {
    public static void main(String[] args) throws IOException {
        String ruta = "archivo.txt";
        BufferedReader br = new BufferedReader(new FileReader(ruta));
        String[] data = br.readLine().split(" ");
        int[] arr = Arrays.stream(data).mapToInt(Integer::parseInt).toArray();
        br.close();

        long startTime = System.currentTimeMillis();

        int max = Arrays.stream(arr).max().getAsInt();
        int[] count = new int[max + 1];
        int[] output = new int[arr.length];

        for (int i = 0; i < arr.length; i++) {
            count[arr[i]]++;
        }

        for (int i = 1; i <= max; i++) {
            count[i] += count[i - 1];
        }

        for (int i = arr.length - 1; i >= 0; i--) {
            output[count[arr[i]] - 1] = arr[i];
            count[arr[i]]--;
        }

        BufferedWriter bw = new BufferedWriter(new FileWriter(ruta));
        for (int num : output) {
            bw.write(num + " ");
        }
        bw.close();

        long endTime = System.currentTimeMillis();
        System.out.println("Tiempo de ejecución: " + (endTime - startTime) + " ms");
    }
}
