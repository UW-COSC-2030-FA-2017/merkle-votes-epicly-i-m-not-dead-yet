#pragma once
#include <string>
#include <queue>
using namespace std;

    struct treeNode{
        string data;
        int time;
		treeNode *left;
		treeNode *right;
    };
class bTREE
{  
private:
    //some data structure to hold your treeNodes together ...
    //DATASTUCTURE treeNodes tree;
    //any helper private variables you need
	treeNode *tree;
	int nodeCount; //keeps track of current node count
	queue<treeNode*> tracker;  //used for insertion location
	
	void bTREE:: displayLeft(ostream &, treeNode*, string);
	void bTREE:: displayRight(ostream &, treeNode*, string);
    
public:
    bTREE();
    ~bTREE();
    
    int dataInserted();
    int numberOfNodes() const;
    
	bool insert(string, int);
    bool insert(queue<treeNode*>&, string, int); //helper function
    
    bool find(string);
	bool find(treeNode*, string); //helper function
    
    string locate(string);
	string locate(treeNode*, string, string); //helper function
	
	treeNode* getTree(); //accessor method for tree
	
	void changeTracker(queue<treeNode*>); //used to change the tracking queue 

    
    friend bool operator==(const bTREE& lhs, const bTREE& rhs);
    friend bool operator!=(const bTREE& lhs, const bTREE& rhs);

    friend ostream& operator<<(ostream& out, const bTREE& p);
    
};

