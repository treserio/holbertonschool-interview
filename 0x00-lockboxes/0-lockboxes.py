#!/usr/bin/python3
''' You have n number of locked boxes in front of you. Each box is numbered
sequentially from 0 to n - 1 and each box may contain keys to the other boxes.
Write a method that determines if all the boxes can be opened. '''


def canUnlockAll(boxes):
    ''' Can all the boxes be opened starting at the zero index? '''
    keyset = {0}

    for key in boxes[0]:
        if (0 <= key < len(boxes)) and key not in keyset:
            boxes[0].extend(boxes[key])
            keyset.add(key)

    return len(keyset) == len(boxes)
