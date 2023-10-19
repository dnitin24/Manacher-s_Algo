#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <array>
#include <iomanip>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#include <functional> 
using namespace __gnu_pbds; 
using namespace std; 
#define int long long  
#define endl "\n" 
const int mod=1e9+7; 
const int MOD= 998244353 ; 
const int inf=1e18; 
const long double eps=1e-7; 

const int N=0; 
 
typedef tree<int, null_type, less<int>, rb_tree_tag,  
tree_order_statistics_node_update>  
ordered_set; 
 
mt19937_64  
rang(chrono::high_resolution_clock::now().time_since_epoch().count()); 
 
void inthe_code(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}

vector<int> zAlgo(string s){
    int n = s.size();
    int l = 0, r = 0;
    vector<int> Z(n);
    for(int i=1;i<n;i++){
        if(i <= r){
            Z[i] = min(r - i + 1, Z[i-l]);
        }
        while(i + Z[i] < n and s[Z[i]] == s[i+Z[i]]){
            Z[i] ++;
        }
        if(i + Z[i] - 1 > r){
            l = i, r = i + Z[i] - 1;
        }
    }
    return Z;
}

// Manacher's Algorithm

// What is the max. length of odd length palindromic substring of the  
// string, with mid index as 'i' and manacher array is M
int oddMax(int i, vector<int>& M){
    return M[2*i + 1];
}

// What is the max. length of even length palindromic substring of the  
// string, with mid index as 'i' and manacher array is M
int evenMax(int i, vector<int>& M){
    return M[2*i + 2];
}

// is [l...r] a palindromic substring ?
bool isPal(int l, int r, vector<int>& M){
    int mid = (l + r)/2;
    int len = (r - l + 1);
    if(len % 2){
        return (oddMax(mid, M) >= len);
    }
    else{
        return (evenMax(mid, M) >= len);
    }
}

int32_t main(){ 
    inthe_code();
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
    srand(chrono::high_resolution_clock::now().time_since_epoch().count()); 
    
    string s;
    cin>>s;
    int n = s.size();
    string t = "";
    for(int i=0;i<n;i++){
        t += '#';
        t += s[i];
    }
    t += '#';
    n = t.size();
    vector<int> M(n);
    int l = 0, r = 0;
    for(int i=0;i<n;i++){
        if(i <= r){
            M[i] = min(r - i + 1, M[l + l - i]);
        }
        while(i + M[i] < n and i - M[i] >= 0 and t[i + M[i]] == t[i - M[i]]){
            M[i] ++;
        }
        if(i + M[i] - 1 > r){
            l = i, r = i + M[i] - 1;
        }
    }
    for(int i=0;i<n;i++){
        M[i] --;
    }
    
}