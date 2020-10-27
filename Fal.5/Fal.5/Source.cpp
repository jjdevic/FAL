//Javier de Vicente Vazquez
//E72

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
vector<int> resolver(vector<int> const& v, int yIni, int yFin) {
    int aux = v[0];
    vector<int> vSol;

    for (int i = 0; i < v.size(); i++) {
        if (v[i] > aux) {
            aux = v[i];
            vSol.push_back(yIni + i);
        }
    }
    return vSol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    vector<int> v;
    vector<int> vSol;
    int yearIni, yearFin, aux2;
    
    cin >> yearIni;
    cin >> yearFin;
    int aux = yearFin - yearIni + 1;
    for (int i = 0; i < aux; i++) {
        cin >> aux2;
        v.push_back(aux2);
    }
    vSol = resolver(v, yearIni, yearFin);

    for (int i = 0; i < vSol.size(); i++) {
        cout << vSol[i] << " ";
    }
    cout << "\n";
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
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}