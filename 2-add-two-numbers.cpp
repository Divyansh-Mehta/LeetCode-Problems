#include <iostream>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int val)
    {
        this->val = val;
        next = NULL;
    }
};

ListNode *input()
{
    ListNode *head = NULL, *tail = NULL;
    int n;
    cin >> n;
    while (n != -1)
    {
        if (head == NULL)
        {
            head = new ListNode(n);
            tail = head;
        }
        else
        {
            tail->next = new ListNode(n);
            tail = tail->next;
        }
        cin >> n;
    }
    return head;
}

void print(ListNode *head)
{
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *ans = NULL, *temp = NULL;
        int carry = 0;
        while (l1 != NULL || l2 != NULL)
        {
            int x = (l1 != NULL) ? l1->val : 0;
            int y = (l2 != NULL) ? l2->val : 0;
            int sum = x + y + carry;
            carry = sum / 10;

            if (ans == NULL)
            {
                temp = new ListNode(sum % 10);
                ans = temp;
            }
            else
            {
                temp->next = new ListNode(sum % 10);
                temp = temp->next;
            }

            if (l1 != NULL)
            {
                l1 = l1->next;
            }
            if (l2 != NULL)
            {
                l2 = l2->next;
            }
        }

        if (carry != 0)
        {
            temp->next = new ListNode(carry);
        }
        return ans;
    }
};

int main()
{
    //-1 will terminate taking input
    //9 9 9 9 -1 will input linkedList as 9 9 9 9
    ListNode *l1 = input(), *l2 = input();
    Solution sol;
    ListNode *result = sol.addTwoNumbers(l1, l2);
    print(result);

    return 0;
}