#include <iostream>
#include <vector>
#include <queue>
#include <stack>

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

    //BFS에서는 queue가 필요!
    void BFSGraph(int startV){
        bool isVisit[numV]; //false로 초기화
        queue<int> q;

        isVisit[startV] = true;
        q.push(startV);
        cout<<startV<<" ";

        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(auto l : adjList[cur]){
              // cout<<"---"<<l<<'\n';
              if(isVisit[l] == false){
                //action
                cout<<" "<<l<<"  ";
                isVisit[l] = true;
                q.push(l);
              }
            }
        }
    }

        //DFS에서는 stack이 필요!
    void DFSGraph(int startV){
        bool isVisit[numV]; //false로 초기화
        fill(isVisit+1, isVisit+numV, 0);
        stack<int> s;

        isVisit[startV] = true;
        s.push(startV);
        // cout<<startV<<" ";

        while(!s.empty()){
            int cur = s.top();
            s.pop();
            cout<<" "<<cur<<" ";     //action
            // cout<<"";
            for(auto l : adjList[cur]){
              if(isVisit[l] == false){
                isVisit[l] = true;
                s.push(l);
              }
            }
        }
    }
};


int main() {

  Graph* testGraph = new Graph(7);

  testGraph->AddEdge(0, 1);
  testGraph->AddEdge(0, 3);
  testGraph->AddEdge(1, 2);

  testGraph->AddEdge(3, 2);
  testGraph->AddEdge(3, 4);
  testGraph->AddEdge(4, 5);
  testGraph->AddEdge(4, 6);

  testGraph->ShowGraph();

  cout<<"BFS"<<'\n';
  testGraph->BFSGraph(6);

  cout<<'\n'<<"DFS"<<'\n';
  testGraph->DFSGraph(6);
  cout<<'\n'<<"end";

}


/*       vector 생성에 대한 공부

    vector<int> vec;        // 비어있는 벡터 생성
    vector<int> vec(5);     // 5개의 원소를 0으로 초기화 시켜 만듬
    vector<int> vec(5, 3);  // 5개의 원소를 3으로 초기화 시켜 만듬
    vector<int> vec2(vec);  // vec 을 복사하여 벡터 생성

*/


/*

class로 만들어서 간선의 BFS, DFS를 보기좋게 만든 것 뿐!!!

결국 실제가 되는 부분은     vector<int>* adjList; !

즉 코딩 테스트에서 처럼 간단하게 하려면 vector만 있으면 됨!!

그리고     vector<int>* adjList; 가 핵심이자 그래프 자체임!!!

*/
