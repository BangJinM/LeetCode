
#include <string>
#include <vector>
#include "code/leetcode_209.cpp"
using namespace std;
int main()
{
    std::vector<int> nums = {5,1,3,5,10,7,4,9,2,8};

    Solution solution;
    auto     str = solution.minSubArrayLen(15, nums);

    return 0;
}