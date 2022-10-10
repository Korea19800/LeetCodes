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
    ListNode *removeElements(ListNode *head, int val) {
	ListNode **list = &head;

	while (*list != nullptr) {
		if ((*list)->val == val) {
		    // You can free `*list` here if you know how it is allocated.
			*list = (*list)->next;
		} else {
			list = &(*list)->next;
		}
	}

	return head;
}
};
