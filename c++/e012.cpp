#include <iostream>
#include <cmath>

int divisors_in_number(long x)
{
    int d = 2;
    for (long i = 2; i <= sqrt(x); i++)
    {
        if (x % i == 0)
            d += 2;
        if (i*i == x)
            d -= 1;
    }
    return d;
}


int main(void)
{
    long ans = 0, i = 1;

    while (divisors_in_number(ans) <= 500)
        ans += i++;

    std::cout << ans << std::endl;

    return 0;
}