/*
 * Problem Name: Tea Tasting(1795C)
 * Platform: Codeforces
 * Link: https://codeforces.com/problemset/problem/1795/C
 * Rating: 1500
 * Time Complexity: O(N * log(N))
 * Space Complexity: O(N)
 * Logic: To avoid TLE, we first precompute the prefix sums of the b array 
 * (the amount each taster can drink). For each tea sort a[i], we use binary 
 * search on the prefix sums to find exactly how many consecutive tasters 
 * can drink their full capacity b[j]. We then use a Difference Array to 
 * efficiently update the count of these "full capacity" tasters in the 
 * [i, r] range. Finally, the remaining amount of tea (if any) is added 
 * directly to the (r + 1)-th taster.
 */

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for(auto &it : a) cin >> it;
    for(auto &it : b) cin >> it;

    vector<ll> pref(n + 1,0);
    vector<int> cnt(n,0);
    vector<ll> ans(n,0);
    ll prev = 0;
    for(int i = 0;i < n;++i) pref[i + 1] = pref[i] + b[i];

    for(int i = 0;i < n;++i){
        int index = lower_bound(pref.begin(), pref.end(), prev + a[i]) - pref.begin();
        if(index == n + 1){
            cnt[i]++;
        }
        else{
            cnt[i]++;
            cnt[index - 1]--;
            ans[index - 1] += a[i] - (pref[index - 1] - pref[i]);
        }
        prev += b[i];
    }
    int k = 0;
    for(int i = 0;i < n;++i){
        k += cnt[i];
        cout << 1ll * k * b[i] + ans[i] << " ";
    }
    cout << endl;
}

int main(){
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}