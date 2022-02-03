#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<sys/file.h>

void suspend(int sigid);
void resume(int sigid);
void handler(int sigid);
 
int main()
{
signal(SIGUSR1,suspend); //SIGUSR1 Suspend
signal(SIGUSR2,resume); //SIGUSR2 Resume

pause();

if (signal(SIGINT, handler) == SIG_ERR) //SIG_ERR Error
printf("\n SIGINT failed \n");
while(1) 
sleep(1);
return 0;
}

void suspend(int sigid)
{
printf("\n Process in queue to be Suspended \nSignal ID: %d\n",sigid);
pause();
printf("\n Exiting from Suspended State \n");
}
void resume(int sigid)
{
printf("\n Process lined up to be Resumed \nSignal ID: %d\n",sigid);
}

void handler(int sigid)
{
if (sigid == SIGINT)
printf("\n Process made defaultly to be Terminated \n");
}
