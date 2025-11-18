#include <iostream>
#include <algorithm>
using namespace std;

class Node
{
public:
	int key;
	Node *left;
	Node *right;
	int height;
	Node(int k) { key = k; left = right = nullptr; height = 1; }
};

class AVLTree
{
protected:
	Node* root;
	int getHeight(Node *n) { return n ? n->height : 0; }
	int getBalance(Node *n) { return n ? getHeight(n->left)-getHeight(n->right) : 0; }

	Node* rightRotate(Node *y)
	{
		Node *x = y->left;
		Node *T2 = x->right;
		x->right = y;
		y->left = T2;
		y->height = max(getHeight(y->left),getHeight(y->right))+1;
		x->height = max(getHeight(x->left),getHeight(x->right))+1;
		return x;
	}

	Node* leftRotate(Node *x)
	{
		Node *y = x->right;
		Node *T2 = y->left;
		y->left = x;
		x->right = T2;
		x->height = max(getHeight(x->left),getHeight(x->right))+1;
		y->height = max(getHeight(y->left),getHeight(y->right))+1;
		return y;
	}

	Node* insertNode(Node *node,int key)
	{
		if(!node) return new Node(key);
		if(key < node->key) node->left = insertNode(node->left,key);
		else if(key > node->key) node->right = insertNode(node->right,key);
		else return node;

		node->height = 1 + max(getHeight(node->left),getHeight(node->right));
		int balance = getBalance(node);

		if(balance > 1 && key < node->left->key) return rightRotate(node);
		if(balance < -1 && key > node->right->key) return leftRotate(node);
		if(balance > 1 && key > node->left->key) { node->left = leftRotate(node->left); return rightRotate(node); }
		if(balance < -1 && key < node->right->key) { node->right = rightRotate(node->right); return leftRotate(node); }

		return node;
	}

	void displayInorder(Node *node)
	{
		if(!node) return;
		displayInorder(node->left);
		cout<<node->key<<" ";
		displayInorder(node->right);
	}

	void displayBalance(Node *node)
	{
		if(!node) return;
		displayBalance(node->left);
		cout<<"Node "<<node->key<<", Balance Factor: "<<getBalance(node)<<endl;
		displayBalance(node->right);
	}

public:
	AVLTree() { root = nullptr; }
	void insert(int key) { root = insertNode(root,key); }
	void displayTree() { displayInorder(root); cout<<endl; }
	void printBalanceFactors() { displayBalance(root); }
	int getHeight() { return root ? root->height : 0; }
};

int main()
{
	AVLTree tree;
	int keys[] = {10,5,15,3,7};
	for(int k : keys) tree.insert(k);
	cout<<"Initial AVL Tree: ";
	tree.displayTree();
	tree.insert(12);
	cout<<"After inserting 12: ";
	tree.displayTree();
	cout<<"Height of tree: "<<tree.getHeight()<<endl;
	cout<<"Balance factors of nodes:"<<endl;
	tree.printBalanceFactors();
	return 0;
}
