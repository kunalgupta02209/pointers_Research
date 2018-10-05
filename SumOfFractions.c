#include<stdio.h>
#include<stdlib.h>

struct fraction
{
  int num, den;
};

struct fractions
{
  int n;
  struct fraction fracs[1000];
};

struct fractions input_fractions(struct fractions frac_list);
void output_fraclist(struct fractions frac_list);
void output_fraction(struct fraction Frac);
struct fraction sum_2(struct fraction frac1, struct fraction frac2);
struct fraction sum_list(struct fractions frac_list);
int gcd(int a, int b);
struct fraction reduce(struct fraction frac);




struct fractions input_fractions(struct fractions frac_list)
{
  printf("Enter no. of fractions\n");
  scanf("%d", &frac_list.n);
  //struct fraction fraclist[nu];
  for(int i = 0; i < frac_list.n; i++)
  {
    printf("Input the fraction sepertating the numerator and denominator by '/'\n");
    scanf("%d/%d", &frac_list.fracs[i].num, &frac_list.fracs[i].den);
  }
  return frac_list;
}

void output_fraclist(struct fractions frac_list)
{
  for(int i = 0; i< frac_list.n; i++)
  output_fraction(frac_list.fracs[i]);
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

struct fraction sum_list(struct fractions frac_list)
{
  int i = 0;
  struct fraction frac;
  while( i < frac_list.n)
  {
    if(i == 0)
    {
      frac = sum_2(frac_list.fracs[i], frac_list.fracs[i+1]);
      //output_fraction(frac);
      i += 2;
    }
    else
    {
      frac = sum_2(frac, frac_list.fracs[i]);
      //output_fraction(frac);
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
  struct fractions frac_list;
  frac_list = input_fractions(frac_list);
  struct fraction frac = sum_list(frac_list);
  frac = reduce(frac);
  output_fraction(frac);
  //output_fraclist(frac_list);
}
