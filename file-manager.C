#include<stdio.h>
#include<string.h>
#include<unistd.h>

int create_file(char x[],char sc[]){
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

int open_file(char nf[],char sc[]){
    char buffer[4096] = {0};
    FILE *popfile = fopen(nf, "r");
    if(strcmp(sc, "-r") == 0){
        FILE *popfile = fopen(nf, "r");
        while(fgets(buffer, sizeof(buffer), popfile) != NULL){
            printf("%s",buffer);
        }
        printf("\n");
    }
    if(popfile == NULL){
        printf("Error opening a file.");
        return 1;
    }
    
    if(strcmp(sc, "-rw") == 0){
        char bufferw[4096];
        popfile = fopen(nf,"a");
        printf("--------------------------------------");
        while(1 == 1){
            printf("> ");
            int i;
            fgets(bufferw, 4096, stdin);
            i = strcspn(bufferw, "\n");
            bufferw[i] = '\0';
            if(strcmp(bufferw, "^e") == 0){
                printf("\n file has been updated");
                break;
            }
            fprintf(popfile, "%s\n", bufferw);
        }
    }

    fclose(popfile);
    return 0;
}

int main(){
    char c[10],nf[24],sc[4];
    printf("> ");
    scanf("%[a-zA-Z] %[a-zA-Z.-] %[a-zA-Z-]",c,nf,sc);
    if(strcmp(c,"pwd") == 0 && strcmp(nf,"-") == 0 && strcmp(sc,"-")){
        char d[1024];
        if(getcwd(d, sizeof(d)) != NULL)
        printf("%s\n",d);
        else
        printf("Error in retriving the directory.");
    }
    if(strcmp(c, "file") == 0){
        if(strcmp(sc, "-c") == 0){
            create_file(nf,sc);
        }            
        else if(strcmp(sc, "-r") == 0|| strcmp(sc, "-rw") == 0){
            open_file(nf,sc);
        }
    }
    else{
        printf("Invalid command");
    }
}

