#include <iostream>
using namespace std;
//题意 如果排队等待时间超过了17；00那就不服务了
struct node
{
	int hour, minute, s, cost;
};
int w[111]; //计算当前窗口需要等待的时间

bool cmp(node a, node b){
	return a.hour*60*60+a.minute*60+a.s == b.hour*60*60+b.minute*60+b.s ?a.hour*60*60+a.minute*60+a.s < b.hour*60*60+b.minute*60+b.s : a.cost < b.cost;
}

int main(){
	int n, m; cin >> n >> m;
	//n是排队的人数，而m是窗口的个数
	std::vector<node> a(n);
	for(int i = 0; i < n; i++){
		scanf("%d:%d:%d %d", &a[i].hour, &a[i].minute, &a[i].s, &a[i].cost);
	}

	sort(a.begin(), a.end(), cmp);

	int index = 0;
	int windowidx = 0;
	int sum = 0; //记录总的等待时间

	while(index < n){
		int tempmin = 0;
		for(int i = 0; i < m; i++){
			if (w[i] < w[tempmin]){
				tempmin = i;
			}
		}
		if(w[tempmin] > 540){
			break;
		}
		sum += w[tempmin];
		
		//找到时间最少的队伍


	}

}