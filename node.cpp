#include "stdafx.h"
#include "node.h"
#include <iostream>
using namespace std;
// Our general node class is relatively simple, all we need is an int to store some data for each node.
// Each node object will become a node in our tree.

// basic constructor which was originally utilized by some of our traversal methods which used stacks.
// since we aren't using those algorithms anymore, this constructor currently serves no purpose.
// I opted to keep it just incase I made future tweaks.
node::node()
{
}

// constructor which takes in an int and sets it to the member variable called data
// we'll be using this constructor to build each node.
// we also have to make sure the data we feed it is a valid integer, if so then we have a nice node object to play with.
node::node(int x)
{
	data = x; // sets the data member variable to the int we took in
}

