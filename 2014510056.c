#include <stdio.h>
#include <string.h>
 
/////////// XML FİLE STRUCTURE  ///////////////
struct my_data
{
int r_id;
char *first_name;
char *last_name;
char *email;
char *phone_number;
char *address;
};

void createdata(FILE *fb,struct my_data testData)
{
fprintf ( fb,"<row id %d>\n",testData.r_id);
fprintf ( fb,"<first_name> %s </first_name>\n",testData.first_name);
fprintf ( fb,"<last_name> %s </last_name>\n",testData.last_name);
fprintf ( fb,"<email> %s </email>\n",testData.email);
fprintf ( fb,"<phone_number> %s </phone_number\n",testData.phone_number);
fprintf ( fb,"<address> %s </address>\n",testData.address);
fprintf ( fb,"</row>\n");
fprintf ( fb,"\n");
}

///////////////////////////////////////////////////////////

int main(void) {
    printf("CSV2XML <inputfile> <outputfile> \n");
    printf("CSV2XML ");

    char inputfile[35];
    char outputfile[35];
    int p1;
    int p2;
    scanf("%s %s", &inputfile, &outputfile);
    printf("separator 1 or 2 or 3 ");
    scanf(" %d", &p1);
    printf("opsys 1 or 2 or 3 ");
    scanf("%d", &p2);


FILE *fp = fopen(inputfile, "r"); //csv file reading
FILE *fb=fopen(outputfile,"w"); //xml file creating

    if (!fp) {
        printf("Can't open file \n");
        return 0;
    }
        char *operate;
        switch(p2){
            case 1:
            operate="windows";
            break;
            case 2:
            operate="linux";
            break;
            case 3:
            operate="macos";
            break;
            default:
            operate="linux";
        }
    char buf[1024];
    int row_count = 0;
    int field_count = 0;
    while (fgets(buf, 1024, fp)) {
        field_count = 0;
        row_count++;

     
        if (row_count == 1) {
            continue;
        }

        char *field;
        switch(p1){
            case 1:
            field=strtok(buf, ",");
            break;
            case 2:
            field=strtok(buf, "\t");
            break;
            case 3:
            field=strtok(buf, ";");
            break;
            default:
            printf("you did not choose any separator\n");
        }

        int i=0;
        struct my_data testData;
        while (field) {

            if (field_count == 0) {
             testData.first_name=field; 
            }
            if (field_count == 1) {
             testData.last_name=field;
            }
            if (field_count == 2) {
             testData.email=field;
            }
            if (field_count == 3) {
             testData.phone_number=field;
            }
            if (field_count == 4) {
             testData.address=field;
            }

            
            printf("%s\n", field);
            field = strtok(NULL, ",");
            
            field_count++;
        }
            fprintf ( fb,"<?xml version=\"1.0\" encoding=\"utf-8\"?>\n");
            printf("\n");
            testData.r_id=row_count-1;
            createdata(fb,testData);
                
    }

    fclose(fp);
    return 0;
}