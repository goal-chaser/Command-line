#include<stdio.h>
#include<conio.h>
#include<string.h>
int create_file(char x[]){
    FILE *pfile = fopen(x,"w");
    if(pfile == NULL){
        printf("Error in writing the file.");
        return 1;
    }

    printf("--------------------------------------------------------------------------------------------\n");
    printf(">");
    char buffer[4096];
    while(1 == 1){
        int i;
        fgets(buffer, sizeof(buffer), stdin);
        i = strcspn(buffer, "\n");
        buffer[i] = '\0';
        if(strcmp(buffer, "^e") == 0){
            printf("\n");
            break;
        }
        fprintf(pfile, "%s\n", buffer);
    }
    printf("The file has been created successfully");
    fclose(pfile);
    return 0;

}

int main(){
    char c[10],nf[24];
    printf("> ");
    scanf("%[a-zA-z] %[a-zA-Z.]",c,nf);
    create_file(nf);
}

