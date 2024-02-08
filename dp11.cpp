#include<bitset>/stdc++.h>
#include <iostream>
using namespace std;
int maxnoofways(int coins[], int n, int sum){
    int dp[n+1][sum +1];
    for(int i=0; i<n+1; i++){
        for(int j=0; j<sum+1; j++){
            if(i==0){
                dp[i][j]==0;
            }
            if(j==0){
                dp[i][j]=1;
            }
        }
    }

    for(int i=1; i<n+1; i++){
        for(int j=1; j<sum+1; j++){
            if(coins[i-1]<=sum){
                dp[i][j]=dp[i-1][j] + dp[i][j-coins[i-1]];
            }

            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }

    return dp[n][sum];

}
int main(){
    int coins[]={};
    int sum=7;
    int n= coins.size();
    cout<<maxnoofways(coins, n, sum);

}