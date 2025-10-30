# Command-line
Creating a command line using C for the back end and using python for the GUI.

Today's date: 29/10/2025
Today i am planning to start the project and first we will start by coding the file managing funciton:
So, to manage files we have different functions and those are:
1) Create a file to write information in it like a notepad;
2) Being able to delete the file that is written; with confirmation;
3) Being able to open the file to re write its contents and then save it;
4) Being able to switch to directories, like cd etc.
5) Being able to list the documents present in the directories. 

For today i will try to write the code the logic of parsing the entered string and be able to open the create and open the file, and able to enter the data:
So the command to create a file is:
    create "File name.type of file".
    if the file already exists we get a message and has option to edit the file.

Todays date is 30/10/25
    And i havent been able to complete the work of the text editor in the terminal, this version of the code works but the new line character is not being reflected in the text editor file.
    And i have decided to use windows header file to receive input but before that i will try to send eah character entered by the user to be sent immediately to the editor for writing a file.
    And if that does'nt work i will continue the work using the windows header file.


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
            printf("\b \b);
        }
        else{
            fputc(ch,pfile);
            printf("%C",ch);
        }
    }

    This version of the code, newline character is being reflected in the file, backspace and arrow keys need to be delt.

    else if(ch == 8){
            printf("\b \b);
        }
    -------------------------------------- NEW UPDATED VERSION(WORKS AS INTENDED) -----------------------------------------------
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

    Adding this version to the code, makes the backspace to work and is being printed in the text file. DONE
    ---------------------------------------------------------------------------------------------------------------------
    THIS MARKS THE COMPLETION OF THE WORKING OF TEXT EDITOR WITHOUT THE FEATURE OF ARROW KEYS.
