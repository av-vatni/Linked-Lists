#include<iostream>
#include<map>

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
    // Sorting 0s, 1s and 2s
    // Approch 1
    Node* sort012_1(Node* head){
        Node* temp = head;
        int zeroCount = 0;
        int oneCount = 0;
        int twoCount = 0;
        while(temp != NULL){
            if(temp->data == 0){
                zeroCount++;
            }else if(temp->data == 1){
                oneCount++;
            }else{
                twoCount++;
            }
            temp = temp->next;
        }
        temp = head;
        while(temp != NULL){
            if(zeroCount != 0){
                temp->data =  0;
                zeroCount--;
            }else if(oneCount != 0){
                temp->data =  1;
                oneCount--;
            }else{
                temp->data =  2;
                twoCount--;
            }
            temp = temp->next;
        }
        return head;
    }
    // Approch 2
    // Creating 3 new lists and merging them
    void insertAtTail(Node* &tail, Node* curr){
        tail->next = curr;
        tail = curr;
    }
    Node* sort012_2(Node* head){
        Node* zeroHead = new Node(-1);
        Node* zeroTail = zeroHead;
        Node* oneHead = new Node(-1);
        Node* oneTail = oneHead;
        Node* twoHead = new Node(-1);
        Node* twoTail = twoHead;

        Node* current = head;

        // Creating 3 lists and adding data to it
        while(current != NULL){
            int value = current->data;
            if(value == 0){
                insertAtTail(zeroTail, current);
            }
            else if(value == 1){
                insertAtTail(oneTail, current);
            }
            else if(value == 2){
                insertAtTail(twoTail, current);
            }
            current = current->next;
        }
        // Merging the created lists

        // If 1st list is not empty
        if(oneHead->next != NULL){
            zeroTail->next = oneHead->next;
        }else{
            // If 1st list is empty
            zeroTail->next = twoHead->next;
        }
        oneTail->next = twoHead->next;
        twoTail->next = NULL;

        head = zeroHead->next;

        delete zeroHead;
        delete oneHead;
        delete twoHead;

        return head;
    }
};
int main(){
    List list;
    Node* head = new Node(1);

    list.insertAtPosition(head, 2, 2);
    list.insertAtPosition(head, 3, 1);
    list.insertAtPosition(head, 4, 2);
    list.insertAtPosition(head, 5, 0);
    list.insertAtPosition(head, 6, 0);

    list.printList(head);

// Using approch 1: 
    Node* sorted = list.sort012_2(head);
    cout<<"List after sorting 0s, 1s and 2s: "<<endl;
    list.printList(sorted);
}