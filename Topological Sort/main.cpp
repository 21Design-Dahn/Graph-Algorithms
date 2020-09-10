#include <iostream>
#include "Graph.h"

int main(){
  // this implementation doesnt work if the given parameter in vertices
  // is not started in 1 and it should be consecutive
  
  Graph<unsigned int> graph;
  Vertices<unsigned int> v1(1);

  Vertices<unsigned int> v2(2);
  Vertices<unsigned int> v3(3);

  Vertices<unsigned int> v4(4);
  Vertices<unsigned int> v5(5);

  Vertices<unsigned int> v6(6);

  Vertices<unsigned int> a(0);

  graph.AddNode(v1, v2);

  graph.AddNode(v2, v3);
  graph.AddNode(v2, v4);

  graph.AddNode(v3, v5);
  graph.AddNode(v3, v6);

  graph.TopologicalSort();
  graph.TopSortPrint();
  
  std:: cin.get();
}