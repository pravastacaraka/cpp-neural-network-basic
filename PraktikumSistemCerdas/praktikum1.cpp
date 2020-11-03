#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int select_mode()
{
	int mode;

	printf("===== McCulloch Pitts =====\n");
	printf("1. Percobaan AND\n");
	printf("2. Percobaan OR\n");
	printf("3. Percobaan XOR\n");
	printf("4. Tugas AND\n");
	printf("5. Tugas OR\n");
	printf("6. Tugas XOR\n");
	printf("7. Keluar Program\n");
	printf("Pilih program: ");
	scanf("%d", &mode);

	return mode;
}

int main()
{
	int mode;
	int x1, x2, x3, y, out;
	int w1, w2, w3, w4, w5, w6, w_or, w_nand, t;

	for (;;)
	{
		mode = select_mode();

		if (mode == 1 || mode == 2)
		{
			if (mode == 1)
			{	
				// inisialiasi bobot dan threshold pada "and"
				w1 = 1, w2 = 1, t = 2;
				printf("\n=== Percobaan AND ===\n");
			}
			else if (mode == 2)
			{
				// inisialiasi bobot dan threshold pada "or"
				w1 = 2, w2 = 2, t = 2;
				printf("\n=== Percobaan OR ===\n");
			}

			// running
			for (int i = 0; i < 4; i++)
			{
				printf("Input x1: ");
				scanf("%d", &x1);
				printf("Input x2: ");
				scanf("%d", &x2);

				y = w1 * x1 + w2 * x2;
				(y >= t) ? out = 1 : out = 0;

				printf("Output: %d\n", out);
			}
		}
		else if (mode == 3)
		{
			// inisialiasi bobot dan threshold pada "xor", nilai -1 adalah bobot lintas neuron (nand)
			w1 = 2, w2 = -1, w3 = 2;
			w4 = -1, w5 = 2, w6 = 2, t = 2;
			int o1, o2, o3, z1, z2;

			printf("\n=== Percobaan XOR ===\n");

			// running
			for (int i = 0; i < 4; i++)
			{
				printf("Input x1: ");
				scanf("%d", &x1);
				printf("Input x2: ");
				scanf("%d", &x2);

				o1 = w1 * x1 + w4 * x2;
				(o1 >= t) ? z1 = 1 : z1 = 0;

				o2 = w2 * x1 + w3 * x2;
				(o2 >= t) ? z2 = 1 : z2 = 0;

				o3 = w5 * z1 + w6 * z2;
				(o3 >= t) ? y = 1 : y = 0;

				printf("Output: %d\n", y);
			}
		}
		else if (mode == 4 || mode == 5)
		{
			if (mode == 4)
			{
				// inisialiasi bobot dan threshold pada "and" 3 input
				w1 = 1, w2 = 1, w3 = 1, t = 3;
				printf("\n=== Tugas AND ===\n");
			}
			else if (mode == 5)
			{
				// inisialiasi bobot dan threshold pada "or" 3 input
				w1 = 2, w2 = 2, w3 = 2, t = 2;
				printf("\n=== Tugas OR ===\n");
			}

			for (int i = 0; i < 8; i++)
			{
				printf("Input x1: ");
				scanf("%d", &x1);
				printf("Input x2: ");
				scanf("%d", &x2);
				printf("Input x3: ");
				scanf("%d", &x3);

				y = w1 * x1 + w2 * x2 + w3 * x3;
				(y >= t) ? out = 1 : out = 0;

				printf("Output: %d\n", out);
			}
		}
		else if (mode == 6)
		{
			// inisialiasi bobot dan threshold pada "xor" 3 input, nilai -1 adalah bobot lintas neuron (nand)
			w_or = 2, w_nand = -1, t = 2;
			int o1, o2, o3, o4, o5, o6, z1, z2, z3, z4, z5;

			printf("\n=== Tugas XOR ===\n");

			// running
			for (int i = 0; i < 8; i++)
			{
				printf("Input x1: ");
				scanf("%d", &x1);
				printf("Input x2: ");
				scanf("%d", &x2);
				printf("Input x3: ");
				scanf("%d", &x3);

				o1 = w_or * x1 + w_nand * x2;
				if (o1 >= t)
					z1 = 1;
				else
					z1 = 0;

				o2 = w_nand * x1 + w_or * x2;
				if (o2 >= t)
					z2 = 1;
				else
					z2 = 0;

				o3 = w_or * z1 + w_or * z2;
				if (o3 >= t)
					z3 = 1;
				else
					z3 = 0;

				o4 = w_or * z3 + w_nand * x3;
				if (o4 >= t)
					z4 = 1;
				else
					z4 = 0;

				o5 = w_nand * z3 + w_or * x3;
				if (o5 >= t)
					z5 = 1;
				else
					z5 = 0;

				o6 = w_or * z4 + w_or * z5;
				if (o6 >= t)
					y = 1;
				else
					y = 0;

				printf("Output: %d\n", y);
			}
		}
		else if (mode == 7)
		{
			break;
		}
		else
		{
			printf("\nMode tidak tersedia!\n\n");
			continue;
		}
		printf("\n");
	}

	return 0;
}