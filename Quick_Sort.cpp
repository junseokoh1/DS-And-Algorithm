#include <iostream>
// #include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int n = 10;
int arr[100000] = {9, 8, 4, 3,2,1,43,39,2, 7};

void quick_sort(int st, int en){

    // if(st <= en-1) return;
    if(en <= st+1) return;

    int pivot = st;
    int l = st+1;
    int r = en-1;

    while(1){
        while(l <= r && arr[l] <= arr[pivot]) l++;
        while(l <= r && arr[r] >= arr[pivot]) r--;
        if(r<l) break;
        // int tmp = arr[l];
        // arr[l] = arr[r];
        // arr[r] = tmp;
        std::swap(arr[l], arr[r]);
    }
    // int tmp = arr[pivot];
    // arr[pivot] = arr[r];
    // arr[r] = tmp;
    std::swap(arr[r], arr[pivot]);


    quick_sort(st, r);
    quick_sort(r+1, en);

}

int main() {
  quick_sort(0, n);
  for(int i=0; i<n; i++)  std::cout<<arr[i]<<" ";
}
