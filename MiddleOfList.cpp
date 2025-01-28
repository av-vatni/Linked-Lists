#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
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
    // 3. Length of list
    int lengthOfList(Node* &head){
        Node* temp = head;
        int cnt = 0;
        while(temp != NULL){
            temp = temp->next;
            cnt++;
        }
        return cnt;
    }
    // 4. Middle of list without pointers
    void middleOfList(Node* &head){
        int len = lengthOfList(head);
        int ans = len/2;

        Node* temp = head;
        int cnt = 0;
        while(cnt  < ans){
            temp = temp->next;
            cnt++;;
        }
        cout<<temp->data;
    }
    // 5. Middle of list with pointers
    void midWithPtr(Node* head){
        if(head == NULL){
            cout<<"List is empty" ;
        }
        if(head -> next == NULL){
            cout<<"Middle is "<<head->data;
        }
        if(head->next->next == NULL){
            cout<<"Middle is "<<head->data;
        }
        Node* slow = head;;
        Node* fast = head->next;

        while(fast != NULL){
            fast = fast->next;
            if(fast != NULL){
                fast = fast->next;
            }
            slow = slow -> next;
        }
        cout<<"Middle is "<<slow->data;
    }
};
int main(){
    cout<<"Finding middle of the linked list"<<endl;
    List list;
    Node* head = new Node(12);

    list.insertAtPosition(head, 2, 24);
    list.insertAtPosition(head, 3, 36);
    list.insertAtPosition(head, 4, 48);
    list.insertAtPosition(head, 5, 60);
    list.insertAtPosition(head, 6, 75);

    list.printList(head);
    // int count = list.lengthOfList(head);
    // cout<<"Length of list is "<<count<<endl;
    // cout<<"Middle of list is ";
    list.midWithPtr(head);
}