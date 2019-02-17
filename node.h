#pragma once
class node
{
public:
	node(); // our basic constructor
	node(int x); // our highly utilized constructor which takes in an int and sets it to the data member variable

	int data; // holds an integer which is used by each node
	node *left; // used by some of our traversal functions to point to the left child of a node
	node *right; // similarly, our right node pointer will point to the right child of a node
	node *parent; // used by some of our traversal functions to keep track of the parent of a node

	bool visited; // used by our postorder traversal function to keep track of nodes we may have visited as we traverse
};

