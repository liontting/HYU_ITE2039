// 2019042497_ΌΫΑ€Έν_11802
#include <stdio.h>
#include <vector>
#include <queue>
#define INF 2100000000
using namespace std;

int N, M, maxi;
vector< pair<int, int> > graph[5010];
int dis[5010];

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		int x, y, w;
		scanf("%d %d %d", &x, &y, &w);
		graph[x].push_back(make_pair(y, w));
	}
	for (int i = 1; i <= N; i++)
		dis[i] = INF;
	priority_queue<pair <int, int> > pq;
	dis[1] = 0;
	pq.push(make_pair(0, 1));
	while (!pq.empty()) {
		int now = pq.top().second;
		int nowdist = -pq.top().first;
		pq.pop();
		for (int i = 0; i < graph[now].size(); i++) {
			pair<int, int> next = graph[now][i];
			if (dis[next.first] >= nowdist + next.second) {
				dis[next.first] = nowdist + next.second;
				pq.push(make_pair(-dis[next.first], next.first));
			}
		}
	}
	for (int i = 1; i <= N; i++)
		if (maxi < dis[i])
			maxi = dis[i];
	printf("%d", maxi);
	return 0;
}