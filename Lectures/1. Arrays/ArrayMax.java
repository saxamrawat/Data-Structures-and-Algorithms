//Find the maximum element of an array.

public class ArrayMax {
        public static void main(String[] args) {
            int  arr[] = {1, 2, 3, 4, 5};
            System.out.println(maxInARange(arr, 1, 3));
        }

        //overall

        static int max(int[] arr){

            //edge case
            if(arr.length == 0){
                return -1;
            }

            int maxNum = Integer.MIN_VALUE;
            for(int i = 0; i < arr.length;i++){
                if(arr[i] > maxNum){
                    maxNum = arr[i];
                }
            }
            return maxNum;
        }

        //in a range

        static int maxInARange(int[] arr, int x, int y){

            //adding edge case before
            if(y > x){
                return -1;
            }

            if(arr == null){
                return -1;
            }

            int maxNum = arr[x];
            for(int i = x; i <=y ;i++){
                if(arr[i] > maxNum){
                    maxNum = arr[i];
                }
            }
            return maxNum;
        }
}
