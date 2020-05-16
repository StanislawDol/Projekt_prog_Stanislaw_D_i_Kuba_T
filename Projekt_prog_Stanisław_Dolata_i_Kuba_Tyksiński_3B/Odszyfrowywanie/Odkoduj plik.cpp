#include<iostream>
#include<cstring>
#include<fstream>
#include<string>
using namespace std;
void a(string tekst)
{
    int pom, uskok, d;
    cout << "Wprowadz wartosc przesuniecia: " << endl;
    cin >> uskok;;
    cout << "----------------------------------" << endl;
    cout << "Wiadomosc po odkodowaniu: " << endl;
    uskok = uskok % 26;
    pom = tekst.size();
    char pom2;
    string pom3;
    ofstream zapis("plik_z_wynikami.txt");
    for (int i = 0; i < pom; i++)
    {
        pom2 = tekst.at(i);
        if (int(pom2) == 32)
        {
            pom3 = pom2;
            zapis << pom3;
            cout << pom3;
            continue;
        }
        if (int(pom2) >= 65 && int(pom2) <= 90 || int(pom2) >= 97 && int(pom2) <= 122)
        {
            if (int(pom2) >= 65 && int(pom2) <= 90)
            {
                pom2 -= 65;
                pom2 -= uskok;
                pom2 = (pom2 + 26) % 26;
                pom2 += 65;
            }
            if (int(pom2) >= 97 && int(pom2) <= 122)
            {
                pom2 -= 97;
                pom2 -= uskok;
                pom2 = (pom2 + 26) % 26;
                pom2 += 97;
            }
        }
        else
        {
            continue;
        }

        pom3 = pom2;
        zapis << pom3;
        cout << pom3;
    }
    zapis.close();
}
int main() {
    string tekst;
    ifstream plik;
    plik.open("wiadomosc.txt");
    getline(plik, tekst);
    cout << "Wiadomosc przed odkodowaniem: " << endl;
    cout << tekst << endl;
    cout << "----------------------------------" << endl;
    cout << "Odkodowanie szyfru Cezara dla liter duzych i malych" << endl;
    cout << "----------------------------------" << endl;
    a(tekst);
    plik.close();
    return 0;
}
