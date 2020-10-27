// Javier de Vicente Vazquez
// E72


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;


//El coste del algoritomo es O(n) puesto que solo se una un bucle for de coste lineal.
//El algoritmo iterativo consiste en un bucle for que itera a lo largo del vector v y que en el caso de que el valor v[i] y v[i+1] sean 0, se guarda la posicion y se suma
//uno al contador previamente iniciado a 1 que representa los metros de valla.


// función que resuelve el problema
int resolver(vector<int>const& v, int mValla) {
    int pos = 0, mActual = 0,mMejor = 0;

    for (int i = 0; i < mValla; i++) {
        if (v[i] == 0) mActual++;
    }
    mMejor = mActual;
    for (int i = mValla; i < v.size(); i++) {
        if (v[i] == 0) mActual++;
        if (v[i - mValla] == 0) mActual--;
        if (mActual > 0 && mActual >= mMejor) {
            mMejor = mActual;
            pos = i - mValla + 1;
        }
    }
    if (mMejor == 0)return -1;
    return pos;
}

bool resuelveCaso() {
    int metros, mValla, aux;
    vector<int> v;

    cin >> metros;
    if (metros == 0) return false;
    else {
        cin >> mValla;
        for (int i = 0; i < metros; i++) {
            cin >> aux;
            v.push_back(aux);
        }
    }

    int sol = resolver(v, mValla);
    if (sol < 0) cout << "No hace falta\n";
    else cout << sol << "\n";
    
    return true;
}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 
    while (resuelveCaso());

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}