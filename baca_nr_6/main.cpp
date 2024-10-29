//Marcin Sztukowski

#include <iostream>

using namespace std;


struct place{

    unsigned short ilosc_towaru = 0;
    char etykieta[2] = {'\0','\0'};


};

struct shelf{

    place tab_shelf_place[128];
    short ile_miejsc=0;


};


struct rack{

    shelf tab_rack_shelf[128];
    short ile_polek=0;

};

struct warehouse{

    rack tab_warehouse_rack[128];
    shelf tab_poreczna_polka_warehouse;

    short ile_regalow = 0 ;

};


warehouse tab_sklad_towaru_warehouse[128];


rack tab_poreczny_regal_sklad_towaru;
shelf tab_poreczna_polka_sklad_towaru;
short ile_magazynow=0;
long long int suma_wszystkich_towarow = 0;



void set_ap( int wb, int rb, int sb, int pe ) // w magazynie nr w regale nr w polce nr ustawia ilosc miejsc pe
{

    if ( wb > 127 || wb < 0 || ile_magazynow <= wb || rb > 127 || rb < 0 || tab_sklad_towaru_warehouse[wb].ile_regalow <= rb || sb > 127 || sb < 0 || tab_sklad_towaru_warehouse[wb].tab_warehouse_rack[rb].ile_polek <= sb || pe > 128 || pe < 0  )
    {
        cout<<"error"<<endl;
    } else
    {
        if ( pe > tab_sklad_towaru_warehouse[wb].tab_warehouse_rack[rb].tab_rack_shelf[sb].ile_miejsc  )
        {
            for (int i = tab_sklad_towaru_warehouse[wb].tab_warehouse_rack[rb].tab_rack_shelf[sb].ile_miejsc ; i < pe ; i++)
            {

                tab_sklad_towaru_warehouse[wb].tab_warehouse_rack[rb].tab_rack_shelf[sb].tab_shelf_place[i].ilosc_towaru = 0;
                tab_sklad_towaru_warehouse[wb].tab_warehouse_rack[rb].tab_rack_shelf[sb].tab_shelf_place[i].etykieta[0] = '\0';
                tab_sklad_towaru_warehouse[wb].tab_warehouse_rack[rb].tab_rack_shelf[sb].tab_shelf_place[i].etykieta[1] = '\0';

            }
            tab_sklad_towaru_warehouse[wb].tab_warehouse_rack[rb].tab_rack_shelf[sb].ile_miejsc = pe ;

        } else if ( pe < tab_sklad_towaru_warehouse[wb].tab_warehouse_rack[rb].tab_rack_shelf[sb].ile_miejsc )
        {
            tab_sklad_towaru_warehouse[wb].tab_warehouse_rack[rb].tab_rack_shelf[sb].ile_miejsc = pe;
        }


    }

}

void set_as( int wb , int rb , int se , int pe  )
{

    if ( wb > 127 || wb < 0 || ile_magazynow <= wb || rb > 127 || rb < 0 || tab_sklad_towaru_warehouse[wb].ile_regalow <= rb || se > 128 || se < 0 || pe > 128 || pe < 0)
    {
        cout<<"error"<<endl;
    } else
    {

        if ( se > tab_sklad_towaru_warehouse[wb].tab_warehouse_rack[wb].ile_polek )
        {
            for (int i = tab_sklad_towaru_warehouse[wb].tab_warehouse_rack[rb].ile_polek ; i < se ; i++ )
            {
                tab_sklad_towaru_warehouse[wb].tab_warehouse_rack[rb].tab_rack_shelf[i].ile_miejsc = pe ;
                for ( int j = 0; j < pe ; j++ )
                {
                    tab_sklad_towaru_warehouse[wb].tab_warehouse_rack[rb].tab_rack_shelf[i].tab_shelf_place[j].ilosc_towaru = 0 ;
                    tab_sklad_towaru_warehouse[wb].tab_warehouse_rack[rb].tab_rack_shelf[i].tab_shelf_place[j].etykieta[0] = '\0' ;
                    tab_sklad_towaru_warehouse[wb].tab_warehouse_rack[rb].tab_rack_shelf[i].tab_shelf_place[j].etykieta[1] = '\0' ;

                }
            }

            for ( int i = 0 ; i < tab_sklad_towaru_warehouse[wb].tab_warehouse_rack[rb].ile_polek ; i++ )
            {
                set_ap(wb,rb,i,pe );
            }

            tab_sklad_towaru_warehouse[wb].tab_warehouse_rack[rb].ile_polek = se ;



        } else if (  se < tab_sklad_towaru_warehouse[wb].tab_warehouse_rack[wb].ile_polek )
        {

            for ( int i = 0 ; i < se ; i++ )
            {
                set_ap(wb,rb,i,pe );
            }
            tab_sklad_towaru_warehouse[wb].tab_warehouse_rack[rb].ile_polek = se ;

        } else
        {
            for ( int i = 0 ; i < se ; i++ )
            {
                set_ap(wb,rb,i,pe );
            }
        }

    }



}

void set_ar(int wb, int re, int se, int pe)
{

    if ( wb > 127 || wb <  0 || ile_magazynow <= wb || re > 128 || re < 0 || se > 128 || se < 0 || pe > 128 || pe < 0  )
    {
        cout<<"error"<<endl;
    } else
    {

        if ( re > tab_sklad_towaru_warehouse[wb].ile_regalow  )
        {
            for ( int i = tab_sklad_towaru_warehouse[wb].ile_regalow ; i < re ; i++ )
            {
                for ( int j = 0 ; j < se ; j++ )
                {
                    for ( int k = 0 ; k < pe ; k++ )
                    {
                        tab_sklad_towaru_warehouse[wb].tab_warehouse_rack[i].tab_rack_shelf[j].tab_shelf_place[k].ilosc_towaru = 0 ;
                        tab_sklad_towaru_warehouse[wb].tab_warehouse_rack[i].tab_rack_shelf[j].tab_shelf_place[k].etykieta[0] = '\0' ;
                        tab_sklad_towaru_warehouse[wb].tab_warehouse_rack[i].tab_rack_shelf[j].tab_shelf_place[k].etykieta[1] = '\0' ;
                    }
                    tab_sklad_towaru_warehouse[wb].tab_warehouse_rack[i].tab_rack_shelf[j].ile_miejsc = pe ;
                }
                tab_sklad_towaru_warehouse[wb].tab_warehouse_rack[i].ile_polek = se ;
            }

            for ( int i = 0 ; i < tab_sklad_towaru_warehouse[wb].ile_regalow ; i++  )
            {
                set_as(wb,i,se,pe);
            }

            tab_sklad_towaru_warehouse[wb].ile_regalow = re ;

        } else if ( re < tab_sklad_towaru_warehouse[wb].ile_regalow )
        {

            for ( int i = 0 ; i < re ; i++  )
            {
                set_as(wb,i,se,pe);
            }

            tab_sklad_towaru_warehouse[wb].ile_regalow = re ;

        } else
        {
            for ( int i = 0 ; i < re ; i++  )
            {
                set_as(wb,i,se,pe);
            }

        }
    }
}



