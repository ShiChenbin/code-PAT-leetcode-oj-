//#pragma GCC optimize ("O2") 
/**
 *    simplifie
 *    This code has been written by YueGuang, feel free to ask me question. Blog: http://www.moonl1ght.xyz
 *    created:
 */
#pragma comment(linker, "/STACK:36777216")
//#pragma GCC optimize ("O2") 
/**
 *    This code has been written by YueGuang, feel free to ask me question. Blog: http://www.moonl1ght.xyz
 *    created:
 */
#define LOCAL
#include <functional>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <numeric>
#include <cstring>
#include <climits>
#include <cassert>
#include <complex>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <list>
#include <set>
#include <map>

//#include <tr1/unordered_set>
//#include <tr1/unordered_map>
//#include <array>

using namespace std;


//}/* .................................................................................................................................. */
const int maxn = 555;
const int INF = 0x3f3f3f3f;

int num[maxn]; //表示从出发点到当前节点有多少条路径
int dis[maxn]; //源城市到当前城市的距离
int e[maxn][maxn];//边权
int weight[maxn];//当前位置的消防队的数量
int w[maxn];//从源点到当前节点一共有多少消防队
bool vis[maxn];



void init(){
	fill(e[0], e[0] + 555 * 555, INF);
	fill(dis, dis + 555, INF);
	fill(vis, vis + 555, false);
}


int main(){
    freopen("in.txt","r",stdin);
	
	init();

	int n, m, c1, c2;	
	cin >> n >> m >> c1 >> c2;
	for(int i = 0; i < n; i++){ cin >> weight[i];}

	for(int i = 1; i <= m; i++){
		int a, b, c; cin >> a >> b >> c;
		e[a][b] = e[b][a] = c;
	}

	dis[c1] = 0;
	w[c1]   = weight[c1]; // 路径数
	num[c1] = 1; //救援队数量

	for(int i = 0; i < n; i++){
		int u = -1, minn = INF; // 找本次循环的最短路
		for(int j = 0; j < n; j++){
			if (vis[j] == false && dis[j] < minn){
				u = j;
				minn = dis[j];
			}
		}

		if (u == -1) break;//如果找不到更短的路，说明已经求解完毕

		vis[u] = true;

		for(int v = 0; v < n; v++){
			if (vis[v] == false && e[u][v] != INF){ 
				if (dis[u] + e[u][v] < dis[v]) {
					dis[v] = dis[u] + e[u][v];//更新最短路的长度
					num[v] = num[u]; //到达当前节点的路径数
					w[v] = w[u] + weight[v]; //当前节点的消防队的数量
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