#include "Contact.hpp"
#include "Phonebook.hpp"

void	Phonebook::search(void)
{
	size_t	i = -1;
	size_t	wanted_index;

	if (phonebook[0].has_value())
		std::cout << std::string(45, '=') << std::endl;
	while (++i < 8 && phonebook[i].has_value())
	{
		std::cout << '|';
		phonebook[i].print_value(INFO(INDEX));
		std::cout << '|';
		phonebook[i].print_value(INFO(NAME));
		std::cout << '|';
		phonebook[i].print_value(INFO(LAST_NAME));
		std::cout << '|';
		phonebook[i].print_value(INFO(NICKNAME));
		std::cout << std::endl << std::string(45, '=') << std::endl;
	}
	if (phonebook[0].has_value())
	{
		std::cout << "wanted index > ";
		std::cin >> wanted_index;
		if (std::cin)
		{
			if (wanted_index > 0 && wanted_index < 9 && phonebook[wanted_index - 1].has_value())
				phonebook[wanted_index - 1].show_contact();
			else
				std::cout << "ERROR: index out of bounds!" << std::endl;
		}
		else
			std::cin.clear();
	}
	else
		std::cout << "phonebook is still empty! try adding some contacts" << std::endl;

}

void	Phonebook::add_contacts(void)
{
	static size_t	i;

	phonebook[i % 8].add_contact(i);
	i++;
}

int	main(void)
{
	std::string	command;
	Phonebook	phonebook;

	while (1)
	{
		std::cout << '>';
		std::getline(std::cin, command);
		if (!command.compare("ADD"))
			phonebook.add_contacts();
		else if (!command.compare("SEARCH"))
			phonebook.search();
		else if (!command.compare("EXIT"))
			break ;
	}
}