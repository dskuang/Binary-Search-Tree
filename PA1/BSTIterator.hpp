//Dominic Kuang
//cs100wdy
//PA1
//1/19/15
//BSTIterator.hpp
/*This program implements the iterator methods for the BST. It allows the
  iterator to keep track of the BSTNodes in inorder traversal. It also has
  the operator overloaded methods.
*/
#ifndef BSTITERATOR_HPP
#define BSTITERATOR_HPP
#include "BSTNode.hpp"
#include <list>
#include <iterator>

template<typename Data>
class BSTIterator : public std::iterator<std::input_iterator_tag,Data> {

private:

  BSTNode<Data>* curr;

 

public:

  /** Constructor.  Use the argument to initialize the current BSTNode
   *  in this BSTIterator.*/
  
  BSTIterator(BSTNode<Data>* curr) : curr(curr)  {

  }

  //This function overloades the dereference operator to return a 
  //copy of the data item in the bstnode
  Data operator*() const {
    return curr->data;
  }
  

  //This function overloades the pre-increment operator to return a reference
  //of the inorder successor of the current BSTNode
  BSTIterator<Data>& operator++() {
    curr = curr->successor();
    return *this;
  }

  /*This function updates the BSTIterator to point to the inorder succesor 
    of the current BSTNode, and return a copy of the old, non-updated
    BSTIterator. */
  BSTIterator<Data> operator++(int) {
    BSTIterator before = BSTIterator(curr);
    ++(*this);
    return before;
  }

  //This function returns true or false indicating equality of nodes
  // in the iterator. This method takes in a BSTIterator<Daa> reference
  bool operator==(BSTIterator<Data> const & other) const {
	 return this->curr == other.curr; 
  }

   //This function returns true or false indicating inequality of nodes
  // in the iterator. This method takes in a BSTIterator<Daa> reference
  bool operator!=(BSTIterator<Data> const & other) const {
	 return this->curr != other.curr; 
  }

};

#endif //BSTITERATOR_HPP
