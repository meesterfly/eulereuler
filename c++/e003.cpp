#include <iostream>
#include <list>


long long next_prime(std::list<long long> *kp) 
{
    for (long long i = kp->back()+2 ;; i++)
    {
        for (auto it = kp->begin(); it != kp->end(); it++)
            if (i % *it == 0)
                continue;

        return i;
    }
}


bool is_prime(long long x, std::list<long long> *kp)
{
    // Check if x is prime by seeing if it's divisible by any known primes
    for (auto it = kp->begin(); it != kp->end(); it++)
        if (x % *it == 0)
            return false;

    // If not, keep generating new primes to test with
    while (kp->back() < x)                                      
    {
        kp->push_back(next_prime(kp));
        if (kp->back() < x && x % kp->back() == 0)
            return false;
    }

    return true;
}


int main(void)
{
    // Our list of known prime numbers, starting with 2
    std::list<long long> kp = { 2, 3 };

    long long x = 600851475143;

    // Reduce x by dividing by its smallest prime factor until it is prime
    while (!is_prime(x, &kp))
        x /= kp.back();

    std::cout << x << std::endl;

    return 0;
}
