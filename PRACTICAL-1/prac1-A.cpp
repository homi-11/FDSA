#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    int h;

    cout<<"enter number of item: ";
    cin>>n;
    
    string items[n];

    for(int i=0; i<n; i++) {
        cout<<"enter item "<<i+1<<": ";
        cin>>items[i];
    }
    
    cout<<"items are: ";
    for(int i=0; i<n; i++){
        cout<<items[i] << " ";
    }
    
    cout<<"\nenter hours: ";
    cin>>h;
    
    for(int i=0; i<h; i++){
        string temp = items[0];
        for(int j=n;j>=0;j--) {
            items[n-j] = items[n-(j-1)];
            items[n] = temp;
        }
    }
    cout<<"items after "<<h<<" hours: ";
    for(int i=0;i<n;i++){
        cout<<items[i]<<" ";
    }
    cout<<"\n";
    return 0;
}