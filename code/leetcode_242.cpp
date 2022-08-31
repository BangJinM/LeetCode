/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
#include <map>
#include <string>
using namespace std;
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false;
        map<char, int> strs;
        for (char c : s)
        {
            if (strs.find(c) == strs.end())
            {
                strs[c] = 0;
            }
            strs[c]++;
        }

        for (char c : t)
        {
            if (strs.find(c) == strs.end())
            {
                return false;
            }
            else
            {
                if (strs[c] <= 0)
                {
                    return false;
                }
                strs[c]--;
            }
        }
        return true;
    }
};
// @lc code=end
