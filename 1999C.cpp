#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <list>
#include <tuple>
#include <string>
using namespace std ;


string itspossible(vector<tuple<long long int,long long int>>& tasks,long long int s ,long long int m){
    int i = 0 ;
    int j = 0 ;
    while(j < tasks.size() && i < m){
            if(i+s <= get<0>(tasks[j]) || (j== tasks.size()-1 && get<1>(tasks[j])+s <= m)){
                return "YES" ;
            }
            else {
                    i = get<1>(tasks[j]) ;
                    j++ ;
            }
    }
    return "NO" ;
}



int main() {
    long long int t ;
    cin >> t ;
    long long int cont = 0 ;
    vector<string> res ;
    while(cont<t){
        
        long long int n ;
        long long int s ;
        long long int m ;
        long long int start ;
        long long int end ;
        long long int ntasks = 0 ;
        vector<tuple<long long int,long long int>> tasks ;
        cin >> n ;
        cin >> s ;
        cin >> m ;
        while(ntasks<n){
            cin >> start ;
           
            cin >> end ;
            tasks.push_back(make_tuple(start,end)) ;
            ntasks ++ ;

        }
        res.push_back(itspossible(tasks,s,m)) ;
        
        cont++ ;
    }
    for(int i = 0 ; i< res.size() ; i++){
        cout <<  res[i]  << endl ;
    }
   
    return 0 ;
}