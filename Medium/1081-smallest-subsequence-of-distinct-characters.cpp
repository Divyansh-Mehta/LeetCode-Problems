//316 and 1081 are similar
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

//Approach Time:-O(n) Space:- O(n)
class Solution1 {
public:
    string removeDuplicateLetters(string s) {
        vector<int> lastIndex(26);
        for (int i = 0; i < s.length(); i++){
            lastIndex[s[i] - 'a'] = i;
        }
        vector<bool> visited(26);
        stack<int> st;
        for (int i = 0; i < s.length(); i++){
            int ch = s[i] - 'a';
            if (visited[ch]){
                continue;
            }
            while (!st.empty() && st.top() > ch && i < lastIndex[st.top()]){
                visited[st.top()] = false;
                st.pop();
            }
            st.push(ch);
            visited[ch] = true;
        }
        
        string ans = "";
        while (!st.empty()){
            char ch = st.top() + 'a';
            ans = ch + ans;
            st.pop();
        }
        return ans;
    }
};

int main(){
    string s;
    cin >> s;
    Solution1 S;
    cout << S.removeDuplicateLetters(s) << endl;

    return 0;
}