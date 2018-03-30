#include<iostream>
using namespace std;
#include<vector>
#include<queue>

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };


 class Solution {
 public:
	 ListNode* mergeKLists(vector<ListNode*>& lists) {
		 ListNode *head = new ListNode(0);
		 ListNode *cur = head;
		 struct cmp1 {
			 bool operator()(const ListNode  *a, const ListNode *b) {
				 return a->val> b->val;
			 }
		 };

		priority_queue<ListNode *, vector<ListNode *>, cmp1> q;
		for (int i = 0; i<lists.size(); i++) if (lists[i] != NULL) q.push(lists[i]);
		 while (!q.empty()) {
			 ListNode * t = q.top();
			 cur->next = new ListNode(t->val);
			 cur = cur->next;
			 q.pop();
			 if (t->next != NULL)
				 q.push(t->next);
		 }
		 return head->next;

	 }
 };

int main() {
	Solution s;
	ListNode a(1);
	ListNode *head;
	head = &a;
	vector<ListNode *> list;
	list.push_back(head);
	cout << s.mergeKLists(list);
}