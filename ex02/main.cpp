#include "PmergeMe.hpp"

int main (int ac, char **av)
{

	PmergeMe pm;
	pm.parse(ac, av);
	
	pm.sortDeque();
}