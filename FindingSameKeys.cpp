// 2019042497_ΌΫΑ€Έν_11802
#include <stdio.h>
int A[100010], B[100010];

void QuickSort(int* arr, int start, int end) {
	if (start >= end)
		return;
	int pivot = start;
	int i = pivot + 1;
	int j = end;
	int temp;

	while (i <= j) {
		while (i <= end && arr[i] <= arr[pivot])
			i++;
		while (j > start && arr[j] >= arr[pivot])
			j--;
		if (i > j) {
			temp = arr[j];
			arr[j] = arr[pivot];
			arr[pivot] = temp;
		}
		else {
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}

	QuickSort(arr, start, j - 1);
	QuickSort(arr, j + 1, end);
}

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	for (int i = 0; i < M; i++) {
		scanf("%d", &B[i]);
	}
	QuickSort(A, 0, N - 1);
	QuickSort(B, 0, M - 1);
	int dap = 0, gi = 0;
	for (int i = 0; i < N; i++) {
		for (int j = gi; j < M; j++) {
			if (A[i] == B[j]) {
				dap++;
				gi = j + 1;
			}
		}
	}
	printf("%d", dap);
	return 0;
}