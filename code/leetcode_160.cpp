/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
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
    // ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    // {
    //     if (!headA || !headB)
    //         return nullptr;

    //     ListNode *listA = headA;
    //     ListNode *listB = headB;
    //     int       count = 0;

    //     bool isA = true;
    //     while (listA || listB)
    //     {
    //         if (!listA)
    //         {
    //             count++;
    //             isA = true;
    //         }
    //         else
    //             listA = listA->next;
    //         if (!listB)
    //         {
    //             count++;
    //             isA = false;
    //         }
    //         else
    //             listB = listB->next;
    //     }

    //     listA = headA;
    //     listB = headB;

    //     while (count)
    //     {
    //         if (isA)
    //             listB = listB->next;
    //         else
    //             listA = listA->next;
    //         count--;
    //     }

    //     while (listA && listB)
    //     {
    //         if (listA == listB)
    //             return listA;
    //         listA = listA->next;
    //         listB = listB->next;
    //     }
    //     return nullptr;
    // }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (!headA || !headB)
            return nullptr;

        ListNode *listA = headA;
        ListNode *listB = headB;

        while (listA != listB)
        {
            listA = listA == nullptr ? headB : listA->next;
            listB = listB == nullptr ? headA : listB->next;
        }
        return listA;
    }
};
// @lc code=end
