#include<bitset>/stdc++.h>
using namespace std;
int minnoofcoins(int coins[], int n, int sum){
    int dp[n+1][sum+1];
    for(int i=0; i<n+1; i++){
        for(int j=0; j<sum+1; j++){
            if(i==0){
                dp[i][j]=INT_MAX -1;
            }
            if(j==0){
                dp[i][j]=0;
            }

            if(i==1){
                if(j%coins[i-1] == 0){
                    dp[1][j]=j%coins[i-1];
                }
                else{
                    dp[i][j]=INT_MAX -1;
                }
            }
        }
    }

    for(int i=1; i<n+1; i++){
        for(int j=1; j<sum +1; j++){
            if(coins[i-1]<=sum){
                dp[i][j]=min(dp[i-1][j], 1 + dp[i][j-coins[i-1]]);
            }
            else{
                dp[i][j]= dp[i-1][j];
            }
        }
    }

    return dp[n][sum];

}
int main(){
    int coins[]={};
    int sum=17;
    int n= coins.size();
    cout<<minnoofcoins(coins, n, sum);
}