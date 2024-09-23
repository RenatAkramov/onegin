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

const int line_len = 17;

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

    int count_sizewrong = text.lines_count * line_len;

    text.text = (char*) calloc(count_sizewrong, sizeof(char));

    text.numm = (char**) calloc(text.lines_count + 1, sizeof(char*));

    text.count_size = (int) fread(text.text, sizeof(char), (size_t) count_sizewrong, st_scan);

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

    int i = 0;

    while ((numm1)[i] ==  (numm2)[i]
            && (numm1)[i] != '\n' && (numm2)[i] != '\n' || isalpha((numm1)[i]) == 0 || isalpha((numm2)[i]) == 0)
    {
        i++;
        //printf("%c", (*numm1)[i]);
    }

    return ((int) (numm1)[i]) - ((int) (numm2)[i]);
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























