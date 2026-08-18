#include<iostream>
using namespace std;

int BinarySearch(int arr[],int n,int key){
    int low = 0;
    int high = n - 1;

    while (low<=high){
        int mid = low+(high-low)/2;
        if(arr[mid]==key)
            return mid;
        else if(arr[mid]<key)
            low = mid+1;
        else
            high = mid-1;
    }
    return -1;
}

int recursiveBinarySearch(int arr[],int low,int high,int key)
{
    if(low>high)
        return -1;
    int mid = low+(high-low)/2;
    if (arr[mid]==key)
        return mid;
    if (arr[mid] > key)
        return recursiveBinarySearch(arr,low,mid-1,key);

    return recursiveBinarySearch(arr,mid+1,high,key);
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
int result1 = BinarySearch(arr,n,key);

    if(result1 != -1)
        cout<<"\nBinary Search: found at index "<<result1<<endl;
    else
        cout<<"\nBinary Search: not found."<<endl;

    int result2 = recursiveBinarySearch(arr,0,n-1,key);

    if(result2 != -1)
        cout<<"Recursive Binary Search: found at index "<<result2<<endl;
    else
        cout<<"Recursive Binary Search: not found."<<endl;

    return 0;
}