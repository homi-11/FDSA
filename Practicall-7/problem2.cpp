#include <iostream>
using namespace std;

struct Node{
    string name;
    Node *next;
};

Node *front=NULL,*rear=NULL;

void arrive(string name){
    Node *n=new Node;
    n->name=name;
    n->next=NULL;

    if(rear==NULL)
        front=rear=n;
    else{
        rear->next=n;
        rear=n;
    }

    cout<<"Patient arrived: "<<name<<endl;
}

void attend(){
    if(front==NULL){
        cout<<"Queue Underflow\n";
        return;
    }

    cout<<"Patient attended: "<<front->name<<endl;

    Node *t=front;
    front=front->next;
    delete t;

    if(front==NULL)
        rear=NULL;
}

void display(){
    if(front==NULL)
        cout<<"Ward Empty\n";
    else
        cout<<"Front Patient: "<<front->name<<endl;
}

int main(){
    int ch;
    string name;

    do{
        cout<<"\n1. Arrive";
        cout<<"\n2. Attend";
        cout<<"\n3. Display Front";
        cout<<"\n4. Exit";
        cout<<"\nEnter choice: ";
        cin>>ch;

        switch(ch){
            case 1:
                cout<<"Enter patient: ";
                cin>>name;
                arrive(name);
                display();
                break;

            case 2:
                attend();
                display();
                break;

            case 3:
                display();
                break;

            case 4:
                cout<<"Exit\n";
                break;

            default:
                cout<<"Invalid choice\n";
        }
    }while(ch!=4);

    return 0;
}