/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        std::unordered_set<ListNode*> visited;
        while (head) {
            if (visited.count(head)) {
                return true;
            }
            visited.insert(head);
            head = head->next;
        }
        return false;
    }
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        auto fast = head;
        auto slow = head;
        while (fast) {
            if (!fast->next) return false;
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast) return true;
        }
        return false;
    }
};
