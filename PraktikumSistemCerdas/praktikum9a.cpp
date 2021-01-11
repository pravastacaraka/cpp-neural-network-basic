#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;

/*	INFORMATION
 *
 *	== Input Membership Function ==
 *	Permintaan: Turun (<5000) | Naik (>1000)
 *	Persediaan: Sedikit (<600) | Banyak (>100)
 *
 *	== Output Membership Function ==
 *	Produksi: Berkurang (<7000) | Bertambah (>2000)
 */

float imfPermintaan(float a, float b, float z) 
{
	float resPermintaan;
	if ((z >= a) && (z < b)) resPermintaan = (b - z) / (b - a);
	if (z <= a) resPermintaan = 1;
	if (z >= b) resPermintaan = 0;
	return resPermintaan;
}

float imfPersediaan(float a, float b, float z) 
{
	float resPersediaan;
	if ((z >= a) && (z < b)) resPersediaan = (z - a) / (b - a);
	if (z <= a) resPersediaan = 0;
	if (z >= b) resPersediaan = 1;
	return resPersediaan;
}

float min(float a, float b) 
{
	float res;
	a < b ? res = a : res = b;
	return res;
}

void main() // Fuzzy Logic (Percobaan)
{
	float u1x, u2x, u1y, u2y;
	/*float minR1, minR2, minR3, minR4;
	float proR1, proR2, proR3, proR4;*/
	float num = 0, denum = 0, coaResult;
	vector <float> minVal;
	vector <float> proVal;

	float permintaan = 4000;
	float persediaan = 300;

	cout << " === PROGRAM FUZZY LOGIC ===" << endl << endl;
	cout << "Persoalan -> ";
	cout << "Permintaan: " << permintaan << " | Persediaan: " << persediaan << endl;
	cout << "Berapa jumlah produksi?" << endl << endl;

	// fuzzyfication
	cout << "Input Membership Function:" << endl;
	u1x = imfPermintaan(1000, 5000, permintaan);
	u2x = imfPersediaan(1000, 5000, permintaan);
	printf("Permintaan -> turun: %.2f | naik: %.2f\n", u1x, u2x);
	u1y = imfPermintaan(100, 600, persediaan);
	u2y = imfPersediaan(100, 600, persediaan);
	printf("Persediaan -> sedikit: %.2f | banyak: %.2f\n", u1y, u2y);
	cout << endl;

	// interference
	cout << "Interference System:" << endl;
	// rule 1: IF Permintaan TURUN And Persediaan BANYAK THEN Produksi Barang BERKURANG
	minVal.push_back(min(u1x, u2y));
	proVal.push_back(7000 - minVal[minVal.size()-1] * 5000);
	printf("Minimum Permintaan TURUN And Persediaan BANYAK: %.2f\n", minVal[minVal.size()-1]);
	printf("Produksi berkurang: %.0f\n", proVal[proVal.size()-1]);
	// rule 2: IF Permintaan TURUN And Persediaan SEDIKIT THEN Produksi Barang BERKURANG
	minVal.push_back(min(u1x, u1y));
	proVal.push_back(7000 - minVal[minVal.size()-1] * 5000);
	printf("Minimum Permintaan TURUN And Persediaan SEDIKIT: %.2f\n", minVal[minVal.size()-1]);
	printf("Produksi berkurang: %.0f\n", proVal[proVal.size()-1]);
	// rule 3: IF Permintaan NAIK And Persediaan BANYAK THEN Produksi Barang BERTAMBAH
	minVal.push_back(min(u2x, u2y));
	proVal.push_back(2000 + minVal[minVal.size()-1] * 5000);
	printf("Minimum Permintaan NAIK And Persediaan BANYAK: %.2f\n", minVal[minVal.size()-1]);
	printf("Produksi bertambah: %.0f\n", proVal[proVal.size()-1]);
	// rule 4: IF Permintaan NAIK And Persediaan SEDIKIT THEN Produksi Barang BERTAMBAH
	minVal.push_back(min(u2x, u1y));
	proVal.push_back(2000 + minVal[minVal.size()-1] * 5000);
	printf("Minimum Permintaan NAIK And Persediaan SEDIKIT: %.2f\n", minVal[minVal.size()-1]);
	printf("Produksi bertambah: %.0f\n", proVal[proVal.size()-1]);
	cout << endl;

	// defuzzyfication
	cout << "Output:" << endl;
	for (int i = 0; i < minVal.size(); i++) {
		num += minVal[i] * proVal[i];
		denum += minVal[i];
	}
	coaResult = num / denum;
	cout << "Jumlah produksi: " << coaResult << endl;
}