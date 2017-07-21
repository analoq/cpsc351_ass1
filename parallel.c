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
  int count;

  FILE *fp = fopen("urls.txt", "rt");
  for ( count = 0; fgets(line, 128, fp); count ++ )
  {
    if ( line[strlen(line)-1] == '\n')
      line[strlen(line)-1] = 0;
    if ( !fork() )
      execlp("/usr/bin/wget", "wget", line, NULL);
  }
  fclose(fp);

  while ( count-- )
    wait(NULL);
  return 0;
}
