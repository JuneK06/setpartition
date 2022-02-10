﻿#include <stdio.h>
#include <stdlib.h>

#define N 6

int trgt = 0;
int best = 10000;
int rslt;
int x[N];

void setpar(int a, int tmp, int cnt)
{
	int i;
	for (i = 0; i < N - a + 1; i++) {
		int c = tmp + x[i + cnt];
		if (cnt + 1 < a) {
			setpar(a, c, cnt + 1);
		}
		else {
			int y = (trgt > c) ? trgt - c : c - trgt;
			if (best > y) {
				best = y;
				rslt = c;
			}
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
		setpar(i, 0, 0);

	printf("結果：%d", rslt);

	return 0;
}