#include<bits/stdc++.h>
using namespace std;

int calcEdges(vector<vector<pair<int, int>>>&adList){
    int edges=0;
    for(auto i = adList.begin(); i != adList.end(); i++){
        edges = edges + i->size();
    }
    return edges;
}

struct smaller{
  bool operator()(const pair<int, int>& a,const pair<int, int>& b) const{
    return a.second>=b.second;
  }
};

class dijkstraHeap{
    private:
        vector<pair<int, int>>arr;
    public:
        void insert(pair<int, int>inp);
        void poll(pair<int, int>& out);
        int size();

};



void dijkstraHeap::insert(pair<int, int> inp){
   arr.push_back(move(inp));
   push_heap(arr.begin(), arr.end(), smaller());
}

void dijkstraHeap::poll(pair<int, int>& out){
    if(!arr.empty()){
        out.first = arr.front().first;
        out.second = arr.front().second;
        pop_heap(arr.begin(), arr.end(), smaller());
        arr.pop_back();
    }
}

int dijkstraHeap::size(){
    return arr.size();
}

int dijkstraLazy(vector<vector<pair<int, int>>>&adList, int start, int end){
    bool* isVisited = new bool[adList.size()];
    memset(isVisited, false, adList.size());
    int* pathCost = new int[adList.size()];
    for(int i=0; i<adList.size(); i++){
        pathCost[i] = INT32_MAX;
    }
    pathCost[start] = 0;
    dijkstraHeap hh;
    hh.insert(make_pair(start, 0));
    pair<int, int>out;
    while(hh.size() != 0){
       hh.poll(out);
       isVisited[out.first] = true;
       if(pathCost[out.first]<out.second){
           continue;
       }
       if(out.first==end){
          return pathCost[end];
       }
       for(auto i = adList[out.first].begin(); i != adList[out.first].end(); i++){
           if(!isVisited[i->first]){
               pathCost[i->first] = min(pathCost[i->first],pathCost[out.first] + i->second);
               hh.insert(make_pair(i->first, i->second));
           }
       }
    }

    return INT32_MAX;

}

int main(){
 
 vector<vector<pair<int, int>>>g1 = {
    {make_pair(1, 3), make_pair(2, 6)},
    {make_pair(2, 4), make_pair(3, 4), make_pair(4, 11)},
    {make_pair(3, 8), make_pair(6, 11)},
    {make_pair(4, 1), make_pair(5, 5), make_pair(6, 2)},
    {make_pair(7, 9)},
    {make_pair(7, 1)},
    {make_pair(7, 2)},
    {}  
 };

 cout<<dijkstraLazy(g1, 0, 3)<<endl;

}