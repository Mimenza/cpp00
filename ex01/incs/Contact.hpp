/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:00:37 by emimenza          #+#    #+#             */
/*   Updated: 2024/04/22 14:00:37 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
using std::string;

class Contact
{
	public:
		void setFirstName(string str);
		void setLastName(string str);
		void setNickName(string str);
		void setPhoneNumber(string str);
		void setDarkestSecret(std::string str);

		const string& getFirstName(void) const;
		const string& getLastName(void) const;
		const string& getNickname(void) const;
		const string& getPhoneNumber(void) const;
		const string& getDarkestSecret(void) const;

	private:
		string	first_name;
		string	last_name;
		string	nickname;
		string	phone_number;
		string darkest_secret;
};

#endif