//Swap two elements of an array

import java.util.Arrays;
import java.util.Scanner;

public class SwappingElements {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int  arr[] = {1, 2, 3, 4, 5};
        int x = scan.nextInt();      //index1  
        int y = scan.nextInt();      //index2
        swap(arr, x, y);
        scan.close();
        System.out.println(Arrays.toString(arr));
    }
    static void swap(int[] arr, int index1, int index2){
        int temp = arr[index1];
        arr[index1] = arr[index2];
        arr[index2] = temp;
    }
}
