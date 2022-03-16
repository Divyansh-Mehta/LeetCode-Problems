#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//Approach - 1 Time:- O(n), space:- O(n)
class Solution1 {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int j = 0;
        for (int i = 0; i < pushed.size(); i++){
            st.push(pushed[i]);
            while (!st.empty() && j < popped.size() && popped[j] == st.top()){
                st.pop();
                j++;
            }
        }
        if (j == popped.size()){
            return true;
        }
        return false;
    }
};

//Approach - 2 Time:- O(n), space:- O(n)
class Solution2 {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int mark = -1, j = 0;
        for (int i = 0; i < pushed.size(); i++){
            pushed[++mark] = pushed[i];
            while (mark >= 0 && pushed[mark] == popped[j]){
                j++;
                mark--;
            }
        }
        return j == popped.size();
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> pushed(n), popped(n);
    for (int i = 0; i < n; i++){
        cin >> pushed[n];
    }

    for (int i = 0; i < n; i++){
        cin >> popped[n];
    }

    Solution1 S;
    if (S.validateStackSequences(pushed, popped)){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }

    return 0;
}