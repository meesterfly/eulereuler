euler euler
----------------

    #include <me/me.hpp>
    #include <projecteuler/projectuler.hpp>
    
    extern Me *i;
    
    int main(int argv, char ** argc)
    {
    	ProjectEuler project_euler;
    
    	while (i->am_alive())
    	{
    	    while (i->am_solving(project_euler.problems))
    	    	i->get_smarter();
    	}
    	
    	return 0;
    }
