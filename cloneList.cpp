#include<iostream>
#include<map>

using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* random;

    Node(int data){
        this->data = data;
        this->next = NULL;
        this->random = NULL;
    }
};
class List{
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
    void insertAtTail(Node* &head, Node* &tail, int data){
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
    // Approch 1
    Node* copyList_1(Node* head){
        // 1.Creating clone list
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        Node* temp = head;
        while(temp != NULL){
            insertAtTail(cloneHead, cloneTail, temp->data);
            temp = temp->next;
        }
        // 2.Create map
        map <Node*, Node*> oldToNewNode;

        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        while(originalNode != NULL && cloneNode != NULL){
            oldToNewNode[originalNode] = cloneNode;;
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }   
        originalNode = head;;
        cloneNode = cloneHead;  
        //3. Dealing with random ptrs:
        while(originalNode != NULL){
            cloneNode->random = oldToNewNode[originalNode->random];
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }  
        return cloneHead; 
    }
};
int main(){
    List list;
    Node* head = new Node(12);

    list.insertAtPosition(head, 2, 24);
    list.insertAtPosition(head, 3, 36);
    list.insertAtPosition(head, 4, 48);
    list.insertAtPosition(head, 5, 60);
    list.insertAtPosition(head, 6, 75);

    list.printList(head);
    
}