/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:27:04 by emimenza          #+#    #+#             */
/*   Updated: 2024/04/22 14:27:04 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> // cin, cout, endl
#include <string> // string class
#include <stdio.h> // clearerr()
#include "incs/PhoneBook.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;

void printOpt(void)
{
	cout << "*-------------------------------------------*\n"
			"|                                           |\n"
			"|          ADD - Add a new contact          |\n"
			"|          SEARCH - Display a contact       |\n"
			"|          EXIT - Exit PhoneBook            |\n"
			"|                                           |\n"
			"*-------------------------------------------*" << endl;
}

int main (int argc, char **argv)
{
	PhoneBook	pb;
	string		input;


	(void)argc;
	(void)argv;
	while(1)
	{
		printOpt();
		getline(cin, input);
		if (input == "add")
			pb.addContact();
		else if (input == "search")
			pb.getContact();
		else if (input == "exit")
		{
			cout << "Exiting..." << endl;
			break;
		}
		else
			cout << "Option not found" << endl;
	}
}