void set_aw(short we, short re , short se, short pe)
{

    if ( we > 128 || we < 0 || re > 128 || re < 0 || se > 128 || se < 0 || pe > 128 || pe < 0 )
    {
        cout<<"error"<<endl;
    } else
    {

        if ( we > ile_magazynow )
        {

            for (int i = ile_magazynow ; i < we ; i++)
            {
                for (int j = 0 ; j < re ; j++ )
                {
                    for (int k = 0 ; k < se ; k++)
                    {
                        for (int l = 0 ; l < pe ; l++ )
                        {
                            tab_sklad_towaru_warehouse[i].tab_warehouse_rack[j].tab_rack_shelf[k].tab_shelf_place[l].ilosc_towaru = 0;
                            tab_sklad_towaru_warehouse[i].tab_warehouse_rack[j].tab_rack_shelf[k].tab_shelf_place[l].etykieta[0] = '\0';
                            tab_sklad_towaru_warehouse[i].tab_warehouse_rack[j].tab_rack_shelf[k].tab_shelf_place[l].etykieta[1] = '\0';
                        }
                        tab_sklad_towaru_warehouse[i].tab_warehouse_rack[j].tab_rack_shelf[k].ile_miejsc = pe ;
                    }
                    tab_sklad_towaru_warehouse[i].tab_warehouse_rack[j].ile_polek = se ;
                }
                tab_sklad_towaru_warehouse[i].ile_regalow = re ;
            }

            for (int i = 0 ; i < ile_magazynow ; i++ )
            {
                set_ar(i,re,se,pe);
            }

            ile_magazynow = we ;

        } else if ( we < ile_magazynow )
        {

            for (int i = 0 ; i < we ; i++ )
            {
                set_ar(i,re,se,pe);
            }

            ile_magazynow = we ;

        } else
        {

            for (int i = 0 ; i < we ; i++ )
            {
                set_ar(i,re,se,pe);
            }

            ile_magazynow = we ;
        }

    }

}



void set_hw(int w , int p)
{

    if ( w < 0 || w > 127 || ile_magazynow <= w || p > 128 || p < 0 )
    {
        cout<<"error"<<endl;
    } else
    {

        if ( p > tab_sklad_towaru_warehouse[w].tab_poreczna_polka_warehouse.ile_miejsc  )
        {

            for ( int i = tab_sklad_towaru_warehouse[w].tab_poreczna_polka_warehouse.ile_miejsc ; i < p ; i++ )
            {
                tab_sklad_towaru_warehouse[w].tab_poreczna_polka_warehouse.tab_shelf_place[i].ilosc_towaru = 0 ;
                tab_sklad_towaru_warehouse[w].tab_poreczna_polka_warehouse.tab_shelf_place[i].etykieta[0] = '\0' ;
                tab_sklad_towaru_warehouse[w].tab_poreczna_polka_warehouse.tab_shelf_place[i].etykieta[1] = '\0' ;
            }

            tab_sklad_towaru_warehouse[w].tab_poreczna_polka_warehouse.ile_miejsc = p ;

        } else if ( p < tab_sklad_towaru_warehouse[w].tab_poreczna_polka_warehouse.ile_miejsc )
        {

            tab_sklad_towaru_warehouse[w].tab_poreczna_polka_warehouse.ile_miejsc = p;

        }

    }


}

void set_hr(int s , int p)
{
    if ( s > 128 || s < 0 || p > 128 || p < 0 )
    {
        cout<< "error" <<endl;
    } else
    {

        if ( s > tab_poreczny_regal_sklad_towaru.ile_polek )
        {

            for ( int i = tab_poreczny_regal_sklad_towaru.ile_polek ; i < s ; i++ )
            {

                for (int j = 0 ; j < p ; j++)
                {

                    tab_poreczny_regal_sklad_towaru.tab_rack_shelf[i].tab_shelf_place[j].ilosc_towaru = 0;
                    tab_poreczny_regal_sklad_towaru.tab_rack_shelf[i].tab_shelf_place[j].etykieta[0] = '\0';
                    tab_poreczny_regal_sklad_towaru.tab_rack_shelf[i].tab_shelf_place[j].etykieta[1] = '\0';

                }
                tab_poreczny_regal_sklad_towaru.tab_rack_shelf[i].ile_miejsc = p;
            }


            for ( int i = 0 ; i < tab_poreczny_regal_sklad_towaru.ile_polek ; i++ )
            {

                if ( p > tab_poreczny_regal_sklad_towaru.tab_rack_shelf[i].ile_miejsc )
                {


                    for ( int j = tab_poreczny_regal_sklad_towaru.tab_rack_shelf[i].ile_miejsc ; j < p ; j++ )
                    {
                        tab_poreczny_regal_sklad_towaru.tab_rack_shelf[i].tab_shelf_place[j].ilosc_towaru = 0 ;
                        tab_poreczny_regal_sklad_towaru.tab_rack_shelf[i].tab_shelf_place[j].etykieta[0] = '\0' ;
                        tab_poreczny_regal_sklad_towaru.tab_rack_shelf[i].tab_shelf_place[j].etykieta[1] = '\0' ;
                    }
                    tab_poreczny_regal_sklad_towaru.tab_rack_shelf[i].ile_miejsc = p;

                } else if ( p < tab_poreczny_regal_sklad_towaru.tab_rack_shelf[i].ile_miejsc )
                {
                    tab_poreczny_regal_sklad_towaru.tab_rack_shelf[i].ile_miejsc = p;
                }

            }


            tab_poreczny_regal_sklad_towaru.ile_polek = s ;

        } else if ( s < tab_poreczny_regal_sklad_towaru.ile_polek )
        {


            for ( int i = 0 ; i < s ; i++ )
            {

                if ( p > tab_poreczny_regal_sklad_towaru.tab_rack_shelf[i].ile_miejsc )
                {


                    for ( int j = tab_poreczny_regal_sklad_towaru.tab_rack_shelf[i].ile_miejsc ; j < p ; j++ )
                    {
                        tab_poreczny_regal_sklad_towaru.tab_rack_shelf[i].tab_shelf_place[j].ilosc_towaru = 0 ;
                        tab_poreczny_regal_sklad_towaru.tab_rack_shelf[i].tab_shelf_place[j].etykieta[0] = '\0' ;
                        tab_poreczny_regal_sklad_towaru.tab_rack_shelf[i].tab_shelf_place[j].etykieta[1] = '\0' ;
                    }
                    tab_poreczny_regal_sklad_towaru.tab_rack_shelf[i].ile_miejsc = p;

                } else if ( p < tab_poreczny_regal_sklad_towaru.tab_rack_shelf[i].ile_miejsc )
                {
                    tab_poreczny_regal_sklad_towaru.tab_rack_shelf[i].ile_miejsc = p;
                }

            }


            tab_poreczny_regal_sklad_towaru.ile_polek = s ;

        } else
        {

            for ( int i = 0 ; i < s ; i++ )
            {

                if ( p > tab_poreczny_regal_sklad_towaru.tab_rack_shelf[i].ile_miejsc )
                {


                    for ( int j = tab_poreczny_regal_sklad_towaru.tab_rack_shelf[i].ile_miejsc ; j < p ; j++ )
                    {
                        tab_poreczny_regal_sklad_towaru.tab_rack_shelf[i].tab_shelf_place[j].ilosc_towaru = 0 ;
                        tab_poreczny_regal_sklad_towaru.tab_rack_shelf[i].tab_shelf_place[j].etykieta[0] = '\0' ;
                        tab_poreczny_regal_sklad_towaru.tab_rack_shelf[i].tab_shelf_place[j].etykieta[1] = '\0' ;
                    }
                    tab_poreczny_regal_sklad_towaru.tab_rack_shelf[i].ile_miejsc = p;

                } else if ( p < tab_poreczny_regal_sklad_towaru.tab_rack_shelf[i].ile_miejsc )
                {
                    tab_poreczny_regal_sklad_towaru.tab_rack_shelf[i].ile_miejsc = p;
                }

            }


        }

    }



}

void set_hs(int p)
{
    if ( p > 128 || p < 0 )
    {
        cout<<"error"<<endl;
    } else
    {
        if ( p > tab_poreczna_polka_sklad_towaru.ile_miejsc )
        {

            for ( int i = tab_poreczna_polka_sklad_towaru.ile_miejsc ; i < p ; i++ )
            {
                tab_poreczna_polka_sklad_towaru.tab_shelf_place[i].ilosc_towaru = 0 ;
                tab_poreczna_polka_sklad_towaru.tab_shelf_place[i].etykieta[0] = '\0' ;
                tab_poreczna_polka_sklad_towaru.tab_shelf_place[i].etykieta[1] = '\0' ;
            }
            tab_poreczna_polka_sklad_towaru.ile_miejsc = p ;

        } else if ( p < tab_poreczna_polka_sklad_towaru.ile_miejsc )
        {
            tab_poreczna_polka_sklad_towaru.ile_miejsc = p;
        }


    }


}



