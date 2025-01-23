#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <string>
using namespace std ;

bool itsgreaterthan(int i,string m){
    string a ;
    string b ;
    for(int j = 0 ; j < m.size() ; j++){
        if(j <= i){
            a += m[j] ;
        }
        else {
            b += m[j] ;
        }
    }
    int aNum = stoi(a);
    int bNum = stoi(b) ;
    if(bNum>aNum){
        return true ;
    }
    return false ;

}

int findValues(string m){
    for(int i = 0 ; i < m.size()-1 ; i++){
        if( m[i+1] != '0' && itsgreaterthan(i,m)){
            return i ;

        }
    }
    return -1 ;
}






int main() {
    long long int t ;
    cin >> t ;
    
    while(t>0){
        long long int n ;
        cin >> n ;
        string m = to_string(n) ;
        
        int res = findValues(m) ;
    
        if(res != -1){
            string a ;
            string b ;
            for(int j = 0 ; j < m.size() ; j++){
                if(j <= res){
                    a += m[j] ;
                }
                else {
                    b += m[j] ;
                }
            }
            int aNum = stoi(a);
            int bNum = stoi(b) ;
            cout <<  aNum << " " << bNum  << endl ;

         }
         else {
            cout <<  res  << endl ;
         }
        t-- ;
        }
    
        
   
    return 0 ;
}