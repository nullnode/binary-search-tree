#include "stdafx.h"
#include "tree.h"
#include "node.h"
#include <iostream>
#include <stack>
using namespace std;

// our basic constructor for our tree, we're setting the root to be NULL since our tree is brand new
tree::tree()
{
	root = NULL; // since we just made our tree, the root will currently be null until we manually insert a node
}

// Notes: Our insertion function uses iteration to locate the appropriate spot for a new node on our tree.
//        First, we check to see if our root is null. If so, then our new node becomes the root. 
//        Next, we loop through the tree and see whether or not our new node is larger or smaller than the left/right children of each node. 
//        Finally, we place the node in its' appropriate location. On a final note, iteration was used because recursion is a bit too easy and I like being challenged a bit.
// Precondition: We have to make sure the root object we send in is infact the root of our tree. 
//               We also must make sure the data we send in is infact an integer. If we look in main, all insertion operations are done automatically using a for loop. This is done automatically because the size of our tree varies between 10 and 10 million nodes, thus there is no need or option for user input.
// Postcondition: We succesfully add a node to our tree and place it in the appropriate location.
void tree::insert(node *root, int data)
{
	node *newNode = new node(data); // creating a new node and sending in the data int we received
	node *tempParent; // creates a temporary parent node to keep track of where we are in the tree
	node *current; // creates a node called current which helps us keep track of our current position within the tree

	if (root->data == NULL) // checks to make sure our tree has a valid root
		root = new node(data); // if our tree doesn't have a root (rather, if the data within our root is null), then we make our new node the root!
	else
	{
		current = root; // sets our current position to root, if root isn't null.
		while (true) // beginning our loop through the tree to find the appropriate spot for our new node
		{
			tempParent = current; // before we move, we set our parent to current. just incase we need to backtrack!
			if (newNode->data < current->data) // checks if our node is smaller than the node we're currently sitting on
			{
				current = current->left; // if our node is smaller than the first node we check, then we know it belongs to the left. so we move down to the left.
				if (current == NULL) // since we just moved down to the left, we need to check if current is null
				{
					tempParent->left = newNode; // if nothing exists in current (remember we moved down to the left), then we set our parent's left node to be our new node!
					newNode->parent = tempParent; // since our tempparent nodes' left child is now our new node, we need to set our new nodes parent to be tempparent
					return; // all done! lets go home!
				}
			}
			else // the if statement wasnt true? oh, so our new node is larger? okay, we should probably head right!
			{
				current = current->right; // moving down to the right, since our new node is larger than the node we checked!
				if (current == NULL) // checking to see if there is a node at our new location
				{
					tempParent->right = newNode; // if no node exists, then we set our parents' right child to be our new node!
					newNode->parent = tempParent; // sets our newnode's parent to be tempParent
					return; // all finished!
				}
			}
		}
	}
}

// Notes: This iterative version of InOrder traversal utilizes Morris Traversal, which means I did not write it from scratch.
//        Since we were given permission to use pieces of other peoples' code, I went ahead and used this algorithm.
//        The algorithm functions in a unique way, using a current node and a pre node which represents a predecessor or "previous" node.
//        The true originality of this algorithm stems from the fact that we're restructuring the tree as we traverse.
//        Afterward, the tree returns to normal.

// Precondition: We must make sure the root node we throw in is infact our root node.
// Postcondition: We output the In Order traversal of our BST (Left, Root, Right)
void tree::inorder(node *root)
{
	node *current; // node pointer which represents our current location in our tree
	node *pre; // node pointer which represents our previous (or predecessor) node, which helps us keep track of where we are

	if (root == NULL) // if our root is null, then obviously the tree is empty. thus, we return.
		return;

	current = root; // we set our current location to the root

	while (current != NULL) // we begin the first step of our traversal by making sure our location is not null
	{
		if (current->left == NULL) // we check to see if the left child node of current (which starts at root) is null
		{
			//cout << current->data << " "; // if the left child is empty, we output current's data
			printf("%d ", current->data);
			current = current->right; // we move to the right child node by setting our current location to current's right child node
			                          // this is where our while loop will iterate through again, starting over by checking if current is null
		}
		else // else statement fires off if current's left child is not null, which means we need to do some processing!
		{
			pre = current->left; // we set our pre (previously visited) pointer to current's left child, we do this preemptively since we're about to perform some operations
			while (pre->right != NULL && pre->right != current) // we check to make sure pre's right child isnt empty and also if pre's right child is not our current location
			{
				pre = pre->right; // we move pre to pre's right child node
			}

			if (pre->right == NULL) // checking to make sure pre's next right child node is null
			{
				pre->right = current; // if pre's right child is null, we set it to our current pointer
				current = current->left; // we then move current to its left child node
			}
			else // if pre's right child node is not null, then this else will fire off
			{
				pre->right = NULL; // we set pre's right child to null and prepare to output some data
				//cout << current->data << " "; // outputting current's node data
				printf("%d ", current->data);
				current = current->right; // we finally move current to it's right child node and let the while loop take over again
			}
		}
	}
}

