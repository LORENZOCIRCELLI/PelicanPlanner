#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

typedef struct{

    char character[30];
    char gift_1[30];
    char gift_2[30];
    char gift_3[30];
    char gift_4[30];
    char gift_5[30];


}Gift_List;

void file_reader();
void list_all_gifts();
void search_gift();
void main_menu();

Gift_List gifts_List[50];



int main(){

    char archive[] = "gifts.csv";
    file_reader(archive);
    system("clear");
    sleep(3);

    main_menu();



    return 0;

}

void file_reader(char archive[]){

    FILE *file = fopen(archive, "r");

    int i = 0;

    if(file == NULL){

        printf("The program was enable to open the database");
        return;

    }

    char line[1000];
    fgets(line, sizeof(line), file);  // Ignora o cabeçalho

    while (fgets(line, sizeof(line), file) != NULL) {

        if (sscanf(line, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",
                gifts_List[i].character,
                gifts_List[i].gift_1,
                gifts_List[i].gift_2,
                gifts_List[i].gift_3,
                gifts_List[i].gift_4,
                gifts_List[i].gift_5) == 6) {
            i++;
        } 
        else if(sscanf(line, "%[^,]", gifts_List[i].character) == 1){i++;}
        
        
        else {
            printf("Erro ao processar linha: %s", line);
        }
    }

    printf("O arquivo foi lido com sucesso!!");

    fclose(file);

}

void list_all_gifts(){

    int i = 0;
    while(i < 50 && strcmp(gifts_List[i].character, "") != 0){

        if(strcmp(gifts_List[i].gift_1, "") == 0){

        printf("\n\n--------------------------------------------------");
        printf("\n\nName of the character:      %s\n", gifts_List[i].character);
        printf("This character can't receive gifts!");

        printf("\n\n--------------------------------------------------\n\n");


        }
        else{
        printf("\n\n--------------------------------------------------");
        printf("\n\nName of the character:      %s\n", gifts_List[i].character);
        printf("Gift 1:                     %s\n",gifts_List[i].gift_1);
        printf("Gift 2:                     %s\n",gifts_List[i].gift_2);
        printf("Gift 3:                     %s\n",gifts_List[i].gift_3);
        printf("Gift 4:                     %s\n",gifts_List[i].gift_4);
        printf("Gift 5:                     %s",gifts_List[i].gift_5);
        printf("\n\n--------------------------------------------------\n\n");
        }
        i++;

    }


}

void search_gift(){

    char name[30];
    printf("\nInsert the character name: ");
    scanf(" %[^\n]", name);



    int i = 0;

    while (i < 50 && strcmp(gifts_List[i].character, name) != 0) {

        i++;

    }

    if(strcmp(gifts_List[i].character, "") == 0){

        printf("The choosen character is either misspelled or he can't receive gifts!");
        
    }
    else{
    printf("\n\n--------------------------------------------------");
    printf("\n\nName of the character:      %s\n\n", gifts_List[i].character);
    printf("Gift 1:                     %s\n",gifts_List[i].gift_1);
    printf("Gift 2:                     %s\n",gifts_List[i].gift_2);
    printf("Gift 3:                     %s\n",gifts_List[i].gift_3);
    printf("Gift 4:                     %s\n",gifts_List[i].gift_4);
    printf("Gift 5:                     %s\n",gifts_List[i].gift_5);
    printf("\n\n--------------------------------------------------\n\n");
    }

}




void main_menu(){

    int option = 0;





    while(option != 9){

        printf("\n\n1. Select the character: \n");

        printf("2. Show all characters: \n");

        printf("3. Profit Calculator: \n");

        printf("4. Tips: \n");

        printf("5. Item Codes: \n\n");

        printf("Insert the option: ");
    
        scanf("%d", &option);

        switch (option)
        {
        case 1:

            search_gift();

            break;
        
        case 2:

            list_all_gifts();

            break;

        case 9:

            break;


        }

    }

}