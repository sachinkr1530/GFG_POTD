class Solution {
    public int celebrity(int mat[][]) {
        int n = mat.length;
        int a = 0, b = n - 1;

        while (a < b) {
            if (mat[a][b] == 1) a++;
            else  b--;
        }

        int j = a;

        for (int i = 0; i < n; i++) {
            if (i != j) {
                if (mat[j][i] != 0 || mat[i][j] != 1) {
                    return -1;
                }
            }
        }

        return j;
    }
}