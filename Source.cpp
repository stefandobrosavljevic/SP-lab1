#include"DList.h"
#include<iostream>
using namespace std;


int main()
{
    DList *l = new DList();

    l->ubaciNaPocetak(4, 2);
    l->ubaciNaKraj(10, 2);
    l->ubaciNaKraj(20, 2);
    l->ubaciNaKraj(5, 3);
    l->ubaciNaKraj(5, 3);
    l->ubaciNaKraj(5, 3);
    l->ubaciNaKraj(5, 4);
    l->ubaciNaKraj(5, 4);
    l->ubaciNaKraj(5, 4);
    l->stampaj();

    l->Compact(2);
    l->stampaj();

    l->Compact(3);
    l->stampaj();

    l->Compact(4);
    l->stampaj();
    delete l;
    return 0;
}

