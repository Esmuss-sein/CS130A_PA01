//Yu Yao
//25th APR 
//PA01 hash.cpp
# include "hash.h"
# include <algorithm>
#include<iostream>
#include<list>
using namespace std;

Hash :: Hash() {}

size_t Hash :: hash(string word) const {
	size_t accumulator = 0;
    
	for (size_t i = 0; i< word.size(); i++){
		accumulator += (word.at(i))^2;
	}
    
	return accumulator% capacity;

}

void Hash :: add(string word){
    
	int index = hash(word);
    
	for (size_t i = 0; i< table[index].size(); i++){
		if (table[index][i].first==word){
			 ++ table[index][i].second;
		return;
		}
	}
    
	table[index].push_back(pair<string,size_t>(word,1));
}
void Hash:: remove(string word){
    
	int index= hash(word);
    
	for (auto i= table[index].begin(); i!= table[index].end(); i++){
		if ((*i).first == word){
			--((*i).second);
			if ((*i).second == 0){
				table[index].erase(i);
				cout<<word<<" deleted"<<endl;
				break;
			}
			else{
				cout<<word<<" deleted, new count = "<<(*i).second<<endl;
				break;
			}
		}
	}
}
void Hash :: search(string word){
    
	int index= hash(word);
    
	for (auto i = table[index].begin(); i!= table[index].end(); i++){
		if ((*i).first == word){
			cout<<word<<" found, count = "<<(*i).second<<endl;		
			return;
		}
	}
	cout<<word<<" not found"<<endl;		
}
void Hash :: insert(string word){
    
	int index = hash(word);
    
	for (size_t i = 0; i< table[index].size(); i++){
		if (table[index][i].first==word){
			 ++ table[index][i].second;
			 cout<<word<<" inserted, new count = "<<table[index][i].second<<endl;
			return;
		}
	}
    
	table[index].push_back(pair<string,size_t>(word,1));
	cout<<word<<" inserted, new count = 1"<<endl;
}
void Hash :: rangeSearchhelper(string str1, string str2){
    
	list<string> l;
    
	for(size_t index = 0; index< capacity; index++){
		for (auto i = table[index].begin(); i!= table[index].end(); i++){
				
				l.push_back(i->first);
		}
	}
	l.sort();
    
	for (auto it=l.begin(); it!=l.end(); ++it){
		if (((*it) >= str1)&&((*it)<=str2))
			cout<< (*it) <<endl;
	}	
}

void Hash :: rangeSearch(string s){
  	string str1;
  	string str2;
  	for (size_t i = 0; i<s.length(); i++){
    	if(s.substr(i,4) == " to "){
      	str1 = s.substr(0,i);
      	str2 = s.substr(i+4);
    	}
  	}
  	rangeSearchhelper(str1,str2);
} 
