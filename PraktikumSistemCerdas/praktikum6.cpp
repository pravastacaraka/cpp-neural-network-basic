#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#define mu 0.2f
#define I 1000
#define M 5

using namespace std;

double Input[I] = { 0.0 };
double Desired[I] = { 0.0 };
double H[M] = { 0.0625, 0.0125, 0.25, 0.5, 1 };

void initialize()
{
	for (int i = 0; i < I; i++) {
		// Inisialisasi input dengan nilai random
		Input[i] = rand() / (float)RAND_MAX;

		// Membuat target sinyal
		for (int j = 0; j < M; j++)
			if (i - j >= 0)
				Desired[i] += Input[i - j] * H[j];
	}
}

void main() // Least Mean Square (LMS)
{
	double X[M] = { 0.0 }, W[M] = { 0.0 }, D, Y, E;

	// Inisialisasi program
	initialize();

	printf("%3s %15s %10s\n", "I", "Output Filter", "Error");
	printf("------------------------------\n");
	for (int T = 0; T < I; T++)
	{
		// Membuat sample input untuk LMS Filter
		for (int m = T; m > T - M; m--)
		{
			if (m >= 0) X[M + (m - T) - 1] = Input[m];
			else break;
		}

		// Target sinyal
		D = Desired[T];
		Y = 0;
		
		// Menghitung output filter
		for (int i = 0; i < M; i++) Y += (W[i] * X[i]);

		// Menghitung error sinyal
		E = D - Y;
		if (E == 0.0) break;

		// Memperbaiki bobot baru
		for (int i = 0; i < M; i++)
			W[i] = W[i] + (mu * E * X[i]);

		printf("%3d %15f %10f\n", T, Y, E);
	}

	printf("\nNilai Bobot:\n");
	for (int i = 0; i < M; i++) {
		printf("%3d %10f\n", i+1, W[i]);
	}
}