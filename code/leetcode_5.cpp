/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
#include <string>
using namespace std;
class Solution
{
private:
    void searchMax(int forward, int before, int& maxCount, int index, string &s, string &result)
    {
        while (true)
        {
            if (index - forward < 0)
                break;
            if (index + before >= s.size())
                break;
            if (s[index - forward] != s[index + before])
                break;
            int all = before + forward + 1;
            if (all > maxCount)
            {
                maxCount = all;
                result   = s.substr(index - forward, all);
            }
            forward++;
            before++;
        }
    }

public:
    string longestPalindrome(string s)
    {
        if (s.size() < 1)
        {
            return "";
        }
        if (s.size() == 1)
        {
            return s;
        }
        string result   = s.substr(0, 1);
        int    maxCount = 1;

        for (size_t index = 0; index < s.size(); index++)
        {
            int forward = 1;
            int before  = 1;
            searchMax(forward, before, maxCount, index, s, result);
            forward = 0;
            searchMax(forward, before, maxCount, index, s, result);
        }
        return result;
    }
};
// @lc code=end
