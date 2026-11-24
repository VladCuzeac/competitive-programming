/*
 * Problem Name: Eastern Exhibition(1486B)
 * Platform: Codeforces
 * Link: https://codeforces.com/contest/1486/problem/B
 * Rating: 1500
 * Time Complexity: O(N * log(N))
 * Space Complexity: O(N)
 * Logic: For Manhattan distance, the x-axis and y-axis are completely
 * independent, so we can solve each axis separately. Consider the x-axis
 * (after sorting): moving the chosen coordinate right by `step` increases
 * the sum of distances to points on the left by `cnt_left * step` and
 * decreases the sum of distances to points on the right by `cnt_right * step`.
 * The total sum of distances is minimized at the median(s) of the sorted
 * coordinates (keeping duplicates, since each house counts separately): a
 * single point when N is odd, or any integer in [a[N/2 - 1], a[N/2]]
 * when N is even. Finally, the number of valid integer positions is the
 * product of the counts of optimal integer coordinates along x and y.
*/

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for(int i = 0;i < n;++i){
        cin >> x[i] >> y[i];
    }

    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    int x_v = 0, y_v = 0;
    if(n % 2){
        x_v = 1;
        y_v = 1;
    }
    else{
        x_v = x[n / 2] - x[(n / 2) - 1] + 1;
        y_v = y[n / 2] - y[(n / 2) - 1] + 1;
    }

    cout << 1ll * x_v * y_v << endl;
}

int main(){
    int t = 1;
    cin >> t;
    while(t--)
        solve();
}
