#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define rep(i, a, b) for (int i=a;i<=b;++i)
const int mod = int(1e9) + 7;
const int inf = 0x3f3f3f3f;
const ll inff = 0x3f3f3f3f3f3f3f3fLL;
const double pi = acos(-1.0); //M_PI;
const int maxn = 2e5 + 10;
	
string ans[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
int v[maxn];
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	string s;
	cin >> s;
	int n = s.size();
	int sum = 0;
	for(int i = 0; i < n; i++){
		sum += s[i] - '0';
	}
    if (sum == 0){
        return printf("zero\n") * 0;
    }
	int num = 0;
	while(sum){
		v[num++] = sum % 10;
		sum /= 10;
	}

	for(int i = num - 1; i >= 0; i--){
		//cout << v[i] << '\n';
        
        if(i == num - 1)
		cout << ans[v[i]];
        else
            cout << " " << ans[v[i]];
	}
    cout << '\n';

}