void set_ap2( short wb, short rb, short sb, short pe )
{
    if (wb > 127 || wb < 0 || rb > 127 || rb < 0 || sb > 127 || sb < 0 || pe > 128 || pe < 0 || ile_magazynow <= wb || tab_sklad_towaru_warehouse[wb].ile_regalow <= rb || tab_sklad_towaru_warehouse[wb].tab_warehouse_rack[rb].ile_polek <= sb   )
    {

        // || ile_magazynow == 0 || tab_sklad_towaru_warehouse[wb].ile_regalow == 0 || tab_sklad_towaru_warehouse[wb].tab_warehouse_rack[rb].ile_polek == 0
        cout << "error" << endl;
    }else
    {
        short i =0;

        if ( pe < tab_sklad_towaru_warehouse[wb].tab_warehouse_rack[rb].tab_rack_shelf[sb].ile_miejsc )
        {

            tab_sklad_towaru_warehouse[wb].tab_warehouse_rack[rb].tab_rack_shelf[i].ile_miejsc = pe;

        } else if ( pe > tab_sklad_towaru_warehouse[wb].tab_warehouse_rack[rb].tab_rack_shelf[sb].ile_miejsc )
        {

            i = tab_sklad_towaru_warehouse[wb].tab_warehouse_rack[rb].tab_rack_shelf[sb].ile_miejsc;
            while ( i < pe )
            {

                tab_sklad_towaru_warehouse[wb].tab_warehouse_rack[rb].tab_rack_shelf[sb].tab_shelf_place[i].ilosc_towaru = 0 ;
                tab_sklad_towaru_warehouse[wb].tab_warehouse_rack[rb].tab_rack_shelf[sb].tab_shelf_place[i].etykieta[0] = '\0';
                tab_sklad_towaru_warehouse[wb].tab_warehouse_rack[rb].tab_rack_shelf[sb].tab_shelf_place[i].etykieta[1] = '\0';

                ++i;
            }
            tab_sklad_towaru_warehouse[wb].tab_warehouse_rack[rb].tab_rack_shelf[sb].ile_miejsc = pe;
        }
    }
}


void set_aw2(short we, short re , short se, short pe)
{

    if (we > 128 || we < 0 || re > 128 || re < 0 || se > 128 || se < 0 || pe > 128 || pe < 0) {
        cout << "error" << endl;
    } else
    {
        if (we > ile_magazynow)
        {

            short i = ile_magazynow ;
            short i_2 = we;

            short j = 0;
            short j_2 = re;

            short k = 0;
            short k_2 = se;

            short l = 0;
            short l_2 = pe;



            ile_magazynow = we;
            while ( i< i_2 )
            {
                tab_sklad_towaru_warehouse[i].ile_regalow = re;
                while ( j < j_2 )
                {
                    tab_sklad_towaru_warehouse[i].tab_warehouse_rack[j].ile_polek = se;
                    while ( k < k_2 )
                    {

                        tab_sklad_towaru_warehouse[i].tab_warehouse_rack[j].tab_rack_shelf[k].ile_miejsc = pe;
                        while ( l < l_2 )
                        {

                            tab_sklad_towaru_warehouse[i].tab_warehouse_rack[j].tab_rack_shelf[k].tab_shelf_place[l].etykieta[0]='\0';
                            tab_sklad_towaru_warehouse[i].tab_warehouse_rack[j].tab_rack_shelf[k].tab_shelf_place[l].etykieta[1]='\0';

                            tab_sklad_towaru_warehouse[i].tab_warehouse_rack[j].tab_rack_shelf[k].tab_shelf_place[l].ilosc_towaru = 0 ;

                            l++;

                        }
                        k++;

                    }
                    j++;

                }
                i++;
            }



            j=0;
            j_2 = we;


            ile_magazynow = we;
            while ( j < j_2 )
            {

                set_ar( j, re, se , pe );
                j++;
            }



        } else if ( we < ile_magazynow )
        {

            int j = 0;
            int j_2 = we;

            ile_magazynow = we;



            while ( j < j_2 )
            {

                set_ar( j, re, se , pe );
                j++;
            }


        } else // we == ile magazynow
        {




            int j=0;
            int j_2 = we;

            ile_magazynow = we;
            while ( j < j_2 )
            {

                set_ar( j, re, se , pe );
                j++;
            }


        }


    }

}



void put_w(int w ,int r,int s,int p,long long int a)
{

    if (w > 127 || w < 0 || r > 127 || r < 0 || s > 127 || s < 0 || p > 127 || p < 0 || ile_magazynow <= w || tab_sklad_towaru_warehouse[w].ile_regalow <= r || tab_sklad_towaru_warehouse[w].tab_warehouse_rack[r].ile_polek <= s || tab_sklad_towaru_warehouse[w].tab_warehouse_rack[r].tab_rack_shelf[s].ile_miejsc <= p   )
    {

        cout << "error" << endl;
    }else
    {

        long long int wynik = tab_sklad_towaru_warehouse[w].tab_warehouse_rack[r].tab_rack_shelf[s].tab_shelf_place[p].ilosc_towaru + a ;

        if ( wynik > 65535 )
        {
            wynik = 65535 ;
        }

        tab_sklad_towaru_warehouse[w].tab_warehouse_rack[r].tab_rack_shelf[s].tab_shelf_place[p].ilosc_towaru = wynik;

    }
}


void put_h(int w,int p, long long int a)
{
    if (w > 127 || w < 0  || p > 127 || p < 0  || ile_magazynow <= w || tab_sklad_towaru_warehouse[w].tab_poreczna_polka_warehouse.ile_miejsc <= p  )
    {

        // || ile_magazynow <= w || tab_sklad_towaru_warehouse[w].tab_poreczna_polka_warehouse.ile_miejsc <= p || a < 0
        cout << "error" << endl;
    }else {

        long long wynik = tab_sklad_towaru_warehouse[w].tab_poreczna_polka_warehouse.tab_shelf_place[p].ilosc_towaru + a ;

        if ( wynik > 65535 )
        {
            wynik = 65535 ;
        }

        tab_sklad_towaru_warehouse[w].tab_poreczna_polka_warehouse.tab_shelf_place[p].ilosc_towaru = wynik;

    }
}

void put_r(int s,int p, long long int a )
{
    if (s > 127 || s < 0  || p > 127 || p < 0 || tab_poreczny_regal_sklad_towaru.ile_polek <= s || tab_poreczny_regal_sklad_towaru.tab_rack_shelf[s].ile_miejsc <= p  )
    {
        cout << "error" << endl;
    }else {

        long long int wynik = tab_poreczny_regal_sklad_towaru.tab_rack_shelf[s].tab_shelf_place[p].ilosc_towaru + a ;

        if ( wynik > 65535 )
        {
            wynik = 65535 ;
        }

        wynik = tab_poreczny_regal_sklad_towaru.tab_rack_shelf[s].tab_shelf_place[p].ilosc_towaru = wynik;

    }
}


void put_s(int p, long long int a)
{
    if (  p > 127 || p < 0  || tab_poreczna_polka_sklad_towaru.ile_miejsc <= p )
    {
        cout << "error" << endl;
    }else {

        long long int wynik = tab_poreczna_polka_sklad_towaru.tab_shelf_place[p].ilosc_towaru + a ;

        if ( wynik > 65535 )
        {
            wynik = 65535 ;
        }

        tab_poreczna_polka_sklad_towaru.tab_shelf_place[p].ilosc_towaru = wynik;

    }
}


