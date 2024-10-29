#include <iostream>


//  czy stracony wymiar x y z gdzy t0 t1 = [ 0 -1 ]  najmniejsza dlugosc krawedzi to 1 czy;o np [ 1 , 1 ]

// najlepiej zrób coś takiego: if( l >= ( n / 2 ) ) turnL = -1, a potem jeden z warunków w ifie: ( l + i * turnL >= 0 ) ( gdzie l to np wysokość, n to rozmiar sześcianu, turnL ma wartość 1, ale jak warunek się spełni, to zmieniasz na -1,  i to iterator po wysokości w tym przypadku

// oddzielne zmienne na tablice wysokosci i szerokosci t0 i t1

// petla w czworoscianie zmiejsza sie o 1 w kazdym kroku  ( po jednym obiegu )

// schodkowo schozdisz

using namespace std;


//void jaki_wymiar_bryly( int tab_wys[2],int tab_szer[2],int tab_glebokosc[2],int wymiar_bryly )
//{
//    if ( tab_wys[0] ==tab_wys[1] )
//    {
//        wymiar_bryly-=1;
//    }
//    if ( tab_szer[0] ==tab_szer[1] )
//    {
//        wymiar_bryly-=1;
//    }
//    if ( tab_glebokosc[0] ==tab_glebokosc[1] )
//    {
//        wymiar_bryly-=1;
//    }
//
//}

short obcinanie_wektora( int tab_tab[2], int kraw_szesc )
{
    short czy_wyszlo_poza=0;
    int temp_swap=0;
    short czy_redukcja_wymiaru=0;
    char ktory_kierunek='x';

    short czy_byl_swap_kierunku_wektora=0;

    if ( tab_tab[0] <= tab_tab[1] )
    {
        ktory_kierunek='y';  // skierowanie ( kierunek wektora ) // normalna strona
    } else if ( tab_tab[0] > tab_tab[1] )
    {
        // skierowanie ( kierunek wektora ) // odwrotna strona
        temp_swap = tab_tab[0];
        tab_tab[0] = tab_tab[1];
        tab_tab[1] = temp_swap;
        ktory_kierunek='y';
        czy_byl_swap_kierunku_wektora=1;

    }

    if ( tab_tab[0] ==  tab_tab[1] )
    {
        if ( tab_tab[0]<0 || tab_tab[0]>=kraw_szesc )
        {
            czy_wyszlo_poza = 1;
        }

    } else if ( ktory_kierunek == 'y' )
    {

        if ( tab_tab[0] < 0 && tab_tab[1] >= kraw_szesc )
        {
            tab_tab[0] = 0;
            tab_tab[1] = kraw_szesc-1;
        }else if ( (tab_tab[0]<0 && tab_tab[1] <0) || ( (tab_tab[0]>=kraw_szesc && tab_tab[1] >= kraw_szesc) ) )
        {
            czy_wyszlo_poza = 1;
        } else if ( tab_tab[0]<0 && tab_tab[1] >=0 && tab_tab[1] < kraw_szesc  )
        {
            tab_tab[0] = 0;
        } else if ( tab_tab[0]>=0 && tab_tab[0]<kraw_szesc && tab_tab[1] >= kraw_szesc )
        {
            tab_tab[1] = kraw_szesc - 1;
        }

    }

    // nie wiem czy zamieniac kolejnascia kierunek wektorow // to moze sie przydac potem // nwm
//    if ( czy_byl_swap_kierunku_wektora == 1 )
//    {
//        temp_swap = tab_tab[0];
//        tab_tab[0] = tab_tab[1];
//        tab_tab[1] = temp_swap;
//    }




    //else if ( tab_tab[0]>=0 && tab_tab[1]<kraw_szesc )


    return czy_wyszlo_poza;

}


short czy_wyszedl_wektor( int tab_tab[2],int kraw_szesc )
{

    short czy_wyszlo_poza=0;
    int temp_swap=0;
    char ktory_kierunek='x';
    short czy_byl_swap_kierunku_wektora=0;


    if ( tab_tab[0] <= tab_tab[1] )
    {
        ktory_kierunek='y';  // skierowanie ( kierunek wektora ) // normalna strona
    } else if ( tab_tab[0] > tab_tab[1] )
    {
        // skierowanie ( kierunek wektora ) // odwrotna strona
        temp_swap = tab_tab[0];
        tab_tab[0] = tab_tab[1];
        tab_tab[1] = temp_swap;
        czy_byl_swap_kierunku_wektora=1;
    }

    if ( tab_tab[0] ==  tab_tab[1] )
    {
        if ( tab_tab[0]<0 || tab_tab[0]>=kraw_szesc )
        {
            czy_wyszlo_poza = 1;
        }

    } else
    {

        if ( (tab_tab[0]<0 && tab_tab[1] <0) || ( (tab_tab[0]>=kraw_szesc && tab_tab[1] >= kraw_szesc) ) )
        {
            czy_wyszlo_poza = 1;
        }
    }
    return czy_wyszlo_poza;

}


