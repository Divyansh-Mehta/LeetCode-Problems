#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//Time - O(n) Space - O(1)
class Solution1 {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *smallHead = NULL, *smallTail = NULL;
        ListNode *largeHead = NULL, *largeTail = NULL;
        ListNode *temp = head;
        
        while (temp != NULL){
            if (temp -> val < x){
                if (smallHead == NULL){
                    smallHead = temp;
                    smallTail = temp;
                }
                else{
                    smallTail -> next = temp;
                    smallTail = temp;
                }
            }
            else{
                 if (largeHead == NULL){
                    largeHead = temp;
                    largeTail = temp;
                }
                else{
                    largeTail -> next = temp;
                    largeTail = temp;
                }
            }
            temp = temp -> next;
        }
        if (smallHead == NULL){
            return largeHead;
        }
        if (largeHead == NULL){
            return smallHead;
        }
        largeTail -> next = NULL;
        smallTail -> next = largeHead;
        return smallHead;
    }
};


//To reduce if conditions in the while loop we can use dummy node as follows:-
class Solution2 {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *smallHead = new ListNode(0), *smallTail = smallHead;
        ListNode *largeHead = new ListNode(0), *largeTail = largeHead;
        ListNode *temp = head;
        
        while (temp != NULL){
            if (temp -> val < x){
                smallTail -> next = temp;
                smallTail = temp;
            }
            else{
                largeTail -> next = temp;
                largeTail = temp;
            }
            temp = temp -> next;
        }
        if (smallHead -> next == NULL){
            return largeHead -> next;
        }
        if (largeHead -> next == NULL){
            return smallHead -> next;
        }
        largeTail -> next = NULL;
        smallTail -> next = largeHead -> next;
        return smallHead -> next;
    }
};

ListNode* createLL(){
    ListNode *head = new ListNode(0), *tail = head;
    int val;
    cin >> val;
    while(val != -1){
        ListNode *newNode = new ListNode(val);
        tail -> next = newNode;
        tail = newNode;
        cin >> val;
    }

    return head -> next;
}

void print(ListNode *head){
    while (head != NULL){
        cout << head -> val << " ";
        head = head -> next;
    }
    cout << endl;
}

int main(){
    ListNode *head = createLL();
    int x;
    cin >> x;
    Solution2 S;
    print(head);
    head = S.partition(head, x);
    print(head);
}
