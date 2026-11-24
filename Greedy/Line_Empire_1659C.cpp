/*
 * Problem Name: Line Empire(1659C)
 * Platform: Codeforces
 * Link: https://codeforces.com/problemset/problem/1659/C
 * Rating: 1500
 * Time Complexity: O(N)
 * Space Complexity: O(N)
 * Logic: Greedy & Prefix Sums approach. Initially, we calculate the baseline cost 
 * of conquering all kingdoms without ever moving the capital from 0 (sum of x_i * b). 
 * Then, we iterate through each kingdom i as the final stopping position for our 
 * capital. Moving the capital step-by-step to x_i adds a relocation cost of (a * x_i), 
 * while reducing the conquest cost for all remaining (n - i) kingdoms to the right 
 * by (b * x_i). We evaluate this trade-off in O(1) per position and track the minimum 
 * total cost.
*/

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

void solve(){
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> arr(n + 1,0);
    for(int i = 1;i <= n;++i) cin >> arr[i];
    ll ans = 0;
    for(int i = 1;i <= n;++i){
        ans += 1ll * arr[i] * b;
    }
    for(int i = 1;i <= n;++i){
        ll tmp = 1ll * ans + (1ll * (arr[i] - arr[i - 1]) * a);
        ll p = 1ll * (arr[i] - arr[i - 1]) * (n - i) * b;
        tmp -= p;
        ans = min(ans, tmp);
    }
    cout << ans << endl;

}

int main(){
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}