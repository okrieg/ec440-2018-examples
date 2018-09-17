# Class 5 Examples
In class 5, we showed three examples that may have relevance to the work you need to do for project 1:

1. **Signal example:** Runs a never-ending counting loop which can be interrupted by SIGINT (^C from the keyboard). The first N times, a message is printed out.  After N times, the default stop action is taken.  N is the command line argument for the program.
*Source: [forever.c](forever.c)*

2. **Parent Child Example:** Simple fork where parent and child print a line. *Sources: [pch.c](prch.c) [no wait]; [prchwait.c](prchwait.c) [parent waits].*

3. **Pipe Example:** *(from Silbershatz & Gagne)* Parent sends a text message to the child. *Source: [up.c](up.c)
