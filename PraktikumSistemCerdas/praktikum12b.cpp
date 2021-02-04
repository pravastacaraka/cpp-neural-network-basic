#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <time.h>

using namespace std;

const int POP_SIZE = 12;
const int SIZE = 6;

int individu[POP_SIZE][SIZE], individuBaru[POP_SIZE][SIZE];
int fitnessValue[POP_SIZE], totalFitness = 0, bestFitness = 0;
double percentValue[POP_SIZE];

int alphabet[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
int Target[SIZE] = {2,1,18,21,11,9}; // BASUKI -> Total fitness = 156

// Inisialisasi gen random tiap individu
void init_population()
{
	for (int i = 0; i < POP_SIZE; i++) // Jumlah individu 12
		for (int j = 0; j < SIZE; j++) // Panjang kromosom 6
			individu[i][j] = rand() % 26 + 1; // Random nilai gen
}

// Perhitungan nilai fitness tiap individu
int fitness()
{
	totalFitness = 0;
	cout << "-- Fitness --" << endl;

	for (int i = 0; i < POP_SIZE; i++)
	{
		fitnessValue[i] = 0;
		for (int j = 0; j < SIZE; j++)
		{
			fitnessValue[i] += abs(individu[i][j] - Target[j]); // Hitung nilai error
		}

		// Hitung nilai fitness per individu dan total fitness keseluruhan
		fitnessValue[i] = 26 * 6 - fitnessValue[i];
		totalFitness += fitnessValue[i];
	}

	// Cari nilai fitness maksimal
	bestFitness = 0;
	for (int i = 0; i < POP_SIZE; i++)
	{
		if (bestFitness < fitnessValue[i]) bestFitness = fitnessValue[i];
	}

	// Tampilkan nilai gen tiap individu
	for (int i = 0; i < POP_SIZE; i++) 
	{
		cout << "Individu[" << i + 1 << "]: ";
		for (int j = 0; j < SIZE; j++) 
		{
			cout << individu[i][j] << " ";
		}
		cout << "== ";
		for (int j = 0; j < SIZE; j++) 
		{
			printf("%c ", alphabet[individu[i][j] - 1]);
		}
		cout << "\tNF: " << fitnessValue[i] << endl;
	}

	cout << "Total Fitness: " << totalFitness << " | Best Fitness: " << bestFitness << endl;

	return bestFitness;
}

// Seleksi
void rouletteSelection()
{
	double totalPercentFitness = 0.0;
	int k = 0;

	// Hitung persentasi fitness tiap individu
	cout << endl;
	for (int i = 0; i < POP_SIZE; i++)
	{
		percentValue[i] = (fitnessValue[i] * 100.0) / totalFitness;
		cout << "Percent individu[" << i + 1 << "]: " << percentValue[i] << endl;
		totalPercentFitness += percentValue[i];
	}
	printf("Total Percent Fitness: %.2f\n\n", totalPercentFitness);

	// Cari persentasi daerahnya
	cout << "-- Seleksi Roulette --" << endl;
	for (int i = 0; i < POP_SIZE; i++)
	{
		double areaPercent = 0;
		double random = rand() % 100;

		// Cari individu keberapa yang terpilih berdasarkan persentasi area < random
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
			cout << individu[i][j] << " ";
		}
		cout << endl;
	}
}

// Pertukaran Gen
void crossOver()
{
	// Pertukaran nilai gen pada kedua individu yang terpilih
	cout << endl << "-- Pertukaran Gen --" << endl;
	for (int i = 0; i < POP_SIZE; i += 2)
	{
		int r = rand() % SIZE;
		for (int j = r; j < SIZE; j++)
		{
			individuBaru[i][j] = individu[i + 1][j];
			individuBaru[i + 1][j] = individu[i][j];
		}
	}

	// Tampilkan nilai gen baru tiap individu
	for (int i = 0; i < POP_SIZE; i++)
	{
		cout << "Individu baru[" << i + 1 << "]: ";
		for (int j = 0; j < SIZE; j++)
		{
			individu[i][j] = individuBaru[i][j];
			cout << individu[i][j] << " ";
		}
		cout << endl;
	}
}

// Mutasi
void mutasi() 
{
	cout << endl << "-- Mutasi --" << endl;
    for (int i = 0; i < POP_SIZE; i+=2) 
	{
      int r = rand() % SIZE;
	  individuBaru[i][r] = 26 - individu[i][r];
    }

	// Tampilkan nilai gen baru tiap individu
	for (int i = 0; i < POP_SIZE; i++)
	{
		cout << "Individu baru[" << i + 1 << "]: ";
		for (int j = 0; j < SIZE; j++)
		{
			individu[i][j] = individuBaru[i][j];
			cout << individu[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int main() // Algoritma Genetika 2 - Pencocokan Kata
{
	int best;
	srand(time(NULL));
	init_population();

	for (int i = 0; i < 1; i++) 
	{
		best = fitness();
		if (best == 156) break;
		rouletteSelection();
		crossOver();
		mutasi();
    }

	return 0;
}

