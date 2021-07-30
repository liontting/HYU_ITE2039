// 2019042497_ΌΫΑ€Έν_11802
#include <stdio.h>
#include <string.h>
#include <algorithm>

int N, total, dap;

typedef struct node {
	char* s;
	int cnt;
	node* left;
	node* right;
}node;

struct HeapStruct {
	int Size;
	node* Elements;
};

HeapStruct* CreateHeap() {
	HeapStruct* heap = (HeapStruct*)malloc(sizeof(HeapStruct));
	heap->Elements = (node*)malloc(sizeof(node)*(30010));
	heap->Size = 0;
	return heap;
}

void Insert(HeapStruct* heap, node value) {
	int i;
	for (i = ++heap->Size; i != 1 && heap->Elements[i / 2].cnt > value.cnt; i /= 2) {
		heap->Elements[i] = heap->Elements[i / 2];
	}
	heap->Elements[i] = value;
}

node* DeleteMin(HeapStruct* heap) {
	int i, child;
	node* Min = (node*)malloc(sizeof(node));
	node Last;
	if (heap->Size == 0)
		return NULL;

	Min->cnt = heap->Elements[1].cnt;
	Min->left = heap->Elements[1].left;
	Min->right = heap->Elements[1].right;
	if (heap->Elements[1].s != NULL) {
		Min->s = (char*)malloc(5);
		strcpy(Min->s, heap->Elements[1].s);
	}
	else
		Min->s = NULL;
	Last = heap->Elements[heap->Size--];
	for (i = 1; i * 2 <= heap->Size; i = child) {
		child = i * 2;
		if (child != heap->Size&&heap->Elements[child + 1].cnt < heap->Elements[child].cnt)
			child++;
		if (Last.cnt > heap->Elements[child].cnt)
			heap->Elements[i] = heap->Elements[child];
		else
			break;
	}
	heap->Elements[i] = Last;
	return Min;
}

node* buildHuffmanTree(HeapStruct* heap) {
	while (1) {
		node* first = DeleteMin(heap);
		node* second = DeleteMin(heap);
		if (second == NULL)
			return first;

		node* newOne = (node*)malloc(sizeof(node));
		newOne->left = first;
		newOne->right = second;
		newOne->cnt = first->cnt + second->cnt;
		newOne->s = NULL;

		Insert(heap, *newOne);
	}
}

void Huffman(node* cur, int count) {
	if (!cur)
		return;
	count++;
	Huffman(cur->left, count);
	Huffman(cur->right, count);
	if (cur->s != NULL) {
		dap += count * cur->cnt;
		//printf("%s, %d, count: %d\n", cur->s, cur->cnt, count);
	}
}

int main() {
	HeapStruct* h = CreateHeap();
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		char s[5];
		int n;
		scanf("%s", s);
		scanf("%d", &n);
		node* newOne = (node*)malloc(sizeof(node));
		newOne->left = NULL;
		newOne->right = NULL;
		newOne->s = (char*)malloc(5);
		strcpy(newOne->s, s);
		newOne->cnt = n;
		Insert(h, *newOne);
	}
	scanf("%d", &total);

	int yee = 1, soo = 0;
	while (N > yee) {
		yee *= 2;
		soo++;
	}

	node* tree = buildHuffmanTree(h);
	Huffman(tree, -1);

	printf("%d\n", total*soo);
	printf("%d\n", dap);
	return 0;
}