#include <iostream>
#include <vector>
using namespace std;

// Time - O(n) Space - O(1)
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] <= 0){
                nums[i] = n + 1;
            }
        }
        
        for (int i = 0; i < n; i++){
            int x = nums[i] > 0 ? nums[i] : -1 * nums[i];
            if (x - 1 < nums.size() && nums[x - 1] > 0){
                nums[x - 1] *= -1;
            }
        }
        
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] > 0){
                return i + 1;
            }
        }
        return n + 1;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Solution S;
    cout << S.firstMissingPositive(arr) << endl;

    return 0;
}