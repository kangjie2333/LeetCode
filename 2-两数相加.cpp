/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int val1,ListNode* next1 = nullptr)
 *        {
 *              val = val1; next = next1;
 *        }
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(-1);
        ListNode* ptr = head;
        int sum = 0;
        bool carry = false;
        while (l1 != nullptr || l2 != nullptr)
        {
            sum = 0;
            if (l1 != nullptr)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            if (carry)
            {
                sum++;
            }
            ptr->next = new ListNode(sum % 10);
            ptr = ptr->next;
            carry = sum / 10;
        }
        if (carry)
        {
            ptr->next = new ListNode(1);
        }
        return head->next;

    }
};