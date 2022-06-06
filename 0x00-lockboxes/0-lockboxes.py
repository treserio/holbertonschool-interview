#!/usr/bin/python3
''' You have n number of locked boxes in front of you. Each box is numbered
sequentially from 0 to n - 1 and each box may contain keys to the other boxes.
Write a method that determines if all the boxes can be opened. '''


def canUnlockAll(boxes):
    ''' Can all the boxes be opened starting at the zero index? '''
    keyset = {0}

    def boxOpener(open=0):
        ''' Opening boxes using available keys '''
        for key in boxes[open]:
            if not (0 <= key < len(boxes)) or key in keyset:
                continue
            keyset.add(key)
            boxOpener(key)

    boxOpener()
    # print(keyset)
    return len(keyset) == len(boxes)
