#include <stdio.h>
#include <string.h>
#include "datas_.h"

int isDate(const TData *data)
{
    if (data->ano < 1909 || data->ano > 2020)
        return 0;

    if (data->mes < 1 || data->mes > 12)
        return 0;

    if (data->dia < 1 || data->dia > 31)
        return 0;

    if (data->mes == 2)
    {
        int bissexto = (data->ano % 4 == 0 && data->ano % 100 != 0) || (data->ano % 400 == 0);
        if (bissexto && data->dia > 29)
            return 0;
        if (bissexto && data->dia > 28)
            return 0;
    }

    if ((data->mes == 4 || data->mes == 6 || data->mes == 9 || data->mes == 11) && data->dia > 30)
    {
        return 0;
    }

    return 1;
}

TData lerDataValida(void)
{
    TData data;
    char buffer[20];

    do
    {
        printf("Digite a data de nascimento (DD/MM/AAAA) ou DD MM AAAA): ");

        if (fgets(buffer, sizeof(buffer), stdin) != NULL)
        {
            buffer[strcspn(buffer, "\n")] = '\0';
        }
        if (sscanf(buffer, "%d%d%d", &data.dia, &data.mes, &data.ano) != 3)
        {
            scanf(buffer, "%d%d%d", &data.dia, &data.mes, &data.ano);
        }
        if (!isDate(&data))
        {
            printf("Data invalida! Tente novamento.\n");
        }
    } while (!isDate(&data));

    return data;
}