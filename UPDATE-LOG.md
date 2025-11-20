# Command-line
Creating a command line using C for the back end and using python for the GUI.
# ---------------------------------------------------USER MANUAL--------------------------------------------------------------------------------------

TYPE "help" in the program to get the manual

# -------------------------------------------------------------------------------------------------------------------------------------------------
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
        
        DATE: 13/11/25 and 14/11/25

            In these two days we have written the working code for changing directories and listing the contents in them, by doing this we can roam around the system files with just the command prompt we can also create, edit and read files in the directory we are in.
            
            For this we have created the following functions:
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
        The first condition here we are using a pre defined strict dirent from the header file and naming it list a pointer to it, 
        after that we are creating a pointer named dir what is the data type DIR(directory related info), and storing the output of opendir function which is a pointer to the directory we have given.

        Next the readdir function which has a pre defined structure in the header file, and in that we have a element d_name which contains the name of the contents the readdir is currently looking at in the directory we have opened.
        and we run the loop until the readdir has read all the contents in the open directory and has returned NULL marking the end.

        Next we will be using the closedir funciton to close the directory we have opened.

        Date: 16/11/25:
            Today we will be building a ping command function into our program.

            We are using AI to learn about the header files we need to build it, the funcitons we need to use, how to use them and how they work.
            
            The functions we are gonna be using are:
            1. socket();
            2. setsockopt();
            3. inet_pton();
            4. sendto();
            5. recvfrom();

        1. SOCKET();
            This function is used to set up a socket, allocate the resources to send and recieve packets, set up filters to only allow ICMP packets.
            This funciton returns a number to describe the socket.
            STRUCTURE:
                socket(domain, type, ip protocol);
                for our case we are going to use IPv4 for the domain, raw_socket for type and icmp protocol.

        2. setsockopt():
            This function is used to set the rules for the communication between the devices, the info coming in and out.
            STRUCTURE:
                setsockopt(socket, level, optname, optval, optlen);
                for our case we are going to set the socket as number we get from the first function.
                level is a socket_level.
                optname as SO_RCVTIMEO (this waits to receive the message until a set time if not we get time out message).
                optval is set as &optval this is a pointer to the struct timeval predefined struct.
                and finally the oplen which is the memeory size of the struct.
        
        3. inet_ption();
            This funciton is used to convert the human readable address like 8.8.8.8 to binary.
            STRUCTRUE:
                inet_ption(af, src, dst);
                for our case we are setting af as af_ient(converts from ip format)
                and src is the ip address in text form.
                dst is the place where we are going to store the converted address &dest_addr.sin_addr(this is a pre defined struct).
        
        4. sendto();
            This function is used to send the icmp packets to the correct destination.
            STRUCTURE:
                sendto(socket, buf, len, flags, dest_addr, addrlen);
                For our case we are going to give the number we get from the socket function.
                Next the buf is set as data we have to send which is the icmp packet we created.
                len is the size of this icmp packet.
                des_addr is set the binary form we get from the inet_ption function.
                addrlen is the size of the destination address.
        5. recvfrom();
            We are letting the OS to wait and listen for the reply from the target and calculates round time trip and ends waiting once the timeout has reached.
            STRUCTURE:
                recvfrom(socket, buf, len, flags, src_addr, addrlen);
                socket is set the number we get from the socket function in the first step.
                buf is the buffer to store any info we recieve.
                flags is set a 0.
                src addr is set to NULL because we don't care where it is coming we know its from the our target.
                and addrlen is set to NULL because we are not accepting any src addr.

        Date: 17/11/25:
            Today marks the completion of the code for the ping funciton. Here we will see the explanation of the code one by one.

                First we will typedef the WSADATA(WSA stands for windows socket API) to wsadata for easier typing, then we will tell the OS of the computer to start the network operations by calling WSAstartup(the first argument is the version we are going to use, this data is filled by OS(wsadata));

                Then we will check for the errors we get if it is not executed properly.

                Now we will go on and call the socket function to create a socket to use it to send and recieve data. we have explained the what are its arguments and its output.

                we will check to errors its going to return if something goes sideways.

                Then we will set the rules that this socket must follow, like what it accepts like the timeout funciton the socket number, its ip version etc.

                We will check for its errors its going to return.

                then we will call a pre defined struct called sockaddr_in which contains information like port value, its family like ip version etc.
                we will set there values as per the values documented in google for icmp packets.

                then we will use the inet_pton funciton to conver the human readable ip or dns address to binary form which will be used by the sendto function in the future.

                then we will construct the struct for the icmp header information according to the documentation given in the google search.

                then we will create a function to calculate the checksum which is used to check for errors in the echo of icmp.
                the checksum function is written as per the doc given in the google search.

                Then we will go on to use the QueryPerformacefrequency, QueryPerformaceCounter function to hekp calculate the round trip time taken.

                We will use the sendto() function and recvfrom() function to send and recieve the icmp echo request and the echo from the target.

                then we will wrap it up by calculate the round trip and printing it.

                Today we will be aiming to create a help function.

        Date: 18/11/25
            Today we will be aiming to code the necessary functions to view our system information(everything) including CPU cahes, RAM usage etc etc.
            
