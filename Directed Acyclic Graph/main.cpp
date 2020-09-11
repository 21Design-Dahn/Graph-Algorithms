#include <iostream>
#include "Graph.h"

int main(){
  Graph<std::string> graph;

  Vertices<std::string> v1("a");
  Vertices<std::string> v2("b");
  Vertices<std::string> v3("c");
  Vertices<std::string> v4("d");
  Vertices<std::string> v5("e");
  Vertices<std::string> v6("f");

  v1.AddEdges(5, v2);
  v1.AddEdges(2, v3);
  v2.AddEdges(2, v3);
  v2.AddEdges(8, v5);
  v3.AddEdges(4, v4);
  v4.AddEdges(5, v6);
  v5.AddEdges(12, v6);

  
  std:: cout << VerticesCount << std:: endl;

  graph.AddVertices(v1);
  graph.AddVertices(v2);
  graph.AddVertices(v3);
  graph.AddVertices(v4);
  graph.AddVertices(v5);
  graph.AddVertices(v6);

  graph.TopologicalSort();
  graph.PrintOrdering();
  graph.PrintTopSort();
  graph.DAGShortestPath();
  
  std:: cin.get();
}