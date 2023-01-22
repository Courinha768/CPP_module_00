#include "contact.class.hpp"

void	contact::add_contact(void)
{

	std::cout << "number         : ";
	std::getline(std::cin, phone );

	std::cout << "name           : ";
	std::getline(std::cin, name);

	std::cout << "nickname       : ";
	std::getline(std::cin, nickname);

	std::cout << "favorite colour: ";
	std::getline(std::cin, favorite_colour);
}

void	contact::show_contact(void)
{
	std::cout << "phone           : " << phone << "\n";
	std::cout << "name            : " << name << "\n";
	std::cout << "nickname        : " << nickname << "\n";
	std::cout << "favorite_colour : " << favorite_colour << "\n";
}

int	main(void)
{
	std::string	command;
	std::string wanted_index;
	contact		phonebook[8];
	size_t		i = 0;


	while (1)
	{
		std::getline(std::cin, command);
		if (!command.compare("exit"))
		{
			exit(0);
		}
		if (!command.compare("add"))
		{
			i = i % 8;
			phonebook[i++].add_contact();
		}
		if (!command.compare("search"))
		{
			std::getline(std::cin, wanted_index);
			phonebook[0].show_contact();			
		}
	}
}