#include<iostream>
using namespace std;
class node
{ 
    public:
	int data;
	node *next;
};
class Stack
{
	node *front;
	public:
	Stack()
	{
		front=NULL;
	}
	void push(int);
	void pop();
	void top();
};
void Stack::push(int d)
{
	node *temp;
	temp=new node();
	temp->data = d;
	if(front==NULL)
	{
		temp->next=NULL;
	}
	else
	{
		temp->next=front;
	}
	front=temp;
}
void Stack::pop()
{
	if(front == NULL)
		cout << "Underflow\n";
	
	else
	{
		node *temp=front;
		front=front->next;
		delete(temp);
	}
}
void Stack::top()
{
	cout<<front->data;
}
int main(){
	Stack st;
	st.push(4);
	st.push(5);
	st.push(7);
	st.top();
}
