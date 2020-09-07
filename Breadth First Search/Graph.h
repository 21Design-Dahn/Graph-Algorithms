#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

template<typename T>
class Node{
  public:
    Node(){ 

    }

    Node(T value)
      : value(value), searched(false), parent(nullptr)
    {

    }

    void AddEdge(Node<T>* n){
      edges.push_back(n);

      n->edges.push_back(this);
    }

    bool operator==(const Node<T>& other){
      return *this = other;
    }
    
    std::vector<Node<T>*> GetEdges() { return edges; }
    size_t GetEdgesSize() { return edges.size(); }
    T GetValue() { return value; }

    std::vector<Node<T>*> edges;
    Node<T>* parent;
    bool searched;
    T value;
  private:
};

template<typename T>
class Graph{
  public:
    Graph(){

    }

    void AddNode(Node<T>* n){
      nodes.push_back(n);

      auto value = n->GetValue();
      graph[value] = n;
    }

  private:
    std::vector<Node<T>*> nodes;
    std::unordered_map<T, Node<T>*> graph;    
};
