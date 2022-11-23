public class ShuffleTheArray {
    public int[] shuffle(int[] nums, int n) {
        int[] newArr = new int[2*n];
        int i = 0;
        int j = n;
        
        for(int k = 0; k < 2*n; k+=2){
            newArr[k] = nums[i];
            newArr[k+1] = nums[j];
            i++;
            j++;
        }
        return newArr;
    }
}
