/*
 * Problem Name: Greetings(1915F)
 * Platform: CodeForces
 * Link: https://codeforces.com/problemset/problem/1915/F
 * Rating: 1500
 * Time Complexity: O(N * log(N))
 * Space Complexity O(N)
 * Logic: Problem could be solved directly using a data structure like Fenwick Tree
 * but it is much easier to observe a usual technique used in CP, store how many
 * elements before have a certain property and just add them to answer, also using
 * already implemented data structures like ordered_set, rather
 * than solve problem directly by using big data structures like Fenwick Tree
 */


#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

typedef long long ll;

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve(){
    int n;
    cin >> n;
    vector<pair<int,int>> a;
    for(int i = 0;i < n;++i){
        int x, y;
        cin >> x >> y;
        a.push_back({x,y});
    }

    sort(a.begin(),a.end());
    ordered_set cnt;
    ll ans = 0;
    for(int i = 0;i < n;++i){
        ans += cnt.size() - cnt.order_of_key(a[i].second);
        cnt.insert(a[i].second);
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
