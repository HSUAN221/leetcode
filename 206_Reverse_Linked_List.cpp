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
    ListNode* reverseList(ListNode* head) {
        // if (!head) return nullptr;
        // ListNode* buffer = nullptr;
        // ListNode* h = head;
        // std::map<ListNode*, ListNode*> map;
        // while (head) {
        //     map[head] = buffer;
        //     buffer = head;
        //     head = head->next;
        // }
        // for (auto& iter : map) {
        //     iter.first->next = iter.second;
        // }
        // return (--map.end())->first;

        ListNode* buffer = nullptr;
        while (head) {
            auto next = head->next;
            head->next = buffer;
            buffer = head;
            head = next;
        }
        return buffer;
    }
};
