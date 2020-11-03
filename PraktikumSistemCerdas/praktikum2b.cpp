#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <time.h>

using namespace std;

double d_rand() 
{
	return(((double)rand() / RAND_MAX - 0.5) * 2.0);
}

int main()
{
	int output[10], error, jum;
	double w[10][8], tmp_output[10], learning_rate = 0.1, init = 0.15, error_total;

	int x[10][8] =
	{ // a b c d e f g 1
		{1,1,1,1,1,1,0,1}, //0
		{0,1,1,0,0,0,0,1}, //1
		{1,1,0,1,1,0,1,1}, //2 
		{1,1,1,1,0,0,1,1}, //3 
		{0,1,1,0,0,1,1,1}, //4
		{1,0,1,1,0,1,1,1}, //5
		{0,0,1,1,1,1,1,1}, //6
		{1,1,1,0,0,0,0,1}, //7
		{1,1,1,1,1,1,1,1}, //8
		{1,1,1,0,0,1,1,1}, //9
	};

	int target[10][10] =
	{
		{1,0,0,0,0,0,0,0,0,0}, //0
		{0,1,0,0,0,0,0,0,0,0}, //1
		{0,0,1,0,0,0,0,0,0,0}, //2
		{0,0,0,1,0,0,0,0,0,0}, //3
		{0,0,0,0,1,0,0,0,0,0}, //4
		{0,0,0,0,0,1,0,0,0,0}, //5
		{0,0,0,0,0,0,1,0,0,0}, //6
		{0,0,0,0,0,0,0,1,0,0}, //7
		{0,0,0,0,0,0,0,0,1,0}, //8
		{0,0,0,0,0,0,0,0,0,1}  //9
	};

	// Inisialisasi bobot
	srand(time(0));
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			w[i][j] = init * d_rand();
		}
	}

	// Training
	for (int k = 0; k < 100; k++)
	{
		for (int p = 0; p < 10; p++)
		{
			for (int i = 0; i < 10; i++)
			{
				tmp_output[i] = 0.0;
				for (int j = 0; j < 8; j++)
				{
					tmp_output[i] = tmp_output[i] + x[p][j] * w[i][j];
				}
				tmp_output[i] > 0.0 ? output[i] = 1 : output[i] = 0;

				error = target[p][i] - output[i];

				if (error != 0)
				{
					for (int j = 0; j < 8; j++)
					{
						w[i][j] = w[i][j] + learning_rate * error * x[p][j];
					}
				}
			}
		}
	}

	// Running
	for (;;)
	{
		for(int i = 0; i < 7; i++)
		{
			cout << "Input x[" << i << "]: ";
			cin >> x[0][i];
		}
		
		cout << endl;
		
		for(int i = 0; i < 10; i++)
		{
			tmp_output[i] = 0.0;
			for (int j = 0; j < 8; j++)
			{
				tmp_output[i] = tmp_output[i] + x[0][j] * w[i][j];
				tmp_output[i] > 0.0 ? output[i] = 1 : output[i] = 0;
			}
		}

		if ((output[0] == 1) && (output[1] == 0) && (output[2] == 0) && (output[3] == 0) && (output[4] == 0) && (output[5] == 0) && (output[6] == 0) && (output[7] == 0) && (output[8] == 0) && (output[9] == 0)) cout << "Output 0" << endl;
		else if ((output[0] == 0) && (output[1] == 1) && (output[2] == 0) && (output[3] == 0) && (output[4] == 0) && (output[5] == 0) && (output[6] == 0) && (output[7] == 0) && (output[8] == 0) && (output[9] == 0)) cout << "Output 1" << endl;
		else if ((output[0] == 0) && (output[1] == 0) && (output[2] == 1) && (output[3] == 0) && (output[4] == 0) && (output[5] == 0) && (output[6] == 0) && (output[7] == 0) && (output[8] == 0) && (output[9] == 0)) cout << "Output 2" << endl;
		else if ((output[0] == 0) && (output[1] == 0) && (output[2] == 0) && (output[3] == 1) && (output[4] == 0) && (output[5] == 0) && (output[6] == 0) && (output[7] == 0) && (output[8] == 0) && (output[9] == 0)) cout << "Output 3" << endl;
		else if ((output[0] == 0) && (output[1] == 0) && (output[2] == 0) && (output[3] == 0) && (output[4] == 1) && (output[5] == 0) && (output[6] == 0) && (output[7] == 0) && (output[8] == 0) && (output[9] == 0)) cout << "Output 4" << endl;
		else if ((output[0] == 0) && (output[1] == 0) && (output[2] == 0) && (output[3] == 0) && (output[4] == 0) && (output[5] == 1) && (output[6] == 0) && (output[7] == 0) && (output[8] == 0) && (output[9] == 0)) cout << "Output 5" << endl;
		else if ((output[0] == 0) && (output[1] == 0) && (output[2] == 0) && (output[3] == 0) && (output[4] == 0) && (output[5] == 0) && (output[6] == 1) && (output[7] == 0) && (output[8] == 0) && (output[9] == 0)) cout << "Output 6" << endl;
		else if ((output[0] == 0) && (output[1] == 0) && (output[2] == 0) && (output[3] == 0) && (output[4] == 0) && (output[5] == 0) && (output[6] == 0) && (output[7] == 1) && (output[8] == 0) && (output[9] == 0)) cout << "Output 7" << endl;
		else if ((output[0] == 0) && (output[1] == 0) && (output[2] == 0) && (output[3] == 0) && (output[4] == 0) && (output[5] == 0) && (output[6] == 0) && (output[7] == 0) && (output[8] == 1) && (output[9] == 0)) cout << "Output 8" << endl;
		else if ((output[0] == 0) && (output[1] == 0) && (output[2] == 0) && (output[3] == 0) && (output[4] == 0) && (output[5] == 0) && (output[6] == 0) && (output[7] == 0) && (output[8] == 0) && (output[9] == 1)) cout << "Output 9" << endl;
		else cout << "Input Salah!" << endl;
		cout << endl;
	}

	return 0;
}