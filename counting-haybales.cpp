// Problem(USACO Silver 2016: Counting Haybales): https://usaco.org/index.php?page=viewproblem2&cpid=666

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

int solve(vector<int> &v){
    int a, b; cin >> a >> b;
    auto lb = lower_bound(v.begin(), v.end(), a);
    auto rlb = upper_bound(v.begin(), v.end(), b); --rlb; 
    if(lb == v.end()){
        return 0;
    }  
    return rlb - lb + 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("haybales.in", "r", stdin);
    freopen("haybales.out", "w", stdout);

    int n, q; cin >> n >> q;

    vector<int> v(n); 
    for(int i = 0; i < n; ++i) cin >> v[i];
    sort(v.begin(), v.end());

    while(q--){
        cout << solve(v) << endl;
    }

    return 0;
}
