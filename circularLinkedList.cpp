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

// we need to find the prev tail node 
// if we find a node with node->Next = head 
// we can say we have found tail node 
// now we need to set newnode as new tail 
// we should set newNode->next = head
// and set prv-next = newNode

// corner case
//c1: linked list is empty or head is NULL 
void insertAtTail(Node* &head, int val){
    // creatin a new node with desire value 
    Node *newNode = new Node(val);

    if(head == NULL){
        head = newNode;
        // making it circular
        newNode->Next = head;
        return;
    }

    Node *temp = head;
    // finding tail node
    while(temp->Next != head){
        temp = temp->Next;
    }

    // setting newNode->Next = head
    newNode->Next = head;
    // setting temp->Next = newNode
    temp->Next = newNode;
}

void inserAtHead(Node* &head, int val){
    //s1 newnode creation
    Node* newNode = new Node(val);
    //s2 update of new node->Next
    newNode->Next = head;

    //s3 update the tail with new head
    //this step is to make list circular

    // checking corner case
    if(head == NULL){
        head = newNode;
        // making it circular
        newNode->Next = head;
        return;
    }

    Node* temp = head;
    while(temp->Next != head){
        temp = temp->Next;
    }
    temp->Next = newNode;

    //s4 update of head
    head = newNode;
}


void display(Node* head){
    Node* temp = head;

    if(head == NULL) {
        cout<<"The linked list is empty"<<endl;
        return;
    }

    do{
        cout<<temp->value;
        temp = temp->Next;
        if(temp!=head)cout<<" -> ";
    }while(temp != head);
}


int main()
{
    
    return 0;
}