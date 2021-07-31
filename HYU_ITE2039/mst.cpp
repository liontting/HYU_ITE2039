// 2019042497_ΌΫΑ€Έν_11802
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct edge {
	int x, y, w;
}edge;

int N, M;
int p[1010];
vector <edge> v;
vector <edge> answer;

bool compare(const edge &e1, const edge &e2) {
	if (e1.w < e2.w)
		return true;
	else if (e1.w == e2.w) {
		if (e1.x < e2.x)
			return true;
		else if (e1.x == e2.x)
			return e1.y < e2.y;
		else
			return false;
	}
	else
		return false;
}

int find(int x) {
	if (p[x] == x) return x;
	else return p[x] = find(p[x]);
}

void uni(int a, int b) {
	if (find(a) != find(b))
		p[find(a)] = find(b);
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++)
		p[i] = i;
	for (int i = 0; i < M; i++) {
		int x, y, w;
		edge temp;
		scanf("%d %d %d", &x, &y, &w);
		temp.x = x;
		temp.y = y;
		temp.w = w;
		v.push_back(temp);
	}
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < M; i++) {
		if (find(v[i].x) != find(v[i].y)) {
			answer.push_back(v[i]);
			uni(v[i].x, v[i].y);
		}
	}
	printf("%d\n", answer.size());
	for (int i = 0; i < answer.size(); i++) {
		printf("%d %d %d\n", answer[i].x, answer[i].y, answer[i].w);
	}
	return 0;
}