/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int       index   = 0;
        ListNode *newHead = new ListNode(0);
        newHead->next     = head;

        ListNode *preNode = nullptr;
        ListNode *node    = newHead;

        while (node)
        {
            index++;
            if (index > n)
            {
                if (!preNode)
                {
                    preNode = newHead;
                }
                else
                {
                    preNode = preNode->next;
                }
            }
            node = node->next;
        }
        if (preNode && preNode->next)
            preNode->next = preNode->next->next;
        return newHead->next;
    }
};
// @lc code=end
