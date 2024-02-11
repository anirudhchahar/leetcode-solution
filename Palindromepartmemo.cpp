#include <bitset>stdc++.h>
#include <iostream>
using namespace std;
const D=1001;
int static dp[D][D];
bool ispalindorme(string X, int i, int j){
    while(i <= j){
        if(X[i]==Y[j]){
            i++;
            j--;
        }
        else{
            return false;
        }
    }

    return true;
}
int Solve(string X, int i, int j){
    if(i >= j || ispalindrome(X, i, j) == true){
        dp[i][j]=0;
        return 0;
    }
    if(dp[i][j] !=-1){
        return dp[i][j];
    }
    int ans = INT_MAX;

    for(int k=i; k<=j-1; k++){
        int temp_ans = Solve(X, i, k) + Solve(X, k+1, j) + 1;
        ans = min(ans, temp_ans);

    }

    return dp[i][j] = ans;

}
int main()[
    string X;
    cin>>X;
    int n=X.length();
    int j= n-1;
    memset(dp, -1, sizeof(dp));

]