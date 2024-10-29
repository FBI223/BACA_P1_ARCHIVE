#include <iostream>

using namespace std;


bool Element( int x , int zb_a[] )
{
    bool czy_znaleziony=false;
    int i =0;


    if ( zb_a[0] == -1 )
    {
        return czy_znaleziony;
    }

    while (zb_a[i] != -1 && czy_znaleziony == false )
    {
        if (zb_a[i] == x)
        {
            czy_znaleziony = true;
        }
        ++i;
    }
    return czy_znaleziony;
}


void Complement_v3( int zb_a[], int zb_c[] )
{
    int j = 1;

    int i = 1;
    int i_c = 0;

    int i_n=0;
    while (zb_a[i_n] != -1 )
    {
        i_n+=1;
    }

    bool temp_bool=true;

    zb_c[0] = -1;

    if ( zb_a[0] == -1 )
    {
        for (int i = 1; i < 4096; ++i)
        {
            zb_c[i_c] = i;
            i_c += 1;
            zb_c[i_c] = -1;
        }

    } else if ( i_n >= 4095  )
    {
        zb_c[0] = -1;

    } else
    {
        cout<<"operacja 0 wykonana "<<endl;

        for (int i = 1; i < 4096; ++i)
        {
            temp_bool = true;
            temp_bool = Element(i,zb_a);

            if (temp_bool == false )
            {
                cout<<"operacja 1 wykonana "<<endl;

                zb_c[i_c] = i;
                i_c += 1;
                zb_c[i_c] = -1;

            }

        }


    }

}



void Complement_v2( int zb_a[], int zb_c[] )
{
    int j = 1;

    int i = 1;
    int i_c = 0;

    bool temp_bool=true;

    zb_c[0] = -1;

    if (zb_a[0] == -1)
    {
        j=1;
        while (j <= 4095)
        {
            zb_c[i_c] = j;
            i_c+=1;
            zb_c[i_c] = -1;
            ++j;
        }

        zb_c[j] =-1;

        //bubble_sort_v2(j,zb_c);

    } else
    {
        i=1;
        while (i < 4096 )
        {
            temp_bool=true;
            temp_bool = Element(i, zb_a);

            if ( temp_bool == false)
            {
                zb_c[i_c] = i;
                i_c += 1;
                zb_c[i_c] = -1;
            }
            ++i;
        }

        //bubble_sort_v2(i_c,zb_c);
    }
}




void Complement( int zb_a[], int zb_c[] )
{

    int i =1;
    int i_c = 0;

    zb_c[0] = -1;

    while ( i < 4096 )
    {
        //cout<< i <<endl;
        if (Element(i,zb_a) == false)
        {

            zb_c[i_c] = i;
            zb_c+=1;
            zb_c[i_c] = -1;
        }
        ++i;
    }


}


int main( )
{

//    int zb_a[2000]={0};
//    int zb_b[4100]={};
//    int zb_w[10]={0};

//    int i_c=1;
//
//    for (int i=0; i<4095;++i)
//    {
//        zb_b[i] = i+1;
//        //cout<< " i :  "<<i<< " to jest :  "<< i+1 <<endl;
//    }
//    zb_b[4095] = -1;
//
//    cout<< " i :  "<<4095<< " to jest :  "<< zb_b[4095] <<endl;
//
//    Complement(zb_b,zb_w);
//
//    for (int i=0; i<10;++i)
//    {
//        cout<< zb_w[i]<<endl;
//    }



    int zb_a[37]={11,12,13,15,16,17,4000,4050,4060,4070,4080,20,21,23,3,-1};
    int zb_b[4100]={-1,-1};

    int zb_w[4100]={0};

    int uniwersum[4096]={};

    for (int i =10 ; i<4090;++i)
    {
        uniwersum[i] = i+1;
    }

    Complement(uniwersum,zb_w);

    for (int i=0; i<4099;++i)
    {
        cout<< zb_w[i]<<endl;
    }


    return 0;
}

