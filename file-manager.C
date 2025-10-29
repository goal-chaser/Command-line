#include<stdio.h>
#include<string.h>
int create_file(char x[]){
    FILE *pfile = fopen(x,"w");
    if(pfile == NULL){
        printf("Error in writing the file.");
        return 1;
    }
    char text[1024];
    printf("--------------------------------------------------------------------------------------------");
    printf(">");
    while(1){
        fgets(text, sizeof(text), stdin);
        if(strcmp(text, "\n") == 0){
            printf(">");
        }
        text[strcspn(text , "\n")] = 0;
        if(strcmp(text, "//0") == 0){
            printf(">");
            break;
        }
        fprintf(pfile, "%s", text);
    }

    printf("The file has been created successfully");
    fclose(pfile);
    return 0;

}

int main(){
    char c[10],nf[24];
    printf(">");
    scanf("%[a-zA-z] %[a-zA-Z.]",c,nf);
    create_file(nf);
}

