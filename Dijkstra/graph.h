#include <iostream>
#include <vector>
#include <utility>
#include <limits.h>
#include <queue>
#include <algorithm>

static unsigned int VerticesCount = 0;

template <typename T>
class Vertices{
  public:
    Vertices() { }
    Vertices(T value)
      : value(value)
      {
        index = VerticesCount;
        VerticesCount++;
      }

    void AddEdges(const Vertices<T>& vertices, unsigned int weight){
      edges.push_back(std::make_pair(vertices, weight));
    }

    std::vector<std::pair<Vertices<T>, unsigned int>> GetEdges() const { return edges; }
    T GetValue() const { return value; }
    unsigned int GetIndex() const { return index; }
  private:
    T value;
    unsigned int index;
    // Edge of this vertices and weight
    std::vector<std::pair<Vertices<T>, unsigned int>> edges;
};

struct PairComparer{
  bool operator()(const std::pair<unsigned int, unsigned int>& lhs, 
    const std::pair<unsigned int, unsigned int>& rhs){
    
    return lhs.second > rhs.second;
  }
};

struct DistPrev{
  int size = 0;
  unsigned int* dist = new unsigned int[size];
  int* prev = new int[size];
};

template <typename T>
class Graph{
  public:
    void AddVertices(const Vertices<T>& vertices){
      collections.push_back(vertices);
    }

    void ShowShortestPath() {
      std::vector<int> path = FindShortestPath(end);
      for(auto p : path){
        std:: cout << collections[p].GetValue() << " ";
      }
      std:: cout << "\n";
    }

    void DijkstraStopEarly(){
      bool visited[Size()];
      for(unsigned int i = 0; i < Size(); i++) { visited[i] = false; }
      unsigned int dist[Size()];
      for(unsigned int i = 0; i < Size(); i++) { dist[i] = UINT_MAX; }

      dist[0] = 0;
      std::priority_queue<std::pair<unsigned int, unsigned int>,
        std::vector<std::pair<unsigned int, unsigned int>>, 
        PairComparer> pq;
      
      pq.push(std::make_pair(0, 0));

      while(!pq.empty()){
        auto top = pq.top();
        pq.pop();

        int index = top.first;
        unsigned int minValue = top.second;
        visited[index] = true;
        if(dist[index] < minValue) { continue; }
        for(auto edge : collections[index].GetEdges()){
          auto edgeTo = edge.first.GetIndex();
          if(visited[edgeTo]) { continue; }
          unsigned int newDist = dist[index] + edge.second;

          if(newDist < dist[edgeTo]){
            dist[edgeTo] = newDist;
            pq.push(std::make_pair(edgeTo, newDist));
          }
        }
      }

      if(top.GetIndex() == end.GetIndex()){
        std:: cout << "found : " << top.GetValue() << std:: endl;
        return;
      }
    }

    void SetEnd(const Vertices<T>& vertices) { end = vertices; }
    size_t Size() const { return collections.size(); }

  private:
    DistPrev DijkstraShortestPath(){
      bool visited[Size()];
      for(unsigned int i = 0; i < Size(); i++) { visited[i] = false; }
      unsigned int dist[Size()];
      for(unsigned int i = 0; i < Size(); i++) { dist[i] = UINT_MAX; }

      int prev[Size()];
      for(unsigned int i = 0; i < Size(); i++) { prev[i] = -1; }

      dist[0] = 0;
      std::priority_queue<std::pair<unsigned int, unsigned int>,
        std::vector<std::pair<unsigned int, unsigned int>>, 
        PairComparer> pq;
      
      pq.push(std::make_pair(0, 0));

      while(!pq.empty()){
        auto top = pq.top();
        pq.pop();

        int index = top.first;
        unsigned int minValue = top.second;
        visited[index] = true;
        if(dist[index] < minValue) { continue; }
        for(auto edge : collections[index].GetEdges()){
          auto edgeTo = edge.first.GetIndex();
          if(visited[edgeTo]) { continue; }
          unsigned int newDist = dist[index] + edge.second;

          if(newDist < dist[edgeTo]){
            prev[edgeTo] = index;
            dist[edgeTo] = newDist;
            pq.push(std::make_pair(edgeTo, newDist));
          }
        }
      }
      
      DistPrev d;
      d.size = Size();
      d.dist = dist;
      d.prev = prev;
      return d;
    }

    std::vector<int> FindShortestPath(const Vertices<T>& end){
      auto data = DijkstraShortestPath();
      unsigned int dist[Size()];
      for(unsigned int i = 0; i < Size(); i++) { dist[i] = data.dist[i]; }
      int prev[Size()];
      for(unsigned int i = 0; i < Size(); i++) { prev[i] = data.prev[i]; }

      std::vector<int> path;
      unsigned int endIndex = end.GetIndex();
      if(dist[endIndex] == UINT_MAX){ return path; }
      for(unsigned int at = endIndex; at != -1; at = prev[at]){
        path.push_back(at);
      }

      std::reverse(path.begin(), path.end());
      return path;
    }

  private:
    Vertices<T> end;
    std::vector<Vertices<T>> collections;
};