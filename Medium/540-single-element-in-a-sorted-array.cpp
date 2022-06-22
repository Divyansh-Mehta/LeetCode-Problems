#include <iostream>
#include <vector>
using namespace std;

// appraoch - 1 Time - O(n) space - O(1)
class Solution1
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        int single = 0;
        for (int i = 0; i < n; i++)
        {
            single ^= nums[i];
        }
        return single;
    }
};

// Approach - 2 Time - O(logn) Space - O(1)
class Solution2a
{
public:
    int singleNonDuplicate(vector<int> &arr)
    {
        int low = 0, high = arr.size() - 1;
        /*if (arr.size() == 1){
            return arr[0];
        }
        if (arr[0] != arr[1]){
            return arr[0];
        }
        if (arr[arr.size() - 1] != arr[arr.size() - 2]){
            return arr[arr.size() - 1];
        }
        */

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (low == high)
            {
                return arr[low];
            }
            else if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1])
            {
                return arr[mid];
            }
            /*
            if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1]) {
                return arr[mid];
            }
            */

            if (mid % 2 == 0)
            {
                if (arr[mid] == arr[mid - 1])
                {
                    high = mid - 2;
                }
                else
                {
                    low = mid + 2;
                }
            }
            else
            {
                if (arr[mid] == arr[mid - 1])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};

// Better code for approach 2
class Solution2b
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int l = 0;
        int r = nums.size() - 1;
        while (l < r)
        {
            int mid = (l + r) / 2;
            bool isEven = mid % 2 == 0;
            if (nums[mid] == nums[mid + 1])
            {
                if (isEven)
                {
                    l = mid + 2;
                }
                else
                {
                    r = mid - 1;
                }
            }
            else if (nums[mid] == nums[mid - 1])
            {
                if (isEven)
                {
                    r = mid - 2;
                }
                else
                {
                    l = mid + 1;
                }
            }
            else
            {
                return nums[mid];
            }
        }
        return nums[l];
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

    Solution2b S;
    cout << S.singleNonDuplicate(arr) << endl;

    return 0;
}

/* Summary
unsorted :- best time :- O(n) using xor
sorted :- best time :- O(logn) using binary Search
*/