#include <iostream>


using namespace std;



long long nwd_i(long long int a, long long int b) {
    if (a < 0) {
        a *= -1;
    }
    if (b < 0) {
        b *= -1;
    }

    if ( b== 0 || a==0 )
    {
        return 1;
    }

    long long int temp = 0;
    while (b > 0) {
        temp = a;
        a = b;
        b = temp % b;

    }
    return a;
}


long long nww(long long int a, long long int b) {
    long long int nwww = 0;

    if (a < 0) {
        a *= -1;
    }
    if (b < 0) {
        b *= -1;
    }


    if ( b== 0 || a==0 )
    {
        return 1;
    }


    nwww = (a * b) / nwd_i(a, b);
    return nwww;
}


short czy_trojkatna(long long int tab_tab[32][32], int dlg_kraw) {
    short czy_trojkatna = 1;

    // czy dolna

    short i_2 = 0; // i_2 to a_2
    short j_2 = 0; // j_2 to b_2

    while ((j_2 < dlg_kraw - 1) && (czy_trojkatna == 1)) {

        i_2 = j_2 + 1;
        while ((i_2 < dlg_kraw) && (czy_trojkatna == 1)) {

            if (tab_tab[i_2][j_2] != 0) {
                czy_trojkatna = 0;
            }

            i_2 += 1;
        }

        j_2 += 1;
    }

    if (czy_trojkatna == 1) {
        return 1;
    }

    // czy gorna

    czy_trojkatna = 1;

    i_2 = 0;
    j_2 = 0;

    while ((i_2 < dlg_kraw - 1) && (czy_trojkatna == 1)) {

        j_2 = i_2 + 1;
        while ((j_2 < dlg_kraw) && (czy_trojkatna == 1)) {

            if (tab_tab[i_2][j_2] != 0) {
                czy_trojkatna = 0;
            }

            j_2 += 1;
        }

        i_2 += 1;
    }

    if (czy_trojkatna == 1) {
        return 1;
    } else {
        return 0;
    }

}

long long int schodkowanie_trojkatnej(long long int tab_tab[32][32], int dlg_kraw) {
    long long int wyznacznik = 1;

    for (int i = 0; i < dlg_kraw; ++i) {

        wyznacznik = wyznacznik * tab_tab[i][i];

    }

    return wyznacznik;

}


