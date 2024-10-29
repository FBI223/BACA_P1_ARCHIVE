#include <iostream>
using namespace std;

int dobry_index(int i,int n_tab)
{
    int temp;
    int wynik=0;
    if (i>= n_tab) {
        wynik = i % n_tab;
    }else if (i<0)
    {
        temp = i % n_tab;
        if (i % n_tab == 0)
        {
            return 0;
        }
        wynik = n_tab + temp;
    }

    return wynik;
}

int tablica_testowa[7]={1,2,3,4,5,6,7};

void odwrot(int x_p,int n,int n_tab)
{

    int temp;

    int ile_cykli_w_cyklu;
    ile_cykli_w_cyklu = n/2;

    int ile_cykli;
    ile_cykli = n_tab / n;


    //int x_p;
    int x_k;
    if (x_p+n>n_tab-1) // x_k gdy wykracza poza tablice
    {
        x_k = dobry_index(x_p + n ,n_tab) + 1 ; // okreslasz gdzie bedzie indeks pierwszej zamiany
    }else if (x_p+n<0)
    {
        x_k = dobry_index(x_p + n,n_tab );
    }else if (x_p+n==0)
    {
        x_k=x_p+n;
    }else if (x_p+n<n_tab && x_p+n>=0 )
    {
        x_k=x_p+n;
    }
    int x_p_stala=x_p;
    int x_k_stala=x_k;


    for (int i = 0; i<ile_cykli;++i)
    {

        for (int j =0;ile_cykli_w_cyklu-1;++j)
        {

            temp = tablica_testowa[x_p];
            tablica_testowa[x_p] = tablica_testowa[x_k];
            tablica_testowa[x_k] = temp;
            x_p= dobry_index(x_p+1,n_tab);
            x_k= dobry_index(x_k-1,n_tab);

        }

        x_p_stala= dobry_index(x_k_stala+1,n_tab);
        x_k_stala= dobry_index(x_p_stala+n,n_tab);


    }
    for (int i = 0;i<n_tab;++i)
    {
        cout <<"i : "<<i<<"  -->  "<<tablica_testowa[i]<<endl;
    }

}


int main()
{

    int ile_cykli=0;
    int ile_elementow_odwrocono=0;

    int x_p;
    int x_k;
    int x_p_stala;
    int x_k_stala;

    int n;



    int index_temp_pocz=0;
    int index_temp_pocz_odwrotnosc=0;

//    cout << "Hello, World!" << endl;
//
//    cout<< dobry_index(-1,5) <<endl;
//    cout<< dobry_index(-2,5) <<endl;
//    cout<< dobry_index(-3,5) <<endl;
//    cout<< dobry_index(-34,5) <<endl;
//    cout<< dobry_index(-35,5) <<endl;

    odwrot(5,3,7);

    return 0;
}
