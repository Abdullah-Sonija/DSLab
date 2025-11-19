/*
Initial AVL Tree : 10, 20, 30, 40, 50
After balancing during insertions, the AVL tree looks like:
        30
       /   \
     20     40
    /         \
  10           50
This tree is perfectly balanced.

Step 1 (15)
        30
       /   \
     20     40
    /         \
  10           50
    \
     15
Step 2:Update Heights bottom up
Step 3: Check Balance Factors:
	The imbalance occurs at node 20, and the new value (15) was inserted into its left subtree’s right child, making this an LR (Left-Right) case.
Step 4: Apply Rotations
Before:
  10
    \
     15
After left rotation:
    15
   /
 10
This updates the subtree under node 20:
     20
    /
  15
 /
10
After right rotation:
    15
   /  \
 10   20

Step 5: Final AVL Tree:
        30
       /   \
     15     40
    /  \      \
  10   20     50
Final Height of AVL Tree: 3
*/


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

public:
	AVLTree() { root = nullptr; }
	void insert(int key) { root = insertNode(root,key); }
	void displayTree() { displayInorder(root); cout<<endl; }
	int getHeight() { return root ? root->height : 0; }
};

int main()
{
	AVLTree tree;
	int keys[] = {10,20,30,40,50};
	for(int k : keys) tree.insert(k);
	cout<<"AVL Tree before inserting 15: ";
	tree.displayTree();
	tree.insert(15);
	cout<<"AVL Tree after inserting 15 and balancing: ";
	tree.displayTree();
	cout<<"Height of AVL Tree: "<<tree.getHeight()<<endl;
	return 0;
}
