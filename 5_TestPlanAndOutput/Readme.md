## High Level Test Plan
|Test ID|Description|Status|Input|Output|Type of Test|
|-------|-----------|------|-----|------|------------|
|HLR_1|Program should alter the Process List (accessed via 'ps' command)|Implemented|'ps' shows Process Status with IDs|'./a.out &': One Extra ID added |Scenario Based|
|HLR_2|Signals carried by SIGUSR1/SIGUSR2|Implemented|'signal(SIGUSR1,suspend); signal(SIGUSR2,resume);'|//SIGUSR1 Suspend, SIGUSR2 Resume|Requirement Based|
|HLR_3|Waiting/Execution Time in between the Signal Issues|Implemented|'pause();'|blocks until a signal arrives whose action is either to execute a handler function, or to terminate the process|Boundary Based|

## Low Level Test Plan
|Test ID|*Mapped To*|Description|Status|Input|Output|Type of Test|
|-------|-----------|-----------|------|-----|------|------------|
|LLR_1|HLR_1|'/a.out' for start process in background, '&' for multiple instance, the more you add the more ./a.out's are created. Also Job Control prints Job Number and Process ID.|Implemented|'./a.out &'|Process SNO & ID created|Scenario Based|
|LLR_2|HLR_2|'kill -USR1 ID' used to suspend the process|Implemented|'kill -USR1 NewID'|Process in queue to be Suspended, ID|Requirement Based|
|LLR_3|HLR_2|'kill -USR2 ID' used to resume the process|Implemented|'kill -USR2 NewId'|Process lined up to be Resumed, Exiting from Suspended State, ID|Requirement Based|
|LLR_4|HLR_3|'pause();' used wherever required, appropriately|Implemented|Used 3 times|Proper Wait Times|Boundary Based|
