/*
 * Problem Name: Anna and the Valentine's Day Gift(1931E)
 * Platform: Codeforces
 * Link: https://codeforces.com/problemset/problem/1931/E
 * Rating: 1400
 * Time Complexity: O(N * log(N))
 * Space Complexity: O(N)
 * Logic: Greedy & Game Theory approach. Sasha wins if the final concatenated 
 * number is >= 10^m, which is equivalent to having strictly more than m digits 
 * in total. Anna tries to minimize the total digit count by reversing numbers with 
 * trailing zeros (removing them), while Sasha tries to protect those trailing zeros 
 * by concatenating them with other numbers. Sorting the counts of trailing zeros 
 * in descending order, Anna removes the 1st, 3rd, 5th... largest counts, while 
 * Sasha saves the 2nd, 4th, 6th... largest counts.
*/

#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(auto &it : a) cin >> it;

    int total = 0;
    for(auto it : a){
        while(it){
            total++;
            it /= 10;
        }
    }
    vector<int> trail;
    for(auto it : a){
        if(it % 10 == 0){
            int tmp = 0;
            while(it > 0 && it % 10 == 0){
                tmp++;
                it /= 10;
            }
            trail.push_back(tmp);
        }
    }
    sort(trail.rbegin(),trail.rend());
    for(int i = 0;i < trail.size();i += 2) total -= trail[i];

    cout << (total > m ? "Sasha\n" : "Anna\n");
}

int main(){
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}