#include <stdio.h>
#include <math.h>


double Denom(double inf)
{
  double first_sum = 0.0;
  for(double u = 1; u <= inf; ++u){
    first_sum += pow(4.0/5.0, u - 1);
  }
  double first_product = 1.0;
  for(double u = 4; u <= 12; ++u){
    first_product *= pow(1.01, u - 1);
  }
  return first_sum + first_product;
}

double TY(double inf)
{
  double inner_sum = 0.0;
  for(double i = 1; i <= inf; ++i){
    inner_sum += 5.0*pow(1.0/2.0, i - 1);
  }
  double sum_a = 0.0;
  for(double k = 3; k <= 8; ++k){
    sum_a += pow(k, 2) - k - inner_sum;
  }
  double sum_b = 0.0;
  for(double k = 2; k <= inf; ++k){
    sum_b += 4.0*pow(1.0/3.0, k - 1);
  }
  return sum_a + sum_b;
}

double TX(double inf)
{
  double sum_x = 0.0;
  for(double k = 1; k <= inf; ++k){
    sum_x += (1.0/2.0)*pow(3.0/4.0, k - 1);
  }
  return sum_x;
}

double Problem(double x, double y, double inf)
{
  double product = 1.0;
  double sum_val = 0.0;
  double final_total = 0.0;
  for(double n = x; n <= y; ++n){
    product = 1.0;
    sum_val = 0.0;
    for(double a = 3; a <= 11; ++a){
      product *= (1.0 - 1.0/pow(a, 2))*n;
    }
    for(double b = 2; b <= 13; ++b){
      sum_val += (2.0/(pow(b, 2) - 1))*pow(n, 2);
    }
    final_total += product + sum_val;
  }
  return final_total;
}

int main()
{
  double inf = 1000000;

  double denominator = Denom(inf);
  double B = TY(inf);
  double A = TX(inf);
  double neumerator = Problem(A, B, inf);

  double final_answer = neumerator / denominator;

  printf("Final Answer %f\n", final_answer);

  return 0;
}
