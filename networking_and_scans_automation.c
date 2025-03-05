#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void help()
{
    //ipconfig,ifconfig ip addr,
    printf("  -sI show ip the machine is connected to\n");
    //with more details: arp, 
    printf("  -sIm show ip with more details\n");
    //default scan:nmap -sC -sV -v <ip addr>
    printf("  -sO our typical scan\n");
    //default scan with given port:nmap -sC -sV -v <ip addr> -p <port number>
    printf("  -sP default scan with given port\n");
    //intense scan plus UDP: nmap -sS -sU -T4 -v --traceroute
    printf("  -iU intense scan plus UDP\n");
    //slow comprenhesive scan:nmap -sS -sU -T4 -v -PE -PP -PS80,443 -PA3389 -PU40125 -PY -g 53 --traceroute
    printf("  -scs slow comprenhesive scan\n");
    //intensive scan, all TCP Ports:nmap -T4 -A -v -PE -PS22,25,80 -PA21,23,80,3389 --traceroute
    printf("  -sa intensive scan, all TCP Ports\n");
    //intense scan,no ping: nmap -T4 -A -v -Pn --traceroute
    printf("  -iN intense scan,no ping\n");
    //intense scan:nmap -T4 -A -v -PE -PS22,25,80 -PA21,23,80,3389 --traceroute -sC -sV
    printf("  -i intense scan\n");
    //quick scan:nmap -T4 --traceroute
    printf("  -q quick scan\n");
    //default,base nse script,force ipv6:nmap --script=default,safe -sS -sV -O -T4 -v -6 --traceroute
    printf("  -sF default,base nse script,force ipv6:\n");
    //default,base nse script:nmap --script=default,safe -sS -sV -O -T4 -v --traceroute
    printf("  -sdb default,base nse script\n");
    //default aggresive:nmap -A -sS -sV -O -T4 -v --traceroute
    printf("  -sA default aggresive\n");
    //default force ipv6:nmap -sS -sV -O -T4 -v -6 --traceroute
    printf("  -d6 default force ipv6\n");
    //default:mnap -sS -sV -O -T4 -v --traceroute 
    printf("  -d default scan\n");
    //wireshark
    printf("  -w watch live the traffic\n");
    //
    printf("  -e evil twin\n");
    //
    printf("  -m man in the middle\n");
    //nc -lnvc
    printf("  -l listen to a port\n");
    //python3 -m <port number>
    printf("  -c create simple server with port\n");
    //
    printf("  -xs xss code creation\n");
    //
    printf("  -xm create xml bomb size given by you\n");
    //
    printf("  -sd send deaufthentication packets\n");
}

