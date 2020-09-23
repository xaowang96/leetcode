#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#include <time.h>

#include "common.h"

#define ROMAN_1         'I'
#define ROMAN_5         'V'
#define ROMAN_10        'X'
#define ROMAN_50        'L'
#define ROMAN_100       'C'
#define ROMAN_500       'D'
#define ROMAN_1000      'M'

char int2TomanByDigits(int num, int digits)
{
    char roman = 0;
    if(num == 4 || num == 5)
    {
        switch(digits)
        {
            case 1 : roman = ROMAN_5; break;
            case 2 : roman = ROMAN_50; break;   
            case 3 : roman = ROMAN_500; break;
            default : roman = 0; break;    
        }
    }
    else if(num == 9)
    {
        switch(digits)
        {
            case 1 : roman = ROMAN_10; break;
            case 2 : roman = ROMAN_100; break;   
            case 3 : roman = ROMAN_1000; break;
            default : roman = 0; break;    
        } 
    }
    //LOG_INFO("char %c", roman);
    return roman;
}

char * intToRoman(int num){
    #define ROMAN_MAX_LENGTH        20
    char roman[ROMAN_MAX_LENGTH] = {0};
    int temp = 0;
    int i = ROMAN_MAX_LENGTH - 2;
    int decimalDigits = 0;
    //LOG_INFO("num %d", num);
    while(num)
    {
        temp = num % 10;
        //LOG_INFO("num %% 10 %d", temp);
        decimalDigits ++;
        //LOG_INFO("digits %d ", decimalDigits);
        if(temp >= 5 && temp < 9)
        {
            int j = temp - 5;
            roman[i - j] = int2TomanByDigits(5, decimalDigits);
            while(j > 0)
            {
                switch(decimalDigits)
                {
                    case 1 : roman[i--] = ROMAN_1; break;
                    case 2 : roman[i--] = ROMAN_10; break;   
                    case 3 : roman[i--] = ROMAN_100; break;
                    default : roman[i--] = 0; break;    
                } 
                j --;
            }
            i --;
        }
        else if(temp < 4)
        {
            while(temp > 0)
            {
                switch(decimalDigits)
                {
                    case 1 : roman[i--] = ROMAN_1; break;
                    case 2 : roman[i--] = ROMAN_10; break;   
                    case 3 : roman[i--] = ROMAN_100; break;
                    case 4 : roman[i--] = ROMAN_1000; break;
                    default : roman[i--] = 0; break;    
                } 
                temp --;
            }
        }        
        else 
        {
            roman[i--] = int2TomanByDigits(temp, decimalDigits);
            switch(decimalDigits)
            {
                case 1 : roman[i--] = ROMAN_1; break;
                case 2 : roman[i--] = ROMAN_10; break;   
                case 3 : roman[i--] = ROMAN_100; break;
                default : roman[i--] = 0; break;    
            }            
        }
        num /= 10;
    }
    i += 1;
    //LOG_INFO("i %d roman %s", i, &roman[i]);
    int romanLength = ROMAN_MAX_LENGTH - i + 1;
    char *pRoman = (char *)malloc(romanLength);
    memset(pRoman, 0, romanLength);
    strcpy(pRoman, &roman[i]);
    return pRoman;
}


int romanToInt(char * s)
{
    int number = 0;
    while(s && *s != 0)
    {
        switch (*s)
        {
        case ROMAN_1:
            if(*(s + 1) == ROMAN_5)
            {
                number += 4;
                s += 1;
            }
            else if(*(s + 1) == ROMAN_10)
            {
                number += 9;
                s += 1;
            }
            else
            {
                number += 1;
            } 
            break;
        case ROMAN_5:
            number += 5;
        break;
        case ROMAN_10:
            if(*(s + 1) == ROMAN_50)
            {
                number += 40;
                s += 1;
            }
            else if(*(s + 1) == ROMAN_100)
            {
                number += 90;
                s += 1;
            }
            else
            {
                number += 10;
            }
        break;
        case ROMAN_50:
            number += 50;
        break;
        case ROMAN_100:
            if(*(s + 1) == ROMAN_500)
            {
                number += 400;
                s += 1;
            }
            else if(*(s + 1) == ROMAN_1000)
            {
                number += 900;
                s += 1;
            }
            else
            {
                number += 100;
            }
        break;
        case ROMAN_500:
            number += 500;
        break;
        case ROMAN_1000:
            number += 1000;
        break;                                
        default:
            break;
        }
        s += 1; 
    }
    return number;
}

int romanCharToInt(char roman)
{
    int num = 0;
    switch (roman)
    {
    case ROMAN_1   :  num = 1; break;   
    case ROMAN_5   :  num = 5; break;   
    case ROMAN_10  :  num = 10; break;   
    case ROMAN_50  :  num = 50; break;   
    case ROMAN_100 :  num = 100; break;   
    case ROMAN_500 :  num = 500; break;   
    case ROMAN_1000:  num = 1000; break;
    default:
        break;
    }
    
    return num;
}
int romanToInt2(char * s)
{
    int number = 0;
    while(s && *s != 0)
    {
        number += romanCharToInt(*(s));
        if(romanCharToInt(*(s)) < romanCharToInt(*(s + 1)))
        {
            number +=  romanCharToInt(*(s + 1)) - 2 * romanCharToInt(*(s));   
            s += 1;
        }
        s += 1;
    }
    return number;
}
int main(int argc, char const *argv[])
{
    if(argc < 2)
    {
        fprintf(stderr, "Usage : %s n \n", argv[0]);
        exit(1);
    }

    int number = atoi(argv[1]);      
    char *pRoman = intToRoman(number);    
    LOG_INFO("num %d roman %s", number, pRoman);
    number = romanToInt(pRoman);
    LOG_INFO("roman %s num %d ", pRoman, number);
    number = romanToInt2(pRoman);
    LOG_INFO("roman %s num %d ", pRoman, number);
    free(pRoman);
    pRoman = NULL;
    return 0;
}