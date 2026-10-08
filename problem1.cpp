#include <iostream>
using namespace std;

int q[100],front=-1,rear=-1,n;

void join(int x){
    if((rear+1)%n==front){
        cout<<"Queue Overflow\n";
        return;
    }

    if(front==-1)
        front=rear=0;
    else
        rear=(rear+1)%n;

    q[rear]=x;
    cout<<"Token issued: "<<x<<endl;
}

void serve(){
    if(front==-1){
        cout<<"Queue Underflow\n";
        return;
    }

    cout<<"Token served: "<<q[front]<<endl;

    if(front==rear)
        front=rear=-1;
    else
        front=(front+1)%n;
}

void display(){
    if(front==-1)
        cout<<"Queue Empty\n";
    else
        cout<<"Front Token: "<<q[front]<<endl;
}

int main(){
    int ch,x;

    cout<<"Enter queue size: ";
    cin>>n;

    do{
        cout<<"\n1. Join";
        cout<<"\n2. Serve";
        cout<<"\n3. Display Front";
        cout<<"\n4. Exit";
        cout<<"\nEnter choice: ";
        cin>>ch;

        switch(ch){
            case 1:
                cout<<"Enter token: ";
                cin>>x;
                join(x);
                display();
                break;

            case 2:
                serve();
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