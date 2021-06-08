
#include <string>
#include <vector>
#include "code/leetcode_24.cpp"
using namespace std;

ListNode *createNodeByVector(vector<int> nums)
{
    ListNode *head = new ListNode(nums[0]);
    ListNode *pre  = head;
    for (int i = 1; i < nums.size(); i++)
    {
        ListNode *node = new ListNode(nums[i]);
        pre->next      = node;
        pre            = node;
    }
    return head;
}

int main()
{
    auto nums = createNodeByVector({1, 2, 3, 4, 5});
    Solution solution;
    solution.swapPairs(nums);

    return 0;
}
