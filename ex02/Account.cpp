#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <locale>
#include <sstream>
#include <ctime>

#define SET02 std::setfill('0') << std::setw(2)

int	Account::_nbAccounts;
int	Account::_totalAmount;
int	Account::_totalNbDeposits;
int	Account::_totalNbWithdrawals;

int	Account::getNbAccounts(void){
	return(Account::_nbAccounts);
}

int	Account::getTotalAmount(void){
	return(Account::_totalAmount);
}

int	Account::getNbDeposits(void){
	return(Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void){
	return(Account::_totalNbWithdrawals);
}

void Account::displayAccountsInfos(void){
	Account::_displayTimestamp();
	std::cout << "accounts:"	<< getNbAccounts()		<< ';';
	std::cout << "total:"		<< getTotalAmount()		<< ';';
	std::cout << "deposits:"	<< getNbDeposits()		<< ';';
	std::cout << "withdrawals:"	<< getNbWithdrawals();
	std::endl (std::cout);
}

void	Account::makeDeposit(int deposit)
{
	int	p_amount = _amount;

	_amount += deposit;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	_nbDeposits++;
	Account::_displayTimestamp();
	std::cout << "index:"		<< _accountIndex	<< ';';
	std::cout << "p_amount:"	<< p_amount			<< ';';
	std::cout << "deposit:"		<< deposit			<< ';';
	std::cout << "amount:"		<< _amount			<< ';';
	std::cout << "nb_deposits:"	<< _nbDeposits ;
	std::endl (std::cout);
}

bool	Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	std::cout << "index:"		<< _accountIndex	<< ';';
	std::cout << "p_amount:"	<< _amount			<< ';';
	if (_amount >= withdrawal)
	{
		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals++;
		_amount -= withdrawal;
		_nbWithdrawals++;
		std::cout << "withdrawal:"		<< withdrawal	<< ';';
		std::cout << "amount:"			<< _amount		<< ';';
		std::cout << "nb_withdrawals:"	<< _nbWithdrawals ;
		std::endl (std::cout);
		return (true);
	}
	else
	{
		std::cout << "withdrawal:"	<< "refused";
		std::endl (std::cout);
		return (false);
	}
}

int		Account::checkAmount(void) const{
	return (_amount);
}

void	Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << "index:"		<< 	_accountIndex	<< ';';
	std::cout << "amount:"		<< 	_amount			<< ';';
	std::cout << "deposits:"	<< 	_nbDeposits		<< ';';
	std::cout << "withdrawals:"	<<  _nbWithdrawals;
	std::endl (std::cout);
}

void	Account::_displayTimestamp( void )
{
	std::time_t											current_time;
	struct tm 											*tm_strc;

	current_time = time(0);
	tm_strc = localtime(&current_time);

	std::cout << '[';
	std::cout << SET02 << tm_strc->tm_year + 1900;
	std::cout << SET02 << tm_strc->tm_mon + 1;
	std::cout << SET02 << tm_strc->tm_mday;
	std::cout << '_';
	std::cout << SET02 << tm_strc->tm_hour;
	std::cout << SET02 << tm_strc->tm_min;
	std::cout << SET02 << tm_strc->tm_sec;
	std::cout << "] ";
}

Account::~Account(void)
{
	Account::_nbAccounts--;
	Account::_displayTimestamp();
	std::cout << "index:"	<< _accountIndex << ';';
	std::cout << "amount:"	<< _amount << ';';
	std::cout << "closed";
	std::endl (std::cout);
}

Account::Account(int initial_deposit)
{
	static size_t	index;

	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
	_accountIndex = index++;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	Account::_displayTimestamp();
	std::cout << "index:"	<< _accountIndex << ';';
	std::cout << "amount:"	<< _amount << ';';
	std::cout << "created";
	std::endl (std::cout);
}
