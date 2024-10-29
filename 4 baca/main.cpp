//Marcin Sztukowski

#include <iostream>

using namespace std;


long long int wyznacznik_2_2(long long int tab_tab[32][32], int wiersz_x_sr, int kolumna_y_sr) {
    long long int wartosc_wyznacznika = 0;

    wartosc_wyznacznika = (tab_tab[wiersz_x_sr][kolumna_y_sr] * tab_tab[wiersz_x_sr + 1][kolumna_y_sr + 1]) -
                          (tab_tab[wiersz_x_sr + 1][kolumna_y_sr] * tab_tab[wiersz_x_sr][kolumna_y_sr + 1]);

    return wartosc_wyznacznika;
}

long long int wyznacznik_3_3(long long int tab_tab[32][32], int wiersz_x_sr, int kolumna_y_sr) {
    long long int wartosc_wyznacznika = 0;


    wartosc_wyznacznika = ((tab_tab[wiersz_x_sr][kolumna_y_sr] * tab_tab[wiersz_x_sr + 1][kolumna_y_sr + 1] *
                            tab_tab[wiersz_x_sr + 2][kolumna_y_sr + 2]) +
                           (tab_tab[wiersz_x_sr + 1][kolumna_y_sr] * tab_tab[wiersz_x_sr + 2][kolumna_y_sr + 1] *
                            tab_tab[wiersz_x_sr][kolumna_y_sr + 2]) +
                           (tab_tab[wiersz_x_sr + 2][kolumna_y_sr] * tab_tab[wiersz_x_sr][kolumna_y_sr + 1] *
                            tab_tab[wiersz_x_sr + 1][kolumna_y_sr + 2])) -
                          ((tab_tab[wiersz_x_sr][kolumna_y_sr + 2] * tab_tab[wiersz_x_sr + 1][kolumna_y_sr + 1] *
                            tab_tab[wiersz_x_sr + 2][kolumna_y_sr + 0]) +
                           (tab_tab[wiersz_x_sr + 1][kolumna_y_sr + 2] * tab_tab[wiersz_x_sr + 2][kolumna_y_sr + 1] *
                            tab_tab[wiersz_x_sr][kolumna_y_sr]) +
                           (tab_tab[wiersz_x_sr + 2][kolumna_y_sr + 2] * tab_tab[wiersz_x_sr][kolumna_y_sr + 1] *
                            tab_tab[wiersz_x_sr + 1][kolumna_y_sr]));


    return wartosc_wyznacznika;
}