void pop_w( int w, int r, int s, int p, long long int a )
{
    if ( w > 127 || w < 0 || r < 0 || r > 127 || s > 127 || s < 0 || p > 127 || p < 0 || ile_magazynow <= w || tab_sklad_towaru_warehouse[w].ile_regalow <= r || tab_sklad_towaru_warehouse[w].tab_warehouse_rack[r].ile_polek <= s || tab_sklad_towaru_warehouse[w].tab_warehouse_rack[r].tab_rack_shelf[s].ile_miejsc <= p || ile_magazynow == 0 || tab_sklad_towaru_warehouse[w].ile_regalow == 0 || tab_sklad_towaru_warehouse[w].tab_warehouse_rack[r].ile_polek == 0 || tab_sklad_towaru_warehouse[w].tab_warehouse_rack[r].tab_rack_shelf[s].ile_miejsc == 0  )
    {
        cout<<"error"<<endl;
    } else
    {
        long long int wynik = tab_sklad_towaru_warehouse[w].tab_warehouse_rack[r].tab_rack_shelf[s].tab_shelf_place[p].ilosc_towaru - a ;

        if ( wynik < 0 )
        {
            wynik = 0;
        }

        tab_sklad_towaru_warehouse[w].tab_warehouse_rack[r].tab_rack_shelf[s].tab_shelf_place[p].ilosc_towaru = wynik ;

    }

}


void pop_h( int w, int p, long long int a )
{
    if ( w > 127 || w < 0 || p > 127 || p < 0 || ile_magazynow <= w || tab_sklad_towaru_warehouse[w].tab_poreczna_polka_warehouse.ile_miejsc <= p || a < 0 )
    {
        cout<<"error"<<endl;
    } else
    {
        long long int wynik = tab_sklad_towaru_warehouse[w].tab_poreczna_polka_warehouse.tab_shelf_place[p].ilosc_towaru - a ;

        if ( wynik < 0 )
        {
            wynik = 0;
        }

        tab_sklad_towaru_warehouse[w].tab_poreczna_polka_warehouse.tab_shelf_place[p].ilosc_towaru = wynik ;

    }

}



void pop_r( int s, int p, long long int a )
{
    if (   s > 127 || s < 0 || p > 127 || p < 0  || tab_poreczny_regal_sklad_towaru.ile_polek <= s || tab_poreczny_regal_sklad_towaru.tab_rack_shelf[s].ile_miejsc <= p  )
    {
        cout<<"error"<<endl;
    } else
    {

        long long int wynik = tab_poreczny_regal_sklad_towaru.tab_rack_shelf[s].tab_shelf_place[p].ilosc_towaru - a ;
        if ( wynik < 0 )
        {
            wynik = 0;
        }

        tab_poreczny_regal_sklad_towaru.tab_rack_shelf[s].tab_shelf_place[p].ilosc_towaru = wynik ;

    }

}


void pop_s(  int p, long long int a )
{
    if (  p > 127 || p < 0 || tab_poreczna_polka_sklad_towaru.ile_miejsc <= p )
    {
        cout<<"error"<<endl;
    } else
    {
        long long int wynik = tab_poreczna_polka_sklad_towaru.tab_shelf_place[p].ilosc_towaru - a ;

        if ( wynik < 0 )
        {
            wynik = 0;
        }

        tab_poreczna_polka_sklad_towaru.tab_shelf_place[p].ilosc_towaru = wynik ;

    }

}

void fill( int w,int r, int s,  int p, int a ) // zbadaj skrajne wartosci typu za duze a za male w lub r itd ...
{

    if ( w > 128 || w < 0 || r > 128 || r < 0 || s > 128 || s < 0 || p > 128 || p < 0 || a < 0 || a > 65535  ) // poreczny regal i poreczne polki maja teakie same bazowe wartosci
    {
        cout << "error" <<endl;
    } else {

        ile_magazynow = w;
        for (int i = 0; i < w; i++) {

            tab_sklad_towaru_warehouse[i].ile_regalow = r;
            for (int j = 0; j < r; j++)
            {
                tab_sklad_towaru_warehouse[i].tab_warehouse_rack[j].ile_polek = s;
                for (int k = 0; k < s; k++)
                {
                    tab_sklad_towaru_warehouse[i].tab_warehouse_rack[j].tab_rack_shelf[k].ile_miejsc = p;
                    for (int l = 0; l < p; l++)
                    {
                        tab_sklad_towaru_warehouse[i].tab_warehouse_rack[j].tab_rack_shelf[k].tab_shelf_place[l].ilosc_towaru = a; // 0
                        tab_sklad_towaru_warehouse[i].tab_warehouse_rack[j].tab_rack_shelf[k].tab_shelf_place[l].etykieta[0] = '\0';
                        tab_sklad_towaru_warehouse[i].tab_warehouse_rack[j].tab_rack_shelf[k].tab_shelf_place[l].etykieta[1] = '\0';

                    }
                }
            }
        }


        for ( int i = 0 ; i < ile_magazynow ; i++)
        {

            tab_sklad_towaru_warehouse[i].tab_poreczna_polka_warehouse.ile_miejsc = p;
            for ( int j = 0 ; j < tab_sklad_towaru_warehouse[i].tab_poreczna_polka_warehouse.ile_miejsc ; j++ )
            {

                tab_sklad_towaru_warehouse[i].tab_poreczna_polka_warehouse.tab_shelf_place[j].ilosc_towaru = a ;
                tab_sklad_towaru_warehouse[i].tab_poreczna_polka_warehouse.tab_shelf_place[j].etykieta[0] = '\0';
                tab_sklad_towaru_warehouse[i].tab_poreczna_polka_warehouse.tab_shelf_place[j].etykieta[1] = '\0';

            }

        }


        tab_poreczny_regal_sklad_towaru.ile_polek = s;
        for (int i = 0; i < s; i++) {

            tab_poreczny_regal_sklad_towaru.tab_rack_shelf[i].ile_miejsc = p;
            for (int j = 0; j < p; j++) {

                tab_poreczny_regal_sklad_towaru.tab_rack_shelf[i].tab_shelf_place[j].ilosc_towaru = a ; // 0
                tab_poreczny_regal_sklad_towaru.tab_rack_shelf[i].tab_shelf_place[j].etykieta[0] = '\0';
                tab_poreczny_regal_sklad_towaru.tab_rack_shelf[i].tab_shelf_place[j].etykieta[1] = '\0';

            }

        }

        tab_poreczna_polka_sklad_towaru.ile_miejsc = p;
        for (int i =0 ; i < p ; i++)
        {
            tab_poreczna_polka_sklad_towaru.tab_shelf_place[i].ilosc_towaru = a;
            tab_poreczna_polka_sklad_towaru.tab_shelf_place[i].etykieta[0] = '\0';
            tab_poreczna_polka_sklad_towaru.tab_shelf_place[i].etykieta[1] = '\0';

        }


    }

}


