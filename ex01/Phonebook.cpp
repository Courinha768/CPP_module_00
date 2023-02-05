#include "Contact.hpp"
#include "Phonebook.hpp"

Phonebook::Phonebook(void)
{
}

Phonebook::~Phonebook(void)
{
}

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}

void	Contact::show_contact(void)
{
	std::cout	<<	"index      	: "	<<	index			<<	std::endl;
	std::cout	<<	"phone      	: "	<<	phone			<<	std::endl;
	std::cout	<<	"name       	: "	<<	name			<<	std::endl;
	std::cout	<<	"last_name  	: "	<<	last_name		<<	std::endl;
	std::cout	<<	"nickname   	: "	<<	nickname		<<	std::endl;
	std::cout	<<	"darkest secret	: "	<<	darkest_secret	<<	std::endl;
}

static void	print_index_s10(size_t index)
{
   std::cout << std::setw(10) << index;
}

static void	print_str_s10(std::string str)
{
	if (str.length() <= 10)
        std::cout << std::setw(10) << str;
    else
    {
        str =  str.substr(0,9) + ".";
        std::cout << std::setw(10) << str;
    }
}

void	Contact::print_value(int info)
{
	if (info == INFO(INDEX))
		print_index_s10(index);
	else if (info == INFO(NAME))
		print_str_s10(name);
	else if (info == INFO(LAST_NAME))
		print_str_s10(last_name);
	else if (info == INFO(NICKNAME))
		print_str_s10(nickname);
	else if (info == INFO(SECRET))
		print_str_s10(darkest_secret);
}

bool	Contact::has_value(void)
{
	if (phone.empty())
		return (false);
	return (true);
}

void	Contact::add_contact(size_t i)
{
	phone = NULL_STR;
	name = NULL_STR;
	last_name = NULL_STR;
	nickname = NULL_STR;
	darkest_secret = NULL_STR;

	index = i % 8 + 1;
	while (phone.empty())
	{
		std::cout << "number         : ";
		std::getline(std::cin, phone );
	}
	while (name.empty())
	{
		std::cout << "name           : ";
		std::getline(std::cin, name);
	}
	while (last_name.empty())
	{
		std::cout << "last name      : ";
		std::getline(std::cin, last_name);
	}
	while (nickname.empty())
	{
		std::cout << "nickname       : ";
		std::getline(std::cin, nickname);
	}
	while (darkest_secret.empty())
	{
		std::cout << "darkest secret : ";
		std::getline(std::cin, darkest_secret);
	}
}