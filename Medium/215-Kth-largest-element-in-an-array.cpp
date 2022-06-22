#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < k; i++){
            pq.push(nums[i]);
        }
        
        for (int i = k; i < nums.size(); i++){
            if (nums[i] >= pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
        }
        
        return pq.top();
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
    int k;
    cin >> k;

    Solution S;
    cout << S.findKthLargest(arr, k) << endl;

    return 0;
}