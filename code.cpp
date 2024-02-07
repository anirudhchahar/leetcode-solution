#include<bitset>/stdc++.h>
using namespace std;

int knapsack(int wt[], int val[], w, n){

    if(n==0 || w==0){
        return 0;
    }

    if(wt[n-1]<=w){
        return max(val[n-1] + knapsack( wt, val, w-wt[n-1], n-1), knapsack(wt, val, w, n-1));
    }

    else if{
        return knapsack(wt, val, w, n-1);
    }
}

int main(){
    int n=5;
    int wt[5]={};
    int val[5]={};
    int w=7;
    cout<<knapsack(wt, val, w, n);

}