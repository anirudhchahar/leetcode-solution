#include<bits/stdc++.h>
using namespace std;
bool subsetsum( int arr[], int val, int n){

    int dp[n+1][sum +1];

    for(int i=0; i<n+1; i++){
        for (int j = 0; j< val +1; j++)
        {
            if(i==0){
                dp[i][j]== false;
            }

            if(j==0){
                dp[i][j]=true;
            }
        }
        
    }

    for(int i=1; i<n+1; i++){
        for(int j=1; j<val+1; j++){
            if(arr[i-1]<=j){
                dp[i][j]= dp[i-1][j-arr[i-1]] || dp[i-1][j];
            }

            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[i][j];

}

int main(){
    int arr[]={};
    int n=arr.size();
    int sum=0;

    for(int i=0; i<n; i++){
        sum+=arr[i];
    }

    if(sum%2 !=0 ){
        return false;
    }

    else{

        cout<<subsetsum(arr, sum/2, n);
    }
}