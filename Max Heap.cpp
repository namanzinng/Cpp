#include<iostream>
#include<vector>
using namespace std;
void display(vector<int> &m)

{
    for(int i=0;i<m.size();++i)
    {
        cout<<m[i]<<" " ;
    }
    cout<<endl;
    return;
}
void heapify(vector<int> &m,int i)
{
    int n = m.size();
    int lar = i;
    int l = 2*i+1;
    int r = 2*i+2;
    if(l<n && m[l]>m[lar])
    {
        lar = l;
    }
     if(r<n && m[r]>m[lar])
     {
        lar = r;
    }
    if(lar != i)
    {
        int temp = m[i];
        m[i] = m[lar];
        m[lar] = temp;
        heapify(m,lar);
    }
}

void insertMax(vector<int> &m,int key)
{
    int n = m.size();
    if(n == 0){
        m.push_back(key);
    }
    else
    {
        m.push_back(key);
        for(int i=n-1;i>=0;i--)
        {
            heapify(m,i);
        }
    }
}

void deleteMax(vector <int> &m,int value)
{
    int n = m.size();
    int i;
    for(i=0;i<n;i++){
        if(value == m[i])
        {
            break;
        }
    }
    int temp = m[i];
    m[i] = m[n-1];
    m[n-1] = temp;
    m.pop_back();
    for(int i=n-1;i>=0;i--)
    {
        heapify(m,i);
    }
}

int main()
{
    vector <int> m;

    int choice;
    do
    {
        cout<<"1. insert in Max heap"<<endl;
        cout<<"2. delete from the Max heap"<<endl;
        cout<<"3. Display The Max heap"<<endl;
        cout<<"0. For Exit"<<endl;
        cout<<"ENTER THE CHOICE : ";
        cin>>choice;
        switch(choice){
        case 0:
            break;
        case 1:
            int data;
            cout<<"Enter the data: ";
            cin>>data;
            insertMax(m,data);
            cout<<endl;
            break;

        case 2:
            int value;
            cout<<"Enter the value: ";
            cin>>value;
            deleteMax(m,value);
            cout<<endl;
            break;

        case 3:
            display(m);
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
