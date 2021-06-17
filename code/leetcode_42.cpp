/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start

#include <list>
#include <vector>

using namespace std;

class Solution
{
public:
    int trap1(vector<int> &height)
    {
        if (height.size() <= 2)
        {
            return 0;
        }
        vector<int> leftMaxs(height.size(), 0);
        vector<int> rightMaxs(height.size(), 0);

        int leftMax = 0;
        for (int index = 0; index < height.size(); index++)
        {
            leftMax         = max(leftMax, height[index]);
            leftMaxs[index] = leftMax;
        }
        int rifhtMax = 0;
        for (int index = height.size() - 1; index >= 0; index--)
        {
            rifhtMax         = max(rifhtMax, height[index]);
            rightMaxs[index] = rifhtMax;
        }

        int size = 0;
        for (int index = 0; index < height.size(); index++)
        {
            size += min(rightMaxs[index] - height[index], leftMaxs[index] - height[index]);
        }
        return size;
    }

    int trap2(vector<int> &height)
    {
        if (height.size() <= 1)
        {
            return 0;
        }
        list<int> nums;
        nums.push_back(height[0]);
        int size = 0;
        for (int index = 1; index < height.size(); index++)
        {
            int num0 = nums.front();
            if (num0 <= height[index])
            {
                while (nums.size())
                {
                    int num = nums.back();
                    size += (num0 - num);
                    nums.pop_back();
                }
            }
            nums.push_back(height[index]);
        }

        if (nums.size() > 0)
        {
            nums.reverse();
            vector<int> temp(nums.begin(), nums.end());
            size += trap(temp);
        }
        return size;
    }
    
    int trap(vector<int> &height) { return trap1(height); }
};
// @lc code=end
