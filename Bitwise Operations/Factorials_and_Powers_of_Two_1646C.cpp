/*
 * Problem Name: Factorials and Powers of Two(1646C)
 * Platform: Codeforces
 * Link: https://codeforces.com/problemset/problem/1646/C
 * Rating: 1500
 * Time Complexity: O(t * S * log2(N)) where S = 2^13 for all subsets sums for factorials
 * Space Complexity: O(2^13)
 * Logic: Bitmasking & Binary Representation approach. Any positive integer n can 
 * always be represented as a sum of distinct powers of 2 (corresponding to the 
 * set bits in its binary form). To minimize the total count of terms, we can 
 * replace parts of the sum with distinct factorials (starting from 3! = 6 up to 
 * 14!, avoiding 1! and 2! so they don't overlap with powers of 2). Since there 
 * are at most 13 such factorials <= 10^12, we use bitmasks to generate all 2^13 
 * subset sums. For each valid subset sum S <= n, the minimum terms needed is 
 * the number of chosen factorials plus the count of set bits (popcount) in (n - S).
*/

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

set<pair<ll,int>> all;
void pre(){
    vector<ll> fact = {6};
    for(int i = 4;i <= 15;++i){
        fact.push_back(1ll * fact.back() * i);
    }
    for(int num = 0; num <= (1 << fact.size());++num){
        ll cur = 0;
        int cnt = 0;
        for(int bit = 0;bit < (int)fact.size();++bit){
            if((num & (1 << bit)) != 0) {
                cur += fact[bit];
                cnt++;
            }
        }
        all.insert({cur,cnt});
    }
}

void solve(){
    ll n;
    cin >> n;

    int ans = 100;
    for(auto it : all){
        if(it.first > n) break;
        int cnt = it.second;
        for(int bit = 0; bit <= 60;++bit){
            if((it.first & (1ll << bit)) == 0 && ((n & (1ll << bit)) != 0)) cnt++;
            else if ((it.first & (1ll << bit)) != 0 && ((n & (1ll << bit)) == 0)){
                it.first += (1ll << bit);
                cnt++;
            }
        }
        ans = min(ans, cnt);
    }
    cout << ans << endl;
}

int main(){
    pre();
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}