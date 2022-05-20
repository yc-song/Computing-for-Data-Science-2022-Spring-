////RBT
//#include "myset.h"
//#include "bst.h"
//#include "rbt.h"
//#include <iostream>
//void MySet::Insert(int data) {
//	rbt.Insert(data);
//  // TODO: insert 'data' into set
//}
//
//void MySet::Erase(int data) {
//  // TODO: erase 'data' from set
//		RBT::Node* tmp = rbt.Search(rbt.GetRoot(), data);
//		if (tmp == NULL || tmp->key == 0) return;
//		else {
//
//		rbt.Delete(tmp);
//		rbt.size--;
//	}
//}
//
//bool MySet::Find(int data) {
//  // TODO: return true if 'data' exists in the set
//	RBT::Node* tmp = rbt.Search(rbt.GetRoot(), data);
//	if (tmp == NULL || tmp->key ==0) return 0;
//   else return 1;
//}
//
//size_t MySet::Size() {
//  // TODO: return number of elements in the set
//	return rbt.size;
//}

// BST
#include "myset.h"
#include "bst.h"
void MySet::Insert(int data) {
	bst.Insert(data);
	// TODO: insert 'data' into set
}

void MySet::Erase(int data) {
	// TODO: erase 'data' from set
	BST::Node* tmp = bst.Search(bst.GetRoot(), data);
	if (tmp != nullptr) {
		bst.Delete(tmp);
		bst.size--;
	}
	else return;
}

bool MySet::Find(int data) {
	// TODO: return true if 'data' exists in the set
	BST::Node* tmp = bst.Search(bst.GetRoot(), data);
	if (tmp == NULL) return 0;
	else return 1;
}

size_t MySet::Size() {
	// TODO: return number of elements in the set
	return bst.size;
}
