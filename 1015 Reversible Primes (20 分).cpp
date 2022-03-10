#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define rep(i, a, b) for (int i=a;i<=b;++i)
const int mod = int(1e9) + 7;
const int inf = 0x3f3f3f3f;
const ll inff = 0x3f3f3f3f3f3f3f3fLL;
const double pi = acos(-1.0); //M_PI;
const int maxn = 1e5 + 10;
	
bool isprime(int x){
    if (x == 2) return true;
	for(int i = 2; i <= sqrt(x); i++){
		if (x % i == 0) return false;
	}
	return true;
}

//先化简成d进制然后再翻转

bool slove(int n, int radix){
	std::vector<int> v;
	while(n){
		v.push_back(n%radix);
		n /= radix;
	}
	int ans = 0;
	for(int i = v.size() - 1, j = 0; i >= 0; i--, j++){
		ans += v[i]*pow(radix, j);
	}
	cout << ans << '\n';
	return isprime(ans);
}
int main(){
	
	int n, radix;
	while(cin >> n){
		if (n <= 0) {
			continue;
		}
		cin >> radix;
		if (!isprime(n) || !slove(n, radix)){
			printf("No\n");
		}
		else
		{
			printf("Yes\n");
			
		}
	}
	
}
