#include<bitset>/stdc++.h>
#include<iostream>
using namespace std;
string SCS(string X, string Y, int n, int m){
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
            if(X[i-1]==Y[j-1]){
                dp[i][j]= 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }

    string scs="";
    int i=n;
    int j=m;
    while(i>0 && j>0){
        if(X[i-1]==Y[j-1]){
            scs+=X[i-1];
            i--;
            j--;
        }
        else{
            if(dp[i][j-1] >  dp[i-1][j]){
                scs+=Y[j-1];
                j--;
            }
            else{
                scs+=X[i-1];
                i--;
            }
        }
    }

    while(i>0){
        scs+=X[i-1];
        i--;
    }
    while(j>0){
        scs+=Y[j-1];
        j--;
    }

    reverse(scs.begin(), scs.end());

    return scs;

}
int main(){
    string X,Y;
    cin>>X>>Y;
    int n=X.length();
    int m=Y.length();
    cout<<SCS(X, Y, n, m);
}