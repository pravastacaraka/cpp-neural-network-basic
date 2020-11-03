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
	double x[11][4] =
	{
		{ 1.00, 1.00, 0.67, 1.00 },
		{ 1.00, 0.67, 0.67, 1.00 },
		{ 1.00, 0.67, 0.33, 1.00 },
		{ 1.00, 0.33, 0.33, 1.00 },
		{ 0.67, 1.00, 0.67, 1.00 },
		{ 0.67, 0.67, 0.67, 1.00 },
		{ 0.67, 0.67, 0.33, 1.00 },
		{ 0.67, 0.33, 0.33, 1.00 },
		{ 0.33, 1.00, 0.67, 1.00 },
		{ 0.33, 0.67, 0.33, 1.00 },
		{ 0.33, 0.33, 0.67, 1.00 }
	};
	double y[6] = { 0.0, 0.0, 1.0, 0.0, 0.0, 0.0 };
	double t[11] = { 1.0, 1.0, 1.0, 0.0, 1.0, 1.0, 1.0, 0.0, 1.0, 0.0, 1.0 };
	double z, delta_o, delta_h[6], g1, f1[6];
	double w[6][4], s[6], tmp_out[6], learning_rate = 0.1, init = 0.15, error;

	srand(time(0)); // untuk mendukung generate rand()

	// Inisialisasi bobot w dan s
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 4; j++) {
			w[i][j] = init * d_rand();
		}
	}
	for (int i = 0; i < 3; i++) {
		s[i] = init * d_rand();
	}

	// Training
	for (int l = 0; l < 5000; l++)
	{
		error = 0.0;
		// jumlah dataset yang akan dilatih
		for (int p = 0; p < 11; p++)
		{
			// perhitungan bobot pada hidden layer
			for (int i = 0; i < 2; i++)
			{
				tmp_out[i] = 0.0;
				// looping masukan sistem + 1 bias
				for (int j = 0; j < 4; j++) {
					tmp_out[i] += x[p][j] * w[i][j];
				}
				y[i] = sigmoid(tmp_out[i]);
			}

			// perhitungan bobot pada output layer
			tmp_out[0] = 0.0;
			for (int j = 0; j < 3; j++)
			{
				tmp_out[0] += y[j] * s[j];
			}
			z = sigmoid(tmp_out[0]);

			// perbedaan t dengan output pada output layer
			g1 = z * (1 - z);
			delta_o = (t[p] - z) * g1;

			// perbedaan t dengan output pada hidden layer
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
				for (int j = 0; j < 4; j++)
				{
					w[i][j] += learning_rate * delta_h[i] * x[p][j];
				}
			}
			error += ((t[p] - z) * (t[p] - z)) / 2;
		}
		error /= 11;
		if (error < 0.00001) break;
		//fprintf(ferr, "%f\n", error);
	}
	//fclose(ferr);

	// Running
	for (int k = 0; k < 7; k++)
	{
		cout << "Nilai IPK: "; cin >> x[0][0];
		cout << "Psikologi: "; cin >> x[0][1];
		cout << "Wawancara: "; cin >> x[0][2];
		cout << endl;

		for (int i = 0; i < 2; i++)
		{
			tmp_out[i] = 0.0;
			for (int j = 0; j < 4; j++)
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

		z < 0.5 
			? cout << "Keputusan: Tidak Lulus" << endl 
			: cout << "Keputusan: Lulus" << endl;
		cout << endl;
	}

	return 0;
}