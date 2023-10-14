/**
 * Definition for singly-linked list.
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    // time complexity: O(n)
    // memory complexity: O(1)
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        /* Add two numbers given as linked lists (head is ones) */
        short carry = 0;
        ListNode *sum = new ListNode(), *temp = sum;

        while (true)
        {
            if (l1 == nullptr && l2 == nullptr) // check if end of lists
                break;

            if (l1)
            {
                temp->val += l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                temp->val += l2->val;
                l2 = l2->next;
            }

            temp->val += carry; // add carry from last addition
            if (temp->val > 9)
            { // calculate new carry if needed
                carry = temp->val / 10;
                temp->val -= carry * 10;
            }
            else
                carry = 0;

            if (l1 || l2 || carry)
            { // if the addition is not complete
                temp->next = new ListNode();
                temp = temp->next;
            }
            else
                break;
        }
        temp->val += carry; // add final carry
        return sum;
    }
};