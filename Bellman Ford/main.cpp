#include <iostream>
#include "Graph.h"

int main(){
  Graph<unsigned int> graph;
  Vertices<unsigned int> v0(0);
  Vertices<unsigned int> v1(1);
  Vertices<unsigned int> v2(2);
  Vertices<unsigned int> v3(3);
  Vertices<unsigned int> v4(4);
  Vertices<unsigned int> v5(5);
  Vertices<unsigned int> v6(6);
  Vertices<unsigned int> v7(7);
  Vertices<unsigned int> v8(8);
  Vertices<unsigned int> v9(9);

  v0.AddEdges(v1, 5);
  
  v1.AddEdges(v6, 60);
  v1.AddEdges(v5, 30);
  v1.AddEdges(v2, 20);

  v2.AddEdges(v3, 10);
  v2.AddEdges(v4, 75);

  v3.AddEdges(v2, -15);

  v4.AddEdges(v9, 100);

  v5.AddEdges(v4, 25);
  v5.AddEdges(v6, 5);
  v5.AddEdges(v8, 50);

  v6.AddEdges(v7, -50);
  
  v7.AddEdges(v8, -10);

  graph.AddVertices(v0);
  graph.AddVertices(v1);
  graph.AddVertices(v2);
  graph.AddVertices(v3);
  graph.AddVertices(v4);
  graph.AddVertices(v5);
  graph.AddVertices(v6);
  graph.AddVertices(v7);
  graph.AddVertices(v8);
  graph.AddVertices(v9);

  graph.BellmanFord();
  std::cin.get();
}