long long int schodkowanie(long long int tab_tab[32][32], int dlg_kraw) {


    long long int temp_nww = 0;
    long long int temp_1 = 0;
    long long int temp_2 = 0;
    long long int temp_3 = 0;

    long long int dzielna_wyznacznika = 1;

    long long int diagonala = 1;


    long long int temp_swap = 0;
    short znak_wyznaccznika = 1;

    short czy_koniec_schodka_i = 0;
    short czy_koniec_schodkow_i = 0;

    short j = 0;
    short i = 0;
    short k = 0;


    int index_schodka = 0;
    int index_sprawdz_kolumne_czy_niezerowa=0;

    int i_indeks_kolumny = 0;
    int j_indeks_wiersza = 0;
    int k_indeks_wiersza = 0;

    // szczegolne przypadki macierzy 2 na 2 oraz trojkatna

//    if (dlg_kraw == 2) {
//        return wyznacznik_2_2(tab_tab, 0, 0);
//    } else if (czy_trojkatna(tab_tab, dlg_kraw) == 1) {
//        return schodkowanie_trojkatnej(tab_tab, dlg_kraw);
//    }


    while ((index_schodka < dlg_kraw - 1) && (czy_koniec_schodka_i != 1))
    {

        index_sprawdz_kolumne_czy_niezerowa = index_schodka;


        while ((tab_tab[index_schodka][index_sprawdz_kolumne_czy_niezerowa] == 0) && (index_sprawdz_kolumne_czy_niezerowa < dlg_kraw))
        {
            index_sprawdz_kolumne_czy_niezerowa += 1;

        }
        if (index_sprawdz_kolumne_czy_niezerowa == dlg_kraw)
        {
            czy_koniec_schodka_i = 1;
            czy_koniec_schodkow_i = 1;
        }

        if (index_sprawdz_kolumne_czy_niezerowa > index_schodka)
        {
            for (int kkk = 0; kkk < dlg_kraw; ++kkk)
            {

                temp_swap = tab_tab[index_schodka][kkk];
                tab_tab[index_schodka][kkk] = tab_tab[index_sprawdz_kolumne_czy_niezerowa][kkk];
                tab_tab[index_sprawdz_kolumne_czy_niezerowa][kkk] = temp_swap;
            }


            znak_wyznaccznika *= -1;
        }


        if (czy_koniec_schodka_i != 1)
        {

            k_indeks_wiersza = index_schodka + 1;


            while (k_indeks_wiersza < dlg_kraw)
            {
                if (tab_tab[k_indeks_wiersza][index_schodka] != 0)
                {

                    cout <<"  operacja zerowania wiersza  " <<endl;

                    temp_nww = nww(tab_tab[index_schodka][index_schodka], tab_tab[k_indeks_wiersza][index_schodka]);

                    temp_1 = temp_nww / tab_tab[index_schodka][index_schodka]; // przez co musisz pomnozyc zeby dostac nwww

                    temp_2 = temp_nww / tab_tab[k_indeks_wiersza][index_schodka];  // przez co musisz pomnozyc zeby dostac nwww

                    dzielna_wyznacznika *= temp_2;

                    for (int zzz = index_schodka; zzz < dlg_kraw; zzz++) {

                        temp_3 = tab_tab[index_schodka][zzz] * temp_1;

                        tab_tab[k_indeks_wiersza][zzz] = tab_tab[k_indeks_wiersza][zzz] * temp_2;

                        if ( tab_tab[k_indeks_wiersza][zzz] < 0 )
                        {
                            temp_3 *= -1;
                        }

                        tab_tab[k_indeks_wiersza][zzz] = tab_tab[k_indeks_wiersza][zzz] - temp_3;


                        cout <<endl;

                        for ( int tso1 = 0;tso1 < dlg_kraw ; ++tso1)
                        {
                            cout <<endl;
                            for ( int tso2 = 0; tso2 < dlg_kraw; ++tso2 )
                            {
                                cout << tab_tab[tso1][tso2]<<" ";
                            }

                        }
                        cout <<endl;

                    }
                    cout << " koniec kolumny "<<endl;



                    czy_koniec_schodkow_i = 1;
                }
                ++k_indeks_wiersza;
            }
        }
        index_schodka++;

    }

    if (czy_koniec_schodka_i != 1) {

        for (int zzzz = 0; zzzz < dlg_kraw; zzzz++) {
            diagonala *= tab_tab[zzzz][zzzz];

        }

        diagonala *= znak_wyznaccznika;

        if ( dzielna_wyznacznika != 0 )
        {
            diagonala = diagonala / dzielna_wyznacznika;
        }


    } else {
        diagonala = 0;
    }



    return diagonala;

}


short obcinanie_wektora(int tab_tab[2], int kraw_szesc) {
    short czy_wyszlo_poza = 0;
    int temp_swap = 0;


    if (tab_tab[0] > tab_tab[1]) {
        // skierowanie ( kierunek wektora ) // odwrotna strona
        temp_swap = tab_tab[0];
        tab_tab[0] = tab_tab[1];
        tab_tab[1] = temp_swap;

    }

    if (tab_tab[0] == tab_tab[1]) {
        if (tab_tab[0] < 0 || tab_tab[0] >= kraw_szesc) {
            czy_wyszlo_poza = 1;
        }

    } else {

        if (tab_tab[0] < 0 && tab_tab[1] >= kraw_szesc) {
            tab_tab[0] = 0;
            tab_tab[1] = kraw_szesc - 1;
        } else if ((tab_tab[0] < 0 && tab_tab[1] < 0) || ((tab_tab[0] >= kraw_szesc && tab_tab[1] >= kraw_szesc))) {
            czy_wyszlo_poza = 1;
        } else if (tab_tab[0] < 0 && tab_tab[1] >= 0 && tab_tab[1] < kraw_szesc) {
            tab_tab[0] = 0;
        } else if (tab_tab[0] >= 0 && tab_tab[0] < kraw_szesc && tab_tab[1] >= kraw_szesc) {
            tab_tab[1] = kraw_szesc - 1;
        }

    }


    return czy_wyszlo_poza;

}


