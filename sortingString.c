#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int comparator(const void *p,const void *q)
{
    char *str1 = *(int *)p;
    char *str2 = *(int *)q;
    return strcmp(str1,str2);
}
//It sorts the the string pointer array but the last element is junk value in the individual pointer array
//another new commit with a (char cast) will give segmentation fault

char** input(int *num)
{
    printf("Enter number of strings\n");
    scanf("%d",num);
    char **a;
    a= (char **)malloc(*num*sizeof(char *));
    char *str;
    for(int i=0;i<*num;i++)
    {
        char s[1000] = "";
        printf("Enter the %d string\n",i+1);
        scanf("%s",s);
        str=malloc(sizeof(s));
        for(int j=0;s[j] !='\0';j++)
           {
               *(str+j)= s[j];
           }
        a[i]=str;
    }
    return a;
}

void output(char **a, int *num)
{
    for(int i=0;i<*num;i++)
        printf("%s\n",*(a+i));
}

int main()
{
    int *num;
    num = (int*)malloc(sizeof(int*));
    char **a = input(num);
    qsort((void *)a, *num, sizeof(a[0]), comparator);
    output(a, num);
    return 0;
}
