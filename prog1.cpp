#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include "BST.h"
#include "hash.h"
using namespace std;

int main(int argv, char** argc){
	BST b1;
	Hashtable h1;
	ifstream file("/autograder/submission/PA1_dataset.txt");
	string word;
	while(getline(file, word)){
		b1.insert(word);
		h1.add(word);
	}
	file.close();
	
	stringstream ss(argc[1]);
	string s;
	while(ss.good()){
		getline(ss, s, ',');
		
		if(s.substr(0,1).compare(" ")==0){
			s = s.substr(1);
		}

		
		if(s.substr(0,6).compare("search")==0){
			b1.search(s.substr(7));
			h1.search(s.substr(7));
		}

		else if(s.substr(0,6).compare("insert")==0){
			b1.insert(s.substr(7));
			b1.insertPrint(s.substr(7));
			h1.insert(s.substr(7));
		}
		else if(s.substr(0,6).compare("delete")==0){
			b1.remove(s.substr(7));
			b1.removePrint(s.substr(7));
			h1.deletew(s.substr(7));
		}
		else if(s.substr(0,12).compare("range search")==0){
			b1.rangeSearch(s.substr(13));
			h1.rangeSearch(s.substr(13));
		}
	}
}
