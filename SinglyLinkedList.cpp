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
    // 1.2 Insert at given position
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
    // 1.3 Insert at End(Using only head pointer)
    void insertAtEnd(Node *&head, int data)
    {
        Node *newNode = new Node(data);
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
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
    // 3.Delete node
    void deleteNode(int position, Node *&head)
    {
        Node *temp = head;
        if (position == 1 || position == 0)
        {
            head = head->next;
        }else{
            for (int i = 1; i < position - 1; i++)
        {
            temp = temp->next;
        }
        temp->next = (temp->next)->next;
        }
        
    }
};

int main()
{
    LinkedList list;

    Node *head = new Node(5);
    // cout << node->data;
    // cout << "Hello AV" << std::endl;

    // 1.INSERT:
    // 1.1 Insert at begin:
    // list.printList(head);

    // list.insertAtBegin(head, 25);
    // list.printList(head);

    // 1.2 Insert at given position:
    list.printList(head);

    list.insertAtPosition(head, 2, 25);
    list.printList(head);

    list.insertAtPosition(head, 3, 125);
    list.printList(head);

    list.insertAtPosition(head, 1, 625);
    list.printList(head);

    // 1.3 Insert at End (using head):
    // list.printList(head);

    // list.insertAtEnd(head, 25);
    // list.printList(head);

    // 3. Deleting a Node
    cout << "After deleting: " << endl;
    list.deleteNode(1, head);
    list.printList(head);

    return 0;
}