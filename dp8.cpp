#include<bitset>/stdc++.h>
using namespace std;
int subsetcount(int arr[], int n, int sum1){
    int dp[n+1][sum1+1];
    for(int i=0; i<n+1; i++){
        for(int j=0; j<sum1 +1; j++){
            if(i==0){
                dp[i][j]=0;
            }
            if(j==0){
                dp[i][j]=1;
            }
        }
    }

    for(int i=1; i<n+1; i++){
        for(int j=1; j<sum1 +1; j++){
            if(arr[i-1]<= j){
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
    int sum=0;
    int arr[]={};
    int n=arr.size();
    int diff=7;

    for(int i=0; i<n; i++){
        sum+=arr[i];
    }

    int sum1= (sum + diff)/2;
    if((sum+diff)%2 != 0){
        return 0;
    }
    else{
        cout<<subsetcount( arr, sum1, n);
    }
}