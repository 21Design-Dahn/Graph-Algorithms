#include <vector>
#include <iostream>

template<typename T>
class Vertices{
  public:
  Vertices(T value)
    : value(value)
  {
  }

  void AddEdges(Vertices<T>& edge){
    edges.push_back(edge);

    edge.GetEdges().push_back(*this);
  }

  void PrintEdges() {
    std:: cout << Value() << " ----> ";
    for(auto e : edges){
      std:: cout << e.Value() << " ";
    }

    std:: cout << " " << std:: endl;
  }

  T Value() const { return value; }
  std::vector<Vertices<T>>& GetEdges() { return edges; }
  private:
    std::vector<Vertices<T>> edges;
    T value;
};

template<typename T>
class AdjacencyList{
  public:
    AdjacencyList(){

    }

    void AddVertices(Vertices<T> v){
      collections.push_back(v);
    }

    void Print(){
      for(auto c : collections){
        c.PrintEdges();
      }
    }
    size_t Size() const { return collections.size(); }
  private:
    std::vector<Vertices<T>> collections;
};