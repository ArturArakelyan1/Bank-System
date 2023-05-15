//
//  Bank.hpp
//
//  Created by Artur Arakelyan on 15.05.23.
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
std::string generateAccountID();

class Money
{
private:
    int m_balance {0};
public:
    Money() = default;
    Money(int amount);
    void addMoney(int);
    void subMoney(int);
    int getMoney();
    void SetBalancebasic(int);
};

class AccountMoney : public Money{
private:
    int m_avaliableBalance {0};
public:
    AccountMoney() = default;
    AccountMoney(int amount);
    int GetAvaliableBalance ();
    int GetBalance();
    void SetAvaliableBalamce(int amount);
    void SubAmount(int amount);
};

class Customor
{
private:
    std::string m_firstName {""};
    std::string m_lastName {""};
    std::string m_accountnumber {0};
    AccountMoney m_money;
public:
    Customor() = default;
    Customor(std::string firstname, std::string lastname);
    int getAvaliableBalance();
    int getBalance();
    void addMoney(int amount);
    void cashManey(int amount);
    //moneyset
    
};

class BankSystem
{
private:
    Money m_bankMoney {0};
    Customor m_newCustomor;
public:
    BankSystem(int money,std::string firstName,std::string lastName);
    BankSystem() = default;
    Money checkBankBalance();
    void topUpBankBalance(int amount);
    void decreaseBankBalance(int amount);
    //void makeCustomor(std::string firstName,std::string lastName);
    int checkAvaliableBalance();
    int checkBalance();
    void AddMoney(int money);
    void cashOut( int money);

    
};

std::string generateAccountID()
{
    int length = 12;
    static const char digits[] = "0123456789";

    std::string accountID;
    srand(static_cast<unsigned int>(time(0))); // Seed the random number generator

    for (int i = 0; i < length; ++i) {
        int randomIndex = rand() % (sizeof(digits) - 1);
        accountID += digits[randomIndex];
    }

    return accountID;
}
