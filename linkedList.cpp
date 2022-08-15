#include <bits/stdc++.h>
using namespace std;


//linear linked list
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
//c1: head empty 
//c2: if the list is even 
int findMid (Node* &head){
    //c1: head empty 
    if(head == NULL) return -1;

    Node* slow = head;
    Node* fast = head;

    //c2: if the list is even -> fast!=NULL
    while(fast!=NULL && fast->Next!=NULL){
        slow = slow->Next;
        fast = fast->Next->Next;
    }

    return slow->value;
}

// cycle detect and remove
// cyle means we will get a position and last node will link with this position.
// So it will look like a cycle 
//make cycle 
void makeCycle(Node* &head, int pos){
    // we need to save node adress of position 
    // and we will make link with tail of the list
    Node* temp = head;
    Node* startNode;
    int count = 1;

    while(temp->Next != NULL){
        if(count==pos) {
            //saving node address of position
            startNode = temp;
        }
        temp = temp->Next;
        count++;
    }

    // making link with tail
    temp->Next = startNode;
}

// if we take a slow and fast pointer and run these threough a cycle 
// this pointer will eventually meet with each other if there is a cycle
bool detectCycle(Node* &head){
    Node* slow = head;
    Node* fast = head;

    while(fast!=NULL && fast->Next!=NULL){
        slow = slow->Next;
        fast = fast->Next->Next;

        //cycle check
        if(slow->Next == fast->Next){
            return true;
        }
    }

    return false;
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
    makeCycle(head,2);

    if(detectCycle(head)) cout<<"cycle detected"<<endl;

    return 0;
}