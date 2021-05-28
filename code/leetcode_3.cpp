// @lc code=end

/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start

#include <string>
#include <unordered_map>

using namespace std;

class Solution
{

public:
    // int lengthOfLongestSubstring(string s)
    // {
    //     if (s.size() == 0)
    //         return 0;
    //     std::map<int, int> has;
    //     int max = 0;
    //     int index = 0;
    //     int maxsize = s.size();
    //     while (index < maxsize)
    //     {
    //         if (has.find(s[index]) == has.end())
    //         {
    //             has[s[index]] = index;
    //             ++index;
    //         }
    //         else
    //         {
    //             int size = has.size();
    //             max = size > max ? size : max;
    //             index = has[s[index]] + 1;
    //             has.clear();
    //         }
    //     }
    //     int size = has.size();
    //     max = size > max ? size : max;
    //     return max;
    // }

    int lengthOfLongestSubstring(string s)
    {
        if (s.size() == 0)
            return 0;
        std::unordered_map<int, int> map;
        int                          max     = 0;
        int                          index   = 0;
        int                          maxsize = s.size();

        int begin = 0;

        while (index < maxsize)
        {
            char index_c = s[index];
            if (map.find(index_c) != map.end())
            {
                if (map[index_c] >= begin)
                {
                    int size = index - begin;
                    max      = size > max ? size : max;
                    begin    = map[index_c] + 1;
                }
            }
            map[index_c] = index;
            index++;
        }
        int size = maxsize - begin;
        max      = size > max ? size : max;
        return max;
    }
};
// @lc code=end