short czy_wyszly_wektory_all(int tab_tab_1[2], int tab_tab_2[2],int tab_tab_3[2],int krawedz_szesc)
{

    short czy_wyszly_wektory_all = 0;

    short x1=czy_wyszedl_wektor(tab_tab_1,krawedz_szesc);
    short x2=czy_wyszedl_wektor(tab_tab_2,krawedz_szesc);
    short x3=czy_wyszedl_wektor(tab_tab_3,krawedz_szesc);

    czy_wyszly_wektory_all = x1+x2+x3;

    if ( czy_wyszly_wektory_all == 0 )
    {
        return czy_wyszly_wektory_all;
    }else
    {
        czy_wyszly_wektory_all = 1;
        return czy_wyszly_wektory_all;
    }

}

short obcinanie_wektorow_all(int tab_wys[2],int tab_szer[2],int tab_glebokosc[2], int kraw_szesc )
{
    // mozna robic kopie wszsys tkich tablic ale chyba nie trzeba ( do referencji )

    short czy_wyszlo_poza_tablice=0;

    int tab_wys_kopia[2]={tab_wys[0],tab_wys[1]};
    int tab_szer_kopia[2]={tab_szer[0],tab_szer[1]};
    int tab_glebokosc_kopia[2]={tab_glebokosc[0],tab_glebokosc[1]};
    int kraw_szesc_kopia = kraw_szesc;

    czy_wyszlo_poza_tablice=    obcinanie_wektora(tab_wys,kraw_szesc);



    if ( czy_wyszlo_poza_tablice != 1 )
    {
         czy_wyszlo_poza_tablice= obcinanie_wektora(tab_szer,kraw_szesc);
    }
    if ( czy_wyszlo_poza_tablice != 1 )
    {
        czy_wyszlo_poza_tablice= obcinanie_wektora(tab_glebokosc,kraw_szesc);
    }

//    tab_wys[0]=tab_wys_kopia[0];
//    tab_wys[1]=tab_wys_kopia[1];
//    tab_szer[0]=tab_szer_kopia[0];
//    tab_szer[1]=tab_szer_kopia[1];
//    tab_glebokosc[0]=tab_glebokosc_kopia[0];
//    tab_glebokosc[1]=tab_glebokosc_kopia[1];

    return czy_wyszlo_poza_tablice;


}




long long int wyznacznik_2_2(int tab_tab[32][32],int wiersz_x_sr,int kolumna_y_sr)
{
    long long int wartosc_wyznacznika = 0;

    long long int a = tab_tab[wiersz_x_sr][kolumna_y_sr] ;
    long long int b = tab_tab[wiersz_x_sr][kolumna_y_sr+1] ;
    long long int c = tab_tab[wiersz_x_sr+1][kolumna_y_sr];
    long long int d = tab_tab[wiersz_x_sr+1][kolumna_y_sr+1] ;
    cout<<endl;
    cout << " a:  "<<a <<endl;
    cout << " b:  "<<b <<endl;
    cout << " c:  "<<c <<endl;
    cout << " d:  "<<d <<endl;
    cout<<endl;
    wartosc_wyznacznika = (a*d) - (c*b);
    //wartosc_wyznacznika = (tab_tab[wiersz_x_sr][kolumna_y_sr] * tab_tab[wiersz_x_sr+1][kolumna_y_sr+1] ) - (tab_tab[wiersz_x_sr+1][kolumna_y_sr] * tab_tab[wiersz_x_sr][kolumna_y_sr+1] )   ;


    cout<<endl;
    cout<<wartosc_wyznacznika<<endl;
    cout<<endl;

    return wartosc_wyznacznika;
}

long long int wyznacznik_3_3(int tab_tab[32][32] ,int wiersz_x_sr,int kolumna_y_sr)
{
    long long int wartosc_wyznacznika = 0;


    //wartosc_wyznacznika = ((wyznacznik_2_2(tab_tab,wiersz_x_sr,kolumna_y_sr))*(wyznacznik_2_2(tab_tab,wiersz_x_sr+2,kolumna_y_sr+2))) - ((wyznacznik_2_2(tab_tab,wiersz_x_sr+2,kolumna_y_sr))*(wyznacznik_2_2(tab_tab,wiersz_x_sr,kolumna_y_sr+2)));

    wartosc_wyznacznika = ((tab_tab[wiersz_x_sr][kolumna_y_sr]*tab_tab[wiersz_x_sr+1][kolumna_y_sr+1]*tab_tab[wiersz_x_sr+2][kolumna_y_sr+2]) + (tab_tab[wiersz_x_sr+1][kolumna_y_sr]*tab_tab[wiersz_x_sr+2][kolumna_y_sr+1]*tab_tab[wiersz_x_sr][kolumna_y_sr+2]) + (tab_tab[wiersz_x_sr+2][kolumna_y_sr]*tab_tab[wiersz_x_sr][kolumna_y_sr+1]*tab_tab[wiersz_x_sr+1][kolumna_y_sr+2])) -  ((tab_tab[wiersz_x_sr][kolumna_y_sr+2]*tab_tab[wiersz_x_sr+1][kolumna_y_sr+1]*tab_tab[wiersz_x_sr+2][kolumna_y_sr+0]) + (tab_tab[wiersz_x_sr+1][kolumna_y_sr+2]*tab_tab[wiersz_x_sr+2][kolumna_y_sr+1]*tab_tab[wiersz_x_sr][kolumna_y_sr]) + (tab_tab[wiersz_x_sr+2][kolumna_y_sr+2]*tab_tab[wiersz_x_sr][kolumna_y_sr+1]*tab_tab[wiersz_x_sr+1][kolumna_y_sr]))    ;


    return wartosc_wyznacznika;
}


