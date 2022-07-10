#include<bits/stdc++.h>
using namespace std;

class TrieNode{
	public:
	char data;
	TrieNode *children[26];
	bool isTerminal;
	
	TrieNode(char ch){
		data=ch;
		for(int i=0;i<26;i++){
			children[i]=NULL;
		}
		isTerminal=false;
	}
};

class Trie{
	public:
	TrieNode *root;
	Trie(){
		root=new TrieNode('\0');
	}
	
	void insertUtil(TrieNode *root,string word){
		if(word.length()==0){
			root->isTerminal=true;
			return;
		}
	
	int index=word[0]-'a';
	TrieNode *child;
	
	if(root->children[index]!=NULL){
		child=root->children[index];
	}
	else{
		child=new TrieNode(word[0]);
		root->children[index]=child;	
	}
	insertUtil(child,word.substr(1));
}
	
	void insert(string word){
		insertUtil(root,word);
	}
	
	bool searchUtil(TrieNode *root,string word){
		if(word.length()==0){
			return root->isTerminal;
		}
		int index=word[0]-'a';
		TrieNode *child;
		
		if(root->children[index]!=NULL){
			child=root->children[index];
		}
		else{
			return false;
		}
		return searchUtil(child,word.substr(1));
	}
	
	bool search(string word){
		return searchUtil(root,word);
	}
};
int main(){
	Trie *t=new Trie();
	t->insert("abcd");
	t->insert("time");
	t->insert("suru");
	t->insert("abhi");
	cout<<"Present or not:"<<t->search("abcd")<<endl;
	cout<<"Present or not:"<<t->search("ai")<<endl;
	return 0;
}
