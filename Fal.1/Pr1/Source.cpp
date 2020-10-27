//Javier de Vicente Vazquez
//E72

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>


void resuelveCaso() {
	int n, mayor, cont = 0;
	std::cin >> n;
	mayor = n;
	
	while (n != 0) {
		if (n > mayor) {
			mayor = n;
			cont = 1;
		}
		else if (n == mayor) cont++;
		std::cin >> n;
	}
		std::cout << mayor << " " << cont << "\n";
}

int main() {
	// Para la entrada por fichero.
		// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i) resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}