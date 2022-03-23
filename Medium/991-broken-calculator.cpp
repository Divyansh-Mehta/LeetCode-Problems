#include <iostream>
using namespace std;

//Time - O(log(target)) Space - O(1)
class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int ans = 0;
        while (target > startValue){
            ans++;
            if (target % 2 == 0){
                target /= 2;
            }
            else{
                target++;
            }
        }
        return ans + startValue - target;
    }
};

int main(){
    int startValue, target;
    cin >> startValue >> target;
    Solution S;
    cout << S.brokenCalc(startValue, target) << endl;

    return 0;
}