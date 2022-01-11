import sys

try:
    number = input('Enter number:')
    number = number.strip()

    #if user enter non numeric value terminate the program 
    if not number.isnumeric():
        sys.exit("Please enter digits only")
    elif int(number) < 0: #if user enter negative value
        sys.exit("currency never be negative value")

    number = str(abs(int(number))) # getting absolute value by removing preceeding zero's which of no meaning

    #list to get currency word by length of word
    number_chart = ['','','','hundred','thousand','thousand','thousand','million','million','million',
    'billion','billion','billion','trillion','trillion','trillioin','quadrillion','quadrillioin','quadrillion',
    'quintillion','quintillion','quintillion','sextillion','sextillion','sextillion','septillion','septillion','septillion',
    'octillion','octillion','octillion','nonillion','nonillion','nonillion','decillion','decillion','decillion',
    'undecillion','undecillion','undecillion','deudecillion','deudecillion','deudecillion','tredecillion','tredecillion','tredecillion',
    'quattuordecillion','quattuordecillion','quattuordecillion','quindecillion','quindecillion','quindecillion ']

    #if number is above or equal to 20 this will return 10th place value 
    twenty_ninghty = ['','','twnenty','thirty','fourty','fifty','sixty','seventy','eighty','ninety']

    #this will return value for single digit from 0-9
    one_nine = ['','one','two','three','four','five','six','seven','eight','nine']

    #if two digit number in between 1-19 this directory will return number in word by matching keys
    eleven_ninteen = {'10':"ten",'11':'eleven','12':'twelve','13':'thirteen','14':'fourteen','15':'fifteen','16':'sixteen',
                    '17':'seventeen','18':'eighteen','19':'nineteen'}

    #list to hold words
    number_in_words = []

    select_factor = 0 #number grouping factor

    initial_length = 0 #initally we have visited no digits in number so zero

    #function to handle two digit number
    def handle_two(two):
        two = str(abs(int(two))) #remove the preceding zero if both number are zero then return 0
        #print(two)
        if len(two) == 2: 
            if two[0]=='1':
                word = eleven_ninteen[two]
                return word
            else:
                tenth_place = twenty_ninghty[int(two[0])] #getting decimal place value of first digit of number
                first_place = one_nine[int(two[1])]       #getting single digit value of remaining number
                return tenth_place+" "+first_place
        elif len(two)==1:#if number was preceded by 0
            first_place = one_nine[int(two[0])]          #getting single digit value of number 
            return first_place
        else:#if both the digits were 0
            return " "

    #function to handle three digits 
    def handle_three(three):
        three = str(abs(int(three))) #removing preecding zeros
        if len(three)==3:#if no preceding zero
            first_palce = one_nine[int(three[0])]
            other = handle_two(three[1:])#value of two digits by calling handle_two() function
            return first_palce+" hundred "+other
        elif len(three)==2:#if having preceding one zero
            other = handle_two(three) #getting two digit number output calling method
            return other
        elif len(three)==1:#if having precedig two zero
            first_palce = one_nine[int(three[0])] #getting direct value from one_nine list
            return first_palce
        else:#if all three digits are zero 
            return ''

    #loop until we visit all the numbers
    while initial_length < len(number):
        select_factor = len(number[initial_length:])%3 #we try to group numbers into three digits in one group and call functions accordingly 
        if select_factor == 1:#after grouping into 3 one digit left ungrouped 
            position = number_chart[len(number[initial_length:])]
            #print('called')
            word = one_nine[int(number[initial_length])]
            if len(word.strip())>0:#if ungrouped element was not 0  
                number_in_words.append(word)
                number_in_words.append(position)
            initial_length = initial_length+1 #increse the total visited element by 1
        elif select_factor == 2:#if afeter grouping into 3 we found two ungrouped elements handle it by handle_two() method
            position = number_chart[len(number[initial_length:])]#get currency word
            word = handle_two(number[initial_length:initial_length+2])
            number_in_words.append(word)
            number_in_words.append(position)
            initial_length = initial_length+2
        else:#if all digits grouped into three get slice of three digits at one time and find words 
            position = number_chart[len(number[initial_length:])]#get currency word
            #print(number[initial_length:])
            #print(number[initial_length:initial_length+3])
            word = handle_three(number[initial_length:initial_length+3])
            if len(number[initial_length:]) == 3 or len(word.strip())==0: position = ''#if len of string left at three so to not add hundred currency word twice checked this condition or sliced digits are 0 only then do not need to add any currency word
            number_in_words.append(word)
            number_in_words.append(position)
            initial_length = initial_length+3
    #print(number_in_words)
    
    number_in_words = [word for word in number_in_words if len(word)>0]

    final_converted_currency = ' '.join(number_in_words)
    print(final_converted_currency)
except Exception as e:
    print(e) #this block will only excute if number length exceeds 51 