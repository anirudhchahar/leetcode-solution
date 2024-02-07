#include<bits/stdc++.h>
using namespace std;
vector<int> subsetdiff(int arr[], int sum, int n){
    bool dp[n+1][sum +1];
    for(int i=0; i<n+1; i++){
        for(int j=0; j<sum+1; j++){
            if(i==0){
                dp[i][j]=false;
            }
            if(j==0){
                dp[i][j]=true;
            }
        }
    }

    for(int i=1; i<n+1; i++){
        for(int j=1; j<sum+1; j++){
            if(arr[n-1]<= j){
                dp[i][j]=dp[i-1][j] || dp[i-1][j-arr[i-1]];
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }

    vector<int> v;
    for(int j=0; j<sum+1; j++){
        if(dp[n][j]==true){
            v.push_back(j);
        }
    }

    return v;


}
int minsubsetdiff(int arr[], int n){
    int range=0;
    for(int i=0; i<arr.size(); i++){
        range+=arr[i];
    }

    vector<int> v=subsetdiff(arr, range, n);
    int mini=INT_MAX;
    for(int i=0; i<v.size(); i++){
        mini = min(mini, abs(range - 2*v[i]));
    }

    return mini;


}

int main(){
    int arr[]={};
    int n=arr.size();
    cout<<minsubsetdiff(arr, n);
    return 0;
}