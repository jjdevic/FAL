// Javier de Vicente Vazquez
// E72

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>

using namespace std;

// Explicación del algoritmo utilizado
	// El alrgoritmo es secuencial en el que hay un unico bucle for que dura v.size en el cual se recorre el vector v y se comprueba mediandte una comparacion en cada ciclo si la el numero almacendo en la posicion del vector i es menor, mayor o igual que una variable "menor"
	// en la que hemos guardado el primer valor de v previamente. Cuando termina el bucle for se devuelve un entero en que se almacena el valor total de la suma y se pasa por referencia otra variable llamada cont en la que hemos guardado el numero de numeros que hemos sumado.

// Coste del algoritmo utilizado
	//O(n)

int resolver(vector<int> const& v, int &cont) {
	int suma = 0, menor, aux = v[0], aux2 = 1;
	menor = v[0];
	for (int i = 1; i < v.size(); ++i) {
		if (v[i] < menor) {
			suma += aux;
			cont += aux2;
			menor = v[i];
			aux = v[i];
			aux2 = 1;
		}
		else if (v[i] == menor) {
			aux += v[i];
			aux2++;
		}
		else {
			suma += v[i];
			cont++;
		}
	}
	return suma;
}

void resuelveCaso() {
	// Lectura de los datos
	int numElem, cont = 0;
	std::cin >> numElem;
	std::vector<int> v(numElem);
	for (int& i : v) std::cin >> i;

	int s = resolver(v, cont);

	std::cout << s << ' ' << cont << '\n';
}

int main() {
	// Para la entrada por fichero. Comentar para mandar a acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i) resuelveCaso();

	// Para restablecer entrada. Comentar para mandar a acepta el reto

#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}