void mov_w(int wb , int rb, int sb , int we, int re, int se , int p , int a )
{

    
    if ( wb > 127 || wb < 0 || rb > 127 || rb < 0 || sb > 127 || sb < 0 || we > 127 || we < 0 || re > 127 || re < 0 || se > 127 || se < 0 || p < 0 || p > 127 || ile_magazynow <= wb || ile_magazynow <= we || tab_sklad_towaru_warehouse[wb].ile_regalow <= rb || tab_sklad_towaru_warehouse[we].ile_regalow <= re ||  tab_sklad_towaru_warehouse[wb].tab_warehouse_rack[rb].ile_polek <= sb || tab_sklad_towaru_warehouse[we].tab_warehouse_rack[re].ile_polek <= se   ||   tab_sklad_towaru_warehouse[wb].tab_warehouse_rack[rb].tab_rack_shelf[sb].ile_miejsc <= p || tab_sklad_towaru_warehouse[we].tab_warehouse_rack[re].tab_rack_shelf[se].ile_miejsc <= p    )
    {
        cout << "error"<<endl;
    } else
    {
        // int zabierz_tu = tab_sklad_towaru_warehouse[wb].tab_warehouse_rack[rb].tab_rack_shelf[sb].tab_shelf_place[p].ilosc_towaru ;
        // int dodaj_tu = tab_sklad_towaru_warehouse[we].tab_warehouse_rack[re].tab_rack_shelf[se].tab_shelf_place[p].ilosc_towaru ;


        if (wb != we || rb != re || sb != se)
        {
            //cout << "operacja nr 4 " <<endl;
            if (a > 65535)
            {
                a = 65535;
            }

            int x1 = 0;
            int x2 = 0;

            int ile_mozesz_wziac_1 = 0;
            int ile_mozesz_dodac_1 = 0;


            if (a <= tab_sklad_towaru_warehouse[wb].tab_warehouse_rack[rb].tab_rack_shelf[sb].tab_shelf_place[p].ilosc_towaru)
            {
                ile_mozesz_wziac_1 = a;
            } else // a > ilosc towaru
            {
                ile_mozesz_wziac_1 = tab_sklad_towaru_warehouse[wb].tab_warehouse_rack[rb].tab_rack_shelf[sb].tab_shelf_place[p].ilosc_towaru;
            }

            ile_mozesz_dodac_1 = 65535 - tab_sklad_towaru_warehouse[we].tab_warehouse_rack[re].tab_rack_shelf[se].tab_shelf_place[p].ilosc_towaru;

            x1 = tab_sklad_towaru_warehouse[wb].tab_warehouse_rack[rb].tab_rack_shelf[sb].tab_shelf_place[p].ilosc_towaru;
            x2 = tab_sklad_towaru_warehouse[we].tab_warehouse_rack[re].tab_rack_shelf[se].tab_shelf_place[p].ilosc_towaru;


            if (ile_mozesz_wziac_1 != 0 && ile_mozesz_dodac_1 != 0)
            {

                if (ile_mozesz_wziac_1 >= ile_mozesz_dodac_1)
                {

                    x2 = tab_sklad_towaru_warehouse[we].tab_warehouse_rack[re].tab_rack_shelf[se].tab_shelf_place[p].ilosc_towaru + (ile_mozesz_dodac_1);

                } else
                {

                    x2 = tab_sklad_towaru_warehouse[we].tab_warehouse_rack[re].tab_rack_shelf[se].tab_shelf_place[p].ilosc_towaru + (ile_mozesz_wziac_1);
                }

                x1 = tab_sklad_towaru_warehouse[wb].tab_warehouse_rack[rb].tab_rack_shelf[sb].tab_shelf_place[p].ilosc_towaru - (x2 - tab_sklad_towaru_warehouse[we].tab_warehouse_rack[re].tab_rack_shelf[se].tab_shelf_place[p].ilosc_towaru);
            }


            tab_sklad_towaru_warehouse[wb].tab_warehouse_rack[rb].tab_rack_shelf[sb].tab_shelf_place[p].ilosc_towaru = x1;
            tab_sklad_towaru_warehouse[we].tab_warehouse_rack[re].tab_rack_shelf[se].tab_shelf_place[p].ilosc_towaru = x2;
        }

    }

}

void mov_h(int w , int r, int s , int p , int a )
{

    if ( w > 127 || w < 0 || r > 127 || r < 0 || s > 127 || s < 0 || p < 0 || p > 127  || ile_magazynow <= w ||  tab_sklad_towaru_warehouse[w].ile_regalow <= r  || tab_sklad_towaru_warehouse[w].tab_warehouse_rack[r].ile_polek <= s || tab_sklad_towaru_warehouse[w].tab_warehouse_rack[r].tab_rack_shelf[s].ile_miejsc <= p || tab_sklad_towaru_warehouse[w].tab_poreczna_polka_warehouse.ile_miejsc <= p  )
    {
        cout << "error"<<endl;
    } else
    {


        if ( a > 65535 )
        {
            a=65535;
        }

        int x1=0;
        int x2=0;

        int ile_mozesz_wziac_1 = 0;
        int ile_mozesz_dodac_1= 0;


        if ( a <=  tab_sklad_towaru_warehouse[w].tab_warehouse_rack[r].tab_rack_shelf[s].tab_shelf_place[p].ilosc_towaru  )
        {
            ile_mozesz_wziac_1 = a;
        } else // a > ilosc towaru
        {
            ile_mozesz_wziac_1 =  tab_sklad_towaru_warehouse[w].tab_warehouse_rack[r].tab_rack_shelf[s].tab_shelf_place[p].ilosc_towaru ;
        }

        ile_mozesz_dodac_1 =  65535 - tab_sklad_towaru_warehouse[w].tab_poreczna_polka_warehouse.tab_shelf_place[p].ilosc_towaru ;

        x1 = tab_sklad_towaru_warehouse[w].tab_warehouse_rack[r].tab_rack_shelf[s].tab_shelf_place[p].ilosc_towaru ;
        x2 = tab_sklad_towaru_warehouse[w].tab_poreczna_polka_warehouse.tab_shelf_place[p].ilosc_towaru ;

        if ( ile_mozesz_wziac_1 != 0 && ile_mozesz_dodac_1 != 0 )
        {

            if ( ile_mozesz_wziac_1 >= ile_mozesz_dodac_1 )
            {

                x2 = tab_sklad_towaru_warehouse[w].tab_poreczna_polka_warehouse.tab_shelf_place[p].ilosc_towaru + ( ile_mozesz_dodac_1 );

            } else
            {

                x2 = tab_sklad_towaru_warehouse[w].tab_poreczna_polka_warehouse.tab_shelf_place[p].ilosc_towaru + ( ile_mozesz_wziac_1 );
            }

        }

        x1 = tab_sklad_towaru_warehouse[w].tab_warehouse_rack[r].tab_rack_shelf[s].tab_shelf_place[p].ilosc_towaru   - ( x2 - tab_sklad_towaru_warehouse[w].tab_poreczna_polka_warehouse.tab_shelf_place[p].ilosc_towaru )        ;

        tab_sklad_towaru_warehouse[w].tab_warehouse_rack[r].tab_rack_shelf[s].tab_shelf_place[p].ilosc_towaru =  x1;
        tab_sklad_towaru_warehouse[w].tab_poreczna_polka_warehouse.tab_shelf_place[p].ilosc_towaru = x2 ;

    }

}

void mov_r(int w , int r, int sb , int se,  int p , int a )
{

    if ( w > 127 || w < 0 || r > 127 || r < 0 || sb > 127 || sb < 0 || se > 127 || se < 0  || p < 0 || p > 127  || ile_magazynow <= w  || tab_sklad_towaru_warehouse[w].ile_regalow <= r  || tab_sklad_towaru_warehouse[w].tab_warehouse_rack[r].ile_polek <= sb || tab_sklad_towaru_warehouse[w].tab_warehouse_rack[r].tab_rack_shelf[sb].ile_miejsc <= p  || tab_poreczny_regal_sklad_towaru.ile_polek <= se ||   tab_poreczny_regal_sklad_towaru.tab_rack_shelf[se].ile_miejsc <= p  )
    {
        cout << "error"<<endl;
    } else
    {



        if ( a > 65535 )
        {
            a=65535;
        }

        int x1=0;
        int x2=0;

        int ile_mozesz_wziac_1 = 0;
        int ile_mozesz_dodac_1= 0;


        if ( a <=  tab_sklad_towaru_warehouse[w].tab_warehouse_rack[r].tab_rack_shelf[sb].tab_shelf_place[p].ilosc_towaru  )
        {
            ile_mozesz_wziac_1 = a;
        } else // a > ilosc towaru
        {
            ile_mozesz_wziac_1 =  tab_sklad_towaru_warehouse[w].tab_warehouse_rack[r].tab_rack_shelf[sb].tab_shelf_place[p].ilosc_towaru ;
        }

        ile_mozesz_dodac_1 =  65535 - tab_poreczny_regal_sklad_towaru.tab_rack_shelf[se].tab_shelf_place[p].ilosc_towaru ;

        x1 = tab_sklad_towaru_warehouse[w].tab_warehouse_rack[r].tab_rack_shelf[sb].tab_shelf_place[p].ilosc_towaru ;
        x2 = tab_poreczny_regal_sklad_towaru.tab_rack_shelf[se].tab_shelf_place[p].ilosc_towaru ;

        if ( ile_mozesz_wziac_1 != 0 && ile_mozesz_dodac_1 != 0 )
        {

            if ( ile_mozesz_wziac_1 >= ile_mozesz_dodac_1 )
            {

                x2 = tab_poreczny_regal_sklad_towaru.tab_rack_shelf[se].tab_shelf_place[p].ilosc_towaru + ( ile_mozesz_dodac_1 );

            } else
            {

                x2 = tab_poreczny_regal_sklad_towaru.tab_rack_shelf[se].tab_shelf_place[p].ilosc_towaru + ( ile_mozesz_wziac_1 );
            }

        }

        x1 = tab_sklad_towaru_warehouse[w].tab_warehouse_rack[r].tab_rack_shelf[sb].tab_shelf_place[p].ilosc_towaru   - ( x2 - tab_poreczny_regal_sklad_towaru.tab_rack_shelf[se].tab_shelf_place[p].ilosc_towaru )        ;

        tab_sklad_towaru_warehouse[w].tab_warehouse_rack[r].tab_rack_shelf[sb].tab_shelf_place[p].ilosc_towaru =  x1;
        tab_poreczny_regal_sklad_towaru.tab_rack_shelf[se].tab_shelf_place[p].ilosc_towaru = x2 ;




    }

}

