#include <bits/stdc++.h>
#include <windows.h>

using namespace std;

int k = 0;
int height, width;
int A[1500][1500];
int minL, minS = 0, minL_P, minS_P;

void allVariations(int i, bool P[]);
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	cout << "Кількість рядків: ";
	cin >> height;
	cout << "Кількість стовпців: ";
	cin >> width;  
	
	minL = height;
	cout << "Введіть таблицю покриттів:" << endl;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			cin >> A[i][j];
		}
		minS += A[i][width - 1];
	}
	
	bool P[height] = {0};
	allVariations(0, P);
	cout<< "1) S -> min: P" << minS_P << "; S = " << minS << endl;
	cout<< "2) l -> min: P" << minL_P << "; l = " << minL << endl;
}

void minValues(int l, int S)
{
	if(l < minL)
	{
		minL = l;
		minL_P = k;
	}
	if(S < minS)
	{
		minS = S;
		minS_P = k;
	}
}
bool isCoverage(bool P[])
{
	bool check;
	for (int i = 0; i < width - 1; i++)
	{
		check = 1;
		for(int j = 0; j < height; j++)
		{
			if (P[j] && A[j][i])
			{
				check = 0;
			}
		}
		if (check) break;
	}
	return !check;
	
}

void outputVariation(bool P[])
{
	int l = 0, S = 0;
	cout << 'P' << k << " = { ";
	for (int i = 0; i < height; i++)
	{
		if (P[i])
		{
			cout << 'A' << i + 1 << ' ';
			l++;
			S += A[i][width - 1];
		}
	}
	cout << '}';
	printf(" - покриття ( l = %d, S = %d) \n", l, S);
	minValues(l, S);
}

void allVariations(int i, bool P[])
{
	for (i; i < height; i++)
	{
		P[i] = 1;
		if(isCoverage(P))
		{
			k++;
			outputVariation(P);
		}
		else
		{
			allVariations(i + 1, P);
		}
		P[i] = 0;
	}
}
