#include <iostream>
#include <fstream>
#include <string>

using namespace std;


struct zestaw_danych{

    int integer=0;
    string stringi="";
    char charakter  = '\0' ;


    bool b1= false ;
    unsigned char ch1 = '\0';
    float f1 = 0;


    bool b2 = false ;
    unsigned char ch2 = '\0';
    float f2 = 0;

    bool b3 = false ;
    unsigned char ch3 = '\0';
    float f3 = 0;

    bool b4 = false ;
    unsigned char ch4 = '\0';
    float f4 = 0;

};


struct zestaw_danych_string{

    string l1 = "" ;
    string l2 = "" ;
    string l3 = "" ;
    string l4 = "" ;
    string l5 = "" ;
    string l6 = "" ;
    string l7 = "" ;

    int index_p = 0;
    int index_k = 0;


};


void szukaj_min_int( string file_str , int ile_zestawow_danych, string file_str_2 )
{


    fstream f1;
    f1.open("C:\\Users\\msztu\\CLionProjects\\untitled\\baca\\ostatnia stacja eliminacja\\f321.txt",ios::in);
    string linia ="";

    int dlg_pliku_f1=0;
    string linia_dlg="";


    while (getline(f1,linia_dlg))
    {
        dlg_pliku_f1 +=1;
    }


    f1.close();
    f1.open("C:\\Users\\msztu\\CLionProjects\\untitled\\baca\\ostatnia stacja eliminacja\\f123.txt",ios::in);

    ofstream f2;
    f2.open("C:\\Users\\msztu\\CLionProjects\\untitled\\baca\\ostatnia stacja eliminacja\\f321.txt",ios::out);

    string czy_pusty_s="";
    int numer_aktualnej_lini=0;
    short czy_koniec_pliku=0;
    zestaw_danych temp_zestaw;


    int najwieksza_licznosc_int = 0;
    int aktualna_licznosc_int = 0;
    int najwieksza_licznosc_int_ilosc_wystapien = 0 ;
    int aktualna_licznosc_int_ilosc_wystapien = 0 ;

    int pozycja_poczatek_maks = 0;
    int pozycja_koniec_maks = 0;

    int pozycja_poczatek_temp = 0;
    int pozycja_koniec_temp = 0;

    int wartosc_dodana_4_charow_maks = 0;
    int wartosc_dodana_4_charow_temp = 0;

    int temp_int = 0;
    string temp_string = "";
    char temp_char='\0';
    unsigned char temp_unsigned_char = '\0';
    bool temp_bool= false ;
    float temp_float= 0.0;

    int pozycja_przed_seek=0;
    int pozycja_po_seek=0;

    int czy_wczytany_poczatek=0;

    int czy_wczytana_p_linia = 0;
    int czy_przeskok = 0;



    int index_przed_cin_int = 0;
    int index_po_cin_int = 0 ;



    int index_glowny_i_1=0;
    int index_glowny_i_2=0;

    int index_struktury_maks_1=0;
    int index_struktury_maks_2=0;

    int index_count = 0;


    int integer_temp = 0;
    int integer_max = 0;


    for (int i = 0 ; i < ile_zestawow_danych - 1 ; i++)
    {
        index_count = -1  ;


        index_glowny_i_1=0;
        index_glowny_i_2=0;

        index_struktury_maks_1=0;
        index_struktury_maks_2=0;


        index_przed_cin_int = 0;
        index_po_cin_int = 0 ;

        ile_zestawow_danych = 2 ;

        for (int j = i + 1 ; j < ile_zestawow_danych ; j++)
        {

            index_przed_cin_int = 0;
            index_po_cin_int = 0 ;


            zestaw_danych_string zestaw_Danych_string_temp;
            string string_int_temp="";
            index_po_cin_int = f1.tellg() ;
            cout << index_po_cin_int << endl;



            int czy_juz_zaczety_index = 0;
            index_przed_cin_int = 0 ;
            while (f1 >> integer_temp )
            {


                cout << "flaga : " << endl;

                string_int_temp = to_string(integer_temp);
                zestaw_Danych_string_temp.l1 = string_int_temp ;

                getline(f1,linia);

                zestaw_Danych_string_temp.l2 = linia ;

                index_po_cin_int = f1.tellg() ;
                getline(f1,linia);
                zestaw_Danych_string_temp.l2 = linia ;
                index_po_cin_int = f1.tellg() ;

                getline(f1,linia);
                zestaw_Danych_string_temp.l2 = linia ;

                getline(f1,linia);
                zestaw_Danych_string_temp.l2 = linia ;

                getline(f1,linia);
                zestaw_Danych_string_temp.l2 = linia ;

                getline(f1,linia);
                zestaw_Danych_string_temp.l2 = linia ;


                index_po_cin_int = f1.tellg() ;
                cout<<"index po po : "  << index_po_cin_int << endl;
                getline(f1,linia) ;
                zestaw_Danych_string_temp.l2 = linia ;
                cout << endl ;


                zestaw_Danych_string_temp.index_k = index_po_cin_int ;

                cout <<endl << endl << endl;
                cout << "p: " <<zestaw_Danych_string_temp.index_p << endl;
                cout << "k : " <<zestaw_Danych_string_temp.index_k << endl;
                cout <<endl << endl << endl;



                // zestaw_Danych_string_temp.index_p = 0 ;



                if ( czy_juz_zaczety_index == 0 )
                {
                    index_przed_cin_int = f1.tellg() ;
                    zestaw_Danych_string_temp.index_p = f1.tellg() ;
                    cout << "przed przed " <<index_przed_cin_int  <<endl;
                    czy_juz_zaczety_index = 1 ;
                } else
                {

                    index_przed_cin_int = f1.tellg() ;
                    zestaw_Danych_string_temp.index_p = f1.tellg() ;

                }







                zestaw_Danych_string_temp.l1 = "" ;
                zestaw_Danych_string_temp.l2 = "" ;
                zestaw_Danych_string_temp.l3 = "" ;
                zestaw_Danych_string_temp.l4 = "" ;
                zestaw_Danych_string_temp.l5 = "" ;
                zestaw_Danych_string_temp.l6 = "" ;
                zestaw_Danych_string_temp.l7 = "" ;





                cout <<"przead :  " <<index_przed_cin_int  << endl;
                cout << " po  :  " << index_po_cin_int << endl;
                cout <<endl << endl << endl;

                cout <<endl << endl << endl;
                cout << "p: " <<zestaw_Danych_string_temp.index_p << endl;
                cout << "k : " <<zestaw_Danych_string_temp.index_k << endl;
                cout <<endl << endl << endl;



            }



        }


    }

    f1.close();


}