void mov_s( int s , int p , int a )
{

    if (  s > 127 || s < 0  || p < 0 || p > 127 || tab_poreczny_regal_sklad_towaru.ile_polek <= s || tab_poreczny_regal_sklad_towaru.tab_rack_shelf[s].ile_miejsc <= p || tab_poreczna_polka_sklad_towaru.ile_miejsc <= p )
    {
        cout << "error"<<endl;
    } else
    {


        if ( a > 65535 )
        {
            a=65535;
        }

        int x1=0;
        int x2=0;

        int ile_mozesz_wziac_1 = 0;
        int ile_mozesz_dodac_1= 0;


        if ( a <=  tab_poreczny_regal_sklad_towaru.tab_rack_shelf[s].tab_shelf_place[p].ilosc_towaru  )
        {
            ile_mozesz_wziac_1 = a;
        } else // a > ilosc towaru
        {
            ile_mozesz_wziac_1 =  tab_poreczny_regal_sklad_towaru.tab_rack_shelf[s].tab_shelf_place[p].ilosc_towaru ;
        }

        ile_mozesz_dodac_1 =  65535 - tab_poreczna_polka_sklad_towaru.tab_shelf_place[p].ilosc_towaru ;

        x1 = tab_poreczny_regal_sklad_towaru.tab_rack_shelf[s].tab_shelf_place[p].ilosc_towaru ;
        x2 = tab_poreczna_polka_sklad_towaru.tab_shelf_place[p].ilosc_towaru ;

        if ( ile_mozesz_wziac_1 != 0 && ile_mozesz_dodac_1 != 0 )
        {

            if ( ile_mozesz_wziac_1 >= ile_mozesz_dodac_1 )
            {

                x2 = tab_poreczna_polka_sklad_towaru.tab_shelf_place[p].ilosc_towaru + ( ile_mozesz_dodac_1 );

            } else
            {

                x2 = tab_poreczna_polka_sklad_towaru.tab_shelf_place[p].ilosc_towaru + ( ile_mozesz_wziac_1 );
            }

        }

        x1 = tab_poreczny_regal_sklad_towaru.tab_rack_shelf[s].tab_shelf_place[p].ilosc_towaru  - ( x2 - tab_poreczna_polka_sklad_towaru.tab_shelf_place[p].ilosc_towaru )        ;

        tab_poreczny_regal_sklad_towaru.tab_rack_shelf[s].tab_shelf_place[p].ilosc_towaru =  x1;
        tab_poreczna_polka_sklad_towaru.tab_shelf_place[p].ilosc_towaru = x2 ;



    }

}


void get_e() //
{
    long long int ilosc_towaru_squad = 0;

    // wszystkie magazyny plus podreczne polki w magazynach
    for ( int i = 0 ; i < ile_magazynow ; i++ )
    {

        for ( int y = 0 ; y < tab_sklad_towaru_warehouse[i].tab_poreczna_polka_warehouse.ile_miejsc ; y++ )
        {
            ilosc_towaru_squad = ilosc_towaru_squad + tab_sklad_towaru_warehouse[i].tab_poreczna_polka_warehouse.tab_shelf_place[y].ilosc_towaru ;
        }



        for ( int j =0; j < tab_sklad_towaru_warehouse[i].ile_regalow;j++)
        {

            for ( int k = 0; k < tab_sklad_towaru_warehouse[i].tab_warehouse_rack[j].ile_polek ; k++)
            {
                for ( int l = 0;  l < tab_sklad_towaru_warehouse[i].tab_warehouse_rack[j].tab_rack_shelf[k].ile_miejsc ; l++)
                {
                    ilosc_towaru_squad = ilosc_towaru_squad + tab_sklad_towaru_warehouse[i].tab_warehouse_rack[j].tab_rack_shelf[k].tab_shelf_place[l].ilosc_towaru ;
                }
            }
        }


    }


    // poreczny regal

    for ( int i = 0 ; i < tab_poreczny_regal_sklad_towaru.ile_polek ; i++)
    {
        for ( int j =0; j < tab_poreczny_regal_sklad_towaru.tab_rack_shelf[i].ile_miejsc ; j++ )
        {
            ilosc_towaru_squad = ilosc_towaru_squad + tab_poreczny_regal_sklad_towaru.tab_rack_shelf[i].tab_shelf_place[j].ilosc_towaru ;
        }
    }

    // poreczna polka

    for ( int i =0 ; i < tab_poreczna_polka_sklad_towaru.ile_miejsc ; i++ )
    {
        ilosc_towaru_squad = ilosc_towaru_squad + tab_poreczna_polka_sklad_towaru.tab_shelf_place[i].ilosc_towaru ;
    }

    cout << ilosc_towaru_squad << endl;

}

void get_w(int w)
{
    if ( w > 127 || w < 0 || ile_magazynow <= w )
    {
        cout<<"error"<<endl;
    } else
    {
        long long int ilosc_towaru_squad = 0;


        for ( int y = 0 ; y < tab_sklad_towaru_warehouse[w].tab_poreczna_polka_warehouse.ile_miejsc ; y++ )
        {
            ilosc_towaru_squad = ilosc_towaru_squad + tab_sklad_towaru_warehouse[w].tab_poreczna_polka_warehouse.tab_shelf_place[y].ilosc_towaru ;
        }



        for ( int j =0; j < tab_sklad_towaru_warehouse[w].ile_regalow;j++)
        {

            for ( int k = 0; k < tab_sklad_towaru_warehouse[w].tab_warehouse_rack[j].ile_polek ; k++)
            {
                for ( int l = 0;  l < tab_sklad_towaru_warehouse[w].tab_warehouse_rack[j].tab_rack_shelf[k].ile_miejsc ; l++)
                {
                    ilosc_towaru_squad = ilosc_towaru_squad + tab_sklad_towaru_warehouse[w].tab_warehouse_rack[j].tab_rack_shelf[k].tab_shelf_place[l].ilosc_towaru ;
                }
            }
        }


        cout << ilosc_towaru_squad << endl;
    }


}

void get_rw( int w , int r  )
{

    if ( w > 127 || w < 0 || r > 127 || r < 0 || ile_magazynow <= w || tab_sklad_towaru_warehouse[w].ile_regalow <= r )
    {
        cout<<"error"<<endl;
    } else
    {

        long long int ilosc_towaru_squad = 0;


        for ( int k = 0; k < tab_sklad_towaru_warehouse[w].tab_warehouse_rack[r].ile_polek ; k++)
        {
            for ( int l = 0;  l < tab_sklad_towaru_warehouse[w].tab_warehouse_rack[r].tab_rack_shelf[k].ile_miejsc ; l++)
            {
                ilosc_towaru_squad = ilosc_towaru_squad + tab_sklad_towaru_warehouse[w].tab_warehouse_rack[r].tab_rack_shelf[k].tab_shelf_place[l].ilosc_towaru ;
            }
        }

        cout << ilosc_towaru_squad << endl;
    }
}


