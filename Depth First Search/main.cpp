#include <iostream>
#include "Graph.h"
#include <stack>

void DFS_Iterative(const Graph<int>& graph, const Vertices<int>& start);
void DFS_Recursive(Graph<int> graph, Vertices<int> start);

Vertices<int> end(7);

int main(){
  Graph<int> graph;
  Vertices<int> start(1);
  Vertices<int> a(2);
  Vertices<int> b(3);
  Vertices<int> c(4);

  a.AddEdges(end);

  start.AddEdges(a);
  start.AddEdges(b);
  start.AddEdges(c);


  graph.SetStart(start);
  auto anotherstart = graph.GetStart();

  DFS_Recursive(graph, anotherstart);
  std:: cin.get();
}

void DFS_Iterative(const Graph<int>& graph, const Vertices<int>& start){
  std:: stack<Vertices<int>> stack;
  stack.push(start);

  while(!stack.empty()){
    auto top = stack.top();
    stack.pop();
    if(top.GetValue() == end.GetValue()){
      std:: cout << "found : " << top.GetValue() << std:: endl;
      break;
    }

    if(!top.isDiscovered()){
      top.setDiscovered(true);
      for(unsigned int index = 0; index < top.EdgesSize(); index++){
        auto edges = top.GetEdges();
        stack.push(edges[index]);
      }
    }
  }
}

void DFS_Recursive(Graph<int> graph, Vertices<int> start){
  start.setDiscovered(true);

  if(start.GetValue() == end.GetValue()){
    std:: cout << "found : " << start.GetValue() <<std:: endl;
    return;
  }

  for(unsigned int i = 0; i < start.EdgesSize(); i++){
    auto edges = start.GetEdges();
    if(!edges[i].isDiscovered()){
      DFS_Recursive(graph, edges[i]);
    }
  }
}