void rob_kopie_macierzy( int tab_tab[32][32],int wiersz_x_sr, int kolumna_y_sr, int dlg_kraw,int x_cofactor,int y_cofactor)
{
    int tab_druga[dlg_kraw-1][dlg_kraw-1];

    for (int i = 0;i<dlg_kraw;++i)
    {

        for ( int j =0; j< dlg_kraw;++j)
        {

            if ( i != x_cofactor && j != y_cofactor )
            {

                tab_druga[i][j] = tab_tab[wiersz_x_sr][kolumna_y_sr];
                wiersz_x_sr+=1;
                kolumna_y_sr+=1;

            }

        }

    }


}

long long int laplaca( int tab_tab[32][32],int wiersz_x_sr, int kolumna_y_sr, int dlg_kraw )
{
    long long int wartosc_wyznacznika=0;
    int wspolczynnik=-1;


    // int kopia_wyznacznika[dlg_kraw][dlg_kraw]={};

    int x_cofator=0;
    int y_cofactor = 0;

    if ( dlg_kraw == 1)
    {
        return tab_tab[wiersz_x_sr][kolumna_y_sr];
    } else if ( dlg_kraw == 2 )
    {
        return wyznacznik_2_2(tab_tab,wiersz_x_sr,kolumna_y_sr);
    }else {

        int ilosc_kolumn = dlg_kraw;


        for (int i = 0; i < dlg_kraw; ++i)
        {
            if ( i % 2 == 0 )
            {
                wspolczynnik = 1;
            } else
            {
                wspolczynnik = (-1)* tab_tab[0][i];
            }

            wartosc_wyznacznika += wspolczynnik;
        }

    }

    return wartosc_wyznacznika;

}



long long int wyznacznik_4_4(int tab_tab[32][32] ,int wiersz_x_sr,int kolumna_y_sr)
{
    long long int wartosc_wyznacznika = 0;


    wartosc_wyznacznika = ((wyznacznik_2_2(tab_tab,wiersz_x_sr,kolumna_y_sr))*(wyznacznik_2_2(tab_tab,wiersz_x_sr+2,kolumna_y_sr+2))) - ((wyznacznik_2_2(tab_tab,wiersz_x_sr+2,kolumna_y_sr))*(wyznacznik_2_2(tab_tab,wiersz_x_sr,kolumna_y_sr+2)));


    return wartosc_wyznacznika;
}

long long int wyznacznik_8_8(int tab_tab[32][32] ,int wiersz_x_sr,int kolumna_y_sr)
{
    long long int wartosc_wyznacznika = 0;

    wartosc_wyznacznika = ((wyznacznik_4_4(tab_tab,wiersz_x_sr,kolumna_y_sr))*(wyznacznik_4_4(tab_tab,wiersz_x_sr+4,kolumna_y_sr+4))) - ((wyznacznik_4_4(tab_tab,wiersz_x_sr+4,kolumna_y_sr))*(wyznacznik_4_4(tab_tab,wiersz_x_sr,kolumna_y_sr+4)));


    return wartosc_wyznacznika;
}

long long int wyznacznik_16_16(int tab_tab[32][32] ,int wiersz_x_sr,int kolumna_y_sr)
{
    long long int wartosc_wyznacznika = 0;

    wartosc_wyznacznika = ((wyznacznik_8_8(tab_tab,wiersz_x_sr,kolumna_y_sr))*(wyznacznik_8_8(tab_tab,wiersz_x_sr+8,kolumna_y_sr+8))) - ((wyznacznik_8_8(tab_tab,wiersz_x_sr+8,kolumna_y_sr))*(wyznacznik_8_8(tab_tab,wiersz_x_sr,kolumna_y_sr+8)));


    return wartosc_wyznacznika;
}

long long int wyznacznik_32_32(int tab_tab[32][32] ,int wiersz_x_sr,int kolumna_y_sr)
{
    long long int wartosc_wyznacznika = 0;

    wartosc_wyznacznika = ((wyznacznik_16_16(tab_tab,wiersz_x_sr,kolumna_y_sr))*(wyznacznik_16_16(tab_tab,wiersz_x_sr+16,kolumna_y_sr+16))) - ((wyznacznik_16_16(tab_tab,wiersz_x_sr+16,kolumna_y_sr))*(wyznacznik_16_16(tab_tab,wiersz_x_sr,kolumna_y_sr+16)));


    return wartosc_wyznacznika;
}







