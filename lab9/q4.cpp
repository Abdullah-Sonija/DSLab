#include <iostream>
#include <algorithm> // for using the max fn
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
	int getBalance(Node *n) { return n ? getHeight(n->left) - getHeight(n->right) : 0; }

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

	void inorder(Node *node,int &k,int &result)
	{
		if(!node) return;
		inorder(node->left,k,result);
		k--;
		if(k==0) { result = node->key; return; }
		inorder(node->right,k,result);
	}

	int countNodes(Node *node)
	{
		if(!node) return 0;
		return 1 + countNodes(node->left) + countNodes(node->right);
	}

public:
	AVLTree() { root = nullptr; }

	void insert(int key) { root = insertNode(root,key); }

	int kthSmallest(int k)
	{
		int result = -1;
		int k_copy = k;
		inorder(root,k_copy,result);
		return result;
	}

	int kthLargest(int k)
	{
		int n = countNodes(root);
		return kthSmallest(n-k+1);
	}

	void printHeights()
	{
		cout<<"Left height from root: "<<getHeight(root->left)<<endl;
		cout<<"Right height from root: "<<getHeight(root->right)<<endl;
	}

	void displayInorder(Node *node)
	{
		if(!node) return;
		displayInorder(node->left);
		cout<<node->key<<" ";
		displayInorder(node->right);
	}

	void displayTree() { displayInorder(root); cout<<endl; }
};

int main()
{
	AVLTree tree;
	int keys[] = {50,30,70,20,40,60,80};
	for(int k : keys) tree.insert(k);

	int k = 3;
	cout<<"Inorder traversal: "; tree.displayTree();
	cout<<"kth smallest: "<<tree.kthSmallest(k)<<endl;
	cout<<"kth largest: "<<tree.kthLargest(k)<<endl;
	tree.printHeights();

	return 0;
}
