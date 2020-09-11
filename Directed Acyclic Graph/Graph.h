#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <array>

static unsigned int VerticesCount = 0;

template<typename T>
class Vertices{
  public:
    Vertices(){ }
    Vertices(T value)
      : value(value)
    {
      index = VerticesCount;
      VerticesCount++;
    }

    void AddEdges(unsigned int weight, const Vertices<T>& vertices){
      edges.push_back(std::make_pair(weight, vertices));
    }
    
    void AdjacencyList(){
      for(auto e : edges){
        std:: cout << e.first < " " << e.second << std:: endl;
      }
    }

    size_t EdgesSize() const { return edges.size(); }
    std::vector<std::pair<unsigned int, Vertices<T>>>& GetEdges() { return edges; }
    unsigned int GetIndex() const { return index; }
    T Value() const { return value; }
  private:
    T value;
    unsigned int index;
    std:: vector<std::pair<unsigned int, Vertices<T>>> edges;
};

template<typename T>
class Graph{
  public:

    void AddVertices(const Vertices<T>& vertices){
      collections.push_back(vertices);
    }

    void TopologicalSort(){
      size_t size = Size();

      bool visited[size];
      for(unsigned int i = 0; i < size; i++){ visited[i] = false; }

      unsigned int order[size];
      for(unsigned int i = 0; i < size; i++){ order[i] = 0; }

      unsigned int index = size - 1;
      for(unsigned int at = 0; at < size; at++){
        if(visited[at] == false){
          index = DFS(index, at, visited, order);
        }
      }

      ordering = new unsigned int[size];
      for(unsigned int i = 0; i < size; i++){
        ordering[i] = order[i];
        TopSort.push_back(collections[order[i]]);
      }
    }

    void DAGShortestPath(){
      int dist[collections.size()];
      for(unsigned int i = 0; i < collections.size(); i++) { dist[i] = 0; }

      for(unsigned int i = 0; i < collections.size(); i++){
        int nodeIndex = ordering[i];

        if(dist[nodeIndex] > -1){
          auto AdjacencyEdges = TopSort[i].GetEdges();
          if(AdjacencyEdges.size() > 0){
            for(auto edge : AdjacencyEdges){
              int newDist = dist[nodeIndex] + edge.first;
              auto edgeTo = edge.second.GetIndex();
              if(dist[edgeTo] == 0){
                dist[edgeTo] = newDist;
              } else {
                if(dist[edgeTo] > newDist){
                  dist[edgeTo] = newDist;
                } else {

                }
              }
            }
          }
        }
      }

      for(unsigned int i = 0; i < collections.size(); i++){
        std:: cout << dist[i] << " ";
      }
      
      std:: cout << "\n";
    }

    void PrintOrdering() const {
      for(unsigned int i = 0; i < collections.size(); i++){
        std:: cout << ordering[i] << " ";
      }
      std:: cout << "\n";
    }

    void PrintTopSort() const {
      for(auto ts : TopSort){
        std:: cout << ts.Value() << " ";
      }
      std:: cout << "\n";
    }
    

    size_t Size() const { return collections.size(); }
  private:
    unsigned int DFS(unsigned int& index, unsigned int& at, bool* visited, unsigned int* order){
      visited[at] = true;

      auto vertices = collections.at(at);
      if(vertices.EdgesSize() != 0){
        for(auto e : vertices.GetEdges()){
          auto edgeTo = e.second.GetIndex();
          if(visited[edgeTo] == false){
            index = DFS(index, edgeTo, visited, order);
          }
        }
      }

      order[index] = at;
      return index - 1;
    }
  private:
    unsigned int * ordering;
    std:: vector<Vertices<T>> TopSort;
    std:: vector<Vertices<T>> collections;
};