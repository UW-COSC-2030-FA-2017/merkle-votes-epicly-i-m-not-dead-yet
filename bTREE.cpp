#include "bTREE.h"
#include <iostream>
#include <queue>

using namespace std;

//look at descriptions in pMT.h for guidance on what you might need for these function to actually do
bTREE::bTREE()
{
	nodeCount = 0;
	tree = NULL;
	//tracker = new queue<treeNode*>;
	tracker.push(tree); //add root to queue
	tracker.push(tree->left); //add left to queue first
	tracker.push(tree->right);
}

bTREE::~bTREE()
{
	delete(tree);
	//delete(tracker);
}

//returns nodes with data (all in this case)
int bTREE::dataInserted()
{
	return nodeCount;
}

//returns the number of nodes with tree
int bTREE::numberOfNodes() const
{
	return nodeCount;
}

//used to insert data into tree
bool bTREE::insert(string data, int time)
{
	return insert(tracker, data, time);
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
		return ".";
	}
	else
	{
		return locate(tree, input, "");
	}
	return "";
}

treeNode* bTREE::getTree()
{
	return tree;
}

void bTREE::changeTracker(queue<treeNode*> change)
{
	tracker = change;
}

//overloader for comparison
bool operator ==(const bTREE& lhs, const bTREE& rhs)
{
	if((lhs.tree == NULL && rhs.tree != NULL) || (rhs.tree == NULL && lhs.tree != NULL)) {return false;} //checks if only one side has anything
	if(lhs.tree->data != rhs.tree->data && lhs.tree->time != rhs.tree->time){return false;}
	else if(lhs.tree->left != rhs.tree->left)
	{
		return false;
	}
	else if(lhs.tree->right != rhs.tree->right)
	{
		return false;
	}
	return true;
}

//overloader for not comparison
bool operator !=(const bTREE& lhs, const bTREE& rhs)
{
	if((lhs.tree == NULL && rhs.tree != NULL) || (rhs.tree == NULL && lhs.tree != NULL)) {return true;} //checks if only one side has anything
	if(lhs.tree->data != rhs.tree->data && lhs.tree->time != rhs.tree->time){return true;}
	else if(lhs.tree->left->data != rhs.tree->left->data && lhs.tree->left->time != rhs.tree->left->time)
	{
		return true;
	}
	else if(lhs.tree->right->data != rhs.tree->right->data && lhs.tree->right->time != rhs.tree->right->time)
	{
		return true;
	}
	return false;
}

//overloader for output
ostream& operator <<(ostream& out, const bTREE& p)
{
	string prefix;
	if(p.tree == NULL)
	{
		out << "-" << endl;
		return out;
	}
	else
	{
		displayLeft(out, p.tree->left, "    ");
		out << "---" << p.tree->data << endl;
		displayRight(out, p.tree->right, "    " );
		return out;
	}
}

void bTREE::displayLeft(ostream & out, bTREE *subtree, string prefix )
{
   if(subtree->tree == NULL)
   {
      out << prefix + "/" << endl;
   }
   else
   {
      displayLeft( out, subtree->left, prefix + "     ");
      out << prefix + "/---" << subtree->tree->data << endl;
      displayRight( out, subtree->tree->right, prefix + "|    ");
   }
}

void bTREE::displayRight(ostream & out, bTREE *subtree, string prefix )
{
   if(subtree->tree == NULL)
   {
      out << prefix + "\\" << endl;
   }
   else
   {
      displayLeft(out, subtree->tree->left, prefix + "|    " );
      out << prefix + "\\---" << subtree->tree->data << endl;
      displayRight(out, subtree->tree->right, prefix + "     " );
   }
}

//helper function for insert
bool bTREE::insert(queue<treeNode*>& tempQ, string data, int time)
{
	/* recursive version of insert (replaced by queue)
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
	*/
	if(tempQ.front() == NULL)
	{
		tempQ.front()->data = data;
		tempQ.front()->time = time;
		nodeCount++;
		return true;
	}
	else if(tempQ.front()->left == NULL)
	{
		tempQ.front()->left->data = data;
		tempQ.front()->left->time = time;
		nodeCount++;
		tempQ.push(tempQ.front()->left->left);
		tempQ.push(tempQ.front()->right->right);
		return true;
	}
	else if(tempQ.front()->right == NULL)
	{
		tempQ.front()->right->data = data;
		tempQ.front()->right->time = time;
		nodeCount++;
		tempQ.push(tempQ.front()->right->left);
		tempQ.push(tempQ.front()->right->right);
		tempQ.pop();
		return true;
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