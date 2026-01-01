#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP
#include<iostream>
#include<vector>
#include<deque>

class PmergeMe
{
	private:
		std::vector<int> vect;
		std::deque<int>  deq;


	public:

		PmergeMe();
		void parse(int size, char **input);
		void sortVector();
		void sortDeque();
		void run();
};





#endif