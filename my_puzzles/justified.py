#!/usr/bin/env python3

words = ['this', 'list', 'is', 'a', 'bunch', 'of', 'words', 'to', 'justify']
maxLen = 13
line = ''
res = []

for i in range(len(words)):
    line += words[i]
    if i + 1 < len(words) and len(line) + 1 + len(words[i + 1]) < maxLen:
        line += ' '
        continue

    if len(line) == maxLen:
        res.append(line)
    else:
        charCnt = 0
        lineWords = line.split(' ')
        # count number of spaces needed
        for word in lineWords:
            charCnt += len(word)
        # insert number of spaces
        print('charCnt', charCnt)
        i = 0
        # add spaces to each word one at a time until all together = maxLen
        while len(''.join(lineWords)) < maxLen:
            if len(lineWords) > 1:
                lineWords[i % (len(lineWords) - 1)] += ' '
            else:
                lineWords[0] += ' '
            i += 1
            print('+spaces:', '"' + ''.join(lineWords) + '"')
        res.append(''.join(lineWords))

    line = ''
    print('lineLen', len(''.join(lineWords)))
    print(res)
