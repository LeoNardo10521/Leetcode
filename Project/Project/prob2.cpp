/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


//version 1.0
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *Node1,*Node2, *Nodetmp, *NodeNext,*NodeNew;
        int carry = 0;
        int tmp;
        Node1 = l1;
        Node2 = l2;
        NodeNew = new ListNode(0);
        Nodetmp = NodeNew;
        int val1,val2;
        while (Node1 != NULL || Node2 != NULL){
            val1 =0; val2 = 0;
            if (Node1!= NULL) {val1 = Node1->val; Node1 = Node1->next;}
            if (Node2!= NULL) {val2 = Node2->val;Node2 = Node2->next;}
            tmp = val1+val2 + carry;
            if (tmp>9) {carry = 1;tmp %=10;}
            else carry = 0;
            NodeNext = new ListNode(tmp);
            Nodetmp->next = NodeNext;
            
            Nodetmp = NodeNext;
           
            
        }
        
        if (carry == 1 ) Nodetmp->next = new ListNode(1);
        return NodeNew->next;
    }
};

//version2.0
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *Node1,*Node2, *Nodetmp,*NodeNew;
        int carry = 0;
        int tmp;
        Node1 = l1;
        Node2 = l2;
        NodeNew = new ListNode(0);
        Nodetmp = NodeNew;
        int val1,val2;
        while (Node1|| Node2 || carry ){
            val1 =0; val2 = 0;
            if (Node1) {val1 = Node1->val; Node1 = Node1->next;}
            if (Node2) {val2 = Node2->val;Node2 = Node2->next;}
            tmp = val1+val2 + carry;
            carry = tmp /10;
            Nodetmp->next = new ListNode(tmp % 10);
            Nodetmp = Nodetmp->next;
        }
        return NodeNew->next;
    }
};



//Answers
class Solution {
    
public:
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode preHead(0), *p = &preHead;
    int extra = 0;
    while (l1 || l2 || extra) {
        if (l1) extra += l1->val, l1 = l1->next;
        if (l2) extra += l2->val, l2 = l2->next;
        p->next = new ListNode(extra % 10);
        extra /= 10;
        p = p->next;
    }
    return preHead.next;
}
};