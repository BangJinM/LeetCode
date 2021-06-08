
/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */

// @lc code=start
class MyLinkedList
{
public:
    struct ListNode
    {
        int       val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    /** Initialize your data structure here. */
    MyLinkedList() { header = new ListNode(-1); }

    ListNode *GetNodeByIndex(int index, bool haveHeader = false)
    {
        if (index < 0 || index > max_size)
            return nullptr;

        ListNode *node = haveHeader ? header : header->next;

        int cur_index = 0;

        while (true)
        {
            if (cur_index == index)
                return node;
            cur_index++;
            node = node->next;
        }
        return nullptr;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index)
    {
        auto node = GetNodeByIndex(index);
        return node ? node->val : -1;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked
     * list. */
    void addAtHead(int val) { addAtIndex(0, val); }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) { addAtIndex(max_size, val); }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended
     * to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val)
    {
        index = index < 0 ? 0 : index;
        index = index > max_size ? max_size : index;

        ListNode *node = GetNodeByIndex(index, true);
        if (node)
        {
            ListNode *temp = new ListNode(val);
            temp->next     = node->next;
            node->next     = temp;
            max_size++;
        }
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index)
    {
        if (index < 0 || index >= max_size)
            return;
        auto preNode  = GetNodeByIndex(index, true);
        preNode->next = preNode->next->next;
        max_size--;
    }

private:
    ListNode *header;
    int       max_size = 0;
};

// class MyLinkedList
// {
// public:
//     struct ListNode
//     {
//         int       val;
//         ListNode *next;
//         ListNode() : val(0), next(nullptr) {}
//         ListNode(int x) : val(x), next(nullptr) {}
//         ListNode(int x, ListNode *next) : val(x), next(next) {}
//     };

//     /** Initialize your data structure here. */
//     MyLinkedList() { header = new ListNode(-1); }

//     ListNode *GetNodeByIndex(int index, bool haveHeader = false)
//     {
//         if (index < 0 || index > max_size)
//             return nullptr;

//         ListNode *node      = haveHeader ? header : header->next;
//         int       cur_index = 0;

//         while (true)
//         {
//             if (cur_index == index)
//                 return node;
//             cur_index++;
//             node = node->next;
//         }
//         return nullptr;
//     }

//     /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
//     int get(int index)
//     {
//         auto node = GetNodeByIndex(index);
//         return node ? node->val : -1;
//     }

//     /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked
//      * list. */
//     void addAtHead(int val)
//     {
//         ListNode *node = new ListNode(val);
//         node->next     = header->next;
//         header->next   = node;
//         max_size++;
//     }

//     /** Append a node of value val to the last element of the linked list. */
//     void addAtTail(int val)
//     {
//         if(max_size ==0)
//             addAtHead(val);
//         ListNode *node = GetNodeByIndex(max_size - 1);
//         if (node)
//         {
//             ListNode *temp = new ListNode(val);
//             node->next     = temp;
//             max_size++;
//         }
//     }

//     /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be
//     appended
//      * to the end of linked list. If index is greater than the length, the node will not be inserted. */
//     void addAtIndex(int index, int val)
//     {
//         auto preNode = GetNodeByIndex(index, true);
//         if (preNode)
//         {
//             ListNode *node = new ListNode(val);
//             node->next     = preNode->next;
//             preNode->next  = node;
//             max_size++;
//         }
//     }

//     /** Delete the index-th node in the linked list, if the index is valid. */
//     void deleteAtIndex(int index)
//     {
//         if (index < 0 || index >= max_size)
//             return;
//         auto preNode  = GetNodeByIndex(index, true);
//         preNode->next = preNode->next->next;
//         max_size--;
//     }

// private:
//     ListNode *header;
//     int       max_size = 0;
// };

// /**
//  * Your MyLinkedList object will be instantiated and called as such:
//  * MyLinkedList* obj = new MyLinkedList();
//  * int param_1 = obj->get(index);
//  * obj->addAtHead(val);
//  * obj->addAtTail(val);
//  * obj->addAtIndex(index,val);
//  * obj->deleteAtIndex(index);
//  */

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end
