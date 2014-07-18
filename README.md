euler euler
----------------

	#include <me/me.hpp>
    #include <projecteuler/projectuler.hpp>
    
    int main(int argv, char ** argc)
    {
    	Me me;
    	Me *i = &me;
    	ProjectEuler project_euler;
    
    	while (i->am_alive())
    	{
    	    while (i->am_solving(project_euler.problems))
    	    	me.smarts++;
    	}
    	return 0;
    }

Watch me get smarter by doing Project Euler questions! I'll work on these whenever it strikes me or when I want to try learning a new language~

**Current languages:**

- C++
- Python
- Haskell
