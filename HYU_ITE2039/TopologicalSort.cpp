// 2019042497_ΌΫΑ€Έν_11802
#include <stdio.h>
#include <stack>
using namespace std;

int arr[1010][1010];
int visited[1010];
int color[1010];
int N, M, num = 1;
stack <int> s;

void DFS(int v) {
	color[v] = 1;
	for (int w = 1; w <= N; w++) {
		if (arr[v][w]) {
			if (!color[w])
				DFS(w);
			else if (color[w] == 1)
				num = 0;
		}
	}
	color[v] = 2;
	s.push(v);
}

int main() {
	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		arr[x][y] = 1;
	}

	for (int i = 1; i <= N; i++)
		if (!color[i])
			DFS(i);

	if (s.size() != N)
		num = 0;

	if (num) {
		printf("1\n");
		while (!s.empty()) {
			printf("%d ", s.top());
			s.pop();
		}
	}
	else
		printf("0\n");
	return 0;
}