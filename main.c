#include <locale.h>
#include <stdio.h>
#include <wchar.h>
#include <string.h>
#include <stdlib.h>

struct temp_interval{
  float t0;
  float t1;
  float c1;
  float c2;
  float c3;
  float c4;
  float c5;
  float c6;
  float c7;
};

struct substance{
  wchar_t *name;
  char *formula;
  float molmass;
  float qf0;
  float qf298;
  float ne;
  float t;
  float cpt0;
  float ft0;
  float st0;
  float delh;
  float lgkt0;
  int num_of_intervals;
  struct temp_interval *temp_intervals;
};

int main(int argc, char **argv) {
  FILE *ivt;
  char buf[200];
  int num_of_substances;
  int i=0;
  int fooint;
  float foofloat;
  wchar_t foowchar[1000];
  struct substance *substances;

  
  setlocale(LC_ALL, "");
  if ( (ivt = fopen("IVT.DAT","r") ) == NULL ) {
      printf("ERROR\n");
      exit(1);
  }
  fscanf(ivt,"  %d",&num_of_substances);
  printf("num_of_substances=%d\n",num_of_substances);
  substances = malloc(num_of_substances*sizeof(struct substance));
  fscanf(ivt,"%d %ls", &fooint, foowchar );
  substances[0].name=wcsdup(foowchar);
  printf("i=%d name=%ls\n", fooint, substances[0].name);
exit(0);
  while ( fgets(buf,200,ivt) != NULL ) {
     printf("%s",buf);
  }

 
  printf("OK\n");
}
