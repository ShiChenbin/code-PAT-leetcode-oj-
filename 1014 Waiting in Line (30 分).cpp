#include <bits/stdc++.h>
using namespace std;
/*
	n个窗口、m个最大黄色队列、k顾客个数、q个顾客查询，每次选择最短的队列排	
*/
const int maxn = 22;
const int MAXN = 1111;
//时间直接记录经过的分钟数，方便比较，最后输出结果的时候再做处理即可
struct node
{
	int poptime, endtime; //队列中第一个人结束的时间和队列中最后一个人结束的时间
	queue<int> q; //
};

int main(){
	int n, m, k, q; cin >> n >> m >> k >> q;
	std::vector<int> time(k + 1);
	std::vector<int> result(k + 1);//记录每个人完成事务的时间
	for(int i = 1; i <= k; i++){
		cin >> time[i]; //输入每个顾客所需要花费的时间
	}
	std::vector<node> window(n + 1); //存储每个窗口的情况
	std::vector<bool> sorry(k + 1, false); //记录超时的人群

	//分两个部分，首先是如果n个窗口都没有排满的时候直接排队即可，然后是

	int index = 1;
	//有n个窗口每个窗口最多可以排m个人
	//第i个位置，第j个窗口，因为每次选择最短的队列进行排队
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			if (index <= k){
				//只用处理k个人
				window[j].q.push(time[index]);//将当前人所需要花费的时间压入窗口队列当中
				if (window[j].endtime >= 540){
					sorry[index] = true;
					//如果服务时间超过17；00就不能服务了，判断为当前人是sorry
				}
				window[j].endtime += time[index]; //当前服务的人所需要的时间
				if (i == 1)
					window[j].poptime = window[j].endtime;//最开始的时候，确定队列减少一个人所需要花费的时间
				result[index] = window[j].endtime;//并且记录这个人的完成时间
				index++;
			}

		}
	}


	while(index <= k){
		
		int tempmin = window[1].poptime,tempwindow = 1;
		//找到最快排到下一个人的队伍，最快出队poptime
		for(int i = 2; i <= n; i++){
			if (window[i].poptime < tempmin){
				tempwindow = i;//记录是哪个窗口
				tempmin = window[i].poptime;
			}
		}

		window[tempwindow].q.pop();//当前窗口的第一个人完成服务
		window[tempwindow].q.push(time[index]);//压入新的一个人
		window[tempwindow].poptime += window[tempwindow].q.front();//当前窗口第一个出队时间

		if (window[tempwindow].endtime >= 540){
			sorry[index] = true; //同样也要对超时时间进行判断
		}
		
		window[tempwindow].endtime += time[index]; //现在去排的就变成最后一位了
		result[index] = window[tempwindow].endtime;//那么这个人的结束时间也可以确定了
		index++;
	}

	for(int i = 1; i <= q; i++){
		int query, minute;
		cin >> query;
		minute = result[query];
		if (sorry[query]){
			printf("Sorry\n");
		}
		else {
			printf("%02d:%02d\n",(minute + 480) / 60, (minute + 480) % 60);
		}
	}
	return 0;
}