void check(int system_inf)
{
    //check_nmap,check_wireshark,check_python,check_netcat
    int check_all[3],i,install;
    char a;
    //freopen("NUL", "w", stdout); can be used too,it's the same thing
    //nmap checking will execute but will not display any output or errors. > NUL 2>&1
    check_all[0]=system("nmap --version > NUL 2>&1");
    //wireshark checking will execute but will not display any output or errors. > NUL 2>&1
    check_all[1]=system("wireshark --version > NUL 2>&1");
    //python3 checking will execute but will not display any output or errors. > NUL 2>&1
    check_all[2]=system("python3 --version > NUL 2>&1");
    //netcat checking will execute but will not display any output or errors. > NUL 2>&1
    check_all[3]=system("nc -h > NUL 2>&1");
    int sum=0;
    //for each check we add it if it succeed
    for(i=0;i<=3;i++)
    {
        if(check_all[i]==0)
        {
            sum++;
        }
    }
    //if all tools exist then  we give the user a message
    if(sum==4)
    {
        printf("all tools are checked\n");
    }
    else
    {
        printf("Do you want to install the requirments? [y/n]\n");
        //loop that guarantes the a is y or Y or n or N as an asnwer
        while(1)
        {
            scanf("%c",&a);
            if(a=='y' || a=='Y' || a=='n' || a=='N')
            {
                //we stop the loop if the answer is what we wanted it to be
                break;
            }
            else
            {
                //otherwise we help the user with a message
                printf("answer must be y for yes or n for no\n");
            }
        }
        int check_all_installed=0;
        if(a=='y' || a=='Y')
        {
            //for each tool we install it with different way because of the os that is currently running
            if(system_inf==32)
            {
                //installation on windows
                if(check_all[0]!=0)
                {
                    //installing nmap
                    install=system("winget install nmap");
                    //checking if it made it
                    if(install==0)
                    {
                        printf("nmap installed\n");
                        check_all_installed++;
                    }
                    else
                    {
                        printf("nmap couldn't get installed");
                    }
                }
                else if(check_all[1]!=0) //installating wireshark
                {
                    install=system("winget install wireshark");
                    //checking if it made it
                    if(install==0)
                    {
                        printf("wireshark installed\n");
                        check_all_installed++;
                    }
                    else
                    {
                        printf("wireshark couldn't get installed");
                    }
                }
                else if(check_all[2]!=0)
                {
                    install=system("winget install python3");
                    if(install==0)
                    {
                        check_all_installed++;
                        printf("python3 installed\n");
                    }
                    else
                    {
                        printf("python3 couldn't get installed,try to install it from python.org or anywhere else\n");
                    }
                }
                else if(check_all[3]!=0)
                {
                    install=system("winget install netcat");
                    if(install==0)
                    {
                        check_all_installed++;
                        printf("netcat installed\n");
                    }
                    else
                    {
                        printf("netcat couldn't get installed\n");
                    }
                }
            }
            else if(system_inf==64 || system_inf==28)
            {
                //installation on linux and unix
                if(check_all[0]!=0)
                {
                    install=system("sudo apt install nmap");
                    if(install==0)
                    {
                        check_all_installed++;
                        printf("nmap installed\n");
                    }
                    else
                    {
                        printf("nmap couldn't get installed");
                    }
                }
                else if(check_all[1]!=0)
                {
                    install=system("sudo install wireshark");
                    if(install==0)
                    {
                        check_all_installed++;
                        printf("wireshark installed\n");
                    }
                    else
                    {
                        printf("wireshark couldn't get installed");
                    }
                }
                else if(check_all[2]!=0)
                {
                    install=system("sudo install python3");
                    if(install==0)
                    {
                        check_all_installed++;
                        printf("python3 installed\n");
                    }
                    else
                    {
                        printf("python3 couldn't get installed,try to install it from python.org or anywhere else\n");
                    }
                }
                else if(check_all[3]!=0)
                {
                    install=system("sudo install netcat");
                    if(install==0)
                    {
                        check_all_installed++;
                        printf("netcat installed\n");
                    }
                    else
                    {
                        printf("netcat couldn't get installed\n");
                    }
                }
            } 
            if( check_all_installed==4)
            {
                printf("Now all tools are installed");
            }
            else
            {
                printf("Aborting\n");
            }     
        }
        else
        {
            printf("exiting\n");
        }
    }
    system("rm NUL");
}

