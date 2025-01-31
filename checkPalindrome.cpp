// Check the linked list is palindrome or not!
#include<iostream>
#include<vector>

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
    // 1. Using method of array: 
    bool checkPalInArray(vector <int> array){
       int n = array.size(); 
       int start = 0;
       int end = n-1;

       while(start<= end){
        if(array[start] != array[end]){
            return false;
        }
        start++;
        end--;
       }
       return true;
    }
    bool checkPalindrome(Node* head){
        vector<int> arr;
        Node* temp = head;
        while(temp != NULL){
             arr.push_back(temp->data);
             temp= temp->next;
        }
        return checkPalInArray(arr);
    }
    // 2. With pointers
    // 2.1 Function to find midlde
    Node* getMiddle(Node* head){
        Node* slow= head;
        Node* fast= head->next;
        while(fast!=NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    // 2.2 Function to reverse the list
    Node* reverse(Node*head){
        Node* current = head;
        Node* prev = NULL;
        Node* next = NULL;
        while (current != NULL)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
        
    }
    bool checkPalPtr(Node* head){
        // For empty or single node list
        if(head == NULL || head->next == NULL){
            return true;
        }
        //1. Find middle
        Node* middle = getMiddle(head);

        //2. Reverse remanining part from middle:
        Node* temp =  middle->next;
        middle -> next = reverse(temp);

        // 3. Compare both the halves
        Node* head1 = head;
        Node* head2 = middle->next;

        while(head2 != NULL){
            if(head1->data != head2->data){
                return false;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        // 4. Return step 2
        temp =  middle->next;
        middle -> next = reverse(temp);

        return true;
    }
};
int main(){
    List list;
    Node* head = new Node(1);

    list.insertAtPosition(head, 2, 2);
    list.insertAtPosition(head, 3, 3);
    list.insertAtPosition(head, 4, 3);
    list.insertAtPosition(head, 5, 2);
    list.insertAtPosition(head, 6, 4);

    list.printList(head);
    bool ans = list.checkPalPtr(head);
    if(ans){
        cout<<"Palindrome"<<endl;
    }else{
        cout<<"Not a Palindrome"<<endl;
    }

}