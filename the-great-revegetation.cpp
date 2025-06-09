// Problem(USACO Silver 2019: The Great Revegetation): https://usaco.org/index.php?page=viewproblem2&cpid=920


#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <climits>
#include <set>
#include <numeric>
#include <stack>
#include <queue>
#define endl "\n"  // Interactive?
using namespace std;

int main(){
    
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<vector<pair<int, char>>> adj(n);
    vector<int> color(n, -1);

    for(int i = 0; i < m; ++i){
        char s; cin >> s;
        int u, v; cin >> u >> v;
        adj[--u].push_back({--v, s});
        adj[v].push_back({u, s});
    }

    int ans = 0;
    for(int i = 0; i < n; ++i){
        if(color[i] == -1){
            ++ans;
            queue<int> q;
            color[i] = 0;
            q.push(i);
            while(!q.empty()){
                int c_n = q.front();
                q.pop();
                for(auto [v, t] : adj[c_n]){
                    int a = (t == 'S' ? color[c_n] : color[c_n]^1);
                    if(color[v] == -1){
                        color[v] = a;
                        q.push(v);
                    }
                    else if(color[v] != a){
                        cout << 0 << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << '1';
    for(int i = 0; i < ans; ++i){
        cout << '0';
    }
}

