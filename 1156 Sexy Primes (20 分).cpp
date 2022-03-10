#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isprime(ll n){
	if (n == 1) return false;
	if (n == 2) return true;
	for(int i = 2; i <= sqrt(n); i++){
		if(n % i == 0) return false;
	}
	return true;
}
int main(){
	//如果是sex primes就输出yes并且输出较小的一个
	ll n; cin >> n;

	if (isprime(n)){
		if (isprime(n - 6)){
			printf("Yes\n%lld\n", n - 6);
			return 0;
		}
		else if (isprime(n + 6)){
			printf("Yes\n%lld\n", n);
			return 0;
		}
	}
	ll ans = n + 1;
  	while(1){
		if (isprime(ans) && isprime(ans + 6)){
  			printf("No\n%lld\n", ans);
  			break;
  		}
  		ans++;
  	}
	
	return 0;
}