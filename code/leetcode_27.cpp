/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution
{
public:
    // int removeElement(vector<int> &nums, int val)
    // {
    // for (int index = nums.size() - 1; index >= 0; index--)
    // {
    //     if(nums[index] == val)
    //     {
    //         nums.erase(nums.begin()+index);
    //     }
    // }
    // return nums.size();
    // }

    int removeElement(vector<int> &nums, int val)
    {
        int index = 0;
        int size  = nums.size() - 1;
        while (index <= size)
        {
            if (nums[index] == val)
            {
                int temp    = nums[index];
                nums[index] = nums[size];
                nums[size]  = temp;
                size--;
            }
            else
            {
                index++;
            }
        }
        return size - 1;
    }
};
// @lc code=end