long long int wyznacznik_glowny( int tab_tab[32][32], int dlg_kraw )
{
    long long int wartosc_wyznacznika = 0;


    if ( dlg_kraw == 2 )
    {
        return wyznacznik_2_2(tab_tab,0,0);
    } else if ( dlg_kraw == 4 )
    {
        return wyznacznik_4_4(tab_tab,0,0);
    }else if ( dlg_kraw == 8 )
    {
        return wyznacznik_8_8(tab_tab,0,0);
    }else if ( dlg_kraw == 4 )
    {
        return wyznacznik_16_16(tab_tab,0,0);
    }else if ( dlg_kraw == 4 )
    {
        return wyznacznik_32_32(tab_tab,0,0);
    }


}



long long nwd_i(long long int a, long long int b)
{
    long long int temp = 0;
    while (b > 0)
    {
        temp = a;
        a = b;
        b = temp % b;

    }
    return a;
}

long long nww(long long int a, long long int b)
{
    long long int nwww=0;

    nwww = (a*b)/ nwd_i(a,b);
    return nwww;
}


long long int schodkowanie( long long int tab_tab[32][32],int dlg_kraw )
{
    //cout<<"flaga nr 1 "<<endl;

    long long int wspolczynnik_mnozacy_wiersz=0;
    long long int temp_nww = 0;
    long long int temp_1=0;
    long long int temp_2=0;
    long long int mnoznik_wyznacznika=1;
    long long int dzielna_wyznacznika=1;

    long long int diagonala=1;


    int temp_swap=0;
    long long int wyznacznik=1;
    int znak_wyznaccznika=1;

    int czy_koniec_schodka_i=0;
    int czy_koniec_schodkow_i=0;

    int element_do_operacji=0;

    int j=0;
    int i=0;
    int k=0;
    //cout<<"flaga nr 1 "<<endl;
    while ((i< dlg_kraw-1) && (czy_koniec_schodka_i != 1))
    {
        //cout<<"flaga nr 1 "<<endl;
        j=i;

        while ( (tab_tab[i][j] == 0) && (j<dlg_kraw))
        {
            cout<<"flaga nr 1 "<<endl;
            j+=1;
        }

        if ( j == dlg_kraw )
        {
            czy_koniec_schodka_i = 1;
            wyznacznik = 0;
        }


        if ( j > i )
        {
            for ( int k = i; k< dlg_kraw; ++k)
            {

                temp_swap= tab_tab[i][k];
                tab_tab[i][k] = tab_tab[j][k];
                tab_tab[j][k] = temp_swap;
                znak_wyznaccznika*=-1;
            }


        }

        if ( czy_koniec_schodka_i != 1  )
        {
            j=i; // kolumna w ktorej dzialamy // idziemy od tej kolumny do konca macierzy
            k=i+1; // wiersz ktory bedziemy zerowac
            while ( k < dlg_kraw  )
            {
                //cout<<"flaga nr 1 "<<endl;
                if ( tab_tab[k][j] != 0)
                {

                    temp_nww = nww(tab_tab[i][i],tab_tab[k][j]);
                    temp_1 = temp_nww / tab_tab[i][i];
                    temp_2 = temp_nww / tab_tab[k][j];
                    dzielna_wyznacznika = temp_1*temp_2;

                    for ( int zzz = i; zzz<dlg_kraw ; zzz++)
                    {

                        tab_tab[i][zzz]=tab_tab[i][zzz]*temp_1;
                        tab_tab[k][zzz]=tab_tab[k][zzz]*temp_2;

                        tab_tab[k][zzz]=tab_tab[k][zzz]-tab_tab[i][zzz];
                    }
                }
                ++k;
            }
        }
        i++;
    }

    if (  czy_koniec_schodka_i != 1) {

        for (int zzzz = 0; zzzz < dlg_kraw; zzzz++) {
            diagonala *= tab_tab[zzzz][zzzz];
        }

        diagonala *= znak_wyznaccznika;
        diagonala = diagonala / dzielna_wyznacznika;

    }else
    {
        diagonala = 0;
    }

    return diagonala;

}

// nie dziala ta funkcja

