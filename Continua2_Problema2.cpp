#include <iostream>

/**************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

***************************/

#include <iostream>
/*

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode (int x) : val(x), next(nullptr){}
    ListNode (int x, ListNode *next) : val(x), next(next){}

    class Solution {
    public:
        ListNode* solucion(ListNode* head, int x){

            ListNode* temp = head;

            ListNode Low = ListNode(0);

            ListNode High = ListNode(0);

            ListNode* temp1 = High.next;
            ListNode* temp2 = Low.next;

            while(temp != nullptr){
                if(temp->val < x){
                    Low.next = temp;
                }
                else{
                    High.next = temp;
                }
                temp = temp -> next;
            }

            while(temp2 != nullptr) {
                temp2 = temp2 -> next;
            }
            temp1->next = temp2;

            return head;

        }
    };
};


int main() {
    ListNode* head;
    head = new ListNode(1);
    head -> next = new ListNode(2);
    head -> next -> next = new ListNode(2);
    head -> next -> next -> next = new ListNode(4);
    head -> next -> next -> next -> next -> next = new ListNode(3);
    head -> next -> next -> next -> next -> next -> next = new ListNode(5);

    int x = 3;
    ListNode * solucion(ListNode *head, int x);
}
*/