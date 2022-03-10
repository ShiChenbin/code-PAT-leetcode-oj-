#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ll number, base; cin >> number >> base;
	std::vector<int> v;
	while(number){
		v.push_back(number % base);
		number /= base;
	}
	int len = v.size();
	bool flag = true;
	for(int i = 0; i <= len / 2; i++){
		if (v[i] != v[len - i - 1]){
			flag = false;
			break;
		}
	}
	if (flag){
		printf("Yes\n");
		for(auto i : v){
			cout << i << " ";
		}
		cout << '\n';
	}
	else {
		printf("No\n");
	}
}