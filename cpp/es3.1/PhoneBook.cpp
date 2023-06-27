#include <iostream>
#include <vector>
#include <functional>
#include <sstream>
#include <string>

using namespace std;

struct Contact
{
    string nome;
    string cognome;
    string prefisso;
    string numTelefono;
};

class AbstractFilter
{
public:
    virtual bool accept(const Contact &contatto) const = 0;
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

    vector<Contact> filter(const AbstractFilter &filter)
    {
        vector<Contact> rubricaFiltrata;

        for (const auto &contatto : contatti)
        {
            if (filter.accept(contatto))
            {
                rubricaFiltrata.push_back(contatto);
            }
        }

        return rubricaFiltrata;
    }

    friend ostream &operator<<(ostream &out, const PhoneBook &phoneBook)
    {
        for (const auto &contatto : phoneBook.contatti)
        {
            out << "Nome: " << contatto.nome << endl
                << "Cognome: " << contatto.cognome << endl
                << "Numero di Telefono: " << contatto.prefisso << " " << contatto.numTelefono << endl
                << "----------------------------------" << endl;
        }
        return out;
    }
};

class FirstLetterFilter : public AbstractFilter
{
private:
    char letteraIniziale;

public:
    FirstLetterFilter(char lettera) : letteraIniziale(lettera) {}

    bool accept(const Contact &contatto) const override
    {
        return !contatto.nome.empty() && contatto.nome[0] == letteraIniziale;
    }
};

class ItalianPrefixFilter : public AbstractFilter
{
public:
    bool accept(const Contact &contatto) const override
    {
        return contatto.prefisso == "+39";
    }
};

int main()
{
    PhoneBook rubrica;

    int scelta;

    // Aggiungo contatti
    Contact newContatto;

    rubrica.append({"Lorenzo", "Domina", "+39", "1112222333"});
    rubrica.append({"Edoardo", "Gini", "+1", "2223333444"});
    rubrica.append({"Luca", "Ottaviano", "+1", "3334444555"});
    rubrica.append({"Gianni", "Valenti", "+39", "4445555666"});

    // Stampa rubrica completa
    cout << endl
         << "Rubrica:" << endl;
    cout << "----------------------------------" << endl;
    cout << rubrica;

    {
        // Ricerca contatto per nome
        string nomeCercato;

        cout << endl
             << "Quale contatto vuoi ricercare? (Inserisci il nome): ";
        cin >> nomeCercato;

        Contact *contattoTrovato = rubrica.find(nomeCercato);
        if (contattoTrovato != nullptr)
        {
            cout << "[OK] Contatto trovato: " << contattoTrovato->nome << " " << contattoTrovato->cognome << " - " << contattoTrovato->prefisso << " " << contattoTrovato->numTelefono << endl
                 << endl;
        }
        else
        {
            cout << "[FAIL] Contatto non trovato." << endl
                 << endl;
        }
    }

    vector<Contact> rubFiltrata;

    {
        cout << "***** Filtraggio Rubrica per la prima lettera del nome *****" << endl;
        char letteraIniziale;
        cout << endl
             << "Inserire la lettera iniziale per cui applicare il filtro: ";
        cin >> letteraIniziale;

        FirstLetterFilter filter(letteraIniziale);
        rubFiltrata = rubrica.filter(filter);

        // Stampa rubrica filtrata
        cout << endl
             << "Rubrica Filtrata: " << endl;
        cout << "----------------------------------" << endl;
        for (const auto &contatto : rubFiltrata)
        {
            cout << contatto.nome << " " << contatto.cognome << " - " << contatto.prefisso << " " << contatto.numTelefono << endl;
        }
    }

    {
        cout << endl
             << "***** Filtraggio Rubrica per prefisso +39 *****" << endl;
        ItalianPrefixFilter filter;
        rubFiltrata = rubrica.filter(filter);

        // Stampa rubrica filtrata
        cout << endl
             << "Rubrica Filtrata: " << endl;
        cout << "----------------------------------" << endl;
        for (const auto &contatto : rubFiltrata)
        {
            cout << contatto.nome << " " << contatto.cognome << " - " << contatto.prefisso << " " << contatto.numTelefono << endl;
        }
    }

    return 0;
}
