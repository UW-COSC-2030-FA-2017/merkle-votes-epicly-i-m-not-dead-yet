#pragma once
#include <string>
using namespace std;

class bTREE
{
    struct treeNode{
        string data;
        int time;
		treeNode *left;
		treeNode *right;
		bool isLeaf();
    };
    
private:
    //some data structure to hold your treeNodes together ...
    //DATASTUCTURE treeNodes tree;
    //any helper private variables you need
	treeNode *tree;
	int nodeCount;
    
public:
    bTREE();
    ~bTREE();
    
    int dataInserted();
    int numberOfNodes();
    
    bool insert(treeNode*, string, int);
    
    bool find(string);
	bool find(treeNode*, string);
    
    string locate(string);
	string locate(treeNode*, string, string); //helper function
    
    
    friend bool operator==(const bTREE& lhs, const bTREE& rhs);
    friend bool operator!=(const bTREE& lhs, const bTREE& rhs);

    friend ostream& operator<<(ostream& out, const bTREE& p);
    
};

