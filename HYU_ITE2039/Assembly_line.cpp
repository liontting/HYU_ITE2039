// 2019042497_ΌΫΑ€Έν_11802
#include <stdio.h>
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
int e[2], x[2], a[2][110], t[2][110], s[2][110], l[3][110];

int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < 2; i++)
		scanf("%d", &e[i]);
	for (int i = 0; i < 2; i++)
		scanf("%d", &x[i]);
	for (int i = 0; i < N; i++)
		scanf("%d", &a[0][i]);
	for (int i = 0; i < N; i++)
		scanf("%d", &a[1][i]);
	for (int i = 0; i < N - 1; i++)
		scanf("%d", &t[0][i]);
	for (int i = 0; i < N - 1; i++)
		scanf("%d", &t[1][i]);

	s[0][0] = e[0] + a[0][0];
	s[1][0] = e[1] + a[1][0];
	for (int i = 1; i < N; i++) {
		if (s[0][i - 1] <= s[1][i - 1] + t[1][i - 1]) {
			s[0][i] = s[0][i - 1] + a[0][i];
			l[0][i] = 1;
		}
		else {
			s[0][i] = s[1][i - 1] + t[1][i - 1] + a[0][i];
			l[0][i] = 2;
		}
		if (s[1][i - 1] <= s[0][i - 1] + t[0][i - 1]) {
			s[1][i] = s[1][i - 1] + a[1][i];
			l[1][i] = 2;
		}
		else {
			s[1][i] = s[0][i - 1] + t[0][i - 1] + a[1][i];
			l[1][i] = 1;
		}
	}
	s[0][N] = s[0][N - 1] + x[0];
	s[1][N] = s[1][N - 1] + x[1];
	int mem;
	if (s[0][N] <= s[1][N]) {
		printf("%d\n", s[0][N]);
		mem = l[0][N] = 1;
	}
	else {
		printf("%d\n", s[1][N]);
		mem = l[1][N] = 2;
	}
	for (int i = N; i >= 1; i--) {
		if (i == N)
			l[2][i] = mem;
		else
			l[2][i] = l[l[2][i + 1] - 1][i];
	}
	for (int i = 1; i <= N; i++)
		printf("%d %d\n", l[2][i], i);
	return 0;
}