#include <iostream>
#include <string>


std::string string_for_number(int x)
{
    if (x < 20)
    {
        std::string s;

        switch (x)
        {
            case 0:  return "";
            case 1:  return "one";
            case 2:  return "two";
            case 3:  return "three";
            case 4:  return "four";
            case 5:  return "five";
            case 6:  return "six";
            case 7:  return "seven";
            case 8:  return "eight";
            case 9:  return "nine";
            case 10: return "ten";
            case 11: return "eleven";
            case 12: return "twelve";
            case 13: return "thirteen";
            case 14: return "fourteen";
            case 15: return "fifteen";
            case 16: return "sixteen";
            case 17: return "seventeen";
            case 18: return "eighteen";
            case 19: return "nineteen";
        }
    }
    else if (x < 100)
    {
        std::string s = string_for_number(x % 10);

        switch (x/10)
        {
            case 2: return "twenty"+s;
            case 3: return "thirty"+s;
            case 4: return "forty"+s; // -__- "forty" not "foUrty"
            case 5: return "fifty"+s;
            case 6: return "sixty"+s;
            case 7: return "seventy"+s;
            case 8: return "eighty"+s;
            case 9: return "ninety"+s;
        }
    }
    else if (x < 1000)
    {
        std::string s = string_for_number(x % 100);

        if (s.length() > 0)
            s = "and" + s;

        switch (x/100)
        {
            case 1: return "onehundred"+s;
            case 2: return "twohundred"+s;
            case 3: return "threehundred"+s;
            case 4: return "fourhundred"+s;
            case 5: return "fivehundred"+s;
            case 6: return "sixhundred"+s;
            case 7: return "sevenhundred"+s;
            case 8: return "eighthundred"+s;
            case 9: return "ninehundred"+s;
        }
    }
    else if (x >= 1000)
        return "onethousand"; // assuming that it will never go above 1000

    return "";
}


int main(void)
{
    int num_chars = 0;

    for (int i = 1; i <= 1000; i++)
        num_chars += string_for_number(i).length();

    std::cout << num_chars << std::endl;

    return 0;
}