/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:34:22 by emimenza          #+#    #+#             */
/*   Updated: 2024/04/23 12:34:22 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

using std::cout;
using std::endl;

//Init static variables
int Account :: _nbAccounts = 0;
int Account :: _totalAmount = 0;
int Account :: _totalNbDeposits = 0;
int Account :: _totalNbWithdrawals = 0;

int Account :: getNbAccounts(void)
{
	return (_nbAccounts);
}

int Account :: getTotalAmount(void)
{
	return (_totalAmount);
}

int Account :: getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int Account :: getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

static void	display_time(void)
{
	const time_t	now = time(0);
	tm				*ltm = localtime(&now);

	cout << "[";
	cout << 1900 + ltm->tm_year;
	cout << std::setfill('0') << std::setw(2) << 1 + ltm->tm_mon;
	cout << std::setfill('0') << std::setw(2) << ltm->tm_mday;
	cout << "_";
	cout << std::setfill('0') << std::setw(2) << ltm->tm_hour;
	cout << std::setfill('0') << std::setw(2) << ltm->tm_min;
	cout << std::setfill('0') << std::setw(2) << ltm->tm_sec;
	cout << "] ";
}

Account::Account( int initial_deposit ) : _amount(initial_deposit)
{
	display_time();
	_accountIndex = _nbAccounts;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	cout << "index:" << _accountIndex << ";";
	cout << "amount:" << initial_deposit << ";";
	cout << "created" << endl;
	_totalAmount += initial_deposit;
	_nbAccounts++;
}

Account :: ~Account(void)
{
	display_time();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed" << std::endl;
}

void Account :: makeDeposit(int deposit)
{
	display_time();
	cout << "index:" << _accountIndex << ";";
	cout << "p_amount:" << _amount << ";";
	cout << "deposit:" << deposit << ";";
	_amount += deposit;
	_totalAmount +=deposit;
	cout << "amount:" << _amount << ";";
	_nbDeposits++;
	_totalNbDeposits++;
	cout << "nb_deposits:" << _nbDeposits << endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	display_time();
	cout << "index:" << _accountIndex << ";";
	cout << "p_amout:" << _amount << ";";
	if (_amount - withdrawal < 0)
	{
		cout << "withdrawal:refused" << endl;
		return 1;
	}
	cout << "withdrawal:" << withdrawal << ";";
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	cout << "amount:" << _amount << ";";
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	cout << "nb_withdrawals:" << _nbWithdrawals << endl;
	return 0;
}

void Account :: displayAccountsInfos(void)
{
	display_time();
	cout << "accounts:" << getNbAccounts() << ";";
	cout << "total:" << getTotalAmount() << ";";
	cout << "deposits:" << getNbDeposits() << ";";
	cout << "withdrawals:" << getNbWithdrawals();
	cout << endl;
}

void	Account::displayStatus( void ) const
{
	display_time();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}