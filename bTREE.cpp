#include "bTREE.h"
#include <iostream>
#include <list>

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
	tree->insert(temp,tree->back);
	nodeCount++;
	return true;
}

bool bTREE::find(string)
{
	bool found = false;
	return found;
}

string bTREE::locate(string target)
{
	return "";
}

bool bTREE::operator ==(const bTREE& lhs, const bTREE& rhs)
{
	if(lhs == rhs){return true;}
	else{return false;}
}

bool bTREE::operator !=(const bTREE& lhs, const bTREE& rhs)
{
	if(lhs != rhs){return true;}
	else{return false;}
}

std::ostream& bTREE::operator <<(std::ostream& out, const bTREE& p)
{
	
}
