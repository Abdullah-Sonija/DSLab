#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;
	int height;
	Node(int val)
	{
		data=val;
		left=right=NULL;
		height=1;
	}
};

class BST
{
	Node *root;
public:
	int get_height(Node *node)
	{
		if(node==NULL) return 0;
		return node->height;
	}

	int get_balance(Node *node)
	{
		if(node==NULL) return 0;
		return get_height(node->left)-get_height(node->right);
	}

	void update_height(Node *node)
	{
		int l_h=get_height(node->left);
		int r_h=get_height(node->right);
		node->height=1+max(l_h,r_h);
	}

	Node *rotate_right(Node *y)
	{
		Node *x=y->left;
		Node *T2=x->right;
		x->right=y;
		y->left=T2;
		update_height(y);
		update_height(x);
		return x;
	}

	Node *rotate_left(Node *x)
	{
		Node *y=x->right;
		Node *T2=y->left;
		y->left=x;
		x->right=T2;
		update_height(x);
		update_height(y);
		return y;
	}

	Node *balance(Node *node)
	{
		int balance=get_balance(node);
		if(balance>1 && get_balance(node->left)>=0) return rotate_right(node);
		if(balance>1 && get_balance(node->left)<0) { node->left=rotate_left(node->left); return rotate_right(node); }
		if(balance<-1 && get_balance(node->right)<=0) return rotate_left(node);
		if(balance<-1 && get_balance(node->right)>0) { node->right=rotate_right(node->right); return rotate_left(node); }
		return node;
	}
};

int main()
{
	BST bst;
	Node *A=new Node(10);
	A->left=new Node(6);
	A->left->left=new Node(4);
	A->left->right=new Node(8);
	Node *B=new Node(10);
	B->right=new Node(16);
	B->right->left=new Node(12);
	B->right->right=new Node(18);
	A=bst.balance(A);
	B=bst.balance(B);
}

/*
--- Explanation ----
1.  Recursively visit all nodes 
2.	Calculate each node’s height
3.	Compute balance factor (left height – right height)
4.	If unbalanced, perform required rotation
5.	Return the new root of the balanced subtree

--- Rotation in x, y, and t2 nodes ---
    x:
    the child causing imbalance
    left child in LL, right child in RR
    y:
    original unbalanced node
    parent node before rotation
    t2:
    subtree that must be reattached
    e.g., right child of x (LL), left child of y (RR)

--- Types of Rotation ---
 All four types of rotations are used (LL, RR, RL, and LR)
--- Which Node Is Returned and Why ---
 The new balanced root of the subtree is returned.
After a single or double rotation, the child node (x or y) becomes the new root.
Returning this node ensures that the parent pointers in the upper recursive calls connect correctly.
This guarantees the entire BST is rebuilt in AVL form from bottom to top.
*/