#include<iostream>
using namespace std;
int binarySearch(int arr[],int num,int data);
int main(){
	int arr[10]={5,9,17,23,25,45,59,63,71,89};
	int data,num=10,ans;
	cout<<"enter a number you want to search";
	cin>>data;
	ans=binarySearch(arr,num,data);
	if(ans==-1)
	 cout<<"number is not present ";
	else
	 cout<<"index of number you entered is :"<<ans;	
}
int binarySearch(int arr[],int num,int data){
	int left=0,right=num-1,mid;
	while(left<=right){
		mid=(left+right)/2;
		if(arr[mid]==data)
			return(mid);
		else if(data<arr[mid])
		   right=mid-1;
		else
		   left=mid+1;
		}
		return(-1);
}
