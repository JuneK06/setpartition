#include <stdio.h>
#include <stdlib.h>

#define N 6

int trgt = 0;
int best = 10000;
int rslt;
int x[N];

void setpar(int a, int tmp, int j, int cnt)
{
	int i;
	for (i = j; i < cnt + N - a; i++) {
		int c = tmp + x[i];
		printf("%d ", i);
		if (cnt < a) {
			setpar(a, c, i + 1, cnt + 1);
		}
		else {
			int y = (trgt > c) ? trgt - c : c - trgt;
			if (best > y) {
				best = y;
				rslt = c;
			}
			putchar('\n');
		}
	}
}

int main(void)
{
	int i;

	for (i = 0; i < N; i++) {
		x[i] = rand() % 100;
		trgt += x[i];
		printf("%d ", x[i]);
	}
	trgt /= 2;
	printf("\n目標値：%d\n", trgt);

	for (i = 1; i <= N / 2; i++)
		setpar(i, 0, 0, 1);

	printf("結果：%d", rslt);

	return 0;
}