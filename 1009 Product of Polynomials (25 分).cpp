#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define rep(i, a, b) for (int i=a;i<=b;++i)
const int mod = int(1e9) + 7;
const int inf = 0x3f3f3f3f;
const ll inff = 0x3f3f3f3f3f3f3f3fLL;
const double pi = acos(-1.0); //M_PI;
const int maxn = 1e4, M = 1e3;

//多项式乘积
struct pol
{
	int n;
	double x;
} a[maxn], b[maxn];
double ans[1000000];
int main(){
	int ka, kb;
	cin >> ka;
	for(int i = 1; i <= ka; i++){ 
		cin >> a[i].n >> a[i].x;
	}
	cin >> kb;
	for(int i = 1; i <= kb; i++){
		cin >> b[i].n >> b[i].x;
	}

	for(int i = 1; i <= ka; i++){
		for(int j = 1; j <= kb; j++){
			ans[a[i].n + b[j].n] += a[i].x*b[i].x;
		}
	}
	int num = 0;
	for(int i = 0; i <= 100000; i++){
		if (ans[i]){
			num++;
		}
	}
	cout << num;
	for(int i = 0; i <= 100000; i++){
		if (ans[i])cout << " " << i << " " << ans[i];
	}
}