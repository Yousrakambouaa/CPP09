#include"RPN.hpp"


RPN::RPN()
{};

RPN::RPN(const std::stack<int>& s) : nmbrs(s){};


RPN& RPN::operator=(const RPN& other)
{
	if(this != &other)
	{
		nmbrs = other.nmbrs;
	}
	return(*this);
}

RPN::~RPN()
{}


void RPN::calcul(char token, int n1, int n2)
{
	if (token == '+')
		nmbrs.push(n1 + n2);
	else if (token == '-')
		nmbrs.push(n1 - n2);
	else if (token == '*')
		nmbrs.push(n1 * n2);
	else if (token == '/')
	{
		if (n2 == 0)
		{
			std::cerr << "Error" << std::endl;
			return;
		}
		nmbrs.push(n1 / n2);
	}
}

void RPN::rpn(const std::string &input)
{
    std::istringstream iss(input);
    std::string token;
    int n1;
    int n2;

    while (iss >> token)
    {
        if (token.size() == 1 && std::isdigit(token[0]))
        {
            nmbrs.push(token[0] - '0');
        }
        else if (token.size() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/'))
        {
            if (nmbrs.size() < 2)
            {
                std::cerr << "Error" << std::endl;
                return;
            }
            n2 = nmbrs.top(); nmbrs.pop();
            n1 = nmbrs.top(); nmbrs.pop();
			calcul(token[0], n1, n2);
        }
        else
        {
            std::cerr << "Error" << std::endl;
            return;
        }
    }
    if (nmbrs.size() != 1)
    {
        std::cerr << "Error" << std::endl;
        return;
    }
    std::cout << nmbrs.top() << std::endl;
}

