	#include <bits/stdc++.h>
	using namespace std;
	typedef long long ll;

	#define rep(i, a, b) for (int i=a;i<=b;++i)
	const int mod = int(1e9) + 7;
	const int inf = 0x3f3f3f3f;
	const ll inff = 0x3f3f3f3f3f3f3f3fLL;
	const double pi = acos(-1.0); //M_PI;
	const int maxn = 1e5 + 10;

	ll get_ten(string str, ll radix){
		ll temp = 0;ll j = 0;
		for(int i = str.size() - 1; i >= 0; i--, j++){
			if (str[i] >= '0' && str[i] <= '9') temp += (str[i] - '0') * pow(radix, j) * 1ll;
			if (str[i] >= 'a' && str[i] <= 'z') temp += ((str[i] - 'a') + 10) * pow(radix, j) * 1ll;		
		}
		return temp;
	}

	void slove(ll a, string str){
		//求b的进制
		ll maxx = -1;
		for(int i = 0; i < str.size(); i++){
			if (str[i] >= '0' && str[i] <= '9') maxx = max(maxx, 1ll * (str[i] - '0'));
			else if (str[i] >= 'a' && str[i] <= 'z') maxx = max(maxx, 1ll * (str[i] - 'a' + 10));
		}

		ll st = maxx+1, en = max(a, maxx+1);
		while(st <= en){
			ll mid = (en+st) / 2;
			ll now = get_ten(str, mid);
			if (now == a){
				cout << mid << '\n';
				return ;
			}
	        else if (now > a || now < 0){
				en = mid - 1;
			}
			
			else if (now < a){
				st = mid + 1;
			}
		}
		printf("Impossible\n");
	}

	int main(){
		//freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);


		string n1, n2; cin >> n1 >> n2;

		int tag;
		ll radix; 

		cin >> tag >> radix;
		

		ll now = 0;
		string str;
		if(tag == 1) {
			now = get_ten(n1, radix);
			str = n2;
		}
		else{
			now = get_ten(n2, radix);
			str = n1;
		}
		slove(now, str);
	}