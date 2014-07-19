#include <iostream>
#include <list>


long long next_prime(std::list<long long> *kp) 
{
    for (long long i = kp->back()+2 ;; i++)
    {
        bool b = true;

        for (auto it = kp->begin(); it != kp->end(); it++)
        {
            if (i % *it == 0)
            {
                b = false;
                break;
            }
        }

        if (b)
            return i;
    }
}


int main(void)
{
    std::list<long long> kp = { 2, 3 };
    long long sum = 2;

    // Go make coffee or something while this runs q:
    while (kp.back() < 2000000)
    {
        sum += kp.back();
        kp.push_back(next_prime(&kp));
    }

    std::cout << sum << std::endl;

    return 0;
}