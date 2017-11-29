#include "bTREE.h"
#include <iostream>
#include <queue>

using namespace std;

//look at descriptions in pMT.h for guidance on what you might need for these function to actually do
bTREE::bTREE()
{
	nodeCount = 0;
	tree = NULL;
}

bTREE::~bTREE()
{
	delete(tree);
}

//returns nodes with data (all in this case)
int bTREE::dataInserted()
{
	return nodeCount;
}

//returns the number of nodes with tree
int bTREE::numberOfNodes()
{
	return nodeCount;
}

//used to insert data into tree
bool bTREE::insert(string data, int time)
{
	return insert(tree, data, time);
}

//returns if the input is in the tree
bool bTREE::find(string input)
{
	return find(tree, input);
}

//returns the path of the location of input (if found in tree)
string bTREE::locate(string input)
{
	if(!find(input))
	{
		return "-";
	}
	else
	{
		return locate(tree, input, "");
	}
	return "";
}

//overloader for comparison
bool operator ==(const bTREE& lhs, const bTREE& rhs)
{
	if(lhs.tree->data == rhs.tree->data && lhs.tree->time == rhs.tree->time){return true;}
	else{return false;}
}

//overloader for not comparison
bool operator !=(const bTREE& lhs, const bTREE& rhs)
{
	if(lhs.tree->data != rhs.tree->data || lhs.tree->time != rhs.tree->time){return true;}
	else{return false;}
}

//overloader for output
ostream& operator <<(ostream& out, const bTREE& p)
{
	cout << "Time: " << p.tree->time << "\nData: " << p.tree->data;
	return out;
}

//helper function for insert
bool bTREE::insert(treeNode *temp, string data, int time)
{
	if(temp == NULL)
	{
	temp->data = data;
	temp->time = time;
	nodeCount++;
	return true;
	}
	else if(temp->left == NULL)
	{
		insert(temp->left, data, time);
	}
	else if(temp->left->left == NULL)
	{
		insert(temp->left->left, data, time);
	}
	else if(temp->left->right == NULL)
	{
		insert(temp->left->right, data, time);
	}
	else if(temp->right == NULL)
	{
		insert(temp->right, data, time);
	}
	else if(temp->right->left == NULL)
	{
		insert(temp->right->left, data, time);
	}
	else if(temp->right->right == NULL)
	{
		insert(temp->right->right, data, time);
	}
	return false;
}

//helper function for find
bool bTREE::find(treeNode *temp, string input)
{
	if(temp->data == input)
	{
		return true;
	}
	if(temp->left != NULL)
	{
		find(temp->left, input);
	}
	if(temp->right != NULL)
	{
		find(temp->right, input);
	}
	return false;
}

//helper function for locate
string bTREE::locate(treeNode *temp, string input, string path)
{
	if(temp->data == input)
	{
	return path;
	}
	if(temp->left != NULL)
	{
		locate(temp->left, input, path+"L");
	}
	if(temp->right != NULL)
	{
		locate(temp->right, input, path+"R");
	}
	return path;
}