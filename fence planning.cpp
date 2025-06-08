// Problem(USACO Silver 2019: Fence Planning): http://www.usaco.org/index.php?page=viewproblem2&cpid=944

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

int n, m;
int crdx = INT_MIN;
int crdmx = INT_MAX;
int crdy = INT_MIN;
int crdmy = INT_MAX;
vector<vector<int>> adj;
vector<bool> visited;
vector<vector<int>> v;

void dfs(int c_n){
    if(visited[c_n]) return;
    visited[c_n] = true;
    crdx = max(crdx, v[c_n][0]);
    crdmx = min(crdmx, v[c_n][0]);
    crdy = max(crdy, v[c_n][1]);
    crdmy = min(crdmy, v[c_n][1]);

    for(int i : adj[c_n]){
        dfs(i);
    }
}

int main(){

    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    adj.resize(n);
    visited.resize(n, false);
    v.resize(n, vector<int> (2)); 

    for(int i = 0; i < n; ++i){
        int x, y; cin >> x >> y;
        v[i][0] = x; v[i][1] = y;
    }
    for(int i = 0; i < m; ++i){
        int u, v; cin >> u >> v;
        adj[--u].push_back(--v);
        adj[v].push_back(u);
    }
    int ans = INT_MAX;
    for(int i = 0; i < n; ++i){
        if(!visited[i]){
            dfs(i);
            ans = min(ans, 2 * ((crdx - crdmx) + (crdy - crdmy)));
            crdx = INT_MIN;
            crdmx = INT_MAX;
            crdy = INT_MIN;
            crdmy = INT_MAX;

        }
    } 
    cout << ans << endl;

    return 0;
}
