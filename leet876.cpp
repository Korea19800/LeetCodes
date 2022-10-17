class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* one = head;
        ListNode* two = head;
        
        while( two -> next != NULL){
            one = one -> next;
            two = two -> next;
            if( two -> next != NULL){
                two = two -> next;
            }
        }
        return one;
    }
};
// One == Poiner that moves one at a time.
// Two == Pointer that moves two at a time.
// When Two arrives at the end of the list, one should be at the middle of the list
