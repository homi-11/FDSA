#include <iostream>
using namespace std;

struct Node{
    string name;
    Node *next,*prev;
};

Node *shead=NULL,*dhead=NULL;

void addSingly(string name){
    Node *n=new Node;
    n->name=name;
    if(shead==NULL){
        shead=n;
        n->next=shead;
        return;
    }
    Node *t=shead;
    while(t->next!=shead)
        t=t->next;
    t->next=n;
    n->next=shead;
}

void deleteSingly(string name){
    if(shead==NULL) return;
    Node *t=shead,*p=NULL;
    do{
        if(t->name==name) break;
        p=t;
        t=t->next;
    }while(t!=shead);

    if(t->name!=name) return;

    if(t==shead){
        if(shead->next==shead){
            delete shead;
            shead=NULL;
        }else{
            Node *last=shead;
            while(last->next!=shead)
                last=last->next;
            shead=shead->next;
            last->next=shead;
            delete t;
        }
    }else{
        p->next=t->next;
        delete t;
    }
}

void displaySingly(){
    if(shead==NULL){
        cout<<"Empty\n";
        return;
    }
    Node *t=shead;
    do{
        cout<<t->name<<" ";
        t=t->next;
    }while(t!=shead);
    cout<<endl;
}

void addDoubly(string name){
    Node *n=new Node;
    n->name=name;

    if(dhead==NULL){
        dhead=n;
        n->next=n;
        n->prev=n;
        return;
    }

    Node *last=dhead->prev;
    n->next=dhead;
    n->prev=last;
    last->next=n;
    dhead->prev=n;
}

void deleteDoubly(string name){
    if(dhead==NULL) return;

    Node *t=dhead;
    do{
        if(t->name==name) break;
        t=t->next;
    }while(t!=dhead);

    if(t->name!=name) return;

    if(t->next==t){
        delete t;
        dhead=NULL;
        return;
    }

    t->prev->next=t->next;
    t->next->prev=t->prev;

    if(t==dhead)
        dhead=t->next;

    delete t;
}

void displayDoubly(){
    if(dhead==NULL){
        cout<<"Empty\n";
        return;
    }

    Node *t=dhead;
    do{
        cout<<t->name<<" ";
        t=t->next;
    }while(t!=dhead);
    cout<<endl;
}

int main(){
    int type,ch;
    string name;

    do{
        cout<<"\n1. Singly Circular";
        cout<<"\n2. Doubly Circular";
        cout<<"\n3. Exit";
        cout<<"\nEnter choice: ";
        cin>>type;

        if(type==3) break;

        do{
            cout<<"\n1. Join Student";
            cout<<"\n2. Leave Student";
            cout<<"\n3. Display Circle";
            cout<<"\n4. Back";
            cout<<"\nEnter choice: ";
            cin>>ch;

            if(ch==1){
                cout<<"Enter student name: ";
                cin>>name;

                if(type==1)
                    addSingly(name);
                else
                    addDoubly(name);
            }
            else if(ch==2){
                cout<<"Enter student name: ";
                cin>>name;

                if(type==1)
                    deleteSingly(name);
                else
                    deleteDoubly(name);
            }
            else if(ch==3){
                if(type==1)
                    displaySingly();
                else
                    displayDoubly();
            }
        }while(ch!=4);

    }while(type!=3);

    return 0;
}