//选择n个新闻网站
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;
int jud[maxn];
int qus[maxn];
int r[maxn];
int main(){
	int n, m; cin >> n >> m;
	for(int i = 1; i <= m; i++){
		map<int, int> ma;
		ma.clear();
		for(int j = 1; j <= n; j++){
			cin >> r[j];
			ma[r[j]]++;
		}


		int nowmax = -1;
		//先找最大值

		for(int i = 1; i <= n; i++){
			if (n - ma[r[i]] > nowmax){
				nowmax = n - ma[r[i]];
			}
		}
		printf("nowmax = %d\n", nowmax);
		for(int i = 1; i <= n; i++){
			if (nowmax == n - ma[r[i]]){
				jud[i]++;
			}
		}
	
	}
	int ans = 1;
	for(int i = 1; i <= n; i++){
		if (jud[i] > jud[ans]){
			ans = i;
		}
	}
	cout << ans << '\n';
}