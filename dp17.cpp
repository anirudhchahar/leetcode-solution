#include<bits/stdc++.h>
#include<iostream>
using namespace std;
strint LCS(string X, string Y, int n, int m){
    int dp[n+1][m+1];
    for(int i=0; i<n+1; i++){
        for(int j=0; j<m+1; j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
        }
    }

    for(int i=1; i<n+1; i++){
        for(int j=1; j<m+1; j++){
            if(X[i-1]==Y[i-1]){
                dp[i][j]= 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j]= max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    string lcs="";
    int i=n;
    int j=m;
    while(i>0 && j>0){
        if(X[i-1]==Y[j-1]){
            lcs+=X[i-1];
            i--;
            j--;
        }
        else{
            if(dp[i][j-1] > dp[i-1][j]){
                j--;
            }
            else{
                i--;
            }
        }
    }

    reverse(lcs.begin(),lcs.end());

    return lcs;


}
int main(){
    string X="abcdgh";
    string Y="abedfh";
    int n=X.length();
    int m=Y.length();
    cout<<LCS(X, Y, n, m);
}