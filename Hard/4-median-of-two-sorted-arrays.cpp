#include <iostream>
#include <vector>
using namespace std;

/*
Approach-1
Time:- O((n+m)lon(n + m))
Space:- O(n + m)

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> temp;
        for (int i = 0; i < nums1.size(); i++){
            temp.push_back(nums1[i]);
        }
        
        for (int i = 0; i < nums2.size(); i++){
            temp.push_back(nums2[i]);
        }
        
        sort(temp.begin(), temp.end());
        double ans;
        int n = temp.size();
        if (n % 2 == 0){
            ans = (temp[n / 2] + temp[(n / 2) - 1]) / 2.0;
        }
        else{
            ans = temp[n / 2];
        }
        
        return ans;
    }
};
*/

/*
Approach-2
Time:- O(m + n)
Space:- O(m + n)

class Solution {
private:
    vector<int> mergeSortedArray(vector<int> &nums1, vector<int> &nums2){
        int i = 0, j = 0;
        vector<int> merge;
        
        while (i < nums1.size() && j < nums2.size()){
            if (nums1[i] < nums2[j]){
                merge.push_back(nums1[i++]);
            }
            else{
                merge.push_back(nums2[j++]);
            }
        }      
        while (i < nums1.size()){
            merge.push_back(nums1[i++]);
        }
        while (j < nums2.size()){
            merge.push_back(nums2[j++]);
        }
        
        return merge;
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merge = mergeSortedArray(nums1, nums2);
        int n = merge.size();
        double ans = 0;
        
        if (n % 2 == 0){
            ans = (merge[(n / 2) - 1] + merge[n / 2]) / 2.0;
        }
        else{
            ans = merge[n / 2];
        }
        
        return ans;
    }
};
*/

//Approach-3
//Time:- O(log(min(m,n)))
//Space:- O(1)
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums2.size() < nums1.size())
        {
            return findMedianSortedArrays(nums2, nums1);
        }

        int n1 = nums1.size();
        int n2 = nums2.size();
        int low = 0, high = n1;

        while (low <= high)
        {
            int cut1 = (low + high) / 2;
            int cut2 = (n1 + n2 + 1) / 2 - cut1;
            int l1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1];
            int l2 = cut2 == 0 ? INT_MIN : nums2[cut2 - 1];
            int r1 = cut1 == n1 ? INT_MAX : nums1[cut1];
            int r2 = cut2 == n2 ? INT_MAX : nums2[cut2];

            if (l1 <= r2 && l2 <= r1)
            {
                if ((n1 + n2) % 2 == 0)
                {
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                }
                return max(l1, l2);
            }
            else if (l1 > r2)
            {
                high = cut1 - 1;
            }
            else
            {
                low = cut1 + 1;
            }
        }

        return 0.0;
    }
};

int main(){
    int n, m;
    
    cin >> n;
    vector<int> nums1(n);
    for (int i = 0; i < n; i++){
        cin >> nums1[i];
    }

    cin >> m;
    vector<int> nums2(m);
    for (int i = 0; i < m; i++){
        cin >> nums2[i];
    }

    Solution sol;
    cout << sol.findMedianSortedArrays(nums1, nums2) << endl;

    return 0;
}