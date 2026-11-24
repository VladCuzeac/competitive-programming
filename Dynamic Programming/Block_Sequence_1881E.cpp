/*
 * Problem Name: Block Sequence(1881E)
 * Platform: CodeForces
 * Rating: 1500
 * Link: https://codeforces.com/problemset/problem/1881/E
 * Time Complexity: O(N)
 * Space Complexity O(N)
 * Logic: Dynamic Programming approach. The dp[i] array stores the maximum number 
 * of elements that can form a valid 'beautiful' sequence up to index i. 
 * At any index i, we can either skip the element, or treat a[i] as a block size 
 * and transition to index i + a[i] + 1. The minimum deletions required will be 
 * the total length N minus the maximum valid elements found.
 */

#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n), dp(n + 1,0);
    for(auto &it : a) cin >> it;
    for(int i = 0;i < n;++i){
        if(i > 0) dp[i] = max(dp[i],dp[i - 1]);
        if(i + 1 + a[i] <= n) dp[i + 1 + a[i]] = max(dp[i + 1 + a[i]], dp[i] + a[i] + 1);
    }
    cout << n - *max_element(dp.begin(),dp.end()) << endl;
}

int main(){
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}