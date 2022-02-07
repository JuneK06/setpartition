#include <stdio.h>

#define N 3

void bsort(int* x)
{
	int i, j;

	for (i = 0; i < N - 1; i++)
		for (j = N - 1; j > i; j--)
			if (x[j - 1] > x[j]) {
				int temp = x[j];
				x[j] = x[j - 1];
				x[j - 1] = temp;
			}
}

int main(void)
{
	int x[N];
	int a = 0, b = 0;
	int i, j;
	int trgt = 0, best;

	for (i = 0; i < N; i++) {
		x[i] = rand();
		trgt += x[i];
	}
	trgt /= 2;

	for (i = 1; i < N; i++) {
		for (j = 0; j < i; j++) {
			a += x[j];
		}
	}

	return 0;
}