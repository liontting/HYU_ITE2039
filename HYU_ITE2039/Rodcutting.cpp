// 2019042497_ΌΫΑ€Έν_11802
#include <stdio.h>
int p[110], r[110], s[110];

int main() {
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &p[i]);
	for (int i = 1; i <= N; i++) {
		r[i] = p[i];
		int j = 0;
		s[i] = i;
		for (j = 1; j <= i; j++) {
			if (r[i] < r[j] + r[i - j]) {
				r[i] = r[j] + r[i - j];
				s[i] = j;
			}
		}
	}
	printf("%d\n", r[N]);
	while (N > 0) {
		printf("%d ", s[N]);
		N = N - s[N];
	}
	return 0;
}