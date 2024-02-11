#include <bitset>/stdc++.h>
#include <iostream>
using namespace std;
int Solve(string X, int i, int j, bool isTrue){
    if(i > j){
        return 0;
    }
    if(i == j){
        if(isTrue == true){
            return X[i] == true;
        }
        else{
            return X[i] == false;
        }
    }

    int ans=0;
    for(int k=i; k<j; k=k+2){
        int lT = Solve(X, i, k-1, true);
        int lF = Solve(X, i, k-1, false); 
        int rT = Solve(X, k+1, j, true);
        int rF = Solve(X, k+1, j, false);

       if (X[k] == '|') {
			if (isTrue == true)
				ans += lT * rT + lT * rF + lF * rT;
			else
				ans += lF * rF;
		}
		else if (X[k] == '&') {
			if (isTrue == true)
				ans += lT * rT;
			else
				ans += lT * rF + lF * rT + lF * rF;
		}
		else if (X[k] == '^') {
			if (isTrue == true)
				ans += lT * rF + lF * rT;
			else
				ans += lT * rT + lF * rF;
		}

	}

	return ans;
    }


}
int main(){
    string X;
    cin>>X;
    int n=X.length();
    cout<<Solve(X, 0, n-1, true)<<endl;
}