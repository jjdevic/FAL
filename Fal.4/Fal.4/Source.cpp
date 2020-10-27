//Javier de Vicente Vazquez
//E72

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Explicación del algoritmo utilizado
	// La función resolver recibe los dos vectores previamente creados, posteriormente se inicia un bucle while en el que se comprueba que componente es menor o igual que la otra, la menor de las dos se carga en el vector solucion y se avanca una posicion en el vector que tenia
	// el menor de los dos numeros, en caso de ser iguales se carga en el vector solucion la del vector 1 de manera arbitraria (daria igual que de las dos guardar) Luego hay otros dos bucles while en caso de que un vector sea mayor que el otro en el que simplemente se guardan en el vector
	// solución el resto del componentes del mismo. 

// Coste del algoritmo utilizado
	//20n + 5


std::vector<int> resolver(std::vector<int>const& v1, std::vector<int>const& v2) {
	int i = 0, j = 0;
	int aux, aux2;
	vector<int> sol;

	while (i < v1.size() && j < v2.size()) {
		aux = v1[i]; 
		aux2 = v2[j];

		if (aux < aux2) {
			sol.push_back(aux);
			i++;
		}
		else if (aux > aux2) {
			sol.push_back(aux2);
			j++;
		}
		else {
			sol.push_back(aux);
			i++;
			j++;
		}
	}
	while (i < v1.size()) {
		aux = v1[i];
		sol.push_back(aux);
		i++;
	}
	while (j < v2.size()) {
		aux2 = v2[j];
		sol.push_back(aux2);
		j++;
	}
	return sol;
}


void resuelveCaso() {
	// Lectura de los datos de entrada
	int n1, n2;
	std::cin >> n1 >> n2;
	std::vector<int> v1(n1);
	std::vector<int> v2(n2);
	for (int& i : v1) std::cin >> i;
	for (int& j : v2) std::cin >> j;
	// LLamada a la función que resuelve el problema
	std::vector<int> sol = resolver(v1, v2);
	if (!sol.empty()) {
		std::cout << sol[0];
		for (int i = 1; i < sol.size(); ++i)
			std::cout << ' ' << sol[i];
	}
	std::cout << '\n';
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto

#ifndef DOMJUDGE
	std::ifstream in("04sample.in");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i) {
		resuelveCaso();
	}

	// Para restablecer entrada. Comentar para acepta el reto

#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}