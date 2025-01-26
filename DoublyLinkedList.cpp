#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

class DoublyList
{
public:
    // 1.INSERT
    // 1.1 INSERT AT BEGINING
    void insertAtBegin(Node *&head, int data)
    {
        if (head == NULL)
        {
            Node *newNode = new Node(data);
            head = newNode;
        }
        else
        {
            Node *newNode = new Node(data);
            Node *temp = head;
            newNode->next = temp;
            head = newNode;
        }
    }

    // 1.2 INSERT AT Given Position
    void insertAtPosition(Node *&head, int position, int data)
    {
        Node *newNode = new Node(data);
        Node *temp = head;

        if (position == 0 || position == 1)
        {
            insertAtBegin(head, data);
        }
        else
        {
            for (int i = 1; i < position - 1; i++)
            {
                temp = temp->next;
            }
            newNode->prev = temp;
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    // 1.3 INSERT AT END
    void insertAtEnd(Node *&head, int data)
    {
        Node *newNode = new Node(data);
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        newNode->prev = temp;
        temp->next = newNode;
    }

    // 2. Printing the List
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

    // 3. DELETE NODE
    void deleteNode(Node *&head, int position)
    {
        Node *temp = head;
        if (position == 0 || position == 1)
        {
            head = head->next;
            (head->next)->prev = NULL;
        }
        else
        {
            for (int i = 1; i < position - 1; i++)
            {
                temp = temp->next;
            }
            if ((temp->next)->next == NULL)
            {
                temp->next = NULL;
            }
            else
            {
                temp->next = (temp->next)->next;
                (temp->next)->prev = temp;
            }
        }
    }
};

int main()
{
    cout << "Starting the code of Doubly linked list and its operations!!" << endl;

    Node *head = new Node(5);

    DoublyList list;

    // 1.INSERT
    // 1.1 INSERT AT BEGINING
    // list.insertAtBegin(head, 25);
    // list.printList(head);

    // list.insertAtBegin(head, 125);
    // list.printList(head);

    // 1.2 INSERT AT Given Position
    // list.insertAtPosition(head, 2, 125);
    // list.printList(head);

    // list.insertAtPosition(head, 1, 625);
    // list.printList(head);

    // list.insertAtPosition(head, 4, 3125);
    // list.printList(head);

    // 1.3 INSERT AT END
    list.insertAtEnd(head, 25);
    list.printList(head);

    list.insertAtEnd(head, 125);
    list.printList(head);

    list.insertAtEnd(head, 225);
    list.printList(head);

    list.insertAtEnd(head, 325);
    list.printList(head);

    // 3.DELETE
    cout << "After deleting " << endl;
    list.deleteNode(head, 1);
    list.printList(head);
}