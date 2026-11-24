/*
 * Problem Name: Data Structures Fan(1872E)
 * Platform: Codeforces
 * Link: https://codeforces.com/problemset/problem/1872/E
 * Rating: 1500
 * Time Complexity: O(1) per query, O(N) precomputation
 * Space Complexity: O(N)
 * Logic: The problem explicitly hints at using a Data Structure like a Segment Tree 
 * with Lazy Propagation for range updates. However, I optimized the solution by 
 * using the properties of the XOR operation (A ^ A = 0). By precomputing a 
 * Prefix XOR array, we can apply range updates and answer global XOR queries in O(1) 
 * time, completely avoiding the heavy overhead of a Segment Tree.
 */

#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &it : a) cin >> it;
    string s;
    cin >> s;
    int zero = 0, one = 0;
    vector<int> pref(n + 1,0);
    for(int i = 0;i < n;++i){
        pref[i + 1] = pref[i] ^ a[i];
        if(s[i] == '0') zero ^= a[i];
        else one ^= a[i];
    }

    int q;
    cin >> q;
    while(q--){
        int t;
        cin >>t;
        if(t == 1){
            int l, r;
            cin >> l >> r;
            int seg = pref[r] ^ pref[l - 1];
            zero ^= seg;
            one ^= seg;
        }
        else{
            int cur;
            cin >> cur;
            cout << (cur == 0 ? zero : one ) << endl;
        }
    }
}

int main(){
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}