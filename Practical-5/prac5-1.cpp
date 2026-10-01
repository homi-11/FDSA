#include <iostream>
#include <cstring>
using namespace std;

struct Node{
    char song[50];
    Node *prev,*next;
};
Node *head=NULL;

void addBeginning(char s[]){
    Node *n=new Node;
    strcpy(n->song,s);
    n->prev=NULL;
    n->next=head;
    if(head!=NULL)
        head->prev=n;
    head=n;
}

void addEnd(char s[]){
    Node *n=new Node;
    Node *t;
    strcpy(n->song,s);
    n->next=NULL;

    if(head==NULL){
        n->prev=NULL;
        head=n;
        return;
    }
    t=head;
    
    while(t->next!=NULL)
        t=t->next;

    t->next=n;
    n->prev=t;
}

void insertAfter(char key[],char s[]){
    Node *t=head;

    while(t!=NULL && strcmp(t->song,key)!=0)
        t=t->next;

    if(t==NULL){
        cout<<"Song not found\n";
        return;
    }

    Node *n=new Node;
    strcpy(n->song,s);

    n->prev=t;
    n->next=t->next;

    if(t->next!=NULL)
        t->next->prev=n;

    t->next=n;
}

void removeFirst(){
    if(head==NULL){
        cout<<"Playlist is empty\n";
        return;
    }

    Node *t=head;
    head=head->next;

    if(head!=NULL)
        head->prev=NULL;

    delete t;
}

void display(){
    Node *t=head;

    if(head==NULL){
        cout<<"Playlist is empty\n";
        return;
    }

    cout<<"Playlist: ";

    while(t!=NULL){
        cout<<t->song;
        if(t->next!=NULL)
            cout<<" <-> ";
        t=t->next;
    }

    cout<<endl;
}

void countSongs(){
    int c=0;
    Node *t=head;

    while(t!=NULL){
        c++;
        t=t->next;
    }

    cout<<"Number of songs: "<<c<<endl;
}

int main(){
    int ch;
    char song[50],key[50];

    do{
        cout<<"\n1. Add Beginning\n";
        cout<<"2. Add End\n";
        cout<<"3. Insert After\n";
        cout<<"4. Remove First\n";
        cout<<"5. Count\n";
        cout<<"6. Display\n";
        cout<<"7. Exit\n";
        cout<<"Enter choice: ";
        cin>>ch;

        switch(ch){
            case 1:
                cout<<"Enter song: ";
                cin.ignore();
                cin.getline(song,50);
                addBeginning(song);
                display();
                break;

            case 2:
                cout<<"Enter song: ";
                cin.ignore();
                cin.getline(song,50);
                addEnd(song);
                display();
                break;

            case 3:
                cout<<"Enter current song: ";
                cin.ignore();
                cin.getline(key,50);
                cout<<"Enter new song: ";
                cin.getline(song,50);
                insertAfter(key,song);
                display();
                break;

            case 4:
                removeFirst();
                display();
                break;

            case 5:
                countSongs();
                break;

            case 6:
                display();
                break;

            case 7:
                cout<<"Exit";
                break;

            default:
                cout<<"Invalid choice\n";
        }
    }while(ch!=7);

    return 0;
}