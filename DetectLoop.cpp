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
    // 4.1. Detection of loop
    // Using MAP:
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
    // Using Floyd detection algorithm:
    Node* floydDetectLoop(Node* head){
        Node* slow = head;
        Node* fast = head;
        while(slow!=NULL && fast != NULL){
            fast = fast->next;
            if (fast != NULL)
            {
                fast = fast->next;
            }
            slow = slow->next;
            if(slow == fast){
                cout<<"Loop is present at "<<slow->data<<endl;
                return slow;
            }
        }
               return NULL;

    }
    // 4.2 Finding starting node of the loop
    Node* getStartingNode(Node* head){
        if(head == NULL){
            cout<<"List is empty"<<endl;
        }
        Node* intersection = floydDetectLoop(head);
        Node* slow = head;

        while (slow != intersection)
        {
            slow = slow->next;
            intersection = intersection->next;
        }
        return slow;   
    }
    // 4.3 Remove the detected loop
    void removeLoop(Node* head){
        if(head == NULL){
            return ;
        }
        Node* startOfLoop = getStartingNode(head);
        Node* temp = startOfLoop;
        while(temp->next != startOfLoop){
            temp = temp->next;
        }
        temp->next = NULL;
        cout<<"Loop is removed!!"<<endl;
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
    bool detected = list.detectLoop(head);
    if(detected){
        cout<<"Loop is there!!"<<endl;
    }else{
        cout<<"Loop is not there!!"<<endl;
    }
    Node* startingNode = list.getStartingNode(head);
    cout<<"Starting node of the loop is "<<startingNode->data;
    list.removeLoop(head);
}