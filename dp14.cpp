#include<bitset>/stdc++.h>
#include<iostream>
using namespace std;
int LCS(string X, string Y, int n, int m){
    if(n==0 || m==0){
        return 0;
    }
    if(dp[n][m] != -1){
        return dp[n][m];
    }

    if(X[n-1]==Y[m-1]){
        dp[n][m]= 1 + LCS(X, Y, n-1, m-1);
    }
    else{
        dp[n][m]= max(LCS(X, Y, n-1, m), LCS(X, Y, n, m-1));
    }

    return dp[n][m];

}

int main(){
    string X="abcdgh";
    string Y="abedfh";
    int n=X.length();
    int m=Y.length();

    int dp[n+1][m+1];
    memset(dp, -1, sizeof(dp));

    cout<<LCS(X, Y, n, m);

    return 0;


}