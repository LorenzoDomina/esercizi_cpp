#include <iostream>

using namespace std;

int main() {
    int n, max;
    int somma = 0;
    int cont = 0;

    cout << "Quanti numeri vuoi inserire: ";
    cin >> max;
    cout << endl;

    while (cont < max) {
        cout << "Inserisci il " << cont+1 <<"° numero: ";
        cin >> n;
        somma += n;
        cont++;
    }

    cout << endl;

    if (cont > 0) {
        double media = static_cast<double>(somma) / cont;

        cout << "La somma dei valori inseriti è: " << somma << endl;
        cout << "La media dei valori inseriti è: " << media << endl;
    } else {
        cout << "Nessun valore inserito." << endl;
    }

    cout << endl;

    return 0;
}
