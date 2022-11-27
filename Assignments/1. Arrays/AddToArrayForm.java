import java.util.*;

public class AddToArrayForm {
    public List<Integer> addToArrayForm(int[] num, int k) {
        List<Integer> arr = new ArrayList<>();
        int i = num.length-1;
        while(i >=0 || k > 0){
            if(i >= 0){
                arr.add((num[i]+k)%10);
                k = (num[i]+k)/10;
            }else{
                arr.add(k%10);
                k = k/10;
            }
            i--;
        }
        Collections.reverse(arr);
        return arr;
    }

    public static void main(String[] args) {
        AddToArrayForm ad = new AddToArrayForm();
        int[] n = {9,9,9,9,9,9,9,9,9};
        System.out.println(ad.addToArrayForm(n, 1));
    }
}
