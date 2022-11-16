#!/usr/bin/python3
''' Given a pile of coins of different values, determine the fewest number of
coins needed to meet a given amount total.
'''

def makeChange(coins, total):
    ''' Given a pile of coins of different values, determine the fewest number
    of coins needed to meet a given amount total.
    '''
    count = 0
    for coin in sorted(coins, reverse=True):
        count += total // coin
        total %= coin
    return count if not total else -1
