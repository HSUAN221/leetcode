/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }
        std::map<Node*, Node*> curr_result_map;
        Node* curr = head;
        while (curr != nullptr) {
            Node* temp = new Node(curr->val);
            // only deep copy node's val
            curr_result_map[curr] = temp;
            curr = curr->next;
        }
        curr = head;
        while (curr != nullptr) {
            // deal with all nodes' ptr by map
            curr_result_map[curr]->next = curr_result_map[curr->next];
            curr_result_map[curr]->random = curr_result_map[curr->random];
            curr = curr->next;
        }
        return curr_result_map[head];
    }
};
