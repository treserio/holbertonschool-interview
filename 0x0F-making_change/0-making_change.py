#!/usr/bin/python3
''' Given a pile of coins of different values, determine the fewest number of
coins needed to meet a given amount total.
'''


def makeChange(coins, total):
    ''' Given a pile of coins of different values, determine the fewest number
    of coins needed to meet a given amount total.
    '''
    coinList = [0] * (total + 1)
    coins.sort(reverse=True)

    # print(coins)
    for coin in coins:
        # print('coin=', coin)
        # check for existing
        for i in range(coin, total + 1):
            # print(i, coinList[i], end=', ')
            if (coinList[i - coin]):
                if (coinList[i]):
                    coinList[i] = min(coinList[i], coinList[i - coin] + 1)
                else:
                    # add 1 to previous
                    coinList[i] = coinList[i - coin] + 1
            elif (not i % coin):
                coinList[i] += 1
            # print(coinList[i], end='|')

    # print(coinList[total])
    return coinList[total] if coinList[total] else -1
