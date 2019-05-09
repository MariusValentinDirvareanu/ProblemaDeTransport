#include <iostream>
#include <fstream>

int min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}



int main() {
	int tablou[10][10] = { 0 }, i, j, linii, coloane;
	int tablouCopie[10][10] = { 0 }, x[10][10] = { 0 };
	int minim = 0;
	std::ifstream f("da.txt");
	std::cin >> linii >> coloane;
	// Citire matrice de inceput
	for (i = 0; i < linii; ++i) {
		for (j = 0; j < coloane; ++j) {
			f >> tablou[i][j];
		}
	}
	f.close();
	memcpy(&tablouCopie, &tablou, sizeof(tablou));

	// Afisare matrice
	for (i = 0; i < linii; ++i) {
		for (j = 0; j < coloane; ++j) {
			std::cout << tablou[i][j] << ' ';
		}
		std::cout << "\n";
	}
	i = 0;
	j = 0;
	while (i<linii && j<coloane) {
		minim = min(tablou[i][coloane - 1], tablou[linii - 1][j]);
		tablou[i][coloane - 1] -= minim;
		tablou[linii - 1][j] -= minim;
		if (tablou[i][coloane - 1] > 0) {
			j++;
		}
		else
		{
			i++;
		}
	}

	// Afisare matrice
	std::cout << "\n";
	for (i = 0; i < linii; ++i) {
		for (j = 0; j < coloane; ++j) {
			std::cout << tablou[i][j] << ' ';
		}
		std::cout << "\n";
	}

	return 0;
}