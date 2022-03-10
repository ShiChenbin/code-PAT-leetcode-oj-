#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define rep(i, a, b) for (int i=a;i<=b;++i)
const int mod = int(1e9) + 7;
const int inf = 0x3f3f3f3f;
const ll inff = 0x3f3f3f3f3f3f3f3fLL;
const double pi = acos(-1.0); //M_PI;
const int maxn = 1e4 + 10;
int arr[maxn];
//最大连续子序列之和
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n;
	cin >> n;
	int now = 0, nowl = 0;
	int ans = -1, ansl = 1, ansr = n;

	for(int i = 1; i <= n; i++){
		cin >> arr[i];
		now = arr[i] + now;
		if (now < 0){
			nowl = i + 1;
			now = 0;
		}else if (now > ans){
			ans = now;
			ansl = nowl;
			ansr = i;
		}
	}
	if (ans < 0){
		ans = 0;

	}
	cout << ans << " " << arr[ansl] << " " << arr[ansr] << '\n';
}