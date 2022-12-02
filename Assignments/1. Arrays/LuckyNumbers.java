import java.util.*;

public class LuckyNumbers {
    public List<Integer> luckyNumbers (int[][] matrix) {
        int[] min = new int[matrix.length];
        int[] max = new int[matrix[0].length];
        int rowMin, maxCol;
        for (int i = 0; i < matrix.length; i++) {
            rowMin = matrix[i][0];
            for (int j = 0; j < matrix[i].length; j++) {
                if (matrix[i][j] < rowMin) {
                    rowMin = matrix[i][j];
                }
                
            }
            min[i] = rowMin;    
        }
        for(int i = 0; i < matrix[0].length; i++){
            maxCol = matrix[0][i];
            for(int j = 0; j< matrix.length;j++){
                if (matrix[j][i] > maxCol) {
                    maxCol = matrix[j][i];
                }
            }
            max[i] = maxCol;
        }
        List<Integer> luckyNums = new ArrayList<Integer>();
        for(int i = 0; i < min.length; i++){
            for(int j = 0; j < max.length; j++){
                if(min[i] == max[j]){
                    luckyNums.add(min[i]);
                }
            }
        }
        return luckyNums;
    }
}
