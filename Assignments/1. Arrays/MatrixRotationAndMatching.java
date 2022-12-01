public class MatrixRotationAndMatching{
    public boolean findRotation(int[][] mat, int[][] target) {
        for(int i=0; i<4; i++){
            if(isEqual(mat,target)){
                return true;   
            } 
            mat = Rotate(mat);
        }
        return false;        
    }
    
    public static boolean isEqual(int[][] m1 , int[][] m2){
        if(m1.length != m2.length){
            return false;
        } 
        if(m1[0].length != m2[0].length){
            return false;
        } 
        for(int row=0; row<m1.length; row++){
            for(int col = 0; col<m1[0].length; col++){
                if(m1[row][col] != m2[row][col]){
                    return false;
                } 
            }
        }
        return true;
    }
    
    public int[][] Rotate(int[][]mat){
        for(int i = 0; i < mat.length; i++){
            for(int j = i; j < mat[i].length; j++){
                int temp = mat[i][j];
                mat[i][j] = mat[j][i];
                mat[j][i] = temp;
            }
        }
        
        for(int i = 0; i < mat.length; i++){
            int li = 0;
            int ri = mat[i].length - 1;
            
            while(li< ri){
                int temp = mat[i][li];
                mat[i][li] = mat[i][ri];
                mat[i][ri] = temp;
                li++;
                ri--;
            }
        }
        
        return mat;
    }
}