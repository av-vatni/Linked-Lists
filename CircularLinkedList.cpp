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
        this->next = NULL;
    }
};

class CircularList
{
public:
    // INSERT
    void insertNode(Node *&tail, int element, int data)
    {
        // Empty list
        if (tail == NULL)
        {
            Node *newNode = new Node(data);
            tail = newNode;
            newNode->next = newNode;
        }
        else
        {
            // Non-Empty list
            // Assuming that the element is present in the list
            Node *curr = tail;

            while (curr->data != element)
            {
                curr = curr->next;
            }
            // Element is found and curr is representing that element
            Node *temp = new Node(data);
            temp->next = curr->next;
            curr->next = temp;
        }
    }
    // PRINT
    void printList(Node *&tail)
    {
        Node *temp = tail;
        do
        {
            cout << tail->data << " ";
            tail = tail->next;
        } while (tail != temp);
        cout << endl;
    }
    // DELETE
    void deleteNode(Node *&tail, int value)
    {
        if(tail == NULL){
            cout<<"List is empty and nothing is here to delete\n"<<endl;
            return;
        }else{
            Node* prev = tail;
            Node* curr = prev->next;

            while(curr->data != value){
                prev = curr;
                curr = curr->next;
            }
            prev->next = curr->next;
            if(tail == curr){
                tail = prev;
            }
            curr->next = NULL;
            delete curr;
        }
    }
};

int main()
{
    cout << "Doubly Linked list" << endl;
    CircularList list;
    Node *tail = NULL;
    list.insertNode(tail, 5, 3);
    list.printList(tail);
    list.insertNode(tail, 3, 5);
    list.printList(tail);
    list.insertNode(tail, 5, 10);
    list.printList(tail);
    list.insertNode(tail, 10, 30);
    list.printList(tail);
    list.insertNode(tail, 5, 69);
    list.printList(tail);
    cout<<"After deleting node: "<<endl;
    list.deleteNode(tail, 69);
    list.printList(tail);

}