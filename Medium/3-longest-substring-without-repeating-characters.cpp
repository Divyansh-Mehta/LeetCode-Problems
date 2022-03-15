#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.empty())
        {
            return 0;
        }
        int i = 0, j = 0;
        int n = s.size();
        int len = 0;
        unordered_map<char, int> hMap;
        while (j < n)
        {
            if (hMap[s[j]] == 0)
            {
                hMap[s[j]]++;
                len = max(len, j - i + 1);
                j++;
            }
            else
            {
                hMap[s[i]]--;
                i++;
            }
        }
        return len;
    }
};

int main()
{
    string s;
    Solution sol;
    cin >> s;
    cout << sol.lengthOfLongestSubstring(s) << endl;

    return 0;
}