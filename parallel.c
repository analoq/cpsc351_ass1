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
  int pid, count;

  FILE *fp = fopen("urls.txt", "rt");
  for ( count = 0; fgets(line, 128, fp); count ++ )
  {
    if ( line[strlen(line)-1] == '\n')
      line[strlen(line)-1] = 0;
    pid = fork();
    if ( pid < 0 )
    {
      fprintf(stderr, "Unable to fork!\n");
      return -1;
    }
    if ( !pid )
    {
      if ( execlp("/usr/bin/wget", "wget", line, NULL) < 0 )
      {
        fprintf(stderr, "Unable to exec!\n");
        return -1;
      }
    }
  }
  fclose(fp);

  while ( count-- )
    wait(NULL);
  return 0;
}
