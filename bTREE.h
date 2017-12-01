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
	int nodeCount;
	queue<treeNode*> tracker;  //used for insertion location
    
public:
    bTREE();
    ~bTREE();
    
    int dataInserted();
    int numberOfNodes();
    
	bool insert(string, int);
    bool insert(queue<treeNode*>&, string, int); //helper function
    
    bool find(string);
	bool find(treeNode*, string); //helper function
    
    string locate(string);
	string locate(treeNode*, string, string); //helper function
    
    
    friend bool operator==(const bTREE& lhs, const bTREE& rhs);
    friend bool operator!=(const bTREE& lhs, const bTREE& rhs);

    friend ostream& operator<<(ostream& out, const bTREE& p);
    
};

