#include<bits/stdc++.h>
using namespace std;
int depthFirstSearch(int at, bool* isVisited, vector<vector<int>>&adList, int t, int* tOrder){
    if(isVisited[at]){
        return t;
    }
    isVisited[at] = true;
    for(auto i=adList[at].begin(); i != adList[at].end(); i++){
        t = depthFirstSearch(*i, isVisited, adList, t, tOrder);
    }
    tOrder[t] = at;
    return t-1;

}

int* topologicalSort(vector<vector<int>>&adList){
    bool* isVisited = new bool[adList.size()];
    memset(isVisited, false, adList.size());
    int* tOrder = new int[adList.size()];
    int t = adList.size()-1;
    for(unsigned long long j=0; j<adList.size(); j++){
        if(!isVisited[j]){
           t =  depthFirstSearch(j, isVisited,adList,t, tOrder);
        }
    }
    return tOrder;
}

int main(){
  vector<vector<int>>g1 = {{1, 2, 3}, {4, 5}, {6}, {6, 7, 8}, {9}, {9}, {}, {10}, {10}, {}, {}};
  int* t1 = topologicalSort(g1);
  for(unsigned long long i=0; i<g1.size(); i++){
      cout<<t1[i]<<" ";
  }
  cout<<endl;

}
