/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
#include <string>
using namespace std;
class Solution
{
public:
    int myAtoi(string s)
    {
        bool      isMinus   = false;
        bool      waitStart = true;
        long long result    = 0;

        int begin = 0;
        for (size_t i = 0; i < s.size(); i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                begin = i;
                break;
            }
            if (s[i] != ' ' && s[i] != '+' && s[i] != '-')
                return 0;
            if (s[i] == '+' || s[i] == '-')
            {
                if (i + 1 >= s.size())
                    return 0;
                if (!(s[i + 1] >= '0' && s[i + 1] <= '9'))
                    return 0;
                begin = i + 1;
                if (s[i] == '-')
                    isMinus = true;
                break;
            }
        }

        for (int index = begin; index < s.size(); index++)
        {
            if (s[index] >= '0' && s[index] <= '9')
            {
                int temp = isMinus ? -(s[index] - '0') : s[index] - '0';
                result   = result * 10 + temp;

                if (result > INT_MAX)
                    return INT_MAX;
                if (result < INT_MIN)
                    return INT_MIN;
            }
            else
                break;
        }
        return int(result);
    }
};
// @lc code=end