void ktora_operacja( char x, int dlg_kraw )
{
    char kod_operacji = 'x';

    cin >> kod_operacji;

    if ( kod_operacji == 'T' ) // czoworscian
    {

        int x_w=-1;
        int y_w=-1;
        int z_w=-1;
        int dlg_e = 0;

        cin >> x_w ;
        cin >> y_w;
        cin >> y_w;
        cin >>dlg_e ;

        int tab_x_w[2]={};
        int tab_y_w[2]={};
        int tab_z_w[2]={};


    } else if ( kod_operacji == 'C' )
    {

        int x_w=-1;
        int y_w=-1;
        int z_w=-1;

        int wys_p = -1;
        int szer_p = -1;
        int glebokosc_p = -1;

        cin >> x_w ;
        cin >> y_w;
        cin >> y_w;

        cin >>wys_p ;
        cin >>szer_p ;
        cin >>glebokosc_p ;

        int tab_x_w[2]={};
        int tab_y_w[2]={};
        int tab_z_w[2]={};


    } else if ( kod_operacji == 'O' )
    {

        int x_w=-1;
        int y_w=-1;
        int z_w=-1;
        int dlg_r = 0;

        cin >> x_w ;
        cin >> y_w;
        cin >> y_w;
        cin >>dlg_r ;

        int tab_x_w[2]={};
        int tab_y_w[2]={};
        int tab_z_w[2]={};


    } else if ( kod_operacji == 'D' )
    {

        char ktory_poziom_pion_panel='x';
        int iii = -1;

        cin >> ktory_poziom_pion_panel;
        cin >> iii;


        if ( ktory_poziom_pion_panel == 'l' )
        {




        }else if (ktory_poziom_pion_panel == 'v')
        {





        } else if ( ktory_poziom_pion_panel == 'p' )
        {






        }




    }



}


