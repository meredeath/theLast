#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

int main(){
  struct stat randbuggy;
  stat("makefile", &randbuggy);
  
  printf("Printing file size: %ld\n",randbuggy.st_size);
  printf("Printing mode, permissions: %o\n",randbuggy.st_mode);
  printf("Printing time of last access: %s\n",ctime(&randbuggy.st_atime));
  return 0;
}
