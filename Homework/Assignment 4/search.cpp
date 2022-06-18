#include <cstdio>
#include <vector>
#include <map>
#include <queue>
#include "search.h"
#include <iostream>
std::map<Vertex*, bool> visited_dfs;
void BFS(Vertex* start, std::map<Vertex*, unsigned int> &distance) {
  unsigned int curr;
  Vertex* vertex;
	std::queue<std::pair<Vertex*, unsigned int>> q;

  // boolean value is true when vertex is visited
  std::map<Vertex*, bool> visited;

  // root node has distance of zero
  curr = 0;
  
  // TODO: mark root node as visited
  visited[start] = 1;

  // push (root node, distance 0) pair to the queue
	q.push(std::make_pair(start, curr));

	// loop utill the queue is empty
	while (q.empty() != true) {
    // lookup front of the queue
		vertex = q.front().first;
    curr = q.front().second;

    // TODO: pop out front of the queue
    q.pop()
    ;
    for (auto adjacent : vertex->GetAdjacencyList()) {
      // when adjacent vertex is not yet visited
      if (visited[adjacent] == false) {
        // TODO: mark adjacent vertex as visited
          visited[adjacent] = true;
          


        // TODO: push (adjacent vertex, distance) pair to the queue
        q.push(std::make_pair(adjacent,1+curr))
          ;
        distance[adjacent]=1+curr;
      }
    }


    // write distance of the vertex to the map

	}
}

void DFS(Vertex* vertex, unsigned int &timestamp,
    std::map<Vertex*, unsigned int> &discovery_time,
    std::map<Vertex*, unsigned int> &finishing_time) {
  // TODO: increase timestamp for discovery time
  // TODO: store discovery time of current vertex
    discovery_time[vertex]=++timestamp;  
    visited_dfs[vertex]=1;
  // TODO: recursively call DFS for vertices in the adjancency list
  for (auto adjacent : vertex->GetAdjacencyList())
  {
      if (visited_dfs[adjacent] == 0) {
          DFS(adjacent, timestamp, discovery_time, finishing_time);
      }
  }
  ;

  // increase timestamp for finishing time
  timestamp += 1;

  // store finishing time of current vertex
  finishing_time[vertex] = timestamp;
  visited_dfs[vertex] = 2;
}
