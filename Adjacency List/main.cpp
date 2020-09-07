#include <iostream>
#include "AdjacencyList.h"

int main(){
  AdjacencyList<std::string> list;

  Vertices<std::string> v("a");
  Vertices<std::string> v2("b");

  v.AddEdges(v2);

  list.AddVertices(v);
  list.AddVertices(v2);

  list.Print();
  std:: cin.get();
}