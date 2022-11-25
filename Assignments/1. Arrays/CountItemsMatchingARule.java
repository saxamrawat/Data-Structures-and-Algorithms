import java.util.*;

public class CountItemsMatchingARule {
    public int countMatches(List<List<String>> items, String ruleKey, String ruleValue) {
        int answ = 0;
        for(int i = 0; i < items.size(); i++){
            if(ruleKey.equals("type") && ruleValue.equals(items.get(i).get(0))){
                answ++;
            }
            if(ruleKey.equals("color") && ruleValue.equals(items.get(i).get(1))){
                answ++;
            }
            if(ruleKey.equals("name") && ruleValue.equals(items.get(i).get(2))){
                answ++;
            }
        }
        return answ;
    }
}
