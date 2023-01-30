#include "contact.class.hpp"
#include "phonebook.class.hpp"

c_phonebook::c_phonebook(void)
{
}

c_phonebook::~c_phonebook(void)
{
}

contact::contact(void)
{
}

contact::~contact(void)
{
}

void	contact::show_contact(void)
{
	std::cout	<<	"index      : "	<<	index		<<	std::endl;
	std::cout	<<	"phone      : "	<<	phone		<<	std::endl;
	std::cout	<<	"name       : "	<<	name		<<	std::endl;
	std::cout	<<	"last_name  : "	<<	last_name	<<	std::endl;
	std::cout	<<	"nickname   : "	<<	nickname	<<	std::endl;
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

void	contact::print_value(int info)
{
	if (info == INFO(INDEX))
		print_index_s10(index);
	else if (info == INFO(NAME))
		print_str_s10(name);
	else if (info == INFO(LAST_NAME))
		print_str_s10(last_name);
	else if (info == INFO(NICKNAME))
		print_str_s10(nickname);
}

bool	contact::has_value(void)
{
	if (phone.empty())
		return (false);
	return (true);
}

void	contact::add_contact(size_t i)
{
	phone = NULL_STR;
	name = NULL_STR;
	last_name = NULL_STR;
	nickname = NULL_STR;

	index = i % 8 + 1;
	while (phone.empty())
	{
		std::cout << "number    : ";
		std::getline(std::cin, phone );
	}
	while (name.empty())
	{
		std::cout << "name      : ";
		std::getline(std::cin, name);
	}
	while (last_name.empty())
	{
		std::cout << "last name : ";
		std::getline(std::cin, last_name);
	}
	while (nickname.empty())
	{
		std::cout << "nickname  : ";
		std::getline(std::cin, nickname);
	}
}