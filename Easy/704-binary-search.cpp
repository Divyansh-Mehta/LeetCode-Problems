#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, h = nums.size() - 1;
        while (l <= h){
            int mid = (l + h) / 2;
            if (nums[mid] == target){
                return mid;
            }
            else if (nums[mid] < target){
                l = mid + 1;
            }
            else{
                h = mid - 1;
            }
        }
        return -1;
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }
    int target;
    cin >> target;
    
    Solution S;
    cout << S.search(nums, target) << endl;

    return 0;
}