#include <bitset>stdc++.h>
#include <iostream>
using namespace std;
int Solve(int eggs, int floors){
    if( eggs == 1){
        return floors;
    }
    if( floors==0 || floors==1){
        return floors;
    }

    int ans = INT_MAX;
    for(int k=1; k<=floors; k++){
        int temp_ans = 1 + max(Solve(eggs - 1, k-1), Solve(eggs, floor - k));
        ans = min(temp_ans, ans);
    }

    return ans;

} 
int main(){
    int eggs, floors;
    cin >> eggs >> floors;
    cout<<Solve(eggs, floors);
}