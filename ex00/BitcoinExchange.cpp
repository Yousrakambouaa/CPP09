#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	data = other.data;
}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		data = other.data;
	return (*this);
}
BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadDatabase(const std::string& filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open database file." << std::endl;
		exit(1);
	}
	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		std::string date;
		std::string str_value;
		bool f = true;
		if (!std::getline(ss, date, ','))
			f = false;
		if (!std::getline(ss, str_value))
			f = false;
		if(f)
		{
			double value = std::atof(str_value.c_str());
			data[date] = value;
		}
	}
	file.close();
}

int BitcoinExchange::validate_date(const std::string &date) const
{
	if (date.length() != 10)
		return (0);
	if (date[4] != '-' || date[7] != '-')
		return (0);
	for (int i = 0; i < 10; i++)
	{
		if (i != 4 && i != 7)
		{
			if (!isdigit(date[i]))
				return (0);
		}
	}
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());
	if (month < 1 || month > 12)
		return (0);
	if (day < 1 || day > 31)
		return (0);
	return (1);
}

int BitcoinExchange::validate_val(double value) const
{
	if (value < 0)
		return (0);
	if (value > 1000)
		return (0);
	return (1);
}

void BitcoinExchange::processInput(const std::string& filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open input file" << std::endl;
		exit(1);
	}
	std::string line;

	while (std::getline(file, line))
	{
		int ok = 1;
		size_t pos = line.find('|');
		if (pos == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			ok = 0;
		}
		std::string date;
		std::string str_value;
		double value;
		if (ok)
		{
			date = line.substr(0, pos);
			str_value = line.substr(pos + 1);
			while (!date.empty() && date[0] == ' ')
				date.erase(0, 1);
			while (!date.empty() && date[date.size() - 1] == ' ')
				date.erase(date.size() - 1, 1);
			while (!str_value.empty() && str_value[0] == ' ')
				str_value.erase(0, 1);
			while (!str_value.empty() && str_value[str_value.size() - 1] == ' ')
				str_value.erase(str_value.size() - 1, 1);
		}
		if (ok && !validate_date(date))
		{
			std::cerr << "Error: bad input => " << date << std::endl;
			ok = 0;
		}
		if (ok)
		{
			value = std::atof(str_value.c_str());
			if (!validate_val(value))
			{
				std::cerr << "Error: not a valid value." << std::endl;
				ok = 0;
			}
		}
		if (ok)
		{
			std::map<std::string, double>::iterator it = data.lower_bound(date);
			if (it == data.end() || it->first != date)
			{
				if (it == data.begin())
				{
					std::cerr << "Error: no earlier date available." << std::endl;
					ok = 0;
				}
				else
					--it;
			}
			if (ok)
			{
				double result = value * it->second;
				std::cout << date << " => " << value << " = " << result << std::endl;
			}
		}
	}
	file.close();
}

