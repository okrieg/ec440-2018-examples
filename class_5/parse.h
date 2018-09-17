/*
 * parsing functionality:
 *   TokenType defines the different tokens returned
 *   ...
 */

enum TokenType {
  TTArgument,
  TTCommand,
  TTOutRedir,
  TTInRedir,
  TTBackground,
  TTPipe
};

#define MAX_SIZE_TOKEN 32
#define MAX_INPUT_LINE 512
#define MAX_TOKENS 15

struct TokenInfo {
  enum TokenType type;		/* type of token from enum above */
  /* other stuff we removed */
};
  
/*
 * what is the return value, and what are the different parameters
 * as well as what the contents of the different pointers are on return
 */
int parse(char *input, struct TokenInfo *toks, int *totalCmdsPtr);
