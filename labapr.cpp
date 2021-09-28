#include <stdio.h>
#include <ctype.h>
#include <cstring>
int main(int argc, char **argv)
{
    if (argc != 3) 
    {
        printf("Неверное количество аргументов");
        return 0;
    }
    else
    {

        if ((strcmp(argv[1], "-l") == 0) or (strcmp(argv[1], "-c") == 0) or (strcmp(argv[1], "-w") == 0))
        {
            FILE *fin;
            fin = fopen(argv[2], "r");
            int pred_cim, slov = 1, ctr = 1, counter = 0;
            int cim;
            cim = fgetc(fin);
            pred_cim = cim;
            if (fin == NULL)
            {
                printf("Файл не найден");
                return 0;
            }
            else
            {
                while (cim != EOF)
                {
                    counter++;
                    if (cim == '\n') 
                    {
                        ctr++;
                    }
                    if (isspace(cim) && (isspace(pred_cim) == false))
                    {
                        slov++;
                    }
                    pred_cim = cim;
                    cim = fgetc(fin);
                }
                fclose(fin);
                if (strcmp(argv[1], "-c") == 0)
                {
                    printf("%d\n", counter);
                }
                if (strcmp(argv[1], "-l") == 0)
                {
                    printf("%d\n", ctr);
                }
                if (strcmp(argv[1], "-w")==0)
                {
                    printf("%d\n", slov);
                }
                return 0;
            }
        }
        else
        {
            printf("Введен неверный алгумент");
            return 0;
        }
    }
}
