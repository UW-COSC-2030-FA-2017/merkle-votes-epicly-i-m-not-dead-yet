#include "bTREE.h"
#include <iostream>

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

int bTREE::dataInserted()
{
	return 0;
}

int bTREE::numberOfNodes()
{
	return nodeCount;
}

bool bTREE::insert(treeNode *temp, string data, int time)
{
	if(temp == NULL)
	{
	temp->data = data;
	temp->time = time;
	nodeCount++;
	return true;
	}
	else if(data < temp->data)
	{
		insert(temp->left, data, time);
	}
	else if(data > temp->data)
	{
		insert(temp->right, data, time);
	}
	else{
		insert(temp->right, data, time);
	}
	return false;
}

bool bTREE::find(string input)
{
	return find(tree, input);
}

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

bool operator ==(const bTREE& lhs, const bTREE& rhs)
{
	if(lhs.tree->data == rhs.tree->data || lhs.tree->time == rhs.tree->time){return true;}
	else{return false;}
}

bool operator !=(const bTREE& lhs, const bTREE& rhs)
{
	if(lhs != rhs){return true;}
	else{return false;}
}

ostream& operator <<(ostream& out, const bTREE& p)
{
	cout << "Time: " << p.tree->time << "\nData: " << p.tree->data;
	return out;
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