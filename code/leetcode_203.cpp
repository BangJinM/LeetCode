/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
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
    ListNode *removeElements(ListNode *head, int val)
    {

        ListNode *newHead = new ListNode(0);
        newHead->next     = head;

        ListNode *node = newHead;

        while (node)
        {
            auto tempNode = node->next;
            if (!tempNode)
                break;
            if (tempNode->val == val)
            {
                node->next = tempNode->next;
            }
            else
            {
                node = node->next;
            }
        }
        return newHead->next;
    }
};
// @lc code=end
