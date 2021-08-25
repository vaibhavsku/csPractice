#include<bits/stdc++.h>
using namespace std;
int* f1(int* cows, int farms, int c, int* day, int dayLength){
    int dp[dayLength][c];
    map<int, int>m1;
    for(int i=0; i<farms; i++){
        if(m1.find(cows[i]) == m1.end()){
            m1[cows[i]] = 1;
        }
        else{
            m1[cows[i]]++;
        }
    }
    for(int i=0; i<dayLength; i++){
        for(int j=0; j<c; j++){
            dp[i][j] = 0;
        }
    }
    for(auto i=m1.begin(); i != m1.end(); i++){
        dp[0][(i->first)-1] = i->second;
    }
    for(int i=0; i<dayLength-1; i++){
        for(int j=0; j<c; j++){
               int nfarms = dp[i][j];
               int ncows = 2*(j+1);
               if(ncows-1 < c){
                   dp[i+1][ncows-1] = dp[i+1][ncows-1] + nfarms;
               }
               else{
                   ncows = ncows/2;
                   nfarms = nfarms*2;
                   dp[i+1][ncows-1] = dp[i+1][ncows-1] + nfarms;
               }
        }
    }
    
    int* answer = new int[dayLength];
    for(int i=0; i<dayLength; i++){
        answer[i] = 0;
    }
    for(int i=0; i<dayLength; i++){
        for(int j=0; j<c; j++){
            answer[i] = answer[i] + dp[day[i]][j];
        }
    }
    return answer;

}

int main(){
    int cows[] = {1, 2, 1, 2, 1};
    int day[] = {0, 1, 2};
    int* answer = f1(cows, 5, 2, day, 3);
    for(int i=0; i<3; i++){
        cout<<answer[i]<<endl;
    }
    return 0;
}