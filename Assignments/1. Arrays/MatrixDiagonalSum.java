public class MatrixDiagonalSum {
    public int diagonalSum(int[][] mat) {
        int len = mat.length-1;
        int ans = 0;
        int mid = 0;
        
        if(mat.length %2 != 0){
            mid = mat[len/2][len/2];
        }
        
        for(int i = 0; i < mat.length; i++){
            ans += mat[i][i] + mat[i][len--];
        }
        return ans-mid;
    }
}
