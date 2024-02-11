#include <bitset>stdc++.h>
#include <iostream>
using namespace std;
bool ispalindrome(strong S, int i, int j){
    while(i <= j){
        if(X[i]==X[j]){
            i++;
            j--;
        }
        else{
            return false;
        }
    }
    return true;

}
int Palindormepartitioning(string S, int i, int j){
    if(i >= j || ispalindrome(S, i, j)==true){
        return 0;
    }
    int ans = INT_MAX;
    for(int k=i; k<=j-1; k++){
        int temp_ans = Palindromepartitioning(S, i, k) + Palindromepartioning(S, k+1, j) + 1;
        ans = min(temp_ans, ans);

    }

    return ans;

}
int main(){
    string S;
    cin>>S;
    int n=S.length();
    cout<<Palindromepartitioning(S, 1, n-1);
}