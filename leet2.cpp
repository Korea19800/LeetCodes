class Solution {
public:
    void addFront(ListNode** head_ref, int n_data){
        ListNode* temp = new ListNode();
        temp -> val = n_data;
        temp -> next = *head_ref;
        *head_ref = temp;
    }

    int linkLength(ListNode* l){
        int count = 0;
        ListNode* temp = l;
        while(temp != NULL){
            temp = temp -> next;
            count++;
        }    
        return count;
    }
    
    int expo(int n){
        int result = 1;
        while(n != 0){
            result *= 10;
            n--;
        }
        return result;
    }
    
    int getNum(ListNode* l){
        int sum = 0;
        ListNode* temp = l;
        int length = linkLength(temp);
        
        while(temp != NULL){
            sum += (temp -> val) * expo( length - 1 );
            temp = temp -> next;
            length--;
        }
        
        return sum;
    }
    
    int revert( int x){
        int rev = 0;
        int rem;
        while( x != 0 ){
            rem = x % 10;
            rev = rev * 10 + rem;
            x /= 10;
        }
        return rev;
    }    
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int n1 = getNum(l1);
        int n2 = getNum(l2);
        int sum = revert(n1) + revert(n2);
        int rev = revert(sum);
        int zero_count = 0;
        
        ListNode* l3 = NULL;
        
        while(sum % 10 == 00){
            zero_count++;
            sum /= 10;
        }

        if( rev == 0){
            addFront( &l3, 0);
            return l3;
        }else{
            while( rev != 0){
                    addFront( &l3, rev % 10 );
                    rev /= 10;
            }  
        }
        for(int i = 0; i < zero_count; i++){
            addFront(&l3,0);
        }
        return l3;
    } 
};
