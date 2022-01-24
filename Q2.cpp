#include<bits/stdc++.h>

using namespace std;

class Node {
	public:
	int val;
	Node * left;
	Node * right;
	Node(int v){
		this->val = v;
		this->left = NULL;
		this->right = NULL;
	}
};

vector<int> post_order(Node * root){
	vector<int> res;
	if(root == NULL) return res;
	stack<Node*> stk1;
	stack<int> stk2;
	stk1.push(root);
	while(!stk1.empty()){
		Node * node = stk1.top();
		stk1.pop();
		stk2.push(node->val);
		if(node->left != NULL) stk1.push(node->left);
		if(node->right != NULL) stk1.push(node->right);
	}
	while(!stk2.empty()){
		res.push_back(stk2.top());
		stk2.pop();
	}
	return res;
}


int main(){
	Node * root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->left->right->left = new Node(7);
	root->left->right->right = new Node(8);
	for(auto i : post_order(root)){
		cout << i << " ";
	}
	cout << endl;
	return 0;	
}
