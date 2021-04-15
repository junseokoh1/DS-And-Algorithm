#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

//완전 다시해야됨....

using namespace std;

//cost, v1, v2
using ti3 = tuple<int, int, int>;


//adj의 index가 시작 vertex
//adj[4] = pair(10, 1)
// cost : 10이고 4 - 1 간선을 의미
//index 1부터 사용하기!

//  cost, index
vector<pair<int, int>> adj[100005];


int V, E;

bool chk[100005];
void prim(){

    int cnt = 0;
    int total_cost=0;
    priority_queue<ti3, vector<ti3>, greater<ti3>> PQ;

    //하나의 정점을 선택해 최소 신장 트리에 추가
    chk[1] = 1;
    //연결된 모든 간선을 추가
    for(auto p : adj[1])
      PQ.push({ p.first, 1, p.second});



    //v-1개의 간선이 될 때 까지
    int cost, v1, v2;
    while(1){

        //힙에서 가장 작은 간선을 꺼낸다.
        tie(cost, v1, v2) = PQ.top();
        PQ.pop();

        //간선이 최소 신장 트리에 이미 포함이면 pass
        if(chk[v2]) continue;

        chk[v2] = 1;     //최소 신장 트리에 추가
        total_cost += cost;
        cnt++;

        if(cnt == V-1)  break;

        // 모든 간선은 힙에 추가
        for(auto p : adj[v2]){
          if(!chk[p.second])
            PQ.push({ p.first, v2, p.second});
        }
        
    }

    cout<<total_cost;

}

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);


  cin>>V>>E;

  //A정점 B정점  Cost
  int A, B, cost;

  for(int i=0; i<E; i++){

      cin>>A>>B>>cost;
      adj[A].push_back(make_pair(cost, B));
      adj[B].push_back(make_pair(cost, A));   //2개다 넣어야됨!!!

  }

  prim();

  
}



//priority_queue<자료형, 구현체, 비교 연산자>
//less<자료형>   greater<자료형>

//구현체는 기본적으로 vector<자료형>으로 정의된다. 
//이말인 즉슨 우리가 쓰는 priority_queue가 실제로는 vector 위에서 돌아가고 있다는 것이다. 
//vector가 아니더라도 deque<자료형> 등을 넣어도 잘 돌아간다.
