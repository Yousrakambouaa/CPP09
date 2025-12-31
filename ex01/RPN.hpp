#ifndef RPN_HPP
#define RPN_HPP

#include <sstream>
#include <stack>
#include <string>
#include <iostream>
#include <cstdlib>

class RPN
{
private:
	std::stack<int> nmbrs;
public:
	RPN();
	RPN(const std::stack<int>& nmbrs);
	RPN& operator=(const RPN& other);
	RPN(const RPN& rpn);
	~RPN();
	void calcul(char token, int n1, int n2);
	void rpn(const std::string &input);
};



#endif