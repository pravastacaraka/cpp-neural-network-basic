#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;

/*	INFORMATION
 *
 *	== Input Membership Function ==
 *	Jarak: Short (<6) | Medium (2-10) | Long (6-14) | Very Long (>10)
 *	Kecepatan: Low (<40) | Medium (20-60) | Hard (>60)
 *
 *	== Output Membership Function ==
 *	Sudut Rem: No Break (<24) | Soft (25-49) | Moderate (50-99) | Hard (>100)
 */

float imfDistance(float a, float b, float c, float z) 
{
	float resDistance;
	if ((z >= a) && (z <= b)) resDistance = (z - a) / (b - a);
	if ((z >= b) && (z <= c)) resDistance = -(z - c) / (c - b);
	if ((z <= a) || (z >= c)) resDistance = 0;
	return resDistance;
}

float imfSpeed(float a, float b, float c, float z) 
{
	float resSpeed;
	if ((z >= a) && (z <= b)) resSpeed = (z - a) / (b - a);
	if ((z >= b) && (z <= c)) resSpeed = -(z - c) / (c - b);
	if ((z <= a) || (z >= c)) resSpeed = 0;
	return resSpeed;
}

float min(float a, float b)
{
	float res;
	a < b ? res = a : res = b;
	return res;
}

void main() // Fuzzy Logic (Tugas)
{
	float u1x, u2x, u3x, u4x, u1y, u2y, u3y;
	float num = 0, denum = 0, coaResult;
	vector <float> minVal;
	vector <float> remVal;

	float distance = 12;
	float speed = 40;

	cout << " === PROGRAM FUZZY LOGIC ===" << endl << endl;
	cout << "Persoalan -> ";
	cout << "Jarak: " << distance << " | Kecepatan: " << speed << endl;
	cout << "Berapa sudut rem?" << endl << endl;

	// fuzzyfikasi
	cout << "Input Membership Function:" << endl;
	u1x = imfDistance(0, 2, 6, distance);
	u2x = imfDistance(2, 6, 10, distance);
	u3x = imfDistance(6, 10, 14, distance);
	u4x = imfDistance(10, 14, 100, distance);
	printf("Jarak -> short: %.2f | medium: %.2f | long: %.2f | very long: %.2f\n", u1x, u2x, u3x, u4x);
	u1y = imfSpeed(0, 20, 40, speed);
	u2y = imfSpeed(20, 40, 60, speed);
	u3y = imfSpeed(40, 60, 100, speed);
	printf("Kecepatan -> low: %.2f | medium: %.2f | high: %.2f\n", u1y, u2y, u3y);
	cout << endl;

	// interferensi
	cout << "Interference System:" << endl;
	// rule 1: IF Jarak SHORT && Kecepatan LOW THEN Sudut Rem MODERATE
	minVal.push_back(min(u1x, u1y));
	remVal.push_back(50);
	printf("Minimum jarak short And kecepatan low: %.2f\n", minVal[minVal.size()-1]);
	printf("Rem moderate: %.0f\n", remVal[remVal.size()-1]);
	// rule 2: IF Jarak SHORT && Kecepatan MEDIUM THEN Sudut Rem HARD
	minVal.push_back(min(u1x, u2y));
	remVal.push_back(100);
	printf("Minimum jarak short And kecepatan medium: %.2f\n", minVal[minVal.size()-1]);
	printf("Rem hard: %.0f\n", remVal[remVal.size()-1]);
	// rule 3: IF Jarak SHORT && Kecepatan HIGH THEN Sudut Rem HARD
	minVal.push_back(min(u1x, u3y));
	remVal.push_back(100);
	printf("Minimum jarak short And kecepatan high: %.2f\n", minVal[minVal.size()-1]);
	printf("Rem hard: %.0f\n", remVal[remVal.size()-1]);
	// rule 4: IF Jarak MEDIUM && Kecepatan LOW THEN Sudut Rem SOFT
	minVal.push_back(min(u2x, u1y));
	remVal.push_back(25);
	printf("Minimum jarak medium And kecepatan low: %.2f\n", minVal[minVal.size()-1]);
	printf("Rem soft: %.0f\n", remVal[remVal.size()-1]);
	// rule 5: IF Jarak MEDIUM && Kecepatan MEDIUM THEN Sudut Rem MODERATE
	minVal.push_back(min(u2x, u2y));
	remVal.push_back(50);
	printf("Minimum jarak medium And kecepatan medium: %.2f\n", minVal[minVal.size()-1]);
	printf("Rem moderate: %.0f\n", remVal[remVal.size()-1]);
	// rule 6: IF Jarak MEDIUM && Kecepatan HIGH THEN Sudut Rem HARD
	minVal.push_back(min(u2x, u3y));
	remVal.push_back(100);
	printf("Minimum jarak medium And kecepatan high: %.2f\n", minVal[minVal.size()-1]);
	printf("Rem hard: %.0f\n", remVal[remVal.size()-1]);
	// rule 7: IF Jarak LONG && Kecepatan LOW THEN Sudut Rem NO BREAK
	minVal.push_back(min(u3x, u1y));
	remVal.push_back(0);
	printf("Minimum jarak long And kecepatan low: %.2f\n", minVal[minVal.size()-1]);
	printf("Rem no break: %.0f\n", remVal[remVal.size()-1]);
	// rule 8: IF Jarak LONG && Kecepatan MEDIUM THEN Sudut Rem SOFT
	minVal.push_back(min(u3x, u2y));
	remVal.push_back(25);
	printf("Minimum jarak long And kecepatan medium: %.2f\n", minVal[minVal.size()-1]);
	printf("Rem soft: %.0f\n", remVal[remVal.size()-1]);
	// rule 9: IF Jarak LONG && Kecepatan HIGH THEN Sudut Rem MODERATE
	minVal.push_back(min(u3x, u3y));
	remVal.push_back(50);
	printf("Minimum jarak long And kecepatan high: %.2f\n", minVal[minVal.size()-1]);
	printf("Rem moderate: %.0f\n", remVal[remVal.size()-1]);
	// rule 10: IF Jarak VERY LONG && Kecepatan LOW THEN Sudut Rem NO BREAK
	minVal.push_back(min(u4x, u1y));
	remVal.push_back(0);
	printf("Minimum jarak very long And kecepatan low: %.2f\n", minVal[minVal.size()-1]);
	printf("Rem no break: %.0f\n", remVal[remVal.size()-1]);
	// rule 11: IF Jarak VERY LONG && Kecepatan MEDIUM THEN Sudut Rem NO BREAK
	minVal.push_back(min(u4x, u2y));
	remVal.push_back(0);
	printf("Minimum jarak very long And kecepatan medium: %.2f\n", minVal[minVal.size()-1]);
	printf("Rem no break: %.0f\n", remVal[remVal.size()-1]);
	// rule 12: IF Jarak VERY LONG && Kecepatan HIGH THEN Sudut Rem SOFT
	minVal.push_back(min(u4x, u3y));
	remVal.push_back(25);
	printf("Minimum jarak very long And kecepatan high: %.2f\n", minVal[minVal.size()-1]);
	printf("Rem soft: %.0f\n", remVal[remVal.size()-1]);
	cout << endl;

	// defuzzyfikasi
	cout << "Output:" << endl;
	for (int i = 0; i < minVal.size(); i++) {
		num += minVal[i] * remVal[i];
		denum += minVal[i];
	}
	coaResult = num / denum;
	cout << "Sudut Rem: " << coaResult << endl;
}