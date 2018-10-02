#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
  int n =0, o = 0, l = 0;
  char st[102];
  scanf("%s", st);
  for(int i =0; i < strlen(st); i++)
  {
    if(st[i] == 'o')
      o++;
    else
      l++;
  }
  if(o == 0)
    printf("YES");
  else if(l%o == 0)
    printf("YES");
  else
    printf("NO");
  return 0;
}
