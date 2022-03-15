#include <iostream>
#include <string>
using namespace std;

//Approach-1 time :- O(n) {three times traversed string}  Space :- O(1) [n == length of string]
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int count = 0;
        for (int i = 0; i < s.length(); i++){
            if (s[i] == '('){
                count++;
            }
            else if (s[i] == ')'){
                if (count == 0){
                    s[i] = '*';
                }
                else{
                    count--;
                }
            }
        }
        count = 0;
        for (int i = s.length(); i >= 0; i--){
            if (s[i] == ')'){
                count++;
            }
            else if (s[i] == '('){
                if (count == 0){
                    s[i] = '*';
                }
                else{
                    count--;
                }
            }
        }
        string ans = "";
        for (int i = 0; i < s.length(); i++){
            if (s[i] != '*'){
                ans += s[i];
            }
        }
        return ans;
    }
};

/*Approach-2 time :- O(n) {two times traversed string} space :- O(n) [n == length of string]
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        for (int i = 0; i < s.length(); i++){
            if (s[i] == '('){
                st.push(i);
            }
            else if (s[i] == ')'){
                if (st.empty()){
                    s[i] = '*';
                }
                else{
                    st.pop();
                }
            }
        }
        while (!st.empty()){
            s[st.top()] = '*';
            st.pop();
        }
        string ans = "";
        for (int i = 0; i < s.length(); i++){
            if (s[i] != '*'){
                ans += s[i];
            }
        }
        
        return ans;
    }
};
*/