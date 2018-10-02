#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int comparator(const void *p,const void *q)
{
    return strcmp(*((char  **)p),*((char  **)q));
}
//It sorts the the string pointer array but the last element is junk value (still) in the individual pointer array
//and no segmentation fault as it was expected earlier
//the segmentation fault was because of some other malloc issue that is fixed in this code

char** input(int *num)
{
    int n;
    printf("Enter number of strings\n");
    scanf("%d",&n);
    *num=n;
    char **a;
    a= (char **)malloc(n*sizeof(char *));
    char s[1000] = "";
    for(int i=0;i<n;i++)
    {
        printf("Enter the %d string\n",i+1);
        scanf("%s",s);
        a[i]=malloc(sizeof(s)+1);
        strcpy(a[i],s)
    }
    return a;
}

void output(char **a, int *num)
{
    for(int i=0;i<*num;i++)
        printf("%s\n",a[i]);
}

int main()
{
    int num;
    char **a = input(&num);
    qsort((void *)a, num, sizeof(a[0]), comparator);
    output(a, num);
    return 0;
}
