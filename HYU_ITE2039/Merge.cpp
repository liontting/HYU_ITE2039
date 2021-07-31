// 2019042497_ΌΫΑ€Έν_11802
#include <iostream>
using namespace std;
int N, num[100010], jeong[100010];

void merge(int left, int right) {
	int mid = (left + right) / 2;
	int i = left;
	int j = mid + 1;
	int k = left;
	while (i <= mid && j <= right) {
		if (num[i] <= num[j])
			jeong[k++] = num[i++];
		else
			jeong[k++] = num[j++];
	}
	if (i > mid)
		while (j <= right)
			jeong[k++] = num[j++];
	else
		while (i <= mid)
			jeong[k++] = num[i++];
	for (int i = left; i <= right; i++)
		num[i] = jeong[i];
}

void partition(int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		partition(left, mid);
		partition(mid + 1, right);
		merge(left, right);
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> num[i];
	partition(0, N - 1);
	for (int i = N - 1; i >= 0; i--)
		cout << num[i] << "\n";
	return 0;
}