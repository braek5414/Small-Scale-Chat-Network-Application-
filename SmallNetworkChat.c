// Chat Network Application 

//-----------------------------------------------------------------------------
// Main
//-----------------------------------------------------------------------------

int main(int argc, char* argv[])
{
    char* remoteIp;
    char str[100];
    int port = REMOTE_PORT;
    int timeout = 100;
    bool quit = false;
    int check = 0;
    char quitcheck[] = {"QUIT"};

    bool goodArguments = (argc == 2);
    if (goodArguments)
    {
        remoteIp = argv[1];
    }
    else
    {
        printf("usage: chat IPV4_ADDRESS\n");
        printf("  where:\n");
        printf("  IPV4_ADDRESS is address of the remote machine\n");
        exit(EXIT_FAILURE);
    }

    check = openUdpListenerPort(port);
   // Create the correct if condition

   
    if(check == 0)
    {
        printf("Port failed to open, exiting....");
        exit(EXIT_FAILURE);
    }
   

    // Print heading so that sent and received messages are in different columns
    printf("Sent\t\t\t\t\t\tReceived\n");
    
    // Start chat loop until someone types a string starting with QUIT
    while(!quit)
    {
        if(kbhit())
        {
            fgets(str, sizeof(str),stdin);
            sendUdpData(remoteIp, port, str);

            if (strncmp(quitcheck, str, 4) == 0)
            {
                quit = true;
            }
        }

        if(receiveUdpData(str, sizeof(str), timeout)){
            printf("\t\t\t\t\t\t%s", str);
        
            if (strncmp(quitcheck, str, 4) == 0)
            {
                printf("\t\t\t\t\t\t%s", str);
                quit = true;
            }

        }
    }

    void closeUdpListenerPort();
    return EXIT_SUCCESS;
}
