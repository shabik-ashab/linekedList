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

void reversedListPrint(Node* n)
{
    if (n == NULL)
    return;

    reversedListPrint(n->Next);
 
    if(n->Next != NULL) cout<<" <- ";
    cout << n->value;
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

void deletionAtHead(Node* &head){
    Node* temp = head;

    // we can just move the head one place forward
    if(temp != NULL){
        head = temp->Next;
        delete temp;
    }else{
        cout<<"There is no value in the linked list"<<endl;
    }
}

void deletionAtTail(Node* &head){
    Node* temp = head;
    if(temp != NULL && temp->Next != NULL){
        while(temp->Next->Next != NULL){
            temp = temp->Next;
        }

        Node* delNode = temp->Next;
        temp->Next = NULL;

        delete delNode;
    }else{
        //head is null
        if(temp == NULL) cout<<"there is no value in the linked list"<<endl;

        // head is tail
        else deletionAtHead(head);
    }
}

//corner case
//c1: list is empty
//c2: if user delete head
//c3: delete tail
void deltaionAtSpecificPos(Node* head, int pos){
    Node* temp = head;
    int len = countLength(head);

    // c1:
    if(temp!=NULL && pos<=len){
        if(pos == 1) deletionAtHead(head);
        else if(pos == len) deletionAtTail(head);
        else{
            int i = 1;
        while(i<pos-1){
            temp = temp->Next;
            i++;
        }

        Node* delNode = temp->Next;
        temp->Next = delNode->Next;
        delete delNode;
        }    
    }else{
        if(pos>len){
            cout<<"position out of  bound"<<endl;
        }else{
            cout<<"linked list is empty "<<endl;
        }
    }
    
}



//find mid using two pointer
// we will have two pointer. one is slow and one is fast pointer.
// fast pointer will move 2x faster than slow pointer 
// when fast pointer find last node slow pointer will point mid of the list

//corner case:
//c1: head empty 
//c2: if the list is even 
int findMid (Node* &head){
    //c1: head empty 
    if(head == NULL) return -1;

    Node* slow = head;
    Node* fast = head;

    //c2: if the list is even solved by (fast!=NULL)
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

//detect cycle
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

//removal of cycle
// for deletaion we will take a slow and fast pointer
// we will check if fast == cycle 
// if fast == slow we will set fast to head
// now we will check which node is tail node
// if fast->next == slow->next we can break the loop and
// set NULL on slow->next
void removeCycle(Node* &head){
    Node* slow = head;
    Node* fast = head;

    //s1: fast = slow
    do{
        slow = slow->Next;
        fast = fast->Next->Next;
    }while(slow!=fast);

    //s2: re initialization of fast
    fast = head;

    //s3: fast->Next = slow->Next
    while(fast->Next != slow->Next){
        // in this step slow and fast pointer will move on same speed
        slow = slow->Next;
        fast = fast->Next;
    }

    //s4: set the tail node
    slow->Next = NULL;
}

// reverse linked list with recursion
// our plan is to return a newHead from head in this recursive fn

Node *reverseRecursive(Node* head){
    if(head == NULL || head->Next == NULL){
        if(head == NULL) cout<<"Linked list is empty"<<endl;
        // base call
        return head;
    }

    // Recursive call
    // we capture newHead the tail of the list
    Node* newHead = reverseRecursive(head->Next);


    head->Next->Next = head;
    head->Next = NULL;

    return newHead;
}

int main()
{
    Node *head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    inserAtHead(head,0);
    insertAtTail(head,4);

    // reversedListPrint(head);

    // int mid = findMid(head);

    // cout<<endl<<"mid value is: "<<mid<<endl;
    // makeCycle(head,2);

    // if(detectCycle(head)) cout<<"cycle detected"<<endl;
    // else cout<<"there is no cycle"<<endl;

    // removeCycle(head);
    // if(detectCycle(head)) cout<<"cycle detected"<<endl;
    // else cout<<"there is no cycle"<<endl;

    // head = reverseRecursive(head);
    deltaionAtSpecificPos(head,5);
    display(head);
    return 0;
}