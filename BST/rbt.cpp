class Node {
private:
	Node* left;
	Node* right;
	Node* parent;
	friend class RBT;
public:
	int value;
	int color; //0: black, 1:red
	Node() { value = 0; left = nullptr; right = nullptr; color = 0; parent = nullptr;}
	Node(int _x) { value = _x; left = nullptr; right = nullptr; color = 1; parent = nullptr;}
	Node(int _x, int _color) { value = _x; left = nullptr; right = nullptr; color = _color; parent = nullptr;}
	Node(int _x, Node* _left, Node* _right, int _color, Node* _parent) { value = _x; left = _left; right = _right; color = _color; parent = _parent; }
};
class RBT {
private:
	void insert_fixup(Node* z) {
		while (z->parent->color == 1) {
			if (z->parent == z->parent->parent->left) {
				uncle = z->parent->parent->right;
				if ( uncle->color == 1) {
						std::cout << "Case 1" << std::endl;
						z->parent->color = 0;
						uncle->color = 0;
						z->parent->parent->color = 1;
						z = z->parent->parent;
					}
					else if (z == z->parent->right) {
						std::cout << "Case 2" << std::endl;
						z = z->parent;
						leftrotate(z);
					}

					std::cout << "Case 3" << std::endl;
					z->parent->color = 0;
					z->parent->parent->color = 1;
					rightrotate(z->parent->parent);
			}
			else {
					uncle = z->parent->parent->left;
					if ( uncle->color == 1) {
						std::cout << "Case 1" << std::endl;
						z->parent->color = 0;
						uncle->color = 0;
						z->parent->parent->color = 1;
						z = z->parent->parent;
					}
					else {
						std::cout << "Case 2" << std::endl;
						if (z == z->parent->left) {
							z = z->parent;
							rightrotate(z);
						}
						std::cout << "Case 3" << std::endl;
						z->parent->color = 0;
						z->parent->parent->color = 1;
						leftrotate(z->parent->parent);
				}
			}
			}
			root->color = 0;
		}

	
	void leftrotate(Node* curnode){
		Node* y = curnode->right;
		curnode->right = y->left;
		if (y->left != nullptr) {
			y->left->parent = curnode;
		}
		y->parent = curnode->parent;
		if (curnode->parent->value ==0) {
			root = y;
		}
		else if (curnode == curnode->parent->left) {
			curnode->parent->left = y;
		}
		else curnode->parent->right = y;
		y->left = curnode;
		curnode->parent = y;
	}
	void rightrotate(Node* curnode) {
		Node* y = curnode->left;
		curnode->left = y->right;
		if (y->left->value !=0) {
			if (y->right->value !=0) y->right->parent = curnode;
		}
		y->parent = curnode->parent;
		if (curnode->parent->value == 0) {
			root = y;
		}
		else if (curnode == curnode->parent->left) {
			curnode->parent->left = y;
		}
		else curnode->parent->right = y;
		y->right = curnode;
		curnode->parent = y;
	}

public:
	Node* uncle;
	Node* root;
	Node* NIL = new Node(0, 0);
	RBT() { root = NIL; };
	RBT(int x) { root =new Node(x,NIL,NIL, 0,NIL );
	}
	void insert(int _z) {
		Node* z=new Node(_z);
		Node* curnode = new Node;
		curnode=root;
		Node* parent = NIL;
		while (curnode != NIL) {
			parent = curnode;
			if (_z < curnode->value) {
				curnode = curnode->left;
			}
			else curnode = curnode->right;
		}
		(z->parent) = parent;
		if (parent == NIL) {
			root = z;
		}
		else if (_z < parent->value) {
			parent->left = z;
		}
		else parent->right = z;
		(z->left) = NIL;
		(z->right) = NIL;
		insert_fixup(z);
	}
	void deleterbt(int _x, Node *curnode) {
		if (curnode->value == _x) {
			__delete(curnode);
		}
		else if (curnode->value > _x) {
			deleterbt(_x, curnode->left);

		}
		else {
			deleterbt(_x, curnode->right);
		}
	}
	void __delete(Node* z) {
		Node* y = new Node;
		y = z; //9
		int original_color = y->color; //red
		Node* x = new Node;
		if (z->left == NIL) {
			x = z->right; 
			transplant(z, z->right); 
		}
		else if (z->right == NIL) {
			x = z->left;
			transplant(z, z->left);
		}
		else {
			y = minimum(z->right); //13
			original_color = y->color;
			x = y->right; //nil
			if (y != z->right) {

				transplant(y, y->right);
				y->right = z->right;
				y->right->parent = y;
			}
			else {
				x->parent = y; 
			}
			transplant(z, y);//9<->13
			y->left = z->left;
			y->left->parent = y;
			y->color = z->color;
		}
		if (original_color == 0) {
			delete_fixup(x);
		}

	}
	void delete_fixup(Node* x) {
		while (x != root && x->color == 0) {
			if (x == x->parent->left) {
				Node* w = x->parent->right;
				if (w->color == 1) {
						std::cout << "D Case 1" << std::endl;
						w->color = 0;
						x->parent->color = 1;
						leftrotate(x->parent);
						w = x->parent->right;
					}
				if (w->left->color == 0 && w->right->color == 0) {
					std::cout << "D Case 2" << std::endl;
					w->color = 1;
					x = x->parent;
				}
				else if (w->right->color == 0) {
					std::cout << "D Case 3" << std::endl;
					w->left->color = 0;
					w->color = 1;
					rightrotate(w);
					w = x->parent->right;
				}
				std::cout << "D Case 4" << std::endl;
				w->color = x->parent->color;
				x->parent->color = 0;
				w->right->color = 0;
				leftrotate(x->parent);
				x = root;
			}
			else {
				Node* w = x->parent->left;
				if (w->color == 1) {
						std::cout << "Case 1" << std::endl;
						w->color = 0;
						x->parent->color = 1;
						rightrotate(x->parent);
						w = x->parent->left;
					}
				if (w->left->color == 0 && w->right->color == 0) {
					std::cout << "Case 2" << std::endl;
					w->color = 1;
					x = x->parent;
				}
				else if (w->right->color == 0) {
					std::cout << "Case 3" << std::endl;
					w->left->color = 0;
					w->color = 1;
					leftrotate(w);
					w = x->parent->left;
				}
				std::cout << "Case 4" << std::endl;
				w->color = x->parent->color;
				x->parent->color = 0;
				w->left->color = 0;
				rightrotate(x->parent);
				x = root;
			}
			}
		x->color = 0;
	}
	Node* minimum(Node* curnode) {
		
		if (curnode->left == nullptr || curnode->left == NIL) return curnode;
		else minimum(curnode->left);
	}
	void transplant(Node* curnode, Node* newnode) {
		if (curnode->parent == NIL) root = newnode;
		else if (curnode->parent->left == curnode) {
			curnode->parent->left = newnode;
		}
		else curnode->parent->right = newnode;
			newnode->parent = curnode->parent;
	
	}
	void inorder() {
		__inorder(root);
	}
	void __inorder(Node* curnode) {
		if (curnode == NULL) return;
		else if (curnode != NULL) {
			__inorder(curnode->left);
			visit(curnode);
			__inorder(curnode->right);
		}
	}
	void visit(Node* curnode) {
		std::cout << (curnode->value) << " ";
	}
};