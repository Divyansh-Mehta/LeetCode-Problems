#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Can be done using hashmap also

//Time: - O(n^2) Space: - O(1)
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int x = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0){
                break;
            }
            if (i != 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            int j = i + 1;
            int k = nums.size() - 1;
            int xr = x - nums[i];
            while (j < k)
            {
                if (nums[j] + nums[k] == xr)
                {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while (j < nums.size() && nums[j] == nums[j - 1])
                    {
                        j++;
                    }
                    while (k >= 0 && nums[k] == nums[k + 1])
                    {
                        k--;
                    }
                }
                else if (nums[j] + nums[k] > xr)
                {
                    k--;
                }
                else
                {
                    j++;
                }
            }
        }
        return ans;
    }
};

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    Solution S;
    vector<vector<int>> ans = S.threeSum(nums);

    for (auto x : ans)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}