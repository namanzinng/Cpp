#include<iostream>
using namespace std;
#define n  20
class qeue{
	int* arr;
	int front;
	int back;
	public:
		qeue(){
		arr=new int[n];
		front=-1;
		back=-1; 
	}
	void push(int x){
		if(back==n-1){
		  cout<<"qeue is overflow"<<endl;
		  return;
    	}
        	back++;
			arr[back]=x;
		if(front==-1)
		 front++; 
	}
	void pop(){
		if(front==-1||front>back){
			cout<<"no element is present"<<endl;
		}
		else
    	 front++;
		
	}
	void peek(){
		if(front==-1||front>back){
			cout<<"no element is present"<<endl;
		}
		else
		  cout<<arr[front]<<endl;
	}
	bool empty(){
		if(front==-1||front>back){
			return(true);
		}
		else{
			return(false);
		}
	}
};
int main(){
	qeue q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.peek();
	q.pop();
	q.peek();
	return(0);	
}
