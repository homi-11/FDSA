#include <iostream>
using namespace std;

struct Node{
    string page;
    Node *next;
};

Node *top=NULL;

void visit(string p){
    Node *n=new Node;
    n->page=p;
    n->next=top;
    top=n;
    cout<<"Visited: "<<p<<endl;
}

void back(){
    if(top==NULL){
        cout<<"No history left\n";
    }else{
        cout<<"Back from: "<<top->page<<endl;
        Node *t=top;
        top=top->next;
        delete t;
    }
}

void display(){
    if(top==NULL)
        cout<<"No page in history\n";
    else
        cout<<"Current Page: "<<top->page<<endl;
}

int main(){
    int ch;
    string page;

    do{
        cout<<"\n1. Visit Page";
        cout<<"\n2. Back";
        cout<<"\n3. Current Page";
        cout<<"\n4. Exit";
        cout<<"\nEnter choice: ";
        cin>>ch;

        switch(ch){
            case 1:
                cout<<"Enter page: ";
                cin>>page;
                visit(page);
                display();
                break;

            case 2:
                back();
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