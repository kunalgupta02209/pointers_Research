#include<stdio.h>
#include<stdlib.h>

struct fraction
{
  int num, den;
};

void input_fractions(int *n, struct fraction fraclist[1000]);
void output_fraclist(struct fraction fraclist[1000], int n);
void output_fraction(struct fraction Frac);
struct fraction sum_2(struct fraction frac1, struct fraction frac2);
struct fraction sum_list(struct fraction fraclist[1000], int n);
int gcd(int a, int b);
struct fraction reduce(struct fraction frac);




void input_fractions(int *n, struct fraction fraclist[1000])
{
  int nu;
  printf("Enter no. of fractions\n");
  scanf("%d", &nu);
  *n = nu;
  //struct fraction fraclist[nu];
  for(int i = 0; i < nu; i++)
  {
    printf("Input the fraction sepertating the numerator and denominator by '/'\n");
    scanf("%d/%d", &fraclist[i].num, &fraclist[i].den);
  }
}

void output_fraclist(struct fraction fraclist[1000], int n)
{
  for(int i = 0; i< n; i++)
    output_fraction(fraclist[i]);
}

void output_fraction(struct fraction Frac)
{
  printf("%d/%d\n", Frac.num, Frac.den);
}

struct fraction sum_2(struct fraction frac1, struct fraction frac2)
{
  int num_sum = 0, den_prod = 1;
  num_sum = frac1.den*frac2.num + frac2.den*frac1.num;
  den_prod = frac1.den*frac2.den;
  struct fraction frac;
  frac.num = num_sum;
  frac.den = den_prod;
  return frac;
}

struct fraction sum_list(struct fraction fraclist[1000], int n)
{
  int i = 0;
  struct fraction frac;
  while( i < n)
  {
            if(i == 0)
            {
                frac = sum_2(fraclist[i], fraclist[i+1]);
                i += 2;
            }
            else
            {
              frac = sum_2(frac, fraclist[i]);
              i += 1;
            }

  }
  return frac;
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

struct fraction reduce(struct fraction frac)
{
	while(1)
	{
    int nu = frac.num;
    int de = frac.den;
    int n = gcd(frac.num, frac.den);
    frac.num = frac.num/n;
    frac.den = frac.den/n;
    if(frac.num == nu)
      break;
  }
  return frac;
}
int main()
{
  int n = 0;
  struct fraction frac_list[1000];
  input_fractions(&n, frac_list);
  struct fraction frac = sum_list(frac_list, n);
  frac = reduce(frac);
  output_fraction(frac);
  //output_fraclist(frac_list, n);
}
