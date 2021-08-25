#include<bits/stdc++.h>
using namespace std;
int depthFirstSearch(int at, bool* isVisited, vector<vector<pair<int, int>>>&adList, int t, int* tOrder){
    if(isVisited[at]){
        return t;
    }
    isVisited[at] = true;
    for(auto i=adList[at].begin(); i != adList[at].end(); i++){
        t = depthFirstSearch(i->second, isVisited, adList, t, tOrder);
    }
    tOrder[t] = at;
    return t-1;

}

int* topologicalSort(vector<vector<pair<int, int>>>&adList){
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

int* SSSPdag(vector<vector<pair<int, int>>>&adList, int edge){
    if(edge>=0 && edge<adList.size()){
        int* cost = new int[adList.size()];
        for(int i=0; i<adList.size(); i++){
            cost[i] = INT32_MAX;
        }
        cost[edge] = 0;
        int* order = topologicalSort(adList);
        int edgeIndex;
        for(int i=0; i<adList.size(); i++){
            if(order[i] == edge){
                edgeIndex = i;
                break;
            }
        }
        for(int i=edgeIndex; i<adList.size(); i++){
           int startVertex = order[i];
           for(int j=0; j<adList[startVertex].size(); j++){
               cost[adList[startVertex][j].second] = min(cost[adList[startVertex][j].second], cost[startVertex]+adList[startVertex][j].first);
           }
        } 
         return cost;
    }
    else{
        return NULL;
    }
}

int main(){
  vector<vector<pair<int,int>>>g1 = {
    {make_pair(3, 1), make_pair(6, 2)},
    {make_pair(4, 2), make_pair(4, 3), make_pair(11, 4)},
    {make_pair(8, 3), make_pair(11, 6)},
    {make_pair(-4, 4), make_pair(5, 5), make_pair(2, 6)},
    {make_pair(9, 7)},
    {make_pair(1, 7)},
    {make_pair(2, 7)},
    {}
  };
  int* t1 = SSSPdag(g1, 2);
  for(unsigned long long i=0; i<g1.size(); i++){
      cout<<t1[i]<<endl;
  }
}
