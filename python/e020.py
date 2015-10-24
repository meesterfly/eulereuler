import numpy as np


def multiply(big_num, lil_num):
    '''
    Multiply a "big" number (represented as a string) by a smaller one.

    Args:
        big_num (str): The big number string to multiply.
        x (int): The smaller number to multiply by.
    Returns:
        str, the result as a string.
    '''

    new_num = ''

    carry = 0

    for digit in reversed(big_num):
        x = int(digit) * lil_num + carry
        new_num += str( x % 10 )
        carry = int( np.floor(x/10) )

    if carry > 0:
        return str(carry) + new_num[::-1]
    else:
        return new_num[::-1]


def factorial(x):
    '''
    Computes x! as a large string number.

    Args:
        x (int): The number to find the factorial of.
    Returns:
        str, the result as a string.
    '''

    ans = '1'

    for i in range(2, x+1):
        ans = multiply(ans, i)

    return ans


def e020():
    '''
    Problem 20: Find the sum of digits in 100!
    '''

    print reduce(lambda x,y: int(x)+int(y), factorial(100))


if __name__ == '__main__':
    e020()

