#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
int a[maxn][maxn];

//某城市被军队占领了，剩下的城市要相互联系需要建造多少条路，并查集，

bool vis[maxn];
int num, n, d, m, k;
void dfs(int root){
	vis[root] = true;
	for(int i = 1; i <= n; i++){
		if (a[i][root] && !vis[i]){
			dfs(i);
		}
	}
}

int main(){
	cin >> n >> m >> k;
	for(int i = 0; i < m; i++){
		int x, y; cin >> x >> y;
		a[x][y] = a[y][x] = 1;
	}
	std::vector<int> ans;
	for(int i = 0; i < k; i++){
		cin >> d;
		num = 0;
		fill(vis, vis + n + 1, false);
		vis[d] = true;
		for(int j = 1; j <= n; j++)
		{
			if (!vis[j]){
				dfs(j);
				num++;
			}
		}
		ans.push_back(num - 1);
	}

	for(auto i : ans){
		cout << i << '\n';
	}
}