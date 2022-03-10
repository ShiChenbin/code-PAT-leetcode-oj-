#include <bits/stdc++.h>
using namespace std;
map<string, bool> m;
bool cmp(string a, string b){
	string a1 = a.substr(6, 8);
	string b1 = b.substr(6, 8);
	if (a1 <= b1){
		return true;
	}
	else {
		return false;
	}
}
int main(){
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		string str; cin >> str;
		m[str] = true;
	}
	int M, cur = 0; cin >> M;
	string ans = "";
	string rans = "";
	for(int i = 0; i < M; i++){
		string str; cin >> str;
		if (m[str]) {
			if (ans == ""){
				ans = str;
			}
			else {
				if (cmp(str, ans)){
					ans = str;
				}
			}
			cur++;
		}
		if (rans == ""){
			rans = str;
		}
		else {
			if (cmp(str, rans)){
				rans = str;
			}
		}
	}
	if(!cur) ans = rans; 

	cout << cur << '\n' << ans << '\n';

}