//Javier de Vicente Vazquez
//E72

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

//El coste del algoritomo es O(n), es decir es lineal, ya que solo iteramos una vez por el vector. El algoritmo consiste en un bucle for por el cual iteramos el vector v, si en v[i] hay un numero par lo que se hace es copiar el valor de esa posicion
//a la posicion par (inicialmente inicializada a 0) y se le anade uno a la variable par. Finalmente lo que se hace es hacer un resize al vector y listo.


// Esta función recibe un vector con los números de matricula de los alumnos
// Modifica el vector de entrada eliminando los valores impares
void resolver(std::vector<int>& v) {
    int par = 0;

    for (int i = 0; i < v.size(); i++) {
        if (v[i] % 2 == 0) {
            v[par] = v[i];
            par++;
        }
    }
    v.resize(par);
}

// Funcion que lee de la entrada, 
// LLama a la función que resuelve el problema
// Escribe la salida
bool resuelveCaso() {
    // Leer datos de entrada
    int numElem;
    std::cin >> numElem;
    if (numElem == -1) return false;
    std::vector<int> v(numElem);
    for (int i = 0; i < numElem; ++i) {
        std::cin >> v[i];
    }
    // LLamada a la función resolver
    resolver(v);
    // Escribir el vector resultado
    if (v.size() > 0) std::cout << v[0];
    for (int i = 1; i < v.size(); ++i)
        std::cout << ' ' << v[i];
    std::cout << '\n';
    return true;
}

int main() {
    // Para la entrada por fichero. Comentar para acepta el reto
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
