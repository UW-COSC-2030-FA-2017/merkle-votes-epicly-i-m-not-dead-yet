#include "bTREE.h"
#include <iostream>
#include <list>

using namespace std;

//look at descriptions in pMT.h for guidance on what you might need for these function to actually do
bTREE::bTREE()
{
	nodeCount = 0;
	tree = NULL;
}

bTREE::~bTREE()
{
	destroy(tree);
}

int bTREE::dataInserted()
{
	return 0;
}

int bTREE::numberOfNodes()
{
	return nodeCount;
}

bool bTREE::insert(bTREE *temp, string data, int time)
{
	/* NEEDS WORK
	temp->data = data;
	temp->time = time;
	tree->insert(temp,tree->back);
	nodeCount++;
	return true;
	 */ 
}

bool bTREE::find(string input)
{
	bool found = false;
	return found;
}

string bTREE::locate(string input)
{
	return "";
}

bool bTREE::operator ==(const bTREE& lhs, const bTREE& rhs)
{
	if(lhs.tree->data == rhs.tree->data || lhs.tree->time == rhs.tree->time){return true;}
	else{return false;}
}

bool bTREE::operator !=(const bTREE& lhs, const bTREE& rhs)
{
	if(lhs != rhs){return true;}
	else{return false;}
}

ostream& bTREE::operator <<(ostream& out, const bTREE& p)
{
	cout << "Time: " << p.tree->time << "\nData: " << p.tree->data;
}
