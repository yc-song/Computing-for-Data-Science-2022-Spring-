#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <array>
#include < list>
#include <queue>
#include <map>
#include <cmath>
#include <utility>
#include <set>
#include <stdio.h>
#include <cstdlib>
using namespace std;
class node
{
private:
	int* color = new int; //white: 0, gray: 1, black:2
	int* id = new int;
	int* distance = new int;
	int* finish = new int;
	node* parent = nullptr;
	list<node> link;
public:

	friend class graph;
	node() { *id = 19; *color = 0; *distance = 0; *finish = 0; };
	node(int _id) { *id = _id; *color = 0; *distance = 0; *finish = 0; };
};
class graph {
private:
	int* size = new int;
	node nodearr[20];
	node nodetranspose[20];
	list<int> ssc;
	int count = 0;
	int time = 0;
	list<int> topsort;
public:
	graph(int _size) { *size = _size; };
	void setnode(int s) {
		node temp(s);
		nodearr[count] = temp;
		nodetranspose[count++] = temp;
	};
	void bft_setconnect(int i, int j) {
		if (i != j) {
			(nodearr[i].link).push_back(nodearr[j]);
			(nodearr[j].link).push_back(nodearr[i]);
		}
	};
	void dft_setconnect(int i, int j) { //i to j
		(nodearr[i].link).push_back(nodearr[j]);
		(nodetranspose[j].link).push_back(nodetranspose[i]);
	};
	void viewcontent(void) {
		for (int i = 0; i < *size; i++) {
			node* curnode = &nodearr[i];
			cout << "node id " << *(curnode->id) << endl;
			cout << "node color " << *(curnode->color) << endl;
			cout << "node time (" << *(curnode->distance) << ",";
			cout << *(curnode->finish) << ")" << endl;

			list<node>::iterator iter;
			list<node>lt = curnode->link;
			//for (iter = lt.begin(); iter != lt.end(); iter++) {
			//	cout << "connected to" << *(iter->id) 
			//		<< " " << endl;
			//}
		}
	}
	void viewtranspose(void) {
		for (int i = 0; i < *size; i++) {
			node* curnode = &nodetranspose[i];
			cout << "node id " << *(curnode->id) << endl;
			cout << "node color " << *(curnode->color) << endl;
			cout << "node time (" << *(curnode->distance) << ",";
			cout << *(curnode->finish) << ")" << endl;

			list<node>::iterator iter;
			list<node>lt = curnode->link;
			//for (iter = lt.begin(); iter != lt.end(); iter++) {
				//cout << "connected to" << *(iter->id) 
					//<< " " << endl;
			//}
		}
	}
	void bft(int s) {
		queue<node*> q;
		list<node>::iterator iter;
		q.push(&nodearr[s]);
		*(nodearr[s].color) = 1;
		while (q.empty() == false) {
			node* tmp = (q.front());
			q.pop();
			for (iter = tmp->link.begin(); iter != tmp->link.end(); iter++) {
				if (*(nodearr[*(iter->id)].color) == 0) {
					*(nodearr[*(iter->id)].color) = 1;

					*(nodearr[*(iter->id)].distance) = 1 + *(tmp->distance);

					nodearr[*(iter->id)].parent = tmp;
					q.push(&nodearr[*(iter->id)]);
				}
			}
			*(tmp->color) = 2;
		};




	};
	void dft(void) {
		for (int y = 0; y < *size; y++) {
			if (*(nodearr[y].color) == 0) { visit(y); }
		}
	};
	void dfttranspose(void) {
		while (topsort.empty() != true) {
			int longest = topsort.front();
			topsort.pop_front();
			if (*(nodetranspose[longest].color) == 2) {
				visittranspose(longest);
				ssc.push_back(98);

			}
		}
	};
	void visit(int s) {
		time++;
		*(nodearr[s].distance) = time;
		*(nodearr[s].color) = 1;
		list<node>::iterator iter;
		for (iter = nodearr[s].link.begin(); iter != nodearr[s].link.end(); iter++) {
			if (*(nodearr[*(iter->id)].color) == 0) {
				nodearr[*(iter->id)].parent = nodearr + s;
				visit(*(iter->id));
			}
		}
		time++;
		*(nodearr[s].finish) = time;
		*(nodearr[s].color) = 2;

	}
	void visittranspose(int s) {
		time++;
		*(nodetranspose[s].distance) = time;
		*(nodetranspose[s].color) = 1;
		list<node>::iterator iter;
		for (iter = nodetranspose[s].link.begin(); iter != nodetranspose[s].link.end(); iter++) {
			if (*(nodetranspose[*(iter->id)].color) == 2) {
				nodetranspose[*(iter->id)].parent = nodetranspose + s;
				visittranspose(*(iter->id));
				ssc.push_back(*(iter->id));
			}
		}
		ssc.push_back(s);

		time++;
		*(nodetranspose[s].finish) = time;
		*(nodetranspose[s].color) = 0;

	}
	void dft_topological_sort(void) {
		for (int y = 0; y < *size; y++) {
			if (*(nodearr[y].color) == 0) { visit_topological_sort(y); }
		}
	};
	void visit_topological_sort(int s) {
		time++;
		*(nodearr[s].distance) = time;
		*(nodearr[s].color) = 1;
		list<node>::iterator iter;
		for (iter = nodearr[s].link.begin(); iter != nodearr[s].link.end(); iter++) {
			if (*(nodearr[*(iter->id)].color) == 0) {
				nodearr[*(iter->id)].parent = nodearr + s;
				visit_topological_sort(*(iter->id));
			}
		}
		time++;
		*(nodearr[s].finish) = time;
		topsort.push_front(s);
		*(nodearr[s].color) = 2;
	}
	void topological_sort() {
		dft_topological_sort();
		list<int>::iterator iter;
		cout << "topological sort";
		for (iter = topsort.begin(); iter != topsort.end(); iter++) {
			cout << *iter << " ";
		}
		cout << endl;
	}
	void showssh() {
		list<int>::iterator iter;
		cout << "showssh ";
		for (iter = ssc.begin(); iter != ssc.end(); iter++) {
			cout << *iter << " ";

		}
		cout << endl;
	}
	void shortpath(int i, int j) {
		if (i == j) { cout << i; }
		else if (nodearr[j].parent == nullptr) { cout << "No path"; }
		else { shortpath(i, *(nodearr[j].parent->id)); cout << j; }
		cout << endl;
	}
};
