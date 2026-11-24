/*
 * Problem Name: News Distribution(1167C)
 * Platform: Codeforces
 * Link: https://codeforces.com/problemset/problem/1167/C
 * Rating: 1400
 * Time Complexity: O(N + K)
 * Space Complexity: O(N + K)
 * Logic: Graph Theory (DFS/BFS). Since news spreads bidirectionally within any 
 * shared friend group, we can model users as nodes in an undirected graph. By 
 * connecting consecutive users within each group (creating k_i - 1 edges per group), 
 * we avoid O(k_i^2) dense subgraphs. Every user in the same connected component will 
 * eventually receive the news, so we run DFS/BFS to find the size of each connected 
 * component and assign that count to all its members.
*/

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

void dfs(int v, vector<vector<int>> &g, vector<int> &vis, int &total, vector<int> &path){
    total++;
    vis[v] = 1;
    path.push_back(v);
    for(auto child : g[v]){
        if(!vis[child]) dfs(child, g, vis, total, path);
    }
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    for(int i = 0;i < m;++i){
        int t;cin >> t;
        if(t == 0) continue;
        vector<int> cur(t);
        for(auto &it : cur) cin >> it;
        for(int j = 1;j < t;++j){
            g[cur[j - 1]].push_back(cur[j]);
            g[cur[j]].push_back(cur[j - 1]);
        }
    }

    vector<int> ans(n + 1,0);
    vector<int> vis(n + 1,0);
    for(int i = 1;i <= n;++i){
        if(!vis[i]){
            int cur = 0;
            vector<int> path;
            dfs(i, g, vis, cur, path);
            for(auto it : path) ans[it] = cur;
        }
    }
    for(int i = 1;i <= n;++i) cout << ans[i] << " ";
}

int main(){
    int t = 1;
    while(t--)
        solve();
    return 0;
}