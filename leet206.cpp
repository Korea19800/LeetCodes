// This was my first code
// Let's fix the error
class Solution {
public:
    void addFront(ListNode** head_ref, int n){
        ListNode* temp = new ListNode();
        temp -> val = n;
        temp -> next = *head_ref;
        *head_ref = temp;
        return;
    }
    
    void addEnd(ListNode** head_ref, int new_data){ 
        ListNode* new_node = new ListNode();
        ListNode *last = *head_ref;
        new_node -> val = new_data; 
        new_node -> next = NULL; 
        
        if (*head_ref == NULL) 
        { 
            *head_ref = new_node; 
            return; 
        } 
   
       while (last->next != NULL)
        {
            last = last->next; 
        }

        last->next = new_node; 
        return; 
    } 
    
    void goBack(ListNode *head, ListNode** h2){
        if( head == NULL ){
            return;
        }
        while( head != NULL){
            goBack( head -> next, h2);
            addEnd(h2, head -> val);
            return;
        }
    }
    
    ListNode* reverseList(ListNode* head) {
        if (head == NULL){
            return head;
        }
        ListNode* h2 = NULL;
        
        goBack(head, &h2);
        
        return head;   
    }
};
