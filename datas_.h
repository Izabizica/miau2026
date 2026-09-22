#ifndef datas_
#define datas_

typedef truct
{
    int dia;
    int mes;
    int ano;
} TData;

int isDate(const TData *data);
TData lerDataValida(void);

#endif // Datas_