#include<stdio.h>
#include<stdlib.h>

typedef struct Page
{
    int id;
    unsigned int count;
}Page;



int main(int argc, char** argv){

    // Add condition to check if argv[1] is not exist (argc < 2)
    if(argc < 2)
    {
        printf("Error in reading the command parameter.\nPlease Provide page_fr_number.");
        return 1;
    }
    const int page_fr_number = strtol(argv[1], NULL, 10);
    Page *page_fr_array = (Page*) calloc(page_fr_number, sizeof(Page));

    FILE *input = fopen("Lab 09 input.txt", "r");
    // Add checker if the file couldn't able to be read
    if(input == NULL){
        printf("Error in reading the file");
        return 1;
    }


    // As the file is fixed and I know the number of words from word editior
    // https://www.charactercountonline.com/
    // or it can be implemented for dynamic size with while(EOF != fscanf(...))

    int hit_count = 0;
    int miss_count = 0;
    for(int x = 0; x < 1000; x++){
        int needed_page;
        fscanf(input, "%d ", &needed_page);
        int tmp_page_index = -1;

        for(int i = 0; i < page_fr_number; i++){
        // printf("%d --- %d\n",page_fr_array[i].id, needed_page);

            if(page_fr_array[i].id == needed_page){
                tmp_page_index = i;
                hit_count++;
                break;
            }
        }

        if(tmp_page_index == -1){
            miss_count++;

            int least_page_count_index = 0;
            for(int i = 1; i < page_fr_number; i++){
                if(page_fr_array[least_page_count_index].count > page_fr_array[i].count)
                    least_page_count_index = i;
            }
            // printf("%d --- %d\n",page_fr_array[least_page_count_index].id, needed_page);

            page_fr_array[least_page_count_index].id = needed_page;
        }

        for (int i = 0; i < page_fr_number; i++)
        {
            page_fr_array[i].count >>= 1;

            if(page_fr_array[i].id == needed_page){
                page_fr_array[i].count |= ((1 << ((sizeof(unsigned int)*8)-1)));
                // printf("%ud", page_fr_array[i].count);
                // printf("debug\n");
            }
        }

    }

    printf("Hit:%d\n",hit_count);
    printf("Miss:%d\n",miss_count);
    printf("Hit/miss:%f\n",(float)hit_count/miss_count);



    // For debugging to know if we reach the end or not
    // printf("Last page_num: %d\n", page_arr[999]);

    free(page_fr_array);
    fclose(input);
    return 0;
}
