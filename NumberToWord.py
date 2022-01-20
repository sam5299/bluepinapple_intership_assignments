import sys
if __name__ == '__main__':
    number = input("Enter number:")
    if not number.isnumeric() :
        sys.exit("Please enter number only")
    elif int(number) < 0:
        sys.exit("Currentcy never be negative")
    word_array = []
    
    number_chart = ['','','hundred','thousand','thousand','thousand','million','million','million',
    'billion','billion','billion','trillion','trillion','trillioin','quadrillion','quadrillioin','quadrillion',
    'quintillion','quintillion','quintillion','sextillion','sextillion','sextillion','septillion','septillion','septillion',
    'octillion','octillion','octillion','nonillion','nonillion','nonillion','decillion','decillion','decillion',
    'undecillion','undecillion','undecillion','deudecillion','deudecillion','deudecillion','tredecillion','tredecillion','tredecillion',
    'quattuordecillion','quattuordecillion','quattuordecillion','quindecillion','quindecillion','quindecillion ']
    
    twenty_ninghty = ['','','twnenty','thirty','fourty','fifty','sixty','seventy','eighty','ninety']

    one_nine = ['','one','two','three','four','five','six','seven','eight','nine']
    
    eleven_ninteen = {'10':"ten",'11':'eleven','12':'twelve','13':'thirteen','14':'fourteen','15':'fifteen','16':'sixteen',
                    '17':'seventeen','18':'eighteen','19':'nineteen'}
    
    def handleTwo(twodigit):
        #temp = str(abs(int(twodigit)))
        if len(twodigit) == 2:
            if twodigit[0] == '1':
                return eleven_ninteen[twodigit]
            else:
                first = twenty_ninghty[int(twodigit[0])]
                second = one_nine[int(twodigit[1])]
                return first+" "+second
        return one_nine[int(twodigit)]
    
    def handleThree(threedigit):
        temp = str(abs(int(threedigit)))
        if len(temp) == 3:
            first = one_nine[int(temp[0])]
            two = handleTwo(temp[1:])
            return first+" hundred "+two;
        
        combine = handleTwo(temp)
        return combine
    
    while(len(number) > 0):
        rem = len(number)%3
        if rem==0 : rem =3
        position = number_chart[len(number) - rem]
        tempnumber = number[:rem]
        result = handleThree(tempnumber)
        word_array.append(result)
        word_array.append(position)
        if len(number[rem:]) > 0:
            number = str(abs(int(number[rem:])))
        else:
            number = ''
    print(" ".join(word_array))