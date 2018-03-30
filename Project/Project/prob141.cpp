//My Solution

class Solution {
public:
    bool hasCycle(ListNode *head) {
        set<ListNode *> record;
        while (head != NULL ) {
            if (record.count(head)== 0) {
                record.insert(head); 
                head = head->next;
            }
            else return 1;
        }
        return 0;
    }
};