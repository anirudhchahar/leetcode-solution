#include <bitset>/stdc++.h>
#include <iostream>
using namespace std;
const D=1000;
int dp[D][D];
int MCM(int arr[], int i, int j){
    
    if(i>=j){
        return 0;
    }
    if(dp[i][j]!= -1){
        return dp[i][j];
    }
    int ans = INT_MAX;
    for(int k=i; k<=j-1; k++){
        int temp_ans = MCM(arr, i, k) + MCM(arr, k+1, j) + arr[i-1]*arr[k]*arr[j];
        if(temp_ans < ans){
            ans = temp;
        }
    }

    return  dp[i][j]=ans;


}
int main(){
    int arr[5]={40, 20, 30, 10, 30};
    int n=arr.length();
    memset(dp, -1, sizeof(dp));
    cout<<MCM(arr, 1, n-1)<<endl;
}