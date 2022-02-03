#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
Approach-1
Time:- O(n^2)
Space:- O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
     vector<int> ans;
        for (int i = 0; i < nums.size() - 1; i++){
            for (int j = i + 1; j < nums.size(); j++){
                if (nums[i] + nums[j] == target){
                    ans.push_back(i);
                    ans.push_back(j);

                }
            }
        }
        return ans;
    }
};
*/

//Approach - 2
//Time:- O(n)
//Space:- O(n)
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> hMap;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            if (hMap.count(target - nums[i]) > 0)
            {
                ans.push_back(hMap[target - nums[i]]);
                ans.push_back(i);
            }
            hMap[nums[i]] = i;
        }
        return ans;
    }
};

int main()
{
    vector<int> nums;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int no;
        cin >> no;
        nums.push_back(no);
    }
    int target;
    cin >> target;
    Solution sol;
    vector<int> ans = sol.twoSum(nums, target);
    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}