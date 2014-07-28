#include <iostream>


enum days { SUNDAY = 0, MONDAY = 1, DAY_COUNT = 7 };
enum months { JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC, MONTH_COUNT };


bool is_leap_year(int year)
{
    if (year % 100 == 0)
        return year % 400 == 0;
    else
        return year % 4 == 0;
}


int num_sundays(int lower_year, int upper_year)
{
    int num_sundays = 0;

    // Start from Monday, January 1, 1900 (since that's all we know)
    int year = 1900;
    int month = JAN;
    int day = MONDAY;

    while (year <= upper_year)
    {
        for (int month = JAN; month < MONTH_COUNT; month++)
        {
            if (month == DEC && year == upper_year)
                break;

            // Go forward the number of days in this month to the next
            if (month == APR || month == JUN || month == SEP || month == NOV)
                day += 30;
            else if (month == FEB)
                day += is_leap_year(year) ? 29 : 28;
            else
                day += 31;

            // Check which day it is
            day = day % DAY_COUNT;

            if (day == SUNDAY && year >= lower_year)
                num_sundays++;
        }
        year++;
    }

    return num_sundays;
}


int main(void)
{
    std::cout << num_sundays(1901, 2000) << std::endl;

    return 0;
}