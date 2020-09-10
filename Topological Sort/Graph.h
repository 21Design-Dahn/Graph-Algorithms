#include <vector>
#include <algorithm>

template<typename T>
class Vertices{
  public:
    Vertices(T value)
      : value(value)
    {

    }

    void AddEdges(const Vertices<T>& v) const{
      edges.push_back(v);
    }

    void PrintEdges() const {
      for(auto e: edges){
        std:: cout << e.Value() << std:: endl;
      }
    }

    bool operator== (const Vertices<T>& other){
      return value == other.Value();
    }

    std:: vector<Vertices<T>> GetEdges() const { return edges; }
    size_t EdgesSize() const { return edges.size(); }
    T Value() const { return value; }
  private:
    mutable std::vector<Vertices<T>> edges;
    T value;
};

template<typename T>
class Graph{
  public:

    void TopologicalSort(){
      size = collections.size(); 
      bool visited[size];
      for(unsigned int i = 0; i < size; i++){
        visited[i] = false;
      }

      unsigned int ordering[size];
      for(unsigned int i = 0; i < size; i++){
        ordering[i] = 0;
      }

      unsigned int index = size - 1;
      for(unsigned int at = 0; at < size; at++){
        if(visited[at] == false){
          index = DFS(index, at, visited, ordering);
        }
      }

      for(unsigned int i = 0; i < size; i++){
        TopSort.push_back(collections[ordering[i]]);
      }
    }

    void AddNode(const Vertices<T>& a){
      collections.push_back(a);
    }

    void AddNode(const Vertices<T>& a, const Vertices<T>& b){
      a.AddEdges(b);

      bool existsA = doesExist(a);
      bool existB = doesExist(b); 

      if(existsA){
        auto oldA = std:: find(collections.begin(), collections.end(), a);
        *oldA = a;

        if(existB){
          return;
        } else {
          collections.push_back(b);
        }

        return;
      } else {
        collections.push_back(a);

        if(existB){
          return;
        } else {
          collections.push_back(b);
        }
      }
    }

    void TopSortPrint(){ 
      for(auto t : TopSort){
        std:: cout << t.Value() << " ";
      }

      std:: cout << "\n";
    }
  private:
    bool doesExist(const Vertices<T>& vertices){
      return std:: find(collections.begin(), collections.end(), vertices) != collections.end();
    }

    unsigned int DFS(unsigned int& i, unsigned int& at, bool* visited, unsigned int* ordering){
      visited[at] = true;

      auto vertices = collections.at(at);

      if(vertices.EdgesSize() != 0){
        for(auto e : vertices.GetEdges()){
          auto edgeTo = e.Value() - 1;
          if(visited[edgeTo] == false){
            i = DFS(i, edgeTo, visited, ordering);
          }
        }
      }

      ordering[i] = at;
      return i - 1;
    }

  private:
    size_t size;
    std:: vector<Vertices<T>> TopSort;
    std:: vector<Vertices<T>> collections;
};