void get_rh(  )
{
    long long int ilosc_towaru_squad = 0 ;

    for ( int k = 0; k < tab_poreczny_regal_sklad_towaru.ile_polek ; k++)
    {
        for ( int l = 0;  l < tab_poreczny_regal_sklad_towaru.tab_rack_shelf[k].ile_miejsc ; l++)
        {
            ilosc_towaru_squad = ilosc_towaru_squad + tab_poreczny_regal_sklad_towaru.tab_rack_shelf[k].tab_shelf_place[l].ilosc_towaru ;
        }
    }

    cout << ilosc_towaru_squad << endl;
}

void get_sw( int w , int r , int s )

{

    if ( w > 127 || w < 0 || r > 127 || r < 0 || s > 127 || s < 0 ||  ile_magazynow <= w || tab_sklad_towaru_warehouse[w].ile_regalow <= r || tab_sklad_towaru_warehouse[w].tab_warehouse_rack[r].ile_polek <= s )
    {

        cout<<"error"<<endl;
    } else
    {

        long long int ilosc_towaru_squad = 0;



        for ( int l = 0;  l < tab_sklad_towaru_warehouse[w].tab_warehouse_rack[r].tab_rack_shelf[s].ile_miejsc ; l++)
        {
            ilosc_towaru_squad = ilosc_towaru_squad + tab_sklad_towaru_warehouse[w].tab_warehouse_rack[r].tab_rack_shelf[s].tab_shelf_place[l].ilosc_towaru  ;
        }



        cout << ilosc_towaru_squad << endl;

    }

}


void get_sh( int w )
{

    if ( w > 127 || w < 0 || ile_magazynow <= w )
    {
        cout<<"error"<<endl;
    } else
    {

        long long int ilosc_towaru_squad = 0;


        for ( int l =0 ; l < tab_sklad_towaru_warehouse[w].tab_poreczna_polka_warehouse.ile_miejsc ; l++)
        {

            ilosc_towaru_squad += tab_sklad_towaru_warehouse[w].tab_poreczna_polka_warehouse.tab_shelf_place[l].ilosc_towaru ;

        }

        cout << ilosc_towaru_squad << endl;

    }

}

void get_sr(  int s )
{

    if ( s > 127 || s < 0 || tab_poreczny_regal_sklad_towaru.ile_polek <= s )
    {
        cout<<"error"<<endl;
    } else
    {

        long long int ilosc_towaru_squad = 0;

        for ( int l =0 ; l < tab_poreczny_regal_sklad_towaru.tab_rack_shelf[s].ile_miejsc ; l++)
        {

            ilosc_towaru_squad += tab_poreczny_regal_sklad_towaru.tab_rack_shelf[s].tab_shelf_place[l].ilosc_towaru ;

        }


        cout << ilosc_towaru_squad << endl;

    }

}

void get_s(  )
{

    long long int ilosc_towaru_squad = 0;

    for ( int l = 0; l < tab_poreczna_polka_sklad_towaru.ile_miejsc ; l++)
    {
        ilosc_towaru_squad += tab_poreczna_polka_sklad_towaru.tab_shelf_place[l].ilosc_towaru ;
    }


    cout << ilosc_towaru_squad << endl;

}


void set_lw(int w , int r , int s , int p , char tab_dd[2] )
{

    if ( w > 127 || w < 0 || r > 127 || r < 0 || s > 127 || s < 0 || p > 127 || p < 0 || ile_magazynow <= w || tab_sklad_towaru_warehouse[w].ile_regalow <= r || tab_sklad_towaru_warehouse[w].tab_warehouse_rack[r].ile_polek <= s || tab_sklad_towaru_warehouse[w].tab_warehouse_rack[r].tab_rack_shelf[s].ile_miejsc <= p  )
    {
        cout << "error" <<endl;
    } else {
        tab_sklad_towaru_warehouse[w].tab_warehouse_rack[r].tab_rack_shelf[s].tab_shelf_place[p].etykieta[0] = tab_dd[0];
        tab_sklad_towaru_warehouse[w].tab_warehouse_rack[r].tab_rack_shelf[s].tab_shelf_place[p].etykieta[1] = tab_dd[1];

    }
}


void set_lh(short w , short p , char tab_dd[2] )
{
    if ( w > 127 || w < 0 || p > 127 || p < 0 || ile_magazynow <= w || tab_sklad_towaru_warehouse[w].tab_poreczna_polka_warehouse.ile_miejsc <= p )
    {
        cout << "error"<<endl;
    } else
    {

        tab_sklad_towaru_warehouse[w].tab_poreczna_polka_warehouse.tab_shelf_place[p].etykieta[0] = tab_dd[0];
        tab_sklad_towaru_warehouse[w].tab_poreczna_polka_warehouse.tab_shelf_place[p].etykieta[1] = tab_dd[1];

    }


}


void set_lr( int s , int p , char tab_dd[2] )
{

    if ( s > 127 || s < 0 || p  >  127 || p < 0 || tab_poreczny_regal_sklad_towaru.ile_polek <= s || tab_poreczny_regal_sklad_towaru.tab_rack_shelf[s].ile_miejsc <= p )
    {
        cout<<"error"<<endl;
    } else
    {

        tab_poreczny_regal_sklad_towaru.tab_rack_shelf[s].tab_shelf_place[p].etykieta[0] = tab_dd[0];
        tab_poreczny_regal_sklad_towaru.tab_rack_shelf[s].tab_shelf_place[p].etykieta[1] = tab_dd[1];
    }

}

void set_ls( int p , char tab_dd[2] )
{
    if (  p  >  127 || p < 0 || tab_poreczna_polka_sklad_towaru.ile_miejsc <= p )
    {
        cout<<"error"<<endl;
    } else
    {

        tab_poreczna_polka_sklad_towaru.tab_shelf_place[p].etykieta[0] = tab_dd[0];
        tab_poreczna_polka_sklad_towaru.tab_shelf_place[p].etykieta[1] = tab_dd[1];
    }

}


void get_lw(int w , int r , int s , int p )
{
    if ( w > 127 || w < 0 || r > 127 || r < 0 || s > 127 || s < 0 || p < 0 || p > 127 ||  ile_magazynow <= w || tab_sklad_towaru_warehouse[w].ile_regalow <= r || tab_sklad_towaru_warehouse[w].tab_warehouse_rack[r].ile_polek <= s || tab_sklad_towaru_warehouse[w].tab_warehouse_rack[r].tab_rack_shelf[s].ile_miejsc <= p )
    {
        cout<<"error"<<endl;
    } else
    {

        if ( tab_sklad_towaru_warehouse[w].tab_warehouse_rack[r].tab_rack_shelf[s].tab_shelf_place[p].etykieta[0] == '\0' || tab_sklad_towaru_warehouse[w].tab_warehouse_rack[r].tab_rack_shelf[s].tab_shelf_place[p].etykieta[1] == '\0'  )
        {
            cout << "--" <<endl;
        } else
        {

            cout << tab_sklad_towaru_warehouse[w].tab_warehouse_rack[r].tab_rack_shelf[s].tab_shelf_place[p].etykieta[0] << tab_sklad_towaru_warehouse[w].tab_warehouse_rack[r].tab_rack_shelf[s].tab_shelf_place[p].etykieta[1] << endl;

        }

    }
}


void get_lh(int w , int p )
{
    if ( w > 127 || w < 0 || p < 0 || p > 127 ||  ile_magazynow <= w ||   tab_poreczna_polka_sklad_towaru.ile_miejsc <= p)
    {
        cout<<"error"<<endl;
    } else
    {

        if ( tab_sklad_towaru_warehouse[w].tab_poreczna_polka_warehouse.tab_shelf_place[p].etykieta[0]  == '\0' || tab_sklad_towaru_warehouse[w].tab_poreczna_polka_warehouse.tab_shelf_place[p].etykieta[1]  == '\0'  )
        {
            cout << "--" <<endl;
        } else
        {

            cout << tab_sklad_towaru_warehouse[w].tab_poreczna_polka_warehouse.tab_shelf_place[p].etykieta[0]  << tab_sklad_towaru_warehouse[w].tab_poreczna_polka_warehouse.tab_shelf_place[p].etykieta[1]  << endl;

        }

    }

}



