#include <iostream>
#include <string>


bool is_palindrome(std::string s)
{
    std::string rs = s;

    for (int i = s.length()-1; i >= 0; i--)
        rs[i] = s[s.length()-i-1];

    return s == rs;
}


int main(void)
{
    int answer = 0;

    for (int i = 0; i < 1000-100; i++)  // zig
    {                                   //   zag
        for (int l = 0; l < i; l++)     // through
        {                               //   the multiplication
            int d = (999-i) * (999-l);  // table

            if (d > answer && is_palindrome(std::to_string(d)))
                answer = d;
        }
    }

    std::cout << answer << std::endl;

    return 0;
}