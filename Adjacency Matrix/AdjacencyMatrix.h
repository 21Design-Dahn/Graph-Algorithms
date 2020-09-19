#include <vector>

static unsigned int verticesCount = 0;

template<typename T>
class Vertices{
  public:
    Vertices(T value)
      : value(value){
        index = verticesCount;
        verticesCount++;
      }
    
    void AddEdges(const Vertices<T>& edge){
      edges.push_back(edge);
    }

    void GetList(){
      list = new int[verticesCount];

      for(int i = 0; i < verticesCount; i++){ list[i] = 0; }

      for(auto edge : edges){
        for(int i = 0; i < verticesCount; i++){
          if(edge.GetIndex() == i){
            list[i] = 1;
          }
        }
      }
    }

    void PrintList() const {
      for(int i = 0; i < verticesCount; i++){
        std:: cout << list[i];
      }

      std:: cout << "\n";
    }

    int GetIndex() const { return index; }
    std::vector<Vertices<T>> GetEdges() const { return edges; }
  private: 
    T value;
    int index;
    int* list;
    std:: vector<Vertices<T>> edges;
};

template<typename T>
class Graph{
  public:

    void AddVertices(const Vertices<T>& vertices){
      collections.push_back(vertices);
    }

    void GetMatrix() {
      size_t size = Size();
      matrix = new int*[size];

      for(int i = 0; i < size; i++){ matrix[i] = new int[size]; }

      for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
          matrix[i][j] = 0;
        }
      }

      for(auto c : collections){
        for(auto edge : c.GetEdges()){
          for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
              if(edge.GetIndex() == i && c.GetIndex() == j){
                matrix[i][j] = 1;
              }
              if(edge.GetIndex() == j && c.GetIndex() == i){
                matrix[i][j] = 1;
              }
            }
          }
        }
      }
    }

    void PrintMatrix() const {
      for(int i = 0; i < Size(); i++){
        for(int j = 0; j < Size(); j++){
          std:: cout << matrix[i][j];
        }
        std::cout << "\n";
      }
    }
    size_t Size() const { return collections.size(); }
  private:
    std::vector<Vertices<T>> collections;
    int** matrix;
};