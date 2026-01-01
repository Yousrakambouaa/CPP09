#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP
#include<iostream>
#include<vector>
#include<deque>
#include <ctime>

class PmergeMe
{
	private:
		std::vector<int> vect;
		std::deque<int>  deq;
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();
		void parse(int size, char **input);
		void sortVector();
		void sortDeque();
		void run(int ac, char **input);
};

#endif