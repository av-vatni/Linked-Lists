#include <iostream>
#include <map>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
class List
{
public:
    // 1. INSERT
    void insertAtPosition(Node *&head, int position, int data)
    {
        Node *newNode = new Node(data);
        Node *temp = head;
        if (position == 0 || position == 1)
        {
            newNode->next = temp;
            head = newNode;
        }
        else
        {
            for (int i = 1; i < position - 1; i++)
            {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
    // 2. PRINT
    void printList(Node *&head)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    Node *reverse(Node *head)
    {
        Node *curr = head;
        Node *next = NULL;
        Node *prev = NULL;

        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    void insertAtTail(Node *&head, Node *&tail, int data)
    {
        Node* temp = new Node(data);
        if(head == NULL){
            head = temp;
            tail = temp;
            return;
        }else{
            tail->next = temp;
            tail =temp;
        }
    }
    Node *add(Node *first, Node *second)
    {
        Node* ansHead = NULL;
        Node* ansTail = NULL;
        int carry = 0;
        while (first != NULL || second != NULL || carry != 0)
        {
            int val1 = 0;
            if(first != NULL){
                val1 = first->data;
            }

            int val2 = 0;
            if(second != NULL){
                val2 = second->data;
            }

            int sum = carry + val1 + val2;
            int digit = sum % 10;

            insertAtTail(ansHead, ansTail, digit);

            carry = sum / 10;
            if(first != NULL){
                first = first->next;
            }
            if(second != NULL){
                second = second->next;
            }
        }
        
        return ansHead;
    }
    Node *addTwoLists(Node *first, Node *second)
    {
        // 1. Reverse the linked lists
        first = reverse(first);
        second = reverse(second);
        // 2. Add 2 lists
        Node *ans = add(first, second);
        // 3. Reverse the answer
        ans = reverse(ans);
    }
};
int main()
{
    cout << "Finding middle of the linked list" << endl;
    List list;
    
    Node *head = new Node(4);
    list.insertAtPosition(head, 2, 5);
    list.printList(head);

    Node *head2 = new Node(1);
    list.insertAtPosition(head2, 2, 0);
    list.insertAtPosition(head2, 3, 0);
    list.printList(head2);

    Node* answer = list.addTwoLists(head, head2);
    list.printList(answer);

}