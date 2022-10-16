class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* &head, int n) {
        if( head == NULL || head -> next == NULL){
            return NULL;
        }
        
        int length = 0;
        ListNode* temp = head;

        while( temp != NULL){
            length++;
            temp = temp -> next;
        }        
        
        if( n == length ){
            ListNode* temp2 = head;
            head = head -> next;
            delete temp2;
            temp2 = NULL;
        }else{
            ListNode* prev = head; 
            ListNode* temp2 = NULL;
            
            // temp 의 위치는 head가 length - n 만큼 이동한 위치이니까 prev 는 여기서 하나 더빼줌
            for( int i = 0; i < length - n - 1; i++){
                prev = prev -> next;
            }
            temp2 = prev -> next;
        
            prev -> next = temp2 -> next;
            delete temp2;
            temp2 = NULL;
        }
        return head;
    }
};
/* Explanation
First case. when head is NULL or head has only one element > return NULL
Second, I am gonna count the length of linked list. > length variable will store the length of linked list
Third, if-else statement
if( n == length) >> ex. [1,2,3] and remove 3rd >> This means remove the first element >> if n == length we need to remove the first element
>> Remove first element and change head to point secoond element. ( I changed argument *head to * &head) 
else >> temp2 will be pointing to the n th from the end. prev will be pointing to n+1 th from the end. which means prev will be at the front of
temp2.

if head movies length - n nodes, that is the position of temp2 node ex. [1,2,3,4,5,6] and remove 3rd from the end. 
> since head is pointing 1, head should move (6-3) to go to remove 4, which is 3rd from the end.
