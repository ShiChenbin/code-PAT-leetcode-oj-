#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define rep(i, a, b) for (int i=a;i<=b;++i)
const int mod = int(1e9) + 7;
const int inf = 0x3f3f3f3f;
const ll inff = 0x3f3f3f3f3f3f3f3fLL;
const double pi = acos(-1.0); //M_PI;
const int maxn = 2020;
struct stu
{
	string name;
 	int c; 
 	int e;
 	int m;
 	int avg;
 	int rank;
} a[maxn];

map<string,pair<char, int> > ans;
map<string, bool> idx;
bool cmp1(stu a, stu b){
	return a.avg > b.avg;
}

bool cmp2(stu a, stu b){
	return a.c > b.c;
}

bool cmp3(stu a, stu b){
	return a.m > b.m;
}

bool cmp4(stu a, stu b){
	return a.e > b.e;
}
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	int n, m; cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i].name >> a[i].c >> a[i].m >> a[i].e;
		idx[a[i].name] = true;
		a[i].avg = (a[i].c + a[i].m + a[i].e);
		a[i].rank = inf;
	}

	sort(a+1, a+1+n, cmp1);
	for(int i = 1; i <= n; i++){
		a[i].rank = i;
        if(a[i].avg == a[i - 1].avg){
        	a[i].rank = a[i - 1].rank;
        }
        else {
            a[i].rank = i;
        }   
        ans[a[i].name].first = 'A';
    	ans[a[i].name].second = a[i].rank;    
	}

	sort(a+1, a+1+n, cmp2);
	for(int i = 1; i <= n; i++){
		a[i].rank = i;
		if (a[i].c == a[i - 1].c) a[i].rank = a[i - 1].rank;
		if (a[i].rank < ans[a[i].name].second){
			ans[a[i].name].first = 'C';
			ans[a[i].name].second = a[i].rank;
		}
	}

	sort(a+1, a+1+n, cmp3);
	for(int i = 1; i <= n; i++){
		a[i].rank = i;
		if (a[i].m == a[i - 1].m) a[i].rank = a[i - 1].rank;
		if (a[i].rank < ans[a[i].name].second){
			ans[a[i].name].first = 'M';
			ans[a[i].name].second = a[i].rank;
		}
	}

	sort(a+1, a+1+n, cmp4);
	for(int i = 1; i <= n; i++){
		a[i].rank = i;
		if (a[i].e == a[i - 1].e) a[i].rank = a[i - 1].rank;
		if (a[i].rank < ans[a[i].name].second){
			ans[a[i].name].first = 'E';
			ans[a[i].name].second = a[i].rank;
		}
	}

	for(int i = 0; i < m; i++){
		string str; cin >> str;
		if (idx[str] == false) cout << "N/A\n";
		else cout << ans[str].second << " " << ans[str].first << '\n';
	}
}