// Detect and Remove duplicates from sorted and Unsorted linked list
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
    // 3. Length of list
    int lengthOfList(Node *&head)
    {
        Node *temp = head;
        int cnt = 0;
        while (temp != NULL)
        {
            temp = temp->next;
            cnt++;
        }
        return cnt;
    }
    // 4. Removing duplicates from sorted list
    Node *uniqueInSorted(Node *head)
    {
        if (head == NULL)
        {
            return NULL;
        }
        Node *current = head;
        while (current != NULL)
        {
            if (current->next != NULL && current->data == current->next->data)
            {
                Node *nextToNext = (current->next)->next;
                Node *nodeToDelete = current->next;
                delete (nodeToDelete);
                current->next = nextToNext;
            }
            else
            {
                current = current->next;
            }
        }
        return head;
    }
    Node *uniqueInUnsorted(Node *head)
    {
        Node* temp = head;
        Node* prev = NULL;
        map<int, bool> visited;
        while (temp != NULL)
        {
            if (visited[temp->data])
            {
                prev->next = temp->next;
                delete (temp);
                temp = prev->next;
                
            }
            else
            {
                visited[temp->data] = true;
                prev = temp;
                temp = temp->next;
            }
        }
        return head;
    }
};
int main()
{
    cout << "Finding middle of the linked list" << endl;
    List list;
    Node *head = new Node(12);

    list.insertAtPosition(head, 2, 24);
    list.insertAtPosition(head, 3, 36);
    list.insertAtPosition(head, 4, 24);
    list.insertAtPosition(head, 5, 60);
    list.insertAtPosition(head, 6, 36);

    list.printList(head);

    Node *uniqueList = list.uniqueInUnsorted(head);
    list.printList(head);
}