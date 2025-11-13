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
    So, this is the code that actaully works after a lot of trail and erros.
    WHAT THIS CODE DOES:
        First the fgets() function waits for the user to enter the data, and when the user presses the enter key, it stops reading 
        and stores the data like the \n in the buffer, after that we will be removing the new line character from the buffer,
        because we want to keep typing data or entering data until a specific key is typed to exit the text editor.
        And when we are satified with the amount of data we have entered or wanted to store in a file, we will enter a newline and
        type ^e to exit the text editor.
        After we press the new line character the fgets funciton will stop reading, and we will remove the new line character, we will check if the user has entered ^e seperately and if not we will directly print the data stored in the buffer.
        now because of the loop we will again make the program wait the user to enter data in a completely new line, and the process continues.
    ---------------------------------------------------------------------------------------------------------------------
    THIS MARKS THE COMPLETION OF THE WORKING OF TEXT EDITOR WITHOUT THE FEATURE OF ARROW KEYS.
    date:11/11/2025
    today we have completely changed the method of decision making and string parsing.
    previously we just used if and else and three different variables to store different commands.
    PREVIOUS METHOD:

        As shown in the user manual the different commands like -r file and file name are used to be stored in different dedicated variables,
        this made the structure of command very rigid for change in the future.
    NEW METHOD:

        Now, we are using the function called strtok() to tokenize the string with spaces, this made the structure of the command flexible and can be changed on the future use.
        We first initilized a pointer named token to store the tokens given by the strtok() after using it using loop we have moved to the next token and stored it in the memeory location.

        if(fgets(input, sizeof(input), stdin) != NULL)
        input[strcspn(input, "\n")] = '\0';
        char *token = strtok(input, " ");
        while(token != NULL)
        Here we removed the next line character so that the strtok() doesn't tokezie that too leading to errors.

    LEARNINGS:
        The new header file <unistd.h> the use of this header file specifically for our code is the use of the function getcwd() which returns the directory the code is currently running in by getting the info from the OS.
        The header file mainly provides access to the POSIX operating system which is desinged by Unix its a set of standards, this helps the developers to interact with the operating system irrespective of the types(like windows,Linux,MacOS), In our case it helps with retreaving the information of directories and files operations.

