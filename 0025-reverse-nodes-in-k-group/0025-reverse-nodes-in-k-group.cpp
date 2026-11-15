
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
    ListNode* reverseKGroup(ListNode* head, int k) {

        // Step 1: Check if k nodes are available
        ListNode* curr = head;

        for (int i = 0; i < k; i++) {
            if (curr == nullptr) {
                return head;
            }
            curr = curr->next;
        }

        // Step 2: Reverse k nodes
        ListNode* prev = nullptr;
        curr = head;

        for (int i = 0; i < k; i++) {
            ListNode* nextNode = curr->next;

            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        // Step 3: Connect remaining reversed groups
        head->next = reverseKGroup(curr, k);

        // Step 4: Return new head
        return prev;
    }
};
