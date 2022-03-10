#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define rep(i, a, b) for (int i=a;i<=b;++i)
const int mod = int(1e9) + 7;
const int inf = 0x3f3f3f3f;
const ll inff = 0x3f3f3f3f3f3f3f3fLL;
const double pi = acos(-1.0); //M_PI;
const int maxn = 100;

struct p
{
	string num;
	int inh, inm, ins;
	int outh, outm, outs;
}a[maxn], maxx, minn;
bool mincmp(p a, p b){
	if (a.inh < b.inh){
		return true;
	}
	else if (a.inh == b.inh){
		if (a.inm < b.inm){
			return true;
		}
		else if (a.inm == b.inm){
			if (a.ins < b.ins){
				return true;
			}
			else if (a.ins == b.ins){
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}
bool maxcmp(p a, p b){
	if (a.outh < b.outh){
		return true;
	}
	else if (a.outh == b.outh){
		if (a.outm < b.outm){
			return true;
		}
		else if (a.outm == b.outm){
			if (a.outs < b.outs){
				return true;
			}
			else if (a.outs == b.outs){
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int t; cin >> t;

	rep(i, 1, t){
		cin >> a[i].num;
		scanf("%d:%d:%d", &a[i].inh, &a[i].inm, &a[i].ins);
		scanf("%d:%d:%d", &a[i].outh, &a[i].outm, &a[i].outs);
		if (i == 1){
			minn.num = a[i].num;
			minn.inh = a[i].inh, minn.inm = a[i].inm, minn.ins = a[i].ins;
			maxx.num = a[i].num;
			maxx.outh = a[i].outh, maxx.outm = a[i].outm,maxx.outs = a[i].outs;
		}
		else {
			if (!mincmp(minn, a[i])){
				minn.num = a[i].num;
				minn.inh = a[i].inh, minn.inm = a[i].inm, minn.ins = a[i].ins;
			}
			if (maxcmp(maxx, a[i])){
				maxx.num = a[i].num;
				maxx.outh = a[i].outh, maxx.outm = a[i].outm,maxx.outs = a[i].outs;
			}
		}
	}
	cout << minn.num << " " << maxx.num << '\n';

}