#include<bits/stdc++.h>
using namespace std;
int knapsack(int wt[], int val[], int w, int n){
    if(n==0 || w==0){
        return 0;
    }

    if(dp[n][w]!=-1){
        return dp[n][w];
    }
    else {
        if(wt[n-1]<=w){
             dp[n][w]=max(val[n-1] + knapsack(wt, val, w - wt[n-1], n-1), knapsack(wt, val, w, n-1));
        }
        }
    
    else if(wt[n-1]>w){
        dp[n][w]=knapsack(wt, val, w, n-1);
    }
        
    }

    return dp[n][w];
}

int main{

    int n=wt.size();
    int wt[]={};
    int val[]={};
    int w=7;
    int dp[n+1][w+1];

    for(int i=0; i<dp.size(); i++){
        for(int j=0; j<dp[0].size(); j++){
            dp[i][j]=-1;
        }
    }
}