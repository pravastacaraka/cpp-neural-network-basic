#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <time.h>

using namespace std;

const int POP_SIZE = 4;
const int SIZE = 5;

int individu[POP_SIZE][SIZE], individuBaru[POP_SIZE][SIZE];
int fitnessValue[POP_SIZE], totalFitness, bestFitness;
double percentValue[POP_SIZE];

// Inisialisasi gen random tiap individu
void init_population() 
{
    for (int i = 0; i < POP_SIZE; i++) // Jumlah individu 4
		for (int j = 0; j < SIZE; j++) // Panjang kromosom 5
			individu[i][j] = rand() % 2; // Random nilai gen 0 atau 1
}

// Perhitungan nilai fitness tiap individu
int fitness() 
{
	totalFitness = 0;
	cout << "-- Fitness --" << endl;

    for (int i = 0; i < POP_SIZE; i++)
	{
		fitnessValue[i] = 0;

		// Tampilkan nilai gen tiap individu
		cout << "Individu[" << i + 1 << "]: ";
		for (int j = 0; j < SIZE; j++) 
		{
			fitnessValue[i] += individu[i][j];
			cout << individu[i][j];
		}

		// Hitung nilai fitness tiap individu
		cout << " NF: " << fitnessValue[i] << endl;

		// Hitung nilai total fitness seluruh individu
		totalFitness += fitnessValue[i];

		// Cari nilai fitness maksimal
		if (bestFitness < fitnessValue[i]) bestFitness = fitnessValue[i];
    }

	cout << "Total Fitness: " << totalFitness << " | Best Fitness: " << bestFitness << endl;
	cout << endl;

	return bestFitness;
}

// Proses seleksi
void rouletteSelection() 
{
	int k = 0;
    double totalPercentFitness = 0.0;
	cout << "-- Seleksi Roulette --" << endl;

	// Hitung persentase dari nilai fitness tiap individu
    for (int i = 0; i < POP_SIZE; i++) 
	{
		percentValue[i] = (fitnessValue[i] * 100.0) / totalFitness;
		cout << "Individu[" << i + 1 << "]: " << percentValue[i] << " %" << endl;
		totalPercentFitness += percentValue[i];
    }
	cout << "Total Percent Fitness: " << totalPercentFitness << " %" << endl;

	// Acak proses seleksi individu berdasarkan nilai persentase
    for (int i = 0; i < POP_SIZE; i++) 
	{
		double areaPercent = 0;
		double random = rand() % 100;

		// Cari individu keberapa yang terpilih untuk disalin
		for (k = 0; k < POP_SIZE; k++) 
		{
			areaPercent += percentValue[k];
			if (random <= areaPercent) break;
		}

		for (int j = 0; j < SIZE; j++) individuBaru[i][j] = individu[k][j];
    }

	// Tampilkan nilai gen baru tiap individu
	for (int i = 0; i < POP_SIZE; i++) 
	{
		cout << "Individu baru[" << i + 1 << "]: ";
		for (int j = 0; j < SIZE; j++) 
		{
			individu[i][j] = individuBaru[i][j];
			cout << individu[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

// Proses cross over
void crossOver() 
{
	cout << "-- Cross Over --" << endl;

	/* Gen ditukar dengan pasangan,
	*  Individu 1 <-> 2
	*  Individu 3 <-> 4
	*/
    for (int i = 0; i < POP_SIZE; i += 2) 
	{
		// Acak index gen untuk melakukan pertukaran mulai dari mana
		int r = rand() % SIZE;
		cout << "Random: " << r << endl;

		/* Dengan data sebagai berikut  
		*  [1] = 00111
		*  [2] = 10101
		*  misalkan dengan index (r) = 2, maka
		*  [1] = 00 | 101
		*  [2] = 10 | 111
		*/
		for (int j = r; j < SIZE; j++) 
		{
			individuBaru[i][j] = individu[i+1][j];
			individuBaru[i+1][j] = individu[i][j];
		}
    }

	// Tampilkan nilai gen baru tiap individu
	for (int i = 0; i < POP_SIZE; i++)
	{
		cout << "Individu baru[" << i + 1 << "]: ";
		for (int j = 0; j < SIZE; j++)
		{
			individu[i][j] = individuBaru[i][j];
			cout << individu[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

// Proses mutasi
void mutasi() 
{
	cout << "-- Mutasi --" << endl;

	// Mutasi dilakukan pada individu 1 dan 3
    for (int i = 0; i < POP_SIZE; i += 2) 
	{
		// Acak index gen pada kromosom yang akan dimutasi
		int r = rand() % SIZE;
		cout << "Random: " << r << endl;

		/* Mutasikan gen dengan nilai sebaliknya
		*  misalkan dengan index (r) = 2,
		*  [1] = 01(0)11 -> 00(1)11
		*/
		if (individu[i][r] == 0) 
			individuBaru[i][r] = 1;
		else
			individuBaru[i][r] = 0;
    }

	// Tampilkan nilai gen baru tiap individu
	for (int i = 0; i < POP_SIZE; i++)
	{
		cout << "Individu baru[" << i + 1 << "]: ";
		for (int j = 0; j < SIZE; j++)
		{
			individu[i][j] = individuBaru[i][j];
			cout << individu[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

int main() // Algoritma Genetika 1
{
	int best;
	srand(time(NULL));
	init_population();

    for (int i = 0; i < 100; i++)
	{
		best = fitness();
		if (best == 5) break;
		rouletteSelection();
		crossOver();
		mutasi();
    }

	return 0;
}