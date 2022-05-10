//#include <iostream>
//#include "heap.cpp"
//using namespace std;
//int main() {
//	priorityqueue h;
//	int a[] = { 9, 17, 4, 13, 16, 23, 34, 40, 5};
//	for (int i : a) {
//		h.insert(i);
//		h.buildmaxheap();
//	}	
//	for (int i = 0; i < 3; i++) {
//		cout << h.max_heap_extract_max() << endl;
//		h.showcontents();
//		std::cout << std::endl;
//	}
//	return 0;
//}

//#include <iostream>
//#include "bst.cpp"
//
//int main() {
//	BST b;
//	int a[] = {9, 17, 4, 13, 16, 23, 34, 40, 5};
//		for (int i : a) {
//			b.insert(i);
//		}
//b.deletebst(9, b.root);
//b.inorder();
//std::cout << std::endl;
//b.preorder();
//	return 0;
//}

#include <iostream>
#include "rbt.cpp"

int main() {
	RBT b(9);
	int a[] = {17, 4, 13, 16, 23, 34, 40,5};
		for (int i : a) {
			std::cout << i << std::endl;
			b.insert(i);
			b.inorder();
			std::cout << std::endl;
		}
		b.deleterbt(17, b.root);
		b.inorder();

		return 0;
}

