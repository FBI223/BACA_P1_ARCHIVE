#include <iostream>
#include <vector>
#include <sstream>
using namespace std;


// podwojny wskaznik to musisz * * uzyc do wyluskania

//share pointer wiele wskanizkow wskazuje to samo

// smart pointer
// wskazniki zwalniaja za nas pamiec

//mozna zwracac swoj typ danych z funkcji !!!
//
//np struct
//...
// konstruktory sa zawsze tworzone
// konstruktor domyslny

//
//
//struct WpisBib {
//    // Pola:
//    vector<string> autorzy_m{"raz","dwa","trzy"}; // #include <vector>
//    string tytul_m="cos";
//    string czasopismo_m="cos";
//    unsigned short tom_m=0;
//    char numer_m{}; // typedef unsigned short wchar_t;
//    unsigned short rok_wydania_m=0;
//    string abstrakt_m="";
//
//
//    // Konstruktory:
//    WpisBib();
//    WpisBib(string autor, string tytul, string czasopismo, unsigned short tom,
//            wchar_t numer, unsigned short rok_wydania, string abstrakt = "brak");
//
//    // Metody:
//    std::string na_napis();
//
//
//    string na_napis() {
//        stringstream ss; // #include <sstream>
//        ss << "autorzy: ";
//        // vector na string:
//        for (size_t i = 0; i < autorzy_m.size(); ++i) {
//            if (i != 0)
//                ss << "; ";
//            ss << autorzy_m[i];
//        }
//        ss << "\ntytul: " << tytul_m << "\nczasopismo: " << czasopismo_m
//           << "\ntom: " << tom_m << "\nnumer: " << numer_m
//           << "\nrok_wydania: " << rok_wydania_m << "\nabstrakt: " << abstrakt_m << "\n";
//        return ss.str();
//    }
//};
//
//struct StrOdDo{
//    unsigned short str_od_m{};
//    unsigned short str_do_m{};
//};
//

struct samochod{
    char marka[20]; //elementy struktury
    char model[20];
    int rok_produkcji;
    double pojemnosc;
};



struct StrOdDo;

struct WpisBib
{
    // Pola:
    //vector<std::string> autorzy_m; // #include <vector>


    vector <std::string> autorzy_m ;
    string tytul_m;
    string czasopismo_m;
    unsigned short tom_m{};
    wchar_t numer_m{}; // typedef unsigned short wchar_t;

    StrOdDo* strony_m{};

    unsigned short rok_wydania_m{};
    string abstrakt_m;

    //Konstruktory:
    WpisBib();
    WpisBib(std::vector<std::string> autorzy, std::string tytul, std::string czasopismo
            , unsigned short tom, wchar_t numer, StrOdDo strony, unsigned short rok_wydania
            , std::string abstrakt = "brak");

    // Metody:
    string na_napis();
};

//mozna zrobic WpisBib :: StrOdDo
struct StrOdDo{
    unsigned short str_od_m{};
    unsigned short str_do_m{};

    StrOdDo();
    StrOdDo(unsigned short str_od, unsigned short str_do);

};

WpisBib::WpisBib(){};
WpisBib::WpisBib(std::vector<std::string> autorzy, std::string tytul, std::string czasopismo
, unsigned short tom, wchar_t numer, StrOdDo strony, unsigned short rok_wydania,std::string abstrakt){};
//std::string abstrakt = "brakk")

//WpisBib:: NA DOL

string na_napis()
{
    stringstream ss; // #include <sstream>
    ss << "autorzy: ";
    // vector na string:
    int size_t = autorzy_m.size()
    for (size_t i = 0; i < autorzy_m; ++i)
    {
        if (i != 0)
            ss << "; ";
        ss << tablica_autorzy_m[i];
    }
    ss << "\ntytul: " << tytul_m << "\nczasopismo: " << czasopismo_m
       << "\ntom: " << tom_m << "\nnumer: " << numer_m
       //<< "\nstrony: " << (*strony_m).str_od_m << " - " << (*strony_m).str_do_m  //
       << "\nstrony: " << strony_m->str_od_m << " - " << strony_m->str_do_m  //
       << "\nrok_wydania: " << rok_wydania_m << "\nabstrakt: " << abstrakt_m << "\n";
    return ss.str();
}

struct punkty{
    int x, y;
    char nazwa;
};







int main()
{
//    samochod peugeot = {"Peugeot","407",2013,2.7};



    StrOdDo costam2 = {10,20};

   WpisBib test1 = {};
   //test1.strony_m={1 , 20};

    // wpisbib nazwa_struktury = { kolejne dane strukyury}

//    int n;
//    cout<<"Podaj liczbę punktów do stworzenia: ";
//    cin>>n;

//    //dynamiczne przydzielenie pamięci na n elementów
//    punkty *tab = new punkty [n];

    //przypisanie wartosci punktów
//
//    for(int i=0;i<n;i++)
//    {
//        cout<<"Punkt "<<i+1<<":\n";
//        cout<<"x = ";
//        cin>>tab[i].x;
//        cout<<"y = ";
//        cin>>tab[i].y;
//        cout<<"nazwa = ";
//        cin>>tab[i].nazwa;
//    }
//    cout<<endl;

    //wypisanie punktów
//    for(int i=0;i<n;i++)
//    {
//        cout<<"Punkt "<<i+1<<":\n";
//        cout<<"x = "<<tab[i].x<<endl;
//        cout<<"y = "<<tab[i].y<<endl;
//        cout<<"nazwa = "<<tab[i].nazwa<<endl;
//    }
//
//
    WpisBib wpis_testowy_v1 = {  };

    cout<<endl;


    cout<<wpis_testowy_v1.strony_m<<endl;
    cout<<wpis_testowy_v1.rok_wydania_m<<endl;

    cout<<endl;




    cout<<endl;
    return 0;
}

