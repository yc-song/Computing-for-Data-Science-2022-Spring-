#include <iostream>
class Node {
private:
	Node* left;
	Node* right;
	Node* parent;
	friend class BST;
public:
	int value;
	Node() { value = 0; left = nullptr; right = nullptr; parent = nullptr; }
	Node(int _x) { value = _x; left = nullptr; right = nullptr; parent = nullptr;
	}
	Node (int _x, Node* _left, Node* _right) { value = _x; left = _left; right = _right; }
};
class BST {
private:

	Node* __search(Node* curnode, int x) {
		if (curnode == nullptr) { return 0; }
		if (x == curnode->value) { return curnode; }
		else if (x < curnode->value) { return __search(curnode->left, x); }
		else { return __search(curnode->right, x); }
		return 0;
	}
	Node* __insert(Node* curnode, int x) {
		if (curnode == nullptr) { curnode = new Node(x); }
		else if (curnode != NULL) {
			if (x < curnode->value) {
				curnode->left = __insert(curnode->left, x);
				curnode->left->parent = curnode;
			}
			else if (x >= curnode->value) {  
				curnode->right=__insert(curnode->right, x);
				curnode->right->parent = curnode;
			}
		}
		return curnode;
	}
	void __inorder(Node* curnode) {
		if (curnode == NULL) return;
		else if (curnode != NULL) {
			__inorder(curnode->left);
			visit(curnode);
			__inorder(curnode->right);
		}
	}
	void transplant(Node* curnode, Node* newnode) {
		if (curnode->parent == nullptr) root = newnode;
		else if (curnode->parent->left==curnode) {
			curnode->parent->left = newnode;
		}
		else curnode->parent->right = newnode;
		if (newnode!=nullptr) {
			newnode->parent = curnode->parent;
		}
	}
	void __preorder(Node* curnode) {
		if (curnode == NULL) return;
		else if (curnode != NULL) {
			visit(curnode);
			__inorder(curnode->left);
			__inorder(curnode->right);
		}
	}
	void __delete(Node* curnode) {
		if (curnode->left == nullptr) {
			transplant(curnode, curnode->right);
		}
		else if (curnode->right == nullptr) {
			transplant(curnode, curnode->left);
		}
		else {
			Node* tmp = minimum(curnode->right);
			if (tmp != curnode->right) {
				transplant(tmp, tmp->right);
				tmp->right = curnode->right;
				tmp->right->parent = tmp;
			}
			transplant(curnode, tmp);
			tmp->left = curnode->left;
			tmp->left->parent = tmp;
		}
	}
		Node* minimum(Node* curnode) {
			if (curnode->left == nullptr) return curnode;
			else minimum(curnode->left);
		}

public:
	  Node* root;
	BST() {root = nullptr;};
	BST(int x) { root=new Node(x); }
	void visit(Node* curnode) {
		std::cout<<(curnode->value)<<" ";
	}
	Node* search(int _x) {
		return __search(root, _x);
	}
	void insert(int _x){
		root=__insert(root, _x);
	 }
	void deletebst(int _x, Node* curnode) {
		if (curnode->value == _x) {
			__delete(curnode);
		}
		else if (curnode->value > _x) {
			deletebst(_x, curnode->left);

		}
		else {
		 deletebst(_x, curnode->right);
		}

	}
	void inorder() {
		__inorder(root);
	}
	void preorder() {
		__preorder(root);
	}
};
