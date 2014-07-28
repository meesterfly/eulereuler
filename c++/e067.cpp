#include <fstream>
#include <iostream>


int main(void)
{
    // Same solution as problem #18, except with a file instead of
    // a hard-coded stringstream.

    std::ifstream input;

    input.open("c++/e067.txt");

    if (!input.is_open())
    {
        std::cout << "File does not exist!" << std::endl;
        return 0;
    }

    int level = 1;
    long *last_level, *current_level;

    // Get the first level from the tree
    last_level = new long[level];
    input >> last_level[0];

    // Scan through the stream
    while (!input.eof())
    {
        level++;

        current_level = new long[level];

        for (int i = 0; i < level; i++)
        {
            // Get the number
            input >> current_level[i];

            // Add the greatest value above our current value and store it in its place.
            // This will make our array the list of greatest possible sums for each elements.

            if (i == 0)
                current_level[i] += last_level[i];
            else if (i == level-1)
                current_level[i] += last_level[i-1];
            else
                current_level[i] += std::max(last_level[i-1], last_level[i]);                
        }

        delete last_level;
        last_level = current_level;
    }
    input.close();

    // Find the largest sum in that last level

    long answer = 0;

    for (int i = 0; i < level; i++)
        if (current_level[i] > answer)
            answer = current_level[i];

    std::cout << answer << std::endl;

    delete current_level;

    return 0;
}