int main()
{

    int temp_wartosc_el_wyz=1;

    int testowy_wyznacznik[32][32] = {};


//    for ( int i =0 ; i<3 ; ++i)
//    {
//        temp_wartosc_el_wyz-=1;
//        for ( int j =0; j<3;++j)
//        {
//
//
//            testowy_wyznacznik[i][j] = temp_wartosc_el_wyz;
//            temp_wartosc_el_wyz+=1;
//
//        }
//
//    }


    testowy_wyznacznik[0][0] = 1 ;
    testowy_wyznacznik[0][1] = 0;
    testowy_wyznacznik[0][2] = 0;
    testowy_wyznacznik[0][3] = 1;

    testowy_wyznacznik[1][0] = 0;
    testowy_wyznacznik[1][1] = 2;
    testowy_wyznacznik[1][2] = 0;
    testowy_wyznacznik[1][3] = 0;

    testowy_wyznacznik[2][0] = 0;
    testowy_wyznacznik[2][1] = 0;
    testowy_wyznacznik[2][2] = 3;
    testowy_wyznacznik[2][3] = 0;

    testowy_wyznacznik[3][0] = 2;
    testowy_wyznacznik[3][1] = 0;
    testowy_wyznacznik[3][2] = 0;
    testowy_wyznacznik[3][3] = 4;

    cout<< wyznacznik_4_4(testowy_wyznacznik,0,0)<<endl;


//    int tab_test_1[2] = { 5,17  };
//    int tab_test_2[2] = { 18,10  };
//    int tab_test_3[2] = { -30,-1  };
//
//    obcinanie_wektorow_all(tab_test_1,tab_test_2,tab_test_3,16,czy_wyszla_bryla_poza);
//
//    cout<< czy_wyszla_bryla_poza<<endl;
//    cout<<endl;
//    cout<< tab_test_1[0]<<endl;
//    cout<< tab_test_1[1]<<endl;
//    cout<<endl;
//    cout<< tab_test_2[0]<<endl;
//    cout<< tab_test_2[1]<<endl;
//    cout<<endl;
//    cout<< tab_test_3[0]<<endl;
//    cout<< tab_test_3[1]<<endl;
//    cout<<endl;
//    cout<<endl;
//    cout<<endl;
//    cout<<endl;
    // zmienne do operacji

    char kod_operacji = 'x';

    short wektor_x_kierunek=0;
    short wektor_y_kierunek=0;
    short wektor_z_kierunek=0;



    // ogolne
    int poziom_w=-1;
    int pion_w=-1;
    int panel_w=-1;

    int tab_wysokosc[2]={};
    int tab_szerokosc[2]={};
    int tab_glebokosc[2]={};

    // czworoscian
    int dlg_e = 0;

    // prostopadloscian
    int wys_p = -1;
    int szer_p = -1;
    int glebokosc_p = -1;

    // kula
    int dlg_r = 0;

    // wyznacznik
    char ktory_poziom_pion_panel='x';
    int iii_det = -1;

    // czy wyszla bryla poza szescian danych
    short czy_wyszlo = 0;
    short czy_wyszlo_2=0;


    int wymiar_bryly=3;

    long long int suma_punktow_bryly_odp = 0;
    int ilosc_puntkow_bryly_w_szescianie=0;

    int i = 0;
    int j = 0;
    int k = 0;

    int i_2=0;  // okreslenie poczatku i konca bryly w petli
    int j_2=0;
    int k_2=0;




    short oryginalne_wspolrzedne_bryly[3]={0,0,0};



    int dlg_kraw= 0 ;
    cin >> dlg_kraw;

    const int dlg_kraw_const = dlg_kraw;


    //long long int tab_wyznacznik_nowa_tabela[dlg_kraw_const][dlg_kraw_const] = {};

    int objetosc_szescianu = dlg_kraw*dlg_kraw*dlg_kraw;

    int tab_szescian_wyznacznik[32][32] = {0};

    int tablica_szescian[32][32][32]={};
    //int tablica_szescian[dlg_kraw_const][dlg_kraw_const][dlg_kraw_const]={};




//    for ( int i = 0; i< objetosc_szescianu;++i )
//    {
//
//
//
//    }

    // i to glebokosc
    // j t wysokosc
    // k to szerokosc
    //
    //  A NIE
    //
    // i to wysokosc
    // j t szerokosc
    // k to glebokosc

    int temp_wartosc_o_1_wieksza = 1;
    while (i < dlg_kraw_const )
    {
        j=0;
        while ( j < dlg_kraw_const )
        {
            k=0;
            while (k < dlg_kraw_const )
            {
                //cin >> temp_wartosci_pkt;
                //tablica_szescian[i][j][k] = temp_wartosci_pkt;
                tablica_szescian[i][j][k] = temp_wartosc_o_1_wieksza;
                temp_wartosc_o_1_wieksza+=1;
                k++;
            }
            j++;
        }
        i++;
    }
    cout<< " koniec koniec koniec   " << endl;
    //temp_wartosc_o_1_wieksza-=1;
    cout<<endl;
    for ( int i = 0; i< dlg_kraw;++i )
    {
    cout<<"glebokosc : " << i << endl;
        for ( int j = 0; j< dlg_kraw;++j )
        {
            cout << endl;
            for ( int k = 0; k< dlg_kraw;++k )
            {
                cout<< " [j][k] " << j<<" "<<k<<" " << " ____ "<<tablica_szescian[i][j][k] <<" ____ " <<" ";
            }
        }
        cout<<endl;
        cout<< " koniec plaszczyzny  nr : "<< i <<endl;
        cout<<endl;
    }

    while ( kod_operacji != 'E' )
    {

        cin >> kod_operacji;


        oryginalne_wspolrzedne_bryly[0]=0;
        oryginalne_wspolrzedne_bryly[1]=0;
        oryginalne_wspolrzedne_bryly[2]=0;

        wektor_x_kierunek=1;
        wektor_y_kierunek=1;
        wektor_z_kierunek=1;


        poziom_w=0;
        pion_w=0;
        panel_w=0;

        dlg_e = 0;
        dlg_r = 0;

        tab_wysokosc[0] = 0;
        tab_wysokosc[1] = 0;

        tab_szerokosc[0] = 0;
        tab_szerokosc[1] = 0;

        tab_glebokosc[0] = 0;
        tab_glebokosc[1] = 0;

        wys_p = 0;
        szer_p = 0;
        glebokosc_p = 0;

        ktory_poziom_pion_panel='x';
        iii_det = 0;

        // okreslenie wierzcholka
        cin >> poziom_w ;
        cin >> pion_w;
        cin >> panel_w;

        oryginalne_wspolrzedne_bryly[0]=poziom_w;
        oryginalne_wspolrzedne_bryly[1]=pion_w;
        oryginalne_wspolrzedne_bryly[2]=panel_w;

        tab_wysokosc[0]=poziom_w;
        tab_szerokosc[0]=pion_w;
        tab_glebokosc[0]=panel_w;

        czy_wyszlo = 0;
        czy_wyszlo_2=0;


        suma_punktow_bryly_odp = 0;
        ilosc_puntkow_bryly_w_szescianie=0;

        i=0;
        j=0;
        k=0;

        i_2=0;  // okreslenie poczatku i konca bryly w petli
        j_2=0;  // wszystko jest juz odwrocone
        k_2=0;

        czy_wyszlo_2=0;


        if ( kod_operacji == 'T' ) // czoworscian
        {

            cin >> dlg_e;

            if ( dlg_e == 0 )
            {
                czy_wyszlo = 1;
            } else
            {

                if ( tab_wysokosc[0] >= dlg_kraw/2 )
                {
                    tab_wysokosc[1] = tab_wysokosc[0] +1 - dlg_e ;

                } else if ( tab_wysokosc[0] < dlg_kraw/2  )
                {
                    tab_wysokosc[1] = tab_wysokosc[0] + dlg_e - 1;
                }

                if ( tab_szerokosc[0] >= dlg_kraw/2 )
                {
                    tab_szerokosc[1] = tab_szerokosc[0] - dlg_e + 1;

                } else if ( tab_szerokosc[0] < dlg_kraw/2  )
                {
                    tab_szerokosc[1] = tab_szerokosc[0] + dlg_e - 1;
                }

                if ( tab_glebokosc[0] >= dlg_kraw/2 )
                {
                    tab_glebokosc[1] = tab_glebokosc[0] - dlg_e + 1 ;

                } else if ( tab_glebokosc[0] < dlg_kraw/2  )
                {
                    tab_glebokosc[1] = tab_glebokosc[0] + dlg_e - 1;
                }

            }

            if ( tab_wysokosc[0] > tab_wysokosc[1] )
            {
                wektor_x_kierunek = -1;
            }
            if ( tab_szerokosc[0] > tab_szerokosc[1] )
            {
                wektor_y_kierunek = -1;
            }
            if ( tab_glebokosc[0] > tab_glebokosc[1] )
            {
                wektor_z_kierunek = -1;
            }



            czy_wyszlo_2 = czy_wyszly_wektory_all(tab_wysokosc,tab_szerokosc,tab_glebokosc,dlg_kraw_const);

            if ( czy_wyszlo == 1 )
            {
                suma_punktow_bryly_odp = 0;
            } else if ( czy_wyszlo == 0 )
            {


                i = tab_glebokosc[0];
                i_2 = tab_glebokosc[1];

                j = tab_wysokosc[0];
                j_2 = tab_wysokosc[1];

                k = tab_szerokosc[0];
                k_2 = tab_szerokosc[1];


                    if (czy_wyszlo == 0 && czy_wyszlo_2 == 0)
                    {
                        while (i <= i_2)  // niewiadomo czy mniejsze badz rowne czy mneijsze bo nie wiadomo co naezy do punktu
                        {
                            j = tab_wysokosc[0];

                            while (j <= j_2)
                            {
                                k = tab_szerokosc[0];

                                while (k <= k_2)
                                {
                                    suma_punktow_bryly_odp += tablica_szescian[i][j][k];
                                    ilosc_puntkow_bryly_w_szescianie += 1;

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
            }

            cout<< suma_punktow_bryly_odp<<endl;

        } else if ( kod_operacji == 'C' ) // prostopadlsocian
        {



            cin >>wys_p ;
            cin >>szer_p ;
            cin >>glebokosc_p ;

            // bryla o wysokosci jeden ma dwa punkty w szescianie danych
            // bryla o szerokosci dwa ma trzy punkty w szescianie danych

            ilosc_puntkow_bryly_w_szescianie=0;
            suma_punktow_bryly_odp=0;




            if ( wys_p==0 || szer_p == 0 || glebokosc_p == 0 )
            {
                czy_wyszlo = 1;
            } else {


                if (tab_wysokosc[0] >= dlg_kraw / 2) {
                    tab_wysokosc[1] = tab_wysokosc[0] - wys_p+1;

                } else if (tab_wysokosc[0] < dlg_kraw / 2) {
                    tab_wysokosc[1] = tab_wysokosc[0] + wys_p-1;
                }
                //
                if (tab_szerokosc[0] >= dlg_kraw / 2) {
                    tab_szerokosc[1] = tab_szerokosc[0] - szer_p+1;


                } else if (tab_szerokosc[0] < dlg_kraw / 2) {
                    tab_szerokosc[1] = tab_szerokosc[0] + szer_p-1;
                }
                //
                if (tab_glebokosc[0] >= dlg_kraw / 2) {
                    tab_glebokosc[1] = tab_glebokosc[0] - glebokosc_p+1;

                } else if (tab_glebokosc[0] < dlg_kraw / 2) {
                    tab_glebokosc[1] = tab_glebokosc[0] + glebokosc_p-1;
                }

            }
            czy_wyszlo_2 = obcinanie_wektorow_all(tab_wysokosc,tab_szerokosc,tab_glebokosc,dlg_kraw_const);
            cout<<"czy wyszlooooooooooo" <<endl;


            cout<< endl;
            cout<< tab_wysokosc[0]<< endl;
            cout<< tab_wysokosc[1]<< endl;
            cout<< endl;
            cout<< tab_szerokosc[0]<< endl;
            cout<< tab_szerokosc[1]<< endl;
            cout<< endl;
            cout<< tab_glebokosc[0]<< endl;
            cout<< tab_glebokosc[1]<< endl;
            cout<<" ----------------------------------"<<endl;
            cout<< " przeszlo 2  " <<endl;


            cout<<"czy wyszlooooooooooo" <<endl;


            cout<<" ----------------------------------"<<endl;

            cout<< endl;
            cout<< tab_wysokosc[0]<< endl;
            cout<< tab_wysokosc[1]<< endl;
            cout<< endl;
            cout<< tab_szerokosc[0]<< endl;
            cout<< tab_szerokosc[1]<< endl;
            cout<< endl;
            cout<< tab_glebokosc[0]<< endl;
            cout<< tab_glebokosc[1]<< endl;
            cout<<" ----------------------------------"<<endl;
            cout<< " przeszlo 2  " <<endl;

            if ( czy_wyszlo == 1 )
            {
                suma_punktow_bryly_odp = 0;
            } else if ( czy_wyszlo == 0 )
            {

                if ( wymiar_bryly == 0 )
                {

                    tablica_szescian[tab_glebokosc[0]][tab_wysokosc[0]][tab_szerokosc[0]];
                } else {


                    cout << " przeszlo 3  " << endl;

                    i = tab_glebokosc[0];
                    i_2 = tab_glebokosc[1];

                    j = tab_wysokosc[0];
                    j_2 = tab_wysokosc[1];

                    k = tab_szerokosc[0];
                    k_2 = tab_szerokosc[1];


                    cout << endl;


                    cout << "---------------------------" << endl;
                    cout << i << endl;
                    cout << i_2 << endl;
                    cout << endl;
                    cout << j << endl;
                    cout << j_2 << endl;
                    cout << endl;
                    cout << k << endl;
                    cout << k_2 << endl;
                    cout << "--------------------------" << endl;
                    cout << endl;
                    cout << endl;

                    if (czy_wyszlo == 0 && czy_wyszlo_2 == 0)
                    {
                        while (i <= i_2)  // niewiadomo czy mniejsze badz rowne czy mneijsze bo nie wiadomo co naezy do punktu
                        {

                            while (j <= j_2)
                            {

                                while (k <= k_2)
                                {

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

            }

            cout<< suma_punktow_bryly_odp<<endl;


        } else if ( kod_operacji == 'O' ) // kula daje fula
        {



            cin >>dlg_r ;

            if ( dlg_r == 0 )
            {

                czy_wyszlo = 1;

            }else {


                if (tab_wysokosc[0] >= dlg_kraw / 2) {
                    tab_wysokosc[1] = tab_wysokosc[0] - dlg_r+1;

                } else if (tab_wysokosc[0] < dlg_kraw / 2) {
                    tab_wysokosc[1] = tab_wysokosc[0] + dlg_r-1;
                }
                //
                if (tab_szerokosc[0] >= dlg_kraw / 2) {
                    tab_szerokosc[1] = tab_szerokosc[0] - dlg_r+1;

                } else if (tab_szerokosc[0] < dlg_kraw / 2) {
                    tab_szerokosc[1] = tab_szerokosc[0] + dlg_r-1;
                }
                //
                if (tab_glebokosc[0] >= dlg_kraw / 2) {
                    tab_glebokosc[1] = tab_glebokosc[0] - dlg_r+1;

                } else if (tab_glebokosc[0] < dlg_kraw / 2) {
                    tab_glebokosc[1] = tab_glebokosc[0] + dlg_r-1;
                }
            }

            if ( tab_wysokosc[0] > tab_wysokosc[1] )
            {
                wektor_x_kierunek = -1;
            }
            if ( tab_szerokosc[0] > tab_szerokosc[1] )
            {
                wektor_y_kierunek = -1;
            }
            if ( tab_glebokosc[0] > tab_glebokosc[1] )
            {
                wektor_z_kierunek = -1;
            }



            czy_wyszlo_2 = czy_wyszly_wektory_all(tab_wysokosc,tab_szerokosc,tab_glebokosc,dlg_kraw_const);




            if ( czy_wyszlo == 1 )
            {
                suma_punktow_bryly_odp = 0;
            } else if ( czy_wyszlo == 0 ) {


                i = tab_glebokosc[0];
                i_2 = tab_glebokosc[1];

                j = tab_wysokosc[0];
                j_2 = tab_wysokosc[1];

                k = tab_szerokosc[0];
                k_2 = tab_szerokosc[1];


                if (czy_wyszlo == 0 && czy_wyszlo_2 == 0)
                {
                    while (i <=i_2)  // niewiadomo czy mniejsze badz rowne czy mneijsze bo nie wiadomo co naezy do punktu
                    {
                        j = tab_wysokosc[0];

                        while (j <= j_2) {

                            k = tab_szerokosc[0];
                            while (k <= k_2) {

                                suma_punktow_bryly_odp += tablica_szescian[i][j][k];
                                ilosc_puntkow_bryly_w_szescianie += 1;

                                k += 1;
                            }

                            k_2 = tab_szerokosc[1] - 1;
                            j += 1;
                        }
                        j_2 = tab_wysokosc[1] - 1;
                        i += 1;
                    }
                    i = 0;
                    j = 0;
                    k = 0;

                }

            }

            cout<< suma_punktow_bryly_odp<<endl;

        } else if ( kod_operacji == 'D' )
        {



            cin >> ktory_poziom_pion_panel;
            cin >> iii_det;

            if ( ktory_poziom_pion_panel == 'l' )
            {


                for (int i = 0; i< dlg_kraw_const;++i)
                {
                    for ( int j =0;j<dlg_kraw_const;++j)
                    {
                        tab_szescian_wyznacznik[i][j] = tablica_szescian[i][iii_det][j];
                    }
                }

            }else if (ktory_poziom_pion_panel == 'v')
            {


                for (int i = 0; i< dlg_kraw_const;++i)
                {

                    for ( int j =0;j<dlg_kraw_const;++j)
                    {
                        tab_szescian_wyznacznik[i][j] = tablica_szescian[i][j][iii_det];
                    }
                }


            } else if ( ktory_poziom_pion_panel == 'p' )
            {


                for (int i = 0; i< dlg_kraw_const;++i)
                {
                    for ( int j =0;j<dlg_kraw_const;++j)
                    {
                        tab_szescian_wyznacznik[i][j] = tablica_szescian[iii_det][i][j];
                    }
                }



            }









        }

    }




    cout << "Hello, World!" << endl;

    return 0;
}
