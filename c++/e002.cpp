#include <iostream>

int main(void)
{
    long sum = 0;

    long fib2 = 1,
         fib1 = 1;

    long next = fib1 + fib2;

    while (next <= 4000000)
    {
        if (next % 2 == 0)
            sum += next;

        fib2 = fib1;
        fib1 = next;

        next = fib1 + fib2;
    }

    std::cout << sum << std::endl;

    return 0;
}