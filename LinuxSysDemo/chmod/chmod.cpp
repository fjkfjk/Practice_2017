//An implemention of chmod in bash shell commands

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char** argv)
{
  int mode;
  int mode_u;    //users
  int mode_g;    //group
  int mode_o;    //other user

  char* file_path;

  if(argc < 3)
  {
    printf("%s <mode num> <target file>\n",argv[0]);
    exit(0);
  }

  mode = atoi(argv[1]);
  if(mode > 777 || mode < 0)
  {
    printf("mode num error!\n");
    exit(0);
  }

  mode_u = mode / 100;
  mode_g = (mode - mode_u * 100) /10;
  mode_o = mode - mode_u * 100 - mode_g * 10;
  mode = mode_u * 8 * 8 + mode_g * 8 + mode_o;

  file_path = argv[2];

  if(chmod(file_path,mode) == -1)
  {
    perror("chmod error");
    exit(1);
  }

  return 0;
}
