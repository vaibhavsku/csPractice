#include <bits/stdc++.h>
using namespace std;
void depthFirstSearch(int at, bool* isVisited, vector<vector<int>>&adList, int* group, int id){
    if(isVisited[at]){
        return;
    }
    isVisited[at] = true;
    group[at] = id;
    //cout<<at<<" ";
    for(auto i = adList[at].begin(); i != adList[at].end(); i++){
        depthFirstSearch(*i, isVisited, adList, group, id);
    }
}
int main(){

vector<vector<int>>g1;

int v, e;

cin>>v>>e;

for(int i=0; i<v+1; i++){
    
    g1.push_back({});

}

for(int i=0; i<e; i++){
    int f,n;
    cin>>f>>n;
    g1[f].push_back(n);
}

bool* n = new bool[v+1];
memset(n, false, v+1);
int* G = new int[v+1];
memset(G, -1, v+1);
int id=-1;
for(int i=1; i<v+1; i++){
    if(!n[i]){
        id++;
        depthFirstSearch(i, n, g1, G, id);
    }
}
for(int i=1; i<v+1; i++){
    cout<<G[i]<<" ";
}
cout<<endl;

}