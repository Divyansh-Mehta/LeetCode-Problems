#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Time - O(nlogn), space O(1)
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), [](vector<int> v1, vector<int> v2){
        return (v1[0] - v1[1] < v2[0] - v2[1]);            
        });
        int ans = 0;
        for (int i = 0; i < costs.size() / 2; i++){
            ans += costs[i][0];
        }
        for (int i = costs.size() / 2; i < costs.size(); i++){
            ans += costs[i][1];
        }
        return ans;
    }
};

int main(){
    int n;
    cin >> n;
    vector<vector<int>> costs(n, vector<int> (2));
    for (int i = 0; i < n; i++){
        cin >> costs[i][0] >> costs[i][1];
    }

    Solution S;
    cout << S.twoCitySchedCost(costs) << endl;

    return 0;
}