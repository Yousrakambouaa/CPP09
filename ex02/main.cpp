#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	try
	{
		PmergeMe pm;
		pm.run(ac, av);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}

}
