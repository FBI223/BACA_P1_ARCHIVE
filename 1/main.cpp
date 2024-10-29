//Marcin Sztukowski
#include <iostream>

using namespace std;



int main()
{

    int op=0;

    short dlg_in;
    cin >> dlg_in;


    int n_tab;



    char operacja_temp='0';


    // odwracanie zmienne

    int ile_cykli;
    int ile_cykli_w_cyklach;

    int x_p;
    int x_k;

    int x_p_stala;
    int x_k_stala;

    int n_odwr;

    int temp_odwr;


    // zamiana par zmienne
    int ile_par_w_tab;
    int n_ciag_p;
    int x_pp_1;
    int x_pp_2;
    int x_kk_1;
    int x_kk_2;


    int x_pp_stala;
    int x_kk_stala;

    int x_pp;
    int x_kk;

    int temp_prr;


    // przesuwanie malych tablic w tablicy o zadana wartosc

    int x_ppp_1;
    int x_kkk_1;

    int x_ppp;
    int x_kkk;
    int n_przesu_frg;
    int wartosc_przesu;
    int wartosc_przesu_main;

    int ile_leftovers;

    int temp_przes;

    int ile_cykli_przesuniecia;

    int ike_swapow_temp;

    int temp_1_swap;
    int temp_2_swap;

    int wartosc_przesu_czy_uj;



    int j = 0;
    int i = 0;
    int k = 0;



    while ( op < dlg_in )
    {


        cin >> n_tab;
        int tablica[n_tab];


        while (i < n_tab)
        {
            cin >> tablica[i];
            ++i;
        }
        i = 0;

        while (i < n_tab-1)
        {

            cout << tablica[i] << ' ';
            ++i;
        }

        cout<< tablica[n_tab-1] <<endl;
        i=0;


        while (operacja_temp != 'F') {

            cin >> operacja_temp;


            if (operacja_temp == 'R') // odwracanie
            {
                cin >> x_p;

                cin >> n_odwr;

                ile_cykli_w_cyklach = n_odwr / 2;
                ile_cykli = n_tab / n_odwr;

                if (x_p >= n_tab) // jezeli indeks wykracza poza tablice ( + )
                {
                    x_p = x_p % n_tab;
                } else if (x_p < 0) // jezeli indeks jest ujemny to szukaj odpowiedni indeks
                {
                    x_p = x_p % n_tab;
                    x_p = n_tab + x_p;
                }
                x_p_stala = x_p;
                x_k = x_p + (n_odwr - 1); // DODAJESZ O 1 mniej bo sam x_p jest elementem fragmentu ciagu
                if (x_k >=
                    n_tab) // sprawdz czy po dodaniu dlugosci fragmentu do pierwszego indeksu czy wychodzi poza tablice
                {
                    x_k = x_k % n_tab;
                }

                x_k_stala = x_k; // ustaw indeks elementu z ktorym bedziesz zamienial x_p

//            cout << x_p <<endl;
//            cout<<x_k<<endl;
//            cout<< ile_cykli<<endl;
//            cout<<ile_cykli_w_cyklach<<endl;

                while (i < ile_cykli) {
                    //cout<<endl;
                    //cout<<" iiiiiiiiiiiii "<<endl;
                    //cout<<endl;
                    while (j < ile_cykli_w_cyklach) {
                        //cout<<endl;
                        //cout<<" jjjjjjjjjjj "<<endl;
                        //cout<<endl;
                        if (x_p != x_k) {

                            temp_odwr = tablica[x_p];
                            tablica[x_p] = tablica[x_k];
                            tablica[x_k] = temp_odwr;
                            // cout << tablica[0]<<"  "<<tablica[1]<<"  "<<tablica[2]<<"  "<<tablica[3]<<"  "<<tablica[4]<<"  "<<tablica[5]<<"  "<<tablica[6]<<"  "<<endl;
                        }

                        x_p += 1;
                        x_k -= 1;

                        if (x_p >= n_tab) {
                            x_p = x_p % n_tab;
                        }
                        if (x_k < 0) {
                            x_k = n_tab - 1;
                        }

                        ++j;
                    }
                    j = 0;
                    ++i;

                    //cout<<x_p_stala<<endl;
                    // cout<<x_k_stala<<endl;

                    x_p_stala = x_k_stala + 1;
                    if (x_p_stala >= n_tab) {
                        x_p_stala = x_p_stala % n_tab;
                    }
                    x_k_stala = x_p_stala + (n_odwr - 1);
                    if (x_k_stala >= n_tab) {
                        x_k_stala = x_k_stala % n_tab;
                    }

                    x_p = x_p_stala;
                    x_k = x_k_stala;

                }
                i = 0;
                j = 0;


            } else if (operacja_temp == 'C') // przesuwanie
            {


                i = 0;
                j = 0;
                k = 0;


                cin >> x_ppp;
                cin >> n_przesu_frg;
                cin >> wartosc_przesu;
                wartosc_przesu_main = wartosc_przesu;


                wartosc_przesu_czy_uj = wartosc_przesu;
                if (wartosc_przesu < 0) {
                    wartosc_przesu_czy_uj = wartosc_przesu_czy_uj * (-1);
                }

                ile_cykli_przesuniecia = n_tab / n_przesu_frg;
                ile_leftovers = n_tab - (ile_cykli_przesuniecia * n_przesu_frg);


                if (x_ppp >= n_tab) {
                    x_ppp = x_ppp % n_tab;
                }
                if (x_ppp < 0) {
                    x_ppp = x_ppp % n_tab;
                    x_ppp = n_tab + x_ppp;
                }


                wartosc_przesu = wartosc_przesu % n_przesu_frg;


                x_kkk = x_ppp + (n_przesu_frg - 1);
                if (x_kkk >= n_tab) {
                    x_kkk = x_kkk % n_tab;
                }

                if (wartosc_przesu < 0) {
                    wartosc_przesu = n_przesu_frg + wartosc_przesu;
                }


                ike_swapow_temp = 0; // ile swapow < n_przesu_frg

                while (i < ile_cykli_przesuniecia) {

                    j = 0;
                    while (j < wartosc_przesu) {
                        temp_przes = tablica[x_kkk];

                        k = x_kkk;
                        temp_2_swap = 0; // ile swapow wykonano dotychczas

                        while (temp_2_swap < n_przesu_frg - 1) {
                            temp_1_swap = k - 1;
                            if (temp_1_swap < 0) {
                                temp_1_swap = n_tab - 1;
                            }

                            tablica[k] = tablica[temp_1_swap];
                            temp_2_swap += 1;
                            k = temp_1_swap;
                        }
                        tablica[x_ppp] = temp_przes;
                        ++j;
                    }
                    ++i;
                    j = 0;


                    x_ppp = x_kkk + 1;
                    if (x_ppp >= n_tab) {
                        x_ppp = x_ppp % n_tab;
                    }
                    x_kkk = x_ppp + (n_przesu_frg - 1);
                    if (x_kkk >= n_tab) {
                        x_kkk = x_kkk % n_tab;
                    }

                }
                i = 0;

                if (ile_leftovers > 1) {

                    x_kkk = x_ppp + (ile_leftovers - 1);
                    if (x_kkk >= n_tab) {
                        x_kkk = x_kkk % n_tab;
                    }

                    wartosc_przesu = wartosc_przesu_main % ile_leftovers;
                    if (wartosc_przesu < 0) {
                        wartosc_przesu = ile_leftovers + wartosc_przesu;
                    }

                    i = 0;
                    j = 0;
                    k = 0;

                    while (i < wartosc_przesu) {
                        temp_przes = tablica[x_kkk];
                        k = x_kkk;
                        temp_2_swap = 0;
                        while (temp_2_swap < ile_leftovers - 1) {
                            temp_1_swap = k - 1;
                            if (temp_1_swap < 0) {
                                temp_1_swap = n_tab - 1;
                            }

                            tablica[k] = tablica[temp_1_swap];
                            k = temp_1_swap;
                            temp_2_swap += 1;
                        }
                        tablica[x_ppp] = temp_przes;
                        ++i;

                    }
                }


            } else if (operacja_temp == 'S') // zamiana parami
            {


                cin >> x_pp;
                cin >> n_ciag_p;

                ile_par_w_tab = n_tab / (n_ciag_p + n_ciag_p);

                i = 0;
                j = 0;

                if (x_pp >= n_tab) {
                    x_pp = x_pp % n_tab;
                }
                if (x_pp < 0) {
                    x_pp = x_pp % n_tab;
                    x_pp = n_tab + x_pp;
                }

                x_kk = x_pp + (n_ciag_p - 1);
                if (x_kk >= n_tab) {
                    x_kk = x_kk % n_tab;
                }

                x_pp_1 = x_pp;
                x_kk_1 = x_kk;

                x_pp_2 = x_kk_1 + 1;

                if (x_pp_2 >= n_tab) {
                    x_pp_2 = x_pp_2 % n_tab;
                }
                x_kk_2 = x_pp_2 + (n_ciag_p - 1);
                if (x_kk_2 >= n_tab) {
                    x_kk_2 = x_kk_2 % n_tab;
                }


                while (i < ile_par_w_tab) {
                    while (j < n_ciag_p) {

                        temp_prr = tablica[x_pp_1];
                        tablica[x_pp_1] = tablica[x_pp_2];
                        tablica[x_pp_2] = temp_prr;

                        x_pp_1 += 1;
                        x_pp_2 += 1;

                        if (x_pp_1 >= n_tab) {
                            x_pp_1 = x_pp_1 % n_tab;
                        }
                        if (x_pp_2 >= n_tab) {
                            x_pp_2 = x_pp_2 % n_tab;
                        }

                        j += 1;
                    }
                    j = 0;
                    ++i;

                    x_pp_1 = x_kk_2 + 1;
                    if (x_pp_1 >= n_tab) {
                        x_pp_1 % n_tab;
                    }
                    x_kk_1 = x_pp_1 + (n_ciag_p - 1);
                    if (x_kk_1 >= n_tab) {
                        x_kk_1 = x_kk_1 % n_tab;
                    }
                    x_pp_2 = x_kk_1 + 1;
                    if (x_pp_2 >= n_tab) {
                        x_pp_2 % n_tab;
                    }
                    x_kk_2 = x_pp_2 + (n_ciag_p - 1);
                    if (x_kk_2 >= n_tab) {
                        x_kk_2 = x_kk_2 % n_tab;
                    }

                }
                i = 0;
                j = 0;

            }

        }

        while (i < n_tab - 1)
        {

            cout << tablica[i] << ' ';
            ++i;
        }

        cout<< tablica[n_tab - 1] <<endl;
        i=0;

        op+=1;
        operacja_temp='0';
    }

    return 0;
}