void get_lr( int s , int p )
{
    if ( s > 127 || s < 0 || p < 0 || p > 127 || tab_poreczny_regal_sklad_towaru.ile_polek <= s || tab_poreczny_regal_sklad_towaru.tab_rack_shelf[s].ile_miejsc <= p )
    {
        cout<<"error"<<endl;
    } else
    {

        if ( tab_poreczny_regal_sklad_towaru.tab_rack_shelf[s].tab_shelf_place[p].etykieta[0]  == '\0' || tab_poreczny_regal_sklad_towaru.tab_rack_shelf[s].tab_shelf_place[p].etykieta[1] == '\0'  )
        {
            cout << "--" <<endl;
        } else
        {

            cout << tab_poreczny_regal_sklad_towaru.tab_rack_shelf[s].tab_shelf_place[p].etykieta[0] << tab_poreczny_regal_sklad_towaru.tab_rack_shelf[s].tab_shelf_place[p].etykieta[1] << endl;

        }

    }

}



void get_ls( int p )
{
    if ( p < 0 || p > 127 || tab_poreczna_polka_sklad_towaru.ile_miejsc <= p )
    {
        cout<<"error"<<endl;
    } else
    {

        if ( tab_poreczna_polka_sklad_towaru.tab_shelf_place[p].etykieta[0]  == '\0' || tab_poreczna_polka_sklad_towaru.tab_shelf_place[p].etykieta[1] == '\0'  )
        {
            cout << "--" <<endl;
        } else
        {

            cout << tab_poreczna_polka_sklad_towaru.tab_shelf_place[p].etykieta[0] << tab_poreczna_polka_sklad_towaru.tab_shelf_place[p].etykieta[1] << endl;

        }

    }

}




int main()
{


    string polecenie_temp = "" ;

    while ( polecenie_temp != "END" )
    {
        cin >> polecenie_temp ;


        if ( polecenie_temp == "SET-AP" )
        {
            int  wb;
            int  rb;
            int  sb;
            int  pe;
            cin >> wb >> rb >> sb >> pe ;
            set_ap(wb,rb,sb,pe);


        } else if ( polecenie_temp == "SET-AS" )
        {

            int wb;
            int rb;
            int se;
            int pe;

            cin >> wb >> rb >> se >> pe ;

            set_as(wb, rb, se, pe);

        } else if ( polecenie_temp == "SET-AR" )
        {

            int wb;
            int re;
            int se;
            int pe;

            cin >> wb >> re >> se >> pe ;
            set_ar(wb, re, se, pe);


        } else if ( polecenie_temp == "SET-AW" )
        {

            int we;
            int re;
            int se;
            int pe;
            cin >> we >> re >> se >> pe ;

            set_aw(we, re, se, pe);


        } else if ( polecenie_temp == "SET-HW" )
        {

            int w;
            int p;
            cin >> w  >> p ;

            set_hw(w, p);


        } else if ( polecenie_temp == "SET-HR" )
        {


            int s;
            int p;
            cin >>  s >> p ;

            set_hr(s, p);

        } else if ( polecenie_temp == "SET-HS" )
        {


            int p;
            cin >>  p ;

            set_hs(p);


        } else if ( polecenie_temp == "PUT-W" ) // ////////////////////////////
        {

            int w;
            int r;
            int s;
            int p;
            int a;

            cin >> w >> r >> s >> p >> a ;


            put_w(w,r,s,p,a);



        } else if ( polecenie_temp == "PUT-H" )
        {

            int w;
            int p;
            int a;

            cin >> w >> p >> a ;

            put_h(w,p,a);


        } else if ( polecenie_temp == "PUT-R" )
        {


            int s;
            int p;
            int a;
            cin >> s >> p >> a ;

            put_r(s,p,a);

        } else if ( polecenie_temp == "PUT-S" )
        {

            int p;
            int a;
            cin >> p >> a ;

            put_s(p,a);

        } else if ( polecenie_temp == "FILL" )
        {

            int w , r , s , p , a ;
            cin >> w >> r >>s >> p >> a ;

            fill(w,r,s,p,a);

        } else if ( polecenie_temp == "POP-W" )
        {

            int w , r , s , p , a ;
            cin >> w >> r >> s >> p >> a ;

            pop_w(w,r,s,p,a);

        } else if ( polecenie_temp == "POP-H" )
        {

            int w , p , a;
            cin >> w >> p >> a ;

            pop_h(w,p,a);

        } else if ( polecenie_temp == "POP-R" )
        {

            int s, p , a ;
            cin >> s >> p >> a ;

            pop_r(s,p,a);

        } else if ( polecenie_temp == "POP-S" )
        {

            int p , a ;
            cin >> p >> a ;

            pop_s(p,a);

        } else if ( polecenie_temp == "MOV-W" )
        {


            int wb,rb,sb,we,re,se,p, a;
            cin >> wb>>rb>> sb>>we>>re>>se>>p>> a;

            mov_w(wb,rb,sb,we,re,se,p,a);


        } else if ( polecenie_temp == "MOV-H" )
        {


            int w,r,s,p,a ;
            cin >> w >>r>>s >> p>>a;

            mov_h(w,r,s,p,a);


        } else if ( polecenie_temp == "MOV-R" )
        {


            int w, r , sb , se , p , a ;
            cin >> w >> r >> sb >> se >> p >> a ;

            mov_r(w, r , sb , se , p , a);


        } else if ( polecenie_temp == "MOV-S" )
        {

            int s,p,a;
            cin >> s >> p >> a ;

            mov_s(s,p,a);


        } else if ( polecenie_temp == "GET-E" )
        {

            get_e();


        } else if ( polecenie_temp == "GET-W" )
        {

            int w ;
            cin >> w ;


            get_w(w);



        } else if ( polecenie_temp == "GET-RW" )
        {

            int w, r ;
            cin >> w >> r ;


            get_rw(w,r);




        } else if ( polecenie_temp == "GET-RH" )
        {

            get_rh();


        } else if ( polecenie_temp == "GET-SW" )
        {


            int w , r , s ;
            cin >> w >> r >> s ;


            get_sw(w,r,s);

        } else if ( polecenie_temp == "GET-SH" )
        {

            int w ;
            cin >> w ;

            get_sh(w);

        } else if ( polecenie_temp == "GET-SR" )
        {


            int s ;
            cin >> s ;

            get_sr(s);


        } else if ( polecenie_temp == "GET-S" )
        {

            get_s();

        } else if ( polecenie_temp == "SET-LW" )
        {


            int w , r , s , p ;
            cin >> w >> r >> s >> p ;

            char tab_dd_temp[3]={'\0','\0','\0'};
            cin >> tab_dd_temp;


            set_lw(w,r,s,p,tab_dd_temp);


        } else if ( polecenie_temp == "SET-LH" )
        {


            int w ,  p ;
            cin >> w >>  p ;

            char tab_dd_temp[3]={'\0','\0','\0'};
            cin >> tab_dd_temp;


            set_lh(w,p,tab_dd_temp);


        } else if ( polecenie_temp == "SET-LR" )
        {


            int s , p ;
            cin >> s >> p ;

            char tab_dd_temp[3]={'\0','\0','\0'};
            cin >> tab_dd_temp;


            set_lr(s,p,tab_dd_temp) ;


        } else if ( polecenie_temp == "SET-LS" )
        {

            int p ;
            cin >> p;

            char tab_dd_temp[2]={'\0','\0'};
            cin >> tab_dd_temp;

            set_ls(p,tab_dd_temp);



        } else if ( polecenie_temp == "GET-LW" )
        {


            int w , r , s , p ;
            cin >> w >> r >> s >> p ;


            get_lw(w,r,s,p);




        } else if ( polecenie_temp == "GET-LH" )
        {


            int w , p ;
            cin >> w >> p ;

            get_lh(w,p);



        } else if ( polecenie_temp == "GET-LR" )
        {


            int  s , p ;
            cin >>  s >> p ;

            get_lr(s,p);

        } else if ( polecenie_temp == "GET-LS" )
        {

            int p ;
            cin >> p;

            get_ls(p);


        }


    }



    return 0;
}





