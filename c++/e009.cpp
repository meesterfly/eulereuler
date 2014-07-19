#include <iostream>

int main(void)
{
    int answer = 0;

    // All positive non-zero integers m, n where m > n
    for (int m = 2; ; m++)
    {
        for (int n = 1; n < m; n++)
        {
            // Euclid's formula for pythagorean triples
            int a = m*m - n*n,
                b = 2*m*n,
                c = m*m + n*n;

            if (a + b + c == 1000)
            {
                answer = a*b*c;
                break;
            }
        }

        if (answer != 0)
            break;
    }

    std::cout << answer << std::endl;

    return 0;
}