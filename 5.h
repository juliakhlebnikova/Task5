#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <cmath>

using namespace std;

struct list
{
    int deg;
    int coef;
    list *next;
};

void structure ();
void structure1 (list* tmp);
void pushtail (list* &tmp, int d, int c);
void print_list (list* ptr);
void dif ();
