//Javier de Vicente Vazquez
//E72

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> resolver(vector<int>& s1, vector<int>& s2) {
    vector <int> sol;
    vector <int> :: iterator it;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    //set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), back_inserter(sol));

    int i = 0, j = 0;
    while (i < s1.size() && j < s2.size()) {
        if (s1[i] == s2[j]) {
            sol.push_back(s1[i]);
            i++;
            j++;
        }
        else {
            if (s1[i] > s2[j]) j++;
            else i++;
        }
    }
    return sol;
}

void resuelveCaso() {
    int aux;
    vector <int> s1;
    vector <int> s2;

    
    cin >> aux;
    while (aux != 0) {
        s1.push_back(aux);
        cin >> aux;
    }
    cin >> aux;
    while (aux != 0) {
        s2.push_back(aux);
        cin >> aux;
    }

    for (int i : resolver(s1, s2)) {
        printf("%d ", i);
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