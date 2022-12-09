#!/usr/bin/python3
"""Prime Game Module"""


def isWinner(x, nums):
    """Function that determines if a player is the winner"""
    # set up the prime numbers for the game
    if not nums or x < 1:
        return None
    n = max(nums)
    primes = [True for i in range(n + 1)]
    primes[0] = False
    primes[1] = False
    for i in range(2, int(n ** 0.5) + 1):
        if primes[i]:
            for j in range(i * i, n + 1, i):
                primes[j] = False
    # set start point of game
    count = 0
    for i in range(n + 1):
        if primes[i]:
            count += 1
        primes[i] = count
    # determine winner if not Maria then Ben
    Maria = 0
    for n in nums:
        if primes[n] % 2 == 1:
            Maria += 1
    if Maria * 2 == len(nums):
        return None
    elif Maria * 2 > len(nums):
        return "Maria"
    else:
        return "Ben"
