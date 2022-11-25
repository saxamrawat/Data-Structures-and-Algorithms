public class NumberOfSmallerElements {
    public int[] smallerNumbersThanCurrent(int[] nums) {
        int[] answer = new int[nums.length];
        for(int i = 0; i < nums.length; i++){
            int numOfSmallerElements = 0;
            for(int j = 0 ; j < nums.length; j++){
                if(nums[j] < nums[i]){
                    numOfSmallerElements++;
                }
            }
            answer[i] = numOfSmallerElements;
        }
        return answer;
    }
}
