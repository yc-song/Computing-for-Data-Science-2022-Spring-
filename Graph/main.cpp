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
#include "graph.cpp"
using namespace std;
int main(void) {
	//int s = 8;
	//graph g(s);
	//for (int i = 0; i < s; i++) {
	//	g.setnode(i);
	//}
	//g.bft_setconnect(0, 1);
	//g.bft_setconnect(2, 1);
	//g.bft_setconnect(2, 3);
	//g.bft_setconnect(3, 5);
	//g.bft_setconnect(4, 5);
	//g.bft_setconnect(3, 4);
	//g.bft_setconnect(4, 6);
	//g.bft_setconnect(5, 6);
	//g.bft_setconnect(7, 6);
	//g.bft_setconnect(7, 4);
	//g.bft(2);
	//g.shortpath(2, 7);
	//g.viewcontent();

	static int s = 9;
	graph g(s);
	for (int i = 0; i < s; i++) {
		g.setnode(i);
	}
	g.dft_setconnect(0, 1);
	g.dft_setconnect(1, 2);
	g.dft_setconnect(1, 4);
	g.dft_setconnect(3, 0);
	g.dft_setconnect(3, 6);
	g.dft_setconnect( 6,4);
	g.dft_setconnect( 6,7);

	g.dft_setconnect(4, 3);
	g.dft_setconnect(4, 7);
	g.dft_setconnect(4, 5);
	g.dft_setconnect(5, 8);
	g.dft_setconnect(8, 7);
	g.dft_setconnect(5, 7);
	g.dft_setconnect(7, 5);
	g.dft_setconnect( 5,2);
	g.dft_setconnect(5, 8);
	g.dft_setconnect(8, 7);

	g.dft_topological_sort();
	g.viewtranspose();
	g.dfttranspose();
	g.showssh();




	return 0;

}
