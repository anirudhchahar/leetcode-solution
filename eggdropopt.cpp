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
        int top, bottom;
		if (dp[eggs - 1][k - 1] != -1)
			top = dp[eggs - 1][k - 1];
		else {
			top = Solve(eggs - 1, k - 1);
			dp[eggs - 1][k - 1] = top;
		}

		if (dp[eggs][floors - k] != -1)
			bottom = dp[eggs][floors - k];
		else {
			bottom = Solve(eggs, floors - k);
			dp[eggs][floors - k] = bottom;
		}
		int temp_ans = 1 + max(top, bottom);
		ans = min(ans, temp_ans);
	}

	return dp[eggs][floors] = ans;
      
    }

    return dp[eggs][floors] = ans;

} 
int main(){
    int eggs, floors;
    cin >> eggs >> floors;
    memset(dp, -1, sizeof(dp));
    cout<<Solve(eggs, floors);
}