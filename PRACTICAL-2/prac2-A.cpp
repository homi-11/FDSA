#include<iostream>
using namespace std;

int LinearSearch(int arr[],int n,int key){
    for(int i=0;i<n;i++){
        if(arr[i] == key)
            return i;
    }
    return -1;
}

int recursiveLinearSearch(int arr[],int n,int key,int index){
    if(index>=n)
        return -1;

    if(arr[index] == key)
        return index;

    return recursiveLinearSearch(arr,n,key,index+1);
}

int main()
{
    int n, key;

    cout<<"Enter number plats: ";
    cin>>n;

    int arr[n];

    cout<<"Enter number plate number:\n";
    for(int i = 0;i<n;i++)
        cin>>arr[i];

    cout<<"Enter no. to search: ";
    cin>>key;

    cout<<"\n----- Search Results -----\n";

    int result1 = LinearSearch(arr,n,key);
    if (result1 != -1)
        cout<<"Linear Search: found at index "<<result1<<endl;
    else
        cout<<"Linear Search: not found\n";

    int result2 = recursiveLinearSearch(arr,n,key,0);
    if (result2 != -1)
        cout<<"Recursive Linear Search: found at index "<<result2<<endl;
    else
        cout<<"Recursive Linear Search: not found\n";
        return 0;
}