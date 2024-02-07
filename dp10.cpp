#include<bitset>/stdc++.h>
using namespace std;
int rodcutting(int length[], int price[], int n, int l){
    int dp[n+1][l+1];
    for(int i=0; i<n+1; i++){
        for(int j=0; j<l+1; j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
        }
    }

    for(int i=0; i<n+1; i++){
        for(int j=0; j<l+1; j++){
            if(l[i-1]<=j){
                dp[i][j]=max(price[i-1] + dp[i][j-l[i-1]] , l[i-1][j]);
            }

            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }

    return dp[n][l];

}
int main(){
    int length[]={};
    int price[]={};
    int n= price.size();
    int l=7;
    cout<<rodcutting(arr, price, n, l);

}