#include <bits/stdc++.h>
using namespace std;
const int maxn = 1111;
int cal_cnt[maxn];
int rev_cnt[maxn];
int dur[maxn][maxn];
bool isTel[maxn];

bool vis[maxn];//已经访问过
bool isOneGang = true;
bool isprintf = true;

int k, m, n;

void dfs(int root){
	if (vis[root] || !isTel[root]) return ;


	if (isOneGang){ printf("%d", root); isOneGang = false;}
	else {
		printf(" %d", root);
	}
	vis[root] = true;
	for(int i = root+1; i <= n; i++){
		//相互打电话，所以应该是a有打给b，b也有打给a
		if (!vis[i] && isTel[i] && (dur[i][root] > 0 && dur[root][i] > 0)){
			dfs(i);
		}
	}
}

int main(){
	cin >> k >> n >> m;
	for(int i = 0; i < m; i++){
		int cal, rec, rdur;
		cin >> cal >> rec >> rdur;
		//计算两个人之间的通话时间
		dur[cal][rec] += rdur;
	}

	//计算每个人的短通话次数
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if (dur[i][j] <= 5 && i != j && dur[i][j] > 0){
				cal_cnt[i]++;//短电话的数量
				if (dur[j][i] > 0) rev_cnt[i]++;//打回电话的数量
			}
		}
	}

	for(int i = 1; i <= n; i++){
		if (cal_cnt[i] > k && rev_cnt[i] <= 0.2 * cal_cnt[i]){
			isTel[i] = true; //判定为电信诈骗犯
		}
	}

	for(int i = 1; i <= n; i++){
		isOneGang = true;
		dfs(i);
		if (!isOneGang) puts("");
		if (isprintf && !isOneGang){
			isprintf = false;
		}
	}
	
	if (isprintf) printf("None\n");
}