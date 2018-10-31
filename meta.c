#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

int main()
{
  struct stat randbuggy;
  stat("makefile", &randbuggy);

  //printf("Printing file size in bytes: %ld\n",randbuggy.st_size);
  char buffer[100];
  int file_size = randbuggy.st_size;
  if(file_size<1000)
  {
    sprintf(buffer,"Size of file: %d bytes\n",file_size);
  }
  else if(1000<=file_size<1000000)
  {
    float kb = (float)file_size/1000.0;
    sprintf(buffer,"Size of file: %f kb\n",kb);
  }
  else if(1000000<=file_size<1000000000)
  {
    float mb = (float)file_size/1000000.0;
    sprintf(buffer,"Size of file: %f mb\n",mb);
  }
  else if(1000000000<=file_size)
  {
    double gb = (double)file_size/1000000000.0;
    sprintf(buffer,"Size of file: %f gb\n",gb);
  }
  printf("%s",buffer);

  printf("Printing mode, permissions: %o\n",randbuggy.st_mode);
  int last_9 = randbuggy.st_mode & 0b111111111;
  printf("Printing permissions in ls -l form: %o\n",last_9);
  printf("Printing time of last access: %s\n",ctime(&randbuggy.st_atime));
  return 0;
}
