#include <iostream>


int get_chain_length(const int _x)
{
    long x = _x;
    int i = 0;

    while (x != 1)
    {
        if (x % 2 == 0)
            x = x/2;
        else
            x = 3*x + 1;
        i++;
    }

    return i;
}


int main(void)
{
    int longest_length = 0;
    int answer = 0;

    for (int i = 2; i < 1000000; i++)
    {
        int length = get_chain_length(i);

        if (length > longest_length)
        {
            answer = i;
            longest_length = length;
        }
    }

    std::cout << answer << std::endl;

    return 0;
}