// two34tree.cpp
// Implementation of ADT 2-3-4 Tree
//     data object: a 2-3-4 tree (a tree containing 2-nodes,
//                  3-nodes, and 4-nodes) where a k-node has
//                  k children
//     data structure: a linked 2-3-4 tree
// note: this is not the formal definition that takes 2 pages in textbook
//     operations: create, destroy, insert, display
// Filename: two34tree.cpp
//
// class Two34TreeNode specifies and implements a node for a
//    2-3-4 tree with room for 1-3 data items from class citem and
//    0-4 children

#include "two34tree.h"
#include <iostream>
using namespace std;
// helpers -------------------------------------

void index1(Two34TreeNode*& treep, const Key& text);
void index2(Two34TreeNode*& treep, const Key& text);
void index3(Two34TreeNode*& treep, const Key& text);

// frees the heap memory of a tree
// pre: treep is assigned but may be empty
// post: all nodes in the tree with root treep
//       have been released back to the heap and
//       treep is empty
// usage: destroyTree (mroot);
void destroyTree(Two34TreeNode*& treep)
{
	
}

// shows the data in the tree in inorder
// pre: treep is assigned but may be empty
//      output is open
// post: the data items in the nodes of treep's tree
//       are printed to output in inorder
void inorder(ostream& output, Two34TreeNode* treep)			// maybe
{
	if (treep != nullptr)
    {
		inorder(output, treep -> kids[0]);
		for (int i = 0; i < 3; i++)
			output << "\t" << treep -> theTexts[i] << endl;
		inorder(output, treep -> kids[1]);
		for (int i = 0; i < 3; i++)
			output << "\t" << treep -> theTexts[i] << endl;		
		inorder(output, treep -> kids[2]);
		for (int i = 0; i < 3; i++)
			output << "\t" << treep -> theTexts[i] << endl;
		inorder(output, treep -> kids[3]);
		for (int i = 0; i < 3; i++)
			output << "\t" << treep -> theTexts[i] << endl;
    }
}

// shows the data in the tree in its tree structure
// pre: output is open. treep is assigned a tree.
//      level is assigned
// post: the data items of the nodes of treep at level
//       in the tree are printed to output with spacing
//       to denote the level.
// usage: pretty (output, mroot, 1);
void pretty(ostream& output, Two34TreeNode* treep, int level)		// maybe
{
	if (treep != nullptr)
	{
		if (treep -> kids[3] != nullptr)
			pretty(output, treep -> kids[3], (level + 1));
		if (treep -> kids[2] != nullptr)
			pretty(output, treep -> kids[2], (level + 1));
		if (treep -> kids[2] == nullptr && treep -> kids[1] != nullptr)
			pretty(output, treep -> kids[1], (level + 1));
		if (level == 0)
		{
			output << "root -> " << treep -> theTexts[0];
			for (int i = 1; i < 3; i++)
				output << " " << treep -> theTexts[i];
			output << endl;
		}
        else
		{
            output << "\t";
            for (int i = 0; i < level; i++)
			    output << "\t\t";
			for (int i = 0; i < 3; i++)
				output << " " << treep -> theTexts[i];
			output << endl;
        }
		if (treep -> kids[2] != nullptr && treep -> kids[1] != nullptr)
			pretty(output, treep -> kids[1], (level + 1));
		if (treep -> kids[0] != nullptr)
			pretty(output, treep -> kids[0], (level + 1));
    }
}

// member functions or methods ------------------------------

// creates an empty 2-3-4 Tree
// post: object is empty
Two34Tree::Two34Tree()
{
	root = nullptr;
}

// destroys a 2-3-4 Tree
// pre: object exists
// post: object does not exist, all pre-memory released
Two34Tree::~Two34Tree()
{
	
}

void index1(Two34TreeNode*& treep, const Key& text)
{
	if (text < treep -> theTexts[0] && treep -> kids[0] == nullptr)
	{
	    treep -> theTexts[1] = treep -> theTexts[0];
	    treep -> theTexts[0] = text;
	}
	else if (treep -> theTexts[0] < text && treep -> kids[0] == nullptr)
		treep -> theTexts[1] = text;
	else if (text < treep -> theTexts[0] && treep -> kids[0] != nullptr)
	{
		treep = treep -> kids[0];
		if (treep -> textIndex == 1)
			index1(treep, text);
		if (treep -> textIndex == 2)
			index2(treep, text);
		if (treep -> textIndex == 3)
			index3(treep, text);
	}
	else if (treep -> theTexts[0] < text && treep -> kids[1] != nullptr)
	{
		treep = treep -> kids[1];
		if (treep -> textIndex == 1)
			index1(treep, text);
		if (treep -> textIndex == 2)
			index2(treep, text);
		if (treep -> textIndex == 3)
			index3(treep, text);
	}
}

void index2(Two34TreeNode*& treep, const Key& text)
{
	if(treep -> theTexts[0] < text && text < treep -> theTexts[1])
	{
		treep -> theTexts[2] = treep -> theTexts[1];
		treep -> theTexts[1] = text;
	}
	else if(treep -> theTexts[0] < text && treep -> theTexts[1] < text)
		treep -> theTexts[2] = text;
	else if(text < treep -> theTexts[0] && text < treep -> theTexts[1])
	{
		treep -> theTexts[2] = treep -> theTexts[1];
		treep -> theTexts[1] = treep -> theTexts[0];
		treep -> theTexts[0] = text;
	}	
}

void index3(Two34TreeNode*& treep, const Key& text)
{
	Key tmp0 = treep -> theTexts[0];
	Key tmp2 = treep -> theTexts[2];
			
	Two34TreeNode* kid0 = new (nothrow) Two34TreeNode(tmp0);
	Two34TreeNode* kid2 = new (nothrow) Two34TreeNode(tmp2);
			
	treep -> cleanUpNode();
	treep -> kids[0] = kid0;
	treep -> kids[1] = kid2;
						
	if (text < treep -> theTexts[0])
	{
		treep = treep -> kids[0];
		if (treep -> textIndex == 1)
			index1(treep, text);
		if (treep -> textIndex == 2)
			index2(treep, text);
	}
	else if (treep -> theTexts[0] < text)
	{
		treep = treep -> kids[1];
		if (treep -> textIndex == 1)
			index1(treep, text);
		if (treep -> textIndex == 2)
			index1(treep, text);
	}	
}

// adds a new key into the tree
// pre: tree object exists. text is assigned.
// post: text is placed in the appropriately sorted
//       position in the 2-3-4 tree object
// usage: tree.addNewEntry(mytext);
void Two34Tree::addNewEntry(const Key& text) throw (Exception)
{
	Two34TreeNode* treep = root;
	
	if (treep == nullptr)
	{
		treep = new (nothrow) Two34TreeNode();
		treep -> theTexts[0] = text;	
		root = treep;
	}
	else
	{
		if (treep -> textIndex == 1)
		    index1(treep, text);
		else if(treep -> textIndex==2)
			index2(treep, text);	
		else if (treep -> textIndex == 3)
			index3(treep, text);
		//else if(treep-> textIndex == 4)
			//index2(treep, text);
	}
	treep -> textIndex++;
}

// displays a tree in one of two formats
// pre: which is either 'i' or 'p'
//      output is open
// post: if which is 'i' the tree is displayed inorder
//       else the tree is displayed showing its tree
//       structure
// usage: tree.display (cout, 'p');
void Two34Tree::display(ostream& output, char which)
{
	if (which == 'p')
		pretty(output, root, 0);
	if (which == 'i')
		inorder(output, root);
}
