/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target, int beginIndex, int endIndex)
    {
        if (nums[beginIndex] == target)
            return beginIndex;
        if (nums[endIndex] == target)
            return endIndex;
        int middle = (beginIndex + endIndex) / 2;
        if (middle == beginIndex || middle == endIndex)
        {
            return -1;
        }
        if (nums[middle] > target)
            return search(nums, target, beginIndex + 1, middle - 1);
        else if (nums[middle] < target)
            return search(nums, target, middle + 1, endIndex - 1);
        else if (nums[middle] == target)
            return middle;
        return -1;
    }

    int search(vector<int> &nums, int target)
    {
        int beginIndex = 0;
        int endIndex   = nums.size() - 1;
        return search(nums, target, beginIndex, endIndex);
    }
};
// @lc code=end
