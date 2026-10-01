#include <iostream>
using namespace std;

int stack[100], top=-1, n;

void push(int x){
    if(top==n-1)
        cout<<"Stack Overflow\n";
    else{
        top++;
        stack[top]=x;
        cout<<"Tray placed\n";
    }
}

void pop(){
    if(top==-1)
        cout<<"Stack Underflow\n";
    else{
        cout<<"Tray taken: "<<stack[top]<<endl;
        top--;
    }
}

void display(){
    if(top==-1)
        cout<<"Stack Empty\n";
    else
        cout<<"Top Tray: "<<stack[top]<<endl;
}

int main(){
    int ch,x;
    cout<<"Enter stack size: ";
    cin>>n;

    do{
        cout<<"\n1. Place Tray";
        cout<<"\n2. Take Tray";
        cout<<"\n3. Display Top";
        cout<<"\n4. Exit";
        cout<<"\nEnter choice: ";
        cin>>ch;

        switch(ch){
            case 1:
                cout<<"Enter tray: ";
                cin>>x;
                push(x);
                display();
                break;

            case 2:
                pop();
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