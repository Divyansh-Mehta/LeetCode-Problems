#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
using namespace std;

//Both push and pop are O(n) time and space is O(n)
class FreqStack {
        unordered_map<int, int> freq;
        unordered_map<int, stack<int>> group;
        int maxFreq;
public:
    FreqStack() {  
        maxFreq = 0;
    }
    
    void push(int val) {
        int f = (freq.count(val) > 0) ? freq[val] + 1 : 1;
        freq[val] = f;
        if (f > maxFreq){
            maxFreq = f;
        }
        group[f].push(val);
    }
    
    int pop() {
        int x = group[maxFreq].top();
        group[maxFreq].pop();
        freq[x]--;
        if (group[maxFreq].empty()){
            maxFreq--;
        }
        return x;
    }
};


int main(){
    int n;
    cin >> n;
    vector<string> operation(n);
    vector<int> val(n);
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        operation[i] = s;
        if (s == "FreqStack" || s == "pop"){
            val[i] = -1;
        }
        else{
            cin >> val[i];
        }
    }
    vector<int> output;
    FreqStack f;
    output.push_back(-1);
    for (int i = 1; i < n; i++){
        if (operation[i] == "push"){
            f.push(val[i]);
            output.push_back(-1);
        }
        else{
            output.push_back(f.pop());
        }
    }
    
    for(auto x : output){
        cout << x << " ";
    }

    return 0;
}