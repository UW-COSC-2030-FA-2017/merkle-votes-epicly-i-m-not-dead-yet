#pragma once

#include "bTREE.cpp"
#include <string>
#include <queue>
#include <array>
using namespace std;
class pMT
{
private:
    int selectedHash;
    bTREE myMerkle;
	
	static int pmtSize;
    
    string hash_1(string);
    string hash_2(string);
    string hash_3(string);
	
	string hashList[pmtSize]; //array of all hashes
	pair<string, int> itemList[pmtSize]; //list of all values
	
	void leafCollection(treeNode*); //adds all leaves to leafTrack
	queue<treeNode*>leafTrack;
    
public:
    pMT();
	pMT(int, int); //copy constructor
    ~pMT();
    
    
    int insert(string, int);
    
    int find(string, int, int);
    int findHash(string);
    
    string locateData(string);
	string locateHash(string);
    
    friend bool operator==(const pMT& lhs, const pMT& rhs);
    
    friend bool operator!=(const pMT& lhs, const pMT& rhs);
    
    friend pMT operator^(const pMT& lhs, const pMT& rhs);
    friend std::ostream& operator<<(std::ostream& out, const pMT& p);
    
};

