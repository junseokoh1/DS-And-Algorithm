#include <iostream>
#include <algorithm>

using namespace std;

//최소 힙
class heap{

  private:

    int numOfData;
    int heap_arr[100000];

  public:


    heap(){
      numOfData = 0;
      fill(heap_arr, heap_arr+100000, 0);
    }


    int getLeftIndex(int cur){
      return cur*2;
    }

    int getRightIndex(int cur){
      return cur*2 + 1;
    }

    int getParentIndex(int cur){
      return cur/2;
    } 

    void add(int pNum){
        heap_arr[++numOfData] = pNum;

        int curIndex = numOfData;

        while(curIndex != 1){
            if(heap_arr[curIndex] < heap_arr[curIndex/2] ){
                swap(heap_arr[curIndex], heap_arr[curIndex/2]);
                curIndex = curIndex/2;
            }
            else{
              break;
            }
        }
    }

    int HDelete(){

        if(numOfData == 0) return 0;

        int result = heap_arr[1];
        swap(heap_arr[1], heap_arr[numOfData]);
        numOfData--;


        int curIndex = 1;
        int minChild = 0;

        while(1){

            //leaf node가 아닐때까지
            // 왼쪽 자식의 index(=2*idx)가 size보다 크면 idx가 leaf라는 의미이다.
            if(curIndex*2 > numOfData){
                break;
            }

            //자식 노드 중 가장 작은 값의 index 가져가기
            if(curIndex*2+1 > numOfData || heap_arr[curIndex*2] < heap_arr[curIndex*2+1])   minChild = curIndex*2;
            else  minChild = curIndex*2+1;


            if(heap_arr[curIndex] < heap_arr[minChild]) break;

            swap(heap_arr[curIndex], heap_arr[minChild]);

            curIndex = minChild;
        }

        return result;

    }


};

int main() {

      ios::sync_with_stdio(0);
  cin.tie(0);

    heap* heapClass = new heap();

    int N, num;

    cin>>N;

    for(int i=0; i<N; i++){
        cin>>num;

        if(num == 0){
            cout<<heapClass->HDelete()<<'\n';
        }
        else{
            heapClass->add(num);
        }
    }

}

/*

힙의 구현은 배열을 기반으로 하며 인덱스가 0인 요소는 비워둔다.

힙에 저장된 노드의 가수와 마지막 노드의 고유 번호는 일치한다.

노드의 고유전호가 노드가 저장되는 배열의 인덱스 값이 된다.


삭제할 때 최소힙이면 자식중에서 가장 작은 값을
최대힙이면 자식중에서 가장 큰 값을


*/
