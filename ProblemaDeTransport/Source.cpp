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

struct Da {
	int val;
	int principala;
};

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
void cost(int tablou[10][10], Da x[10][10]) {
	int costTotal = 0;
	for (i = 0; i < linii; ++i) {
		for (j = 0; j < coloane; ++j) {
			costTotal += x[i][j].val * tablou[i][j];
		}
	}
	std::cout << "Costul total este " << costTotal << " lei";
}


// Calcul metoda muchie NV
void NV(int a[10][10], Da b[10][10]) {
	i = 0;
	j = 0;
	while (i < linii && j < coloane) {
		b[i][j].val = min(a[i][coloane - 1], a[linii - 1][j]);
		b[i][j].principala = 1;
		a[i][coloane - 1] -= b[i][j].val;
		a[linii - 1][j] -= b[i][j].val;
		if (a[i][coloane - 1] > 0) {
			j++;
		}
		else
		{
			i++;
		}
	}
}

void RezolvareSistem(int tablouCopie[10][10], Da x[10][10]) {
	bool ok = true;
	i = 1;
	while (i < linii) {
		for(j=0;j<coloane;++j) {
			if (x[i - 1][j].val != 0) {
				if (ok == false) {
					if (tablouCopie[0][j + 1] != 0) {
						tablouCopie[i][0] = tablouCopie[i][j + 1] - tablouCopie[0][j + 1];
						ok = true;
					}
				}
				else {
					tablouCopie[0][j + 1] = tablouCopie[i][j + 1] - tablouCopie[i][0];
				}
			}
		}
		i++;
		ok = false;
	}
}


int main() {
	int tablou[10][10] = { 0 };
	int tablouCopie[10][10] = { 0 };
	Da x[10][10];
	std::ifstream f("da.txt");
	std::cin >> linii >> coloane;


	for (i = 0; i < linii; ++i) {
		for (j = 0; j < coloane; ++j) {
			x[i][j].val = 0;
			x[i][j].principala = 0;
		}
	}

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

	std::cout << "Tablou\n";
	print(tablou);

	std::cout << "TablouCopie\n";
	print(tablouCopie);

	NV(tablou, x);

	std::cout << "Tablou\n";
	print(tablou);


	cost(tablou, x);
	
	RezolvareSistem(tablouCopie, x);


	std::cout << "\n";
	std::cout << "TablouCopie\n";
	print(tablouCopie);


	for (i = 0; i < linii-1; ++i) {
		for (j = 0; j < coloane-1; ++j) {
			if (x[i][j].principala == 0) {
				x[i][j].val = tablouCopie[0][j + 1] + tablouCopie[i + 1][0] - tablouCopie[i + 1][j + 1];
			}
		}
	}



	for (i = 0; i < linii-1; ++i) {
		for (j = 0; j < coloane-1; ++j) {
			std::cout << x[i][j].val << ' ';
		}
		std::cout << "\n";
	}
	std::cout << "\n";


	return 0;
}