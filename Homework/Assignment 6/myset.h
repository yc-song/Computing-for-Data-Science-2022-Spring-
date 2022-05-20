#pragma once

#include "bst.h"
#include "rbt.h"

class MySet {
private:
public:

	BST bst;
	RBT rbt;
  void Insert(int data);
  void Erase(int data);
  
  bool Find(int data);
  size_t Size();
};
