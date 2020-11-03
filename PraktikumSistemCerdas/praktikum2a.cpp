#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

double d_rand()
{
	return(((double)(rand() % 32767) / 32767.0 - 0.5) * 2.0);
}

int select_mode()
{
	int mode;

	printf("===== Single Perceptron =====\n");
	printf("1. Percobaan AND\n");
	printf("2. Percobaan OR\n");
	printf("3. Keluar Program\n");
	printf("Pilih Mode: ");
	scanf("%d", &mode);

	return mode;
}

int main()
{
	int mode, i, j, out, ERR, y;
	int T[4];

	for (;;)
	{
		int x[3][4] = { // inisialisasi data set
			{0, 0, 1, 1},
			{0, 1, 0, 1},
			{1, 1, 1, 1}
		};
		float w[3], O, LR = 0.1, init = 0.15;

		mode = select_mode();

		if (mode == 1) {
			T[0] = 0; T[1] = 0; T[2] = 0; T[3] = 1;
			printf("\n=== Percobaan AND ===\n");
		}
		else if (mode == 2) {
			T[0] = 0; T[1] = 1; T[2] = 1; T[3] = 1;
			printf("\n=== Percobaan OR ===\n");
		}
		else if (mode == 3) {
			break;
		}
		else {
			printf("\nMode tidak tersedia!\n\n");
			continue;
		}

		// inisialisasi bobot
		for (i = 0; i < 3; i++) {
			w[i] = init * d_rand();
		}

		// training
		for (i = 0; i < 10; i++)
		{
			for (j = 0; j < 4; j++)
			{
				O = x[0][j] * w[0] + x[1][j] * w[1] + x[2][j] * w[2];
				(O > 0.0) ? out = 1 : out = 0;

				ERR = T[j] - out;
				if (ERR != 0)
				{
					w[0] = w[0] + LR * x[0][j] * ERR;
					w[1] = w[1] + LR * x[1][j] * ERR;
					w[2] = w[2] + LR * x[2][j] * ERR;
				}
			}
		}

		// running
		for (i = 0; i < 4; i++)
		{
			printf("Input x1: ");
			scanf("%d", &x[0][0]);
			printf("Input x2: ");
			scanf("%d", &x[1][0]);

			O = x[0][0] * w[0] + x[1][0] * w[1] + x[2][0] * w[2];
			if (O > 0.0)
				y = 1;
			else
				y = 0;

			printf("Output: %d\n", y);
		}
		printf("\n");
	}

	return 0;
}