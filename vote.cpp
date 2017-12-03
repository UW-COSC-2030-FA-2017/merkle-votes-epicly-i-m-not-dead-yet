#include <stdio.h>
#include <fstream>
#include "pMT.cpp"
using namespace std;

int main(int argc, char **argv)
{
	string filename;
	ifstream infile;
	//pMT mTree;
	int hashSelect;
	
	cout << "enter file name: ";
	cin >> filename;
	
	cout << "which hash function (1/2/3): ";
	cin >> hashSelect;
	
	infile.open(filename);
	
	if(infile.is_open())
	{
		int size = 0;
		int time = 0;
		while(!infile.eof())
		{
			cin.getline(infile);
			size++;
		}
		pMT mTree(hashSelect, size);
		while(!infile.eof())
		{
			mTree.insert(cin.getline(infile), time);
			time++;
		}
		
		mTree.hashItAllOut();
		cout << mTree;
	}
	
	else{
		cout << "unable to open file" << endl;
	}
	
	infile.close();
	
	return 0;
}
