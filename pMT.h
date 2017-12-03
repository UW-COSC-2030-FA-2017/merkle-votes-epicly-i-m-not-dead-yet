#pragma once

#include "bTREE.cpp"
#include <string>
#include <queue>
#include <vector>
#include <stack>
using namespace std;
class pMT
{
private:
    int selectedHash;
    bTREE myMerkle;
    
    string hash_1(string);
    string hash_2(string);
    string hash_3(string);
	
	vector<string> hashList; //vector of all hashes
	vector<pair<string, int>> itemList; //list of all values
	
	void leafCollection(treeNode*); //adds all leaves to leafTrack
	void hashLocation(treeNode*); //adds parents of leaves to hLocations
	queue<treeNode*>leafTrack;
	stack<treeNode*>hLocations; //queue filled of parent nodes of leaves
    
public:
    pMT();
	pMT(int, int); //copy constructor
    ~pMT();
    
    int insert(string, int);
    
    int find(string, int, int);
    int findHash(string);
    
    string locateData(string);
	string locateHash(string);
	
	void hashItAllOut();
    
    friend bool operator==(const pMT& lhs, const pMT& rhs);
    
    friend bool operator!=(const pMT& lhs, const pMT& rhs);
    
    friend pMT operator^(const pMT& lhs, const pMT& rhs);
    friend std::ostream& operator<<(std::ostream& out, const pMT& p);
    
};

