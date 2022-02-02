#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<sys/file.h>

void suspend(int sigid);
void resume(int sigid);

int main()
{
signal(SIGUSR1,suspend);
signal(SIGUSR2,resume);
pause();
}

void suspend(int sigid)
{
printf("Process is in Queue to be Suspended \nSignal ID: %d\n",sigid);
pause();
printf("Exiting from Suspended State \n");
}
void resume(int sigid)
{
printf("Proceeding Signal to Resume \nSignal ID: %d\n",sigid);
} 
