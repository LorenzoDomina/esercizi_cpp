#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool frequenzaParole(const pair<string, int> &a, const pair<string, int> &b)
{
    return a.second > b.second;
}

int main()
{
    string nomeFile = "/home/user/Documenti/esercizi/cpp/es1.3/canto1.txt";
    ifstream file(nomeFile);

    if (!file.is_open())
    {
        cout << "Impossibile aprire il file." << endl;
        return 1;
    }

    map<string, int> freqParole;

    string line;
    while (getline(file, line))
    {
        istringstream iss(line);
        string parola;
        while (iss >> parola)
        {
            if (parola.length() > 3)
            {
                freqParole[parola]++;
            }
        }
    }

    file.close();

    if (freqParole.empty())
    {
        cout << "Nessuna parola rilevata nel file." << endl;
        return 0;
    }

    vector<pair<string, int>> freqParoleVector(freqParole.begin(), freqParole.end());

    sort(freqParoleVector.begin(), freqParoleVector.end(), frequenzaParole);

    cout << "Le 10 parole più frequenti:" << endl;
    for (int i = 0; i < 10 && i < freqParoleVector.size(); i++)
    {
        cout << freqParoleVector[i].first << " - Frequenza: " << freqParoleVector[i].second << endl;
    }

    return 0;
}
