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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* list_node_result = new ListNode();
        ListNode* head = list_node_result;
        int carry = 0;
        // The order of if - else if is important!!!
        // while will stop when 
        // l1==nullptr && l2==nullptr && carry==0
        while(l1 != nullptr || l2 != nullptr ||carry != 0){
            if(l1 == nullptr && l2 == nullptr){
                list_node_result->val = carry;
            }else if(l1 == nullptr){
                list_node_result->val = l2->val+carry;
                l2 = l2->next;
            }else if(l2 == nullptr){
                list_node_result->val = l1->val+carry;
                l1 = l1->next;
            }else{
                list_node_result->val = l1->val + l2->val + carry;
                l1 = l1->next;
                l2 = l2->next;
            }
            
            if(list_node_result->val >= 10) {
                list_node_result->val %= 10;
                carry = 1;
            }
            else carry = 0;
            
            if(l1==nullptr && l2==nullptr && carry==0) break;
            
            // important
            list_node_result->next = new ListNode();
            list_node_result = list_node_result->next;
        }
        
        return head;
    }
};