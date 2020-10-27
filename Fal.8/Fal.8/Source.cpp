//Javier de Vicente Vazquez
//E72

#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <fstream>

using namespace std;

// Explicación del algoritmo utilizado

// Coste del algoritmo utilizado



// Recibe un vector con los datos de entrada del problema
// Debe contar el número de veces que aparece cada valor usando un vector auxiliar.
// Devuelve un vector con los valores que se repiten el número máximo de veces
// para que la función resuelveCaso solo tenga que escribirlos. 
// Si solo hay un valor que se repite el número máximo de veces el vector de salida
// tendrá solo ese valor 

std::vector<int> resolver(std::vector<int> const& v, int maximoValores) {
    vector<int> sol;
    vector<int> aux(maximoValores);
    int max = 0, x;

    for (int i = 0; i < v.size(); i++) {
        x = v[i] - 1;
        aux[x]++;
        if (aux[x] > max) max = aux[x];
    }

    for (int i = 0; i < aux.size(); i++) {
        if (aux[i] == max) {
            int y = i + 1;
            sol.push_back(y);
            max = aux[i];
        }
    }
    return sol;
}

// Entrada y salida de datos
bool resuelveCaso() {
    int numTiradas, valorMax;
    std::cin >> numTiradas >> valorMax;
    if (numTiradas == -1) return false;  // Entrada con centinela
    std::vector<int> v(numTiradas);
    vector<int> sol;
    for (int& i : v) std::cin >> i;

    sol = resolver(v, valorMax);
    for (int i = sol.size() - 1; i >= 0; i--) {
        cout << sol[i] << " ";
    }
    cout << "\n";
    return true;
}

int main() {
    // Para la entrada por fichero.
       // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
}