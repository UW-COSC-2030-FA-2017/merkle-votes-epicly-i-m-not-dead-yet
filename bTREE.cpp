#include "bTREE.h"
#include <iostream>


//look at descriptions in pMT.h for guidance on what you might need for these function to actually do
bTREE::bTREE()
{
	nodeCount = 0;
	tree = new list<treeNode>;
}

bTREE::~bTREE()
{
	delete tree;
}

int bTREE::dataInserted()
{
	return 0;
}

int bTREE::numberOfNodes()
{
	return nodeCount;
}

bool bTREE::insert(string data, int time)
{
	treeNode temp;
	temp.data = data;
	temp.time = time;
	tree->insert(temp);
	nodeCount++;
	return true;
}

bool bTREE::find(string)
{
	return false;
}

string bTREE::locate(string target)
{
	return "";
}

friend bool bTREE::operator ==(const bTREE& lhs, const bTREE& rhs)
{
	if(lhs == rhs){return true;}
	else{return false;}
}

friend bool bTREE::operator !=(const bTREE& lhs, const bTREE& rhs)
{
	if(lhs != rhs){return true;}
	else{return false;}
}

friend std::ostream& bTREE::operator <<(std::ostream& out, const bTREE& p)
{
	
}
