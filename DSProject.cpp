// DSProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "node.h"
#include "tree.h"
#include <ctime>
using namespace std;


int main()
{
	node *root = new node(5); // creating a root node for our tree and giving it a value, this is the starting point for our tree
	tree *binary = new tree(); // tree object called binary, this is where our nodes will be placed
	clock_t begin; // clock_t variable used for timing all of our functions for the sake of comparing efficiency
	double inorderI, preorderI, postorderI, inorderR, preorderR, postorderR, preorderStack; // each float will hold the resulting time of each of their respective methods
	int random; // integer used to hold a random number which will then be turned into a node
	srand(time(NULL));  // used for generating random numbers

	// Our first step is to build a BST, which is done in the following for loop by iterating through a constant number, generating a random number, and inserting it into our tree object.

	// Note: The for loop below will determine the size of our tree, just change the constant to a number of your choice! I'd highly advise not building a tree over 1 million nodes, unless you feel like staring at your monitor for an hour.
	for (int i = 0; i < 1000; i++) // used for building our tree; we iterate a constant number of times to build a tree as big as we want!
	{
		random = rand() % 1000; // uses mod to generate a random number which will be turned into a node
		binary->insert(root, random); // using our tree object to call its' insert method which inserts a node into the tree, in this case we're feeding it the random number we just generated
	}

	// We now have our tree, so let's do some tests by running all of our recursive/iterative traversals and comparing the times!

	// Iterative functions begin below:

	begin = clock(); // we set our clock_t variable equal to current clock ticks
	cout << "Iterative In Order Using Morris Traversal: "; // output label to notify the user this is the result of our iterative In Order traversal
	binary->inorder(root); // calling our tree object's iterative inorder function and sending in our root node as a reference for where to begin
	cout << endl;
	inorderI = (clock() - begin) / (double) CLOCKS_PER_SEC; // we set our float equal to the result of subtracting the current clock ticks minus begin's clock ticks, then dividing by CLOCKS_PER_SEC to get a readable time

	//begin = clock(); // we set our clock_t variable equal to current clock ticks
	//cout << "Iterative Pre Order: "; // output label to notify the user this is the result of our iterative Pre Order traversal
	//binary->preorder(root); // calling our tree object's iterative Pre Order function and sending in our root node as a reference for where to begin
	//cout << endl;
	//preorderI = (clock() - begin) / (double) CLOCKS_PER_SEC; // we set our float equal to the result of subtracting the current clock ticks minus begin's clock ticks, then dividing by CLOCKS_PER_SEC to get a readable time

	begin = clock(); // we set our clock_t variable equal to current clock ticks
	cout << "Iterative Pre Order Using Stack: "; // output label to notify the user this is the result of our iterative Pre Order traversal
	binary->preorderStack(root); // calling our tree object's iterative Pre Order function and sending in our root node as a reference for where to begin
	cout << endl;
	preorderStack = (clock() - begin) / (double)CLOCKS_PER_SEC; // we set our float equal to the result of subtracting the current clock ticks minus begin's clock ticks, then dividing by CLOCKS_PER_SEC to get a readable time

	begin = clock(); // we set our clock_t variable equal to current clock ticks
	cout << "Iterative Post Order Using Bools: "; // output label to notify the user this is the result of our iterative Post Order traversal
	binary->postorder(root); // calling our tree object's iterative Post Order function and sending in our root node as a reference for where to begin
	cout << endl << endl;
	postorderI = (clock() - begin) / (double)CLOCKS_PER_SEC; // we set our float equal to the result of subtracting the current clock ticks minus begin's clock ticks, then dividing by CLOCKS_PER_SEC to get a readable time


	// Recursive methods begin below:

	begin = clock(); // we set our clock_t variable equal to current clock ticks
	cout << "Recursive In Order: ";  // output label to notify the user this is the result of our recursive In Order traversal
	binary->R_inorder(root); // calling our tree object's recursive Post Order function and sending in our root node as a reference for where to begin
	cout << endl;
	inorderR = (clock() - begin) / (double)CLOCKS_PER_SEC; // we set our float equal to the result of subtracting the current clock ticks minus begin's clock ticks, then dividing by CLOCKS_PER_SEC to get a readable time

	begin = clock(); // we set our clock_t variable equal to current clock ticks
	cout << "Recursive Pre Order: "; // output label to notify the user this is the result of our recursive Pre Order traversal
	binary->R_preorder(root); // calling our tree object's recursive Post Order function and sending in our root node as a reference for where to begin
	cout << endl;
	preorderR = (clock() - begin) / (double)CLOCKS_PER_SEC; // we set our float equal to the result of subtracting the current clock ticks minus begin's clock ticks, then dividing by CLOCKS_PER_SEC to get a readable time

	begin = clock(); // we set our clock_t variable equal to current clock ticks
	cout << "Recursive Post Order: "; // output label to notify the user this is the result of our recursive Post Order traversal
	binary->R_postorder(root); // calling our tree object's recursive Post Order function and sending in our root node as a reference for where to begin
	cout << endl;
	postorderR = (clock() - begin) / (double)CLOCKS_PER_SEC; // we set our float equal to the result of subtracting the current clock ticks minus begin's clock ticks, then dividing by CLOCKS_PER_SEC to get a readable time

	// After getting our results, let's output them in a neat fashion. That way, the user can compare the results without straining his eyes!
	// Below, we can see the time outputs of each function. They have been paired neatly together.
	cout << endl;
	cout << "In Order via Iteration: " << inorderI << " Note: Using Morris Traversal " << endl;
	cout << "In Order via Recursion: " << inorderR << endl << endl;

	cout << "Pre Order via Iteration: " << preorderStack << " Note: Using a Stack" << endl;
	cout << "Pre Order via Recursion: " << preorderR << endl << endl;

	cout << "Post Order via Iteration: " << postorderI << " Note: Using a bool" << endl;
	cout << "Post Order via Recursion: " << postorderR << endl << endl;

    return 0;
}

