#include <stdio.h>
#include <string.h>

typedef truct
{
    int dia;
    int mes;
    int main;
} TData;

int isDate(const TData *data);
TData lerDataValida(void);
