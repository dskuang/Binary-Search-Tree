//Dominic Kuang
//cs100wdy
//PA1
//1/19/15
//BSTNode.hpp
/* This program implements a BSTNode. It initializes the parent, left, and
   right pointers and also contains the successor method for an
   inorder tree traversal. */

#ifndef BSTNODE_HPP
#define BSTNODE_HPP
#include <iostream>
#include <iomanip>
template<typename Data>
class BSTNode {

public:

  /** Constructor.  Initialize a BSTNode with the given Data item,
   *  no parent, and no children.
   */
  BSTNode(const Data & d) : data(d) {
    left = right = parent = 0;
  }

  BSTNode<Data>* left;
  BSTNode<Data>* right;
  BSTNode<Data>* parent;
  Data const data;   // the const Data in this node.

  /* This function will find and return the succesor node of the current node 
     by using an inorder tree traversal. It returns null if there is no
     successor */
  BSTNode<Data>* successor() {
	BSTNode<Data>* temp_node = this;
	BSTNode<Data>* max = searchLast(temp_node);
        //checks for right node case
        if(right){
		if(!right->left){
			return right;
		}
		else{
			temp_node = right;
			while(temp_node ->left){
				temp_node = temp_node->left;
			}
		return temp_node;
		}
	}
        //checks for parent case
	else if(parent){
		temp_node = parent;
		if(this == max)
			return 0;
	
		if(this == parent->left){
			return parent;
		}
		else if( this == parent->right){
			while(temp_node->parent && 
			temp_node!= temp_node->parent->left){
				temp_node = temp_node->parent;
			}
		if(temp_node->data < data)
			return temp_node->parent;
		
		return temp_node;
		}
	}
	
	return 0;
  }


private:

/* This function will find the lastNode in the BST. It takes in the 
  current pointer to BSTNode<Data> type as the parameter and returns
  the lastnode found in the tree */
static BSTNode<Data>* searchLast(BSTNode<Data>* curr){
      BSTNode<Data>* temp_node = curr; 

  
      if(!temp_node){         
          return nullptr;
      }

      while(temp_node->parent){   
          temp_node = temp_node->parent; 
      }
    
      while(temp_node->right){      
          temp_node = temp_node->right;
      }
    
	  return temp_node;
  
}	   

}; 

/** Overload operator<< to print a BSTNode's fields to an ostream. */
template <typename Data>
std::ostream & operator<<(std::ostream& stm, const BSTNode<Data> & n) {
  stm << '[';
  stm << std::setw(10) << &n;                 // address of the BSTNode
  stm << "; p:" << std::setw(10) << n.parent; // address of its parent
  stm << "; l:" << std::setw(10) << n.left;   // address of its left child
  stm << "; r:" << std::setw(10) << n.right;  // address of its right child
  stm << "; d:" << n.data;                    // its data field
  stm << ']';
  return stm;
}

#endif // BSTNODE_HPP