// Deprecated preorder function. No longer in use.
void tree::preorder(node *root) 
{
	while (root) // a clean boolean expression to ensure that we loop as long as root isn't empty
	{
		if (root->left == NULL) // checking to see if roots left child is empty, if so then we do the following lines of code below
		{
			cout << root->data << " "; // outputs roots data
			root = root->right; // moving down to roots right child
		}
		else // fires off if root's left child isnt empty
		{
			node* current = root->left; // creating a current pointer to help us keep track of where we are. then, initializes it to root's left child

			while (current->right && current->right != root) // we're checking to make sure current has a right child and also making sure that child isnt root 
			{
				current = current->right; // we move current down to its right child
			}

			if (current->right == root) // checking to see if currents right child is root (remember, we're moving our pointers around for this function)
			{
				current->right = NULL; // if currents right child is our root pointer, then we set it to null (again, remember we're moving root around, which may seem counter intuitive and require a visualization)
				root = root->right; // we move root to its right child
			}

			else // fires off if currents right child is not root, which means we'll need to output some data!
			{
				cout << root->data << " "; // outputs roots data
				current->right = root; // sets currents right child node to root
				root = root->left; // moves root down to its left child node
			}
		}
	} // At this point, our while loop will begin another loop.
} // ported version of morris traversal for preorder, this is no longer being used.

  // Notes: Our new preorder function uses a stack for greater efficiency. We take in a root node and take nodes with a priority of Root, left, Right.

  // Precondition: We have to make sure our root node that gets passed in is infact the root node of our tree.
  // Postcondition: Output of a Pre Order traversal of our tree (Root, Left, Right).
void tree::preorderStack(node *root)
{
	if (root == NULL) // check to see if root is null, if so then we return
		return;

	stack<node *> nodeStack; // we're making a stack of nodes to use as a container for holding the proper order of our traversal
	nodeStack.push(root); // push root onto the stack, since our priority begins with Root.

	while (nodeStack.empty() == false) // making sure our stack isnt empty
	{
		struct node *node = nodeStack.top(); // popping the top item (equivilant of peek) 
		printf("%d ", node->data); // printing our top data value
		nodeStack.pop(); // popping the node we just printed

		// Push right and left children of the popped node to stack
		if (node->right) // checking to see if our node has a right child
			nodeStack.push(node->right); // if we have a right child, we'll push it onto the stack
		if (node->left) // checking to see if our node has a left child
			nodeStack.push(node->left); // if we have a left child, we push it onto the stack.
		// The above if statements enforce prioritization of Root -> Left -> Right. Above the if statements, we've already printed out root node.
		// Bear in mind that since we push right and THEN left, our stack structure allows left to be processed first.
	}
}

// Notes: Our iterative Post Order traversal function is a tad tricky, I had the option of using a stack or queue but I opted for a bool to track the nodes we visited.
//        I remembered how we used a "visited" bool for the breadth-first traversal and suddenly this function became infinitely easier to write.
//        Thus, I added a visited member variable to our node class and bent my brain a little bit using multiple && statements.

// Precondition: As always, we have to make sure the root node we send in to the function is infact the root node of the tree.
// Postcondition: We output the Post Order traversal of our BST (Left, Right, Root)
void tree::postorder(node *root)
{
	node *temp = root; // creating a temp node to help us keep track of where we are, we then set it to be at roots location

	while (temp && temp->visited == false) // we check to make sure temp isnt empty AND we check to make sure we havent already visited temp
	{
		if (temp->left && temp->left->visited == false) // checking to see if temp has a left child AND if so, making sure we havent visited it 
			temp = temp->left; // we move temp to its left child node, since we now know it exists and we havent been there before!
		else if (temp->right && temp->right->visited == false) // checks to see if temp has a right child AND if so, we make sure we havent been there before
			temp = temp->right; // moving temp to its right child node
		else { 
			//cout << temp->data << " "; // outputs temp's data
			printf("%d ", temp->data);
			temp->visited = true; // sets temps visited bool to true, since we just outputted the data. 
			temp = root; // moves temp to root
		}
	} // At this point, the while loop will iterate again until there are no more nodes to visit!
}


// Recursive versions of our traversals begin below.

// Notes: Since PreOrder is (Root, Left, Right), our first step is to check if our root is null and then output the data if there is any.
//        Next, we recurse to the left and then to the right.
// Precondition: Ensure that our root node is the root of our tree.
// Postcondition: Recursive output of a Pre Order traversal
void tree::R_preorder(node *root)
{
	if (root != NULL) // checking to make sure our root node isnt empty
	{
		//cout << root->data << " "; // outputting the root data, since that's the first step of PreOrder (root, left, right)
		printf("%d ", root->data);
		R_preorder(root->left); // recurse to the left child
		R_preorder(root->right); // recurse to the right child
	}
}


// Notes: We take in our root node and beautifully traverse by beginning with a call to our roots left child.
//        Eventually, we'll hit a dead end and output the data. Then, our next recurse begins on the right node.
// Precondition: We have to make sure our root node is the actual root of our tree.
// Postcondition: Recursive output of an In Order traversal
void tree::R_inorder(node* root)
{
	if (root != NULL) // implied base case, making sure our root isnt empty
	{
		R_inorder(root->left); // we recurse on the left child
		//cout << root->data << " "; // output the data of the node we're on
		printf("%d ", root->data);
		R_inorder(root->right); // recurse on the right child
	}
}

// Notes: PostOrder is (Left, Right, Root), so we begin recursing to the left child node, followed by the right. Lastly, we output our data.
// Precondition: Make sure our root node is infact the proper root node of our tree.
// Postcondition: Recursive output of a Post Order traversal.
void tree::R_postorder(node *root)
{
	if (root != NULL) // making sure root isnt empty
	{
		R_postorder(root->left); // we begin with a recurse to the left child, since PostOrder has precedence of (Left, Right, Root)
		R_postorder(root->right); // recurse to the right child
		//cout << root->data << " "; // output the data of the node we're on
		printf("%d ", root->data);
	}
}
