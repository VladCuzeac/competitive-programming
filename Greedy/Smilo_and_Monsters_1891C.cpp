/*
 * Problem Name: Smilo and Monsters(1891C)
 * Platform: CodeForces
 * Link: https://codeforces.com/problemset/problem/1891/C
 * Rating: 1500
 * Time Complexity: O(N * log(N))
 * Space Complexity O(N)
 * Logic: After a bit of observation, it is clear that we should keep the created combo
 * for caves with the biggest amount of monsters, so we keep a greedy strategy,
 * plus two pointers approach, in a sorted array, left pointer keeps the cave with
 * smallest amount of monsters, the right pointer to the cave with biggest amount
 * of monsters, then just use operation 1 to the left pointers while current combo
 * is smaller than the right pointer monsters in cave
 */


#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &it : a)cin >> it;
    sort(a.begin(),a.end());
    int l = 0, r = n - 1;
    ll ans = 0, cur = 0;
    while(l < r){
        if(cur + a[l] >= a[r]){
            ans += a[r] - cur + 1;
            a[l] -= a[r] - cur;
            cur = 0;
            r--;
        }
        else{
            cur += a[l];
            ans += a[l];
            l++;
        }

    }
    if(l == r){
        if(a[l] == 1) ans++;
        else if(a[l] > 1) ans += ((a[l] - cur + 1) / 2) + 1;
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