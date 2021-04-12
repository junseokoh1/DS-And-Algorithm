#include <iostream>
#include <vector>

using namespace std;

//무방향 그래프 (방향으로 바꾸고 싶으면 AddEdge만 수정)
class Graph{

  private:

    int numV; //정점의 개수
    int numE; //간선의 개수

    vector<int>* adjList;

  public:

    Graph(int pNumV, int pNumE=0){
        numV = pNumV;
        numE = pNumE;
        adjList = new vector<int>[pNumV];
    }

    void AddEdge(int fromV, int toV){
        adjList[fromV].push_back(toV);
        adjList[toV].push_back(fromV);

    }

    void ShowGraph(){
        for(int i=0; i< numV; i++){
          cout<<i<<" : ";
          for(auto l : adjList[i])
            cout<<l<<" ";
          cout<<'\n';
        }
    }
};

int main() {

  Graph* testGraph = new Graph(5);

  testGraph->AddEdge(0, 1);
  testGraph->AddEdge(4, 1);
  testGraph->AddEdge(1, 3);

  testGraph->ShowGraph();

}


/*       vector 생성에 대한 공부

    vector<int> vec;        // 비어있는 벡터 생성
    vector<int> vec(5);     // 5개의 원소를 0으로 초기화 시켜 만듬
    vector<int> vec(5, 3);  // 5개의 원소를 3으로 초기화 시켜 만듬
    vector<int> vec2(vec);  // vec 을 복사하여 벡터 생성

*/
