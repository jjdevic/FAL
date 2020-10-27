//Javier de Vicente Vazquez
//E72

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;
using lli = long long int;

void resolver(std::vector<int> const& a, std::vector<lli>& v)
{
    lli aux = a[0];
    v.push_back(aux);
    for (int i = 1; i < a.size(); i++) {
        aux += a[i];
        v.push_back(aux);
    }
}

bool resuelveCaso() {
    int a1, a2;
    vector<int> a;
    vector<lli> v;
    std::cin >> a1 >> a2;

    if (a1 == 0 && a2 == 0) return false;
    int aux = a2 - a1 + 1, aux2;
    
    for (int i = 0; i < aux; i++) {
        cin >> aux2;
        a.push_back(aux2);
    }
    resolver(a, v);

    int m; std::cin >> m;
    for (int i = 0; i < m; ++i) {
        int f1, f2;
        std::cin >> f1 >> f2;
        if (f1 < a1 && f2 < a2 || f1 > a1 && f2 > a2 ) { //estoy fuera del intervalo totalmente
            cout << "0\n";
        }
        else{
            if (f1 < a1) f1 = a1;//estoy fuera por la izq
            if (f2 > a2) f2 = a2; //estoy fuera por la derecha
            int pos = f2 - a1;
            if (f1 - a1 == 0) cout << v[pos] << "\n";
            else {
            cout << v[pos] - v[f1-a1-1] << "\n";
            }
        }
    }
    std::cout << "---\n";
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


#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
