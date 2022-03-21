#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> count(26);
        for (int i = 0; i < s.length(); i++){
            count[s[i] - 'a'] = i;
        }
        
        int end = 0, start = 0;
        vector<int> ans;
        for (int i = 0; i < s.length(); i++){
            end = max(end, count[s[i] - 'a']);
            if (i == end){
                ans.push_back(end - start + 1);
                start = i + 1;
            }
        }
        return ans;
    }
};

int main(){
    string s;
    cin >> s;

    Solution S;
    vector<int> interval = S.partitionLabels(s);

    for (auto x : interval){
        cout << x << " ";
    }

    return 0;
}