#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> v;
    int n;
    int choice;

    do
    {
        cout << "Vuoi inserire un numero? (1-si / 2-no): ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "inserisci un numero: ";
            cin >> n;
            v.push_back(n);
        }
    } while (choice == 1);

    if (!v.empty())
    {
        sort(v.begin(), v.end());

        int size = v.size();
        double median;

        if (size % 2 == 0)
        {
            median = static_cast<double>(v[size / 2 - 1] + v[size / 2]) / 2;
        }
        else
        {
            median = static_cast<double>(v[size / 2]);
        }

        cout << "La median dei numeri inseriti é " << median << endl;
    }
    else
    {
        cout << "Nessun valore inserito!" << endl;
    }

    return 0;
}
