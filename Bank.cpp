
#include "Bank.hpp"

Money::Money(int amount):m_balance {amount} {}

int Money::getMoney()
{
    return m_balance;
}

void Money::addMoney(int amount)
{
    m_balance += amount;
}

void Money::SetBalancebasic(int amount)
{
    m_balance = amount;
}

AccountMoney::AccountMoney(int amount):m_avaliableBalance(amount){}

int AccountMoney::GetAvaliableBalance()
{
    return m_avaliableBalance;
}

int AccountMoney::GetBalance()
{
    return this->getMoney();
}
void AccountMoney::SetAvaliableBalamce(int amount)
{
    m_avaliableBalance = amount;
}

void AccountMoney::SubAmount(int amount)
{
    m_avaliableBalance-=amount;
}

Customor::Customor(std::string first, std::string last) : m_firstName(first), m_lastName(last), m_accountnumber(generateAccountID())
{
    
}

int Customor::getBalance()
{
    return this->m_money.GetBalance();
}

int Customor::getAvaliableBalance()
{
    return this->m_money.GetAvaliableBalance();
}

void Customor::addMoney(int amount)
{
    int tmp = this->getBalance() + ((this->getAvaliableBalance() - this->getBalance()) + amount);
    this->m_money.SetBalancebasic(tmp);
    this->m_money.SetAvaliableBalamce(amount);
}

void Customor::cashManey(int amount)
{
    this->m_money.SubAmount(amount);
};

BankSystem::BankSystem(int money, std::string first,std::string last):m_bankMoney(money),m_newCustomor(first,last){};

Money BankSystem::checkBankBalance()
{
    return m_bankMoney;
};

void BankSystem::topUpBankBalance(int amount)
{
    this->m_bankMoney.addMoney(amount);
}

void BankSystem::decreaseBankBalance(int amount)
{
    this->m_bankMoney.subMoney(amount);
}

int BankSystem::checkAvaliableBalance()
{
    return this-> m_newCustomor.getAvaliableBalance();
}

int BankSystem::checkBalance()
{
    return this->m_newCustomor.getBalance();
}

void BankSystem::AddMoney(int money)
{
    this->m_newCustomor.addMoney(money);
}

void BankSystem::cashOut(int money)
{
    this->m_newCustomor.cashManey(money);
}
