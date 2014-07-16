#! /usr/bin/env bash

# Solve a Project Euler question with a given language ezpz

# Expects files to be in a directory the same name of the language, 
# named with the convention e###.whtvr (ex: "/haskell/e001.hs")


# Usage: sh solve.sh [language] [problem number]


if [ $# = 2 ]; then {

    if [ $1 = "c++" ]; then

        echo '\n'`printf "Running the C++ solution for problem #%03d:" $2`'\n'

        g++ `printf "./c++/e%03d.cpp" $2` -o e; wait

        ./e; wait; echo;

        rm e

    elif [ $1 = "python" ]; then
        
        echo '\n'`printf "Running the Python solution for problem #%03d:" $2`'\n'

        python `printf "./python/e%03d.py" $2`; wait; echo;

    elif [ $1 = "haskell" ]; then
        
        echo '\n'`printf "Running the Haskell solution for problem #%03d:" $2`'\n'

        ghc `printf "./haskell/e%03d.hs" $2` -o e; wait

        echo; ./e; wait; echo

        rm e
        rm `printf "haskell/e%03d.hi" $2`
        rm `printf "haskell/e%03d.o" $2`

    else
        echo "that ain't a thing!"
    fi
    
} else
    echo "that ain't enough!"
fi
