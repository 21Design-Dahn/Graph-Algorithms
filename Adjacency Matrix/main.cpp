#include <iostream>
#include "AdjacencyMatrix.h"

int main(){
  Graph<unsigned int> graph;
  Vertices<unsigned int> v0(0);
  Vertices<unsigned int> v1(1);
  Vertices<unsigned int> v2(2);
  Vertices<unsigned int> v3(3);

  v2.AddEdges(v3);
  v0.AddEdges(v1);
  v0.AddEdges(v2);

  v0.GetList();
  v0.PrintList();
  
  graph.AddVertices(v0);
  graph.AddVertices(v1);
  graph.AddVertices(v2);
  graph.AddVertices(v3);

  graph.GetMatrix();
  graph.PrintMatrix();

  std:: cin.get();
}