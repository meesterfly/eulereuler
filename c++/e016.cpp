#include <iostream>
#include <string>

int main(void)
{
    double x = 2;

    for (int i = 1; i < 1000; i++)
        x *= 2;

    std::string s = std::to_string(x);

    long sum = 0;

    for (int i = 0; i < s.length() && s[i] != '.'; i++)
        sum += s[i]-'0';

    std::cout << sum << std::endl;

    return 0;
}