#include <iostream>
#include <string>
#include "graph.h"

int main(){
  Graph<std::string> graph;
  Vertices<std::string> v0("a");
  Vertices<std::string> v1("b");
  Vertices<std::string> v2("c");
  Vertices<std::string> v3("d");
  Vertices<std::string> v4("e");

  v0.AddEdges(v1, 4);
  v0.AddEdges(v2, 1);
  v1.AddEdges(v3, 1);
  v2.AddEdges(v1, 2);
  v2.AddEdges(v3, 5);
  v3.AddEdges(v4, 3);

  graph.AddVertices(v0);
  graph.AddVertices(v1);
  graph.AddVertices(v2);
  graph.AddVertices(v3);
  graph.AddVertices(v4);

  graph.SetEnd(v4);
  graph.ShowShortestPath();

  std:: cin.get();
}