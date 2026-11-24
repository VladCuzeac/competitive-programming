/*
 * Problem Name: Palindrome Basis(1673C)
 * Platform: Codeforces
 * Link: https://codeforces.com/problemset/problem/1673/C
 * Rating: 1500
 * Time Complexity: O(N * P) where P = 498 palindromes, O(1) per query
 * Space Complexity: O(N)
 * Logic: Dynamic Programming (Unbounded Knapsack / Coin Change combinations). 
 * Since there are only 498 palindromic numbers up to 4*10^4, we can precompute 
 * the answers for all possible sums in a single DP table. To avoid counting 
 * duplicate permutations (e.g., counting both 1 + 4 and 4 + 1 as distinct), 
 * we iterate through the available palindromes in the outer loop and update 
 * the target sums in the inner loop. This ensures elements are considered in 
 * non-decreasing order.
 */

#include <bits/stdc++.h>

using namespace std;

bool good(int n){
    vector<int> a;
    while(n){
        a.push_back(n % 10);
        n /= 10;
    }

    int l = 0, r = a.size() - 1;
    while(l <= r){
        if(a[l] != a[r]) return 0;
        l++;
        r--;
    }
    return 1;
}

vector<int> dp(40001,0);
void f(){
    int mod = 1e9 + 7;
    vector<int> pal;
    dp[0] = 1;
    for(int i = 1;i <= 40000;++i) if(good(i)) pal.push_back(i);

    for(auto it : pal){
        for(int i = 1;i <= 40000;++i){
            if(it > i) continue;
            dp[i] += dp[i - it];
            dp[i] %= mod;
        }
    }

}

void solve(){
    int n;
    cin >> n;
    cout << dp[n] << endl;
}

int main(){
    f();
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}