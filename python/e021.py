import numpy as np


def sum_divisors(n):
    '''
    Get the sum of proper divisors of n

    Args:
        n (int): The number to evaluate.
    Returns
        int, the sum of proper divisors.
    '''

    ans = 1
    for x in range(2, n):
        if n % x == 0:
            ans += x
    return ans


def e021():
    '''
    Problem 21: Amicable Numbers
    '''

    ans = 0

    for n in range(2, 10000):
        x = sum_divisors(n)
        if n != x and sum_divisors(x) == n:
            ans += n + x

    print ans


if __name__ == '__main__':
    e021()

