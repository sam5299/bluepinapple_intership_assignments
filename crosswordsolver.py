def checkWords(word,position):
    for p in position.keys():
                if x[p] != position[p]:
                    return 1
    return 0

if __name__ == '__main__':

    word_dictionary = ['app','application','alot','attend','append','appliences','actually','basic','block','blue','clue','clone'
                    'cute','commins','coming','come','cross','dazon','slot','cobra','zebra']

    alphabetical = {}

    for word in word_dictionary:
        if word[0] not in alphabetical.keys():
            alphabetical.update({word[0]:[word]})
        else:
            temp = alphabetical[word[0]]
            temp.append(word)
            temp = sorted(temp,key=len)
            alphabetical[word[0]] = temp

    length = int(input('Enter length of word to find:'))
    position = {}

    for x in range(length):
        print(f'Give hint at position:{x}\npress enter to skip')
        value = input()
        if len(value.strip()) == 1:
            position.update({x:value})
        else:
            print('hint not added')

    final_words = []

    if 0 in position.keys():
        for x in alphabetical[position[0]]:
            if len(x)==length:
                temp = checkWords(x,position)
                if temp==0:final_words.append(x)
            elif len(x)>length:
                break
            else:
                continue
    else:
        for x in word_dictionary:
            if len(x)==length:
                temp = checkWords(x,position)
                if temp==0:final_words.append(x)

    if len(final_words)==0:print('no words found')
    else:print(final_words)