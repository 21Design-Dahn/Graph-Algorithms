#include <iostream>
#include <vector>

template<typename T>
class Vertices{
  public:
    Vertices()
      : discovered(false)
    {

    }

    Vertices(T value)
      : value(value), discovered(false)
    {

    }
    void AddEdges(const Vertices<T>& edge){
      edges.push_back(edge);
    }
    
    std::vector<Vertices<T>>& GetEdges() { return edges; }
    size_t EdgesSize() const { return edges.size(); }
    void setDiscovered(bool cond) { discovered = cond; }
    bool& isDiscovered() { return discovered; }
    T GetValue() const { return value; }
  private:
    T value;
    bool discovered;
    std::vector<Vertices<T>> edges;
};

template<typename T>
class Graph{
  public:
    Graph(){

    }

    void SetStart(const Vertices<T>& s){
      start = s;

      graph.push_back(start);
    }

    void AddVertices(const Vertices<T>& vert){
      graph.push_back(vert);
    }

    Vertices<T>& GetStart() { return start; }
    std::vector<Vertices<T>>& GetGraph() { return graph; }
    size_t GraphSize() { return graph.size(); }
  private:
    Vertices<T> start;
    Vertices<T> end;
    std::vector<Vertices<T>> graph;
};