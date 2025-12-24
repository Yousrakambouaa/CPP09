#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange
{
    private:
        std::map<std::string, double> _prices; 

    public:
        BitcoinExchange();                           
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();                            // destructor

        void loadDatabase(const std::string& filename);
        void processInput(const std::string& filename);

        double getExchangeRate(const std::string& date) const;
};

#endif
