// 2019042497_ΌΫΑ€Έν_11802
#include <stdio.h>

int arr[1010][1010];
int visited[1010];
int N, M, num;

void DFS(int v) {
	visited[v] = 1;

	for (int w = 1; w <= N; w++)
		if (arr[v][w] && !visited[w])
			DFS(w);
}

int main() {
	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		arr[x][y] = 1;
		arr[y][x] = 1;
	}

	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			DFS(i);
			num++;
		}
	}
	
	printf("%d", num);
	return 0;
}