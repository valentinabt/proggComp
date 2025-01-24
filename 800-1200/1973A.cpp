#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <climits> 
using namespace std ;

int maxDraws(int p1,int p2,int p3,vector<vector<vector<int>>>& memo){

    //caso base
    if (p1 < 0 || p2 <0 || p3 <0 ){
        return INT_MIN ;
    }
    if( (p1 == 0 && p2 == 0 && p3 % 2 == 0) || (p1 == 0 && p3 == 0 && p2 % 2 == 0)|| (p2 == 0 && p3 == 0  && p1 % 2 == 0)){
        return 0 ;
    }


    if(memo[p1][p2][p3] != -1){
        return memo[p1][p2][p3] ;
    }
    int onewith2 = maxDraws(p1-1,p2-1,p3,memo) + 1 ;
    memo[p1][p2][p3] = onewith2 ;
    int onewith3 = maxDraws(p1-1,p2,p3-1,memo) +1;
    memo[p1][p2][p3] = onewith3 ;
    int twowith3 = maxDraws(p1,p2-1,p3-1,memo)+1 ;
    memo[p1][p2][p3] = twowith3 ;
    int res = max(max(onewith2,onewith3),twowith3) ;
    return res ;

}







int main(){
    long long int t ;
    cin >> t ;
    int p1 ;
    int p2 ;
    int p3 ;
    while(t>0){
        cin >> p1 ;
        cin >> p2 ;
        cin >> p3 ;
        vector<vector<vector<int>>> memo (31,vector<vector<int>>(31,vector<int>(31,-1))) ;
        int res = maxDraws(p1,p2,p3,memo) ;
        if (res<0){
            cout << -1 << endl ;
        }
        else {
            cout << res << endl ;
        }
        t-- ;

    }
    return 0 ;
}