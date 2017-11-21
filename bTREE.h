#pragma once
#include <string>
#include <list>
using namespace std;

class bTREE
{
    struct treeNode{
        string data;
        int time;
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
    
    bool insert(string, int);
    
    bool find(string);
    
    string locate(string);
    
    
    friend bool operator==(const bTREE& lhs, const bTREE& rhs);
    friend bool operator!=(const bTREE& lhs, const bTREE& rhs);

    friend std::ostream& operator<<(std::ostream& out, const bTREE& p);
    
};

