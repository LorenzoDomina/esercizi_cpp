#include <iostream>
#include <vector>

using namespace std;

struct Contact
{
    string nome;
    string cognome;
    string numTelefono;
};

class PhoneBook
{
private:
    vector<Contact> contatti;

public:
    void append(const Contact &contatto)
    {
        contatti.push_back(contatto);
    }

    Contact *find(const string &nome)
    {
        for (auto &contatto : contatti)
        {
            if (contatto.nome == nome)
            {
                return &contatto;
            }
        }
        return nullptr;
    }

    vector<Contact> filter(int scelta)
    {
        vector<Contact> rubricaFiltrata;

        switch (scelta)
        {
        case 1:
            char letteraIniziale;
            cout << endl
                 << "Inserire la lettera iniziale per cui applicare il filtro: ";
            cin >> letteraIniziale;

            for (const auto &contatto : contatti)
            {
                if (!contatto.nome.empty() && contatto.nome[0] == letteraIniziale)
                {
                    rubricaFiltrata.push_back(contatto);
                }
            }
            break;

        case 2:
            int numElementi;
            cout << endl
                 << "Inserisci il numero di elementi per il filtro: ";
            cin >> numElementi;

            int count = 0;
            for (const auto &contatto : contatti)
            {
                rubricaFiltrata.push_back(contatto);
                count++;
                if (count >= numElementi)
                {
                    break;
                }
            }
            break;
        }

        if (scelta < 1 || scelta > 2)
        {
            cout << "Scelta non valida." << endl;
        }

        return rubricaFiltrata;
    }

    friend ostream &operator<<(ostream &out, const PhoneBook &phoneBook)
    {
        for (const auto &contatto : phoneBook.contatti)
        {
            out << "Nome: " << contatto.nome << endl
                << "Cognome: " << contatto.cognome << endl
                << "Numero di Telefono: " << contatto.numTelefono << endl
                << "----------------------------------" << endl;
        }
        return out;
    }
};

int main()
{
    PhoneBook rubrica;

    int scelta;

    // Aggiungo contatti
    Contact newContatto;

    do
    {
        cout << endl
             << "Vuoi inserire un nuovo contatto? (1-si, 2-no): ";
        cin >> scelta;
        if (scelta == 1)
        {
            cout << "Nome: ";
            cin >> newContatto.nome;
            cout << "Cognome: ";
            cin >> newContatto.cognome;
            cout << "Numero di Telefono: ";
            cin >> newContatto.numTelefono;

            rubrica.append(newContatto);
        }

    } while (scelta == 1);

    // Ricerca contatto per nome
    string nomeCercato;

    cout << endl
         << "Quale contatto vuoi ricercare? (Inserisci il nome): ";
    cin >> nomeCercato;

    Contact *contattoTrovato = rubrica.find(nomeCercato);
    if (contattoTrovato != nullptr)
    {
        cout << "[OK] Contatto trovato: " << contattoTrovato->nome << " " << contattoTrovato->cognome << " - " << contattoTrovato->numTelefono << endl
             << endl;
    }
    else
    {
        cout << "[FAIL] Contatto non trovato." << endl
             << endl;
    }

    // menu scelta filtro
    cout << "Seleziona il tipo di filtro: " << endl;
    cout << "|1) Filtra per prima lettera del nome" << endl;
    cout << "|2) Filtra per numero di elementi" << endl;
    cout << "Scelta: ";
    cin >> scelta;

    vector<Contact> rubFiltrata = rubrica.filter(scelta);

    // Stampa rubrica filtrata
    cout << endl
         << "Rubrica Filtrata: " << endl;
    cout << "----------------------------------" << endl;
    for (const auto &contatto : rubFiltrata)
    {
        cout << contatto.nome << " " << contatto.cognome << " - " << contatto.numTelefono << endl;
    }

    // Stampa rubrica completa
    cout << endl
         << "Rubrica:" << endl;
    cout << "----------------------------------" << endl;
    cout << rubrica;

    return 0;
}
