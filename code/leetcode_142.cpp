/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode
{
    int       val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *slow = head;
        if (!slow)
            return nullptr;
        ListNode *fast = slow->next;
        if (!fast)
            return nullptr;

        while (fast != slow)
        {
            if (fast == nullptr)
                return nullptr;
            slow = slow->next;
            fast = fast->next ? fast->next->next : nullptr;
        }
        ListNode *ptr = head;
        while (ptr != slow)
        {
            ptr  = ptr->next;
            slow = slow->next;
        }
        return ptr;
    }

    // n * t = 4
    // head + x * t = 4
    // head + y * t = 8
};
// @lc code=end
