#include <iostream>
#include <stack>
#include <string>
using namespace std;

//Approach-1:- Time - O(n), space - O(n)
class Solution1 {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);
        for (int i = 0; i < s.length(); i++){
            if (s[i] == '('){
                st.push(0);
            }
            else{
                int temp = 0;
                if (st.top() == 0){
                       temp = 1;
                }
                else{
                    temp = st.top() * 2;
                }
                st.pop();
                temp += st.top();
                st.pop();
                st.push(temp);
            }
        }
        return st.top();
    }
};

//Approach-2:- Time - O(n), space - O(1)
class Solution2 {
public:
    int scoreOfParentheses(string s) {
        int ans = 0, fac = 0;
        for (int i = 0; i < s.length(); i++){
            if (s[i] == '('){
                fac++;
            }
            else{
                fac--;
                if (s[i - 1] == '('){
                    ans += 1 << fac;
                }
            }
        }
        
        return ans;
    }
};


int main(){
    string s;
    cin >> s;
    Solution1 S;
    cout << S.scoreOfParentheses(s) << endl;

    return 0;
}