// 2019042497_송정명_11802
#include <stdio.h>
int m[110][110], s[110][110], p[110];

void print(int i, int j) {
	if (i == j)
		printf("%d ", i);
	else {
		printf("( ");
		print(i, s[i][j]);
		print(s[i][j] + 1, j);
		printf(") ");
	}
}

int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i <= N; i++)
		scanf("%d", &p[i]);
	for (int i = 1; i <= N; i++)
		m[i][i] = 0;
	for (int a = 1; a < N; a++) {
		for (int i = 1; i <= N - a; i++) {
			int j = i + a;
			m[i][j] = 2100000000;
			for (int k = i; k < j; k++) {
				int tmp = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (tmp < m[i][j]) {
					m[i][j] = tmp;
					s[i][j] = k;
				}
			}
		}
	}
	printf("%d\n", m[1][N]);
	print(1, N);
	return 0;
}