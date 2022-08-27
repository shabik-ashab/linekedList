#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int value;
    Node *Next;
    Node *Prev;

    //cosnstructor created 
    Node(int val){
        value = val;
        Next = NULL;
        Prev = NULL;
    }
};

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
    newNode->Prev = temp;    
}

void inserAtHead(Node* &head, int val){
    Node* newNode = new Node(val);

    head->Prev = newNode;
    newNode->Next = head;
    head = newNode;
}

void display(Node* n){
    while(n != NULL){
        cout<<n->value;
        if(n->Next != NULL) cout<<" -> ";
        n = n->Next;
    }
}

int countLength(Node* &head){
    int count = 0;
    Node* temp = head;

    while(temp != NULL){
        count++;
        temp = temp->Next;
    }

    return count;
}



int main()
{
    Node* head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    inserAtHead(head,0);
    insertAtTail(head,4);

    return 0;
}