#include <iostream>
using namespace std;

int main()
{
    int n;
    cout<<"enter number of book id's: ";
    cin>>n;
    int books[n];

    cout<<"enter book id's:"<<endl;
    for(int i=0;i<n;i++){
        cin>>books[i];
    }

    bool found = false;

    cout<<"duplicate book id's:"<<endl;

    for(int i=0;i<n;i++){
        bool alreadyPrinted = false;

        for(int k=0;k<i;k++){
            if(books[i] == books[k]){
                alreadyPrinted = true;
                break;
            }
        }

        if(alreadyPrinted)
            continue;

        int count = 0;
        for(int j=0;j<n;j++)
        {
            if(books[i] == books[j]){
                count++;
            }
        }

        if(count>1){
            cout<<"book id:"<<books[i]<<"(count = "<<count<<")"<< endl;
            found = true;
        }
    }

    if(!found){
        cout<<"no duplicate book id's found."<<endl;
    }

    return 0;
}