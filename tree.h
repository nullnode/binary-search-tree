#pragma once
#include "node.h"
class tree
{
	// all preconditions, postconditions, and elaborated explanations are located in the cpp file
	// generalized explanations are below, this way we can inform the general user who reads this header file without going into explicit detail.
public:

	tree();
	void insert(node *root, int data); // properly inserts a node into the binary search tree.
	void preorder(node *root); // iterative version of preorder traversal and output of our tree
	void inorder(node *root); // iterative version of inorder traversal and output of our tree
	void postorder(node *root); // iterative version of postorder traversal and output of our tree
	void preorderStack(node *root);

	void R_preorder(node *root); // recursive version of preorder traversal and output of our tree
	void R_inorder(node *root); // recursive version of inorder traversal and output of our tree
	void R_postorder(node *root); // recursive version of postorder traversal and output of our tree

private:
	node *root; // node object which lets us know where our root is located, thus giving us a starting point for traversals
	node *prev; // node object which tells us essentially which node we came from, thereby reducing operations for better efficiency
	
};

