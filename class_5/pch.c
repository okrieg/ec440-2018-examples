/* parch2.c: simple example of a fork system call

   This example prints hello, then forks off a child process.
   Both parent and child then inspect the return value from the fork
   and print that value and who they are...

 */

#include <stdio.h>
#include <unistd.h>

int main()
{
  pid_t myid, newid;

  myid=getpid();
  printf("Hello from parent process %d!  ", myid);
  fflush(stdout); // flush output buffer

  if ((newid=fork())){
    printf("I am the proud parent of new process %d.\n",newid);
    fflush(stdout);
  } else {
    printf("Hi. I am new the child.  My parent is %d\n",myid);
    fflush(stdout);
  }
}
