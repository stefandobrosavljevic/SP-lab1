#include"DList.h"
#include<iostream>
using namespace std;


int main()
{
    DList l;

    l.ubaciNaPocetak(4);
    l.ubaciNaKraj(5);
    l.ubaciNaPocetak(3);
    l.stampaj();

    l.izbrisiEl(4);
    l.stampaj();


    return 0;
}