void SortCount ( string f1_s , string f2_s , string f3_s )
{


//    fstream f2;
//    f2.open(f2_s.c_str(),ios::trunc);
//    f2.close();


    fstream f1;
    f1.open("C:\\Users\\msztu\\CLionProjects\\untitled\\baca\\ostatnia stacja eliminacja\\f321.txt",ios::in);
    string linia ="";

    int dlg_pliku_f1=0;
    string linia_dlg="";
    while (getline(f1,linia_dlg))
    {
        dlg_pliku_f1 +=1;
        cout<<linia_dlg<<endl;
    }

    cout << "dlg pliku : " <<dlg_pliku_f1 << endl;

    f1.close();
    f1.open("C:\\Users\\msztu\\CLionProjects\\untitled\\baca\\ostatnia stacja eliminacja\\f321.txt",ios::in);

    string czy_pusty_s="";
    int numer_aktualnej_lini=0;
    short czy_koniec_pliku=0;
    int ile_zestawow_danych = 0;
    zestaw_danych temp_zestaw;


    int najwieksza_licznosc_int = 0;
    int aktualna_licznosc_int = 0;
    int najwieksza_licznosc_int_ilosc_wystapien = 0 ;
    int aktualna_licznosc_int_ilosc_wystapien = 0 ;

    int pozycja_poczatek_maks = 0;
    int pozycja_koniec_maks = 0;

    int pozycja_poczatek_temp = 0;
    int pozycja_koniec_temp = 0;

    int wartosc_dodana_4_charow_maks = 0;
    int wartosc_dodana_4_charow_temp = 0;

    int temp_int = 0;
    string temp_string = "";
    char temp_char='\0';
    unsigned char temp_unsigned_char = '\0';
    bool temp_bool= false ;
    float temp_float= 0.0;

    int pozycja_przed_seek=0;
    int pozycja_po_seek=0;

    int czy_wczytany_poczatek=0;

    int czy_wczytana_p_linia = 0;
    int czy_przeskok = 0;


    while ( czy_koniec_pliku == 0 )
    {

        if ( numer_aktualnej_lini % 7 == 0 )
        {


            //cout << "przed f1 >>    " <<linia << endl;


            pozycja_przed_seek = f1.tellg() ;

            if ( czy_wczytana_p_linia == 0 )
            {
                getline(f1,linia);
                czy_wczytana_p_linia = 1;
            } else
            {
                getline(f1,linia);
                getline(f1,linia);



                //getline(f1,linia);

            }


            pozycja_poczatek_temp =  f1.tellg() ;


            //f1 >> temp_int;
            pozycja_po_seek = f1.tellg() ;

            //f1.seekg(pozycja_przed_seek);

            //linia = to_string(temp_int);

            //cout << "LINIAAAAAA   " << linia <<"     pozycja nr linii "<<numer_aktualnej_lini <<  endl;

            if ( linia != "" )
            {

                temp_int = stoi(linia);
                temp_zestaw.integer = temp_int ;

                //cout << "temp zestaw integer   " << temp_int << endl;
            } else
            {

                linia = "" ;

                while ( linia == "" )
                {

                    for (int i = 0 ; i < 7 ; i++)
                    {
                        getline(f1, linia);
                        numer_aktualnej_lini += 1;
                        //cout << "kurcze  " << linia << endl;


                        if ( numer_aktualnej_lini >= (dlg_pliku_f1-1) )
                        {
                            czy_koniec_pliku = 1;
                            break;
                        }

                    }



                    if ( numer_aktualnej_lini >= (dlg_pliku_f1-1) )
                    {
                        czy_koniec_pliku = 1;
                        break;
                    }
                }

                if ( numer_aktualnej_lini < (dlg_pliku_f1-1) )
                {
                    temp_int = stoi(linia);
                    temp_zestaw.integer = temp_int;
                }

            }

        } else if ( numer_aktualnej_lini % 7 == 1 )
        {


            //getline(f1,linia) ;
            getline(f1,linia) ;
            temp_zestaw.stringi=linia;


        } else if ( numer_aktualnej_lini % 7 == 2 )
        {

            char kolejny_char = '0';
            int kolejny_int =0;


            getline(f1,linia);
            kolejny_char = linia[0];
            kolejny_int = kolejny_char;
            cout << kolejny_char << "  kolejny char  " <<endl;
            cout << kolejny_int <<"   kolejny int" <<endl;

            //f1 >> temp_char ;
            temp_zestaw.charakter = kolejny_char ;

            linia = "character ";

        } else if ( numer_aktualnej_lini % 7 == 3 )
        {
            f1 >> temp_zestaw.b1;
            f1 >> temp_zestaw.ch1;
            f1 >> temp_zestaw.f1 ;



            linia = "z1" ;
        } else if ( numer_aktualnej_lini % 7 == 4 )
        {

            f1 >> temp_zestaw.b2;
            f1 >> temp_zestaw.ch2;
            f1 >> temp_zestaw.f2 ;


            linia = "z2" ;
        } else if ( numer_aktualnej_lini % 7 == 5 )
        {
            f1 >> temp_zestaw.b3;
            f1 >> temp_zestaw.ch3;
            f1 >> temp_zestaw.f3 ;



            linia = "z3" ;
        }  else if ( numer_aktualnej_lini % 7 == 6 )
        {
            f1 >> temp_zestaw.b4;
            f1 >> temp_zestaw.ch4;
            f1 >> temp_zestaw.f4 ;

            linia = "z4" ;

            pozycja_koniec_temp = f1.tellg();

            wartosc_dodana_4_charow_temp = temp_zestaw.ch1 + temp_zestaw.ch2 + temp_zestaw.ch3 +temp_zestaw.ch4 ;

            cout << temp_zestaw.integer <<endl ;
            cout << temp_zestaw.stringi <<endl ;
            cout << temp_zestaw.charakter <<endl ;

            cout << " ----- " << endl;
            cout << " ----- " << endl;
            cout << temp_zestaw.b1 << endl;
            cout << temp_zestaw.b2 << endl;
            cout << temp_zestaw.b3 << endl;
            cout << temp_zestaw.b4 << endl;
            cout << " ----- " << endl;
            cout << temp_zestaw.ch1 << endl;
            cout << temp_zestaw.ch2 << endl;
            cout << temp_zestaw.ch3 << endl;
            cout << temp_zestaw.ch4 << endl;
            cout << " ----- " << endl;
            cout << temp_zestaw.f1 << endl;
            cout << temp_zestaw.f2 << endl;
            cout << temp_zestaw.f3 << endl;
            cout << temp_zestaw.f4 << endl;
            cout << " ----- " << endl;
            cout << " ----- " << endl;

        }



        if (  ( numer_aktualnej_lini % 7 == 0 ) && czy_koniec_pliku == 0 )
        {
            ile_zestawow_danych +=1;
        }



        cout<< "nr aktualnej liniii "  << numer_aktualnej_lini <<"     linia str " << linia  <<endl;



        if ( numer_aktualnej_lini == (dlg_pliku_f1 - 1 ) )
        {
            czy_koniec_pliku = 1;
        }



        if ( czy_koniec_pliku != 1 )
        {
            numer_aktualnej_lini+=1;
        }

        linia ="";

    }


    f1.close();

    cout << temp_zestaw.integer <<endl ;
    cout << temp_zestaw.stringi <<endl ;
    cout << temp_zestaw.charakter <<endl ;

    cout << " ----- " << endl;
    cout << " ----- " << endl;
    cout << temp_zestaw.b1 << endl;
    cout << temp_zestaw.b2 << endl;
    cout << temp_zestaw.b3 << endl;
    cout << temp_zestaw.b4 << endl;
    cout << " ----- " << endl;
    cout << temp_zestaw.ch1 << endl;
    cout << temp_zestaw.ch2 << endl;
    cout << temp_zestaw.ch3 << endl;
    cout << temp_zestaw.ch4 << endl;
    cout << " ----- " << endl;
    cout << temp_zestaw.f1 << endl;
    cout << temp_zestaw.f2 << endl;
    cout << temp_zestaw.f3 << endl;
    cout << temp_zestaw.f4 << endl;
    cout << " ----- " << endl;
    cout << " ----- " << endl;
}


