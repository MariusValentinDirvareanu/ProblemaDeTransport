#include <iostream>
#include <fstream>

// Calcul minim
int min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}

int linii, coloane, i, j;

// Afisare matrice
void print(int a[10][10]) {
	for (i = 0; i < linii; ++i) {
		for (j = 0; j < coloane; ++j) {
			std::cout << a[i][j] << ' ';
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

// Calcul cost total
void cost(int tablou[10][10], int x[10][10]) {
	int costTotal = 0;
	for (i = 0; i < linii; ++i) {
		for (j = 0; j < coloane; ++j) {
			costTotal += x[i][j] * tablou[i][j];
		}
	}
	std::cout << "Costul total este " << costTotal << " lei";
}


// Calcul metoda muchie NV
void NV(int a[10][10], int b[10][10]) {
	i = 0;
	j = 0;
	while (i < linii && j < coloane) {
		b[i][j] = min(a[i][coloane - 1], a[linii - 1][j]);
		a[i][coloane - 1] -= b[i][j];
		a[linii - 1][j] -= b[i][j];
		if (a[i][coloane - 1] > 0) {
			j++;
		}
		else
		{
			i++;
		}
	}
}


int main() {
	int tablou[10][10] = { 0 };
	int tablouCopie[10][10] = { 0 }, x[10][10] = { 0 };
	std::ifstream f("da.txt");
	std::cin >> linii >> coloane;

	// Citire matrice de inceput
	for (i = 0; i < linii; ++i) {
		for (j = 0; j < coloane; ++j) {
			f >> tablou[i][j];
		}
	}
	f.close();

	for (i = 0; i < linii; ++i) {
		for (j = 0; j < coloane; ++j) {
			tablouCopie[i + 1][j + 1] = tablou[i][j];
		}
	}

	print(tablou);


	NV(tablou, x);

	print(tablou);

	print(x);

	cost(tablou, x);

	return 0;
}