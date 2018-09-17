/* parch3.c: simple example of a fork system call

   This example prints hello, then forks off a child process.
   Both parent and child then inspect the return value from the fork
   and print that value and who they are...

 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
  pid_t myid, newid;
  int status;

  myid=getpid();
  printf("Hello from parent process %d!  \n", myid);
  fflush(stdout); // flush output buffer

  if ((newid=fork())){
    wait(&status);
    printf("I was the proud parent of new process %d which has now exited with status %x.\n",
        newid, status);
    fflush(stdout);
  } else {
    printf("Hi. I am new the child.  My parent is %d\n",myid);
    fflush(stdout);
  }
}
