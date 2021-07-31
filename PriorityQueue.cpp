// 2019042497_ΌΫΑ€Έν_11802
#include <stdio.h>

int heap[100010], N;

void HeapIfy(int i) {
	int parent = i;
	int left = i * 2;
	int right = i * 2 + 1;
	int big = parent;

	if (right <= N && heap[right] > heap[big])
		big = right;
	if (left <= N && heap[left] > heap[big])
		big = left;
	if (parent != big) {
		int temp = heap[parent];
		heap[parent] = heap[big];
		heap[big] = temp;
		HeapIfy(big);
	}
}

int DeleteMax() {
	int i, child;
	int Max = heap[1];
	int Last = heap[N];
	for (i = 1; i * 2 <= N; i = child) {
		child = i * 2;
		if (child + 1 <= N && heap[child] <= heap[child + 1])
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
	int first;
	while (1) {
		scanf("%d", &first);
		if (first == 0) {
			printf("\n");
			for (int i = 1; i <= N; i++)
				printf("%d ", heap[i]);
			break;
		}
		else if (first == 1) {
			N++;
			scanf("%d", &heap[N]);
			int i = N;
			while (i > 1 && heap[i / 2] < heap[i]) {
				int tmp = heap[i / 2];
				heap[i / 2] = heap[i];
				heap[i] = tmp;
				i = i / 2;
			}
		}
		else if (first == 2) {
			printf("%d ", DeleteMax());
			N--;
		}
		else if (first == 3) {
			int index, num;
			scanf("%d %d", &index, &num);
			if (heap[index] > num) {
				heap[index] = num;
				HeapIfy(index);
			}
			else if (heap[index] < num) {
				heap[index] = num;
				int i = index;
				while (i > 1 && heap[i / 2] < heap[i]) {
					int tmp = heap[i / 2];
					heap[i / 2] = heap[i];
					heap[i] = tmp;
					i = i / 2;
				}
			}
		}
	}
	return 0;
}