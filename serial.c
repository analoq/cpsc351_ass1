/*
 * CPSC 351 - Assignment 1
 * Aaron Matthews
 * apmatthews@csu.fullerton.edu
 */
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  char line[128];
  int pid;

  FILE *fp = fopen("urls.txt", "rt");
  while ( fgets(line, 128, fp) )
  {
    if ( line[strlen(line)-1] == '\n')
      line[strlen(line)-1] = 0;

    pid = fork();
    if ( pid < 0 )
    {
      fprintf(stderr, "Unable to fork!\n");
      return -1;
    }
    if ( pid )
      wait(NULL);
    else
    {
      if ( execlp("/usr/local/bin/wget", "wget", line, NULL) < 0 )
      {
        fprintf(stderr, "Unable to exec!\n");
        return -1;
      }
    }
  }
  fclose(fp);

  return 0;
}
