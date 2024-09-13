#include <stdio.h>
#include <math.h>
#include <TXLib.h>


const int line_len = 20;
const int line = 43;


void sort_line(char text[][line_len]);

void sort_txt();

int srav_elem(const char* el1, const char* el2);

void swap(int* a, int* b);

int main()
{
    sort_txt();
    return 0;
}

void sort_txt()
{
    FILE* st_scan = fopen("Onegin.txt", "r");
    FILE* st_scan1 = fopen("Onegin.txt", "r");
    int lines_count = 1;


    if (st_scan == NULL )
    {
        printf("ERROR1");
        exit(1);

    }


    while ( ! feof(st_scan1))
    {
        if (fgetc(st_scan1) == '\n')
        {
            lines_count++;
        }
    }
    //(char*) text = (char*) calloc((size_t)lines_count, sizeof(char));
    const int line = 43;

    char text[line][line_len] = {};
    printf("%d", lines_count);
    for (int i = 0; i < lines_count; i++)
    {
        if (fgets(text[i], line_len, st_scan) == NULL)
        {
            printf("ERROR2");
            exit(1);
        }
    }

    fclose(st_scan);

    sort_line(text);
}

void sort_line(char text[][line_len])
{
    int ind[line] = {};
    for (int i =0; i < line; i++)
    {
        ind[i] = i;
    }

    int gran = line - 1;
    while (gran > 0)
    {
        for (int j = 0; j < gran; j++)
        {
            if (srav_elem(text[ind[j]], text[ind[j +1]]) > 0)
            {
                swap(&ind[j], &ind[j + 1]);
            }
        }

        gran = gran - 1;
    }

    for (int i = 0; i < line; i++)
    {
        printf("%s", text[ind[i]]);

    }

}


void swap(int* a, int* b)
{
    int z = *b;

    *b = *a;
    *a = z;

}

int srav_elem(const char* el1, const char* el2)
{
    int i = 0;
    while (i < line_len && ((int) el1[i]) == ((int) el2[i]))
    {
        i++;
    }
    if (i == line_len)
    {
        return 0;
    }
    return ((int) el1[i]) -((int) el2[i]);
}
