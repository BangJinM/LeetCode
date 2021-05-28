/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */
#include <math.h>
// @lc code=start
class Solution
{
public:
    // bool isPalindrome(int x)
    // {
    //     if (x < 0)
    //         return false;
    //     if (x < 10)
    //         return true;
    //     int num   = x;
    //     int count = 0;
    //     while (num > 0)
    //     {
    //         num = num / 10;
    //         count++;
    //     }
    //     num       = x;
    //     int num2  = x;
    //     int index = 1;
    //     while (true)
    //     {
    //         int powNum = pow(10, count - index);
    //         int temp1  = num / powNum;
    //         int temp2  = num2 % 10;

    //         num  = num % powNum;
    //         num2 = num2 / 10;

    //         if (temp1 != temp2)
    //             return false;
    //         index++;
    //         if (index > count / 2)
    //             break;
    //     }
    //     return true;
    // }
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        if (x < 10)
            return true;
        int num2 = x;
        long long num1 = 0;
        while (num2 > 0)
        {
            num1 *= 10;
            num1 += (num2 % 10);
            num2 /= 10;
        }
        return x == num1;
    }
};
// @lc code=end
