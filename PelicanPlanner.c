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

typedef struct{

    char name[30];
    int base_value;
    char season[20];
    char seller[30];
    int grow;
    int regrow;

    int silver_value;
    int golden_value;
    int iridium_value;
    
}Crop;

Crop crops_List[100];
Gift_List gifts_List[50];

void gift_reader();
void crop_reader();
void list_all_gifts();
void list_all_crops();
void crop_farm_calculator();
void search_gift();
void main_menu();



int main(){

    char archive[] = "gifts.csv";
    gift_reader(archive);
    crop_reader();
    system("clear");
    sleep(3);

    main_menu();



    return 0;

}

void gift_reader(char archive[]){

    FILE *file = fopen(archive, "r");

    int i = 0;

    if(file == NULL){

        printf("The program can't open the database");
        return;

    }

    char line[1000];
    fgets(line, sizeof(line), file);

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

void crop_reader(){

    FILE *file = fopen("crops.csv", "r");

    int i = 0;

    if(file == NULL){

        printf("The program can't open the database");
        return;

    }

    char line[1000];
    fgets(line, sizeof(line), file);

    while(fgets(line, sizeof(line),file) != NULL){

        char regrow_str[10];

        if (sscanf(line, "%[^,],%d,%[^,],%[^,],%d,%[^,\n]", crops_List[i].name, 
                &crops_List[i].base_value, crops_List[i].season, 
                crops_List[i].seller, &crops_List[i].grow, regrow_str) == 6) {
            
            if (strlen(regrow_str) > 0)
                crops_List[i].regrow = atoi(regrow_str);
            else
                crops_List[i].regrow = -1; 

            float silver_result = crops_List[i].base_value * 1.25;
            float gold_result = crops_List[i].base_value * 1.50;
            float iridium_result = crops_List[i].base_value * 2;

            crops_List[i].silver_value = (int) silver_result;
            crops_List[i].golden_value = (int) gold_result;
            crops_List[i].iridium_value = (int) iridium_result;

            i++;
        }   

    }

    printf("\nO arquivo foi lido com sucesso!");

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

void list_all_crops() {
    int i = 0;

    while (strcmp(crops_List[i].name, "") != 0) {
        printf("--------------------------------------------------\n");
        printf("Name of the crop:           %s\n", crops_List[i].name);
        printf("Base Value:                 %d\n", crops_List[i].base_value);
        printf("Season:                     %s\n", crops_List[i].season);
        printf("Vendor:                     %s\n", crops_List[i].seller);
        printf("Silver Value:               %d\n", crops_List[i].silver_value);
        printf("Gold Value:                 %d\n", crops_List[i].golden_value);
        printf("Iridium Value:              %d\n", crops_List[i].iridium_value);
        printf("--------------------------------------------------\n");
        i++;
    }
}

void crop_farm_calculator(){
    int restant_days = 0;

    int harvests_possible = 0;
    int i = 0, tiles = 0, day = 0;
    printf("Insert the crop that you will use: ");
    char name[20];
    scanf(" %[^\n]", name);
    printf("Insert the amount of tiles that you will plant: ");
    scanf(" %d", &tiles);
    printf("Insert the first day that you will plant: ");
    scanf(" %d", &day);

    
    while(strcmp(crops_List[i].name,name)!=0){

        i++;

    }
    printf("\n\nInformations:\n");
    printf("--------------------------------------------------\n");
    printf("Name of the crop:           %s\n", crops_List[i].name);
    printf("Base Value:                 %d\n", crops_List[i].base_value);
    printf("Season:                     %s\n", crops_List[i].season);
    printf("Vendor:                     %s\n", crops_List[i].seller);
    printf("Silver Value:               %d\n", crops_List[i].silver_value);
    printf("Gold Value:                 %d\n", crops_List[i].golden_value);
    printf("Iridium Value:              %d\n", crops_List[i].iridium_value);
    printf("--------------------------------------------------\n");

    if(crops_List[i].regrow == -1){
        restant_days = 28 - day;
        float float_harvests_possible = restant_days / crops_List[i].grow;
        harvests_possible = (int) float_harvests_possible;

        printf("--------------------------------------------------\n");
        printf("Amount of harvests: %d\n", harvests_possible);
        printf("Days to plant and harvest: \n");
        int harvest_loops = day;
        for(int j = 1 ; j <= harvests_possible; j++){
            
        printf("Plant: %d\n", harvest_loops);
        harvest_loops += crops_List[i].grow;
        printf("Harvest: %d\n", harvest_loops);

        }


    }
    else{

        restant_days = 28 - (day + crops_List[i].grow);
        float float_harvests_possible = restant_days / crops_List[i].regrow;
        harvests_possible = 1+ float_harvests_possible;  

        printf("--------------------------------------------------\n");
        printf("Amount of harvests: %d\n", harvests_possible);
        printf("Days to plant and harvest: \n");
        int harvest_loops = day+crops_List[i].grow;

        printf("Plant: %d\n", day);

        for(int j = 1 ; j <= harvests_possible; j++){
            
        printf("Harvest: %d\n", harvest_loops);
        harvest_loops += crops_List[i].regrow;
        }



    }
    printf("--------------------------------------------------\n");
    printf("Profit(minimal): %d\n", crops_List[i].base_value * harvests_possible * tiles);
    printf("--------------------------------------------------\n");


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


void profit_calculator(){

    int var1 = 0;


}

void main_menu(){

    int option = 0;

    while(option != 9){

        printf("\n\n1. Select the character: \n");

        printf("2. Show all characters: \n");

        printf("3. Show all crops: \n");

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
        
        case 3:

            list_all_crops();

            break;

        case 9:

            break;


        }

    }

}