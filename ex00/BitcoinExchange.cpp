#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

void BitcoinExchange::loadDatabase(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    std::string line;

    if (!file.is_open())
    {
        std::cerr << "Error: could not open database." << std::endl;
        return;
    }

    std::getline(file, line);

    
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string date;
        std::string priceStr;
        double price;

        if (!std::getline(ss, date, ','))
            continue;
        if (!std::getline(ss, priceStr))
            continue;

        std::stringstream(priceStr) >> price;

        _prices[date] = price;
    }

    file.close();
}


void BitcoinExchange::processInput(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    std::string line;

    if (!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::getline(file, line);

    while (std::getline(file, line))
    {
        std::string date;
        std::string valueStr;
        std::size_t separator;

        separator = line.find(" | ");
        if (separator == std::string::npos)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        date = line.substr(0, separator);
        valueStr = line.substr(separator + 3);

        std::cout << "DATE: [" << date << "] VALUE: [" << valueStr << "]" << std::endl;
    }

    file.close();
}