int main(int argc,char* argv[])
{
    int system_inf=0;
    //getting os information
    #ifdef _WIN32
        //windows
        system_inf=32;
    #elif __linux__
        //linux
        system_inf=64;
    #elif __unix__
        //unix 
        system_inf=28;
    #else
        //not in list
        system_inf=-1;
        printf("system not in list\n");
    #endif
    //checking requirments
    check(system_inf);
    //a help message to the user
    printf("For help type -h\n");
    //if you want to print what argv[1] has:printf("%s\n",argv[1]);
    //compare what 2 pointers has (the content)
    int command;
    char *ip;
    char full_command[200];
    char *port;
    if(strcmp(argv[1], "-h") == 0)
    {
    //calling help() function to print everything the user needs
        help();
    }
    if(argc==2)
    {
        if(strcmp(argv[1], "-sI") == 0)
        {
            if(system_inf==32)
            {
                command=system("ifconfig");
                if(command!=0)
                {
                    command=system("ip addr");
                }
            }
            if(system_inf==64 || system_inf ==28)
            {
                command=system("ip addr");
                if(command !=0)
                {
                    command=system("ifconfig");
                }
            }
        }
        else if(strcmp(argv[1], "-sIm") == 0)
        {
            if(system_inf==32)
            {
                command=system("arp");
                if(command!=0)
                {
                    command=system("ipconfig /all");
                }
            }
            if(system_inf==64 || system_inf ==28)
            {
                command=system("arp");
                if(command !=0)
                {
                    command=system("nmcli device show");
                }
            }
        }
        else if(strcmp(argv[1], "-sO") == 0)
        {
            printf("You must give an ip address,proccess aborts\n");
        }
        else if(strcmp(argv[1], "-sP") == 0)
        {
            printf("You must give an ip address and port number,proccess aborts\n");
        }
        else if(strcmp(argv[1], "-iU") == 0)
        {
            printf("You must give an ip address,proccess aborts\n");
        }
        else if(strcmp(argv[1], "-scs") == 0)
        {
            printf("You must give an ip address,proccess aborts\n");
        }
        else if(strcmp(argv[1], "-sa") == 0)
        {
            printf("You must give an ip address,proccess aborts\n");
        }
        else if(strcmp(argv[1], "-iN") == 0)
        {
            printf("You must give an ip address,proccess aborts\n");
        }
        else if(strcmp(argv[1], "-i") == 0)
        {
            printf("You must give an ip address,proccess aborts\n");
        }
        else if(strcmp(argv[1], "-q") == 0)
        {
            printf("You must give an ip address,proccess aborts\n");
        }
        else if(strcmp(argv[1], "-sF") == 0)
        {
            printf("You must give an ip address,proccess aborts\n");
        }
        else if(strcmp(argv[1], "-sdb") == 0)
        {
            printf("You must give an ip address,proccess aborts\n");
        }
        else if(strcmp(argv[1], "-sA") == 0)
        {
            printf("You must give an ip address,proccess aborts\n");
        }
        else if(strcmp(argv[1], "-d6") == 0)
        {
            printf("You must give an ip address,proccess aborts\n");
        }
        else if(strcmp(argv[1], "-d") == 0)
        {
            printf("You must give an ip address,proccess aborts\n");
        }
        else if(strcmp(argv[1], "-w") == 0)
        {
            system("sudo wireshark");
        }
        else if(strcmp(argv[1], "-e") == 0)
        {
            printf("You must give an ip address,proccess aborts\n");
        }
        else if(strcmp(argv[1], "-m") == 0)
        {
            printf("You must give an ip address,proccess aborts\n");
        }
        else if(strcmp(argv[1], "-l") == 0)
        {
            printf("You must give a port number,proccess aborts\n");
        }
        else if(strcmp(argv[1], "-c") == 0)
        {
            printf("You must give a port number,proccess aborts\n");
        }
        else if(strcmp(argv[1], "-xs") == 0)
        {
            printf("You must create a server,then give the ip and the port of the server and the ip and the port of the target\n");
        }
        else if(strcmp(argv[1], "-xm") == 0)
        {
            printf("You must give a number,the number tells how big the bomb be\n");
        }
        else if(strcmp(argv[1], "-sd") == 0)
        {
            printf("Choose one of the following internet connections\n");
        }
    }
    else if (argc == 3)
    {
        if(strcmp(argv[1], "-sO") == 0)
        {
            //storing in a pointer the address of the argv[2]
            ip=argv[2];
            strcpy(full_command,"nmap -sC -sV -v ");
            strcat (full_command, ip);
            //executing the full comand which is nmap -sC -sV -v <ip_address>
            system(full_command);
        }
        else if(strcmp(argv[1], "-sP") == 0)
        {
            printf("You must give aport number too,proccess aborts\n");
        }
        else if(strcmp(argv[1], "-iU") == 0)
        {
            //storing in a pointer the address of the argv[2]
            ip=argv[2];
            strcpy(full_command,"nmap -sS -sU -T4 -v --traceroute ");
            strcat (full_command, ip);
            //executing the full_comand
            system(full_command);
        }
        else if(strcmp(argv[1], "-scs") == 0)
        {
            //storing in a pointer the address of the argv[2]
            ip=argv[2];
            strcpy(full_command,"nmap -sS -sU -T4 -v -PE -PP -PS80,443 -PA3389 -PU40125 -PY -g 53 --traceroute ");
            strcat (full_command, ip);
            //executing the full_comand
            system(full_command);
        }
        else if(strcmp(argv[1], "-sa") == 0)
        {
            //storing in a pointer the address of the argv[2]
            ip=argv[2];
            strcpy(full_command,"nmap -T4 -A -v -PE -PS22,25,80 -PA21,23,80,3389 --traceroute ");
            strcat (full_command, ip);
            //executing the full_comand
            system(full_command);
        }
        else if(strcmp(argv[1], "-iN") == 0)
        {
            //storing in a pointer the address of the argv[2]
            ip=argv[2];
            strcpy(full_command,"nmap -T4 -A -v -Pn --traceroute ");
            strcat (full_command, ip);
            //executing the full_comand
            system(full_command);
        }
        else if(strcmp(argv[1], "-i") == 0)
        {
            //storing in a pointer the address of the argv[2]
            ip=argv[2];
            strcpy(full_command,"nmap -T4 -A -v -PE -PS22,25,80 -PA21,23,80,3389 --traceroute -sC -sV ");
            strcat (full_command, ip);
            //executing the full_comand
            system(full_command);
        }
        else if(strcmp(argv[1], "-q") == 0)
        {
            //storing in a pointer the address of the argv[2]
            ip=argv[2];
            strcpy(full_command,"nmap -T4 --traceroute ");
            strcat (full_command, ip);
           //executing the full_comand
            system(full_command);
        }
        else if(strcmp(argv[1], "-sF") == 0)
        {
            //storing in a pointer the address of the argv[2]
            ip=argv[2];
            strcpy(full_command,"nmap --script=default,safe -sS -sV -O -T4 -v -6 --traceroute ");
            strcat (full_command, ip);
            //executing the full_comand
            system(full_command);
        }
        else if(strcmp(argv[1], "-sdb") == 0)
        {
            //storing in a pointer the address of the argv[2]
            ip=argv[2];
            strcpy(full_command,"nmap --script=default,safe -sS -sV -O -T4 -v --tracerout ");
            strcat (full_command, ip);
            //executing the full_comand
            system(full_command);
        }
        else if(strcmp(argv[1], "-sA") == 0)
        {
            //storing in a pointer the address of the argv[2]
            ip=argv[2];
            strcpy(full_command,"nmap -A -sS -sV -O -T4 -v --traceroute ");
            strcat (full_command, ip);
            //executing the full_comand
            system(full_command);
        }
        else if(strcmp(argv[1], "-d6") == 0)
        {
            //storing in a pointer the address of the argv[2]
            ip=argv[2];
            strcpy(full_command,"nmap -sS -sV -O -T4 -v -6 --traceroute ");
            strcat (full_command, ip);
            //executing the full_comand
            system(full_command);
        }
        else if(strcmp(argv[1], "-d") == 0)
        {
            //storing in a pointer the address of the argv[2]
            ip=argv[2];
            strcpy(full_command,"mnap -sS -sV -O -T4 -v --traceroute ");
            strcat (full_command, ip);
            //executing the full_comand
            system(full_command);
        }
        else if(strcmp(argv[1], "-w") == 0)
        {
            printf("too many arguments\n");
        }
        else if(strcmp(argv[1], "-e") == 0)
        {
            //evil twin
            printf("You must give an ip address,proccess aborts\n");
        }
        else if(strcmp(argv[1], "-m") == 0)
        {
            //man in the middle
            printf("You must give an ip address,proccess aborts\n");
        }
        else if(strcmp(argv[1], "-l") == 0)
        {
            //storing in a pointer the address of the argv[2]
            port=argv[2];
            strcpy(full_command,"nc -tunlp ");
            strcat (full_command, port);
            //executing the full_comand
            system(full_command);
        }
        else if(strcmp(argv[1], "-c") == 0)
        {
            //storing in a pointer the address of the argv[2]
            port=argv[2];
            strcpy(full_command,"python3 -m http.server ");
            strcat (full_command, port);
            //executing the full_comand
            system(full_command);
        }
        else if(strcmp(argv[1], "-xs") == 0)
        {
            FILE *fptr;
            // Open a file in writing mode
            fptr = fopen("filename.txt", "w");
            char *number=argv[2];
            //data for xss will be put here
            fprintf(fptr,"");
            fclose(fptr);

        }
        else if(strcmp(argv[1], "-xm") == 0)
        {
            //converting the argv[2] into an integer
            int x = atoi(argv[2]);
            if(x>0)
            {
                char c;
                FILE *fptr;
                // Open a file in writing mode
                fptr = fopen("bomb.txt", "w");
                fprintf(fptr, "<?xml version=\"1.1\"?>\n<!DOCTYPE lolz [\n\t<!ENTITY lol \"lol\">\n\t<!ENTITY lol2 \"&lol;&lol;&lol;&lol;&lol;&lol;&lol;&lol;&lol;&lol;\">");
                if(x>=2)
                {
                    int n;
                    char xml[100]="\n\t<!ENTITY lol2 \"&lol;&lol;&lol;&lol;&lol;&lol;&lol;&lol;&lol;&lol;\">";
                    for(int i=2;i<=x;i++)
                    {
                        //convert i to char
                        c = (char)i;
                        n=i-1;
                        xml[17]=c;
                        c = (char)(n);
                        xml[24]=c;
                        xml[29]=c;
                        xml[34]=c;
                        xml[39]=c;
                        xml[44]=c;
                        xml[49]=c;
                        xml[54]=c;
                        xml[59]=c;
                        xml[64]=c;
                        xml[69]=c;
                        fprintf(fptr,xml);
                        printf("%s",xml);
                    }
                }
                fprintf(fptr,"\n]>\n<lolz>&lol9;</lolz>");
                fclose(fptr);
            }
        }
    }
    return 0;
}