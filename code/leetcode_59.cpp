/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        int                 count = n * n;
        vector<vector<int>> nums(n);

        for (int i = 0; i < n; i++)
        {
            vector<int> numTemp(n);
            nums[i] = numTemp;
        }

        int num = 0;
        for (int i = 0; i < n; i++)
        {
            nums[0][i] = ++num;
        }

        bool dir = true;

        int max = n - 1;

        int row = n - 1;
        int col = 1;

        while (max > 0)
        {
            int index = 0;
            while (index < max)
            {
                nums[col][row] = ++num;
                if (index + 1 >= max)
                    break;
                if (dir)
                    col++;
                else if (!dir)
                    col--;
                index++;
            }
            index = 0;
            if (dir)
                row--;
            else
                row++;
            while (index < max)
            {
                nums[col][row] = ++num;
                if (index + 1 >= max)
                    break;
                if (dir)
                    row--;
                else
                    row++;
                index++;
            }
            if (dir)
                col--;
            else
                col++;

            dir = !dir;
            max--;
        }

        return nums;
    }

    vector<vector<int>> generateMatrix2(int n)
    {
        int                 maxNum = n * n;
        int                 curNum = 1;
        vector<vector<int>> matrix(n, vector<int>(n));
        int                 row = 0, column = 0;
        vector<vector<int>> directions     = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};  // 右下左上
        int                 directionIndex = 0;
        while (curNum <= maxNum)
        {
            matrix[row][column] = curNum;
            curNum++;
            int nextRow    = row + directions[directionIndex][0];
            int nextColumn = column + directions[directionIndex][1];
            if (nextRow < 0 || nextRow >= n || nextColumn < 0 || nextColumn >= n || matrix[nextRow][nextColumn] != 0)
            {
                directionIndex = (directionIndex + 1) % 4;  // 顺时针旋转至下一个方向
            }
            row    = row + directions[directionIndex][0];
            column = column + directions[directionIndex][1];
        }
        return matrix;
    }

    vector<vector<int>> generateMatrix3(int n)
    {
        int                 num = 1;
        vector<vector<int>> matrix(n, vector<int>(n));
        int                 left = 0, right = n - 1, top = 0, bottom = n - 1;
        while (left <= right && top <= bottom)
        {
            for (int column = left; column <= right; column++)
            {
                matrix[top][column] = num;
                num++;
            }
            for (int row = top + 1; row <= bottom; row++)
            {
                matrix[row][right] = num;
                num++;
            }
            if (left < right && top < bottom)
            {
                for (int column = right - 1; column > left; column--)
                {
                    matrix[bottom][column] = num;
                    num++;
                }
                for (int row = bottom; row > top; row--)
                {
                    matrix[row][left] = num;
                    num++;
                }
            }
            left++;
            right--;
            top++;
            bottom--;
        }
        return matrix;
    }
};
// @lc code=end

// 1  2  3  4  5

// 16 17 18 19 6

// 15 24 25 20 7

// 14 23 22 21 8

// 13 12 11 10 9

// 1  2  3  4
// 12 13 14 5
// 11 16 15 6
// 10 9  8  7

// [[1,2,3],
//  [8,9,4],
//  [7,6,5]]
