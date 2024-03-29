
#include<bitset>/stdc++.h>
using namespace std;
int subsetcount(int arr[], int sum, int n){
    int dp[n+1][sum+1];
    for(int i=0; i<n+1; i++){
        for(int j=0; j<sum+1; j++){
            if(i==0){
                dp[i][j]==0;
            }
            if(j==0){
                dp[i][j]==1;
            }
        }
    }

    for(int i=1; i<n+1; i++){
        for(int j=1; j<sum+1; j++){
            if(arr[i-1]<=j){
                dp[i][j]=dp[i-1][j] + dp[i-1][j-arr[i-1]];
            }

            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }

    return dp[n][sum];

}
int main(){
    int arr[]={};
    int sum=7;
    int n=arr.size();

    cout<<subsetcount(arr, sum, n);
}