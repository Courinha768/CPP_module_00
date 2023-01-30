#include "Account.hpp"
#include <iostream>
#include <string>
#include <locale>
#include <iomanip>	
#include <sstream> 
//#include <chrono>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

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
	//Account::_displayTimestamp();
	std::cout << "accounts:"	<< getNbAccounts()		<< ';';
	std::cout << "total:"		<< getTotalAmount()		<< ';';
	std::cout << "deposits:"	<< getNbDeposits()		<< ';';
	std::cout << "withdrawals:"	<< getNbWithdrawals();
	std::endl (std::cout);
}


//TODO: ACERTAR AS GLOBAL VARS E ESTUDAR ISSO MELHOR

void	Account::makeDeposit(int deposit)
{
	int	p_amount = _amount;

	_amount += deposit;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	_nbDeposits++;
	//Account::_displayTimestamp();
	std::cout << "index:"		<< _accountIndex	<< ';';
	std::cout << "p_amount:"	<< p_amount			<< ';';
	std::cout << "deposit:"		<< deposit			<< ';';
	std::cout << "amount:"		<< _amount			<< ';';
	std::cout << "nb_deposits:"	<< _nbDeposits ;
	std::endl (std::cout);
}

bool	Account::makeWithdrawal(int withdrawal)
{
	//Account::_displayTimestamp();
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals++;
	std::cout << "index:"		<< _accountIndex	<< ';';
	std::cout << "p_amount:"	<< _amount			<< ';';
	if (_amount >= withdrawal)
	{
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
	//Account::_displayTimestamp();
	std::cout << "index:"		<< 	_accountIndex	<< ';';
	std::cout << "amount:"		<< 	_amount			<< ';';
	std::cout << "deposits:"	<< 	_nbDeposits		<< ';';
	std::cout << "withdrawals:"	<<  _nbWithdrawals;
	std::endl (std::cout);
}

//void	Account::_displayTimestamp( void )
//{
	
//}

Account::~Account(void)
{
	Account::_nbAccounts--;
	//Account::_displayTimestamp();
	std::cout << "index:"	<< _accountIndex << ';';
	std::cout << "amount:"	<< _amount << ';';
	std::cout << "closed";
	std::endl (std::cout);
}

Account::Account(int initial_deposit)
{
	static size_t	index;

	Account::_nbAccounts++;
	_accountIndex = index++;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	//Account::_displayTimestamp();
	std::cout << "index:"	<< _accountIndex << ';';
	std::cout << "amount:"	<< _amount << ';';
	std::cout << "created";
	std::endl (std::cout);
}
