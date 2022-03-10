#include <iostream>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 510;

int weight[maxn]; //每个节点的权值
int e[maxn][maxn]; //边权
int dis[maxn]; //单源点距离
int num[maxn]; //路径数
int w[maxn];//消防队数
bool vis[maxn]; //访问

int main(){
	int n, m, c1, c2;

	for(int i = 0; i < maxn; i++) dis[i] = INF;
	fill(e[0], e[0] + 510 * 510, INF);
	fill(vis, vis + 510, false);

	cin >> n >> m >> c1 >> c2;
	for(int i = 0; i < n; i++) cin >> weight[i];
	for(int i = 0; i < m; i++){
		int a, b, c; cin >> a >> b >> c;
		e[a][b] = e[b][a] = c;
	}

	dis[c1] = 0;
	w[c1] = weight[c1];
	num[c1] = 1;

	for(int i = 0; i < n; i++){
		int u = -1, minn = INF;
		for(int j = 0; j < n; j++){
			if (vis[j] == false && dis[j] < minn) {
				u = j;
				minn = dis[j];
			}
		}

		if(u == -1) break;
		vis[u] = true;
		for(int v = 0; v < n; v++){
			if(vis[v] == false && e[u][v] != INF){
				if (dis[u] + e[u][v] < dis[v]){
					dis[v] = dis[u] + e[u][v];
					num[v] = num[u];
					w[v] = w[u] + weight[v];
				}
				else if (dis[u] + e[u][v] == dis[v]){
					num[v] = num[v] + num[u];
					if (w[u] + weight[v] > w[v]){
						w[v] = w[u] + weight[v];
					}
				}
			}
		}
	}

	cout << num[c2] << " " << w[c2] << '\n';
}