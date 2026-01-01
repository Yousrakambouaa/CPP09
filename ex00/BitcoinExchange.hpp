#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <fstream>
#include <sstream>

class BitcoinExchange
{
	private:
		std::map<std::string, double> data; 
	public:
		BitcoinExchange();                           
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();
		void loadDatabase(const std::string& filename);
		void processInput(const std::string& filename);
		int validate_date(const std::string &date) const;
		int validate_val(double value) const ;
};

#endif
