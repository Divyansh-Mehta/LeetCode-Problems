#include <iostream>
#include <vector>
using namespace std;

class Solution {
    bool found(vector<vector<char>>& board, string word, int i, int j, int indx, int m, int n){
        if (indx == word.size()){
            return true;
        }
        
        if (i < 0 || j < 0 || i >= m || j >= n){
            return false;
        }
        
        int move[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        if (word[indx] == board[i][j]){
            char ch = board[i][j];
            board[i][j] = '$';
            for (auto x : move){
                if (found(board, word, i + x[0], j + x[1], indx + 1, m, n)){
                    return true;
                }
            }
            board[i][j] = ch;
        }
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (board[i][j] == word[0]){
                    if (found(board, word, i, j, 0, m, n)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

int main(){
    int m, n;
    cin >> m >> n;
    vector<vector<char>> board(m, vector<char> (n));

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cin >> board[i][j];
        }
    }
    string word;
    cin >> word;

    Solution S;
    if (S.exist(board, word)){
        cout << "true" << endl;
    } 
    else{
        cout << "false" << endl;
    }

    return 0;
}