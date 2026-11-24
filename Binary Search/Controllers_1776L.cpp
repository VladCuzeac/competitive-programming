/*
 * Problem Name: Controllers(1776L)
 * Platform: Codeforces
 * Link: https://codeforces.com/problemset/problem/1776/L
 * Rating: 1500
 * Time Complexity: O(log(N)) per query, O(N) precomputation
 * Space Complexity: O(N)
 * Logic: First, observe that the order of rounds doesn't matter, so we only 
 * need to count the total number of '+' and '-' symbols. For each query (a, b), 
 * we use binary search to check if there is a valid distribution of '+' rounds 
 * assigned to button 'a' that yields a final score of 0. This works because the 
 * resulting score function is monotonic: assigning more '+' rounds to 'a' 
 * changes the remaining balance assigned to 'b' predictably, allowing us to 
 * efficiently narrow down the exact solution.
 */

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int x = 0, y = 0;
    for(auto it : s){
        x += (it == '+');
        y += (it == '-');
    }
    if(x < y) swap(x,y);
    int q;
    cin >> q;
    while(q--){
        ll a, b;
        cin >> a >> b;
        if(a > b) swap(a,b);
        int l = 0, r = x;
        bool g = 0;
        while(l <= r){
            int mid = (l + r) / 2;
            ll right = 1ll * (y - (x - mid)) * b;
            ll left = 1ll * mid * a;
            if(left == right) {
                g = 1;
                break;
            }
            else if (left > right) l = mid + 1;
            else r = mid - 1;
        }
        cout << (g ? "YES\n" : "NO\n");
    }
}

int main(){
    int t = 1;
    //cin >> t;
    while(t--)
        solve();
    return 0;
}