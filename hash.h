//Yu Yao
//25th Apr
//PA01 Hash.h
# ifndef HASH_H
# define HASH_H

#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include <algorithm>

using namespace std;

class Hash {
    
	public:

		Hash();
		void add(string word);
		void insert(string word);
		void remove(string word);
		void search(string word);
		void rangeSearch (string s);
    
	private:
    
		const static size_t capacity = 10000;
		std::vector<pair<string,int> > table[capacity];
		size_t hash(string word) const;
		void rangeSearchhelper(string value1,string value2);
};
#endif
