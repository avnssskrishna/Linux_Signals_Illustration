# Linux Signals Illustration
A brief illustration performed on the Linux Ubuntu Terminal showing how the process of signals goes and how actions like suspend &amp; resume work.

## End-Goal
The sole intention is to introduce & explain Signals as part of **Inter Process Communication i.e. _IPC_**.

## Author/Programmer Information
| PS No. | Name | GitHub Username |
---------|-------------|----------------|
`40020843` | Sai Krishna Atchutanna | avnssskrishna |

# Requirements

## Introduction (with ofcourse the Research)
A Signal is basically any command to the Linux Kernel, say a gesture or an expression. If the Terminal is the body of Linux, Signal is the body language of it. It dictates & disrupts how processes work. A _Software Interrupt_.

## Objective (The Motivation & The Inspiration)
To utilize the power of signals on the path of process glory.

## 4Ws and 1H

### What
A pure program consisting of pure signal commands.
### When
Right there, right now when the processes are being run. Same instance, multiple operations. Literally.
### Where
On the beautifully robust Linux Ubuntu Terminal.
### How
Refer to the Report for the detailed document. (Documentation guys, your chance to shine)

### Why 
_Held this back for this_

FUN & PASSION!!!

## SWOT Analysis

### Strengths
Reliable Signals: A state in between the Creation & Success is introduced, called the Pending State. There Signal is blocked but then will work whenever summoned.

### Weaknesses
Unreliable Signals: Lost ones, the process won't even know one occured. Sad.

### Oppurtunities
Abundant

### Threats
Redundancy

## High Level Requirements:  
|ID|Description|Status|
|--|------------|------|
|HLR_1|Program should alter the Process List (accessed via 'ps' command)|Implemented|
|HLR_2|Signals carried by SIGUSR1/SIGUSR2|Implemented|
|HLR_3|Waiting/Execution Time in between the Signal Issues|Implemented|
|HLR_4|More Signal Commands to be Integrated|Future|

## Low Level Requirements:
|ID|*Mapped To*|Description|Status|
|--|-----------|-----------|------|
|LLR_1|HLR_1|'/a.out' for start process in background, '&' for multiple instance, the more you add the more ./a.out's are created. Also Job Control prints Job Number and Process ID.|Implemented|
|LLR_2|HLR_2|kill -USR1 used to suspend the process|Implemented|
|LLR_3|HLR_2|kill -USR2 used to resume the process|Implemented|
|LLR_4|HLR_3|pause(); used wherever required, appropriately|Implemented|
|LLR_5|HLR_4|After the current signal commands, play around with the rest 31-odd standards|Future|


# Design
![Signal Processes](https://github.com/avnssskrishna/Linux_Signals_Illustration/blob/72277bfbce3754a5ac94d7045391a430832f1987/2_Design/Signal%20Processes.png)

## Base Code

![Main File Link (Click!)](https://github.com/avnssskrishna/Linux_Signals_Illustration/blob/main/3_Implementation/src/signals.c)

```sh
#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<sys/file.h>

void suspend(int sigid);
void resume(int sigid);
void handler(int sigid);

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

void handler(int sigid)
{
if (sigid == SIGINT)
printf("\n Process made defaultly to be Terminated \n");
}
```
![Initial Execution](https://github.com/avnssskrishna/Linux_Signals_Illustration/blob/72277bfbce3754a5ac94d7045391a430832f1987/4_Media/Initial%20Execution.png)
![Process Execution](https://github.com/avnssskrishna/Linux_Signals_Illustration/blob/72277bfbce3754a5ac94d7045391a430832f1987/4_Media/Initial%20Execution.png)
