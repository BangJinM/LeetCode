/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    // string convert(string s, int numRows)
    // {
    //     int sSize = s.size();
    //     if (sSize <= numRows || numRows <= 1)
    //         return s;
    //     string result = "";

    //     int t1     = sSize / (2 * numRows - 2);
    //     int t2     = sSize % (2 * numRows - 2);
    //     int maxCol = t1 * (numRows - 1);

    //     if (t2 > 0)
    //         maxCol += (t2 - numRows > 0) ? (t2 - numRows) + 1 : 1;

    //     vector<int> pos(numRows * maxCol, -1);
    //     for (int index = 0; index < sSize; index++)
    //     {
    //         int tt   = index / (2 * numRows - 2);
    //         int temp = index % (2 * numRows - 2);

    //         int y = (temp + 1 - numRows > 0 ? numRows - (temp + 1 - numRows) - 1 : temp);

    //         int x = tt * (numRows - 1);
    //         if (temp > 0)
    //             x += (temp + 1 - numRows > 0) ? (temp + 1 - numRows) : 0;

    //         pos[y * maxCol + x] = index;
    //     }
    //     for (size_t i = 0; i < pos.size(); i++)
    //     {
    //         if (pos[i] >= 0)
    //             result += s[pos[i]];
    //     }
    //     return result;
    // }

    void AddString(string &result, int index, int max, string &s)
    {
        if (index < max)
            result += s[index];
    }

    string convert(string s, int numRows)
    {
        int sSize = s.size();
        if (sSize <= numRows || numRows <= 1)
            return s;
        string result = "";

        int t1 = sSize / (2 * numRows - 2);
        int t2 = sSize % (2 * numRows - 2);

        if (t2 > 0)
            t1++;

        int maxSize = s.size();

        for (size_t index = 0; index < numRows; index++)
        {
            for (size_t i = 0; i < t1; i++)
            {
                int strIndex = i * (2 * numRows - 2);
                if (index == 0 || index == numRows - 1)
                {
                    AddString(result, strIndex + index, maxSize, s);
                }
                else
                {
                    AddString(result, strIndex + index, maxSize, s);
                    AddString(result, strIndex + 2 * numRows - 2 - index, maxSize, s);
                }
            }
        }

        return result;
    }
};
// @lc code=end
