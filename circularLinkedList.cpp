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

void deletionAtHead(Node* &head){
    Node* temp = head;
    if(temp != NULL){
        Node* delNode = temp;

        // caching the tail at temp
        while(temp->Next != head){
            temp = temp->Next;
        }

        // adding head to tail
        temp->Next = delNode->Next;
        // updating the head
        head = delNode->Next;

        delete delNode;
    }else{
        cout<<"There is no value in the linked list"<<endl;
    }
}

void deletionAtTail(Node* &head){
    Node* temp = head;
    if(temp != NULL && temp->Next != head){
        while(temp->Next->Next != head){
            temp = temp->Next;
        }

        Node* delNode = temp->Next;
        temp->Next = delNode->Next;

        delete delNode;
    }else{
        //head is null
        if(temp == NULL) cout<<"there is no value in the linked list"<<endl;

        // head is tail
        else deletionAtHead(head);
    }
}

// reason to use do while loop:
// for circular linked list we usually check if 
// something is equal to head or not 
// but if we use while loop th econdiotion will be true at first run 
// and our algorithom will fail
// do will do the task at first and than check the condition
int countLength(Node* &head){
    int count = 0;
    Node* temp = head;

    do{
        count++;
        temp = temp->Next;
    }while(temp != head);

    return count;
}


int main()
{
    Node *head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    inserAtHead(head,0);
    insertAtTail(head,4);

    display(head);
    cout<<endl;
    
    cout<<countLength(head)<<endl;

    deletionAtHead(head);
    display(head);
    return 0;
}