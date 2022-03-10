#include <bits/stdc++.h>
using namespace std;
int t[10] = {0};
int rt[10] = {0};
std::vector<int> ans;
int main(){
	string str; cin >> str;
	int n = str.size();
	std::vector<int> v(n);
	for(int i = 0; i < n; i++){
		t[str[i] - '0']++;
		v[i] = str[i] - '0';
	}
	int carry = 0;
	
	for(int i = n - 1; i >= 0; i--){
		ans.push_back((v[i] * 2 + carry) % 10);
		rt[(v[i] * 2 + carry) % 10]++;
		carry = (v[i] * 2 + carry) / 10;
	}
	if (carry!=0)
		rt[carry]++;
	bool flag = true;
	for(int i = 0; i < 10; i++){
		//cout << t[i] << " " << rt[i] << '\n';
		if (t[i] != rt[i]) {
			flag = false;
			break;
		}
	}
	if (flag) printf("Yes\n");
	else printf("No\n");
    if (carry) cout << carry;
	for(int i = n - 1; i >= 0; i--){
		cout << ans[i];
	}
}
