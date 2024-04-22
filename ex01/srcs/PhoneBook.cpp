/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:00:49 by emimenza          #+#    #+#             */
/*   Updated: 2024/04/22 14:00:49 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "../incs/PhoneBook.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;
using std::setw;

std::string getFormattedField(const std::string& field)
{
	if (field.length() > 10)
		return field.substr(0,9) + ".";
	return field;
}

int check_data(const Contact& contact)
{
	if (contact.getFirstName().empty() ||
		contact.getLastName().empty() ||
		contact.getNickname().empty() ||
		contact.getPhoneNumber().empty() ||
		contact.getDarkestSecret().empty())
	{
		cout << "No field should be empty, Contact has not been added" << endl;
		return 0;
	}
	return 1;
}

void display_contact_info(Contact contact)
{
	cout << endl;
	cout << "First Name: " << contact.getFirstName() << endl;
	cout << "Last Name: " << contact.getLastName() << endl;
	cout << "Nickname: " << contact.getNickname() << endl;
	cout << "Phone Number: " << contact.getPhoneNumber() << endl;
	cout << "Darkest Secret: " << contact.getDarkestSecret() << endl;
	cout << endl;
}

PhoneBook::PhoneBook()
{
	count = 0;
}

void PhoneBook::addContact(void)
{
	Contact	new_contact;
	string	input;

	cout << "First Name: ";
	getline(cin, input);
	new_contact.setFirstName(input);

	cout << "Last Name: ";
	getline(cin, input);
	new_contact.setLastName(input);

	cout << "Nickname: ";
	getline(cin, input);
	new_contact.setNickName(input);

	cout << "Phone Number: ";
	getline(cin, input);
	new_contact.setPhoneNumber(input);

	cout << "Darkest Secret: ";
	getline(cin, input);
	new_contact.setDarkestSecret(input);

	if (check_data(new_contact) == 0)
		return ;
	if (count > 8)
	{
		this->contact[count - 1] = new_contact;
	}
	else
	{
		this->count += 1;
		this->contact[count - 1] = new_contact;
	}
	cout << "Contact added" << endl;
}

void PhoneBook::getContact(void)
{
	size_t i = 0;

	if (count == 0)
	{
		cout << "No countacts to display" <<endl;
		return;
	}
	cout << "\n|     Index|First Name| Last Name|  Nickname|\n" << endl;

	while (i < this->count)
	{
		cout << "|" << std::right << std::setw(10) << i << "|";
		cout << std::right << std::setw(10) << getFormattedField(contact[i].getFirstName()) << "|" ;
		cout << std::right << std::setw(10) << getFormattedField(contact[i].getLastName()) << "|";
		cout << std::right << std::setw(10) << getFormattedField(contact[i].getNickname()) << "|";
		cout << endl;
		i++;
	}

	string	input;
	int		index;

	while (1)
	{
		cout << "Enter the index" << endl;
		getline(cin, input);

		index = std::atoi(input.c_str());
		if (index < 0 || index > 8 || index > (int)count - 1)
			cout << "Invalid index" << endl;
		else
		{
			display_contact_info(this->contact[index]);
			break;
		}
	}
}