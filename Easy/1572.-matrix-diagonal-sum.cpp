#include <iostream>
#include <vector>
using namespace std;


// Time - O(n) Space - O(1)
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0, n = mat.size();
        for (int i = 0; i < n; i++){
            sum += mat[i][n - i - 1] + mat[i][i];
        }
        int sub = n % 2 == 0? 0:  mat[n / 2][n / 2];
        return sum - sub;
    }
};

int main(){
    int n;
    cin >> n;

    vector<vector<int>> mat(n, vector<int>(n));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> mat[i][j];
        }
    }

    Solution S;
    cout << S.diagonalSum(mat) << endl;

    return 0;
}