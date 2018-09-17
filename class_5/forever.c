/* Signal Example Program This program illustrates a signal handler
   for SIGINT.  It counts integers as fast as it can, printing at
   intervals specified by it argument.  When it receives SIGINT, it
   prints its current count and decrements a counter named 'chances'.
   When chances is 0, the SIGINT handler is switched back to the
   default handler.
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>


// These global variables are access both by the handler and main!
unsigned long long total=0; 	// a ridiculously large counter
int chances;			// number of interrupts remaining 
int flag=0;		    // flag for main to print after interrupt 


void myhandler(int);            /* declaration of the handler function */

const struct sigaction defint={SIG_DFL,0,0,0}; // sigaction for default handler 
const struct sigaction mine={myhandler,0,0,0};  // sigaction for our handler 


void myhandler(int signum){
  flag=1; // sets a flag that main reads to know if interrupt occurred 
  --chances;			// decrement chance counter 
  if (chances<=0){		// if there are no more chances,
				// then revert to default handler
    if (sigaction(SIGINT,&defint,NULL) != 0) {
      perror("sigact in myhandler\n");
      exit(-1);
    }
  }
}

int
main(int argc, char *argv[])
{
  unsigned long j;
  
  if (argc!=2){
    fprintf(stderr,"Usage: %s <max interrupts>\n",argv[0]);
    exit(1);
  }
  chances=atoi(argv[1]);
  
  printf("I will count forever unless you interrupt me more than %d times!\n",
	 chances);
  
  sigaction(SIGINT,&mine,NULL);	//change SIGINT handler to "myhandler"
  
  while(1){			// forever loop
    for (j=0;j<1000000000;++j){	// count 1 billion per print line
      ++total;
      if (flag) {
	printf("\nInterrupted at count %lld: ",total);
	if (chances>0){
	  printf("you have %d more chances!\n",chances);
	} else {
	  printf("next time is the end!\n");
	}
	flag=0;
      }
    }
    printf(" %lld\n",total);
  }
  return 0;
}
