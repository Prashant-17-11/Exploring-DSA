// https://codeforces.com/problemset/problem/1627/A

#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve() {
    int n, m, r, c;
    cin>>n>>m>>r>>c;
    
    int black = 0;
    char grid[n+1][m+1];
    for(int i = 1 ; i <= n ; i++) {
        for(int j = 1; j <= m ; j++) {
            cin>>grid[i][j];
            if(grid[i][j] == 'B') {
                black++;
            }
        }
    }
    
    if(black == 0) {
        cout<<"-1\n";
        return;
    }

    if(grid[r][c] == 'B') {
        cout<<"0\n";
        return;
    }

    black = 0;
    for(int i = 1; i <= n; i++) {
        if(grid[i][c] == 'B') {
            black++;
        }
    }
    for(int j = 1; j <=m ; j++) {
        if(grid[r][j] == 'B') {
            black++;
        }
    }

    if(black) {
        cout<<"1\n";
    } else {
        cout<<"2\n";
    }
    return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	ll t;
	cin>>t;
	while(t--) {
	    solve();
	}
	
	return 0;
}
