#include <iostream>
#include <string>
#include <queue>
#include "Graph.h"

int main(){
  Graph<std::string> graph;

  Node<std::string>* node1 = new Node<std::string>("mama mo");
  Node<std::string>* node2 = new Node<std::string>("papa mo");
  Node<std::string>* node3 = new Node<std::string>("tita mo");

  node1->AddEdge(node2);
  node2->AddEdge(node3);

  graph.AddNode(node1);
  graph.AddNode(node2);
  graph.AddNode(node3);

  std::queue<Node<std::string>*> queue;
  node1->searched = true;
  queue.push(node1);

  while(!queue.empty()){
    auto current = queue.front();
    if(current == node3){
      std:: cout << "found : " << node3->value << std:: endl;
    }
    for(unsigned int i = 0; i < current->GetEdgesSize(); i++){
      auto neighbor = current->edges[i];
      if(neighbor->searched == false){
        neighbor->searched = true;
        neighbor->parent = current;
        queue.push(neighbor);
      }
    }
    queue.pop();
  }

  std::vector<Node<std::string>*> path;
  path.push_back(node3);
  auto next = node3->parent;
  while(next != nullptr){
    path.push_back(next);
    next = next->parent;
  }

  for(auto& p : path){
    std:: cout << p->value << " ";
  }

  std:: cin.get();
}