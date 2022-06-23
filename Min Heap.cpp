#include<iostream>
#include<vector>
using namespace std;
void display(vector<int> &mh)
{
    for(int i=0;i<mh.size();++i)
    {
        cout<<mh[i]<<" " ;
    }
    cout<<endl;
    return;
}
void heapify(vector<int> &mh,int i)
{
    int n = mh.size();
    int small = i;
    int l = 2*i+1;
    int r = 2*i+2;
    if(l<n && mh[l]<mh[small])
    {
        small = l;
    }
     if(r<n && mh[r]<mh[small])
     {
        small = r;
    }
    if(small != i)
    {
        int temp = mh[i];
        mh[i] = mh[small];
        mh[small] = temp;
        heapify(mh,small);
    }
}

void insertMin(vector<int> &mh,int key)
{
    int n = mh.size();
    if(n == 0)
    {
        mh.push_back(key);
    }
    else
    {
        mh.push_back(key);
        for(int i=n-1;i>=0;i--)
        {
            heapify(mh,i);
        }
    }
}

void deleteMin(vector <int> &mh,int value)
{
    int n = mh.size();
    int i;
    int flag = 0;
    for(i=0;i<n;i++){
        if(value == mh[i])
        {
            flag++;
            break;
        }
    }
    if(flag==0){
        cout<<value<<" is not present in heap!"<<endl;
        return;
    }
    int temp = mh[i];
    mh[i] = mh[n-1];
    mh[n-1] = temp;
    mh.pop_back();
    for(int i=n-1;i>=0;i--)
    {
        heapify(mh,i);
    }
}

int main()
{
    vector <int> mh;

    int choice;
    do
    {
        cout<<"1. insert in Min heap"<<endl;
        cout<<"2. delete from the Min heap"<<endl;
        cout<<"3. Display The Min heap"<<endl;
        cout<<"0. For Exit"<<endl;
        cout<<"ENTER THE CHOICE : ";
        cin>>choice;
        switch(choice)
        {
        case 0:
            break;
        case 1:
            int data;
            cout<<"Enter the value: ";
            cin>>data;
            insertMin(mh,data);
            cout<<endl;
            break;

        case 2:
            int value;
            cout<<"Enter the value: ";
            cin>>value;
            deleteMin(mh,value);
            cout<<endl;
            break;

        case 3:
            display(mh);
            cout<<endl;
            break;

        default:
            cout<<"Please enter correct choice"<<endl;
            cout<<endl;
            break;
        }
    }
    while(choice!=0);
    return 0;
}
