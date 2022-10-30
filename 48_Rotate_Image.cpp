class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int sum = n-1;
        for (int i = 0; i < n/2; ++i) {
            for (int j = i; j < sum-i; ++j) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[sum-j][i];
                matrix[sum-j][i] = matrix[sum-i][sum-j];
                matrix[sum-i][sum-j] = matrix[j][sum-i];
                matrix[j][sum-i] = temp;
            }
        }
    }
};
