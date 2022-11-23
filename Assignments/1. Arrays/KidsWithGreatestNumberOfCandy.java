import java.util.*;

public class KidsWithGreatestNumberOfCandy {
    public List<Boolean> kidsWithCandies(int[] candies, int extraCandies) {
        ArrayList<Boolean> result = new ArrayList<>(candies.length);
        int greatest = Integer.MIN_VALUE;
        
        for(int i = 0; i < candies.length; i++){
            if(candies[i] > greatest){
                greatest = candies[i];
            }
        }
        
        for(int i = 0 ; i < candies.length; i++){
            if(candies[i]+extraCandies >= greatest){
                result.add(true);
            }else{
                result.add(false);
            }
        }
        return result;
    }
}
