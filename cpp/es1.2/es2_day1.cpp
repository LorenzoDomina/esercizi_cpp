#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> v;
    int n;
    int scelta;

    do
    {
        cout << "Vuoi inserire un numero? (1-si / 2-no): ";
        cin >> scelta;

        if (scelta == 1)
        {
            cout << "inserisci un numero: ";
            cin >> n;
            v.push_back(n);
        }
    } while (scelta == 1);

    if (!v.empty())
    {
        sort(v.begin(), v.end());

        int size = v.size();
        double mediana;

        if (size % 2 == 0)
        {
            mediana = static_cast<double>(v[size / 2 - 1] + v[size / 2]) / 2;
        }
        else
        {
            mediana = static_cast<double>(v[size / 2]);
        }

        cout << "La mediana dei numeri inseriti é " << mediana << endl;
    }
    else
    {
        cout << "Nessun valore inserito!" << endl;
    }

    return 0;
}
