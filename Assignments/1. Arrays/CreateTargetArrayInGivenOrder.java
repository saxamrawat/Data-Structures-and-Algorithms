public class CreateTargetArrayInGivenOrder {
    public int[] createTargetArray(int[] nums, int[] index) {
        int[] target = new int[nums.length];
        
        for(int i = 0; i < nums.length; i++){
            int ind = index[i];
            if(ind < i){
                int j = i;
                while(j > ind){
                    target[j] = target[j-1];
                    target[j-1] = nums[i];
                    j--;
                }
            }else{
                target[ind] = nums[i];
            }
        }
        
        return target;
    }
}
