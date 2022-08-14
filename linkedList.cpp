#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int value;
    Node *Next;

    //cosnstructor created 
    Node(int val){
        value = val;
        Next = NULL;
    }
};


void display(Node* n){
    while(n != NULL){
        cout<<n->value;
        if(n->Next != NULL) cout<<" -> ";
        n = n->Next;
    }
}

void insertAtTail(Node* &head, int val){
    Node *newNode = new Node(val);

    if(head == NULL){
        head = newNode;
        return;
    }

    Node *temp = head;
    while(temp->Next != NULL){
        temp = temp->Next;
    }

    temp->Next = newNode;
}

void inserAtHead(Node* &head, int val){
    //s1 newnode creation
    Node* newNode = new Node(val);
    //s2 update of new node->Next
    newNode->Next = head;
    //s3 update of head
    head = newNode;
}


void reversedListPrint(Node* n)
{
    if (n == NULL)
    return;

    reversedListPrint(n->Next);
 
    if(n->Next != NULL) cout<<" <- ";
    cout << n->value;
}

//find mid using two pointer
//we will have two pointer. one is slow and one is fast pointer.
// fast pointer will move 2x faster than slow pointer 
// when fast pointer find last node slow pointer will point mid of the list

//corner case
//c1: 
int findMid (Node* &head){
    Node* slow = head;
    Node* fast = head;

    while(fast->Next!=NULL){
        slow = slow->Next;
        fast = fast->Next->Next;
    }

    return slow->value;
}

int main()
{
    Node *head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    inserAtHead(head,0);
    insertAtTail(head,4);

    reversedListPrint(head);

    int mid = findMid(head);

    cout<<"mid value is: "<<mid<<endl;

    return 0;
}