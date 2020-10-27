//Javier de Vicente Vazquez
//E72

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>

using namespace std;

bool resolver(const vector<int>& v, int p, int s) {
	int mayorP, menorP = 0;
	mayorP = v[0];
	for (int i = 0; i <= p; i++) {
		if (v[i] > mayorP) mayorP = v[i];
	}
	if (p + 1 < s) menorP = v[p + 1];
	else menorP = mayorP + 1;
	for (int j = (p + 1); j < s; j++) {
		if (v[j] <= menorP) menorP = v[j];
	}
	return mayorP < menorP;
}


void resuelveCaso() {
	// leer los datos de la entrada
	int size, p, cont = 0, aux;

	std::cin >> size;
	std::cin >> p;

	vector<int> v;
	while (cont < size) {
		std::cin >> aux;
		v.push_back(aux);
		cont++;
	}
	if (resolver(v, p, size)) std::cout << "SI\n";
	else std::cout << "NO\n";
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif 


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}