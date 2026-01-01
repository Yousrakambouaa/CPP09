#include "PmergeMe.hpp"
PmergeMe::PmergeMe(){};
void PmergeMe::parse(int size, char **input)
{
	for (int i = 1; i < size; i++)
	{
	std::string s(input[i]);
	for (size_t j = 0; j < s.length(); j++)
	{
		if (!isdigit(s[j]))
		{
			std::cerr << "Error" << std::endl;
			return;
		}
	}
	int value = std::atoi(input[i]);
	if (value < 0)
	{
		std::cerr << "Error" << std::endl;
		return;
	}
	vect.push_back(value);
	deq.push_back(value);
	}
}


void PmergeMe::sortVector()
{
	std::cout << "\nbefore\n";
	for(size_t i = 0 ; i < vect.size(); i++)
		std::cout << vect[i] << "   ";
	size_t i = 0;
	std::vector< std::pair<int, int> > pairs;
	int unpaired;
	bool hasUnpaired = false;
	if (vect.size() % 2 != 0)
	{
		unpaired = vect.back();
		hasUnpaired = true;
	}
	while (i + 1 < vect.size())
	{
		int n1 = vect[i];
		int n2 = vect[i + 1];

		if (n1 < n2)
			pairs.push_back(std::make_pair(n1, n2));
		else
			pairs.push_back(std::make_pair(n2, n1));
		i += 2;
	}
	for (size_t i = 0; i < pairs.size(); ++i)
	{
		for (size_t j = 0; j + 1 < pairs.size() - i; ++j)
		{
			if (pairs[j].second > pairs[j + 1].second)
			{
				std::pair<int, int> tmp = pairs[j];
				pairs[j] = pairs[j + 1];
				pairs[j + 1] = tmp;
			}
		}
	}
    std::vector<int> main_chain;
    for (size_t i = 0; i < pairs.size(); ++i)
    {
		main_chain.push_back(pairs[i].second);
    }
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        int small = pairs[i].first;
        std::vector<int>::iterator it;
        for (it = main_chain.begin(); it != main_chain.end(); ++it)
        {
            if (small < *it)
            {
                main_chain.insert(it, small);
                break;
            }
        }
        if (it == main_chain.end())
            main_chain.push_back(small);
    }
    if (hasUnpaired)
    {
		std::vector<int>::iterator it;
		for (it = main_chain.begin(); it != main_chain.end(); ++it)
		{
			if (unpaired < *it)
			{
				main_chain.insert(it, unpaired);
				break;
			}
		}
		if (it == main_chain.end())
			main_chain.push_back(unpaired);
    }
	vect = main_chain;
	std::cout << "\nafter\n";
	for(size_t i = 0 ; i < vect.size(); i++)
		std::cout << vect[i] << "   ";
}







///////deqqqqqqqque



void PmergeMe::sortDeque()
{
	std::cout << "\ndeq before\n";
	for(size_t i = 0 ; i < deq.size(); i++)
		std::cout << deq[i] << "   ";
	size_t i = 0;
	std::deque< std::pair<int, int> > pairs;
	int unpaired;
	bool hasUnpaired = false;
	if (deq.size() % 2 != 0)
	{
		unpaired = deq.back();
		hasUnpaired = true;
	}
	while (i + 1 < deq.size())
	{
		int n1 = deq[i];
		int n2 = deq[i + 1];

		if (n1 < n2)
			pairs.push_back(std::make_pair(n1, n2));
		else
			pairs.push_back(std::make_pair(n2, n1));
		i += 2;
	}
	for (size_t i = 0; i < pairs.size(); ++i)
	{
		for (size_t j = 0; j + 1 < pairs.size() - i; ++j)
		{
			if (pairs[j].second > pairs[j + 1].second)
			{
				std::pair<int, int> tmp = pairs[j];
				pairs[j] = pairs[j + 1];
				pairs[j + 1] = tmp;
			}
		}
	}
    std::deque<int> main_chain;
    for (size_t i = 0; i < pairs.size(); ++i)
    {
		main_chain.push_back(pairs[i].second);
    }
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        int small = pairs[i].first;
        std::deque<int>::iterator it;
        for (it = main_chain.begin(); it != main_chain.end(); ++it)
        {
            if (small < *it)
            {
                main_chain.insert(it, small);
                break;
            }
        }
        if (it == main_chain.end())
            main_chain.push_back(small);
    }
    if (hasUnpaired)
    {
		std::deque<int>::iterator it;
		for (it = main_chain.begin(); it != main_chain.end(); ++it)
		{
			if (unpaired < *it)
			{
				main_chain.insert(it, unpaired);
				break;
			}
		}
		if (it == main_chain.end())
			main_chain.push_back(unpaired);
    }
	deq = main_chain;
	std::cout << "\n deq after\n";
	for(size_t i = 0 ; i < deq.size(); i++)
		std::cout << deq[i] << "   ";
}
