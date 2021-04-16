/**
 *      file    :  unique.c
 *      author  :  deepak_jangra
 *      created :  2021 Apr 16 11:48:50  IST
 *      lastMod :  Friday 16 April 2021 11:48:50 AM IST
 **/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
typedef struct uni
{

  char *ma;
  char ch;

}uni;

int unique(uni a)
{
  int flag,i,len;
  len = strlen(a.ma);
  for(i = 0 ; i < len ; i++)
  {
    if(*(a.ma + i) == a.ch)
    {
      flag = 0;
      return flag;
    }
  }
  flag = 1;
  return flag;

}

int main()
{
  printf("%s : Begin\n",__func__);
  int fd,ret,i,len;
  char *ma,*ch;
  uni a;
  fd = open("inputfile", O_RDONLY);

  printf("FD : %d\n", fd);
  if(fd == -1)
  {
    perror("open");
    exit(EXIT_FAILURE);
  }

  a.ma = (char*)malloc(sizeof(char)*128);


  memset(a.ma,'\0',128);
  i = 0;
  while(1)
  {

    ret = read(fd,&a.ch,1);

    if(ret == -1)
    {
      perror("read");
      exit(EXIT_FAILURE);
    }
    if(ret == 0)
      break;

    if(unique(a))                           //Call unique fn...if it return 1 then value of ch assign to (ma + i) otherwise not
      *(a.ma + i++) = a.ch;
  }

  printf("%s\n", a.ma);
  printf("%s : End\n",__func__);
  printf("%s End\n", __func__);
  return 0;
}    