void SortInt ( string f1_s , string f2_s , string f3_s )
{

    fstream f1;
    f1.open(f1_s.c_str(),ios::trunc);
    f1.close();


    fstream f2;
    f2.open(f2_s.c_str(),ios::trunc);
    f2.close();




}

void SortString ( string f1_s , string f2_s , string f3_s )
{



    fstream f1;
    f1.open(f1_s.c_str(),ios::trunc);
    f1.close();



    fstream f2;
    f2.open(f2_s.c_str(),ios::trunc);
    f2.close();




}

void SymmetricDifference (string f1_s, string f2_s, string f3_s )
{


    fstream f1;
    f1.open(f1_s.c_str(),ios::trunc);
    f1.close();



    fstream f2;
    f2.open(f2_s.c_str(),ios::trunc);
    f2.close();



    fstream f3;
    f3.open(f3_s.c_str(),ios::trunc);
    f3.close();





}


int main()
{

    string linia ;
    fstream f1;
    f1.open("C:\\Users\\msztu\\CLionProjects\\untitled\\baca\\ostatnia stacja eliminacja\\f123.txt",ios::in);
    f1.seekg(72);
    getline(f1,linia);
    cout<< "linia w mainie " <<linia << endl;
    f1.close() ;

    szukaj_min_int("123",2,"321");

    cout << "Hello, World!" << endl;

    return 0;
}


