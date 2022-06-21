#include <iostream>
using namespace std;

struct Node {
	int data;
	struct Node *left, *right;
};

bool iterativeSearch(struct Node* root, int key)
{
	while (root != NULL) {
		
		if (key > root->data)
			root = root->right;

		else if (key < root->data)
			root = root->left;
		else
			return true; 
	}
	return false;
}

// A utility function to create a new BST Node
struct Node* newNode(int item)
{
	struct Node* temp = new Node;
	temp->data = item;
	temp->left = temp->right = NULL;
	return temp;
}


struct Node* insert(struct Node* Node, int data)
{

	if (Node == NULL)
		return newNode(data);


	if (data < Node->data)
		Node->left = insert(Node->left, data);
	else if (data > Node->data)
		Node->right = insert(Node->right, data);


	return Node;
}


int main()
{

	struct Node* root = NULL;
	root = insert(root, 50);
	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);
	if (iterativeSearch(root, 15))
		cout << "Yes";
	else
		cout << "No";
	return 0;
}
