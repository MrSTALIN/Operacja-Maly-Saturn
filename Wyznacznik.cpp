#include <time.h>
#include <iostream>
#include <vector>

using namespace std;

class Wyznacznik
{
	
public:
	void wyswietl(int N);
	
};

void Wyznacznik::wyswietl(int N)
{
	vector<vector<double>> tab;
	time_t t;
	srand(static_cast<unsigned>(time(&t)));
	tab = new double[N];
	cout << "Wylosowana macierz" << endl << endl;
	for (int i = 0; i < N; i++) tab[i] = new double[N];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			tab[i][j] = rand() % 50;
			cout << tab[i][j] << " ";
			if (j == N - 1)cout << endl;
		}
	double det = 1.0;
	for (int k = 0; k < N - 1; k++)
	{
		for (int i = k + 1; i < N; i++)
			for (int j = N - 1; j >= k; j--)
				tab[i][j] = tab[i][j] - tab[i][k] * tab[k][j] / tab[k][k];
	}

	for (int i = 0; i < N; i++) det = det * tab[i][i];
	cout << endl << "DET =  " << det << endl;
	cout << "press ENTER....";

	for (int i = 0; i < N; i++) delete[] tab[i];
	delete tab;
}


int main()
{
	int N;
	
	cout << "Podaj rozmiar macierzy: ";
	cin >> N;

	Wyznacznik matrix;
	matrix.wyswietl(N);
	
	cin.sync();
	cin.get();
	system("cls");
	main();
}
