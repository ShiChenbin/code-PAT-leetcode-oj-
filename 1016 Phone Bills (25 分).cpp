#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define rep(i, a, b) for (int i=a;i<=b;++i)
const int mod = int(1e9) + 7;
const int inf = 0x3f3f3f3f;
const ll inff = 0x3f3f3f3f3f3f3f3fLL;
const double pi = acos(-1.0); //M_PI;
const int maxn = 1e5 + 10;
	
int rate[25] = {0};
struct node
{
	string name;
	int status, month, time, day, hour, minute;
};

bool cmp(node a, node b){
	return a.name != b.name ? a.name < b.name : a.time < b.time;
}
double billFromZero(node call){
	//计算总花费
	double total = rate[call.hour] * call.minute + rate[24] * 60 * call.day;
	//分钟和天是好算的先进行计算
	//接下来计算多出的小时数
	for(int i = 0; i < call.hour; i++){
		total += rate[i] * 60;
	}
	return total / 100.0; //注意是美分
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	for(int i = 0; i < 24; i++){
		scanf("%d", &rate[i]);
		rate[24] += rate[i];
	}
	//用数组的最后一个位置去存储当时间是一天所需要的花费
	int n; cin >> n;//输入数据个数n
	std::vector<node> data(n);
	for(int i = 0; i < n; i++){
		cin >> data[i].name;
		scanf("%d:%d:%d:%d", &data[i].month, &data[i].day, &data[i].hour, &data[i].minute);
		string temp;
		cin >> temp;
		data[i].status = (temp == "on-line")? 1 : 0;
		data[i].time = data[i].day * 24 * 60 + data[i].hour * 60 + data[i].minute;
		//计算从0：0：0：0到当前时刻是多少分钟
	}
	sort(data.begin(), data.end(), cmp);
	map<string, vector<node> > custom;
	for(int i = 1; i < n; i++){
		if (data[i].name == data[i - 1].name && data[i].status == 0 && data[i - 1].status == 1){
			custom[data[i - 1].name].push_back(data[i - 1]);
			custom[data[i].name].push_back(data[i]);
			//将人的名字作为索引存储这个人的所有信息
		}
	}

	for(auto it: custom){
		std::vector<node> temp = it.second;
		cout << it.first;
		printf(" %02d\n", temp[0].month);//输出账单月份
		double total = 0.0;
		for(int i = 1; i < temp.size(); i += 2){
			double t = billFromZero(temp[i]) - billFromZero(temp[i - 1]); //计算花费
			printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", temp[i - 1].day, temp[i - 1].hour, temp[i - 1].minute, temp[i].day, temp[i].hour, temp[i].minute, temp[i].time - temp[i - 1].time, t);
            total += t;
		}
		printf("Total amount: $%.2f\n", total);
	}
	return 0;

}