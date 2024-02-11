#include <bitset>stdc++.h>
#include <iostream>
using namespace std;
const D=101;
int static dp[D][D];
int Solve(int eggs, int floors){


    if( dp[eggs][floors] != -1){
        return dp[eggs][floors];
    }
    if( eggs == 1 || floors==0 || floors==1){
        return floors;
    }

    int ans = INT_MAX;
    for(int k=1; k<=floors; k++){
        int temp_ans = 1 + max(Solve(eggs - 1, k-1), Solve(eggs, floor - k));
        ans = min(temp_ans, ans);
    }

    return dp[eggs][floors] = ans;

} 
int main(){
    int eggs, floors;
    cin >> eggs >> floors;
    memset(dp, -1, sizeof(dp));
    cout<<Solve(eggs, floors);
}