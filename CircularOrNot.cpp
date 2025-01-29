#include <iostream>
#include<map>
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
    // Checking  if it is circular or Not
    bool isCircular(Node* head){
        if(head == NULL){
            return true;
        }
        Node *temp = head->next;
        while(temp != NULL && temp != head){
            temp=temp->next;
        }
        if(temp == head){
            return true;
        }
          return false;
    }
    // Loop detection
    bool detectLoop(Node* head){
        Node* temp = head;
        if(head == NULL){
            return false;
        }
        map<Node*, bool>visited;
        while (temp->next == NULL){
            if(visited[temp] == true){
                return false;
            }
            visited[temp] = true;
            temp = temp->next;
        }
        return false;
    }
};

int main()
{
    cout << "Circular Linked list" << endl;
    CircularList list;
    Node *tail = NULL;
    list.insertNode(tail, 5, 3);
    list.insertNode(tail, 3, 5);
    list.insertNode(tail, 5, 10);
    list.insertNode(tail, 10, 30);
    list.insertNode(tail, 5, 69);
    list.printList(tail);
    bool decision =list.isCircular(tail);
    if(decision){
        cout<<"List is Circular!!";
    }else{
        cout<<"List is Not Circular!!";
    }
    bool detected = list.detectLoop(tail);
    if(detected){
        cout<<"Loop is there!!"<<endl;
    }else{
        cout<<"Loop is not there!!";
    }
}