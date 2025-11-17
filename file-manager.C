#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<unistd.h>
#include<dirent.h>
#include<errno.h>
#include<stdbool.h>

int ping_f(char[]);

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
        if(strcspn(buffer, "^e") == 0){
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
        printf("--------------------------------------\n");
        while(1 == 1){
            printf("> ");
            int i;
            fgets(bufferw, 4096, stdin);
            i = strcspn(bufferw, "\n");
            bufferw[i] = '\0';
            if(strcspn(bufferw, "^e") == 0){
                printf("\n file has been updated");
                break;
            }
            fprintf(popfile, "%s\n", bufferw);
        }
        fclose(popfile);
        return 0;
    }
char help[] = "# ---------------------------------------------------USER MANUAL--------------------------------------------------------------------------------------\n"
"\n"
"To do any type of changes related to a file, the command structure goes like:\n"
"    file <action you want to perform> <the file name if in the same directory or relative path of the file>\n"
"        For the actions you want to perform:\n"
"        <-c> for creating a file.\n"
"        <-r> for reading an existing file.\n"
"        <-rw> for appending an existing file.\n"
" \n                                                                                                                                                                    "
"    For performing directory related actions \n"
"            STRUCTURE: cd <file name or relative file path> or to move back into the previous directory <..>\n"
"       To print the directory you are currently present in <pwd>.\n"
"        To print the contents present in the directory <ls>.\n"
"        To move to a desired directory:\n"
"            If the desired folder is present in the current directory folder name is enough.\n"
"            If the desired folder is not present in the current directory then relative file path is neccessary.\n"
"        To check if a host you want to connect to is alive or not use ping then the address of the host.          \n" 
"\n"
"-------------------------------------------------------------------------------------------------------------------------------------------------\n";

int list(char *x){
    struct dirent *list;
    DIR *dir = opendir(x);
    if(dir == NULL){
        perror("opendir failed");
        return 1;
    }
    
    while((list = readdir(dir)) != NULL){
        printf("%s \n",list -> d_name);
    }
    if(errno != 0){
        perror("readdir failed");
        return 1;
    }
    if(closedir(dir) != 0){
        perror("close dir failed");
    }

    return 0;
}

void change_directory(char *y){
    int check;
    check = chdir(y);
    if(check != 0){
        perror("error in chdir");
    }
}

int main(){
    while(1 == 1){
    char wd[1024];
    char input[100];
    if(fgets(input, sizeof(input), stdin) != NULL){
        input[strcspn(input, "\n")] = '\0';
        char *token = strtok(input, " ");
        if(strcmp(token, "exit") == 0){
            break;
        }
        if(strcmp(token, "file") == 0){
            token = strtok(NULL, " ");
            if(strcmp(token, "-c") == 0){
                token = strtok(NULL, " ");
                create_file(token);
            }
            else if(strcmp(token, "-r") == 0){
                token = strtok(NULL, " ");
                read_file(token);
            }
            else if(strcmp(token, "-rw") == 0){
                token = strtok(NULL, " ");
                edit_file(token);
            }
            else{
                printf("Invalid command");
            }
        }
        if(strcmp(token, "pwd") == 0){
            getcwd(wd, sizeof(wd));
            printf("%s\n",wd);
        }
        if(strcmp(token, "ls") == 0){
            getcwd(wd, sizeof(wd));
            list(wd);
        }
        if(strcmp(token, "cd") == 0){
            token = strtok(NULL,"");
            change_directory(token);
        }
        if(strcmp(token, "ping") == 0){
            token = strtok(NULL, "");
            while(1 == 1){
                ping_f(token);
                Sleep(1000);
                }
            }
        if(strcmp(token, "help") == 0){
            printf("%s",help);
        }
}
}
}
