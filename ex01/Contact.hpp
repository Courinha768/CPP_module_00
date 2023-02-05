#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

# include <iostream>
# include <string>
# include <locale>
# include <iomanip>	
# include <sstream> 

# define TRUE 1
# define FALSE 0

# define NULL_STR ""

enum	INFO {INDEX, NAME, NICKNAME, LAST_NAME, SECRET};

class Contact
{
	private	:
		size_t		index;
		std::string	phone;
		std::string	name;
		std::string last_name;
		std::string	nickname;
		std::string	darkest_secret;

	public	:
		Contact(void);
		~Contact(void);
		void	add_contact(size_t i);
		void	show_contact(void);
		bool	has_value(void);
		void	print_value(int msg);
};

#endif