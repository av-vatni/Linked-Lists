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
    // Merge 2 sorted lists:
    Node* solve(Node* first, Node* second){
        // If only one node is there in first list
        if(first->next == NULL){
            first->next = second;
            return first;
        }
        Node* current1 = first;
        Node* next1 = current1->next;
        Node* current2 = second;
        Node* next2 = current2->next;

        while(next1 != NULL && current2!=NULL){
            if(current2->data >= current1->data && current2->data <= next1->data){
                // Adding the node in between the first list
                current1->next = current2;
                next2 = current2->next;
                current2->next = next1;

                // Updating the ptrs
                current1 = current2;
                current2 = next2;

            }else{
                current1 = next1;
                next1 = next1->next;

                if(next1 == NULL){
                    current1->next = current2;
                    return current2;
                }
            }
        }
        return first;
    }
    Node* sortLists(Node* first, Node* second){
        if(first == NULL){
            return second;
        }
        if(second == NULL){
            return first;
        }
        if(first->data <= second->data){
            solve(first, second);
        }else{
            solve(second, first);
        }
    }
    
};
int main(){
    List list;
    Node* head = new Node(1);

    list.insertAtPosition(head, 2, 1);
    list.insertAtPosition(head, 3, 2);
    list.insertAtPosition(head, 4, 4);
    list.insertAtPosition(head, 5, 8);
    list.insertAtPosition(head, 6, 9);

    list.printList(head);

    Node* head2 = new Node(1);

    list.insertAtPosition(head2, 2, 2);
    list.insertAtPosition(head2, 3, 3);
    list.insertAtPosition(head2, 4, 5);
    list.insertAtPosition(head2, 5, 6);
    list.insertAtPosition(head2, 6, 7);

    list.printList(head2);

    Node* sortedList = list.sortLists(head, head2);
    cout<<"Sorted lists after merge: "<<endl;
    list.printList(sortedList);
}