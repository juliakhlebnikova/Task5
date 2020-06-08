#include "5.h"

using namespace std;

list* P = new list;   //P=Q+R
list* Q = new list;
list* R = new list;

//Создание
void structure ()
{
    structure1 (P);
    cout << "P = ";
    print_list(P);
    structure1 (Q);
    cout << "Q = ";
    print_list(Q);
}

void structure1 (list* tmp)
{
    tmp -> next = NULL;
    int d,c;
    cin >> d;
    cin >> c;
    tmp ->deg = d;
    tmp ->coef = c;
    tmp -> next = NULL;
    cin >> d;
    cin >> c;
    while (c!=0)
    {
        pushtail(tmp,d,c);
        cin >> d;
        cin >> c;
    }
}

//Добавление в хвост
void pushtail (list* &tmp, int d, int c)
{
    list* t = new list;
    list* p = tmp;
    t -> deg = d;
    t -> coef = c;
    t -> next = NULL;
    while (!p->next == NULL) {p = p -> next;}
    p -> next = t;
}

//Вывод на печать
void print_list(list* ptr)
{
    while(ptr)
    {
        cout << ptr->coef << " * x^" ;
        cout << ptr->deg;
        if (ptr->next) {cout<< " + ";}
        ptr = ptr->next;
    }
    cout << '\n';
}

//разность
void dif ()
{
    R->next = NULL;
    if (P->deg > Q->deg) {
        R->coef=P->coef;
        R->deg=P->deg;
        R->next = NULL;
        P=P->next;
    }
    else if (P->deg < Q->deg) {
        R->coef=-Q->coef;
        R->deg=Q->deg;
        R->next = NULL;
        Q=Q->next;
    }
    else if (P->deg == Q->deg) {
        R->coef=P->coef-Q->coef;
        R->deg=P->deg;
        R->next = NULL;
        P=P->next;
        Q=Q->next;
    }
    //print_list(R);
    while (P!=NULL && Q!=NULL) {
        if (P->deg > Q->deg)
        {
            pushtail(R, P->deg, P->coef);
            P=P->next;
        }
        else if (P->deg < Q->deg)
        {
            pushtail(R, Q->deg, -Q->coef);
            Q=Q->next;
        }
        else if (P->deg == Q->deg)
        {
            pushtail(R, P->deg, P->coef-Q->coef);
            P=P->next;
            Q=Q->next;
        }
    }
    while (P!=NULL) {
        pushtail(R, P->deg, P->coef);
        P=P->next;
    }
    while (Q!=NULL) {
        pushtail(R, Q->deg, -Q->coef);
        Q=Q->next;
    }
    cout << "R = P - Q = ";
    print_list(R);
}
