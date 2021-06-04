/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
#include <algorithm>
#include <vector>
using namespace std;
class Solution
{
public:
    // int minSubArrayLen(int target, vector<int> &nums)
    // {
    //     int flag = 0;

    //     for (int index = 0; index < nums.size(); index++)
    //     {
    //         int all   = nums[index];
    //         int point = index;
    //         while (true)
    //         {
    //             int length = index - point + 1;
    //             if (all >= target)
    //             {
    //                 if (flag == 0)
    //                     flag = length;
    //                 else if (flag > length)
    //                     flag = length;
    //                 break;
    //             }
    //             if (flag != 0 && flag <= length)
    //             {
    //                 break;
    //             }

    //             point--;

    //             if (point < 0)
    //                 break;
    //             all += nums[point];
    //         }
    //     }
    //     return flag;
    // }

    int minSubArrayLen(int target, vector<int> &nums)
    {
        bool flag = false;

        int length = 0;
        int all    = 0;

        for (int index = 0; index < nums.size(); index++)
        {
            all += nums[index];
            if (!flag)
                length++;
            else
                all -= nums[index - length];

            if (all >= target && !flag)
                flag = true;

            while (flag)
            {
                auto tempAll = all - nums[index + 1 - length];
                if (tempAll >= target)
                {
                    all = tempAll;
                    length--;
                }
                else
                    break;
            }
        }
        return flag ? length : 0;
    }
};
// @lc code=end