short obcinanie_wektorow_all(int tab_wys[2], int tab_szer[2], int tab_glebokosc[2], int kraw_szesc) {
    // mozna robic kopie wszsys tkich tablic ale chyba nie trzeba ( do referencji )

    short czy_wyszlo_poza_tablice = 0;

    czy_wyszlo_poza_tablice = obcinanie_wektora(tab_wys, kraw_szesc);


    if (czy_wyszlo_poza_tablice != 1) {
        czy_wyszlo_poza_tablice = obcinanie_wektora(tab_szer, kraw_szesc);
    }
    if (czy_wyszlo_poza_tablice != 1) {
        czy_wyszlo_poza_tablice = obcinanie_wektora(tab_glebokosc, kraw_szesc);
    }


    return czy_wyszlo_poza_tablice;

}


short czy_wyszedl_wektor(int tab_tab[2], int kraw_szesc) {

    short czy_wyszlo_poza = 0;
    int temp_swap = 0;
    char ktory_kierunek = 'x';
    short czy_byl_swap_kierunku_wektora = 0;

    // skierowanie ( kierunek wektora ) // normalna strona
    if (tab_tab[0] > tab_tab[1]) {
        // skierowanie ( kierunek wektora ) // odwrotna strona
        temp_swap = tab_tab[0];
        tab_tab[0] = tab_tab[1];
        tab_tab[1] = temp_swap;
        czy_byl_swap_kierunku_wektora = 1;
    }

    if (tab_tab[0] == tab_tab[1]) {
        if (tab_tab[0] < 0 || tab_tab[0] >= kraw_szesc) {
            czy_wyszlo_poza = 1;
        }

    } else {

        if ((tab_tab[0] < 0 && tab_tab[1] < 0) || ((tab_tab[0] >= kraw_szesc && tab_tab[1] >= kraw_szesc))) {
            czy_wyszlo_poza = 1;
        }
    }
    return czy_wyszlo_poza;

}


short czy_wyszly_wektory_all(int tab_tab_1[2], int tab_tab_2[2], int tab_tab_3[2], int krawedz_szesc) {

    short czy_wyszly_wektory_all = 0;

    short x11 = czy_wyszedl_wektor(tab_tab_1, krawedz_szesc);
    short x22 = czy_wyszedl_wektor(tab_tab_2, krawedz_szesc);
    short x33 = czy_wyszedl_wektor(tab_tab_3, krawedz_szesc);

    czy_wyszly_wektory_all = x11 + x22 + x33;

    if (czy_wyszly_wektory_all == 0) {
        return czy_wyszly_wektory_all;
    } else {
        czy_wyszly_wektory_all = 1;
        return czy_wyszly_wektory_all;
    }

}


