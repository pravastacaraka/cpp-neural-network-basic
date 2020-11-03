#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <math.h>

using namespace std;

int mode;

void coba_praktikum(int maxEpoch) 
{
	const int totalClass = 2, totalData = 4, totalFeature = 4;
	double w[totalClass][totalFeature] = { // bobot awal
		{.2, .6, .5, .9},
		{.8, .4, .7, .3}
	};
	int x[totalData][totalFeature] = { // inisialisasi data set
		{1, 1, 0, 0},
		{0, 0, 0, 1},
		{1, 0, 0, 0},
		{0, 0, 1, 1}
	};
	double D[totalClass]; // jarak bobot dengan nilai masukan
	double LR = 0.6;

	// training
	for (int l = 0; l < maxEpoch; l++) {
		// looping untuk setiap dataset
		for (int k = 0; k < totalData; k++) {
			// hitung jarak D untuk setiap bobot dan masukan vektor
			for (int j = 0; j < totalClass; j++) {
				D[j] = 0.0;
				for (int i = 0; i < totalFeature; i++) {
					D[j] = D[j] + (w[j][i] - x[k][i])*(w[j][i] - x[k][i]);
				}
			}
			// pembaruan nilai bobot untuk jarak minimum
			if (D[0] < D[1]) {
				for (int i = 0; i < totalFeature; i++) {
					w[0][i] = w[0][i] + LR * (x[k][i] - w[0][i]);
				}
			}
			else {
				for (int i = 0; i < totalFeature; i++) {
					w[1][i] = w[1][i] + LR * (x[k][i] - w[1][i]);
				}
			}
		}

		// print nilai bobot baru
		for (int i = 0; i < totalFeature; i++) {
			for (int j = 0; j < totalClass; j++) {
				cout << "W[" << j << "]: " << w[j][i] << endl;
			}
			cout << endl;
		}

		LR = 0.5*LR; // update learning rate tiap iterasi
	}

	// running
	cout << "Input Features: ";
	for (int i = 0; i < totalFeature; i++) {
		cin >> x[0][i];
	}
	cout << endl;

	for (int j = 0; j < totalClass; j++) {
		D[j] = 0.0;
		for (int i = 0; i < totalFeature; i++) {
			D[j] = D[j] + sqrt((w[j][i] - x[0][i])*(w[j][i] - x[0][i]));
		}
		cout << "Distance[" << j << "]: " << D[j] << endl;
	}

	cout << endl;
	(D[0] < D[1]) ? cout << "Cluster 1" << endl : cout << "Cluster 2" << endl;
}

void tugas_praktikum(int maxEpoch) 
{
	const int totalClass = 2, totalData = 6, totalFeature = 2;
	double w[totalClass][totalFeature] = { // bobot awal
		{.5, .5},
		{.5, .5}
	};
	double x[totalData][totalFeature] = { // dataset
		{.1, .1},
		{.2, .2},
		{.3, .1},
		{.5, .3},
		{.4, .4},
		{.2, .4}
	};
	double D[totalClass]; // jarak bobot dengan nilai masukan
	double LR = 0.6;

	// training
	for (int l = 0; l < maxEpoch; l++) {
		// looping untuk setiap dataset
		for (int k = 0; k < totalData; k++) {
			// hitung jarak D untuk setiap bobot dan masukan vektor
			for (int j = 0; j < totalClass; j++) {
				D[j] = 0.0;
				for (int i = 0; i < totalFeature; i++) {
					D[j] = D[j] + (w[j][i] - x[k][i])*(w[j][i] - x[k][i]);
				}
			}
			// pembaruan nilai bobot untuk jarak minimum
			if (D[0] < D[1]) {
				for (int i = 0; i < totalFeature; i++) {
					w[0][i] = w[0][i] + LR * (x[k][i] - w[0][i]);
				}
			}
			else {
				for (int i = 0; i < totalFeature; i++) {
					w[1][i] = w[1][i] + LR * (x[k][i] - w[1][i]);
				}
			}
		}

		// print nilai bobot baru
		for (int i = 0; i < totalFeature; i++) {
			for (int j = 0; j < totalClass; j++) {
				cout << "W[" << j << "]: " << w[j][i] << endl;
			}
			cout << endl;
		}

		LR = 0.5*LR; // update learning rate tiap iterasi
	}

	// running
	cout << "Input Features: ";
	for (int i = 0; i < totalFeature; i++) {
		cin >> x[0][i];
	}
	cout << endl;

	for (int j = 0; j < totalClass; j++) {
		D[j] = 0.0;
		for (int i = 0; i < totalFeature; i++) {
			D[j] = D[j] + sqrt((w[j][i] - x[0][i])*(w[j][i] - x[0][i]));
		}
		cout << "Distance[" << j << "]: " << D[j] << endl;
	}

	cout << endl;
	(D[0] < D[1]) ? cout << "Cluster 1" << endl : cout << "Cluster 2" << endl;
}

int main() // Jaringan Kohonen
{
	for (;;) {
		cout << "===== Jaringan Kohonen =====" << endl;
		cout << "1. Percobaan Praktikum" << endl;
		cout << "2. Tugas Praktikum" << endl << endl;

		cout << "Pilih program: ";
		cin >> mode;

		// run program
		if (mode == 1) coba_praktikum(100);
		else if (mode == 2) tugas_praktikum(10);
		else break;

		cout << endl;
	}

	return 0;
}