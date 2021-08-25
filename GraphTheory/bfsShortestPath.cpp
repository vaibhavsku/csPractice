#include<bits/stdc++.h>
using namespace std;
void reverse(vector<int>&arr){
    int a,b;
    a = 0;
    b= arr.size()-1;
    while(a<=b){
        if(a==b){
            break;
        }
        swap(arr[a], arr[b]);
        a++;
        b--;
    }
}
void breadthFirstSearch(int at, bool* isVisited, vector<vector<int>>&adList, int* parent){
    queue<int>qq;
    qq.push(at);
    isVisited[at] = true;
    while(!qq.empty()){
        for(auto i = adList[qq.front()].begin(); i != adList[qq.front()].end(); i++){
            if(!isVisited[*i]){
                parent[*i] = qq.front();
                qq.push(*i);
                isVisited[*i] = true;
            }
        }
        qq.pop();
    }
}
vector<int> findShortestPath(int start, int end, bool* isVisited, vector<vector<int>>&adList, int vertex){
    int* parent = new int[vertex+1];
    memset(parent, 0, vertex+1);
    breadthFirstSearch(start, isVisited,adList, parent);
    vector<int>path;
    for(int i = end; i != 0; i = parent[i]){
        path.push_back(i);
    }
    reverse(path);
    if(path[0] == start){
        return path;
    }
    return {};
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

vector<int>p = findShortestPath(1, 7, n, g1, v);
for(auto i = p.begin(); i!=p.end(); i++){
    cout<<*i<<" ";
}
cout<<endl;
}