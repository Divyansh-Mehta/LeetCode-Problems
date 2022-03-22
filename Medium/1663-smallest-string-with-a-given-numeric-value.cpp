#include <iostream>
#include <string>
using namespace std;

//Both apporaches are Time - O(n) space - O(1)
//Approach - 1 Making answer string from the end
class Solution1 {
    void reverse(string &s){
        int i = 0, j = s.length() - 1;
        while(i < j){
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
        }
    }
public:
    string getSmallestString(int n, int k) {
        string ans = "";
        for (int i = 1; i <= n; i++){
            int numVal = (k - n + i >= 26) ? 26 : (k - n + i);
            char ch = numVal + 'a' - 1;
            ans += ch;
            k -= numVal;
        }
        reverse(ans);
        return ans;
    }
};

//Approach-2 Making answer string from the beginning
class Solution2 {
public:
    string getSmallestString(int n, int k) {
        string ans = "";
        for (int i = 1; i <= n; i++){
            int numVal = ((n - i) * 26 >= k - 1) ? 1 : (k - ((n - i) * 26));
            char ch = numVal + 'a' - 1;
            ans += ch;
            k -= numVal;
        }
        return ans;
    }
};

int main(){
    int n, k;
    cin >> n >> k;
    Solution1 S;
    cout << S.getSmallestString(n , k) << endl;

    return 0;
}