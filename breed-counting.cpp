// Problem(USACO Silver 2015: Breed Counting): https://usaco.org/index.php?page=viewproblem2&cpid=572

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
    
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<vector<int>> pfSum(n+1, vector<int>(3, 0));
    for(int i = 0; i < n; ++i){
        int a; cin >> a;
        if(a == 1){
            pfSum[i+1][0] = pfSum[i][0] + 1;
            pfSum[i+1][1] = pfSum[i][1];
            pfSum[i+1][2] = pfSum[i][2];
        } else if(a == 2){
            pfSum[i+1][1] = pfSum[i][1] + 1;
            pfSum[i+1][0] = pfSum[i][0];
            pfSum[i+1][2] = pfSum[i][2];

        } else{
            pfSum[i+1][2] = pfSum[i][2] + 1;
            pfSum[i+1][1] = pfSum[i][1];
            pfSum[i+1][0] = pfSum[i][0];
        }      
    }
    for(int i = 0; i < q; ++i){
        int a, b; cin >> a >> b;
        cout << pfSum[b][0] - pfSum[a - 1][0] << " " << pfSum[b][1] - pfSum[a - 1][1] << " " << pfSum[b][2] - pfSum[a - 1][2] << endl;
    }

    return 0;
}
