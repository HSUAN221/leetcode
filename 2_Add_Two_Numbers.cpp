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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto dummy = new ListNode(-1);
        auto curr = dummy;
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr) {
            int num1 = (l1 == nullptr ? 0 : l1->val);
            int num2 = (l2 == nullptr ? 0 : l2->val);
            // std::cout << num1 << " " << num2 << std::endl;

            int sum = num1 + num2 + carry;
            curr->next = new ListNode(sum % 10);
            carry = sum / 10;

            if (l1 != nullptr)
                l1 = l1->next;
            if (l2 != nullptr)
                l2 = l2->next;
            curr = curr->next;
        }
        if (carry != 0) {
            curr->next = new ListNode(carry);
        }
        return dummy->next;
    }
};
