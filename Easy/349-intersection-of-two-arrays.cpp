#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//Time: - O(n + m) Space: - O(n)
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hMap;
        for (int i = 0; i < nums1.size(); i++){
            hMap[nums1[i]]++;
        }
        vector<int> ans;
        for (int i = 0; i < nums2.size(); i++){
            if (hMap[nums2[i]] > 0){
                ans.push_back(nums2[i]);
                hMap[nums2[i]] = 0;
            }
        }
        return ans;
    }
};

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> nums1(n), nums2(m);
    for (int i = 0; i < n; i++){
        cin >> nums1[i];
    }
    for (int i = 0; i < m; i++){
        cin >> nums2[i];
    }
    
    Solution S;
    vector<int> ans = S.intersection(nums1, nums2);

    for(auto x : ans){
        cout << x << " ";
    }

    return 0;
}