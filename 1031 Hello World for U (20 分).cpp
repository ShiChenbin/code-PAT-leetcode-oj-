#include <bits/stdc++.h>
using namespace std;
char a[100][100];
int main(){
	for(int i = 0; i < 80; i++){
		for(int j = 0; j < 80; j++){
			a[i][j] = ' ';
		}
	}
	string str;
	cin >> str;
	int n = str.size();
	int n1 = n / 3;
	int n2 = n / 3 + n % 3;
	int idx = 0;
	for(int i = 0; i < n1; i++){
		a[i][0] = str[idx++];
	}
	for(int i = 0; i < n2; i++){
		a[n1][i] = str[idx++];
	}
	for(int i = n1 - 1; i >= 0; i--){
		a[i][n2 - 1] = str[idx++];
	}
	for(int i = 0; i <= n1; i++){
		for(int j = 0; j < n2; j++){
			cout << a[i][j];
		}
		cout << '\n';
	}
}