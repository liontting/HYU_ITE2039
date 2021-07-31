// 2019042497_ΌΫΑ€Έν_11802
#include <iostream>
using namespace std;
int num[30010];
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> num[i];
	int j;
	for (int i = 1; i < N; i++) {
		int temp = num[i];

		for (j = i - 1; j >= 0 && num[j] < temp; j--)
			num[j + 1] = num[j];
		num[j + 1] = temp;
	}

	for (int i = 0; i < N; i++)
		cout << num[i] << "\n";
	return 0;
}