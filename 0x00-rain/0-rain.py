#!/usr/bin/python3

'''
Given a list of non-negative integers representing the heights of walls
with unit width 1, as if viewing the cross-section of a relief map,
calculate how many square units of water will be retained after it rains.

Prototype: def rain(walls)
walls is a list of non-negative integers.
Return: Integer indicating total amount of rainwater retained.
Assume that the ends of the list (before index 0 and after index walls[-1])
are not walls, meaning they will not retain water.
If the list is empty return 0.
'''


def rain(walls):
    ''' calculate water retention '''
    bucket = 0
    if walls:
        for i in range(1, len(walls) - 1):
            l_wall = max(walls[i], (max(walls[:i])))
            r_wall = max(walls[i], (max(walls[i + 1:])))
            bucket += min(l_wall, r_wall) - walls[i]
    return bucket
