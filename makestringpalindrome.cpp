// minimum no. of deletion required to  make a string palindrome
#include<bitset>std/c++.h>
#include<iostream>
using namespace std;
int LCS(string X, string Y, int n, int m){
    int dp[n+1][m+1];
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m+1; j++){
            if(X[i-1]==Y[j-1]){
                dp[i][j]=1 + dp[i-1][j-1];
            }
            else{
                dp[i][j]= max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[n][m];
    
}
int LPS(string X, int n){
    string revX=X;
    reverse(revX.begin(), revX.end());
    return LCS(X, revX, n, n);

}
int MinDelPal(string X, int n ){
    return n - LPS(X,n);

}

int main(){
    string X;
    cin>>X;
    int n=X.length();
    cout<<MinDelPal(X, n);
}