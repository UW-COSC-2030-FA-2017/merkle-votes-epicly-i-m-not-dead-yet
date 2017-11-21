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
	bool found = false;
	return found;
}

string bTREE::locate(string input)
{
	if(tree.data == input)
	{
		return "";
	}
	if(tree.left != NULL)
	{
		locate();
	}
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
