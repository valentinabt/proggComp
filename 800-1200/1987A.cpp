#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <iomanip>
using namespace std ;




int minTime(int k ,int n) {
    int seconds = 0 ;
    while(n>0){
        if (seconds % k ==0){
            n -- ;
            seconds ++ ;

        }
        else {
            seconds ++ ;
        }
    }
    return seconds ;
}


int main() {
    long long int t ;
    cin >> t ;
    long long int cont = 0 ;
    vector<int> res ;
    while(cont<t){
        long long int n = 0 ;
        long long int k = 0 ;
        cin >> n ;
        cin >> k ;
        cont++ ;
        res.push_back(minTime(k,n)) ;

    }
    for(int i = 0 ; i< res.size() ; i++){
        cout <<  res[i]  << endl ;
    }
   
    return 0 ;
}