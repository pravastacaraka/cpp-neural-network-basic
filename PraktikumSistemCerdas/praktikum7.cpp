#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <math.h>

using namespace std;

int mode;

void coba_praktikum(int maxEpoch)
{
	const int totalClass = 2, totalData = 10, totalFeature = 6;
	int x[totalData][totalFeature] = { // inisialisasi data set
		{ 1, 0, 0, 0, 1, 0 }, //1
		{ 0, 1, 1, 1, 1, 0 }, //2
		{ 0, 0, 1, 0, 0, 1 }, //1
		{ 0, 0, 1, 0, 1, 0 }, //1
		{ 0, 1, 0, 0, 0, 1 }, //1
		{ 1, 0, 1, 0, 1, 1 }, //1
		{ 0, 0, 1, 1, 0, 0 }, //2
		{ 0, 1, 0, 1, 0, 0 }, //2
		{ 1, 0, 0, 1, 0, 1 }, //2
		{ 0, 1, 1, 1, 1, 1 }  //2
	};
	int T[totalData] = { 1, 2, 1, 1, 1, 1, 2, 2, 2, 2 }; // target kelas
	float w[totalClass][totalFeature], D[totalClass], LR = 0.05f;

	// inisialisasi bobot
	for (int j = 0; j < totalClass; j++) {
		for (int i = 0; i < totalFeature; i++) {
			w[j][i] = x[j][i];
		}
	}

	// training
	cout << endl;
	for (int l = 0; l < maxEpoch; l++) {
		// looping untuk setiap dataset
		for (int k = 2; k < totalData; k++) {
			// hitung jarak D untuk setiap bobot dan masukan vektor
			for (int j = 0; j < totalClass; j++) {
				D[j] = 0.0;
				for (int i = 0; i < totalFeature; i++) { 
					// Rumus Dj = (Xi - Wij)^2
					D[j] += pow((x[k][i] - w[j][i]), 2);
				}
				D[j] = sqrt(D[j]);
				cout << "Distance[" << j << "]: " << D[j] << endl;
			}

			// pembaruan nilai bobot untuk jarak minimum
			if (D[0] <= D[1]) {
				cout << "Min. Distance = D[0]" << endl;
				if (T[k] == 1) { // Bila jarak minimum ke-1 == Kelas 1
					for (int i = 0; i < totalFeature; i++) {
						w[0][i] = w[0][i] + LR * (x[k][i] - w[0][i]);
						cout << "W[0][" << i << "]: " << w[0][i] << endl;
					}
				}
				else { // Bila jarak minimum ke-1 != Kelas 1
					for (int i = 0; i < totalFeature; i++) {
						w[0][i] = w[0][i] - LR * (x[k][i] - w[0][i]);
						cout << "W[0][" << i << "]: " << w[0][i] << endl;
					}
				}
			}
			else {
				cout << "Min. Distance = D[1]" << endl;
				if (T[k] == 2) { // Bila jarak minimum ke-2 == Kelas 2
					for (int i = 0; i < totalFeature; i++) {
						w[1][i] = w[1][i] + LR * (x[k][i] - w[1][i]);
						cout << "W[1][" << i << "]: " << w[1][i] << endl;
					}
				}
				else { // Bila jarak minimum ke-2 != Kelas 2
					for (int i = 0; i < totalFeature; i++) {
						w[1][i] = w[1][i] - LR * (x[k][i] - w[1][i]);
						cout << "W[1][" << i << "]: " << w[1][i] << endl;
					}
				}
			}
			cout << endl;
		}
		LR = LR - 0.1*LR; // update learning rate
	}

	// running
	cout << "Input Features: ";
	for (int i = 0; i < totalFeature; i++) {
		cin >> x[0][i];
	}
	cout << endl;

	// proses perhitungan dan pengklasifikasian
	for (int j = 0; j < totalClass; j++) {
		D[j] = 0.0;
		for (int i = 0; i < totalFeature; i++) {
			D[j] += pow((x[0][i] - w[j][i]), 2);
		}
		D[j] = sqrt(D[j]);
		cout << "Distance[" << j << "]: " << D[j] << endl;
	}
	cout << endl;

	(D[0] <= D[1]) ? cout << "Kelas 1" << endl : cout << "Kelas 2" << endl;
}

