#include <iostream>
#include <vector>
#include <limits.h>
#include <utility>

static unsigned int verticesCount = 0;
template<typename T>
class Vertices{
  public:
    Vertices(T value)
      : value(value){
        index = verticesCount;
        verticesCount++;
      }

    void AddEdges(const Vertices<T>& edge, int weight){
      edges.push_back(std::make_pair(edge, weight));
    }

    std::vector<std::pair<Vertices<T>, int>> GetEdges() const { return edges; }
    size_t EdgesSize() const { return edges.size(); }
    unsigned int GetIndex() const { return index; }
  private:
    T value;
    unsigned int index;
    std::vector<std::pair<Vertices<T>, int>> edges;
};


// E number of edges
// V number of vertices
// S starting vertex
// D array size of V that tracks the best distance from S to each vertex

template <typename T>
class Graph{
  public:
    void AddVertices(const Vertices<T>& vertices) {
      collections.push_back(vertices);
    }

    void BellmanFord(){
      dist = new int[verticesCount];
      for(unsigned int i = 0; i < verticesCount; i++) {dist[i] = INT_MAX; }
      dist[0] = 0;

      PrintDist();
      
      // Relax edge(update D with shorter path)
      for(unsigned int i = 0; i < verticesCount; i++){
        int edgeFrom = collections[i].GetIndex();

        for(auto edge : collections[i].GetEdges()){
          int edgeTo = edge.first.GetIndex();
          if(dist[edgeFrom] + edge.second < dist[edgeTo]){
            dist[edgeTo] = dist[edgeFrom] + edge.second;
          }
        }
      }

      PrintDist();

      for(unsigned int i = 0; i < verticesCount - 1; i++){
        int edgeFrom = collections[i].GetIndex();

        for(auto edge : collections[i].GetEdges()){
          int edgeTo = edge.first.GetIndex();
          if(dist[edgeFrom] + edge.second < dist[edgeTo]){
            dist[edgeTo] = INT_MIN;
          }
        }
      }

      PrintDist();
    }

    void PrintDist() const {
      for(unsigned int i = 0; i < verticesCount; i++){
        std:: cout << dist[i] << " ";
      }

      std:: cout << "\n";
    }

    size_t Size() const { return collections.size(); }
  private:
    int* dist;
    std::vector<Vertices<T>> collections;
};
