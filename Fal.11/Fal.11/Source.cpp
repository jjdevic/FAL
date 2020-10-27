// Javier de Vicente Vazquez
// E72

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

//El coste del algoritmo es O(n) ya que es lineal puesto que solo se itera el vector una sola vez a traves de un bucle for, el algoritmo consiste en el bucle, y una serie de variables que almacenaran valores como la longitud actual, la maxima, y la posicion en el que estas empiezan
//finalmente lo que se hace es guardar la posicion inicial que es la posicion previamente almacenada menos la longitud maxima, y la final, que sera la incial mas la longitud maxima.

// La función recibe un vector con las alturas de los edificios, y la altura de la nave que realizará el rescate
// Devuelve las posiciones de inicio y fin del segmento máximo encontrado.

void resolver(std::vector<int> const& v, int alturaNave, int& posIni, int& posFin) {
    int lAct = 0, lMax = 0, pos = 0;
    
    for (int i = 0; i < v.size(); i++) {
        if (v[i] > alturaNave) {
            lAct++;
            if (lAct > lMax) {
                lMax = lAct;
                pos = i;
            }

        }
        else lAct = 0;
    }

    if (lMax < lAct) {
        lMax = lAct;
        pos = v.size() - 1;
    }
    posIni = pos - lMax + 1;
    posFin = pos;
}

// Funcion que lee de la entrada, 
// LLama a la función que resuelve el problema
// Escribe la salida
void resuelveCaso() {
    // Lectura de los datos de entrada
    int numElem, alturaNave;
    std::cin >> numElem >> alturaNave;
    std::vector<int> v(numElem);
    for (int& i : v) std::cin >> i;
    // LLamada a la función resolver
    int p, q;
    resolver(v, alturaNave, p, q);
    // Escribir el resultado
    std::cout << p << ' ' << q << "\n";
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