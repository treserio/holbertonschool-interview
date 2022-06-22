#!/usr/bin/python3
''' module to implement minOperations function '''


def minOperations(n):
    ''' fewest copy / paste of 1 char to reach n
        prime factors are used since to create a prime it takes the prime
        number of operations so we can return their summation

        Args:
            n (number): the number of characters to reach

        Returns:
            number: the fewest operations to reach n
    '''
    # print('input', n)
    if n < 2:
        return 0
    ops = 0
    factor = 2
    # reduce by factor until unable, then move to next prime
    while n > 1:
        if not n % factor:
            n //= factor
            ops += factor
            # print('n /', factor, '=', n)
        else:
            if factor == 2:
                factor += 1
            else:
                factor += 2
    return ops
