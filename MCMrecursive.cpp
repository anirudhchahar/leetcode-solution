#include<bitset>stdc++.h>
#include <iostream>
using namespace std;
int MCM(int arr[], int i, int j){
    if(i >= j){
        return 0;
    }
    int ans= INT_MAX;
    for(int k=i; k<=j-1; k++){
        int tempans = MCM(arr, i, k) + MCM(arr, k+1, j) + arr[i-1]*arr[k]*arr[j];
        ans = min (ans, tempans);  

    }
    return ans;

}
int main(){
    int arr[5]={40, 20, 30, 10, 30};
    int n= arr.size();
    cout<<MCM(arr, 1, n-1);
}