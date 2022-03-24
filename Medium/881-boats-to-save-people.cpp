#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int i = 0, j = people.size() - 1;
        int count = 0;
        while (i <= j){
            count++;
            if (people[i] + people[j] <= limit){
                i++;
            }
            j--;
        }
        return count;
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> people(n);
    for (int i = 0; i < n; i++){
        cin >> people[i];
    }
    int limit;
    cin >> limit;

    Solution S;
    cout << S.numRescueBoats(people, limit) << endl;

    return 0;
}