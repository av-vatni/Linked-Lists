#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    // Constructor to initialize the node
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
class LinkedList
{
public:
    // 1. INSERT
    // 1.1 Insert at Begining
    void insertAtBegin(Node *&head, int data)
    {
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
    }
    void insertAtPosition(Node *&head, int position, int data)
    {
        Node *newNode = new Node(data);
        Node *temp = head;
        if (position == 1 || position == 0)
        {
            insertAtBegin(head, data);
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

    // 2. Print/Read list
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
    // 3. Reverse the linked list in K groups.
    Node *reverseInKgrp(Node *&head, int k)
    {
        // Base case
        if (head == NULL)
        {
            return NULL;
        }

        // 1. Reversed first k nodes

        Node *prev = NULL;
        Node *curr = head;
        Node *next = NULL;
        int cnt = 0;

        while (curr != NULL && cnt < k)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            cnt++;
        }
        // 2. Recursion
        if (next != NULL)
        {
            head->next = reverseInKgrp(next, k);
        }
        // 3.Return the list!!
        return prev;
    }
};

int main(){
    Node* head = new Node(15);
    LinkedList list;
    list.insertAtPosition(head, 2, 30);
    list.insertAtPosition(head, 3, 45);
    list.insertAtPosition(head, 4, 60);
    list.insertAtPosition(head, 5, 75);
    list.printList(head);
    cout<<"List after reversed in group of 3: "<<endl;
    Node* prev = list.reverseInKgrp(head, 3);
    list.printList(prev);
}
