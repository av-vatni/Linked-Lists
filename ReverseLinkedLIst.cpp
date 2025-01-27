#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        ;
        this->next = NULL;
    }
};
class LinkedList
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
    // 3.Reverse list without recursion
    void reverseListIteratively(Node *&head)
    {
        Node *prev = NULL;
        Node *current = head;
        Node *forward = NULL;
        // Empty or Single node list:
        if (head == NULL || head->next == NULL)
        {
            printList(head);
        }
        while (current != NULL)
        {
            forward = current->next;
            current->next = prev;
            prev = current;
            current = forward;
        }
        printList(prev);
    }
    // 4.Reverse list with recursion
    void reverseForRecursion(Node* &head, Node* current, Node* prev){
        // Base case
        if(current == NULL){
            head = prev;
            return;
        }
        Node* forward = current->next;
        reverseForRecursion(head, forward, current);
        current->next = prev;
    }
    void reverseWithRecursion(Node* &head){
        Node* current = head;
        Node *prev = NULL;
        reverseForRecursion(head, current, prev);
        printList(head);
    }
};
int main()
{
    LinkedList list;
    int element;
    int choice;

    cout << "Enter the starting node in the list: ";
    cin >> element;
    Node *head = new Node(element);

    do
    {
        cout << "Enter choice: " << endl;
        cout << " 1.Insert an element at any position\n 2.Print the list\n 3.Reverse list with iteration\n 4.Reverse list with recursion\n   Enter 0 to exit the menu" << endl;
        cin >> choice;
        //Switch case for choosen option
        switch (choice)
    {
    case 1:
        int position, element2;
        cout << "Enter Position and Element respectively: ";
        cin >> position >> element2;
        list.insertAtPosition(head, position, element2);
        cout << "Element inserted at position " << position << " Successfully!!" << endl;
        break;
    case 2:
        list.printList(head);
        break;
    case 3:
        list.reverseListIteratively(head);
        cout << "List reversed successfully!! " << endl;
        break;
        case 4:
        list.reverseWithRecursion(head);
        cout << "List reversed successfully!! " << endl;
        break;
    default:
        cout << "Enter a valid choice from given menu😊 " << endl;
        break;
    }
    } while (choice);

    
}