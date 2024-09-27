#include <stdio.h>
#include <math.h>
#include <TXLib.h>


struct text_info
{
    int* mas_len_str;

    char* text;

    char** numm;

    int lines_count;

    int count_size;

} text;

void sort_txt();

int srav_elem(char* numm1, char* numm2, int mas_len_str, int mas_len_str1);

void make_text();

void swap_str(char** nummi, char** nummi1);

void swap_int(int* elem1, int* elem2);


int main()
{
    sort_txt();

    return 0;
}


void make_text()
{
    FILE* st_scan = fopen("Onegin.txt", "r");  //change

    text.lines_count = 0;

    if (st_scan == NULL )
    {
        printf("ERROR1");

        exit(1);
    }

    rewind(st_scan);

    while ( ! feof(st_scan))
    {
        if (fgetc(st_scan) == '\n')
        {
            text.lines_count++;
        }
    }

    rewind(st_scan);

    text.count_size = 0;

    while ( ! feof(st_scan))
    {
        if (fgetc(st_scan) != EOF )
        text.count_size++;
        //printf("%d",text.count_size);

    }




    rewind(st_scan);

    text.mas_len_str = (int*) calloc(text.lines_count + 1, sizeof(int));

    int i_1= 1;
    int len_str = 0;
    while ( ! feof(st_scan))
    {

        if (fgetc(st_scan) != '\n')
        {
            len_str++;
        }
        else
       {
            text.mas_len_str[i_1] = len_str;
            ++i_1;
            len_str = 0;
        }
    }

    rewind(st_scan);

    text.text = (char*) calloc(text.count_size, sizeof(char));

    text.numm = (char**) calloc(text.lines_count + 1, sizeof(char*));

    fread(text.text, sizeof(char), (size_t) text.count_size, st_scan);

    text.numm[0] = text.text;

    int j_1 = 1;

    for (int i = 0; i < text.count_size; i++)
    {
        if (text.text[i] == '\n')
        {
            text.numm[j_1] = text.text + i + 1;
            j_1++;
        }
    }

    fclose(st_scan);

}
void sort_txt()
{

    make_text();


    int gran = text.lines_count - 1;

    while (gran != 0)
    {
        for (int i = 0; i < gran; i++)
        {

            if (srav_elem(text.numm[i], text.numm[i + 1], text.mas_len_str[i + 1], text.mas_len_str[i + 2]) > 0)
            {
                //printf("%s \n %s \n", (numm)[i], (numm)[i + 1]);
                swap_str(&text.numm[i], &text.numm[i + 1]);
                swap_int(&text.mas_len_str[i+1], &text.mas_len_str[i+2]);
            }

        }

        --gran;
    }

    for (int i = 0; i < text.lines_count; i++)
        {
            for(int j = 0; j < text.mas_len_str[i+1]; ++j) {
                printf("%c", text.numm[i][j]);
            }
            printf("\n");
        }

}


int srav_elem(char* numm1, char* numm2, int mas_len_str1, int mas_len_str2)
{
    char* numm1_copy = numm1;

    char* numm2_copy = numm2;

    int i_2 = mas_len_str2;

    int i_1 = mas_len_str1;

    while (isalpha((numm1_copy)[i_1]) == 0)
    {
        i_1--;
    }

    while (isalpha((numm2_copy)[i_2]) == 0)
    {

        i_2--;

    }

    while ((numm1_copy)[i_1] ==  (numm2_copy)[i_2] && (numm1_copy)[i_1] != '\n' && (numm2_copy)[i_2] != '\n')
    {
        i_1--;
        i_2--;
        //printf("%c", (*numm1_copy)[i]);
    }

    return ((int) (numm1_copy)[i_1]) - ((int) (numm2_copy)[i_2]);
}


void swap_str(char** nummi, char** nummi1)
{
    char* z = *nummi;

    *nummi = *nummi1;
    *nummi1 = z;
}

void swap_int(int* elem1, int* elem2) {
    int tmp = *elem1;
    *elem1 = *elem2;
    *elem2 = tmp;
}
