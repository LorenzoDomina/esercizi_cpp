#include <iostream>

using namespace std;

class Date
{
private:
    int dd;
    int mm;
    int yyyy;

public:
    // Costruttore di default
    Date()
    {
        dd = 1;
        mm = 1;
        yyyy = 1970;
    }

    // Costruttore con parametri
    Date(int day, int month, int year)
    {
        dd = day;
        mm = month;
        yyyy = year;
    }

    // Metodi getter
    int day() const { return dd; }
    int month() const { return mm; }
    int year() const { return yyyy; }

    // Operatore di output '<<'
    friend ostream &operator<<(ostream &os, const Date &date)
    {
        os << date.dd << "/" << date.mm << "/" << date.yyyy;
        return os;
    }

    // Operatore di confronto '=='
    friend bool operator==(const Date &one, const Date &other)
    {
        return (one.dd == other.dd && one.mm == other.mm && one.yyyy == other.yyyy);
    }

    // Metodo per aggiungere giorni
    void addDays(int num_d)
    {
        // Calcolo numero giorni nel mese corrente
        int giorniMese = getGiorniMese(mm, yyyy);

        dd += num_d;

        // Controllo incremento mese
        while (dd > giorniMese)
        {
            dd -= giorniMese;
            mm++;

            // Controllo incremento anno
            if (mm > 12)
            {
                mm = 1;
                yyyy++;
            }

            giorniMese = getGiorniMese(mm, yyyy);
        }
    }

    // Metodo per aggiungere mesi
    void addMonths(int num_m)
    {
        mm += num_m;

        // Controllo incremento anno
        while (mm > 12)
        {
            mm -= 12;
            yyyy++;
        }

        // Controllo lim numero giorni nel mese corrente
        int giorniMese = getGiorniMese(mm, yyyy);
        if (dd > giorniMese)
            dd = giorniMese;
    }

    // Metodo per aggiungere anni
    void addYears(int num_y)
    {
        yyyy += num_y;

        // Controllo lim numero giorni nel mese corrente
        int giorniMese = getGiorniMese(mm, yyyy);
        if (dd > giorniMese)
            dd = giorniMese;
    }

private:
    // Funzione per ottenere numero di giorni in un mese
    int getGiorniMese(int month, int year) const
    {
        static const int giorniMese[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        // Gestione anni bisestili
        if (month == 2 && (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)))
            return 29;

        return giorniMese[month - 1];
    }
};

int main()
{
    cout << "Data Customizzata 1: "
         << "20/06/2023" << endl;

    // Prove di funzionamento dei metodi addDays(), addMonths(), addYears()
    {
        Date dataCustom(20, 6, 2023);

        dataCustom.addDays(10);
        if (dataCustom.day() != 30)
        {
            cout << "[FAIL] addDays(10)" << endl;
        }
        else
        {
            cout << "[OK] addDays(10): " << dataCustom << endl;
        }
    }

    {
        Date dataCustom(20, 6, 2023);

        dataCustom.addMonths(2);
        if (dataCustom.month() != 8)
        {
            cout << "[FAIL] addMonths(2)" << endl;
        }
        else
        {
            cout << "[OK] addMonths(2): " << dataCustom << endl;
        }
    }

    {
        Date dataCustom(20, 6, 2023);

        dataCustom.addYears(-1);
        if (dataCustom.year() != 2022)
        {
            cout << "[FAIL] addYears(-1)" << endl
                 << endl;
        }
        else
        {
            cout << "[OK] addYears(-1): " << dataCustom << endl
                 << endl;
        }
    }

    {
        Date dataCustom2(28, 2, 2023);
        cout << "Data Customizzata 2: " << dataCustom2 << endl;

        dataCustom2.addDays(1);
        if (dataCustom2.day() != 1 || dataCustom2.month() != 3 || dataCustom2.year() != 2023)
        {
            cout << "[FAIL] addDays(1)" << endl
                 << endl;
        }
        else
        {
            cout << "[OK] addDays(1): " << dataCustom2 << endl
                 << endl;
        }
    }

    {
        Date dataCustom2(31, 1, 2023);
        cout << "Data Customizzata 3: " << dataCustom2 << endl;

        dataCustom2.addMonths(1);
        if (dataCustom2.day() != 28 || dataCustom2.month() != 2 || dataCustom2.year() != 2023)
        {
            cout << "[FAIL] addMonths(1)" << endl
                 << endl;
        }
        else
        {
            cout << "[OK] addMonths(1): " << dataCustom2 << endl
                 << endl;
        }
    }

    {
        Date dataCustom2(31, 8, 2023);
        cout << "Data Customizzata 4: " << dataCustom2 << endl;

        dataCustom2.addMonths(3);
        if (dataCustom2.day() != 30 || dataCustom2.month() != 11 || dataCustom2.year() != 2023)
        {
            cout << "[FAIL] addMonths(3)" << endl
                 << endl;
        }
        else
        {
            cout << "[OK] addMonths(3): " << dataCustom2 << endl
                 << endl;
        }
    }

    return 0;
}
