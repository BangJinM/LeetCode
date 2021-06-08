/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode
{
    int       val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        ListNode *tempHead = new ListNode(-1);
        tempHead->next     = head;

        ListNode *node   = tempHead;
        ListNode *first  = node->next;
        ListNode *second = first->next;

        while (node->next && node->next->next)
        {
            first  = node->next;
            second = first->next;

            first->next  = second->next;
            node->next   = second;
            second->next = first;

            node = first;
        }
        return tempHead->next;
    }
};
// @lc code=end
