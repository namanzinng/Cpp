#include<iostream>
using namespace std;
int b_search(int arr[], int n, int key)
{
    int start = 0;
    int end = n;
    while(start<=end)
    {
        int mid = (start+end)/2;

        if(arr[mid]==key)
        {
            return mid;
        }

        else if(arr[mid]>key)
        {
            end = mid - 1;
        }

        else
        {
             start = mid + 1;
        }
    }

    return -1;

}
int main()
{
    int n;
    cout<<"Enter the size of array -:";
    cin>>n;

    int arr[n];
    int i,key;
    cout<<"Enter array in ascending or descending order -:";
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    cout<<"Enter array was -:"<<endl;
    for(i=0;i<n;i++)
    
      cout<<" "<<arr[i]<<"\t";


      cout<<"Enter Key element to find  -:"<<endl;
      cin>>key;

      cout<<"Element present at "<< b_search(arr,n,key) <<" Index " <<endl;

        
    


}
