/*
 * Problem Name: Queen (1143C)
 * Platform: Codeforces
 * Link: https://codeforces.com/problemset/problem/1143/C
 * Rating: 1400
 * Time Complexity: O(N * log(N))
 * Space Complexity: O(N)
 * Logic: A vertex v can be deleted if c[v] == 1 and 
 * all of its children also have c[child] == 1. The key insight is that deleting a 
 * vertex and reattaching its children to its parent never changes the deletion 
 * eligibility of any other vertex in the tree (since the reattached children all 
 * have c == 1). Therefore, we don't need to simulate the tree modifications; A simple
 * dfs solve our problem, where we just check that every respect[children] = 1
 * and our curent node is also respect[node] = 1.
 */

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

void dfs(int v, vector<vector<int>> &g, vector<int> &vis, vector<int> &resp, vector<int> &ans){
    vis[v] = 1;
    bool good = 1;
    for(auto child : g[v]){
        if(resp[child] == 0){
            good = 0;
            break;
        }
    }
    if(good && resp[v]) ans.push_back(v);

    for(auto child : g[v]){
        if(!vis[child]) dfs(child, g, vis, resp, ans);
    }
}

void solve(){
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    vector<int> resp(n + 1,0);
    vector<int> vis(n + 1,0);
    vector<int> ans;
    int start = -1;
    for(int i = 0;i < n;++i){
        int v, u;
        cin >> v >> u;
        if(v != -1){
            g[v].push_back(i + 1);
            resp[i + 1] = u;
        }
        else start = i + 1;
    }
    for(auto child : g[start]){
        dfs(child, g, vis, resp, ans);
    }
    sort(ans.begin(),ans.end());
    if(ans.size() == 0){
        cout << -1;
    }
    else{
        for(auto it : ans) cout << it << " ";
    }
}

int main(){
    int t = 1;
    while(t--)
        solve();
    return 0;
}