void tugas_praktikum(int maxEpoch)
{
	const int totalClass = 3, totalData = 15, totalFeature = 63;
	int x[totalData][totalFeature] = { // inisialisasi data set
		{ 1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1 }, // A1
		{ 0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,1,0,1,0,0,0,0,1,0,1,0,0,0,1,1,1,1,1,0,0,1,0,0,0,1,0,0,1,0,0,0,1,0,1,1,0,0,0,1,1,1,1,0,0,0,1,1 }, // A2
		{ 0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,1,0,1,0,0,0,1,0,0,0,1,0,0,1,0,0,0,1,0,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1 }, // A3
		{ 0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,1,0,0,0,1,0,1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1 }, // A4
		{ 0,0,0,1,0,0,0,0,1,1,0,1,1,0,0,1,0,0,0,1,0,0,1,0,0,0,1,0,0,1,1,1,1,1,0,1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1 }, // A5
		{ 1,1,1,1,1,0,0,1,0,0,0,0,1,0,1,0,0,0,0,0,1,1,0,0,0,0,1,0,1,1,1,1,1,0,0,1,0,0,0,0,1,0,1,0,0,0,0,0,1,1,0,0,0,0,1,0,1,1,1,1,1,0,0 }, // B1
		{ 1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,1,1,1,1,1,0,1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1 }, // B2
		{ 1,1,1,1,1,1,0,1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,1,0,1,1,1,1,1,0,0,1,0,0,0,0,1,0,1,0,0,0,0,0,1,1,1,1,1,1,1,0 }, // B3
		{ 1,1,1,1,1,1,0,1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1,0,1,1,1,1,1,0,1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1,0,1,1,1,1,1,0 }, // B4
		{ 1,1,1,1,1,1,0,1,0,0,0,0,0,1,1,0,0,0,0,1,0,1,1,1,1,1,0,0,1,0,0,0,0,1,0,1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,1,1,1,1,1,0 }, // B5
		{ 1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1 }, // H1
		{ 1,1,0,0,0,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,0,0,0,1,1,1,1,0,0,0,1,1,1,1,0,0,0,1,1,1,1,0,0,0,1,1 }, // H2
		{ 1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1 }, // H3
		{ 1,1,0,0,0,1,1,0,1,0,0,0,1,0,0,1,0,0,0,1,0,0,1,0,0,0,1,0,0,1,1,1,1,1,0,0,1,0,0,0,1,0,0,1,0,0,0,1,0,0,1,0,0,0,1,0,1,1,0,0,0,1,1 }, // H4
		{ 1,1,1,0,1,1,1,0,1,0,0,0,1,0,0,1,0,0,0,1,0,0,1,0,0,0,1,0,0,1,1,1,1,1,0,0,1,0,0,0,1,0,0,1,0,0,0,1,0,0,1,0,0,0,1,0,1,1,1,0,1,1,1 }  // H5
	};
	int T[totalData] = {
		1, 1, 1, 1, 1, // Kelas A
		2, 2, 2, 2, 2, // Kelas B
		3, 3, 3, 3, 3  // Kelas H
	}; // target kelas
	float w[totalClass][totalFeature], D[totalClass], LR = 0.05f;

	// inisialisasi bobot
	for (int i = 0; i < totalFeature; i++) {
		w[0][i] = x[0][i];
		w[1][i] = x[5][i];
		w[2][i] = x[10][i];
	}

	// training
	for (int l = 0; l < maxEpoch; l++) {
		// looping untuk setiap dataset
		for (int k = 0; k < totalData; k++) {
			// hitung jarak D untuk setiap bobot dan masukan vektor
			for (int j = 0; j < totalClass; j++) {
				D[j] = 0.0;
				for (int i = 0; i < totalFeature; i++) {
					// Rumus Dj = (Xi - Wij)^2
					D[j] += pow((x[k][i] - w[j][i]), 2);
				}
				D[j] = sqrt(D[j]);
				cout << "Distance[" << j << "]: " << D[j] << endl;
			}
			// pembaruan nilai bobot untuk jarak minimum
			if (D[0] <= D[1] && D[0] <= D[2]) {
				cout << "Min. Distance: D[0]" << endl;
				if (T[k] == 1) { // Bila jarak minimum ke-1 == Kelas 1
					for (int i = 0; i < totalFeature; i++) {
						w[0][i] = w[0][i] + LR * (x[k][i] - w[0][i]);
						cout << "W[0][" << i << "]: " << w[0][i] << endl;
					}
				}
				else { // Bila jarak minimum ke-1 != Kelas 1
					for (int i = 0; i < totalFeature; i++) {
						w[0][i] = w[0][i] - LR * (x[k][i] - w[0][i]);
						cout << "W[0][" << i << "]: " << w[0][i] << endl;
					}
				}
			}
			else if (D[1] <= D[0] && D[1] <= D[2]) {
				cout << "Min. Distance: D[1]" << endl;
				if (T[k] == 2) { // Bila jarak minimum ke-2 == Kelas 2
					for (int i = 0; i < totalFeature; i++) {
						w[1][i] = w[1][i] + LR * (x[k][i] - w[1][i]);
						cout << "W[1][" << i << "]: " << w[1][i] << endl;
					}
				}
				else { // Bila jarak minimum ke-2 != Kelas 2
					for (int i = 0; i < totalFeature; i++) {
						w[1][i] = w[1][i] - LR * (x[k][i] - w[1][i]);
						cout << "W[1][" << i << "]: " << w[1][i] << endl;
					}
				}
			}
			else {
				cout << "Min. Distance: D[2]" << endl;
				if (T[k] == 3) {  // Bila jarak minimum ke-3 == Kelas 3
					for (int i = 0; i < totalFeature; i++) {
						w[1][i] = w[2][i] + LR * (x[k][i] - w[2][i]);
						cout << "W[2][" << i << "]: " << w[2][i] << endl;
					}
				}
				else { // Bila jarak minimum ke-3 != Kelas 3
					for (int i = 0; i < totalFeature; i++) {
						w[2][i] = w[2][i] - LR * (x[k][i] - w[2][i]);
						cout << "W[2][" << i << "]: " << w[2][i] << endl;
					}
				}
			}
			cout << endl;
		}
		LR = LR - 0.1*LR; // update learning rate
	}

	// running
	cout << "Input Features: ";
	for (int i = 0; i < totalFeature; i++) {
		cin >> x[0][i];
	}
	cout << endl;

	// proses perhitungan dan pengklasifikasian
	for (int j = 0; j < totalClass; j++) {
		D[j] = 0.0;
		for (int i = 0; i < totalFeature; i++) {
			// Rumus Dj = (Xi - Wij)^2
			D[j] += pow((x[0][i] - w[j][i]), 2);
		}
		D[j] = sqrt(D[j]);
		cout << "Distance[" << j << "]: " << D[j] << endl;
	}
	cout << endl;

	if (D[0] <= D[1] && D[0] <= D[2]) {
		cout << "Kelas A" << endl;
	}
	else if (D[1] <= D[0] && D[1] <= D[2]) {
		cout << "Kelas B" << endl;
	}
	else {
		cout << "Kelas H" << endl;
	}

	//Huruf A
	//0 0 0 1 0 0 0 0 0 1 0 1 0 0 0 1 0 0 0 1 0 0 1 0 0 0 1 0 0 1 1 1 1 1 0 0 1 1 1 1 1 0 0 1 0 0 0 1 0 1 1 0 0 0 1 1 1 1 0 0 0 1 1

	//Huruf B
	//1 0 1 1 1 0 0 1 1 0 0 0 1 0 1 0 0 0 0 0 1 1 0 0 0 0 1 0 1 1 1 1 1 0 0 1 0 0 0 0 1 0 1 0 0 0 0 0 1 1 1 0 0 0 0 1 1 0 1 1 1 1 0

	//Huruf H
	//1 1 0 0 0 1 1 1 1 0 0 0 1 1 1 1 0 0 0 1 1 1 1 0 0 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 1 1 1 1 0 0 0 1 1 1 1 0 0 0 1 1
}

void main() // Learning Vector Quantization (LVQ)
{
	for (;;) {
		cout << "===== Learning Vector Quantization (LVQ) =====" << endl;
		cout << "1. Percobaan Praktikum" << endl;
		cout << "2. Tugas Praktikum" << endl << endl;

		cout << "Pilih program: ";
		cin >> mode;

		// run program
		if (mode == 1) coba_praktikum(10);
		else if (mode == 2) tugas_praktikum(10);
		else break;

		cout << endl;
	}
}