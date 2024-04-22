/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:06:34 by emimenza          #+#    #+#             */
/*   Updated: 2024/04/22 13:06:34 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using std::cout;
using std::endl;
using std::string;

string ToUpper(string arg)
{
	size_t i = 0;
	while (i < arg.size())
	{
		arg[i] = toupper(arg[i]);
		i++;
	}
	return arg;
}

int main (int argc, char **argv)
{
	if (argc == 1)
	{
		cout << "* LOUD AND UNBEREABLE FEEDBACK NOISE *" << endl;
		return 0;
	}
	else
	{
		int i = 1;
		while (i < argc)
		{
			std::cout << ToUpper(argv[i]);
			if (i < argc - 1)
				std::cout << " ";
			else
				std::cout << std::endl;
			i++;
		}
	}
	return 0;
}