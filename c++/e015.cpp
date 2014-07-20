#include <iostream>


long number_of_routes(int x, int y, long ** a)
{
    long px = 0, py = 0;

    bool b = false;

    if (a == NULL) // Allocate an array of known answers for a given xy pair
    {
        a = new long*[x+1];
        for (int i = 0; i < x+1; i++)
        {
            a[i] = new long[y+1];
            for (int l = 0; l < y+1; l++)
                a[i][l] = 0;
        }
    }

    // If we're at the end of the grid, return 1 (it took us one move to get here)
    if (x == 0 && y == 0)
        return 1;

    // Otherwise, recurse to make a move down and right
    if (x != 0)
    {
        if (a[x-1][y] != 0) 
            px = a[x-1][y]; // If we already found this answer before, use that
        else
            px = number_of_routes(x-1, y, a); // Otherwise, recurse
    }
    if (y != 0)
    {
        if (a[x][y-1] != 0)
            py = a[x][y-1];
        else
            py = number_of_routes(x, y-1, a);
    }

    a[x][y] = px + py; //

    if (b) // If we allocated the array in this instance, deallocate it
    {
        for (int i = 0; i < x+1; i++)
            delete a[i];
        delete a;
    }

    return px + py;
}


long number_of_routes(int x, int y)
{
    return number_of_routes(x, y, NULL);
}


int main(void)
{
    std::cout << number_of_routes(20, 20) << std::endl;
    return 0;
}