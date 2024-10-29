#include <iostream>
#include <bitset>
#include <string>
#include <iomanip>

//    cout.setf()
//    cout.setf()
//    cout.setf()

// CONST MUSISZ PRZEKAZAC DO FUNKCJI NP CONST SIZE_N_TAB = 3 F ( SIZE_N )

// type def cos  tam okresla typ
// typedef przypisuje alternatywna nazwe do instniejacych juz typow

 // bitset <rozmiar> ( ewentualnie string lub int )
 // 0B 010101010101 = int xxxxxyxyyxy;

 // setf bierze stara flage i cos tam
 // SET F I METODA UNSETF



using namespace std;


 // ios zamiast ios_base !! wazne
//typedef ios::fmtflags FFLAG;
// typedef ios::fmtflags flags;


//int funkcja_1(int x, int y )
//{
//
//
//    return  (x >= y) ?  x :  y;
//
//}

//
//void funkcja_2_bitset( bitset<4> bitt )
//{
//    int ile_bitow=0;
//    int ile_zer_2=0;
//    int ile_jedynek_2=0;
//    for (int i =0 ; i < 4;++i)
//    {
//        if (bitt[i] == '1')
//        {
//            ile_jedynek_2+=1;
//        }else if (bitt[i]=='0')
//        {
//            ile_zer_2+=1;
//        }else
//        {
//            ile_bitow+=1;
//        }
//
//    }
//
//    int n_bitset = bitt.size();
//    int ile_jedynek= bitt.count();
//    int ile_zer = n_bitset - ile_jedynek;
//
//    cout<< " w bitsecie jest : "<< ile_zer_2<<" zer" <<endl;
//
//}



int main()
{

//
//    int x = 0;
//    int y = 2;
//
//    int liczba = 20;
//
//    // if ( 0 <= liczba < 10 ) // 0 < liczba wynik to jeden ( bo prawda ) i drugi przedzial tez bedzie prawda //
//
// //    (x >= y) ? 1 :  0 ;
// //    cout<< 9*2. <<endl;
// //    cout<<funkcja_1(2,3)<<endl;
// //
//
//    // 0001 0000
//    // 0000 1111
//
//    //
//    //
//    //
//
//    string cos = "0001";
//    funkcja_2_bitset(bitset<4>cos );
//
//
//
//    if  ( x==0 | y/x >=0 )
//    {
//        cout<< " warunek prawdziwy "<<endl;
//    }


    int x_2 = 2;
    // string x = "00000001";
    bitset<8> bitt_1;
    // bitset<8> bitt_2 (x);
    bitset<8> bitt_3 (x_2);


    char ch_2 = '2';

    x_2<<=1;
    cout<<x_2<<endl;
    x_2<<=1;
    cout<<ch_2<<endl;
    x_2<<=1;
    cout<<x_2<<endl;

    cout<<endl;

//
//    ch_2<<=1;
//    cout<<ch_2<<endl;
//    ch_2<<=1;
//    cout<<ch_2<<endl;
//    ch_2<<=1;
//    cout<<ch_2<<endl;




    //cout.flags(cout.hex);




    cout << bitt_3 <<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    int bittttt = 0b0101;
    cout<< bittttt <<endl;
    bitset<8> bts1 ( 0b00101010 );
    bitset<8> bts2 ( 0b10101010 );
    bitset<8> btsw ( bts1^bts2 );
    cout<< btsw <<endl;



    cout<< " przerwa "<<endl;
    cout<< " przerwa "<<endl;
    cout<< " przerwa "<<endl;
    cout<< "                             "<<endl;

//
//    // konstruujemy flage stanu
//    ios::fmtflags n = ios::hex  | ios::showbase
//                                | ios::uppercase;
//            // ustawiamy nowa flage
//           // i zapamietujemy stara
//       ios::fmtflags o = cout.flags(n);
//       //
//        // ... korzystamy z nowych ustawien
//          cout.flags(o);  // przywracamy stara
//



//    int hexx = 0x165;
//    cout.flags() << hexx <<endl;



//
//
//
//    int    m =  49;
//    double x = 21.73;
//
//    cout << "1. m = " << m << ", x = " << x << endl;
//
//    FFLAG  newf = ios::hex | ios::showbase
//                  | ios::showpoint;
//    FFLAG  oldf = cout.flags(newf);
//    cout << "2. m = " << m << ", x = " << x << endl;
//
//    cout.setf(ios::scientific, ios::floatfield);
//    cout.unsetf(ios::showbase);
//    cout << "3. m = " << m << ", x = " << x << endl;
//
//    cout.setf(ios::fixed, ios::floatfield);
//    cout.setf(ios::showbase | ios::uppercase);
//    cout << "4. m = " << m << ", x = " << x << endl;
//
//    cout.flags(oldf);
//    cout << "5. m = " << m << ", x = " << x << endl;
//


    cout<< "                             "<<endl;
    cout<< " przerwa "<<endl;
    cout<< " przerwa "<<endl;
    cout<< " przerwa "<<endl;
    cout<< "                             "<<endl;




// Zapamietujemy aktualne ustawienie flag.
    std::ios::fmtflags flagi_obecnie = cout.flags();
    int int_to_print = 97;

// showbase - przedrostek 0x
    // cout.flags(cout.hex | cout.showbase | cout.width(10));
    cout << int_to_print << '\n';

// Powrot do pierwotnych ustawien.
    cout.flags(flagi_obecnie);

// Przy ponizszym zapisie tez zostaja ustawienia,
    cout << std::setw(10) << std::hex << std::showbase << int_to_print << '\n';


    cout<< "                             "<<endl;
    cout<< " przerwa "<<endl;
    cout<< " przerwa "<<endl;
    cout<< " przerwa "<<endl;
    cout<< "                             "<<endl;




    cout << "Ustawienie flagi wyswietlania hex." << '\n';
    cout.flags(cout.hex);
    cout << 0x2B << '\n';
    cout << "Ustawienie flagi wyswietlania oct." << '\n';
    cout.flags(cout.oct);
    cout << 045 << '\n';
    cout << "Nie ma flagi wyswietlania bin." << '\n';
    cout << std::bitset<4>(0b1001) << '\n';
// Ustawienie kilku jednoczesnie.
    cout << "Ustawienie kilku flag." << '\n';
    cout.flags(cout.scientific  | cout.right);
    cout << 3.103 << '\n';
// Obowiązują do zmiany.
    // cout.flags(cout.fixed | cout.precision(6) | cout.width(20));
    cout << 3.103 << '\n';


    cout<< "                             "<<endl;
    cout<< " przerwa "<<endl;
    cout<< " przerwa "<<endl;
    cout<< " przerwa "<<endl;
    cout<< "                             "<<endl;



    std::cout.flags(std::ios::left);
    std::cout.unsetf(std::ios::dec);
    std::ios::fmtflags flaggi = std::cout.flags();

    std::cout.flags(flaggi | std::ios::showpos);



    return 0;
}



