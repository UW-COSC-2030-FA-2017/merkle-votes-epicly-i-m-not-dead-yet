#include "pMT.h"
#include <iostream>
#include <string>
#include <array>
#include <vector>

using namespace std;

pMT::pMT()
/**
 * @brief 
 * @param hashSelect a number corresponding to the hashfunction to use for this pMT
 * @return 
 */
{
}

//copy constructor -- creates empy tree of certain size
pMT::pMT(int hashSelect, int size)
{
	selectedHash = hashSelect;
	hashList = new string[size]; //array of all hashes
	itemList = new pair<string, int>[size]; //list of all values
	for(int i = 0; i < size*2; i++) //need to create 2x the number desired leaves to get correct build
	{
		insert("", 0.0);
		if(i > size && i < size*2)
		{
			leafCollection(myMerkle.getTree());
		}
	}
}

pMT::~pMT()
/**
 * @brief destructor
 * @return nada
 */
{
}

//adds leaf to collection
void pMT::leafCollection(treeNode *temp)
{
	leafTrack.push(temp);
}

int pMT::insert(string vote, int time)
/**
 * @brief insert a vote and time into a leaf node of tree
 * @param vote - a string
 * @param time - an int representing the time 
 * @return the number of operations needed to do the insert, -1 if out of memory
 */

{
	switch(selectedHash)
	{
	case 1:
		myMerkle.insert(hash_1(vote),time);
		for(int i = 0; i < hashList.size(); i++)
		{
			if(hashList[i] == NULL)
			{
				hashList[i] = hash_1(vote);
				itemList[i].first = vote;
				itemList[i].second = time;
				break;
			}
		}
		return 1;
	case 2:
		myMerkle.insert(hash_2(vote),time);
		for(int i = 0; i < hashList.size(); i++)
		{
			if(hashList.at(i) == NULL)
			{
				hashList[i] = hash_2(vote);
				break;
			}
		}
		return 1;
	case 3:
		myMerkle.insert(hash_3(vote),time);
		for(int i = 0; i < hashList.size(); i++)
		{
			if(hashList.at(i) == NULL)
			{
				hashList[i] = hash_3(vote);
				break;
			}
		}
		return 1;
	default:
		return -1;
	}
}

int pMT::find(string vote, int time, int hashSelect)
/**
 * @brief given a vote, timestamp, and hash function, does this vote exist in the tree?
 * @param vote, a string
 * @param time, an int
 * @param hashSelect, an int corresponding to the hash functions _1, _2, and _3
 * @return 0 if not found, else number of opperations required to find the matching vote
 */
{
	return 0;
}

int pMT::findHash(string mhash)
/**
 * @brief does this hash exist in the tree?
 * @param mhash, a string to search for in the tree
 * @return 0 if not found, else number of opperations required to find the matching hash
 */
{
	int opCount = 0; //counter for operations
	for(int i = 0; i < hashList.size(); i++)
	{
		opCount++;
		if(hashList.at(i) == mhash){break;} //stops loop if hash is found in list
	}
    return opCount;
}


string pMT::locateData(string vote)
/**
 * @brief Function takes a hash of Vote and returns the sequence of (L)eft and (R)ight moves to get to that node starting from root. 
 * @param vote, the data to search for 
 * @return sequence of L's and R's comprising the movement to the leaf node; else return a dot '.'
 */
{
	string sequence;
	return sequence;
}

string pMT::locateHash(string mhash)
/**
 * @brief Function takes a hash and returns the sequence of (L)eft and (R)ight moves to get to that node starting from root. 
 * @param mhash, the hash to search for 
 * @return sequence of L's and R's comprising the movement to the hash node, ; else return a dot '.'
 */
{
	string sequence;
	return sequence;
}


// need to make own function
string pMT::hash_1(string key)
/**
 * @brief A function that takes in a key and returns a hash of that key using some custom function
 * @param key, a string
 * @return a hash of the key
 */
{
	
	unsigned int a = 378551;
	unsigned int b = 63689;
	unsigned int hash = 0;
	
	for(size_t i = 0; i < key.length(); i++)
	{
		hash = hash * a + key[i];
		a = a * b;
	}
	
	return to_string(hash);
}

// need to make own function
string pMT::hash_2(string key)
/**
 * @brief A function that takes in a key and returns a hash of that key using some custom function
 * @param key, a string
 * @return a hash of the key
 */
{
	unsigned int hash = 0;
	
	for(size_t i = 0; i < key.length(); i++)
	{
	hash = key[i] + (hash << 6) + (hash << 16) - hash;
	}
	
	return to_string(hash);
}

// need to make own function
string pMT::hash_3(string key)
/**
 * @brief A function that takes in a key and returns a hash of that key using some custom function
 * @param key, a string
 * @return a hash of the key
 */
{
	unsigned int hash = 5381;
	
	for(size_t i = 0; i < key.length(); i++)
	{
	hash = ((hash << 5) + hash) + key[i];
	}
	
	return to_string(hash);

	return to_string(hash);
}

bool operator ==(const pMT& lhs, const pMT& rhs)
/**
 * @brief Comparison between two merkle trees
 * @param lhs, the left hand side of the equality statment
 * @param rhs, the right hand side of the equality statement
 * @return true if equal, false otherwise
 */
{
	if(lhs.myMerkle == rhs.myMerkle) {return true;}
	else{return false;}
}

bool operator !=(const pMT& lhs, const pMT& rhs)
/**
 * @brief Comparison between two merkle trees
 * @param lhs, the left hand side of the equality statment
 * @param rhs, the right hand side of the equality statement
 * @return true if not equal, false otherwise
 */
{
	if(lhs.myMerkle != rhs.myMerkle) {return true;}
	else{return false;}
}

//returns matching pMT if true, null if false (OPTIONAL)
pMT operator ^=(const pMT& lhs, const pMT& rhs)
/**
 * @brief XOR between two merkle trees
 * @param lhs, the left hand side of the equality statment
 * @param rhs, the right hand side of the equality statement
 * @return true if not equal, false otherwise
 */
{
   return lhs; 
}


ostream& operator <<(ostream& out, const pMT& p)
/**
 * @brief Print out a tree
 * @param out
 * @param p
 * @return a tree to the screen
 */
{
	cout << "";
	return out;
}


pMT operator ^(const pMT& lhs, const pMT& rhs)
/**
 * @brief Where do two trees differ
 * @param lhs
 * @param rhs
 * @return a tree comprised of the right hand side tree nodes that are different from the left
 */
{
	pMT differ;
	int limit;
	//checks for which tree is bigger, if either is
	if(lhs.myMerkle.numberOfNodes() > rhs.myMerkle.numberOfNodes())
	{
		limit = lhs.myMerkle.numberOfNodes();
	}
	else{
		limit = rhs.myMerkle.numberOfNodes();
	}
	for(int i = 0; i < limit; i++)
	{
		
	}
	return differ;
}
