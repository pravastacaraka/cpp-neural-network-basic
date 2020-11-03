#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <math.h>
#include <time.h>

using namespace std;

double d_rand()
{
	return ((double)(((rand() % 32767) / 32767.0 - 0.5) * 2.0));
}

double sigmoid(double x) {
	return ((double)(1.0 / (1.0 + exp(-x))));
}

int main() 
{
	//FILE *ferr = fopen("error.txt", "wt");
	int x[4][3] = 
	{
		{ 0, 0, 1 },
		{ 0, 1, 1 },
		{ 1, 0, 1 },
		{ 1, 1, 1 }
	};
	double y[3] = { 0.0, 0.0, 1.0 };
	double target[4] = { 0.0, 1.0, 1.0, 0.0 };
	double z, delta_o, delta_h[2], g1, f1[2];
	double w[2][3], s[3], tmp_out[2], learning_rate = 0.1, init = 0.15, error;

	// Inisialisasi bobot w dan s
	srand(time(0));
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			w[i][j] = init * d_rand();
		}
	}
	for (int i = 0; i < 3; i++) {
		s[i] = init * d_rand();
	}

	// Training
	for (int l = 0; l < 15000; l++) 
	{
		error = 0.0;
		for (int p = 0; p < 4; p++)
		{
			// hidden layer
			for (int i = 0; i < 2; i++)
			{
				tmp_out[i] = 0.0;
				for (int j = 0; j < 3; j++) {
					tmp_out[i] = tmp_out[i] + x[p][j] * w[i][j];
				}
				y[i] = sigmoid(tmp_out[i]);
			}

			// output layer
			tmp_out[0] = 0.0;
			for (int j = 0; j < 3; j++)
			{
				tmp_out[0] = tmp_out[0] + y[j] * s[j];
			}
			z = sigmoid(tmp_out[0]);

			// perbedaan target dengan output pada output layer
			g1 = z * (1 - z);
			delta_o = (target[p] - z) * g1;

			// perbedaan target dengan output pada hidden layer
			for (int i = 0; i < 2; i++)
			{
				f1[i] = y[i] * (1 - y[i]);
				delta_h[i] = delta_o * s[i] * f1[i];
			}

			// perbaikan bobot pada output layer dan hidden layer
			for (int j = 0; j < 3; j++)
			{
				s[j] += learning_rate * delta_o * y[j];
			}
			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					w[i][j] += learning_rate * delta_h[i] * x[p][j];
				}
			}
			error += ((target[p] - z) * (target[p] - z)) / 2;
		}
		error /= 4;
		if (error < 0.01) break;
		//fprintf(ferr, "%f\n", error);
	}
	//fclose(ferr);

	// Running
	for (int k = 0; k < 4; k++)
	{
		for (int i = 0; i < 2; i++)
		{
			cout << "Input x" << i << ": ";
			cin >> x[0][i];
		}

		for (int i = 0; i < 2; i++)
		{
			tmp_out[i] = 0.0;
			for (int j = 0; j < 3; j++)
			{
				tmp_out[i] = tmp_out[i] + x[0][j] * w[i][j];
			}
			y[i] = sigmoid(tmp_out[i]);
		}

		tmp_out[0] = 0.0;
		for (int j = 0; j < 3; j++)
		{
			tmp_out[0] = tmp_out[0] + y[j] * s[j];
		}
		z = sigmoid(tmp_out[0]);
		z < 0.5 ? cout << "Output: 0" << endl : cout << "Output: 1" << endl;
	}
	cout << endl;

	return 0;
}