long long nwd_i(long long int a, long long int b) {
    if (a < 0) {
        a *= -1;
    }
    if (b < 0) {
        b *= -1;
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





    // szczegolne przypadki macierzy 2 na 2 oraz trojkatna

//    if (dlg_kraw == 2) {
//        return wyznacznik_2_2(tab_tab, 0, 0);
//    } else if (czy_trojkatna(tab_tab, dlg_kraw) == 1) {
//        return schodkowanie_trojkatnej(tab_tab, dlg_kraw);
//    }


    while ((i < dlg_kraw - 1) && (czy_koniec_schodka_i != 1)) {
        j = i;

        while ((tab_tab[j][i] == 0) && (j < dlg_kraw)) {
            j += 1;
        }
        if (j == dlg_kraw) {
            czy_koniec_schodka_i = 1;
            czy_koniec_schodkow_i = 1;
        }
        if (j > i) {
            for (int kkk = 0; kkk < dlg_kraw; ++kkk) {

                temp_swap = tab_tab[i][kkk];
                tab_tab[i][kkk] = tab_tab[j][kkk];
                tab_tab[j][kkk] = temp_swap;
            }

            znak_wyznaccznika *= -1;
        }


        if (czy_koniec_schodka_i != 1) {

            j = i; // kolumna w ktorej dzialamy // idziemy od tej kolumny do konca macierzy

            if ((i + 1) < dlg_kraw) {
                k = i + 1; // wiersz ktory bedziemy zerowac
            }


            while (k < dlg_kraw) {
                if (tab_tab[k][j] != 0) {


                    temp_nww = nww(tab_tab[i][i], tab_tab[k][j]);

                    if (tab_tab[i][i] == 0 || tab_tab[k][j] == 0) {
                        return 0;
                    }

                    temp_1 = temp_nww / tab_tab[i][i];
                    temp_2 = temp_nww / tab_tab[k][j];
                    dzielna_wyznacznika *= temp_2;


                    for (int zzz = i; zzz < dlg_kraw; zzz++) {

                        temp_3 = tab_tab[i][zzz] * temp_1;
                        tab_tab[k][zzz] = tab_tab[k][zzz] * temp_2;
                        tab_tab[k][zzz] = tab_tab[k][zzz] - temp_3;

                    }

                    czy_koniec_schodkow_i = 1;
                }
                ++k;
            }
        }
        i++;
    }


    if (czy_koniec_schodka_i != 1) {

        for (int zzzz = 0; zzzz < dlg_kraw; zzzz++) {
            diagonala *= tab_tab[zzzz][zzzz];
        }

        diagonala *= znak_wyznaccznika;

        if (dzielna_wyznacznika != 0) {
            diagonala = diagonala / dzielna_wyznacznika;
        }


    } else {
        diagonala = 0;
    }


    return diagonala;

}


int main() {



    // zmienne do operacji

    char kod_operacji = 'x';


    // ogolne
    int poziom_w = -1;
    int pion_w = -1;
    int panel_w = -1;

    int tab_wysokosc[2] = {};
    int tab_szerokosc[2] = {};
    int tab_glebokosc[2] = {};

    // czworoscian
    int dlg_e = 0;

    // prostopadloscian
    int wys_p = -1;
    int szer_p = -1;
    int glebokosc_p = -1;

    // kula
    int dlg_r = 0;

    // wyznacznik
    char ktory_poziom_pion_panel = 'x';
    int iii_det = -1;

    // czy wyszla bryla poza szescian danych
    short czy_wyszlo = 0;
    short czy_wyszlo_2 = 0;


    int wymiar_bryly = 3;

    long long int suma_punktow_bryly_odp = 0;
    int ilosc_puntkow_bryly_w_szescianie = 0;

    int i = 0;
    int j = 0;
    int k = 0;

    int i_2 = 0;  // okreslenie poczatku i konca bryly w petli
    int j_2 = 0;
    int k_2 = 0;

    int oryginalne_wspolrzedne_bryly[3] = {0, 0, 0};

    short czy_rownanie_kuli_spelnione = 0;
    long long int rownanie_kuli = 0;
    long long int rownanie_czworoscianu = 0;
    short czy_rownanie_czworoscianu_spelnione = 0;


    int odleglosc_x_od_wierzcholka_czoworscian = 0;
    int odleglosc_y_od_wierzcholka_czoworscian = 0;
    int odleglosc_z_od_wierzcholka_czoworscian = 0;

    int temp_1_czworoscian = 0;
    int temp_2_czworoscian = 0;
    int temp_3_czworoscian = 0;

    int dlg_kraw = 0;
    cin >> dlg_kraw;

    const int dlg_kraw_const = dlg_kraw;

    int objetosc_szescianu = dlg_kraw * dlg_kraw * dlg_kraw;

    long long int tab_szescian_wyznacznik[32][32] = {0};

    int tablica_szescian[32][32][32] = {0};


    int temp_wartosci_pkt;
    // int temp_wartosc_o_1_wieksza = 1;
    while (i < dlg_kraw_const) {
        j = 0;
        while (j < dlg_kraw_const) {
            k = 0;
            while (k < dlg_kraw_const) {
                cin >> temp_wartosci_pkt;
                tablica_szescian[i][j][k] = temp_wartosci_pkt;


                k++;
            }
            j++;
        }
        i++;
    }


    while (kod_operacji != 'E') {

        cin >> kod_operacji;


        poziom_w = 0;
        pion_w = 0;
        panel_w = 0;

        dlg_e = 0;
        dlg_r = 0;


        wys_p = 0;
        szer_p = 0;
        glebokosc_p = 0;

        ktory_poziom_pion_panel = 'x';
        iii_det = 0;

        // okreslenie wierzcholka

        if (kod_operacji != 'D' && kod_operacji != 'E') {


            tab_wysokosc[0] = 0;
            tab_wysokosc[1] = 0;

            tab_szerokosc[0] = 0;
            tab_szerokosc[1] = 0;

            tab_glebokosc[0] = 0;
            tab_glebokosc[1] = 0;


            cin >> poziom_w;
            cin >> pion_w;
            cin >> panel_w;

            oryginalne_wspolrzedne_bryly[0] = poziom_w;
            oryginalne_wspolrzedne_bryly[1] = pion_w;
            oryginalne_wspolrzedne_bryly[2] = panel_w;

            tab_wysokosc[0] = poziom_w;
            tab_szerokosc[0] = pion_w;
            tab_glebokosc[0] = panel_w;

            czy_wyszlo = 0;
            czy_wyszlo_2 = 0;

            czy_rownanie_kuli_spelnione = 0;
            rownanie_kuli = 0;

            rownanie_czworoscianu = 0;
            czy_rownanie_czworoscianu_spelnione = 0;

            suma_punktow_bryly_odp = 0;
            ilosc_puntkow_bryly_w_szescianie = 0;

        }


        i = 0;
        j = 0;
        k = 0;

        i_2 = 0;  // okreslenie poczatku i konca bryly w petli
        j_2 = 0;  // wszystko jest juz odwrocone
        k_2 = 0;


        if (kod_operacji == 'T') // czworoscian
        {

            cin >> dlg_e;


            if (tab_wysokosc[0] >= dlg_kraw / 2) {
                tab_wysokosc[1] = tab_wysokosc[0] - dlg_e;

            } else if (tab_wysokosc[0] < dlg_kraw / 2) {
                tab_wysokosc[1] = tab_wysokosc[0] + dlg_e;
            }

            if (tab_szerokosc[0] >= dlg_kraw / 2) {
                tab_szerokosc[1] = tab_szerokosc[0] - dlg_e;

            } else if (tab_szerokosc[0] < dlg_kraw / 2) {
                tab_szerokosc[1] = tab_szerokosc[0] + dlg_e;
            }

            if (tab_glebokosc[0] >= dlg_kraw / 2) {
                tab_glebokosc[1] = tab_glebokosc[0] - dlg_e;

            } else if (tab_glebokosc[0] < dlg_kraw / 2) {
                tab_glebokosc[1] = tab_glebokosc[0] + dlg_e;
            }


            czy_wyszlo_2 = obcinanie_wektorow_all(tab_wysokosc, tab_szerokosc, tab_glebokosc, dlg_kraw_const);


            if (czy_wyszlo == 1 || czy_wyszlo_2 == 1) {
                suma_punktow_bryly_odp = 0;
            } else if ((czy_wyszlo == 0) && (czy_wyszlo_2 == 0)) {


                odleglosc_x_od_wierzcholka_czoworscian = 0;
                odleglosc_y_od_wierzcholka_czoworscian = 0;
                odleglosc_z_od_wierzcholka_czoworscian = 0;


                i = tab_glebokosc[0];
                i_2 = tab_glebokosc[1];

                j = tab_wysokosc[0];
                j_2 = tab_wysokosc[1];

                k = tab_szerokosc[0];
                k_2 = tab_szerokosc[1];


                while (i <= i_2)  // niewiadomo czy mniejsze badz rowne czy mneijsze bo nie wiadomo co naezy do punktu
                {
                    j = tab_wysokosc[0];


                    while (j <= j_2) {


                        k = tab_szerokosc[0];
                        while (k <= k_2) {


                            rownanie_czworoscianu = 0;

                            temp_1_czworoscian = k - oryginalne_wspolrzedne_bryly[1];
                            if (temp_1_czworoscian < 0) {
                                temp_1_czworoscian *= -1;
                            }
                            temp_2_czworoscian = j - oryginalne_wspolrzedne_bryly[0];
                            if (temp_2_czworoscian < 0) {
                                temp_2_czworoscian *= -1;
                            }
                            temp_3_czworoscian = i - oryginalne_wspolrzedne_bryly[2];
                            if (temp_3_czworoscian < 0) {
                                temp_3_czworoscian *= -1;
                            }

                            rownanie_czworoscianu = temp_1_czworoscian + temp_2_czworoscian + temp_3_czworoscian;


                            if (rownanie_czworoscianu <= (dlg_e)) {
                                czy_rownanie_czworoscianu_spelnione = 1;
                                ilosc_puntkow_bryly_w_szescianie += 1;
                                suma_punktow_bryly_odp += tablica_szescian[i][j][k];

                            }


                            k += 1;
                        }
                        j += 1;
                    }
                    i += 1;
                }
                i = 0;
                j = 0;
                k = 0;

            }

            cout << suma_punktow_bryly_odp << endl;

        } else if (kod_operacji == 'C') // prostopadlsocian
        {


            cin >> wys_p;
            cin >> szer_p;
            cin >> glebokosc_p;


            ilosc_puntkow_bryly_w_szescianie = 0;
            suma_punktow_bryly_odp = 0;


            if (tab_wysokosc[0] >= dlg_kraw / 2) {
                tab_wysokosc[1] = tab_wysokosc[0] - wys_p;

            } else if (tab_wysokosc[0] < dlg_kraw / 2) {
                tab_wysokosc[1] = tab_wysokosc[0] + wys_p;
            }
            //
            if (tab_szerokosc[0] >= dlg_kraw / 2) {
                tab_szerokosc[1] = tab_szerokosc[0] - szer_p;


            } else if (tab_szerokosc[0] < dlg_kraw / 2) {
                tab_szerokosc[1] = tab_szerokosc[0] + szer_p;
            }
            //
            if (tab_glebokosc[0] >= dlg_kraw / 2) {
                tab_glebokosc[1] = tab_glebokosc[0] - glebokosc_p;

            } else if (tab_glebokosc[0] < dlg_kraw / 2) {
                tab_glebokosc[1] = tab_glebokosc[0] + glebokosc_p;
            }


            czy_wyszlo_2 = obcinanie_wektorow_all(tab_wysokosc, tab_szerokosc, tab_glebokosc, dlg_kraw_const);


            if (czy_wyszlo == 1) {
                suma_punktow_bryly_odp = 0;
            } else if (czy_wyszlo == 0) {


                i = tab_glebokosc[0];
                i_2 = tab_glebokosc[1];

                j = tab_wysokosc[0];
                j_2 = tab_wysokosc[1];

                k = tab_szerokosc[0];
                k_2 = tab_szerokosc[1];


                if (czy_wyszlo == 0 && czy_wyszlo_2 == 0) {
                    while (i <=
                           i_2)  // niewiadomo czy mniejsze badz rowne czy mneijsze bo nie wiadomo co naezy do punktu
                    {

                        while (j <= j_2) {

                            while (k <= k_2) {

                                suma_punktow_bryly_odp += tablica_szescian[i][j][k];
                                ilosc_puntkow_bryly_w_szescianie += 1;

                                k += 1;
                            }
                            k = tab_szerokosc[0];


                            j += 1;
                        }
                        j = tab_wysokosc[0];
                        i += 1;
                    }
                    i = 0;
                    j = 0;
                    k = 0;

                }


            }

            cout << suma_punktow_bryly_odp << endl;

        } else if (kod_operacji == 'O') // kula daje fula
        {


            cin >> dlg_r;


            if (tab_wysokosc[0] >= dlg_kraw / 2) {
                tab_wysokosc[1] = tab_wysokosc[0] - dlg_r;

            } else if (tab_wysokosc[0] < dlg_kraw / 2) {
                tab_wysokosc[1] = tab_wysokosc[0] + dlg_r;
            }
            //
            if (tab_szerokosc[0] >= dlg_kraw / 2) {
                tab_szerokosc[1] = tab_szerokosc[0] - dlg_r;

            } else if (tab_szerokosc[0] < dlg_kraw / 2) {
                tab_szerokosc[1] = tab_szerokosc[0] + dlg_r;
            }
            //
            if (tab_glebokosc[0] >= dlg_kraw / 2) {
                tab_glebokosc[1] = tab_glebokosc[0] - dlg_r;

            } else if (tab_glebokosc[0] < dlg_kraw / 2) {
                tab_glebokosc[1] = tab_glebokosc[0] + dlg_r;
            }


            czy_wyszlo_2 = obcinanie_wektorow_all(tab_wysokosc, tab_szerokosc, tab_glebokosc, dlg_kraw_const);


            if (czy_wyszlo == 1 || czy_wyszlo_2 == 1) {
                suma_punktow_bryly_odp = 0;
            } else if ((czy_wyszlo == 0) && (czy_wyszlo_2 == 0)) {

                //dlg_r -= 1;

                i = tab_glebokosc[0];
                i_2 = tab_glebokosc[1];

                j = tab_wysokosc[0];
                j_2 = tab_wysokosc[1];

                k = tab_szerokosc[0];
                k_2 = tab_szerokosc[1];


                while (i <= i_2)  // niewiadomo czy mniejsze badz rowne czy mneijsze bo nie wiadomo co naezy do punktu
                {
                    j = tab_wysokosc[0];

                    while (j <= j_2) {

                        k = tab_szerokosc[0];
                        while (k <= k_2) {

                            rownanie_kuli =
                                    (i - oryginalne_wspolrzedne_bryly[2]) * (i - oryginalne_wspolrzedne_bryly[2]) +
                                    (j - oryginalne_wspolrzedne_bryly[0]) * (j - oryginalne_wspolrzedne_bryly[0]) +
                                    (k - oryginalne_wspolrzedne_bryly[1]) * (k - oryginalne_wspolrzedne_bryly[1]);

                            if (rownanie_kuli <= dlg_r * dlg_r) {

                                czy_rownanie_kuli_spelnione = 1;
                                ilosc_puntkow_bryly_w_szescianie += 1;
                                suma_punktow_bryly_odp += tablica_szescian[i][j][k];

                            }

                            k += 1;
                        }
                        j += 1;
                    }
                    i += 1;
                }
                i = 0;
                j = 0;
                k = 0;

            }

            cout << suma_punktow_bryly_odp << endl;


        } else if (kod_operacji == 'D') {


            cin >> ktory_poziom_pion_panel;
            cin >> iii_det;
            // poziom - wys
            if (ktory_poziom_pion_panel == 'l') {

                for (int i_3 = 0; i_3 < dlg_kraw_const; ++i_3) {
                    for (int j_3 = 0; j_3 < dlg_kraw_const; ++j_3) {
                        tab_szescian_wyznacznik[i_3][j_3] = tablica_szescian[i_3][iii_det][j_3];
                    }
                }
                // pion - szer
            } else if (ktory_poziom_pion_panel == 'v') {

                for (int i_3 = 0; i_3 < dlg_kraw_const; ++i_3) {

                    for (int j_3 = 0; j_3 < dlg_kraw_const; ++j_3) {
                        tab_szescian_wyznacznik[i_3][j_3] = tablica_szescian[i_3][j_3][iii_det];
                    }
                } // panel - gleb
            } else if (ktory_poziom_pion_panel == 'p') {

                for (int i_3 = 0; i_3 < dlg_kraw_const; ++i_3) {
                    for (int j_3 = 0; j_3 < dlg_kraw_const; ++j_3) {
                        tab_szescian_wyznacznik[i_3][j_3] = tablica_szescian[iii_det][i_3][j_3];
                    }
                }

            }

            cout << schodkowanie(tab_szescian_wyznacznik, dlg_kraw_const) << endl;

        }

    }

    return 0;
}


