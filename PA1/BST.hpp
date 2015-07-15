//Dominic Kuang
//cs100wdy
//PA1
//1/19/15
//BST.hpp
// This program implements a binary tree data structure. Each binary tree 
// contains one BSTTree instance and zero or more BSTNodes. It also contains
// the insert, find, destructor, and size methods.
#ifndef BST_HPP
#define BST_HPP
#include "BSTNode.hpp"
#include "BSTIterator.hpp"
#include <iostream>
using namespace std;

template<typename Data>
class BST {

protected:

  /** Pointer to the root of this BST, or 0 if the BST is empty */
  BSTNode<Data>* root;

  /** Number of Data items stored in this BST. */
  unsigned int isize;

public:

  /** define iterator as an aliased typename for BSTIterator<Data>. */
  typedef BSTIterator<Data> iterator;

  /** Default constructor.
      Initialize an empty BST.
   */
  BST() : root(0), isize(0) {  }


  /* This method deallocates memory associated with the BST by calling
      the clear method*/
  virtual ~BST() {

     clear();   
  }

  
  /* This function will search through the tree and place an element in the 
      correct location. It returns true if an element can be returned.
      Duplicate insertions is not allowed and returns false. It takes in
      a reference to a constant Data type called item. */
  virtual bool insert(const Data& item) {
         //sets pointer to temp_node as root
	 BSTNode<Data> * temp_node = root; 
	 while(true){
                //checks if root is null
		if(root == nullptr){
			root = new BSTNode<Data>(item);
			isize++;
			return true;
		}
                //checks for duplicates
		if(item == temp_node->data){
			return false;
		}
                //checks if item is smaller than data
		if(item < temp_node->data){
			if(temp_node->left){
				temp_node = temp_node->left;
				continue;
			}
			else{
                                //creates a node left of parent node
				temp_node->left = new BSTNode<Data>(item);
				temp_node->left->parent = temp_node;
				isize++;
				return true;
			}
		}
		else{
                        //checks for right node and goes right
			if(temp_node->right){
				temp_node = temp_node->right;
				continue;
			}
			else{
				temp_node->right = new BSTNode<Data>(item);
				temp_node->right->parent = temp_node;
				isize++;
				return true;
			}
		}
	}
  }


  /* This function will search through the tree and find an element in the 
      correct location. It returns the iterator pointing to the location of
      the element if the element exists, or false if it does not exist.
      It takes in a reference to a constant Data type called item. */
  iterator find(const Data& item) const {
        //sets pointer to temp_node as root
	BSTNode<Data> * temp_node = root;
	while(true){
		//checks if root is null
		if(root == nullptr)
			return end();
                //checks if item is found
		if(item == temp_node->data){
			BSTIterator<Data> it = BSTIterator<Data>(temp_node);
			return it;
		}
                //checks if item in node is smaller than data
		if(item < temp_node-> data){
                        //go left
			if(temp_node->left){
				temp_node = temp_node->left;
				continue;
			}
			else
				return end();
		}
		else{
                        //checks if right node exists and goes right
			if(temp_node->right){
				temp_node = temp_node->right;
				continue;
			}
			else
				return end();
		}
	}
	return end();
  }

  
  /* This function returns the amount of nodes in the tree */
  unsigned int size() const {
	return isize;
  }

 

  /* This function checks to see if the tree has any nodes. Returns true
     or false for indication of emptiness. */
  bool empty() const {
	if(isize == 0)
		return true;
	else
		return false;
  }

  /* This function returns an iterator pointing to the first item in the BST 
   */ 
  iterator begin() const {
    return typename BST<Data>::iterator(first(root));
  }

  /* This function returns an iterator pointing past the last item in the BST.
   */
  iterator end() const {
    return typename BST<Data>::iterator(0);
  }

  /* this function calls the inorder method passing in root as the first node*/
  void inorder() const {
    inorder(root);
  }


private:


  /* This function traverses the BST inorder, recursively left, prints, and
    then recursively right. It takes in a pointer to a BSTNode<Data> type.
   */
  void inorder(BSTNode<Data>* n) const {
	 if(n == nullptr) return 0;
	 if(n->left)
	      inorder(n->left);

         cout<< n->data <<endl;  

	 if(n->right)
	      inorder(n-right);
	
  }

  /* This methos calls the deleteAll function and passes in the root
     node as the starting node */
  void clear() {
    // Set temp to root Node
    BSTNode<Data> * temp_node = root; 
    // traverse through tree
    deleteAll(temp_node);   
  }

  /* This method findsthe first element of the BST. It takes in a 
     pointer to a BSTNode<Data> type.
   */ 
  static BSTNode<Data>* first(BSTNode<Data>* root) {
    if(root == nullptr) return 0;
    while(root->left != 0) root = root->left;
    return root;
  }

   /* This function traverses the BST postorder, recursively left, 
    then recursively right, then deletes. It takes in a pointer 
    to a BSTNode<Data> type as a parameter.
   */
  static void deleteAll(BSTNode<Data>* n) {
	if(n == nullptr)
	return;
	if(n->left)
		deleteAll(n->left);
	if(n->right)
		deleteAll(n->right);
	
	delete n;
        n = nullptr;
    /* Pseudo Code:
      if current node is null: return;
      recursively delete left sub-tree
      recursively delete right sub-tree
      delete current node
    */
  }


 };


#endif //BST_HPP
