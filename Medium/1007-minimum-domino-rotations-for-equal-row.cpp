#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        vector<int> countTop(7, 0);
        vector<int> countBot(7, 0);
        vector<int> countSame(7, 0);
        int n = tops.size();
        for (int i = 0; i < n; i++){
            countTop[tops[i]]++;
            countBot[bottoms[i]]++;
            if (tops[i] == bottoms[i]){
                countSame[tops[i]]++;
            }
        }
        int ans = INT_MAX;
        for (int i = 1; i < 7; i++){
            if (countTop[i] + countBot[i] - countSame[i] == n){
                ans = min(ans, (n - max(countTop[i], countBot[i])));
            }
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> tops(n), bottoms(n);

    for (int i = 0; i < n; i++){
        cin >> tops[i];
    }

    for (int i = 0; i < n; i++){
        cin >> bottoms[i];
    }
    Solution S;
    cout << S.minDominoRotations(tops, bottoms) << endl;

    return 0;
}