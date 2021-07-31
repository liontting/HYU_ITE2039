// 2019042497_ΌΫΑ€Έν_11802
#include <stdio.h>
int A[100010], B[100010], num[100010];

int main() {
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 1; i <= K; i++) {
		scanf("%d %d", &A[i], &B[i]);
	}
	for (int i = 1; i <= N; i++) {
		int n;
		scanf("%d", &n);
		num[n]++;
	}
	for (int i = 1; i <= K; i++) {
		int dap = 0;
		for (int j = A[i]; j <= B[i]; j++) {
			if (num[j] != 0)
				dap++;
		}
		printf("%d\n", dap);
	}
	return 0;
}