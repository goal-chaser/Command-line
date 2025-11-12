#include<stdio.h>
#include<string.h>
#include<unistd.h>

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

int read_file(char nf[]){
    char buffer[4096] = {0};
    FILE *popfile = fopen(nf, "r");
    
        while(fgets(buffer, sizeof(buffer), popfile) != NULL){
            printf("%s",buffer);
        }
        printf("\n");
    
    if(popfile == NULL){
        printf("Error opening a file.");
        return 1;
    }
    fclose(popfile);
    return 0;
}

int edit_file(char nf[]){
    FILE *popfile = fopen(nf, "a");
        char bufferw[4096];
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
        fclose(popfile);
        return 0;
    }



int main(){
    char wd[1024];
    char input[100];
    if(fgets(input, sizeof(input), stdin) != NULL){
        input[strcspn(input, "\n")] = '\0';
        char *token = strtok(input, " ");
        while(token != NULL){
            if(strcmp(token, "file") == 0){
                token = strtok(NULL, " ");
                if(strcmp(token, "-c") == 0){
                    token = strtok(NULL, " ");
                    create_file(token);
                    break;
                }
                else if(strcmp(token, "-r") == 0){
                    token = strtok(NULL, " ");
                    read_file(token);
                    break;
                }
                else if(strcmp(token, "rw") == 0){
                    token = strtok(NULL, " ");
                    edit_file(token);
                    break;
                }
                else{
                    printf("Invalid command");
                }
            }
            if(strcmp(token, "pwd") == 0){
                getcwd(wd, sizeof(wd));
                printf("%s\n",wd);
                break;
            }
        }
    }
}

