#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{

    char character[30];
    char gift_1[30];
    char gift_2[30];
    char gift_3[30];
    char gift_4[30];
    char gift_5[30];


}Gift_List;

Gift_List gifts_List[50];

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
        } else {
            printf("Erro ao processar linha: %s", line);
        }
    }

    printf("O arquivo foi lido com sucesso!!");
    fclose(file);

}

void search_gift(){

    char name[30];
    printf("\n\nInsert the character name: ");
    scanf("%[^\n]", name);

    int i = 0;

    while (i < 50 && strcmp(gifts_List[i].character, name) != 0) {

        if (i == 50) {
            printf("Unable to find the character!\n");
            return;
        }

        i++;

    }
    printf("\n\n--------------------------------------------------");
    printf("\n\nName of the character:      %s\n", gifts_List[i].character);
    printf("Gift 1:                     %s\n",gifts_List[i].gift_1);
    printf("Gift 2:                     %s\n",gifts_List[i].gift_2);
    printf("Gift 3:                     %s\n",gifts_List[i].gift_3);
    printf("Gift 4:                     %s\n",gifts_List[i].gift_4);
    printf("Gift 5:                     %s\n",gifts_List[i].gift_5);
    printf("\n\n--------------------------------------------------\n\n");


}

int main(){

    char archive[] = "gifts.csv";
    file_reader(archive);

    search_gift();

    return 0;

}