//YU YAO
//25th Apr
//PA01 "BST.cpp"
#include "BST.h"
using std:: cout;
using namespace std;

BST :: BST() : root(0){ }

BST :: ~BST() {
	clear (root);
}


void BST :: clear(Node* n){
	if(n){
		clear(n->left);
		clear(n->right);
		delete n;
	}
}

bool BST :: insert(string value){
	if(!root){
		root = new Node(value);
    
		return true;
	}
	return insert(value,root);
}

bool BST :: insert(string value, Node *n){
	if (value == n->info){
		n -> count ++;
		return true;
	}
 if (value < (n->info)){
 	if (n->left){
 		return insert(value, n->left);
 	}
 	else{
 		n->left = new Node(value);
 		n->left->parent =n;
 		return true;
 	}
 }
 else{
 	if(n->right){
 		return insert(value,n->right);
 	}
 	else{
 		n->right = new Node(value);
 		n->right->parent = n;
 		 return true;
 	}
 }
}

BST:: Node* BST::getNodeFor(string value, Node* n) const{
	if(n==NULL){
		return NULL;
	}
	if(n->info==value){
		return n;
	}
	Node* leftptr = getNodeFor(value, n->left);
	if(leftptr){
		return leftptr;
	}
	else{
		return getNodeFor(value, n->right);
	}	
}
bool BST::contains(string value) const { 
	return (getNodeFor(value,root)!= NULL);
}

BST::Node* BST::getPredecessor(string value) const{
	Node*tmp=getNodeFor(value,root);
  	if (tmp->left!=NULL){
       	tmp=tmp->left;
       	while(tmp->right!=NULL){
            	tmp=tmp->right;
       	}
       	return tmp;
       	}
   	else{

       	while( tmp->parent && tmp->parent->left == tmp){
            	tmp = tmp->parent;   
        	}
        if(tmp->parent) return tmp->parent;
        return NULL;
      }

}



bool BST :: remove(string value){
	Node* n=getNodeFor(value,root);
    if ((n->count) > 1) {
        n -> count--;
        return true;
    }
    if ((n->count) <= 0) {
        return false;
    }
    if(n -> count == 1){
        
    if(!n->left && !n->right){
            if(!n->parent){
                clear(root);
                root = NULL;
                return true;
            }
            if(n->parent->left == n)
                n->parent->left = NULL;
            else
                n->parent->right = NULL;
            n->parent = NULL;
            delete n;
        }
        else if(n->left && !n->right){

            if(n->parent->left == n){
                    n->parent->left = n->left;
                    n->left->parent = n->parent;
                    
                }
                else{
                    n->parent->right = n->left;
                    n->left->parent = n->parent;
                    
                }
                n->parent = NULL;
                delete n;
            }
        else if(!n->left && n->right){

            if(n->parent->left == n){
                n->parent->left = n->right;
                n->right->parent = n->parent;
                
                }
                else{
                    n->parent->right = n->right;
                    n->right->parent = n->parent;
                    
                    
                }
                n->parent = NULL;
                delete n;
            }

        else if(n->left && n->right){
            Node* temp = getPredecessor(value);
            string word = temp->info;
            temp->info = n->info;
            n->info = word;
            if(!temp->left && !temp->right){
                if(temp->parent->left == temp)
                    temp->parent->left = NULL;
                else
                    temp->parent->right = NULL;
                
                temp->parent = NULL;
                delete temp;
                
            }
            else if(temp->left && !temp->right){
                if(temp->parent->left == temp){
                    temp->parent->left = temp->left;
                    temp->left->parent = temp->parent;
                    
                }
                else{
                    temp->parent->right = temp->left;
                    temp->left->parent = temp->parent;
                    
                }
                temp->parent = NULL;
                delete temp;
            }
            else if(!temp->left && temp->right){
                if(temp->parent->left == temp){
                    temp->parent->left = temp->right;
                    temp->right->parent = temp->parent;
                    
                }
                else{
                    temp->parent->right = temp->right;
                    temp->right->parent = temp->parent;
                    
                    
                }
                temp->parent = NULL;
                delete temp;
            }
        

        }
        else if(n->left == NULL && n->right == NULL) {
            n->parent = NULL;
            root = NULL;
            delete n;
        }
        return true;
    }
}
void BST::printInOrder() const {
    printInOrder(root);
}
void BST::printInOrder(Node *n) const {
     if (n!=0){
         printInOrder(n->left);
         cout<<n->info<< " "<<n->count<<endl;
         printInOrder(n->right);
    }
}
void BST :: search(string value){
  if(Node *ptr = getNodeFor(value, root)){
  cout<< ptr->info<<" found, count = "<<ptr->count<<endl;
  }
  else{
    cout<<value<<" not found"<<endl;
  }
}

void BST :: insertPrint(string value){
  if(Node *ptr = getNodeFor(value, root)){
    cout<< ptr->info<<" inserted, new count = "<<ptr->count<<endl;
  }
} 

void BST :: removePrint(string value){
  	if(Node *ptr = getNodeFor(value, root)){
    		cout<< ptr->info<<" deleted, new count = "<<ptr->count<<endl;
  	}
  	else{
    		cout<<value<<" deleted"<<endl;
  	}
}

void BST :: rangeSearchHelper(Node *n, string str1, string str2){
	if(NULL == n) return;
	if (str1< n->info) rangeSearchHelper(n->left,str1,str2);
	if (str1 <= n->info && n->count>0 && str2 >= n->info) cout<< n->info<<endl;
 	if (str2 > n->info) rangeSearchHelper(n->right,str1,str2);
}

void BST :: rangeSearch(string s){
  	string str1;
 	string str2;
 	for (size_t i = 0; i<s.length(); i++){
   	if(s.substr(i,4) == " to "){
      		str1 = s.substr(0,i);
      		str2 = s.substr(i+4);
    		}
  	}
  	rangeSearchHelper(root, str1,str2);
} 
