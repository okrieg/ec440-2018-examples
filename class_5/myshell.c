#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/wait.h>
#include <strings.h>
#include "parse.h"

/* 
 * input values are the line typed in by user, information deliminating the 
 * different tokens, ...
 * function returns ...
 */
int
executeLine(char *input, struct TokenInfo *toks, int totalCmds, int tokenCount)
{
  return 2; 			/* bogus */
}

int
get_line(char *input, int max)
{
  // read input line
  if(fgets(input, MAX_INPUT_LINE, stdin)==NULL){
    exit(0); 			/* we are done, EOF */
  }
  return 0; 
}


int
main(int argc, char* argv[])
{
  char input[MAX_INPUT_LINE];
  int print_prompt = 1;	/* start out printing the prompt */
  
  // process the input arguments

  while(1){ // main loop of shell
    int tokenCount = 0, totalCmds =0;
    struct TokenInfo tokens[MAX_TOKENS];
    
    if (print_prompt) {
      printf("shell5: ");
      fflush(stdout);
    }
    get_line(input, MAX_INPUT_LINE);
      
    tokenCount = parse(input, tokens, &totalCmds);
    if (tokenCount > 0) {	
      executeLine(input, tokens, totalCmds, tokenCount);
    }
  }
  return 0;
}

