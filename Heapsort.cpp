// 2019042497_ΌΫΑ€Έν_11802
#include <stdio.h>

int heap[100010], N, k;

void HeapIfy(int i) {
	int parent = i;
	int left = i * 2;
	int right = i * 2 + 1;
	int big = parent;

	if (left <= N && heap[left] > heap[big])
		big = left;
	if (right <= N && heap[right] > heap[big])
		big = right;
	if (parent != big) {
		int temp = heap[parent];
		heap[parent] = heap[big];
		heap[big] = temp;
		HeapIfy(big);
	}
}

void BuildMax() {
	int i;
	for (i = N / 2; i >= 1; i--)
		HeapIfy(i);
}

int DeleteMax(int* heap, int end) {
	int i, child;
	int Max = heap[1];
	int Last = heap[end];
	for (i = 1; i * 2 <= end; i = child) {
		child = i * 2;
		if (child + 1 < end && heap[child] < heap[child + 1])
			child++;
		if (Last < heap[child])
			heap[i] = heap[child];
		else
			break;
	}
	heap[i] = Last;
	return Max;
}

int main() {
	scanf("%d %d", &N, &k);
	for (int i = 1; i <= N; i++)
		scanf("%d", &heap[i]);
	BuildMax();
	for (int i = 0; i < k; i++)
		printf("%d ", DeleteMax(heap, N - i));
	printf("\n");
	for (int i = 1; i <= N - k; i++)
		printf("%d ", heap[i]);
	return 0;
}