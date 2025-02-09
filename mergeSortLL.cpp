#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    // Constructor to initialize the node
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
    // 1.1 Insert at Begining
    void insertAtBegin(Node *&head, int data)
    {
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
    }
    // 1.2 Insert at given position
    void insertAtPosition(Node *&head, int position, int data)
    {
        Node *newNode = new Node(data);
        Node *temp = head;
        if (position == 1 || position == 0)
        {
            insertAtBegin(head, data);
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

    // 2. Print/Read list
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

    // 3.Merge sort:
    Node *findMid(Node *head)
    {
        Node *slow = head;
        Node *fast = head->next;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    Node *merge(Node *&left, Node *&right)
    {
        if (left == NULL)
        {
            return right;
        }
        if (right == NULL)
        {
            return left;
        }

        Node *ans = new Node(-1);
        Node *temp = ans;

        while (left != NULL && right != NULL)
        {
            if (left->data < right->data)
            {
                temp->next = left;
                temp = left;
                left = left->next;
            }
            else
            {
                temp->next = right;
                temp = right;
                right = right->next;
            }
        }
        while (left != NULL)
        {
            temp->next = left;
            temp = left;
            left = left->next;
        }
        while (right != NULL)
        {
            temp->next = right;
            temp = right;
            right = right->next;
        }
        ans = ans->next;
        return ans;
    }
    // Sort function using recursion
    Node* mergeSort(Node *head)
    {
        // base case
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        Node *mid = findMid(head);
        Node *left = head;
        Node *right = mid->next;
        mid->next = NULL;
// Recursive calls
        left = mergeSort(left);
        right = mergeSort(right);
        Node *ans = merge(left, right);

        return ans;
    }
};

int main()
{
    List list;
    Node *head1 = new Node(60);

    list.insertAtPosition(head1, 2, 48);
    list.insertAtPosition(head1, 3, 36);
    list.insertAtPosition(head1, 4, 24);
    list.insertAtPosition(head1, 5, 12);

    Node* mergedList = list.mergeSort(head1);

    list.printList(mergedList);
}
// Time complexity : O(nlogn)
// Space complexity : O(logn)