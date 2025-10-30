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
    while(1){
        char ch = _getch();
        if(ch == 27){
            printf("\n");
            break;
        }

        else if(ch == '\r'){
            fputc('\n',pfile);
            printf("\n");
        }
        else if(ch == 8){
            printf("\b \b");
            fputc('\b \b', pfile);
        }
        else{
            fputc(ch,pfile);
            printf("%C",ch);
        }
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

