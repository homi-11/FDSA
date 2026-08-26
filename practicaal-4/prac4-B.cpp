#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

void insertEnd(Node *&head,int value){
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if(head==NULL){
        head = newNode;
        return;
    }
    Node *temp = head;

    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

void deleteValue(Node *&head,int value){
    if(head==NULL){
        cout<<"List is empty!"<<endl;
        return;
    }

    if(head->data==value){
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node *temp = head;

    while(temp->next!=NULL){
        if(temp->next->data==value){
            Node *deleteNode = temp->next;
            temp->next = deleteNode->next;
            delete deleteNode;
            return;
        }
        temp = temp->next;
    }
    cout<<"Value not found!"<<endl;
}

void display(Node *head){
    Node *temp = head;

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout << endl;
}

void reverseDisplay(Node *head){
    if(head==NULL)
        return;
    reverseDisplay(head->next);
    cout<<head->data<<" ";
}

int main(){
    Node *head = NULL;

    insertEnd(head,10);
    insertEnd(head,20);
    insertEnd(head,30);
    insertEnd(head,40);

    cout<<"Forward: ";
    display(head);

    cout<<"Reverse: ";
    reverseDisplay(head);
    cout<<endl;

    deleteValue(head,20);

    cout<<"After deleting 20: ";
    display(head);

    return 0;
}