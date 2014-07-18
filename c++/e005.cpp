#include <iostream>
#include <vector>

int main(void)
{
    std::vector<int> a;

    // get list of numbers that don't evenly divide with 20
    for (int i = 2; i < 20; i++)
        if (20 % i != 0)
            a.push_back(i);

    int x = 20;
    for (;;)
    {
        x += 20; // Increment by 20 (biggest jump we can make)
        bool b = true;
        for (auto it = a.begin(); it != a.end(); it++)
        {
            if (x % *it != 0)
            {
                b = false;
                break;
            }
        }
        if (b)
            break;
    }

    std::cout << x << std::endl;

    return 0;
}