int main() {


    long long int testowy_wyznacznik[32][32] = {};


    testowy_wyznacznik[0][0] = 2;
    testowy_wyznacznik[0][1] = 1;
    testowy_wyznacznik[0][2] = 3;
    testowy_wyznacznik[0][3] = 2;

    testowy_wyznacznik[1][4] = 5;
    testowy_wyznacznik[1][5] = 3;
    testowy_wyznacznik[1][0] = 4;
    testowy_wyznacznik[1][1] = 3;

    testowy_wyznacznik[2][2] = 3;
    testowy_wyznacznik[2][3] = -4;
    testowy_wyznacznik[2][4] = 2;
    testowy_wyznacznik[2][5] = 6;

    testowy_wyznacznik[3][2] = 4;
    testowy_wyznacznik[3][3] = 5;
    testowy_wyznacznik[3][4] = 2;
    testowy_wyznacznik[3][5] = -4;

    cout << endl;
    cout<< "wartosc wyznacnzika  :   "<< schodkowanie(testowy_wyznacznik,4) <<endl;
    cout << endl;


    testowy_wyznacznik[0][0] = 3;
    testowy_wyznacznik[0][1] = 0;
    testowy_wyznacznik[0][2] = 1;
    testowy_wyznacznik[0][3] = 2;

    testowy_wyznacznik[1][4] = 2;
    testowy_wyznacznik[1][5] = 4;
    testowy_wyznacznik[1][0] = 2;
    testowy_wyznacznik[1][1] = 1;

    testowy_wyznacznik[2][2] = 0;
    testowy_wyznacznik[2][3] = -2;
    testowy_wyznacznik[2][4] = 3;
    testowy_wyznacznik[2][5] = 0;

    testowy_wyznacznik[3][2] = 1;
    testowy_wyznacznik[3][3] = 4;
    testowy_wyznacznik[3][4] = -2;
    testowy_wyznacznik[3][5] = -1;

    cout << endl;
    cout<< "wartosc wyznacnzika  :   "<< schodkowanie(testowy_wyznacznik,4) <<endl;
    cout << endl;


    testowy_wyznacznik[0][0] = 0;
    testowy_wyznacznik[0][1] = 5;
    testowy_wyznacznik[0][2] = 3;
    testowy_wyznacznik[0][3] = 6;

    testowy_wyznacznik[1][4] = -2;
    testowy_wyznacznik[1][5] = -3;
    testowy_wyznacznik[1][0] = 0;
    testowy_wyznacznik[1][1] = 2;

    testowy_wyznacznik[2][2] = 4;
    testowy_wyznacznik[2][3] = 1;
    testowy_wyznacznik[2][4] = 2;
    testowy_wyznacznik[2][5] = 1;

    testowy_wyznacznik[3][2] = 3;
    testowy_wyznacznik[3][3] = -2;
    testowy_wyznacznik[3][4] = 0;
    testowy_wyznacznik[3][5] = 2;

    cout << endl;
    cout<< "wartosc wyznacnzika  :   "<< schodkowanie(testowy_wyznacznik,4) <<endl;
    cout << endl;



    testowy_wyznacznik[0][0] = 2;
    testowy_wyznacznik[0][1] = -3;
    testowy_wyznacznik[0][2] = 4;
    testowy_wyznacznik[0][3] = 0;

    testowy_wyznacznik[1][4] = 5;
    testowy_wyznacznik[1][5] = -2;
    testowy_wyznacznik[1][0] = 3;
    testowy_wyznacznik[1][1] = 2;

    testowy_wyznacznik[2][2] = 6;
    testowy_wyznacznik[2][3] = 3;
    testowy_wyznacznik[2][4] = 0;
    testowy_wyznacznik[2][5] = 0;

    testowy_wyznacznik[3][2] = -5;
    testowy_wyznacznik[3][3] = 4;
    testowy_wyznacznik[3][4] = -6;
    testowy_wyznacznik[3][5] = 3;

    cout << endl;
    cout<< "wartosc wyznacnzika  :   "<< schodkowanie(testowy_wyznacznik,4) <<endl;
    cout << endl;



    testowy_wyznacznik[0][0] = 4;
    testowy_wyznacznik[0][1] = 2;
    testowy_wyznacznik[0][2] = -3;
    testowy_wyznacznik[0][3] = 0;

    testowy_wyznacznik[1][4] = 3;
    testowy_wyznacznik[1][5] = 0;
    testowy_wyznacznik[1][0] = 1;
    testowy_wyznacznik[1][1] = 3;

    testowy_wyznacznik[2][2] = 1;
    testowy_wyznacznik[2][3] = 0;
    testowy_wyznacznik[2][4] = -5;
    testowy_wyznacznik[2][5] = -3;

    testowy_wyznacznik[3][2] = -2;
    testowy_wyznacznik[3][3] = 4;
    testowy_wyznacznik[3][4] = 6;
    testowy_wyznacznik[3][5] = 0;

    cout << endl;
    cout<< "wartosc wyznacnzika  :   "<< schodkowanie(testowy_wyznacznik,4) <<endl;
    cout << endl;


    testowy_wyznacznik[0][0] = 4;
    testowy_wyznacznik[0][1] = 2;
    testowy_wyznacznik[0][2] = 3;
    testowy_wyznacznik[0][3] = 7;

    testowy_wyznacznik[1][4] = -6;
    testowy_wyznacznik[1][5] = -3;
    testowy_wyznacznik[1][0] = 4;
    testowy_wyznacznik[1][1] = -2;

    testowy_wyznacznik[2][2] = 4;
    testowy_wyznacznik[2][3] = 5;
    testowy_wyznacznik[2][4] = 7;
    testowy_wyznacznik[2][5] = 8;

    testowy_wyznacznik[3][2] = 3;
    testowy_wyznacznik[3][3] = -5;
    testowy_wyznacznik[3][4] = 2;
    testowy_wyznacznik[3][5] = 9;

    cout << endl;
    cout<< "wartosc wyznacnzika  :   "<< schodkowanie(testowy_wyznacznik,4) <<endl;
    cout << endl;

    // ////////////////

//    testowy_wyznacznik[2][0] = 0;
//    testowy_wyznacznik[2][1] = 33;
//    testowy_wyznacznik[2][2] = 23;
//    testowy_wyznacznik[2][3] = 126;
//    testowy_wyznacznik[2][4] = 15;
//    testowy_wyznacznik[2][5] = 1;

    cout<< "        KONIEEEEEEEC    << ENDL;" <<endl;
//
//    testowy_wyznacznik[0][0] = 0;
//    testowy_wyznacznik[0][1] = 2;
//    testowy_wyznacznik[0][2] = 0;
//    testowy_wyznacznik[0][3] = 1;
//    testowy_wyznacznik[0][4] = 12;
//    testowy_wyznacznik[0][5] = 1;
//
//    testowy_wyznacznik[1][0] = 0;
//    testowy_wyznacznik[1][1] = 0;
//    testowy_wyznacznik[1][2] = 2;
//    testowy_wyznacznik[1][3] = 0;
//    testowy_wyznacznik[1][4] = 1;
//    testowy_wyznacznik[1][5] = 17;
//
//
//    testowy_wyznacznik[2][0] = 0;
//    testowy_wyznacznik[2][1] = 33;
//    testowy_wyznacznik[2][2] = 23;
//    testowy_wyznacznik[2][3] = 12;
//    testowy_wyznacznik[2][4] = 15;
//    testowy_wyznacznik[2][5] = 1;
//
//
//    testowy_wyznacznik[3][0] = 4;
//    testowy_wyznacznik[3][1] = 55;
//    testowy_wyznacznik[3][2] = 0;
//    testowy_wyznacznik[3][3] = 76;
//    testowy_wyznacznik[3][4] = 1;
//    testowy_wyznacznik[3][5] = 11;
//
//    testowy_wyznacznik[4][0] = 4;
//    testowy_wyznacznik[4][1] = 41;
//    testowy_wyznacznik[4][2] = 29;
//    testowy_wyznacznik[4][3] = 123;
//    testowy_wyznacznik[4][4] = 10;
//    testowy_wyznacznik[4][5] = 1;
//
//    testowy_wyznacznik[5][0] = 4;
//    testowy_wyznacznik[5][1] = 21;
//    testowy_wyznacznik[5][2] = 77;
//    testowy_wyznacznik[5][3] = 0;
//    testowy_wyznacznik[5][4] = 49;
//    testowy_wyznacznik[5][5] = 13;
//
//
//    cout << schodkowanie(testowy_wyznacznik, 6) << endl;


    return 0;
}