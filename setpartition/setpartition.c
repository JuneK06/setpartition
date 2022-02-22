#include <stdio.h>
#include <stdlib.h>

#define N 6

int trgt = 0;
int best = 10000;
int rslt;
int x[N] = { 0 }; /* 手動で値を代入 */
int tmpi[N / 2] = { 0 };
int index[N / 2] = { 0 };

void setpar(int a, int tmp, int j, int cnt)
{
	int i;
	for (i = j; i < cnt + N - a; i++) {
		int c = tmp + x[i];
		tmpi[cnt - 1] = i;
		if (cnt < a) {
			setpar(a, c, i + 1, cnt + 1);
		}
		else {
			int y = (trgt > c) ? trgt - c : c - trgt;
			if (best > y) {
				best = y;
				rslt = c;
				int k;
				for (k = 0; k < N / 2; k++)
					index[k] = tmpi[k];
			}
		}
	}
}

int main(void)
{
	int i;

	for (i = 0; i < N; i++) {
		x[i] = rand() % 100; /* ランダムな値を代入(手動にする場合はコメントアウト) */
		trgt += x[i];
		printf("%d ", x[i]);
	}
	trgt /= 2;
	printf("\n目標値：%d\n", trgt);

	for (i = 1; i <= N / 2; i++)
		setpar(i, 0, 0, 1);

	printf("結果：%d\n", rslt);
	printf("インデックス：");
	for (i = 0; i < N / 2; i++)
		if (i == 0 || index[i] != 0)
			printf("%d ", index[i]);
	putchar('\n');

	return 0;
}